#include "initialize_leds.h"

#ifndef state_machine_logic_include
#define state_machine_logic_include

/**
 * Given the current state, returns the next state in the state machine.
 * 
 * We increment the minute by 5 each time (which is just one state transition),
 * then we roll over the hour once we go from 55 minutes to 0 minutes, and increase hour by 1 (which is up one state).
 */
int GetNextState(int current_state);

/**
 * Returns the GPIOA output bitmask for the given state.
 * For this, we invert the state so that the LED's turn on
 * (Because the state is just the bit mask for which LEDs are on).
 */
int GetStateOutputGPIOA(int current_state);

int GetStateOutputGPIOB(int current_state);

/* Define states as constants */
// Hour 1 - LED1A - PA26
#define HOUR_ONE GPIO_PIN(26)
// Hour 2 - LED2A - PA24
#define HOUR_TWO GPIO_PIN(24)
// Hour 3 - LED3A - PA22
#define HOUR_THREE GPIO_PIN(22)
// Hour 4 - LED4A - PA18
#define HOUR_FOUR GPIO_PIN(18)
// Hour 5 - LED5A - PA16
#define HOUR_FIVE GPIO_PIN(16)
// Hour 6 - LED6A - PA14
#define HOUR_SIX GPIO_PIN(14)
// Hour 7 - LED7A - PA12
#define HOUR_SEVEN GPIO_PIN(12)
// Hour 8 - LED8A - PA10
#define HOUR_EIGHT GPIO_PIN(10)
// Hour 9 - LED9A - PA08
#define HOUR_NINE GPIO_PIN(8)
// Hour 10 - LED10A - PA06
#define HOUR_TEN GPIO_PIN(6)
// Hour 11 - LED11A - PA28
#define HOUR_ELEVEN GPIO_PIN(28)
// Hour 12 - LED12A - PA0
#define HOUR_TWELVE GPIO_PIN(0)

// Minute 0 - LED1B - PA27
#define MINUTE_ZERO GPIO_PIN(27)
// Minute 5 - LED2B - PA25
#define MINUTE_FIVE GPIO_PIN(25)
// Minute 10 - LED3B - PA23
#define MINUTE_TEN GPIO_PIN(23)
// Minute 15 - LED4B - PA21
#define MINUTE_FIFTEEN GPIO_PIN(21)
// Minute 20 - LED5B - PA17
#define MINUTE_TWENTY GPIO_PIN(17)
// Minute 25 - LED6B - PA15
#define MINUTE_TWENTYFIVE GPIO_PIN(15)
// Minute 30 - LED7B - PA13
#define MINUTE_THIRTY GPIO_PIN(13)
// Minute 35 - LED8B - PA11
#define MINUTE_THIRTYFIVE GPIO_PIN(11)
// Minute 40 - LED9B - PA09
#define MINUTE_FORTY GPIO_PIN(9)
// Minute 45 - LED10B - PA07
#define MINUTE_FORTYFIVE GPIO_PIN(7)
// Minute 50 - LED11B - PA05
#define MINUTE_FIFTY GPIO_PIN(5)
// Minute 55 - LED12B - PA01
#define MINUTE_FIFTYFIVE GPIO_PIN(1) 

// Bitmask for hours to extract hour section
#define HOUR_MASK (HOUR_ONE | HOUR_TWO | HOUR_THREE | HOUR_FOUR | HOUR_FIVE | \
            HOUR_SIX | HOUR_SEVEN | HOUR_EIGHT | HOUR_NINE | HOUR_TEN | \
            HOUR_ELEVEN | HOUR_TWELVE)

// Bitmask for minutes to extract minute section
#define MINUTE_MASK (MINUTE_ZERO | MINUTE_FIVE | MINUTE_TEN | MINUTE_FIFTEEN | \
            MINUTE_TWENTY | MINUTE_TWENTYFIVE | MINUTE_THIRTY | MINUTE_THIRTYFIVE | \
            MINUTE_FORTY | MINUTE_FORTYFIVE | MINUTE_FIFTY | MINUTE_FIFTYFIVE)

#define ALL_PINS (HOUR_MASK | MINUTE_MASK)

#define OFF 0



#endif /* state_machine_logic_include */
