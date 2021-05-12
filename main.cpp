#include <iostream>
#include <string>
#include <vector>
#include "Scale.h"
#include "Keyboard.hpp"

using namespace std;

// {Note::FFlat, "F-flat"},


using namespace std;

int main(){
    // Scale scale(Note::C, ScaleType::IONIAN);

    // cout << "Scale size: " << scale.size() << endl;
    // for(int i = 0; i < scale.size(); i++){
    //     cout << "Note: " << scale.getNote_toString(i) << endl;
    // }

    Keyboard piano(Note::A, 88);
    for(unsigned int i = 0; i < piano.getNumberOfKeys(); i++){
        if(piano.getNote(i) == Note::C){
            std::cout << std::endl;
        }
        std::cout << piano.getNote_toString(i) << " ";
    }

    return 0;
}
