#pragma once
#include <iostream>

class Info { // ����� � ����������� ��� ��������� ������ ���������
	int arrStart[9]; // ��������� ���������
	int arrFinish[9]; // Գ������ ���������
	int steps_num; // ʳ������ �����
	int sec; // ʳ������ ������ �� ��������
	int min; // ʳ������ ������ �� ��������
	int depth; // ����������� ������� ������ ��� LDFS
	int milisec; // ʳ������ �������� �� ��������
	char name[5]; // ����� ���������
	char date[20]; // ���� ������
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