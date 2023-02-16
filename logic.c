#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include "logic.h"
#include "user_actions.h"

/**
 * @brief converts given character to uppercase
 *
 * @param low
 * @return char as uppercase
 */
char toUpper(char low)
{
    int ascii_to_upper = low - 32;
    char upper = ascii_to_upper;
    return upper;
}
/**
 * @brief cheks if input is in word
 * @details conversion to uppercase is considered as well
 * @param selected_word is the word the player should guess
 * @param input is the character the player typed in the console
 * @param size limits the number of steps are made
 * @return true if guess is correct, falls if not
 */
bool is_input_in_word(char *selected_word, char input, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        if (selected_word[i] == input)
        {
            return true;
        }
        else if (selected_word[i] == toUpper(input))
        {
            return true;
        }
        else if (selected_word[i] != input)
        {
            if (size - 2 == i)
            {
                return false;
            }
        }
        else if (selected_word[i] != toUpper(input))
        {
            if (size - 2 == i)
            {
                return false;
            }
        }
    }
}

/**
 * @brief initializes guessed_word array with underscores for every position
 * @param guessed_word word that's filled with the users input
 * @param length limits the number of steps are made
 */
void init_array(char * array, int length)
{
    for (int i = 0; i < length - 1; i++)
    {
        array[i] = '_';
    }
}

/**
 * @brief it puts the input character at the positions where it is in the original word
 * @details it converts input to uppercase so the guessed_word contains uppercase characters
 * @param guessed_word word that's filled with the users input
 * @param selected_word is the word the player should guess
 * @param input
 * @param size limits the number of steps are made
 */

void fill_guessed_word(char *guessed_word, char *selected_word, char input, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (selected_word[i] == input)
        {
            guessed_word[i] = toUpper(input);
        }
        else if (selected_word[i] == toUpper(input))
        {
            guessed_word[i] = toUpper(input);
        }
    }
}

/**
 * @brief checks if the full word is guessed by the player
 * @param gurssed is the word the player should guess
 * @param selected
 * @param size limits the number of steps are made
 * @return true if words are equal, false if still characters are missing
 */

bool is_equal(char *guessed, char *selected, int size)
{

    for (int i = 0; i < size - 1; i++)
    {
        if (guessed[i] != selected[i])
        {
            return false;
        }
    }
    return true;
}

/**
 * @brief increase counter of wrong guesses
 * @param wrong_guesses
 * @return new value of wrong guesses
 */

int update_wrong_guesses(int wrong_guesses)
{
    wrong_guesses++;
    return wrong_guesses;
}

/**
 * @brief checks if input is a special character
 * @param input
 * @return true if it's a special character, falls if its a letter excpet ö,ä,ü
 */
bool is_special_character(char input)
{
    int input_ascii = input;
    if (input_ascii >= 65 && input_ascii <= 90)
    {
        return false;
    }
    else if (input_ascii >= 97 && input_ascii <= 122)
    {
        return false;
    }
    else
    {
        return true;
    }
}

/**
 * @brief checks if char is lower or upper case and converts input to lowercase if necessary
 * @param input
 * @return lowercase version of input
 */

char convert_to_lower(char input)
{
    if (!is_special_character(input))
    {
        if (input >= 65 && input <= 90)
        {
            return input + 32;
        }
        else
        {
            return input;
        }
    }
}

/**
 * @brief checks if the user input has been guessed already
 * @details necessary, because this counts as mistake
 * @param input
 * @param guessed_word
 * @param size
 * @return
 */

bool is_already_guessed(char input, char *guessed_word, int size)
{

    for (int i = 0; i < size - 1; i++)
    {

        if (guessed_word[i] == toUpper(input))
        {
            return true;
        }
        else if (guessed_word[i] != toUpper(input))
        {
            if (size - 2 == i)
            {
                return false;
            }
        }
    }
}

/**
 * @brief checks if user input is aleady in wrong_guesses array
 * @details keeps the array with wrong guesses short, as it doesn't contain doubled values
 * @param input
 * @param wrong_guesses
 * @return
 */

bool is_already_in_wrong_inputs(char input, char *wrong_guesses)
{
    for (int i = 0; i < sizeof(wrong_guesses); i++)
    {
        if (wrong_guesses[i] == input)
        {
            return true;
        }
    }
    return false;
}
