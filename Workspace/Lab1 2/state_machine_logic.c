#include "state_machine_logic.h"

int GetNextState(int current_state)
{
    if (current_state == OFF) return ON1;
    if (current_state == ON1) return ON2;
    return OFF;
}

int GetStateOutputGPIOA(int current_state)
{
    (void)current_state;
    return 0;
}

int GetStateOutputGPIOB(int current_state)
{
    (void)current_state;
    return 0;
}
