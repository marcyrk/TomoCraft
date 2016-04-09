#include "LCD.h"                                   

using namespace std;                                                   

LCD::LCD(){
	initLCD();
}

void LCD::setRGB(int R, int G, int B){
	i2cReg (m_i2c_lcd_rgb, m_rgb_control_address, 0x04, R);
	i2cReg (m_i2c_lcd_rgb, m_rgb_control_address, 0x03, G);
	i2cReg (m_i2c_lcd_rgb, m_rgb_control_address, 0x02, B);
}

void LCD::setCursor(int row, int col){
	this->row_addr[0] = 0x80;
        this->row_addr[1] = 0xc0;
        this->row_addr[2] = 0x14;
        this->row_addr[3] = 0x54;
	this->offset = ((col%16) + row_addr[row]);
	i2Cmd (m_i2c_lcd_control, offset); 
}

void LCD::write(string msg, int row, int col){
	clear();
	LCD::setCursor(row, col);
	for (std::string::size_type i = 0; i < msg.size(); ++i) { 
        	i2cData (m_i2c_lcd_control, msg[i]);;                
        }
        sleep(1);                                                
}

void LCD::clear(){
	int row = 2;
	int col = 16;
	for(int i = 0 ; i<row ; ++i){
		setCursor(i, 0);
		for(int j = 0 ; j<col ; ++j){	
			i2cData(m_i2c_lcd_control, ' ');
		}
	}
	setCursor(0,0); // voir lequel est le plus utile
}

LCD::~LCD(){
	mraa_i2c_stop(m_i2c_lcd_control);
}
