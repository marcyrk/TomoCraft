#include "tomocraft.h"

Tomocraft::Tomocraft(){
	// init attributs
	myMood = HAPPY;
	
	// init des differentes parties
	/*
	LED	happiness(2);
	Serv	head(3);
	LED	eyes(4);
	Buzz	voice(5);
	Button	A(6), B(7), C(8);
	LCD	screen;
	*/
	Move myMove;
}

Tomocraft::~Tomocraft(){}

int Tomocraft::getMood(){
	return myMood;
}

void Tomocraft::setMood(int mood){
	myMood = mood;
}
