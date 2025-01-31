#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"
#include "pico/time.h"
#include "lib/led.h"

#define LED_PIN_G 11
#define LED_PIN_B 12
#define LED_PIN_R 13

bool led_stat_r = true;
bool led_stat_g = false;
bool led_stat_b = false;

uint32_t intervalo = 3000;

int main() {
    stdio_init_all();

    led_init(LED_PIN_G);
    led_init(LED_PIN_B);
    led_init(LED_PIN_R);

    absolute_time_t next_wake_time = delayed_by_us(get_absolute_time(), intervalo * 1000);

    while (true) {
        if(time_reached(next_wake_time)){
            printf("passou-se 3 segundos\n");
            if (led_stat_r) {
                led_stat_r = !led_stat_r;
            }
            gpio_put(LED_PIN_R, led_stat_r);

            next_wake_time = delayed_by_us(next_wake_time, intervalo * 1000);
        }
        sleep_ms(1);
    }
}