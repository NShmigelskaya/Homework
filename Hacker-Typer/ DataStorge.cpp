#include <iostream>
#include <fstream>
#include <string>


struct DataStorage
{
    std::string filename;

    std::string readFromFile()
    { 
        std::ifstream file(filename);

        std::string s((std::istreambuf_iterator<char>(file)),std::istreambuf_iterator<char>());
        return s;
    }
};

