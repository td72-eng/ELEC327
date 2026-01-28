#ifndef initialize_leds_include
#define initialize_leds_include

/**
 * Initializes the GPIO pins for the LEDs.
 * This is meant to initialize the LEDs for the clock display.
 */ 
void InitializeGPIO();

// Macro to define GPIO pin bitmask for pin n
#define GPIO_PIN(n) (1U << (n))

#endif /* initialize_leds_include */
