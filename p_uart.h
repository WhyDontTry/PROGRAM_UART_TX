







##include <stdint.h>



void tx_port_pin_init();
void tx_timer_init();
inline void set_tx_pin();
inline void reset_tx_pin();
inline void tx_timer_enable();
inline void tx_timer_disable();


void program_uart_init();
void p_uart_char_send(char character);

inline void tx_vector_handler();
