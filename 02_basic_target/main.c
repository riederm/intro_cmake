#include <stdio.h>
#include "uart.h"
#include "led.h"

int main(void)
{
    printf("[main] firmware start\n");

    uart_init();
    led_init();

    uart_send("hello world");
    led_on();
    led_off();

    printf("[main] firmware done\n");
    return 0;
}
