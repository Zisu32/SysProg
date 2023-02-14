#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "hal.h"

void main(void);
void start_game(void);
void wrong_guess(int * wrong, char * guessed_word, char lower_case_input);
void true_guess(char * ptr_to_guessed_word,char*  ptr_to_selected_word, char input,int size, int * wrong_guesses);
void SysTick_Handler (void);
void update_gui(void);
void update_wrong_inputs(char lower_case_input);
void number_to_characters(int number);
void clear_characters(void);
void print_stats(void);
void play(void);
void end(void);
int lcg_random(void);
int get_random_in_range(int min, int max);