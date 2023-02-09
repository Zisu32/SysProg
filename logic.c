#include <ctype.h>
#include "logic.h"
#include "user_actions.h"
char toUpper(char low)
{
    int ascii = low;
    int ascii_to_upper = low-32;
    char upper = ascii_to_upper;
    return upper;
}

bool is_input_in_word(char * selected_word,char input, int size){
    for(int i =0; i < size-1; i++)
    {
        if(selected_word[i]==input)
        {
            return true;
        }
        else if(selected_word[i]==toUpper(input))
        {
            return true;
        }
        else if(selected_word[i]!=input)
        {
            if(size-2==i)
            {
                return false;
            }

        }
        else if(selected_word[i]!=toUpper(input))
        {
            if(size-2==i)
            {
                return false;
            }
        }
    }
}


void init_guessed_word(char * guessed_word, int length){
    for(int i = 0;i<length-1; i++)
    {
        guessed_word[i]= '_';
    }
}

void fill_guessed_word(char * guessed_word, char * selected_word,char input, int size)
{
    for(int i = 0; i<size; i++)
        {
            if(selected_word[i]==input)
            {
                guessed_word[i]= toUpper(input);
            }
            else if(selected_word[i]==toUpper(input))
            {
                guessed_word[i]=toUpper(input);
            }
        }
}

bool is_equal(char *gurssed, char*selected, int size)
{
    
    for(int i = 0; i<size; i++)
    {
        if(gurssed[i]!=selected[i])
        {
            return false;
        }
    }
    return true;
}

int update_wrong_guesses(int wrong_guesses)
{
    wrong_guesses ++;
    return wrong_guesses;
}
bool is_special_character(char input)
{
    int input_ascii = input;
    if(input_ascii >= 65 && input_ascii <= 90)
    {
        return false;
    }
    else if(input_ascii >= 97 && input_ascii <= 122)
    {
        return false;
    }
    else 
    {
        return true;
    }
}
char convert_to_lower(char input)
{
    if(!is_special_character(input))
    {
        if( input >= 65 && input <= 90)
        {
            return input +32;
        }
        else
        {
            return input;
        }
    }
}