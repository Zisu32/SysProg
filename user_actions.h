#include "hal.h"

void print_single_character(char text);
char read(void);
void print_guessed_word(const char *text);
void print_word_to_guess(const char *text, int length);
void draw_hangman(int incorrect);
void fill_tries_array(const char* tries);
void fill_wrong_tries_array(const char* wrong_tries);
void draw_game_over(void);
void draw_stats(void);
void draw_you_win(void);
void draw_starting_scrren(void);
int get_word_to_guess(char* word_to_guess);
