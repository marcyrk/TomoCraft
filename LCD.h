#ifndef LCD_H
#define LCD_H

#include "mraa/i2c.h"                                        
#include <unistd.h>                                           
#include <iostream>                                            
#include <string>

#define LCD_CLEARDISPLAY 0x01                                
#define LCD_ENTRYMODESET 0x04                                  
#define LCD_FUNCTIONSET 0x20                                 
#define LCD_DATA 0x40                                        
#define LCD_CMD 0x80                                              
#define LCD_DISPLAYCONTROL 0x08                              
#define LCD_DISPLAYON 0x04                                 

// flags for display entry mode                              

#define LCD_ENTRYLEFT 0x02                                        
#define LCD_ENTRYSHIFTDECREMENT 0x00                                           
#define LCD_2LINE 0x08       

/*****************************************************/
/*                        LCD                        */
/*****************************************************/                               

using namespace std;

class LCD {

protected:
	int m_bus=0;     
	int m_lcd_control_address=0x3E;                              
	int m_rgb_control_address=0x62;                                
	mraa_result_t i2cData (mraa_i2c_context ctx, uint8_t value) {
		mraa_result_t error = MRAA_SUCCESS;                                 
		uint8_t data[2] = { LCD_DATA, value };                 
		error = mraa_i2c_address (ctx, m_lcd_control_address);   
		error = mraa_i2c_write (ctx, data, 2);                   
		return error;                                                              
	}                                                         
		                                                        
	mraa_result_t i2Cmd (mraa_i2c_context ctx, uint8_t value) {                    
		mraa_result_t error = MRAA_SUCCESS;            
		    uint8_t data[2] = { LCD_CMD, value };                    
		//error = mraa_i2c_address (ctx, m_lcd_control_address);   
		error = mraa_i2c_write (ctx, data, 2);                   
		return error;                                            
	}                                                            
		                                                              
	mraa_result_t i2cReg (mraa_i2c_context ctx, int deviceAdress, int addr, uint8_t value) {
		mraa_result_t error = MRAA_SUCCESS;                    
		uint8_t data[2] = { (uint8_t)addr, value };                       
		error = mraa_i2c_address (ctx, deviceAdress);                 
		error = mraa_i2c_write (ctx, data, 2);                                     
		return error;                                             
	}           

	int row_addr[4];
	uint8_t offset;
	string msg;
	mraa_i2c_context m_i2c_lcd_control, m_i2c_lcd_rgb;
	
	void initLCD(){                                                   
		//mraa_i2c_context m_i2c_lcd_control, m_i2c_lcd_rgb;       
		// initialisation                                                          
		m_i2c_lcd_control = mraa_i2c_init(m_bus);                  
		mraa_i2c_address(m_i2c_lcd_control, m_lcd_control_address);
		m_i2c_lcd_rgb = mraa_i2c_init(m_bus);                         
		mraa_i2c_address(m_i2c_lcd_rgb, m_rgb_control_address);                    
		usleep(50000);                                         
		i2Cmd (m_i2c_lcd_control, LCD_FUNCTIONSET | LCD_2LINE);    
		usleep(4500);                                            
		i2Cmd (m_i2c_lcd_control, LCD_FUNCTIONSET | LCD_2LINE);       
		usleep(4500);                                                              
		i2Cmd (m_i2c_lcd_control, LCD_FUNCTIONSET | LCD_2LINE);
		usleep(4500);                                              
		i2Cmd (m_i2c_lcd_control, LCD_FUNCTIONSET | LCD_2LINE);       
		i2Cmd (m_i2c_lcd_control, LCD_DISPLAYCONTROL | LCD_DISPLAYON);
		i2Cmd (m_i2c_lcd_control, LCD_CLEARDISPLAY);                               
		usleep(4500);                                   
		i2Cmd (m_i2c_lcd_control, LCD_ENTRYMODESET |               
		       LCD_ENTRYLEFT |                                   
		       LCD_ENTRYSHIFTDECREMENT);                              
		i2cReg (m_i2c_lcd_rgb, m_rgb_control_address, 0, 0);                       
		i2cReg (m_i2c_lcd_rgb, m_rgb_control_address, 1, 0);       
		i2cReg (m_i2c_lcd_rgb, m_rgb_control_address, 0x08, 0xAA);
		

		// modifier ces 3 valeurs pour modifier la couleur du fond par defaut en blanc

		i2cReg (m_i2c_lcd_rgb, m_rgb_control_address, 0x04, 255);     
		i2cReg (m_i2c_lcd_rgb, m_rgb_control_address, 0x03, 255);                  
		i2cReg (m_i2c_lcd_rgb, m_rgb_control_address, 0x02, 255);

		// positionnement                         
		int row=0, column=3;                        
		this->row_addr[0] = 0x80;
        	this->row_addr[1] = 0xc0;
        	this->row_addr[2] = 0x14;             
        	this->row_addr[3] = 0x54;   
		//row_addr = {0x80, 0xc0, 0x14, 0x54};              
		offset = ((column % 16) + row_addr[row]);          

		i2Cmd (m_i2c_lcd_control, offset);                            


		// écriture d'un texte                                                     

		this->msg="TOMOCRAFT!";                                
		usleep(1000);          
		for (std::string::size_type i = 0; i < msg.size(); ++i) {     
		    i2cData (m_i2c_lcd_control, msg[i]);                                   
		}                                                        

		// fin                                                        
		sleep(1);                                                     
		//mraa_i2c_stop(m_i2c_lcd_control);
	}       

public :
	// constructeur
	LCD();

	// fonctions de base

	void setRGB(int R, int G, int B);	// changer la couleur RGB de l'écran
	void setCursor(int row, int col);
	void write(string msg, int row, int col);	// ecrire un message
	void clear();

	// destructeur
	~LCD();
};

#endif                                 

