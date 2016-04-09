#include "games.h"

Games::Games(){
	Games::myNumGame = 1;
	Games::setGame0();
}

Games::~Games(){}

int Games::setGame0(){ // interactions de base Ã rajouter
	while(1){
		Games::myScreen.write("'Bonjour~ !'", 0, 1);

		if(A.read()){
			Games::myScreen.write("'ByeBye !'", 0, 5);
		} else {
			Games::myScreen.write("'Yoho !'", 0, 6);
		}
	}
	return 0;
}

int Games::setGame1(){ // nourrir
	Games::myScreen.write("'J'ai faim !'", 0, 0);
	if(A.read()){
		Games::myScreen.write("'Merci !!'", 0, 0); 
	} else if(B.read()){
		Games::myScreen.write("'MÃchant !'", 0, 0); 
	} else if(C.read()){
		Games::myScreen.write("'Hey ! (>_<)'", 0, 0); 
	}
	return (0); 
}

int Games::setGame2(){
        return (0);   
}

int Games::setGame3(){
        return (0);   
}

