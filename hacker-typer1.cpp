#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>

std::string ReadFromFile(std::ifstream & fout)
{
    std::string s;
    char line[6];
    &fout.getline(line,6);
    s = std::string(line);
    return s;
}    


std::string ReadFromFile2(std::ifstream & fout)
{
    int p=0;
    std::string s;
    char line[6];
    &fout.getline(line,6);
    if (line.eof())
    {
        p+=1;
    }                          
    
    return p;
}    
 

int main()
{
    int p = 0;
    std::string s;
    std::string u="ghjhjhghkgkh \nhjgkdhfjkghkdjfkgn \n dfjkgjhfkjg";
    sf::Font font;
    sf::Event event;

    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
   
    font.loadFromFile("arial.ttf");
    int i = 0;
    int k = 0;
    std::ifstream fout;
    fout.open("had-code.txt");
    std::ifstream& file = fout;
    
    while(window.isOpen())
    {  
        
        while(window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed){
                window.close();}

            if (event.type == sf::Event::KeyPressed){
                
                //u = ReadFromFile(file);
                p = p + ReadFromFile2(file);
                //i = i+1;
                //if (i==4)
                //{
                  //  s = s + u + "\n";
                //}
                //else
                //{
                  //  s = s + u;
                //}
                s = s + u;
                
                
            }
        } 
        sf::Text text(s, font, 15);
        
        text.setPosition(20, 20-p*10);
       
        text.setFillColor(sf::Color::Green);
        window.draw(text);   
        window.display();
        window.clear();

   
    }
    return 0;
} 
