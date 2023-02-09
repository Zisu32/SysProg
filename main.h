#include <stdint.h>
#include <stdio.h>
#include "hal.h"

void main(void);
void start_game(void);
void wrong_guess(int * wrong, char * guessed_word);
void true_guess(char * ptr_to_guessed_word,char*  ptr_to_selected_word, char input,int size, int * wrong_guesses);
void SysTick_Handler (void);
void update_gui(void);