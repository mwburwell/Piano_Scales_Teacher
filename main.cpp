#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "Chord.hpp"
#include "Piano.hpp"
#include "CSV_Reader.hpp"



int main(){

    CSV_Reader reader("chordprogressions.csv");

    for(int i = 0; i < reader.getSize(); i++){

    }


    // file.close();
    // std::vector<int> chordProgressionStructure = {};
    // Note key = Note::C;
    // Piano piano(Note::A, 88);
    // Scale scale(key, ScaleType::IONIAN);

    // std::vector<Chord*> chordProgression;
    // chordProgression.push_back(new Triad(key, ScaleType::IONIAN));

    //  for(unsigned int i = 0; i < piano.getSize(); i++){
    //     if(piano.getNote(i) == Note::C){
    //         std::cout << "X" << " ";
    //     }
    //     else{
    //         std::cout << "_" << " ";
    //     }
    // }

    // std::cout << std::endl;

    // for(unsigned int i = 0; i < (int)(piano.getSize() / 2); i++){
    //     if(piano.getNote(i) == chordProgression.at(0)->getNote(0)){
    //         std::cout << "1" << " ";
    //     }
    //     else if(piano.getNote(i) == chordProgression.at(0)->getNote(1)){
    //         std::cout << "2" << " ";
    //     }
    //     else if(piano.getNote(i) == chordProgression.at(0)->getNote(2)){
    //         std::cout << "3" << " ";
    //     }
    //     else{
    //         std::cout << "_" << " ";
    //     }
    // }

    // for(unsigned int i = (int)(piano.getSize() / 2); i < piano.getSize(); i++){
    //     if(scale.contains(piano.getNote(i))){
    //         std::cout << "X" << " ";
    //     }
    //     else{
    //         std::cout << "_" << " ";
    //     }
    // }

    return 0;
}
