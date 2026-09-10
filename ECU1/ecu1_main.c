#include "adc.h"
#include "can.h"
#include "ecu1_sensor.h"
#include "msg_id.h"
#include "uart.h"

#define _XTAL_FREQ 20000000

int main()
{
    init_adc();
    init_uart();
    init_can();
    //Call the functions
    unsigned char indicator = 0;
    unsigned char ind = 'O';
    uint8_t data_arr[8];

    while(1)
    {
        uint16_t  ret = get_rpm();
        unsigned char ch = (ret / 1000) + 48;
        data_arr[0] = ch;
        ch = ((ret / 100) % 10) + 48;
        data_arr[1] = ch;
        ch = ((ret / 10) % 10) + 48;
        data_arr[2] = ch;
        ch = (ret %10) + 48;
        data_arr[3] = ch;
        
        can_transmit(RPM_MSG_ID, data_arr, 4);
        for(int wait = 3000; wait--;);
        
        //INDIGATOR
        indicator = process_indicator();
        if(indicator == e_ind_left)
        {
            ind = 'L';
        }
        else if(indicator == e_ind_right)
        {
            ind = 'R';
        }
        else if(indicator == e_ind_off)
        {
            ind = 'O';
        }
        
        can_transmit(INDICATOR_MSG_ID, &ind, 1);
        for(int wait = 3000; wait--;);

    }
}