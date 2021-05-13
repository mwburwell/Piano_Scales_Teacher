#pragma once
#include <vector>
#include <iostream>
#include "Enumerators.hpp"

class Piano{
private:
    unsigned int numberOfKeys;
    std::vector<Note> keyboard;
    Note firstKey;
public:
    Piano(Note firstKey, unsigned int numKeys){
        try{
            this->firstKey = firstKey;
            setNumberOfKeys(numKeys);
            setKeyboard(firstKey);
        } catch(std::exception ex){
            std::cout << "Exception creating key Board: " << ex.what() << std::endl;
            throw ex;
        }
    }

    unsigned int getSize() const {return this->numberOfKeys;}

    Note getNote(int index){
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

    std::vector<int> getIndecesOfNote(Note n){
        std::vector<int> indeces;
        for(unsigned int i = 0; i < getSize(); i++){
            if(getNote(i) == n){
                indeces.push_back(i);
            }
        }
        return indeces;
    }

    std::string getNote_toString(int index) const {
		Note n = this->keyboard.at(index);
		return noteToString[n];
	}

    std::string toString(){
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

    friend std::ostream& operator<<(std::ostream& output, Piano &p) {
        output << p.toString();
        return output;
    }
private:
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
};