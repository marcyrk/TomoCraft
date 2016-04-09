#include "fichier.h"
#include <string>

using namespace std;

Fichier::Fichier(string name_file){
	this->QAP.myQuestion = "";
	this->QAP.myAnswer = "";
	this->QAP.myPoints = 0;
	
	this->myFile = Fichier::openFile(name_file);
	//this->myFile = Fichier::openFile("myQuestionsFile.txt");
	//myMelody_struct.myMelody = ;
	//myMelody_struct.myTempo = ; 
}

Fichier::~Fichier(){
	fclose(myFile);
}

FILE * Fichier::openFile(string name_file){
  	myFile = fopen(name_file.c_str(),"r");
  	if (myFile == NULL){
		cout << "erreur ouverture fichier" << endl;
	} else {
		return myFile;
	}
	return myFile;
}

string Fichier::pickAQuestion(FILE* monFichier){
	int a = 3; // random number
	int b = 0;
	char *c = NULL;
	string line = "";
	//FILE * monFichier = Fichier::openFile("myQuestionsFile.txt");
	while(b != a){
		fgets(c, 100, monFichier); 
		b++;
	}
	line = (string)(c);	
	return line;
}

Fichier::myQuestion_t Fichier::splitQuestion(string line){
	myQuestion_t monRetour;
	string tmp = "";
	int cpt = 0;
	string q = "";
	string a = "";
	string p = "";
	for(int i=0 ; line[i] ; i++){
		if(line[i] != ';'){
			tmp += line[i];
		} else {
			if(cpt == 0){
				q = tmp;
			} else if(cpt == 1){
				a = tmp;
			} else if(cpt == 2) {
				p = tmp;
			}
			cpt++;
			tmp = "";
		}
	}
	monRetour.myQuestion = q;
	monRetour.myAnswer = a;
	monRetour.myPoints = stoi(p);
	return monRetour;
}

FILE * Fichier::getFile(){
	return myFile;
} 

/*
string Fichier::pickAMelody(string name_file){ 
	ifstream monFichier = Fichier::openFile(name_file);
}*/

