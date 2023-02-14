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

#define MAX_WRONG_TRIES 9
#define MAX_WORD_LENGTH 23
#define MAX_NUMBER_CHARS 4
#define ASCII_CONVERSION_OFFSET 48
#define NUM_WORDS (sizeof(words) / sizeof(words[0]))

#define MIN_NUM 1
#define MAX_NUM 100


int wrong = 0;
int *wrong_guesses = &wrong;

char selected_word[MAX_WORD_LENGTH];
char *ptr_to_selected_word = selected_word;
int size = sizeof(selected_word);
char guessed_word[sizeof(selected_word)];
char *ptr_to_guessed_word = guessed_word;

int tries = 0;
int *ptr_to_tries = &tries;

char wrong_inputs[MAX_WRONG_TRIES];
char *ptr_to_wrong_inputs = wrong_inputs;
int current_position_at_wrong_input = 0;

char number_as_character[MAX_NUMBER_CHARS] = "000";
char *ptr_to_number_as_character = number_as_character;

char lower_input;
void clear_characters()
{
    for (int i = 0; i < MAX_NUMBER_CHARS - 1; i++)
    {
        number_as_character[i] = '0';
    }
}

void print_stats(void)
{
    print_word(ptr_to_wrong_inputs);
    number_to_characters(*ptr_to_tries);
    print_word(number_as_character);
    number_to_characters(*wrong_guesses);
    print_word(number_as_character);
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
            ptr_to_number_as_character[array_position--] = (number_to_convert % 10) + ASCII_CONVERSION_OFFSET;
            number_to_convert /= 10;
        }
    }
}

/// @brief adds character to wrong_input array
/// @param lower_case_input
void update_wrong_inputs(char lower_case_input)
{
    ptr_to_wrong_inputs[current_position_at_wrong_input] = lower_case_input;
    current_position_at_wrong_input += 1;
}

/// @brief updates the screen
void update_gui()
{
    print_word("\033[H\033[J");
    print_word(ptr_to_guessed_word);
    draw_hangman(*wrong_guesses - 1);
}

/// @brief calls necessary functions if guess is correct
/// @param ptr_to_guessed_word
/// @param ptr_to_selected_word
/// @param input
/// @param size
/// @param wrong_guesses
void true_guess(char *ptr_to_guessed_word, char *ptr_to_selected_word, char input, int size, int *wrong_guesses)
{
    fill_guessed_word(ptr_to_guessed_word, ptr_to_selected_word, input, size);
    *ptr_to_tries += 1;
    // update_gui();
}

/// @brief calls necessary functions if guess is wrong
/// @param wrong
/// @param guessed_word
/// @param lower_case_input
void wrong_guess(int *wrong, char *guessed_word, char lower_case_input)
{
    *wrong += 1;
    *ptr_to_tries += 1;
    if (!is_already_in_wrong_inputs(lower_case_input, wrong_inputs))
    {
        update_wrong_inputs(lower_case_input);
    }
    // update_gui();
}

void play()
{
    int random_number;
    random_number = (ReadFromRegister(0xE000E014)+12335)%NUM_WORDS;
    print_word(words[random_number]);



    while (!is_equal(ptr_to_guessed_word, ptr_to_selected_word, size) && *wrong_guesses < MAX_WRONG_TRIES)
    {
        char input = read();
        lower_input = convert_to_lower(input);
        if (!is_special_character(lower_input))
        {
            if (is_input_in_word(ptr_to_selected_word, lower_input, size))
            {
                if (!is_already_guessed(lower_input, guessed_word, size))
                {
                    true_guess(ptr_to_guessed_word, ptr_to_selected_word, lower_input, size, wrong_guesses);
                }
                else
                {
                    wrong_guess(wrong_guesses, guessed_word, lower_input);
                }
            }
            else if (!is_input_in_word(ptr_to_selected_word, lower_input, size))
            {
                wrong_guess(wrong_guesses, ptr_to_guessed_word, lower_input);
            }
        }
        if (is_special_character(lower_input))
        {
            wrong_guess(wrong_guesses, ptr_to_guessed_word, lower_input);
        }
    }
}

void end()
{
    WriteToRegister(0xE000E010, 0x00000000);
    // update_gui();
    print_stats();
}
/// @brief starts game
void start_game()
{
    uint32_t clocks_to_tick = 80000 - 1;
    WriteToRegister(0xE000E014, clocks_to_tick);
    WriteToRegister(0xE000E018, 0);
    WriteToRegister(0xE000E010, 0x00000007);
    init_guessed_word(guessed_word, size);
    print_word("enter first letter\r");
    play();
    end();
}
void SysTick_Handler()
{
    if (!is_equal(ptr_to_guessed_word, ptr_to_selected_word, size) && *wrong_guesses < MAX_WRONG_TRIES)
    {
        // update_gui();
        *ptr_to_tries += 1;
        *wrong_guesses += 1;
    }
    else
    {
        end();
        return;
    }
}
/// @brief is the main function called by entry_c.c
void main()
{
    start_game();
}
