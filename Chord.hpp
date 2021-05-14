/**
 * Title:       Piano Tutor
 * Author:      Michael Burwell
 * Class:       CSCI201
 * Instructor:  Kristopher Roberts;
 * 
 * File:            Chord.hpp
 * Descriptions:    A chord is a combination of keys on the piano.  When they come together
 *                  they play a specific chord.
 * 
 * Child Classes:   Triad   <-- 3 finger chord usually just called major or minor
 *                  Seventh <-- 4 finger chord pretty much a triad with a fourth note, common in blues
 *                  Suss2   <-- 3 finger chord.  Should probably not build a progression with it,  
 *                              both sus-chords are meant for tension and not structure
 *                  Sus4    <-- 3 finger chord.  If I have a Sus2 than gotta have a Sus4;
 */
#pragma once
#include <iostream>
#include <vector>
#include "Enumerators.hpp"
#include "Scale.hpp"
#include "Piano.hpp"

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
        delete scale;
        scale = NULL;
    }

    // returns all of the notes in the chord
    std::vector<Note> getChordNotes(){
        return this->chordNotes;
    }

    // returns the scale that the chord was built from
    Scale *getScale(){return this->scale;}

    // returns the size of the chord
    unsigned int getSize() const {
        return this->numberOfNotes;
    }

    // returns a string of a note based on an index provided
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

    // retuns a note based on an index provided
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

    // returns true/false based on if the note is in the chord
    bool contains(const Note &n) const {
        for(unsigned int i = 0; i < Chord::getSize(); i++){
            if(Chord::getNote(i) == n){
                return true;
            }
        }
        return false;
    }

    // currently the only virtual function which returns the name of the chord
    virtual std::string ChordName() = 0;

    // prints the chord on the left of the piano and the scale on the right of the piano
    std::string chord_scale_toString(const Piano &p){
        int leftSide = (int)(p.getOctaves() / 2);
        int rightSide = (int)(p.getOctaves() - leftSide);
        std::string lightUpString;
        for(unsigned int i = 0; i < p.getSize(); i++){
            if(leftSide > 0){
                if(p.getNote(i) == Chord::getNote(Chord::getSize() - 1)){
                    leftSide--;
                }

                if(Chord::contains(p.getNote(i))){
                    lightUpString += "O ";
                }
                else{
                    lightUpString += "  ";
                }
            } 
            else{
                if(Chord::getScale()->contains(p.getNote(i))){
                    lightUpString += "X ";
                }
                else{
                    lightUpString += "  ";
                }
            }
        }
        return lightUpString;
    }

    // prints the chord on the right of the piano and the scale on the left (for practicing with the left hand)
    std::string scale_Chord_toString(const Piano &p){
        int rightSide = (int)(p.getOctaves() / 2);
        int leftSide = (int)(p.getOctaves() - rightSide);
        std::string lightUpString;
        for(unsigned int i = 0; i < p.getSize(); i++){
            if(leftSide > 0){
                if(p.getNote(i) == Chord::getNote(0)){
                    leftSide--;
                }

                if(Chord::contains(p.getNote(i)) && leftSide > 0){
                    lightUpString += "O ";
                }
                else{
                    lightUpString += "  ";
                }
            } 
            else{
                if(Chord::getScale()->contains(p.getNote(i))){
                    lightUpString += "X ";
                }
                else{
                    lightUpString += "  ";
                }
            }
        }
        std::cout << "LeftSide: " << leftSide << std::endl;
        std::cout << "RightSide: " << rightSide << std::endl;
        return lightUpString;
    }


private:
    // set the total number of notes in the chord
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

    std::string ChordName(){ return "Triad";}
private:

};

class Seventh : public Chord {
private:
public:
    Seventh(Note root, ScaleType mode) : Chord(root, mode, {0,2,4,6}){}

    std::string ChordName(){ return "Seventh";}
private:
};

class Sus2 : public Chord{
private:
public:
    Sus2(Note root, ScaleType mode) : Chord(root, mode, {0,1,4}){}

    std::string ChordName(){ return "Sus2";}
private:
};

class Sus4 : public Chord{
private:
public:
    Sus4(Note root, ScaleType mode) : Chord(root, mode, {0,3,4}){}

    std::string ChordName(){ return "Sus4";}
private:
};