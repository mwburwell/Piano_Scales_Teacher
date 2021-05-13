#pragma once
#include <iostream>
#include <vector>

/**
 * NEED TO MAKE MOST OF THESE FUNCTIONS TEMPLATE FUNCTIONS
 */

class Console{
public:

    static int getIntegerFromUserMinMax(const std::string &prompt, const int &min, const int &max){
        int input;

        try{
            if(max < min){
                throw std::invalid_argument("The maximum can not be less than the minimum");
            }

            std::cout << prompt;
            std::cin >> input;

            if(std::cin.fail()){
                std::cout << "You did not enter a number try again." << std::endl;
                input = getIntegerFromUserMinMax(prompt, min, max);
            }
            if(input < min || input > max){
                std::cout << "Input is out of range (" << min << "," << max << ")" << std::endl;
                input = getIntegerFromUserMinMax(prompt, min, max);
            }

        } catch(std::invalid_argument ex) {
            std::cout << "getIntegerFromUserMinMax <invalid_argument> - " << ex.what() << std::endl;
        }
        return input;
    }

    static void printVectorLine(const std::vector<std::string> &stringVector, const int &choice ){
        std::cout << "option " << choice << ":  ";
        for(unsigned int i = 0; i < stringVector.size(); i++){
            std::cout << stringVector.at(i) << ", ";
        }
        std::cout << std::endl;
    }

    static void printVectorMultiLine(const std::vector<std::string> &vec){
        for(unsigned int i = 0; i < vec.size(); i++){
            std::cout << i + 1 << ":  " << vec.at(i) << std::endl;
        }
    }

    static void printIntMapMultiLine(std::map<Note, std::string> m) {
        for(unsigned int i = 0; i < m.size(); i++){
            std::cout << i + 1 << ":  " << m[(Note)i] << std::endl;
        }
    }

};