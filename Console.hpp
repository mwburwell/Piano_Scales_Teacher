/**
 * Title:       Piano Tutor
 * Author:      Michael Burwell
 * Class:       CSCI201
 * Instructor:  Kristopher Roberts;
 * 
 * File:            Console.hpp
 * Descriptions:    Some functions that are usually associated with input/ouput to the console
 */
#pragma once
#include <iostream>
#include <vector>

/**
 * NEED TO MAKE MOST OF THESE FUNCTIONS TEMPLATE FUNCTIONS
 */

class Console{
public:

    // gets an integer with a minimum and maximum
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
                std::cin.clear();
                std::cin.ignore(1000, '\n');            // need to add system specific information for the ignore function
                input = getIntegerFromUserMinMax(prompt, min, max);
            }
            if(input < min || input > max){
                std::cout << "Input is out of range (" << min << "," << max << ")" << std::endl;
                input = getIntegerFromUserMinMax(prompt, min, max);
            }

        } catch(std::invalid_argument ex) {
            std::cout << "getIntegerFromUserMinMax <invalid_argument> - " << ex.what() << std::endl;
        }
        std::cout << std::endl;
        return input;
    }

    // prints a single line to the console from a vector of type string
    static void printVectorLine(const std::vector<std::string> &stringVector, const int &choice ){
        std::cout << "option " << choice << ":  ";
        for(unsigned int i = 0; i < stringVector.size(); i++){
            std::cout << stringVector.at(i) << ", ";
        }
        std::cout << std::endl;
    }

    // prints a multi line using a string vector
    static void printVectorMultiLine(const std::vector<std::string> &vec){
        for(unsigned int i = 0; i < vec.size(); i++){
            std::cout << i + 1 << ":  " << vec.at(i) << std::endl;
        }
    }

    // prints a multi line using a Note and string map
    static void printNoteMapMultiLine(std::map<Note, std::string> m) {
        for(unsigned int i = 0; i < m.size(); i++){
            std::cout << i + 1 << ":  " << m[(Note)i] << std::endl;
        }
    }
};