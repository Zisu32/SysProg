#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "main.h"
#include "user_actions.h"
#include "logic.h"
#include "hal.h"

char *words[] =
    {
        "QUACKSALBER",
        "FRITTENSAUCE",
        "NICHTSDESTOTROTZ",
        "MISCHPOKE",
        "HAFTPFLICHTVERSICHERUNG",
        "BLUBBERWASSER",
        "KAFFEEKLATSCH",
        "OEL",
        "KAULQUAPPE",
        "PURZELBAUM",
        "QUATSCHKOPF",
        "QUIETSCHFIDEL",
        "WACKELDACKEL",
        "WONNEPROPPEN",
        "AXOLOTL",
        "GYNAEKOLOGIE",
        "QUALITATIV",
        "RHESUSFAKTOR",
        "XYLOPHON",
        "TIPP",
        "OPERNARIE",
};

#define MAX_WRONG_TRIES 11
#define MAX_WORD_LENGTH 21
#define MAX_NUMBER_CHARS 4
#define ASCII_CONVERSION_OFFSET 48

int wrong = 0;
int *wrong_guesses = &wrong;

char word_to_guess[MAX_WORD_LENGTH] = "____________________";
char guessed_word[MAX_WORD_LENGTH];
int size = 0;
int *ptr_to_size = &size;
int tries = 0;
int *ptr_to_tries = &tries;

char wrong_inputs[MAX_WRONG_TRIES];
int current_position_at_wrong_input = 0;

char number_as_character[4] = "000";
char wrong_guesses_as_character[4] = "000";

char lower_input;
void clear_characters()
{
    for (int i = 0; i < MAX_NUMBER_CHARS - 1; i++)
    {
        number_as_character[i] = '0';
    }
}

void clear_wrong_guesses_as_characters()
{
    for (int i = 0; i < MAX_NUMBER_CHARS - 1; i++)
    {
        wrong_guesses_as_character[i] = '0';
    }
}

void print_stats(void)
{
    print_guessed_word(wrong_inputs);
    number_to_characters(tries);
    print_guessed_word(number_as_character);
    number_to_characters(wrong);
    print_guessed_word(number_as_character);
}

/// @brief converts number to character representation
/// @param number number to be converted
void number_to_characters(int number)
{
    clear_characters();
    int number_to_convert = number;
    int array_position = MAX_NUMBER_CHARS - 2;
    if (number_to_convert != 0)
    {
        while (number_to_convert > 0)
        {
            number_as_character[array_position--] = (number_to_convert % 10) + ASCII_CONVERSION_OFFSET;
            number_to_convert /= 10;
        }
    }
}

void wrong_guesses_to_characters(int wrong_guesses)
{
    clear_wrong_guesses_as_characters();
    int number_to_convert = wrong_guesses;
    int array_position = MAX_NUMBER_CHARS - 2;
    if (number_to_convert != 0)
    {
        while (number_to_convert > 0)
        {
            wrong_guesses_as_character[array_position--] = (number_to_convert % 10) + ASCII_CONVERSION_OFFSET;
            number_to_convert /= 10;
        }
    }
}

/// @brief adds character to wrong_input array
/// @param lower_case_input
void update_wrong_inputs(char lower_case_input)
{
    wrong_inputs[current_position_at_wrong_input] = lower_case_input;
    current_position_at_wrong_input += 1;
}

/// @brief updates the screen
void update_gui()
{
    print_guessed_word("\033[H\033[J");
    print_guessed_word(guessed_word);
    draw_hangman(*wrong_guesses);
}

/// @brief calls necessary functions if guess is correct
/// @param ptr_to_guessed_word
/// @param ptr_to_selected_word
/// @param input
/// @param size
/// @param wrong_guesses
void true_guess(char *ptr_to_guessed_word, char *ptr_to_selected_word, char input, int size, int *wrong_guesses)
{
    fill_guessed_word(guessed_word, word_to_guess, input, *ptr_to_size);
    tries += 1;
    update_gui();
}

/// @brief calls necessary functions if guess is wrong
/// @param wrong
/// @param guessed_word
/// @param lower_case_input
void wrong_guess(int *wrong, char *guessed_word, char lower_case_input)
{
    *wrong_guesses += 1;
    tries += 1;
    if (!is_already_in_wrong_inputs(lower_case_input, wrong_inputs))
    {
        update_wrong_inputs(lower_case_input);
    }
    update_gui();
}

void play()
{
    while (!is_equal(guessed_word, word_to_guess, *ptr_to_size) && *wrong_guesses < MAX_WRONG_TRIES)
    {
        char input = read();
        uint32_t clocks_to_tick = 8000000 - 1;
        WriteToRegister(0xE000E014, clocks_to_tick);
        WriteToRegister(0xE000E018, 0);
        WriteToRegister(0xE000E010, 0x00000007);
        lower_input = convert_to_lower(input);
        if (!is_special_character(lower_input))
        {
            if (is_input_in_word(word_to_guess, lower_input, *ptr_to_size))
            {
                if (!is_already_guessed(lower_input, guessed_word, *ptr_to_size))
                {
                    true_guess(guessed_word, word_to_guess, lower_input, *ptr_to_size, wrong_guesses);
                }
                else
                {
                    wrong_guess(wrong_guesses, guessed_word, lower_input);
                }
            }
            else if (!is_input_in_word(word_to_guess, lower_input, *ptr_to_size))
            {
                wrong_guess(wrong_guesses, guessed_word, lower_input);
            }
        }
        if (is_special_character(lower_input))
        {
            wrong_guess(wrong_guesses, guessed_word, lower_input);
        }
    }
    if (*wrong_guesses == MAX_WRONG_TRIES)
    {
        loose();
    }
    else if (is_equal(guessed_word, word_to_guess, *ptr_to_size))
    {
        win();
    }
}

/// @brief starts game
void start_game()
{
    *ptr_to_size = get_word_to_guess(word_to_guess);
    *ptr_to_size +=1;
    init_guessed_word(guessed_word, *ptr_to_size);
    print_guessed_word("enter first letter\r");
    play();
}
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
        loose();
        return;
    }
}

void win()
{
    WriteToRegister(0xE000E010, 0x00000000);
    print_guessed_word("\033[H\033[J");
    draw_you_win();
    clear_characters();
    number_to_characters(tries);
    fill_tries_array(number_as_character);
    wrong_guesses_to_characters(wrong);
    fill_wrong_tries_array(wrong_guesses_as_character);
    draw_stats();
}
void loose()
{
    WriteToRegister(0xE000E010, 0x00000000);
    print_guessed_word("\033[H\033[J");
    draw_game_over();
    clear_characters();
    number_to_characters(tries);
    fill_tries_array(number_as_character);
    wrong_guesses_to_characters(wrong);
    fill_wrong_tries_array(wrong_guesses_as_character);
    draw_stats();
    print_guessed_word("Following word should have been guesses\n\r");
    print_word_to_guess(word_to_guess, *ptr_to_size);
}

/// @brief is the main function called by entry_c.c
void main()
{
    draw_starting_scrren();
    print_guessed_word("Press s/S to start!");
    char input = read();
    while (input != 's' && input != 'S')
    {
        input = read();
    }
    start_game();
}
