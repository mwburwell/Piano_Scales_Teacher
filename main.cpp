#include <iostream>
#include <string>
#include <vector>
#include "Chord.hpp"
#include "Keyboard.hpp"

using namespace std;

// {Note::FFlat, "F-flat"},


using namespace std;

int main(){

    std::vector<Chord*> chordProgression;
    chordProgression.push_back(new Triad(Note::C, ScaleType::IONIAN));
    Scale scale(Note::C, ScaleType::IONIAN);

    Keyboard piano(Note::A, 88);
    for(unsigned int i = 0; i < piano.getSize(); i++){
        if(piano.getNote(i) == Note::C){
            std::cout << "X" << " ";
        }
        else{
            std::cout << "_" << " ";
        }
    }

    std::cout << std::endl;

    for(unsigned int i = 0; i < (int)(piano.getSize() / 2); i++){
        if(piano.getNote(i) == chordProgression.at(0)->getNote(0)){
            std::cout << "1" << " ";
        }
        else if(piano.getNote(i) == chordProgression.at(0)->getNote(1)){
            std::cout << "2" << " ";
        }
        else if(piano.getNote(i) == chordProgression.at(0)->getNote(2)){
            std::cout << "3" << " ";
        }
        else{
            std::cout << "_" << " ";
        }
    }

    for(unsigned int i = (int)(piano.getSize() / 2); i < piano.getSize(); i++){
        if(scale.contains(piano.getNote(i))){
            std::cout << "X" << " ";
        }
        else{
            std::cout << "_" << " ";
        }
    }

    return 0;
}
