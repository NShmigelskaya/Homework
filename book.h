#pragma once
#ifndef BOOK_H_
#define BOOK_H_
#include <string>
#include <fstream>




struct Book
{
    
    std::string name;
    void readBook();
    std::string data = "description";
    
    
}; 

void Book::readBook()
{
    std::ifstream book_data(this->name);
    std::string Big_data = "";
    
    while(book_data)
    {
        std::string str;
        std::getline(book_data, str);
        if (str != "") 
        {
            Big_data += str;
            Big_data += "\n";
        }
    }
    this->data = Big_data;
}





#endif
