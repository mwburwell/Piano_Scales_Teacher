#pragma once
#include <iostream>
#include <vector>
#include "Scale.hpp"
#include "Enumerators.hpp"

class Chord {
private:
    unsigned int numberOfNotes;
    Scale *scale;
    std::vector<Note> chordNotes;
public:
    Chord(Note root, ScaleType mode, std::vector<int> noteIndeces) {
        scale = new Scale(root, mode);
        setNumOfNotes(noteIndeces.size());
        setChord(noteIndeces);
    }
    ~Chord() {
    }

    unsigned int getSize() const {
        return this->numberOfNotes;
    }

	std::string getNote_toString(int index) const {
        try{
            if(index < 0)
                throw std::invalid_argument("index can not be less than 0.");

            if(index > this->getSize() - 1)
                throw std::invalid_argument("index reference outside of array bounds.");

            return noteToString[chordNotes.at(index)];
        } catch (std::invalid_argument ex){
            std::cout << "getNote_toString <invalid_argument> - " << ex.what() << std::endl;
            throw ex;
        }
	}

    Note getNote(int index) const {
        try{
            if(index < 0)
                throw std::invalid_argument("index can not be less than 0.");

            if(index > this->Chord::getSize() - 1)
                throw std::invalid_argument("index reference outside of array bounds.");


            return this->chordNotes.at(index);
        } catch (std::invalid_argument ex){
            std::cout << "getNote <invalid_argument> - " << ex.what() << std::endl;
            throw ex;
        }
    }

private:
    void setNumOfNotes(int amountOfNotes){
        try{
            if(amountOfNotes < 2)
                throw std::invalid_argument("Total amount of notes in the chord can not be less than 2");

            if(amountOfNotes > 12)
                throw std::invalid_argument("Can not have a chord greater than an octave.");

            this->numberOfNotes = amountOfNotes;
        } catch(std::invalid_argument ex){
            std::cout << "setNumOfNotes <invalid_argument> - " << ex.what() << std::endl;
            throw ex;
        }
    }   

    /**
     * Sets the chord based on the layout of the notes in the chord which
     * are determined by what type of chord it is
     */
    void setChord(std::vector<int> noteIndeces){
        try{
            if(this->scale->getSize() < 5)
                throw std::overflow_error("Scale does not have 5 notes.");

            /**
             * Loops through the argument passed in which will be a vector of Indeces
             * where each index is a note in the chords scale.
            */
            for(unsigned int i = 0; i < noteIndeces.size(); i++){
                this->chordNotes.push_back(
                    this->scale->getNote(
                        noteIndeces.at(i)));
            }


        } catch(std::overflow_error ex){
            std::cout << "setChord <overflow_error> - " << ex.what() << std::endl;
            throw ex;
        }
    }
};





class Triad : public Chord {
private:
public:
    Triad(Note root, ScaleType mode) : Chord(root, mode, {0,2,4}){}


private:

};

class Seventh : public Chord {
private:
public:
    Seventh(Note root, ScaleType mode) : Chord(root, mode, {0,2,4,6}){}

private:
};

class Sus2 : public Chord{
private:
public:
    Sus2(Note root, ScaleType mode) : Chord(root, mode, {0,1,4}){}

private:
};

class Sus4 : public Chord{
private:
public:
    Sus4(Note root, ScaleType mode) : Chord(root, mode, {0,3,4}){}

private:
};