#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <vector>


class CSV_Reader{
private:
    std::ifstream file;
    std::map<int, std::vector<std::string>> chordProgressionMap;
    unsigned int mapSize;
public:
    CSV_Reader(std::string fileName){
        openFile(fileName);
        readFileIntoContainer(this->file);
        this->file.close();
    }

    std::map<int, std::vector<std::string>> getMap() const {return this->chordProgressionMap; }

    std::vector<std::string> getProgression(unsigned int index){
        try{
            if(index < 0 || index > (this->getSize() - 1))
                throw std::out_of_range("Index is out of range (0,"+std::to_string(getSize() - 1)+") - " + std::to_string(index) );
    
            return this->chordProgressionMap[index];

        } catch(std::out_of_range ex){
            std::cout << "getProgression <out_of_range> - " << ex.what() << std::endl;
        }
    }

    int getSize() const {return this->mapSize; }

private:
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
        std::vector<std::string> row;
        std::string line, word, temp;
        int count = 0;

        while(file >> line){
            row.clear();

            std::stringstream s(line);

            while(std::getline(s,word,',')){
                row.push_back(word);
            }

            chordProgressionMap[count] = row;
            count++;
        }
    }

};