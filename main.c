#include "main.h"
#include "user_actions.h"
#include "logic.h"


void start_game()
{
    char selected_word[] = "ausgewaehltes Wort";
    char guessed_word[sizeof(selected_word)];
    int size = sizeof(selected_word)/sizeof(selected_word[0]);
    char *ptr_to_selected_word = selected_word;
    char *ptr_to_guessed_word = guessed_word;
    init_guessed_word(ptr_to_guessed_word, size);
    print_word(ptr_to_guessed_word);
}

void main()
{
    start_game();
}
