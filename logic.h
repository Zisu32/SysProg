#include <stdbool.h>
bool is_input_in_word(char * selected_word,char input, int size);
void fill_guessed_word(char * guessed_word,char * selected_word, char input, int size);
void init_guessed_word(char * guessed_word, int length);
void start_sysTick(void);
void SysTick_Handler(void);
bool is_equal(char *gurssed, char*selected, int size);
int update_wrong_guesses(int wrong_guesses);
bool is_special_character(char input);
char convert_to_lower(char input);