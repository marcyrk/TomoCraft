#ifndef GAMES_H
#define GAMES_H

#include "capteurs.h"
#include "actionneurs.h"
#include "move.h"

class Games{
	private:
		int myNumGame;
		Move myMove;
		Button A = Button(6);
                Button B = Button(7);
                Button C = Button(8);
		LCD myScreen;
	public:
		Games();
		~Games();

		int setGame0(); // interactions de base a coder (oui/non)
		int setGame1();	// nourrir (sequence de texte et de mimiques a coder)
		// a implementer si on a d autres idees
		int setGame2(); 
		int setGame3();
};


#endif
