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

int wrong = 0;
int *wrong_guesses = &wrong;

char word_to_guess[MAX_WORD_LENGTH] ;
char guessed_word[MAX_WORD_LENGTH];

int size = 0;
int *ptr_to_size = &size;

int tries = 0;

char wrong_inputs[MAX_WRONG_TRIES];
int current_position_at_wrong_input = 0;

char tries_as_characters[MAX_NUMBER_CHARS] = "000";
char wrong_guesses_as_character[MAX_NUMBER_CHARS] = "000";

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
    print_word(guessed_word);
    draw_hangman(*wrong_guesses);
    print_word(wrong_inputs);
}
/**
 * @brief handles input if it's in the word_to_guess array
 * 
 */
void true_guess(char input)
{
    fill_guessed_word(guessed_word, word_to_guess, input, *ptr_to_size);
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
    while (!is_equal(guessed_word, word_to_guess, *ptr_to_size) && *wrong_guesses < MAX_WRONG_TRIES-1)
    {
        char input = read();
        start_sysTick();
        char lower_input = convert_to_lower(input);
        if (!is_special_character(lower_input))
        {
            if (is_input_in_word(word_to_guess, lower_input, *ptr_to_size))
            {
                if (!is_already_guessed(lower_input, guessed_word, *ptr_to_size))
                {
                    true_guess(lower_input);
                }
                else
                {
                    wrong_guess(lower_input);
                }
            }
            else if (!is_input_in_word(word_to_guess, lower_input, *ptr_to_size))
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
    if (*wrong_guesses == MAX_WRONG_TRIES-1)
    {
        finish_game(0);
    }
    else if (is_equal(guessed_word, word_to_guess, *ptr_to_size))
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
    print_word("enter first letter\r");
    get_guesss();
    handle_no_guesses_left();
}

/**
 * @brief starts the game by getting the word to guess and initializing the necessary arrays
 * 
 */
void start_game()
{
    *ptr_to_size = get_word_to_guess(word_to_guess)+1;
    init_guessed_word(guessed_word, *ptr_to_size);
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
    clear_screen();
    clear_screen();
    if (result == 1)
    {
        draw_you_win();
    }
    else if (result == 0)
    {
        draw_game_over();
    }
    fill_arrays_for_statistics();
    draw_stats();
    // if (result == 0)
    // {
    //     print_word("Following word should have been guessed");
    //     print_word(word_to_guess);
    // }
    return;
}

/**
 * @brief starts the SysTick Timer
 * 
 */
void start_sysTick()
{
    uint32_t clocks_to_tick = 8000000 - 1;
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
 * @brief says what to do if the SysTick Timer went down to 0
 * 
 */
void SysTick_Handler()
{
    if (!is_equal(guessed_word, word_to_guess, *ptr_to_size) && *wrong_guesses < MAX_WRONG_TRIES)
    {
        update_gui();
        tries += 1;
        wrong += 1;
    }
    else
    {
        finish_game(0);
        return;
    }
}




/**
 * @brief is the main function called by entry_c.c
 * 
 */
void main()
{
    draw_starting_scrren();
    print_word("Press s/S to start!");
    char input = read();
    while (input != 's' && input != 'S')
    {
        input = read();
    }
    start_game();
}
