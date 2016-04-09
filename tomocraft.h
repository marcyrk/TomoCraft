#ifndef TOMOCRAFT_H
#define TOMOCRAFT_H

#include "move.h"
#include "games.h"

class Tomocraft {
	private:
		int myMood; // mode (heureux, colere, neutre)
		int myKokoro; // niveau de bonheur
	public:
		Tomocraft();
		~Tomocraft();

		// getters
		int getMood();

		// setters
		void setMood(int mood);

		int startMusicGame();
};

#endif
