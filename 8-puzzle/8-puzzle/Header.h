#pragma once 

#include "pch.h" 

#include <vector> 

#include "Puzzle.h" 

#include "Info.h" 

using namespace std;



void mooveButton(System::Windows::Forms::Button^, cli::array<System::Windows::Forms::Button^, 1>^); // ��� ������ 

vector<int*> BFS(int*, System::Windows::Forms::TextBox^);// BFS �������� 

Puzzle* DLS(Puzzle*, vector<Puzzle*>, int, int);// DLS �������� 

bool chack(int*);// �������� �� ������� ��������� 

void removeData(vector<Puzzle*>); // ��������� ����� 

bool Contains(vector<Puzzle*>, int*); // �������� �� ��� ��������� ����� 

vector<int*> SolutionPath(Puzzle*); // ���������� ������� ����� �� �������� 

void Display(vector<int*>, System::Windows::Forms::TextBox^, string, int); // ���� ���������� � TextBox 

void WriteToFile(Info); // ����� � ���� 

void ReadFile(System::Windows::Forms::TextBox^); // ������� � ����� 

string addZero(string); // ��������� ���� �� ���� ��� ���� 

char* getCurDate(); // ������� ���� � ��� 