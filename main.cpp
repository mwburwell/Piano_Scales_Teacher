#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "Chord.hpp"
#include "Piano.hpp"
#include "Console.hpp"
#include "CSV_Reader.hpp"

NoteFromRoot getRootOfChord(const std::string &s);

int selectChordProgression(const std::string &prompt,const CSV_Reader &progMap){
    for(unsigned int i = 0; i < progMap.getSize(); i++){
        Console::printVectorLine(progMap.getProgression(i), i + 1);
    }

    return Console::getIntegerFromUserMinMax(prompt, 1, progMap.getSize());
}


int main(){
    CSV_Reader chordsFile("chordprogressions.csv");
    std::map<int, std::vector<std::string>> progressions = chordsFile.getMap();
 
    for(int i = 0; i < progressions.size(); i++){
        for(int j = 0; j < progressions.at(i).size(); j++){
            std::cout << progressions[i].at(j) << ", ";
        }
        std::cout << std::endl;
    }

    NoteFromRoot note = getRootOfChord("III");

    std::cout << (int)note << std::endl;

    Console::printIntMapMultiLine(noteToString);



    // int selection = selectChordProgression("Which progression would you like to do? ", chordsFile);

    // Console::printVector(chordsFile.getProgression(selection - 1), selection);

    Piano piano(Note::A, 88);

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
