#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "Chord.hpp"
#include "Piano.hpp"
#include "Console.hpp"
#include "CSV_Reader.hpp"

const std::vector<std::string> CHORD_NAMES = {"Triad", "Seventh", "Sus2", "Sus4"};

NoteFromRoot getRootOfChord(const std::string &s);
int selectChordProgression(const std::string &prompt, const std::map<int, std::vector<std::string>> &prog);

int main(){
    // initialize the chord progressions from the csv on file
    CSV_Reader chordsFile("chordprogressions.csv");
    std::map<int, std::vector<std::string>> progressions = chordsFile.getMap();

    // get the piano information from the user
    int pianoSize = Console::getIntegerFromUserMinMax("How many Keys does your piano have:  ",12,88);
    Console::printNoteMapMultiLine(noteToString);
    Note firstNote = (Note)(Console::getIntegerFromUserMinMax("What note does your piano start with:  ", 1, 12) - 1);

    // create piano
    Piano piano(firstNote, pianoSize);

    // get the chord progression
    int choice = selectChordProgression("Which chord progression would you like to display:  ", progressions);

    Console::printVectorMultiLine(CHORD_NAMES);
    Chords chordType = (Chords)(Console::getIntegerFromUserMinMax("Which chord would you like to play:  ", 1, CHORD_NAMES.size()) - 1);

    

    std::cout << chordTypeName[chordType] << std::endl;
 
    std::cout << piano << std::endl;


    return 0;
}

NoteFromRoot getRootOfChord(const std::string &s){
    for(unsigned int i = 0; i < majorNoteFromRoot.size(); i++){
        if(s.compare(majorNoteFromRoot[(NoteFromRoot)i]) == 0){
            return (NoteFromRoot)i;
        }
    }
    for(unsigned int i = 0; i < minorNoteFromRoot.size(); i++){
        if(s.compare(minorNoteFromRoot[(NoteFromRoot)i]) == 0){
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
