/**
 * Title:       Piano Tutor
 * Author:      Michael Burwell
 * Class:       CSCI201
 * Instructor:  Kristopher Roberts;
 * 
 * File:            Piano.hpp
 * Descriptions:    This is a piano class that will be created with the size of the keyboard
 *                  and the note that it starts with.
 */
#pragma once
#include <vector>
#include <iostream>
#include "Enumerators.hpp"

class Piano{
private:
    unsigned int numberOfKeys;
    std::vector<Note> keyboard;
    Note firstKey;
    int maxOctaves;
public:
    Piano(Note firstKey, unsigned int numKeys){
        try{
            this->firstKey = firstKey;
            setNumberOfKeys(numKeys);
            setKeyboard(firstKey);
            setMaxOctaves(numKeys);
        } catch(std::exception ex){
            std::cout << "Exception creating key Board: " << ex.what() << std::endl;
            throw ex;
        }
    }

    // returns the size of the piano
    unsigned int getSize() const {return this->numberOfKeys;}

    // returns the total octaves allowed on the piano
    unsigned int getOctaves() const { return this->maxOctaves; }

    // returns a note from the Piano found by index
    Note getNote(int index) const {
        try{
            if(index < 0){
                throw std::invalid_argument("index cannot be less than 0.");
            }
            if(index > getSize() - 1){
                throw std::invalid_argument("index is greater than size of vector.");
            }
            return this->keyboard.at(index);

        }catch(std::invalid_argument ex){
            std::cout << "getNote <Invalid Argument> - " << ex.what() << std::endl;
            throw ex;
        }
    }

    // returns all indeces of a single note
    std::vector<int> getIndecesOfNote(Note n) const {
        std::vector<int> indeces;
        for(unsigned int i = 0; i < getSize(); i++){
            if(getNote(i) == n){
                indeces.push_back(i);
            }
        }
        return indeces;
    }

    // returns a string for the note in the pianos vector of Notes
    std::string getNote_toString(int index) const {
		Note n = this->keyboard.at(index);
		return noteToString[n];
	}

    // make a string of the piano's keys and spaces
    std::string toString() const {
        std::string pString;
        for(unsigned int i = 0; i < Piano::getSize(); i++){
            pString += "_ ";
        }
        pString += '\n';
    
        for(unsigned int i = 0; i < Piano::getSize(); i++){
            std::string n = noteToString[this->keyboard.at(i)];
            if(n.length() > 1){
                pString += "^ ";
            }
            else{
                pString += (n + " ");
            }
        }
        pString += '\n';
        return pString;
    }

    // makes piano friendly with the output stream
    friend std::ostream& operator<<(std::ostream& output, Piano &p) {
        output << p.toString();
        return output;
    }
private:
    // set the number of keys with Exceptions that can be thrown 
    void setNumberOfKeys(unsigned int keys){
        /**Verify the number of keys are between 12 and 88 then assign to class variable */
        try{
            if(keys < 12){
                throw std::underflow_error("Keyboard cannot be less than 12 keys");
            }
            if(keys > 88){
                throw std::overflow_error("Keyboard cannot be greater than 88 keys");
            }
            this->numberOfKeys = keys;

        } catch(std::underflow_error ex) {
            std::cout << "setNumberOfKeys <underflow_error> - " << ex.what() << std::endl;
            throw ex;
        } catch(std::overflow_error ex) {
            std::cout << "setNumberOfKeys <overflow_error> - " << ex.what() << std::endl;
            throw ex;
        }
    }

    // set all notes in the keyboard starting from the first note
	void setKeyboard(Note key){
		this->keyboard.push_back(key);
		/**Takes the root key of the scale and puts it in the scale then starting
		 * from there it will move parallel with the step pattern of the scale
		 * and push_back the vector of notes by turning the note to step from into
		 * an integer and adding the current step interval to that.
		 */
		for(int i = 0; i < this->numberOfKeys; i++){
			Note newNote = (Note)Piano::nextNote((int)keyboard[i], 1);
            keyboard.push_back(newNote);
		}
	}

    // is used in the set keyboard function to find the next note
    int nextNote(int note, int step){
        int octave = (int)((note + step) / 12);
        if(octave > 0){
            note -= 12 * octave;
        }
        else if((note + step) > 11){		// will loop back to the start of the notes
            note -= 12 * octave;
        }
        return (note + step);
	}

    // sets the maximum number of octaves
    void setMaxOctaves(const int &size){
        /** Will usually end in a double but I just want the maximum full octaves anyway */
        this->maxOctaves = (int)(size / 12);
    }
};