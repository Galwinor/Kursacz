#pragma once
#include <iostream>

class Info { // Класс з інформацією про результат роботи алгоритму
	int arrStart[9]; // Початкове положення
	int arrFinish[9]; // Фінальне положення
	int steps_num; // Кількість кроків
	int sec; // Кількість секунд на алгоритм
	int min; // Кількість хвилин на алгоритм
	int depth; // Максимальна глибина пошуку для LDFS
	int milisec; // Кількість мілісекунд на алгоритм
	char name[5]; // Назва алгоритму
	char date[20]; // Дата запису
public:
	Info(int, int, const char*, int*, int*, char*, int);
	Info(){}
	std::string getWorkTime();
	char* getName() { return name; }
	int getSteps() { return steps_num; };
	int* getArrStart() { return arrStart; }
	int* getArrFinish() { return arrFinish; }
	char* getDate() { return date; }
	int getDepth() { return depth; }
};