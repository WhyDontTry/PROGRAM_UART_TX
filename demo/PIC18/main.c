/*  Software ("bit-bang") UART Transmitter (8 data bits, 1 stop bit, no parity)
    for Attiny24A/44A/84A using the internal 8MHz oscillator as clock source

    (c) 2018 Marcel Meyer-Garcia
    see LICENCE.txt
 */

 /* NOTE: since the internal 8MHz oscillator is not very accurate, the value for OCR0A can be tuned
    to achieve the desired baud rate (nominal value is 103)
 */
#include "p_uart.h"



int main(void)
{
   program_uart_init();

   while(1)
   {
     p_uart_char_send("Y");
     p_uart_char_send("e");
     p_uart_char_send("s");
     p_uart_char_send("\n");
    _delay_ms(100);
   }

   return 0;
}
