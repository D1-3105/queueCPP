#pragma once
#include <iostream>
void menu();
int choice();
template<class T>
void chosenClass(T& q);
template<class obj>
inline void print(obj o, int newline=1) {
	try {
		if (newline == 0)
			std::cout << o;
		else
			std::cout << o << std::endl;
	}
	catch (std::exception error) {
		print(error.what(), 1);
	}
}

