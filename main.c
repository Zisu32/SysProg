#include "main.h"
#include "user_actions.h"
#include "logic.h"

    const int  MAX_WRONG_TRIES = 9;
    int wrong =0;
    int *wrong_guesses = &wrong;
    char selected_word[] = "Kreuzfahrt";
    char guessed_word[sizeof(selected_word)];
    int size = sizeof(selected_word)/sizeof(selected_word[0]);
    char *ptr_to_selected_word = selected_word;
    char *ptr_to_guessed_word = guessed_word;

void true_guess(char * ptr_to_guessed_word,char*  ptr_to_selected_word, char input,int size, int * wrong_guesses)
{
    fill_guessed_word(ptr_to_guessed_word, ptr_to_selected_word, input, size);
    print_word("\033[H\033[J");
    print_word(ptr_to_guessed_word);
    draw_hangman(*wrong_guesses-1);
}
void wrong_guess(int * wrong, char * guessed_word)
{
    *wrong+=1;
    print_word("\033[H\033[J");
    print_word(guessed_word);
    draw_hangman(*wrong-1);
}

void start_game()
{

    // 80 000 000 mal / sek
	//     80 000 mal / msek
	//    800 000 mal / 10 msek
	uint32_t clocks_to_tick = 800000000 - 1;
    WriteToRegister(0xE000E014, clocks_to_tick);

    init_guessed_word(ptr_to_guessed_word, size);
    print_word("enter first letter\r");
    while(!is_equal(ptr_to_guessed_word, ptr_to_selected_word, size)&&wrong!= MAX_WRONG_TRIES)
    {
        char input = read();
        char lower_input = convert_to_lower(input);
        print_single_character(lower_input);
        if(!is_special_character(lower_input))
        {
    if(is_input_in_word(ptr_to_selected_word, lower_input, size))
    {
        true_guess(ptr_to_guessed_word, ptr_to_selected_word, input,size, wrong_guesses);
    }
    else if(!is_input_in_word(ptr_to_selected_word, lower_input, size))
    {
        wrong_guess(wrong_guesses, ptr_to_guessed_word);
    }
        }
        if(is_special_character(input))
        {
            wrong_guess(wrong_guesses, ptr_to_guessed_word);
        }
    }

}
void SysTick_Handler()
{
    wrong_guess(wrong_guesses, ptr_to_guessed_word);
}
void main()
{
    start_game();
}
