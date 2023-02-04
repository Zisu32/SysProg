#include "main.h"
#include "user_actions.h"
#include "logic.h"


void start_game()
{
    char selected_word[10];
    char guessed_word[sizeof(selected_word)];
    char *ptr_to_selected_word = selected_word;
    char *ptr_to_guessed_word = guessed_word;
    init_guessed_word(ptr_to_guessed_word);
}

void main()
{
    start_game();
}
