


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
