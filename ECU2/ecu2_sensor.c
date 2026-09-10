#include "ecu2_sensor.h"
#include "adc.h"
#include "can.h"
#include "uart.h"

uint16_t get_speed()
{
    // Implement the speed function
    unsigned int ret = read_adc(CHANNEL4);
        if(ret > 0)
            ret = ((ret/10.23)-1);
    return ret;
}

unsigned char get_gear_pos()
{
    // Implement the gear function
    unsigned char once0 = 1;
    unsigned char once1 = 1;
    unsigned char once2 = 1;
    unsigned char key = read_digital_keypad(STATE_CHANGE);
    static unsigned char gear = 0;
    if(key == 0x0E && once0)
    {
        if(gear == 7)
        {
            gear = 0;
        }
        else if(gear < 6)
        {
            gear++;
        }
        once0 = 0;
    }
    if(key == 0xFF)
    {
        once0 = 1;
    }

    if(key == 0x0D && once1)
    {
        if(gear == 7)
        {
            gear = 0;
        }
        else if(gear > 0)
        {
            gear--;
        }
        once1 = 0;
    }
    if(key == 0xFF)
    {
        once1 = 1;
    }

    if(key == 0x0B && once2)
    {
        gear = 7;
        once2 = 0;
    }
    if(key == 0xFF)
    {
        once2 = 1;
    }
    
    return gear;
}