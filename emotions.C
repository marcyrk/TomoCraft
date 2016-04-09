#include "emotions.h"

Emotions::Emotions(){
	myMode = -1;
	setKokoro(50);	// on commence neutre
}

Emotions::~Emotions(){}	// destructeur de base

int Emotions::setEmotion(int mode){
	myMode = mode;	
	return mode;
}

int Emotions::setKokoro(int star){
	myKokoro = star;
	return myKokoro;
}

int Emotions::addKokoro(int star){
	myKokoro += star;
	return myKokoro;
}

int Emotions::delKokoro(int star){
        myKokoro -= star;         
        return myKokoro;          
}  

int Emotions::getMood(){
	return myMode;
}

int Emotions::getKokoro(){
	return myKokoro;
}
