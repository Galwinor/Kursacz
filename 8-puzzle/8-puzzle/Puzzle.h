#pragma once 

#include <iostream> 

#include <vector> 



class Puzzle

{

	int* arr; // Масив цифр 

	int posZero; // Позиція порожньої кнопки 

	Puzzle* anc; // Батько поточного елементу 

public:

	Puzzle(int*, Puzzle* = NULL);

	~Puzzle() { delete arr; }

	int* getArr() { return arr; }

	int getZeropos() { return posZero; }

	Puzzle* getAnc() { return anc; }

	std::vector<Puzzle*> mooves(); // Всі можливі переміщення 

	Puzzle* mooveRight(); // Переміщення вправо 

	Puzzle* mooveLeft(); // Переміщення вліво 

	Puzzle* mooveUp(); // Переміщення вверх 

	Puzzle* mooveDown(); // Переміщення вниз 

};