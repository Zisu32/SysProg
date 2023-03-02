#include "hal.h"

char read(void);
char read_with_interrupt_handling(void);
void print_word(const char *text);
void draw_hangman(int incorrect);
void draw_game_over(void);
void draw_stats(void);
void draw_you_win(void);
void draw_end(void);
void draw_starting_screen(void);
void draw_rules(void);
void clear_screen(void);
void fill_stats(const char *array_with_number, int position);
void draw_play_again(void);
