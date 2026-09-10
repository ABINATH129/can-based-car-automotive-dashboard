#include <xc.h>
#include <string.h>
#include "message_handler.h"
#include "msg_id.h"
#include "can.h"
#include "clcd.h"
#include "uart.h"
#include "timer0.h"

uint16_t msg_id;
uint8_t data[8];
uint8_t len;
    


volatile unsigned char led_state = LED_OFF, status = e_ind_off;


void handle_speed_data(uint8_t *data, uint8_t len)
{
    //Implement the speed function
    clcd_print("SPD ",LINE1(9));
    clcd_print(data,LINE2(9));
    clcd_putch(' ', LINE2(11));
    clcd_putch(' ', LINE2(12));
}

void handle_gear_data(uint8_t *data, uint8_t len) 
{
    //Implement the gear function
    clcd_print("GER",LINE1(13));
    clcd_putch(' ', LINE2(13));
    clcd_putch(data[0], LINE2(14));
    clcd_putch(' ', LINE2(15));
}

void handle_rpm_data(uint8_t *data, uint8_t len) 
{
//    Implement the rpm function
    clcd_print("RPM ",LINE1(0));
    clcd_print(data, LINE2(0));
    clcd_putch(' ', LINE2(4));
}

void handle_indicator_data(uint8_t *data, uint8_t len) 
{
    //Implement the indicator function
    clcd_print("IND",LINE1(5));
    clcd_putch(' ', LINE2(5));
    clcd_putch(data[0], LINE2(6));
    clcd_putch(' ', LINE2(7));
    if(data[0] == 'L')
    {
        RIGHT_IND_OFF();
        LEFT_IND_ON();
    }
    if(data[0] == 'O')
    {
        RIGHT_IND_OFF();
        LEFT_IND_OFF();
    }
    if(data[0] == 'R')
    {
        RIGHT_IND_ON();
        LEFT_IND_OFF();
    }
    
    
}

void process_canbus_data() 
{   
    //process the CAN bus data
   
    can_receive(&msg_id, data, &len);
    

   if(msg_id == RPM_MSG_ID)
   {
       data[len] = '\0';
       handle_rpm_data(data, len);
   }
   if(msg_id == INDICATOR_MSG_ID)
   {
       handle_indicator_data(data, len);
   }
   if(msg_id == SPEED_MSG_ID)
   {
       data[len] = '\0';
       handle_speed_data(data, len);
   }
   if(msg_id == GEAR_MSG_ID)
   {
       handle_gear_data(data, len);
   }
}