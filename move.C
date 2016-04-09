#include "move.h"
/*
		LED myKokoro(2);
		Serv myhead(3);
		LED myEyes(4);
		Buzz myVoice(5);
		Button A(6), B(7), C(8);
		LCD myScreen;	
		Emotions myFeels;
*/
Move::Move(){
	myEyes.ON();
	myKokoro.ON();
	// REMPLACER LES FONCTIONS SUIVANTES PAR UN PLAY MELODY
	/*
	int melody1[7] = {DO, DO, SOL, SOL, LA, LA, SOL};
        int melody2[7] = {FA, FA, MI, MI, RE, RE, DO};
        int melody3[7] = {SOL, SOL, FA, FA, MI, MI, RE};
        int melody4[7] = {SOL, SOL, FA, FA, MI, MI, RE};
        int melody5[7] = {DO, DO, SOL, SOL, LA, LA, SOL};
        int melody6[7] = {FA, FA, MI, MI, RE, RE, DO};   
                                                      
        int duree[7] = {1, 1, 1, 1, 1, 1, 2};*/
	//myVoice.playMelody(melody1, duree);
	//sleep(1);
	//myVoice.stopSound();
	Move::setMoveMood(myFeels.getMood());
}

Move::~Move(){}
		
int Move::setMoveMood(int mood){
	switch(mood){
		case -1:
			this->myEyes.OFF();
			this->myScreen.write("IDLE STATE", 0, 0);
			this->myHead.setAngle(0.0);
		case 0:
			for(int i = 0 ; i < 2 ; i++){
				this->myEyes.blink(2, 1000);
				this->myHead.sayNO(500);
			}

			break;
		case 1:
			for(int i = 0 ; i < 2 ; i++){          
                                this->myEyes.blink(3, 500);        
                                this->myHead.sayNO(1000);             
                        }                                      
                        break;  
		case 2:
			for(int i = 0 ; i < 2 ; i++){          
                                this->myEyes.blink(10, 2000);
				this->myVoice.playSound(FA_d, 250000);
				this->myVoice.stopSound();         
                                this->myHead.sayNO(500);             
                        }                                      
                        break;  
		//case 3:

			break;

		default:
			break;
				
	
	}
	return (0);	
}

int Move::react(int answer, int star){
	switch(answer){
		case 0:
			this->myScreen.setRGB(255, 10, 10);
			this->myHead.sayNO(200); 
			this->myEyes.blink(2, 500);
			this->myEyes.OFF();
			this->myFeels.delKokoro(star);
			break;
		case 1:
			this->myScreen.setRGB(150, 150, 150);
			this->myHead.sayNO(400);
			this->myEyes.blink(3, 1000);
			this->myEyes.ON();                           
                        this->myFeels.addKokoro(star);  
			break;


	}
	return 0;
}

Emotions Move::getEmotion(){
	return this->myFeels;
}
