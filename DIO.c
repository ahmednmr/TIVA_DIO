/*
 * DIO.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Nmr
 */

#include"DIO.h"


void DIO_init_pin(unsigned char PORT,unsigned char pin,unsigned char direction)
{

    unsigned long base_add_port=0;

    if(PORT==PORT_A)             base_add_port=PORTA_BASE_ADD;
    else if(PORT==PORT_B)        base_add_port=PORTB_BASE_ADD;
    else if(PORT==PORT_C)        base_add_port=PORTC_BASE_ADD;
    else if(PORT==PORT_D)        base_add_port=PORTD_BASE_ADD;
    else if(PORT==PORT_E)        base_add_port=PORTE_BASE_ADD;
    else if(PORT==PORT_F)        base_add_port=PORTF_BASE_ADD;


    SYSCTL_RCGC2 |= (1<<PORT);
    delay = SYSCTL_RCGC2;           // Allow time for clock to start
    (*((volatile unsigned long *)(base_add_port|GPIO_LOCK_OFFSET))) = 0x4C4F434B;
    (*((volatile unsigned long *)(base_add_port|GPIO_CR_OFFSET))) |= (1<<pin);

    if(direction==OUTPUT)         (*((volatile unsigned long *)(base_add_port|GPIO_DIR_OFFSET)))  |= (1<<pin);
    else if(direction==INPUT)     (*((volatile unsigned long *)(base_add_port|GPIO_DIR_OFFSET)))  &=~(1<<pin);

    (*((volatile unsigned long *)(base_add_port|GPIO_AFSEL_OFFSET))) = 0x00;
    (*((volatile unsigned long *)(base_add_port|GPIO_DEN_OFFSET))) |= (1<<pin);;
}


void DIO_enable_pull_resistor(unsigned char PORT,unsigned char pin,unsigned char pull_resistor)
{

    unsigned long base_add_port=0;

    if(PORT==PORT_A)             base_add_port=PORTA_BASE_ADD;
    else if(PORT==PORT_B)        base_add_port=PORTB_BASE_ADD;
    else if(PORT==PORT_C)        base_add_port=PORTC_BASE_ADD;
    else if(PORT==PORT_D)        base_add_port=PORTD_BASE_ADD;
    else if(PORT==PORT_E)        base_add_port=PORTE_BASE_ADD;
    else if(PORT==PORT_F)        base_add_port=PORTF_BASE_ADD;

    if(pull_resistor==PULL_UP_RESISTOR)
    {
        (*((volatile unsigned long *)(base_add_port|GPIO_PUR_OFFSET))) |= (1<<pin);;

    }
    else if(pull_resistor==PULL_DOWN_RESISTOR)
      {
          (*((volatile unsigned long *)(base_add_port|GPIO_PDR_OFFSET))) |= (1<<pin);;

      }


}

void DIO_set_pin_value(unsigned char PORT,unsigned char pin,unsigned char state)
{

    unsigned long base_add_port=0;

    if(PORT==PORT_A)             base_add_port=PORTA_BASE_ADD;
    else if(PORT==PORT_B)        base_add_port=PORTB_BASE_ADD;
    else if(PORT==PORT_C)        base_add_port=PORTC_BASE_ADD;
    else if(PORT==PORT_D)        base_add_port=PORTD_BASE_ADD;
    else if(PORT==PORT_E)        base_add_port=PORTE_BASE_ADD;
    else if(PORT==PORT_F)        base_add_port=PORTF_BASE_ADD;

    if(state==HIGH)
    {
        (*((volatile unsigned long *)(base_add_port|GPIO_DATA_OFFSET))) |= (1<<pin);;

    }
    else if(state==LOW)
      {
          (*((volatile unsigned long *)(base_add_port|GPIO_DATA_OFFSET))) &= ~(1<<pin);;

      }


}

unsigned char DIO_get_pin_value(unsigned char PORT,unsigned char pin)
{

    unsigned long base_add_port=0;

    if(PORT==PORT_A)             base_add_port=PORTA_BASE_ADD;
    else if(PORT==PORT_B)        base_add_port=PORTB_BASE_ADD;
    else if(PORT==PORT_C)        base_add_port=PORTC_BASE_ADD;
    else if(PORT==PORT_D)        base_add_port=PORTD_BASE_ADD;
    else if(PORT==PORT_E)        base_add_port=PORTE_BASE_ADD;
    else if(PORT==PORT_F)        base_add_port=PORTF_BASE_ADD;


      return((*((volatile unsigned long *)(base_add_port|GPIO_DATA_OFFSET)))&(1<<pin));


}


