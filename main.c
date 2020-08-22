/*
 *
 *  Created on: 22/8/2020
 *      Author: Nmr
 */
#include"DIO.h"


int main(void) {

    int PF0;
    int PF4;

    DIO_init_pin(PORT_F,0,INPUT);
    DIO_init_pin(PORT_F,1,OUTPUT);
    DIO_init_pin(PORT_F,2,OUTPUT);
    DIO_init_pin(PORT_F,3,OUTPUT);
    DIO_init_pin(PORT_F,4,INPUT);

    DIO_enable_pull_resistor(PORT_F,0,PULL_UP_RESISTOR);
    DIO_enable_pull_resistor(PORT_F,4,PULL_UP_RESISTOR);

    DIO_set_pin_value(PORT_F,3,HIGH);


        while(1){

        PF0 =DIO_get_pin_value(PORT_F,0);
        PF4 =DIO_get_pin_value(PORT_F,4);

        if(!PF0&&PF4)
        {
            DIO_set_pin_value(PORT_F,1,HIGH);
            DIO_set_pin_value(PORT_F,2,LOW);
            DIO_set_pin_value(PORT_F,3,LOW);
        }
        if(PF0&&!PF4)
        {
            DIO_set_pin_value(PORT_F,1,LOW);
            DIO_set_pin_value(PORT_F,2,HIGH);
            DIO_set_pin_value(PORT_F,3,LOW);
        }
        if(!PF0&&!PF4)
        {
            DIO_set_pin_value(PORT_F,1,LOW);
            DIO_set_pin_value(PORT_F,2,LOW);
            DIO_set_pin_value(PORT_F,3,HIGH);
        }

        }

    //End of the code...
}
