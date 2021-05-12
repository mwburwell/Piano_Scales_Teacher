#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <map>
#include "Enumerators.hpp"

enum class ScaleType {IONIAN, DORIAN,PHRYGIAN,LYDIAN,MIXOLYDIAN,AEOLIAN,LOCRIAN};

class Scale {
private:
	std::vector<Note> scale;
	Note root;
	int scaleSize;
public:
	Scale(Note key, ScaleType mode) {
		stepFromKey(key, this->scale, chooseScaleSteps(mode));
		this->scaleSize = scale.size();
	}

    bool contains(const Note &n){
        for(unsigned int i = 0; i < Scale::getSize(); i++){
            if(this->getNote(i) == n){
                return true;
            }
        }
        return false;
    }
	std::vector<Note> getScale() const {
        return this->scale;
    }

	int getSize() const {
        return this->scaleSize;
    }

	std::string getNote_toString(int index) const {
        try{
            if(index < 0)
                throw std::invalid_argument("index can not be less than 0.");

            if(index > this->getSize() - 1)
                throw std::invalid_argument("index reference outside of array bounds.");

            return noteToString[scale.at(index)];
        } catch (std::invalid_argument ex){
            std::cout << "getNote_toString <invalid_argument> - " << ex.what() << std::endl;
            throw ex;
        }
	}

    Note getNote(int index) const {
        try{
            if(index < 0)
                throw std::invalid_argument("index can not be less than 0.");

            if(index > this->getSize() - 1)
                throw std::invalid_argument("index reference outside of array bounds.");


            return this->scale.at(index);
        } catch (std::invalid_argument ex){
            std::cout << "getNote <invalid_argument> - " << ex.what() << std::endl;
            throw ex;
        }
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

};
