#include "mraa/i2c.h"
#include <unistd.h>
#include <iostream>
#include <string>

mraa_result_t i2cReg (mraa_i2c_context ctx, int deviceAdress, int addr, uint8_t value) {
                mraa_result_t error = MRAA_SUCCESS;   
                uint8_t data[2] = { (uint8_t)addr, value };           
                error = mraa_i2c_address (ctx, deviceAdress);
                error = mraa_i2c_write (ctx, data, 2);               
                return error;                                                  
        }

int main(){
	                                                                
        int m_bus=0;                                                   
	int m_lcd_control_address=0x3E;                                        
        int m_rgb_control_address=0x62;
	mraa_i2c_context m_i2c_lcd_rgb;
	m_i2c_lcd_rgb = mraa_i2c_init(m_bus);   
	int R = 255;
	int G = 0;
	int B = 0;  
	i2cReg (m_i2c_lcd_rgb, m_rgb_control_address, 0x04, R); 
        i2cReg (m_i2c_lcd_rgb, m_rgb_control_address, 0x03, G); 
        i2cReg (m_i2c_lcd_rgb, m_rgb_control_address, 0x02, B); 

	return (0);
}
