#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

class Fichier{
	protected:
		typedef struct Question{
			string myQuestion;
			string myAnswer;
			int myPoints;
		} myQuestion_t;

		myQuestion_t QAP;

		FILE * myFile;

		/*
		typedef struct Melody{
			int* myMelody;
			int* myTempo;
		} myMelody_t;
		*/

	public:
		Fichier(string name_file);
		~Fichier();		
		// ouverture de fichier
		FILE * openFile(string name_file);

		// decoupage d'une ligne en struct question
		myQuestion_t splitQuestion(string line);

		// getter file
		FILE * getFile();

		// decoupage d'une ligne en struct melody
		//struct Melody splitMelody(string line);

		// choix d'une question
		string pickAQuestion(FILE* monFichier);

		// choix d'une melodie
		//string pickAMelody(string name_file);

};
