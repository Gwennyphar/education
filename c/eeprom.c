#include <stdio.h>
#include <stdint.h>
 
// ...
// nicht dargestellt: Implementierung von uart_puts (vgl. Abschnitt UART)
// ...
 
uint16_t counter;
 
// Ausgabe eines unsigned Integerwertes
void uart_puti( uint16_t value )
{
    uint8_t puffer[20];
 
    sprintf( puffer, "Zählerstand: %u", value );
    uart_puts( puffer );
}
 
int main()
{
  counter = 5;
 
  uart_puti( counter );
  uart_puti( 42 );
}
