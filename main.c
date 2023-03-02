/// \file
#include "main.h"
#include "user_actions.h"
#include "logic.h"

#define MAX_WRONG_TRIES 11
#define MAX_WORD_LENGTH 26
#define MAX_NUMBER_CHARS 4
#define UPPER_CASE_P 80
#define LOWER_CASE_P 112
#define ESCAPE_ASCCI 27
#define ENTER_ASCII_VALUE 13
#define SMALLEST_UPPER_CASE_ASCII_VALUE 65
#define HIGHEST_UPPER_CASE_ASCII_VALUE 90
#define SMALLEST_LOWER_CASE_ASCII_VALUE 97
#define HIGHEST_LOWER_CASE_ASCII_VALUE 122

int number_of_wrong_inputs = 0;
int length_of_word = 0;
int tries = 0;
int timeouts_by_systick = 0;
char tries_as_characters[MAX_NUMBER_CHARS] = "000";
char wrong_guesses_as_character[MAX_NUMBER_CHARS] = "000";
char wordToGuessLength[MAX_NUMBER_CHARS] = "000";
char timeouts_as_characters[MAX_NUMBER_CHARS] = "000";

char word_to_guess[MAX_WORD_LENGTH];
char guessed_word[MAX_WORD_LENGTH];
char wrong_inputs[MAX_WRONG_TRIES];

/**
 * @brief starts the SysTick Timer
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
 */
void stop_sysTick()
{
    WriteToRegister(0xE000E010, 0x00000000);
}

/**
 * @brief updates screen to the newest game progress
 */
void update_gui()
{
    clear_screen();
    draw_hangman(number_of_wrong_inputs);
    print_word(guessed_word);
    print_word("Letters guessed wrong or several times:");
    print_word(wrong_inputs);
}

/**
 * @brief handles input if it's in the word_to_guess array
 *
 */
void true_guess(char input)
{
    fill_guessed_word(guessed_word, word_to_guess, input, length_of_word);
    tries += 1;
    update_gui();
}

/**
 * @brief handles input if it is not part of the word
 * @param lower_case_input
 */
void wrong_guess(char lower_case_input)
{
    number_of_wrong_inputs += 1;
    tries += 1;
    if (!is_already_in_wrong_inputs(lower_case_input, wrong_inputs) && !is_special_character(lower_case_input))
    {
        update_wrong_inputs(lower_case_input, wrong_inputs);
    }
    if (number_of_wrong_inputs == MAX_WRONG_TRIES)
    {
        stop_sysTick();
    }
    update_gui();
}

/**
 * @brief fills the stats array with the number of tries and the number of mistakes
 */
void fill_array_with_statistics()
{
    number_to_characters(tries, tries_as_characters, MAX_NUMBER_CHARS);
    fill_stats(tries_as_characters, 1);
    number_to_characters(number_of_wrong_inputs, wrong_guesses_as_character, MAX_NUMBER_CHARS);
    fill_stats(wrong_guesses_as_character, 3);
    number_to_characters(timeouts_by_systick, timeouts_as_characters, MAX_NUMBER_CHARS);
    fill_stats(timeouts_as_characters, 5);
}

/**
 * @brief draws the final results to the console
 * @param result 0 => loose, 1 => win
 */
void finish_game(int result)
{
    stop_sysTick();
    if (result == 1)
    {
        draw_you_win();
    }
    else if (result == 0)
    {
        draw_game_over();
        print_word("The gussed word was:");
        print_word(word_to_guess);
    }
    print_word("Press any key to show statistics");
    read();
    fill_array_with_statistics();
    draw_stats();
    draw_play_again();
    print_word("Enter p/P to play again or any button to leave");
    int decision_asccii_value = read();
    if (decision_asccii_value == LOWER_CASE_P || decision_asccii_value == UPPER_CASE_P)
    {
        clear_screen();
        main();
    }
    else
    {
        clear_screen();
        draw_end();
    }
}

/**
 * @brief is called when the word is guessed or too many wrong inputs were made
 */
void handle_no_guesses_left()
{
    stop_sysTick();
    if (number_of_wrong_inputs == MAX_WRONG_TRIES)
    {
        finish_game(0);
    }
    else if (is_equal(guessed_word, word_to_guess, length_of_word))
    {
        finish_game(1);
    }
}

/**
 * @brief while the word isn't guessed wright and there are more wrong inputs allowed
 */
void get_guess()
{
    start_sysTick();
    while (!is_equal(guessed_word, word_to_guess, length_of_word) && number_of_wrong_inputs < MAX_WRONG_TRIES)
    {
        char input = read_with_interrupt_handling();
        if (input == ESCAPE_ASCCI)
        {
            timeouts_by_systick++;
            wrong_guess(input);
        }
        else if (input != ESCAPE_ASCCI)
        {
            char lower_input = convert_to_lower(input);
            if (!is_special_character(input))
            {
                if (is_input_in_word(word_to_guess, lower_input, length_of_word))
                {
                    if (!is_already_guessed(lower_input, guessed_word, length_of_word))
                    {
                        true_guess(lower_input);
                    }
                    else
                    {
                        wrong_guess(lower_input);
                    }
                }
                else if (!is_input_in_word(word_to_guess, lower_input, length_of_word))
                {
                    wrong_guess(lower_input);
                }
            }
        }
    }
}

/**
 * @brief calls the functions for the gameplay
 */
void play()
{
    print_word("Enter first letter\r");
    get_guess();
    handle_no_guesses_left();
}

/**
 * @brief Get the word to guess
 * @details fills the word_to_guess array 
 */
void get_word_to_guess()
{
    int position = 0;
    while (position < MAX_WORD_LENGTH-1)
    {
        char input = read();
        int input_ascii_value = input;
        if (input_ascii_value >= SMALLEST_UPPER_CASE_ASCII_VALUE && input_ascii_value <= HIGHEST_UPPER_CASE_ASCII_VALUE)
        {
            word_to_guess[position] = input;
            position += 1;
        }
        else if (input_ascii_value >= SMALLEST_LOWER_CASE_ASCII_VALUE && input_ascii_value <= HIGHEST_LOWER_CASE_ASCII_VALUE)
        {
            word_to_guess[position] = convert_to_upper(input);
            position += 1;
        }
        else if (input_ascii_value == ENTER_ASCII_VALUE)
        {
            length_of_word = position+1;
            return;
        }
    }
    length_of_word = position+1;
}

/**
 * @brief starts the game by getting the word to guess and initializing the necessary arrays
 */
void start_game()
{
    get_word_to_guess();
    init_array(guessed_word, length_of_word);
    number_to_characters(length_of_word-1, wordToGuessLength, MAX_NUMBER_CHARS);
    print_word("The length of the word we are looking for is:");
    print_word(wordToGuessLength);
    play();
}

/**
 * @brief resets dynamic filled values and arrays
 *
 */
void reset_everything()
{
    tries = 0;
    number_of_wrong_inputs = 0;
    timeouts_by_systick = 0;
    length_of_word = 0;
    reset_wrong_inputs_position();
    remove_characters_from_array(guessed_word, MAX_WORD_LENGTH);
    remove_characters_from_array(word_to_guess, MAX_WORD_LENGTH);
    remove_characters_from_array(wrong_inputs, sizeof(wrong_inputs));
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
    clear_screen();
    draw_rules();
    start_game();
}
