#ifndef EMOTIONS_H
#define EMOTIONS_H

#include "capteurs.h"
#include "actionneurs.h"

/*
#include "LED.h"
#include "serv.h"
#include "LCD.h"
*/
#define IDLE	(-1)
#define ANGER   (0)
#define NEUTRAL (1)
#define HAPPY   (2)
#define CRAZY	(3)

#define MAX_KOKORO	(100)
#define MID_KOKORO	(50)
#define MIN_KOKORO	(0)

class Emotions{
	private:
		int myMode;	// ANGER NEUTRAL HAPPY
		int myKokoro;	// niveau de bonheur
	public:

		Emotions();
		~Emotions();

		// setters
		int setEmotion(int mode);
		int setKokoro(int star);
		int addKokoro(int star);
		int delKokoro(int star);

		// getters
		int getMood();
		int getKokoro();
};
#endif

