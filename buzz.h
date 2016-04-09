#ifndef BUZZ_H
#define BUZZ_H

#include <iostream>
#include <string>
#include <mraa/gpio.h>
#include <mraa/pwm.h>
#include <unistd.h>

#define  DO	(0)     //3830	  261 Hz
#define  RE	(1)     //3400    294 Hz
#define  MI     (2)	//3038    329 Hz
#define  FA     (3)	//2864    349 Hz
#define  SOL    (4)	//2550    392 Hz
#define  LA     (5)	//2272    440 Hz
#define  SI     (6)     //2028    493 Hz

#define  DO_d	(7)	//	277 Hz
#define  RE_b	(7)
#define  RE_d	(8)	//	311 Hz
#define  MI_b	(8)
#define  FA_d	(9)	//	370 Hz
#define  SOL_b	(9)
#define  SOL_d  (10)    //      415 Hz  
#define  LA_b   (10)
#define  LA_d	(11)	//	466 Hz
#define  SI_b	(11)


#define	NB_MAX_NOTES	12

using namespace std;

class Buzz {

protected:
	int myPin;
	int myPeriod;
	mraa_pwm_context myBuzz;
	float volume;
	int freqNotes[NB_MAX_NOTES];
	int periodNotes[NB_MAX_NOTES];
	int timeHNotes[NB_MAX_NOTES];
	/*
	//int freqNotes[] = {261, 294, 329, 349, 392, 440, 493};

	int freqNotes[7];
	freqNotes[0] = 261; freqNotes[1] = 294; freqNotes[2] = 329; freqNotes[3] = 349;
	freqNotes[4] = 392; freqNotes[5] = 440; freqNotes[6] = 493;   

	//int periodNotes[] = {3830, 3400, 3038, 2864, 2550, 2272, 2028};

	int periodNotes[7];
	periodNotes[0] = 3830; periodNotes[1] = 3400; periodNotes[2] = 3038;  
	periodNotes[3] = 2864; periodNotes[4] = 2550; periodNotes[5] = 2272;
	periodNotes[6] = 2028;    

	//int timeHNotes[] = {1915, 1700, 1519, 1432, 1275, 1136, 1014};

	int timeHNotes[7];
	timeHNotes[0] = 1915; timeHNotes[1] = 1700; timeHNotes[2] = 1519;
	timeHNotes[3] = 1432; timeHNotes[4] = 1275; timeHNotes[5] = 1136;
	timeHNotes[6] = 1014;
	*/
public:
	Buzz(int pin);

	~Buzz();

	// Setters
	//int playSound(int note);
	int playSound(int note, int delay);
	
	void setVolume(float vol);
	void stopSound();


	// RAJOUTER UN PLAY MELODY !!!
	void playMelody(int *melody, int *duree);
	// Getters
	float getVolume();	
};

#endif
