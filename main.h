#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "hal.h"

void main(void);
void start_game(void);
void wrong_guess(char lower_case_input);
void true_guess(char input);
void SysTick_Handler (void);
void update_gui(void);
void update_gui_from_interrupt(void);
void play(void);
void fill_arrays_for_statistics(void);
void finish_game(int result);
void stop_sysTick(void);
void start_sysTick(void);
