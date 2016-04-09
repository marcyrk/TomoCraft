#include "fichier.h"

int main(){
	Fichier testFichier("myQuestionsFile.txt");
	cout << "apres la creation du fichier" << endl;
	cout << testFichier.pickAQuestion(testFichier.getFile()) << endl;
	return (0);
}
