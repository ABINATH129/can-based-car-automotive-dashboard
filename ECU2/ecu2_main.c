#include "ecu2_sensor.h"
#include "adc.h"
#include "can.h"
#include "uart.h"
#include "msg_id.h"

#define _XTAL_FREQ 20000000

int main()
{
    
    TRISC0 = 1;
    TRISC1 = 1;
    TRISC2 = 1;
    
    init_adc();
    init_uart();
    init_can();
    
    //call the functions
    while(1)
    {
        //SPEED
        uint16_t ret = get_speed();
        unsigned char data_arr[8];
        
        unsigned char ch = (ret /10) + 48;
        data_arr[0] = ch;
        ch = (ret %10) + 48;
        data_arr[1] = ch;
        
        can_transmit(SPEED_MSG_ID, data_arr, 2);
        for(int wait = 3000; wait--;);

        //GEAR
        unsigned char gears[] = {'N','1','2','3','4','5','R','C'};
        unsigned char g = get_gear_pos();
        
        can_transmit(GEAR_MSG_ID, &gears[g], 1);
        for(int wait = 3000; wait--;);
    }
}
