#ifndef MOVE_H
#define MOVE_H

#include "emotions.h"
#include "capteurs.h"
#include "actionneurs.h"

class Move{
	protected:
		LED myKokoro = LED(2);
		Serv myHead = Serv(3);
		LED myEyes = LED(4);
		Buzz myVoice = Buzz(5);
		Button A = Button(6);
		Button B = Button(7);
		Button C = Button(8);
		LCD myScreen;	
		Emotions myFeels;
	public:
		Move();
		~Move();
		
		// execution de mouvements selon l humeur
		int setMoveMood(int mood);

		int react(int answer, int star);

		Emotions getEmotion();
};

#endif
