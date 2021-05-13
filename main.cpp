#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "Chord.hpp"
#include "Piano.hpp"
#include "Console.hpp"
#include "CSV_Reader.hpp"

int selectChordProgression(const std::string &prompt,const CSV_Reader &progMap){
    for(unsigned int i = 0; i < progMap.getSize(); i++){
        Console::printVector(progMap.getProgression(i), i + 1);
    }

    return Console::getIntegerFromUserMinMax(prompt, 1, progMap.getSize());
}


int main(){

    CSV_Reader chordsFile("chordprogressions.csv");
    Console::getIntegerFromUserMinMax()

    for(int i = 0; i < chordsFile.getSize(); i++){
        std::cout << "Index: " << i << std::endl;
        std::vector<std::string> progression = chordsFile.getProgression(i);
        for(int j = 0; j < progression.size(); j++){
            std::cout << progression.at(j) << ", ";
        }
        std::cout << std::endl;
    }

    int selection = selectChordProgression("Which progression would you like to do? ", chordsFile) - 1;

    printVector(chordsFile.getProgression(selection), selection + 1);



    return 0;
}
