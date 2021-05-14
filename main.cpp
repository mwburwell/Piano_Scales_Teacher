/**
 * Title:       Piano Tutor
 * Author:      Michael Burwell
 * Class:       CSCI201
 * Instructor:  Kristopher Roberts;
 * 
 * File:            Main
 * Descriptions:    
 */#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "Chord.hpp"
#include "Piano.hpp"
#include "Console.hpp"
#include "CSV_Reader.hpp"

const std::vector<std::string> CHORD_NAMES = {"Triad", "Seventh", "Sus2", "Sus4"};

std::vector<NoteFromRoot> getVectorOfRootNotes(const std::vector<std::string> &strings, std::vector<ScaleType> &majMin);
NoteFromRoot getRootOfChord(const std::string &s, std::vector<ScaleType> &majMin);
int selectChordProgression(const std::string &prompt, const std::map<int, std::vector<std::string>> &prog);
Chord* getChord(const Note &root, const ScaleType &mode, Chords c = Chords::TRIAD);

int main(){
    std::map<int, std::vector<std::string>> progressions;
    std::vector<NoteFromRoot> pattern;
    std::vector<ScaleType> majMinPattern;
    int pianoSize, choice;
    Note firstNote, root;
    Chords chordType;

    // initialize the chord progressions from the csv on file
    CSV_Reader chordsFile("chordprogressions.csv");
    progressions = chordsFile.getMap();

    // get the piano information from the user
    pianoSize = Console::getIntegerFromUserMinMax("How many Keys does your piano have:  ",12,88);
    Console::printNoteMapMultiLine(noteToString);
    firstNote = (Note)(Console::getIntegerFromUserMinMax("What note does your piano start with:  ", 1, 12) - 1);

    // create piano
    Piano piano(firstNote, pianoSize);

    // get the chord progression
    choice = selectChordProgression("Which chord progression would you like to display:  ", progressions);
    // turn the progression into enum vector chord pattern
    pattern = getVectorOfRootNotes(progressions.at(choice), majMinPattern);


    Console::printVectorMultiLine(CHORD_NAMES);
    chordType = (Chords)(Console::getIntegerFromUserMinMax("Which chord would you like to play:  ", 1, CHORD_NAMES.size()) - 1);
    Console::printNoteMapMultiLine(noteToString);
    root = (Note)(Console::getIntegerFromUserMinMax("What is your root note for the chord progression:  ", 1, 12) - 1);
    Scale rootScale(root, ScaleType::IONIAN);

    for(int i = 0; i < pattern.size(); i++){
        ScaleType sType;
        Chord* chord = getChord(rootScale.getNote((int)pattern.at(i)), majMinPattern.at(i), chordType);

        std::cout   << chord->ChordName() << " - " 
                    << chord->getNote_toString(0) << " - " 
                    << chord->getScale()->getMode_toString() << std::endl;

        std::cout << chord->chord_scale_toString(piano) << std::endl;
        std::cout << piano << std::endl << std::endl;

        delete chord;
        chord = NULL;
    }

    return 0;
}

Chord* getChord(const Note &root, const ScaleType &mode, Chords c){
    switch(c){
        case Chords::TRIAD: return new Triad(root, mode); break;
        case Chords::SEVENTH: return new Seventh(root, mode); break;
        case Chords::SUS2: return new Sus2(root, mode); break;
        case Chords::SUS4: return new Sus4(root, mode); break;
        default: return new Triad(root, mode); 
    }
}

NoteFromRoot getRootOfChord(const std::string &s, std::vector<ScaleType> &majorMinor){
    for(unsigned int i = 0; i < majorNoteFromRoot.size(); i++){
        if(s.compare(majorNoteFromRoot[(NoteFromRoot)i]) == 0){
            majorMinor.push_back(ScaleType::IONIAN);
            return (NoteFromRoot)i;
        }
    }
    for(unsigned int i = 0; i < minorNoteFromRoot.size(); i++){
        if(s.compare(minorNoteFromRoot[(NoteFromRoot)i]) == 0){
            majorMinor.push_back(ScaleType::AEOLIAN);
            return (NoteFromRoot)i;
        }
    }

    return (NoteFromRoot)-1;
}

int selectChordProgression(const std::string &prompt, const std::map<int, std::vector<std::string>> &prog){
    for(unsigned int i = 0; i < prog.size(); i++){
        Console::printVectorLine(prog.at(i), i + 1);
    }

    return Console::getIntegerFromUserMinMax(prompt, 1, prog.size()) - 1;
}

std::vector<NoteFromRoot> getVectorOfRootNotes(const std::vector<std::string> &strings, std::vector<ScaleType> &majMin){
    std::vector<NoteFromRoot> notes;
    for(int i = 0; i < strings.size(); i++){
        notes.push_back(getRootOfChord(strings.at(i), majMin));
    }
    return notes;
}
