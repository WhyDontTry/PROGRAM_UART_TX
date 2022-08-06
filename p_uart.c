






#include "p_uart.h"



volatile uint16_t tx_shift_reg = 0;


void p_uart_char_send(char character)
{
   uint16_t local_tx_shift_reg = tx_shift_reg;
   //if sending the previous character is not yet finished, return
   //transmission is finished when tx_shift_reg == 0
   if(local_tx_shift_reg){return;}
   //fill the TX shift register witch the character to be sent and the start & stop bits (start bit (1<<0) is already 0)
   local_tx_shift_reg = (character << 1) | (1 << 9); //stop bit (1<<9)
   tx_shift_reg = local_tx_shift_reg;
   //start timer0 with a prescaler of 8
   tx_timer_enable();
   while(tx_shift_reg);
}




program_uart_init()
{
    tx_port_pin_init();
    tx_timer_init();  // 104 us for 9600 baud
}


inline void tx_vector_handler()
{
  uint16_t local_tx_shift_reg = tx_shift_reg;
  //output LSB of the TX shift register at the TX pin
  if( local_tx_shift_reg & 0x01 )
  {
     set_tx_pin();
  }
  else
  {
     reset_tx_pin();
  }
  //shift the TX shift register one bit to the right
  local_tx_shift_reg >>= 1;
  tx_shift_reg = local_tx_shift_reg;
  //if the stop bit has been sent, the shift register will be 0
  //and the transmission is completed, so we can stop & reset timer0
  if(!local_tx_shift_reg)
  {
     tx_timer_disable();
  }
}
