/*
 * DIO.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Nmr
 */

#ifndef DIO_H_
#define DIO_H_



#define   PORT_A      0
#define   PORT_B      1
#define   PORT_C      2
#define   PORT_D      3
#define   PORT_E      4
#define   PORT_F      5

#define OUTPUT  1
#define INPUT   0

#define HIGH  1
#define LOW   0

#define PULL_UP_RESISTOR  1
#define PULL_DOWN_RESISTOR  2

//APB Base ADD
#define PORTA_BASE_ADD  0x40004000
#define PORTB_BASE_ADD  0x40005000
#define PORTC_BASE_ADD  0x40006000
#define PORTD_BASE_ADD  0x40007000
#define PORTE_BASE_ADD  0x40024000
#define PORTF_BASE_ADD  0x40025000


volatile unsigned long delay;
#define GPIO_DATA_OFFSET       0x000003FC
#define GPIO_DIR_OFFSET        0x00000400
#define GPIO_AFSEL_OFFSET      0x00000420
#define GPIO_PUR_OFFSET        0x00000510
#define GPIO_PDR_OFFSET        0x00000514
#define GPIO_DEN_OFFSET        0x0000051C
#define GPIO_LOCK_OFFSET       0x00000520
#define GPIO_CR_OFFSET         0x00000524
#define GPIO_AMSEL_OFFSET      0x00000528
#define GPIO_PCTL_OFFSET       0x0000052C
#define SYSCTL_RCGC2           (*((volatile unsigned long *)0x400FE108))



void DIO_init_pin(unsigned char PORT,unsigned char pin,unsigned char direction);
void DIO_enable_pull_resistor(unsigned char PORT,unsigned char pin,unsigned char pull_resistor);
void DIO_set_pin_value(unsigned char PORT,unsigned char pin,unsigned char state);
unsigned char DIO_get_pin_value(unsigned char PORT,unsigned char pin);



#endif /* DIO_H_ */
