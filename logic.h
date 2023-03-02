#include <stdbool.h>
bool is_input_in_word(char * selected_word,char input, int size);
bool is_already_guessed(char input, char* guessed_word, int size);
bool is_already_in_wrong_inputs(char input, char* wrong_guesses);
void fill_guessed_word(char * guessed_word,char * selected_word, char input, int size);
void init_array(char * array, int length);
bool is_equal(char *guessed, char*selected, int size);
bool is_special_character(char input);
char convert_to_lower(char input);
char convert_to_upper(char low);
void remove_characters_from_array(char *array, int end);
void number_to_characters(int number, char *array_to_fill, int size);
void update_wrong_inputs(char lower_case_input, char* wrong_inputs);
void reset_wrong_inputs_position();