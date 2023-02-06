#include "logic.h"
#include "user_actions.h"

#define MAX_WRONG_TRIES = 11;
int wrong_guesses =0;

bool is_input_in_word(char input, char * guessed_word){}
void fill_selected_word(char * selected_word){}
void fill_guessed_word(char * guessed_word){}
bool guesses_left(void){}
void update_wrong_guesses(void){}
void start_sysTick(void){}
void SysTick_Handler(void){}

void init_guessed_word(char * guessed_word){
    for(int i = 0;i<(10*sizeof(char)); i++)
    {
        guessed_word[i]= '_';
    }
}