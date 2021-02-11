#pragma once
#ifndef STORAGE_H_
#define STORAGE_H_
#ifndef HASHFUNC_H_
#define HASHFUNC_H_
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <cstdlib>
#include <list>
#include "book.h"
#include "hash_function"
struct cell
{
	std::string hash = "";
	std::list<Book> Cell;
};
struct Storage
{
	cell storage[2756];
	void SetHash();
	void ReadFile();
	void FindBook();
	void AddBook();
	void DeleteBook();
	int  FindRightCell(std::string book_name);
	std::string itos(int n);
	std::string generated_hash(std::string book_name);

};
void Storage::ReadFile()
{
	std::string filename = "hash_english.txt";
	std::ifstream f(filename);
	std::string tmp_str;
	std::string tmp_hash;
	std::string hash;
	std::string it;

	while (f)
	{
		std::string str;
		std::getline(f, str);

		if (str != "") 
		{
			it = str[0];
			tmp_str += str[0];
			tmp_str += str[1];
			tmp_hash = generated_hash(tmp_str);
			tmp_str = "";
			hash = generated_hash(str);
			for (int i = 0; i < 2756; i++)
			{
				if (tmp_hash == storage[i].hash)
				{
					Book new_book;
					new_book.name = str;
					storage[i].Cell.push_back(new_book);
					break;
				}
			}
		}
	}
}
int Storage::FindRightCell(std::string book_name)
{
	std::string tmp_book_hash = "";
	tmp_book_hash += book_name[0];
	tmp_book_hash += book_name[1];
	tmp_book_hash = generated_hash(tmp_book_hash);
	int index = -1;
	for (int i = 0; i < 2756; i++)
	{
		if (tmp_book_hash == storage[i].hash)
		{
			index = i;
			return index;
		}
	}
}
void Storage::FindBook()
{
	std::string book_name = "";
	std::cin >> book_name;
	std::string book_hash = generated_hash(book_name);
	int cell_index = FindRightCell(book_name);
	std::list <Book>::iterator  cell_iter;
	std::string lib_book_hash;
	for (cell_iter = storage[cell_index].Cell.begin(); cell_iter != storage[cell_index].Cell.end(); cell_iter++)
	{
		lib_book_hash = generated_hash((*cell_iter).name);
		if (book_hash == lib_book_hash)
		{
			(*cell_iter).readBook();
			std::cout << (*cell_iter).data << std::endl;
		}
	}
}
void Storage::AddBook()
{
	std::string book_name = "";
	std::cin >> book_name;
	std::string book_hash = generated_hash(book_name);
	int cell_index = FindRightCell(book_name);
	std::list <Book>::iterator  cell_iter;
	std::string lib_book_hash;
	for (cell_iter == storage[cell_index].Cell.begin(); cell_iter == storage[cell_index].Cell.end(); cell_iter++)
	{
		lib_book_hash = generated_hash((*cell_iter).name);
		if (lib_book_hash != generated_hash((*cell_iter).name));
		{
			Book new_book;
			new_book.name = book_name;
			storage[cell_index].Cell.push_back(new_book);
			std::ofstream fout;
			fout.open("hash_english.txt", std::ofstream::app);
			if (fout.is_open())
			{
				std::cout<< "Book" <<std::endl;
				std::cin>> (*cell_iter).name;
				fout << std::endl << (*cell_iter).name<< " ";
				fout.close();
			}
			else
			{
				std::cout << "File is not found" << std::endl;
			}
		}
	}
}
void Storage::SetHash()
{
	std::string tmp_char_1;
	std::string tmp_char_2;
	std::string tmp_hash_1 = "";
	std::string tmp_hash_2 = "";
	for (int i = 0; i < 52; i++)
	{
		if (i < 26)
		{
			tmp_char_1 = (char)(65 + i);
		}
		else
		{
			tmp_char_1 = (char)(71 + i);
		}
		tmp_hash_1 = generated_hash(tmp_char_1);
		for (int j = 0; j < 53; j++)
		{
			if (j < 26)
			{
				tmp_char_2 = (char)(65 + j);
			}
			else if (j == 53)
			{
				tmp_char_2 = (char)(32);
			}
			else
			{
				tmp_char_2 = (char)(71 + j);
			}
			tmp_hash_2 = generated_hash(tmp_char_2);
			storage[52 * i + j].hash = tmp_hash_1 + tmp_hash_2;
		}
	}
}
#endif
#endif
 
