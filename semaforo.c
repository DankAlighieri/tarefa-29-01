#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"
#include "pico/time.h"
#include "lib/led.h"

#define LED_PIN_G 11
#define LED_PIN_Y 12
#define LED_PIN_R 13

bool led_stat_r = true;
bool led_stat_y = false;
bool led_stat_g = false;

uint32_t intervalo = 3000;

bool repeating_timer_callback(struct repeating_timer *t) {
    if (led_stat_r) {
        printf("Desligando vermelho e ligando amarelo\n");
        led_stat_r = !led_stat_r;
        led_stat_y = !led_stat_y;
        gpio_put(LED_PIN_R, led_stat_r);
        gpio_put(LED_PIN_Y, led_stat_y);
    } else if(led_stat_y){
        printf("Desligando amarelo e ligando verde\n");
        led_stat_y = !led_stat_y;
        led_stat_g = !led_stat_g;
        gpio_put(LED_PIN_Y, led_stat_y);
        gpio_put(LED_PIN_G, led_stat_g);
    } else {
        printf("Desligando verde e ligando vermelho\n");
        led_stat_g = !led_stat_g;
        led_stat_r = !led_stat_r;
        gpio_put(LED_PIN_G, led_stat_g);
        gpio_put(LED_PIN_R, led_stat_r);
    }
}

int main() {
    stdio_init_all();

    led_init(LED_PIN_G);
    led_init(LED_PIN_Y);
    led_init(LED_PIN_R);
    gpio_put(LED_PIN_R, led_stat_r);

    struct repeating_timer timer;

    add_repeating_timer_ms(intervalo, repeating_timer_callback, NULL, &timer);

    while (true) {
        printf("Hello world! (1000 ms)\n");
        sleep_ms(1000);
    }
}