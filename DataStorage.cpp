#include <iostream>
#include <fstream>
#include <string>
#include <SFML/Graphics.hpp>
#include "DataStorage.h"

void Text::readFromFile()
{
    std::ifstream file(filename);

    std::string s((std::istreambuf_iterator<char>(file)),std::istreambuf_iterator<char>());
    this->fullText = s;
}



