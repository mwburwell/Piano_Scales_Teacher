#pragma once
#include <vector>
#include <string>
#include <map>

enum class Note {C,DFlat,D,EFlat,E,F,GFlat,G,AFlat,A,BFlat,B};
std::map<Note,std::string> noteToString {
    {Note::C, "C"},
    {Note::DFlat, "D-flat"},
    {Note::D, "D"},
    {Note::EFlat, "E-flat"},
    {Note::E, "E"},
    {Note::F, "F"},
    {Note::GFlat, "G-flat"},
    {Note::G, "G"},
    {Note::AFlat, "A-flat"},
    {Note::A, "A"},
    {Note::BFlat, "B-flat"},
    {Note::B, "B"}
};
enum class Sharps {CSharp,DSharp,ESharp,FSharp,GSharp,ASharp,BSharp};

class Scale {
private:
	std::vector<Note> notes;
	Note root;
	int scaleSize;
public:
	Scale(Note key, std::vector<int> stepPattern) {
		stepFromKey(key, this->notes, stepPattern);
		this->scaleSize = notes.size();
	}

	std::vector<Note> getScale(){return this->notes;}
	int size(){return this->scaleSize;}
	std::string getNote_toString(int index){
		Note n = notes.at(index);
		return noteToString[n];
	}


private:
	void stepFromKey(Note key, std::vector<Note> &scal, std::vector<int> steps){
		scal.push_back(key);
		for(int i = 0; i < steps.size(); i++){
			scal.push_back((Note)nextNote((int)scal[i], steps[i]));
		}
	}

	int nextNote(int note, int step){
		if(((int)note + step) > 12){		// will loop back to the start of the notes
			note -= 12;
		}
		return (note + step);
	}
};


class Algerian : public Scale {
private:
public:
	Algerian(Note key) : Scale(key, { 2,1,2,1,1,1,2,1 }) {

	}
};




class Major : public Scale {
private:
public:
	Major() :Scale() {

	}

};

class Minor : public Scale {
	Minor() : Scale() {

	}
};

class Ionian : public Major {
private:
	int StepStructure[7] = { 2,2,1,2,2,2,1 };
public:
	Ionian(Note root) : Major() {

	}



};

class Lydian : public Major {

};

class Mixolydian : public Major {

};

class Aeolian : public Minor {

};

class Dorian : public Minor {

};

class Phrygian : public Minor {

};

class Locrian : public Minor {

};