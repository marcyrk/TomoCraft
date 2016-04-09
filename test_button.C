#include "button.h"
#include <iostream>

int main(){

	Button testButton(2);
	
	while(1){

		if (testButton.getButton()){
			cout << "coucou" << endl;
		} else {
			cout << "bye" << endl;
		}
	}
	return (0);
}
