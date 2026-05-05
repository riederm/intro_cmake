#include <stdio.h>
#include "uart.h"

void uart_init(void)
{
    printf("[uart] init\n");
}

void uart_send(const char *msg)
{
    printf("[uart] send: '%s'\n", msg);
}
