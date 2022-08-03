#include "pch.h"
#include "Info.h"
#include <string>
using namespace std;
Info::Info(int steps, int WorkTime, const char* algorithm, int* startArr, int* finishArr, char* Data, int Depth) {
	steps_num = steps;
	depth = Depth;
	for (int i = 0; i < 9; i++) {
		arrStart[i] = startArr[i];
		arrFinish[i] = finishArr[i];
	}
	for (int i = 0; i < 4; i++)
		name[i] = algorithm[i];
	min = WorkTime / 60000; // Переведення мілісекунд в хвилини
	sec = (WorkTime % 60000) / 1000; // Переведення мілісекунд в секунди
	milisec = WorkTime % 1000; // Кількість мілісекунд
	for (int i = 0; i < 20; i++)
		date[i] = Data[i];
}

std::string Info::getWorkTime() {
	std::string time = "--took " + to_string(min) + "m. " + to_string(sec) + "s. " + to_string(milisec) + "ms.--";
	return time;
}