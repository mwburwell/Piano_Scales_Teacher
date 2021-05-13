#pragma once
#include <iostream>
#include <vector>

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

    static void printVector(const std::vector<std::string> &stringVector, const int &choice ){
        std::cout << choice << "\t";
        for(unsigned int i = 0; i < stringVector.size(); i++){
            std::cout << stringVector.at(i) << ", ";
        }
        std::cout << std::endl;
    }

};