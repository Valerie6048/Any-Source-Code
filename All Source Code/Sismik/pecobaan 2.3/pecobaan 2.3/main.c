/*
 * pecobaan 2.3.c
 *
 * Created: 9/26/2021 12:32:23 PM
 * Author : KyuRinTao
 */ 

#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>
#include <avr/interrupt.h>
#define LED PORTC
#define LEDDir DDRC
int main(void)
{
	LEDDir = 0xFF;
	LED = 0xFF;
	DDRD = 0x00;
	PORTD = 0xFF;
	GICR = 1<<INT0 | 1<<INT1;
	MCUCR = 1<<ISC01 | 1<<ISC00 | 1<<ISC10 | 1<<ISC11;
	sei();
	while (1)
	{
		LED = 0b00000001; _delay_ms(1000);
		LED = 0b00000010; _delay_ms(1000);
		LED = 0b00000100; _delay_ms(1000);
		LED = 0b00001000; _delay_ms(1000);
		LED = 0b00010000; _delay_ms(1000);
		LED = 0b00100000; _delay_ms(1000);
		LED = 0b01000000; _delay_ms(1000);
		LED = 0b10000000; _delay_ms(1000);
	}
}
ISR(INT0_vect)
{
	LED = 0x0F; _delay_ms(1000);
}
ISR(INT1_vect)
{
	LED = 0xF0; _delay_ms(1000);
}
