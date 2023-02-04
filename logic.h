#include <stdbool.h>
bool is_input_in_word(char input, char * guessed_word);
void fill_selected_word(char * selected_word);
void fill_guessed_word(char * guessed_word);
void init_guessed_word(char * guessed_word);
bool guesses_left(void);
void update_wrong_guesses(void);
void start_sysTick(void);
void SysTick_Handler(void);