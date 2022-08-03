#pragma once 

#include "pch.h" 

#include <vector> 

#include "Puzzle.h" 

#include "Info.h" 

using namespace std;



void mooveButton(System::Windows::Forms::Button^, cli::array<System::Windows::Forms::Button^, 1>^); // Рух кнопки 

vector<int*> BFS(int*, System::Windows::Forms::TextBox^);// BFS алгоритм 

Puzzle* DLS(Puzzle*, vector<Puzzle*>, int, int);// DLS алгоритм 

bool chack(int*);// Перевірка на шуканий результат 

void removeData(vector<Puzzle*>); // Видалення вузлів 

bool Contains(vector<Puzzle*>, int*); // Перевірка чи був обролений вузол 

vector<int*> SolutionPath(Puzzle*); // Формування вектора кроків до вирішення 

void Display(vector<int*>, System::Windows::Forms::TextBox^, string, int); // Вивід результатів у TextBox 

void WriteToFile(Info); // Запис у файл 

void ReadFile(System::Windows::Forms::TextBox^); // Читання з файлу 

string addZero(string); // Додавання нуля до дати або часу 

char* getCurDate(); // Поточна дата і час 