#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "main.h"
#include "user_actions.h"
#include "logic.h"
#include "hal.h"

#define MAX_WRONG_TRIES 12
#define MAX_WORD_LENGTH 21
#define MAX_NUMBER_CHARS 4
#define ASCII_CONVERSION_OFFSET 48
#define UPPER_CASE_P 80
#define LOWER_CASE_P 112
#define UPPER_CASE_Q 81
#define LOWER_CASE_Q 113

int wrong = 0;

char word_to_guess[MAX_WORD_LENGTH];
char guessed_word[MAX_WORD_LENGTH];

int size = 0;

int tries = 0;

char wrong_inputs[MAX_WRONG_TRIES];
int current_position_at_wrong_input = 0;

char tries_as_characters[MAX_NUMBER_CHARS] = "000";
char wrong_guesses_as_character[MAX_NUMBER_CHARS] = "000";

void remove_characters_from_array(char *array, int start, int end)
{
    for (int i = start; i < end; i++)
    {
        array[i] = '\0';
    }
}

/**
 * @brief restes given array to inital "000" value to prevent wrong outputs by previous convertions
 *
 * @param array_to_reset
 */
void reset_number_as_character_array(char *array_to_reset)
{
    for (int i = 0; i < MAX_NUMBER_CHARS - 1; i++)
    {
        array_to_reset[i] = '0';
    }
}
/**
 * @brief converts the given number to an charcter and fills the gien array with the converted number
 *
 * @param number
 * @param array_to_fill
 */
void number_to_characters(int number, char *array_to_fill)
{
    reset_number_as_character_array(array_to_fill);
    int number_to_convert = number;
    int array_position = MAX_NUMBER_CHARS - 2;
    if (number_to_convert != 0)
    {
        while (number_to_convert > 0)
        {
            array_to_fill[array_position--] = (number_to_convert % 10) + ASCII_CONVERSION_OFFSET;
            number_to_convert /= 10;
        }
    }
}

/**
 * @brief adds input to the wrong_inputs array if user input isn't part of the word_to_guess array, or it's already gueesed
 *
 */
void update_wrong_inputs(char lower_case_input)
{
    wrong_inputs[current_position_at_wrong_input] = lower_case_input;
    current_position_at_wrong_input += 1;
}

/**
 * @brief updates screen to the newest game progress
 *
 */
void update_gui()
{
    clear_screen();
    draw_hangman(wrong);
    print_word(guessed_word);
    print_word(wrong_inputs);
}
void update_gui_from_interrupt(void)
{
    wrong++;
    tries++;
    clear_screen();
    draw_hangman(wrong);
    print_word(guessed_word);
    print_word(wrong_inputs);
    if (wrong == MAX_WRONG_TRIES)
    {
        stop_sysTick();
    }
}
/**
 * @brief handles input if it's in the word_to_guess array
 *
 */
void true_guess(char input)
{
    fill_guessed_word(guessed_word, word_to_guess, input, size);
    tries += 1;
    update_gui();
}

/**
 * @brief handles input if it is not part of the word
 *
 * @param lower_case_input
 */
void wrong_guess(char lower_case_input)
{
    wrong += 1;
    tries += 1;
    if (!is_already_in_wrong_inputs(lower_case_input, wrong_inputs))
    {
        update_wrong_inputs(lower_case_input);
    }
    update_gui();
}

/**
 * @brief as long the word isn't guessed fully and there are still tries left it gets a new input and processes it
 *
 */
void get_guesss()
{
    start_sysTick();
    while (!is_equal(guessed_word, word_to_guess, size) && wrong < MAX_WRONG_TRIES - 1)
    {
        char input = read();
        char lower_input = convert_to_lower(input);
        if (!is_special_character(lower_input))
        {
            if (is_input_in_word(word_to_guess, lower_input, size))
            {
                if (!is_already_guessed(lower_input, guessed_word, size))
                {
                    true_guess(lower_input);
                }
                else
                {
                    wrong_guess(lower_input);
                }
            }
            else if (!is_input_in_word(word_to_guess, lower_input, size))
            {
                wrong_guess(lower_input);
            }
        }
        if (is_special_character(lower_input))
        {
            wrong_guess(lower_input);
        }
    }
}

/**
 * @brief is called when the word is guessed or too many wrong inputs were made
 *
 */
void handle_no_guesses_left()
{
    stop_sysTick();
    if (wrong == MAX_WRONG_TRIES - 1 || wrong == MAX_WRONG_TRIES)
    {
        finish_game(0);
    }
    else if (is_equal(guessed_word, word_to_guess, size))
    {
        finish_game(1);
    }
}

/**
 * @brief calls the functions for the gameplay
 *
 */
void play()
{
    print_word("Enter first letter\r");
    get_guesss();
    handle_no_guesses_left();
}

/**
 * @brief starts the game by getting the word to guess and initializing the necessary arrays
 *
 */
void start_game()
{
    size = get_word_to_guess(word_to_guess) + 1;
    init_array(guessed_word, size);
    play();
}

/**
 * @brief fills the stats array with the number of tries and the number of mistakes
 *
 */
void fill_arrays_for_statistics()
{
    number_to_characters(tries, tries_as_characters);
    fill_stats(tries_as_characters, 1);
    number_to_characters(wrong, wrong_guesses_as_character);
    fill_stats(wrong_guesses_as_character, 3);
}

/**
 * @brief draws the final results to the console
 *
 * @param result 0 => loose, 1 => win
 */
void finish_game(int result)
{
    stop_sysTick();
    // clear_screen();
    // clear_screen();
    if (result == 1)
    {
        draw_you_win();
    }
    else if (result == 0)
    {
        draw_game_over();
        draw_play_again();
    }
    fill_arrays_for_statistics();
    draw_stats();

    print_word("Enter p/P to play again");
    int decision_asccii_value = read();
    // if (decision_asccii_value == LOWER_CASE_P || decision_asccii_value == UPPER_CASE_P)
    // {
    //     clear_screen();
    //     main();
    // }
    // else
    // {
    //     draw_end();
    // }
}

/**
 * @brief starts the SysTick Timer
 *
 */
void start_sysTick()
{
    uint32_t clocks_to_tick = 80000 - 1;
    WriteToRegister(0xE000E014, clocks_to_tick);
    WriteToRegister(0xE000E018, 0);
    WriteToRegister(0xE000E010, 0x00000007);
}

/**
 * @brief stops the SysTick if the game is over
 *
 */
void stop_sysTick()
{
    WriteToRegister(0xE000E010, 0x00000000);
}

/**
 * @brief resets dynamic filled values and arrays
 *
 */
void reset_everything()
{
    tries = 0;
    wrong = 0;
    remove_characters_from_array(guessed_word, 0, MAX_WORD_LENGTH);
    remove_characters_from_array(word_to_guess, 0, MAX_WORD_LENGTH);
    remove_characters_from_array(wrong_inputs, 0, sizeof(wrong_inputs));
}

/**
 * @brief is the main function called by entry_c.c
 *
 */
void main()
{
    reset_everything();
    clear_screen();
    draw_starting_screen();
    print_word("Press s/S to start!");
    char input = read();
    while (input != 's' && input != 'S')
    {
        input = read();
    }
    start_game();
}
