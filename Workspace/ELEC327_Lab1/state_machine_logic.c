#include "state_machine_logic.h"
#include <ti/devices/msp/msp.h>

int GetNextState(int current_state)
{
    // Extract the hour and minute from the current state
    int hour = current_state & HOUR_MASK;
    int minute = current_state & MINUTE_MASK;

    // These will hold the new hour and minute values
    int new_hour = hour;
    int new_minute = minute;
    // This finds the next state by moving the state to the next minute increment, and rolling over the hour if needed
    switch (minute)
    {
    case MINUTE_ZERO: new_minute = MINUTE_FIVE; break;
    case MINUTE_FIVE: new_minute = MINUTE_TEN; break;
    case MINUTE_TEN: new_minute = MINUTE_FIFTEEN; break;
    case MINUTE_FIFTEEN: new_minute = MINUTE_TWENTY; break;
    case MINUTE_TWENTY: new_minute = MINUTE_TWENTYFIVE; break;
    case MINUTE_TWENTYFIVE: new_minute = MINUTE_THIRTY; break;
    case MINUTE_THIRTY: new_minute = MINUTE_THIRTYFIVE; break;
    case MINUTE_THIRTYFIVE: new_minute = MINUTE_FORTY; break;
    case MINUTE_FORTY: new_minute = MINUTE_FORTYFIVE; break;
    case MINUTE_FORTYFIVE: new_minute = MINUTE_FIFTY; break;
    case MINUTE_FIFTY: new_minute = MINUTE_FIFTYFIVE; break;
    case MINUTE_FIFTYFIVE:
        // Loop back to zero minutes
        new_minute = MINUTE_ZERO;
        // Once we've reached the top of hour, increment hour
        switch (hour)
        {
        case HOUR_ONE: new_hour = HOUR_TWO; break;
        case HOUR_TWO: new_hour = HOUR_THREE; break;
        case HOUR_THREE: new_hour = HOUR_FOUR; break;
        case HOUR_FOUR: new_hour = HOUR_FIVE; break;
        case HOUR_FIVE: new_hour = HOUR_SIX; break;
        case HOUR_SIX: new_hour = HOUR_SEVEN; break;
        case HOUR_SEVEN: new_hour = HOUR_EIGHT; break;
        case HOUR_EIGHT: new_hour = HOUR_NINE; break;
        case HOUR_NINE: new_hour = HOUR_TEN; break;
        case HOUR_TEN: new_hour = HOUR_ELEVEN; break;
        case HOUR_ELEVEN: new_hour = HOUR_TWELVE; break;
        // Loop midnight back to hour one
        case HOUR_TWELVE: new_hour = HOUR_ONE; break;
        default: new_hour = HOUR_TWELVE; break;
        }
        break;
    default:
        // In this case we're just gonna go to zero
        new_minute = MINUTE_ZERO; break;
    }
    // Combine new hour and minute to form new state (which will always be two bits)
    return new_hour | new_minute;
}

int GetStateOutputGPIOA(int current_state) {
    // Invert the current state so that LEDs turn on
    return ~(current_state);
}

int GetStateOutputGPIOB(int current_state) {
    return 0;
};
