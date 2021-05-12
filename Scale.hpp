#pragma once
#include <vector>
#include <string>
#include <map>
#include "Enumerators.hpp"

enum class ScaleType {IONIAN, DORIAN,PHRYGIAN,LYDIAN,MIXOLYDIAN,AEOLIAN,LOCRIAN};

class Scale {
private:
	std::vector<Note> notes;
	Note root;
	int scaleSize;
public:
	Scale(Note key, ScaleType mode) {
		stepFromKey(key, this->notes, chooseScaleSteps(mode));
		this->scaleSize = notes.size();
	}

	std::vector<Note> getScale(){return this->notes;}
	int size(){return this->scaleSize;}
	std::string getNote_toString(int index){
		Note n = notes.at(index);
		return noteToString[n];
	}

	std::vector<int> chooseScaleSteps(ScaleType type){
		switch(type){
			case ScaleType::IONIAN: return {2,2,1,2,2,2,1}; break;
			case ScaleType::DORIAN: return {2,1,2,2,2,1,2}; break;
			case ScaleType::PHRYGIAN: return {1,2,2,2,1,2,2}; break;
			case ScaleType::LYDIAN: return {2,2,2,1,2,2,1}; break;
			case ScaleType::MIXOLYDIAN: return {2,2,1,2,2,1,2}; break;
			case ScaleType::AEOLIAN: return {2,1,2,2,1,2,2}; break;
			case ScaleType::LOCRIAN: return {1,2,2,1,2,2,2}; break;
			default: return {0}; break;
		}
		return {0};
	}


private:
	void stepFromKey(Note key, std::vector<Note> &scal, std::vector<int> steps){
		scal.push_back(key);
		/**Takes the root key of the scale and puts it in the scale then starting
		 * from there it will move parallel with the step pattern of the scale
		 * and push_back the vector of notes by turning the note to step from into
		 * an integer and adding the current step interval to that.
		 */
		for(int i = 0; i < steps.size(); i++){
			Note newNote = (Note)nextNote((int)scal[i], steps[i]);
			if(newNote != key){
				scal.push_back(newNote);
			}
		}
	}

	int nextNote(int note, int step){
		if((note + step) > 11){		// will loop back to the start of the notes
			note -= 12;
		}
		return (note + step);
	}
};
