#include "buzz.h"

using namespace std;

Buzz::Buzz(int pin){
	
	myPin = pin;
	
	//int freqNotes[] = {261, 294, 329, 349, 392, 440, 493};
	// frÃquence gamme 3                                        
	/*
        this->freqNotes[0] = 262;
	this->freqNotes[1] = 294; 
	this->freqNotes[2] = 330;
	this->freqNotes[3] = 349;
        this->freqNotes[4] = 392;
	this->freqNotes[5] = 440;
	this->freqNotes[6] = 494;
	this->freqNotes[7] = 277;
        this->freqNotes[8] = 311;
        this->freqNotes[9] = 370;
        this->freqNotes[10] = 415;
        this->freqNotes[11] = 494;
	*/

	this->freqNotes[0] = 523;                               
        this->freqNotes[1] = 587;                               
        this->freqNotes[2] = 659;                               
        this->freqNotes[3] = 698;                               
        this->freqNotes[4] = 784;                               
        this->freqNotes[5] = 880;                               
        this->freqNotes[6] = 988;
        this->freqNotes[7] = 554;
        this->freqNotes[8] = 622;
        this->freqNotes[9] = 740;
        this->freqNotes[10] = 831;
        this->freqNotes[11] = 932;

        
	/*                                                        
        //int periodNotes[] = {3830, 3400, 3038, 2864, 2550, 2272, 2028};
                                        
        //int periodNotes[7];                                                     
        this->periodNotes[0] = (int)(1000000.0/(float)freqNotes[0]);
	this->periodNotes[1] = (int)(1000000.0/(float)freqNotes[1]);  
	this->periodNotes[2] = (int)(1000000.0/(float)freqNotes[2]);  
        this->periodNotes[3] = (int)(1000000.0/(float)freqNotes[3]); 
	this->periodNotes[4] = (int)(1000000.0/(float)freqNotes[4]); 
	this->periodNotes[5] = (int)(1000000.0/(float)freqNotes[5]); 
	this->periodNotes[6] = (int)(1000000.0/(float)freqNotes[6]);                        
                                        
        //int timeHNotes[7];                                                  
        this->timeHNotes[0] = (int)((float)periodNotes[0]/2.0); 
	this->timeHNotes[1] = (int)((float)periodNotes[1]/2.0); 
	this->timeHNotes[2] = (int)((float)periodNotes[2]/2.0); 
        this->timeHNotes[3] = (int)((float)periodNotes[3]/2.0); 
	this->timeHNotes[4] = (int)((float)periodNotes[4]/2.0); 
	this->timeHNotes[5] = (int)((float)periodNotes[5]/2.0); 
        this->timeHNotes[6] = (int)((float)periodNotes[6]/2.0); 
	*/

	for(int i = 0 ; i < NB_MAX_NOTES ; i++){
		this->periodNotes[i] = (int)(1000000.0/(float)(this->freqNotes[i])); 
		this->timeHNotes[i] = (int)((float)(this->periodNotes[i]/2.0));
	}

	myPeriod = periodNotes[LA];
	myBuzz = mraa_pwm_init(myPin);
	if(myBuzz == NULL){
		cout << "error init PWM" << endl;
	}

	mraa_result_t a = mraa_pwm_enable(myBuzz, 1);
	if(a != MRAA_SUCCESS){
		cout << "error enable pwm" << endl;
	}
	mraa_pwm_period_us(myBuzz, myPeriod);
        mraa_pwm_pulsewidth_us(myBuzz, timeHNotes[LA]);

	setVolume(1.0);
}

Buzz::~Buzz(){
	Buzz::stopSound();
	mraa_pwm_enable(myBuzz, 0);
	mraa_pwm_close(myBuzz);
}
/*
int Buzz::playSound(int note){
	mraa_pwm_enable(myBuzz, 1);
	mraa_pwm_period_us(myBuzz, periodNotes[note]);
	mraa_pwm_pulsewidth_us(myBuzz, timeHNotes[note]);
	//mraa_pwm_write(myBuzz, 0.5*volume);
	if(delay){
        	usleep(delay);
        	Buzz::stopSound();
    	}
	return note;
}*/

int Buzz::playSound(int note, int delay){
	mraa_pwm_period_us(myBuzz, periodNotes[note]);
	mraa_pwm_pulsewidth_us(myBuzz, timeHNotes[note]);
	if(delay){
		usleep(delay);
		Buzz::stopSound();
	}
	return note;
}

void Buzz::playMelody(int *melody, int *duree){
	for(unsigned int i = 0 ; i < (sizeof(melody)/sizeof(melody[0])); i++){    
        	Buzz::playSound(melody[i], duree[i]*250000);
        	usleep(100*1000);     
        }
	Buzz::stopSound(); 
}

void Buzz::stopSound(){
	mraa_pwm_period_us(myBuzz, 1);
	mraa_pwm_write(myBuzz, 0);
}

void Buzz::setVolume(float vol){
	//this->volume = vol;
	volume = vol;
}
