/**
 * Title:       Piano Tutor
 * Author:      Michael Burwell
 * Class:       CSCI201
 * Instructor:  Kristopher Roberts;
 * 
 * File:            Scale
 * Descriptions:    A scale is a spcific step pattern between an octave that all sounds natural together.
 * 
 * 					There are a lots and lots of different scales that can be played.  I have include
 * 					the 7 Greak modes.  IONIAN, DORIAN,PHRYGIAN,LYDIAN,MIXOLYDIAN,AEOLIAN,LOCRIAN
 * 
 * 					While I currently have only programmed main to use the IONIAN and AEOLIAN scales I have
 * 					provided enough code to be able to begin using the different modes.
 * 
 * 					once I create a class based on different types of hand grips that I could probably put in
 * 					the chords file I will start using the separate modes.
 * 
 * 					Ionian is the major scale
 * 					Aeolian is the natural minor scale
 *  
 */
#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <map>
#include "Enumerators.hpp"

class Scale {
private:
	std::vector<Note> scale;
	ScaleType mode;
	Note root;
	int scaleSize;
public:
	Scale(Note key, ScaleType mode) {
		this->mode = mode;
		stepFromKey(key, this->scale, chooseScaleSteps(mode));
		this->scaleSize = scale.size();
	}

	// returns true/false based on if the note provided is in the Scale
    bool contains(const Note &n){
        for(unsigned int i = 0; i < Scale::getSize(); i++){
            if(this->getNote(i) == n){
                return true;
            }
        }
        return false;
    }

	// returns the full scale to the caller
	std::vector<Note> getScale() const {
        return this->scale;
    }

	// returns the mode of the scale as a string
	std::string getMode_toString() const { 
		return scaleTypeNames[this->mode];
	}

	// retuns the type of scale
	ScaleType getMode() const { 
		return this->mode; 
	}

	// returns the size of the scale
	int getSize() const {
        return this->scaleSize;
    }

	// returns a specific note in the scale found by an index will throw out_of_range exception
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

	// retuns a specific not in the scale found by an index will throw out_of_range exception
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
	// will start at a specific not and fill the scale based on the modes specific step pattern
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

	// returns int, the next note based on the next step passed in.  will cycle the octabe if
	// the end is reached
	int nextNote(int note, int step){
		if((note + step) > 11){		// will loop back to the start of the notes
			note -= 12;
		}
		return (note + step);
	}

	// will return Vectro<int> the step pattern of a mode that is passed in by parameter
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
