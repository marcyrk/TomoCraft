#include "serv.h"

using namespace std;

Serv::Serv(int pin){
	myPin = pin;
	myMinPW = MIN_PULSE_WIDTH;
	myMaxPW = MAX_PULSE_WIDTH;
	myPeriod = PERIOD;
	//mraa_pwm_context PWM;                                                   
        myPWM = mraa_pwm_init(pin);
	cout << myPWM << endl;
	/*
        mraa_pwm_enable(myPWM, 1);
        mraa_pwm_period_us(myPWM, myPeriod);                                        
	mraa_pwm_pulsewidth_us(myPWM, MIN_PULSE_WIDTH);
	*/
	Serv::setAngle(90.0);
	//myPWM = PWM;      
}

Serv::~Serv(){
	mraa_pwm_close(myPWM);
}

void Serv::setMinPW(int w){
	myMinPW = w;
}

void Serv::setMaxPW(int w){
	myMaxPW = w;
}

void Serv::setAngle(float a){
	mraa_pwm_enable(myPWM, HIGH);          
        mraa_pwm_period_us(myPWM, myPeriod);  
	mraa_pwm_pulsewidth_us(myPWM, (int)((float)(MIN_PULSE_WIDTH)+(a/(float)180)*(((float)MAX_PULSE_WIDTH - (float)MIN_PULSE_WIDTH)) ));
	sleep(1);
	mraa_pwm_enable(myPWM, LOW);
}

void Serv::sayNO(int timePause){
	Serv::goFront();                                                   
        usleep(timePause*1000);    
	Serv::setAngle(30.0);
	usleep(timePause*1000);
	Serv::setAngle(160.0);                                                   
        usleep(timePause*1000);    
	Serv::goFront();
}

void Serv::goFront(){
	Serv::setAngle(90.0);
}  

int Serv::getMinPW(){
	return myMinPW;
}

int Serv::getMaxPW(){
	return myMaxPW;
}

int Serv::getPeriod(){
	return myPeriod;
}

float Serv::getPWM(){
	return mraa_pwm_read(myPWM);	
}
