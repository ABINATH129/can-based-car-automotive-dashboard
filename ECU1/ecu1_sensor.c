#include "ecu1_sensor.h"
#include "adc.h"
#include "can.h"
#include "msg_id.h"
#include "uart.h"

uint16_t get_rpm()
{
    //Implement the rpm function
    unsigned short ret = read_adc(RPM_ADC_CHANNEL);
        
        //SPEED
        if(ret > 23)
            ret = (ret-23)*6;
    return ret;
}

IndicatorStatus process_indicator()
{
    //Implement the indicator function
    unsigned char key = read_digital_keypad(STATE_CHANGE);
    unsigned char once1 = 1;
    unsigned char once2 = 1;
    unsigned char once3 = 1;
    static IndicatorStatus state = e_ind_off; 

    //LEFT
    if(key == 0x0E && once1)
    {
        once1 = 0;
//        RIGHT_IND_OFF();
//        LEFT_IND_ON();
        state = e_ind_left;
    }
    else if(key == 0xFF)
    {
        once1 = 1;
    }
    //RIGHT
    if(key == 0x0B && once2)
    {
        once2 = 0;
//        LEFT_IND_OFF();
//        RIGHT_IND_ON();
        state = e_ind_right;
    }
    else if(key == 0xFF)
    {
        once2 = 1;
    }
    //OFF
    if(key == 0x0D && once3)
    {
        once3 = 0;
//        LEFT_IND_OFF();
//        RIGHT_IND_OFF();
        state = e_ind_off;
    }
    else if(key == 0xFF)
    {
        once3 = 1;
    }
    
    return state;
}