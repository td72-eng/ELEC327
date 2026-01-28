#include <ti/devices/msp/msp.h>
#include "delay.h"
#include "initialize_leds.h"

/* same masks as in initialize_leds.c (repeat here to avoid extra files) */
#define LED12A (1u << 0)
#define LED11A (1u << 28)  // may not work if PA28 isn't GPIOA channel
#define LED10A (1u << 6)
#define LED9A  (1u << 8)
#define LED8A  (1u << 10)
#define LED7A  (1u << 12)
#define LED6A  (1u << 14)
#define LED5A  (1u << 16)
#define LED4A  (1u << 18)
#define LED3A  (1u << 22)
#define LED2A  (1u << 24)
#define LED1A  (1u << 26)

#define LED12B (1u << 27)
#define LED11B (1u << 1)
#define LED10B (1u << 5)
#define LED9B  (1u << 7)
#define LED8B  (1u << 9)
#define LED7B  (1u << 11)
#define LED6B  (1u << 13)
#define LED5B  (1u << 15)
#define LED4B  (1u << 17)
#define LED3B  (1u << 21)
#define LED2B  (1u << 23)
#define LED1B  (1u << 25)

#define ALL_LEDS_GPIOA ( \
    LED12A|LED11A|LED10A|LED9A|LED8A|LED7A|LED6A|LED5A|LED4A|LED3A|LED2A|LED1A| \
    LED12B|LED11B|LED10B|LED9B|LED8B|LED7B|LED6B|LED5B|LED4B|LED3B|LED2B|LED1B )

int main(void)
{
    InitializeGPIO();

    /* Turn ON all LEDs (active-low => drive LOW) */
    GPIOA->DOUTCLR31_0 = ALL_LEDS_GPIOA;

    while (1) {
        // stay on forever for inspection
    }
}
