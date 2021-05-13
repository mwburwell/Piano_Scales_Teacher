/**
 * Title:       Piano Tutor
 * Author:      Michael Burwell
 * Class:       CSCI201
 * Instructor:  Kristopher Roberts;
 * 
 * File:            CSV_Reader
 * Descriptions:    This is a CSV reading class that will read any number of columns into a map
 *                  indexed by the amount of rows in the data.
 */
#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
/**
 * I WOULD EVENTUALLY LIKE TO MAKE THIS A TEMPLATE TO BE MORE ABSTRACT WITH READING A CSV FILE
 */

class CSV_Reader{
private:
    std::ifstream file;
    std::map<int, std::vector<std::string>> chordProgressionMap;
    unsigned int mapSize;
public:
    /**open file and file the map container */
    CSV_Reader(std::string fileName){
        openFile(fileName);
        readFileIntoContainer(this->file);
        this->file.close();
    }

    std::map<int, std::vector<std::string>> getMap() const {return this->chordProgressionMap; }

    /**Pull a progression by index will catch to see if index being passed is out of range */
    std::vector<std::string> getProgression(unsigned int index) const {
        try{
            if(index < 0 || index > (this->getSize() - 1))
                throw std::out_of_range("Index is out of range (0,"+std::to_string(getSize() - 1)+") - " + std::to_string(index) );
    
            return this->chordProgressionMap.at(index);

        } catch(std::out_of_range ex){
            std::cout << "getProgression <out_of_range> - " << ex.what() << std::endl;
        }
        return {0};  // <--- should never get here;
    }

    /**Get the size of the map */
    int getSize() const {return this->mapSize; }



private:
    /**
     * Open the file with a file name.
     * Will catch a file open failure exception.
     */
    void openFile(std::string fileName){
        try{
            this->file.open(fileName, std::ios::in);
        } catch(std::ios_base::failure ex){
            std::cout << "openFile <ios_base::failure> - " << ex.what() << std::endl;
            throw ex;
        }
    }

    void readFileIntoContainer(std::ifstream &file){
        /**
         * Thanks to https://www.geeksforgeeks.org/csv-file-management-using-c/
         * for helping with this code.
         */
        std::vector<std::string> row;   // initialize a row
        std::string line, word, temp;   // initialize string variables
        int count = 0;                  // initialize count

        while(file >> line){            // take each line of the file
            row.clear();                // clear the vector

            std::stringstream s(line);  // setup a string stream

            while(std::getline(s,word,',')){    // pull each word out of the string with the ',' delimeter
                row.push_back(word);            // push word to the vector
            }

            this->chordProgressionMap[count] = row;   // add the vector to classes map
            count++;
        }

        this->mapSize = count;          // initialize map size
    }

};