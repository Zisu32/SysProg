#include "hal.h"

void print_single_character(char text);
char read(void);
char read_with_interrupt_handling(void);
void waitForAnyInput();
void print_word(const char *text);
void draw_hangman(int incorrect);
void draw_game_over(void);
void draw_stats(void);
void draw_you_win(void);
void draw_end(void);
void draw_starting_screen(void);
int get_word_to_guess(char* word_to_guess, int size);
void clear_screen(void);
void fill_stats(const char *array_with_number, int position);
void draw_play_again(void);