#include "main.h"
#include "user_actions.h"
#include "logic.h"

    const int  MAX_WRONG_TRIES = 9;
    int wrong =0;
    int *wrong_guesses = &wrong;

    char selected_word[] = "KREUZFAHRT";
    char *ptr_to_selected_word = selected_word;
    int size = sizeof(selected_word)/sizeof(selected_word[0]);

    char guessed_word[sizeof(selected_word)];
    char *ptr_to_guessed_word = guessed_word;


    int tries = 0;
    int *ptr_to_tries = &tries; 

    int number_of_wrong_inputs = 0;
    int * ptr_to_number_of_wrong_inputs = &number_of_wrong_inputs;

    char wrong_inputs[27];
    char * ptr_to_wrong_inputs = wrong_inputs;


void update_gui()
{
    print_word("\033[H\033[J");
    print_word(ptr_to_guessed_word);
    draw_hangman(*wrong_guesses-1);
}

void true_guess(char * ptr_to_guessed_word,char*  ptr_to_selected_word, char input,int size, int * wrong_guesses)
{
    fill_guessed_word(ptr_to_guessed_word, ptr_to_selected_word, input, size);
    update_gui();
}
void wrong_guess(int * wrong, char * guessed_word)
{
    *wrong+=1;
   update_gui();
}

void start_game()
{

    // 80 000 000 mal / sek
	//     80 000 mal / msek
	//    800 000 mal / 10 msek
	uint32_t clocks_to_tick = 800000000 - 1;
    WriteToRegister(0xE000E014, clocks_to_tick);
    WriteToRegister(0xE000E018, 0);
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
        true_guess(ptr_to_guessed_word, ptr_to_selected_word, lower_input,size, wrong_guesses);
    }
    else if(!is_input_in_word(ptr_to_selected_word, lower_input, size))
    {
        wrong_guess(wrong_guesses, ptr_to_guessed_word);
    }
        }
        if(is_special_character(lower_input))
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
