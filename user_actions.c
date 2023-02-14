#include "user_actions.h"

#include <stdio.h>

const char *HANGMAN_ASCII_ART[] = {
    " _______\n\r"
    " |/     |\n\r"
    " |       \n\r"
    " |       \n\r"
    " |       \n\r"
    " |       \n\r"
    " |\n\r"
    " |\n\r"
    "_|___\n\r",
    " _______\n\r"
    " |/     |\n\r"
    " |      (\n\r"
    " |       \n\r"
    " |       \n\r"
    " |       \n\r"
    " |\n\r"
    " |\n\r"
    "_|___\n\r",
    " _______\n\r"
    " |/     |\n\r"
    " |      ()\n\r"
    " |       \n\r"
    " |       \n\r"
    " |       \n\r"
    " |\n\r"
    " |\n\r"
    "_|___\n\r",
    " _______\n\r"
    " |/     |\n\r"
    " |      ()\n\r"
    " |      \\ \n\r"
    " |       \n\r"
    " |       \n\r"
    " |\n\r"
    " |\n\r"
    "_|___\n\r",
    " _______\n\r"
    " |/     |\n\r"
    " |      ()\n\r"
    " |     \\| \n\r"
    " |       \n\r"
    " |       \n\r"
    " |\n\r"
    " |\n\r"
    "_|___\n\r",
    " _______\n\r"
    " |/     |\n\r"
    " |      ()\n\r"
    " |     \\|/\n\r"
    " |       \n\r"
    " |       \n\r"
    " |\n\r"
    " |\n\r"
    "_|___\n\r",
    " _______\n\r"
    " |/     |\n\r"
    " |      ()\n\r"
    " |     \\|/\n\r"
    " |      |\n\r"
    " |       \n\r"
    " |\n\r"
    " |\n\r"
    "_|___\n\r",
    " _______\n\r"
    " |/     |\n\r"
    " |      ()\n\r"
    " |     \\|/\n\r"
    " |      |\n\r"
    " |      /\n\r"
    " |\n\r"
    " |\n\r"
    "_|___\n\r",
    " _______\n\r"
    " |/     |\n\r"
    " |      ()\n\r"
    " |     \\|/\n\r"
    " |      |\n\r"
    " |     / \\\n\r"
    " |\n\r"
    " |\n\r"
    "_|___\n\r"};

/// @brief draws hangman picture
/// @param incorrect
void draw_hangman(int incorrect)
{
    print_word(HANGMAN_ASCII_ART[incorrect]);
}

void print_single_character(char text)
{
    printChar(text);
}

char read(void)
{
    char input = read_input();
    return input;
}

void print_word(const char *text)
{
    printString(text);
}