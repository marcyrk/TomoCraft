#include "touch.h"
#include "LED.h"

	Touch testTouch(4);
	LED testLED(8);

int main(){

	while(1){
		if(testTouch.getTouch()){
			testLED.ON();
		} else {
			testLED.OFF();
		}

	}
	return (0);
}
