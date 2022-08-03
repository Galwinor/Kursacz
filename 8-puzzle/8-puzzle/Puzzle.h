#pragma once 

#include <iostream> 

#include <vector> 



class Puzzle

{

	int* arr; // ����� ���� 

	int posZero; // ������� �������� ������ 

	Puzzle* anc; // ������ ��������� �������� 

public:

	Puzzle(int*, Puzzle* = NULL);

	~Puzzle() { delete arr; }

	int* getArr() { return arr; }

	int getZeropos() { return posZero; }

	Puzzle* getAnc() { return anc; }

	std::vector<Puzzle*> mooves(); // �� ������ ���������� 

	Puzzle* mooveRight(); // ���������� ������ 

	Puzzle* mooveLeft(); // ���������� ���� 

	Puzzle* mooveUp(); // ���������� ����� 

	Puzzle* mooveDown(); // ���������� ���� 

};