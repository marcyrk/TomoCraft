#include "move.h"

int main(){
	Move testMove;
	testMove.react(1,5);
	cout << testMove.getEmotion().getKokoro() << endl;	
	return (0);
}
