#include "pch.h" 

#include "Puzzle.h" 



using namespace std;



Puzzle::Puzzle(int* ar, Puzzle* ancictor) {

	arr = new int[9];

	for (int i = 0; i < 9; i++)

		arr[i] = ar[i];

	for (int i = 0; i < 9; i++)

		if (arr[i] == 0)

			posZero = i;

	anc = ancictor;

}



vector<Puzzle*> Puzzle::mooves() {

	vector<Puzzle*> moov;

	Puzzle* vertix = this->mooveRight();

	if (vertix != NULL)

		moov.push_back(vertix);

	vertix = this->mooveLeft();

	if (vertix != NULL)

		moov.push_back(vertix);

	vertix = this->mooveUp();

	if (vertix != NULL)

		moov.push_back(vertix);

	vertix = this->mooveDown();

	if (vertix != NULL)

		moov.push_back(vertix);

	vertix = NULL;

	delete vertix;

	return moov;

}



Puzzle* Puzzle::mooveRight() {

	int zeroPos = this->getZeropos();

	if (zeroPos + 1 < 9 && zeroPos / 3 == (zeroPos + 1) / 3) {

		int* arr = new int[9];

		int* oldArr = this->getArr();



		for (int i = 0; i < 9; i++)

			arr[i] = oldArr[i];

		arr[zeroPos] = arr[zeroPos + 1];

		arr[zeroPos + 1] = 0;

		Puzzle* vertix = new Puzzle(arr, this);

		delete[] arr;

		return vertix;

	}

	return NULL;

}



Puzzle* Puzzle::mooveLeft() {

	int zeroPos = this->getZeropos();

	if (zeroPos - 1 >= 0 && zeroPos / 3 == (zeroPos - 1) / 3) {

		int* arr = new int[9];

		int* oldArr = this->getArr();



		for (int i = 0; i < 9; i++)

			arr[i] = oldArr[i];

		arr[zeroPos] = arr[zeroPos - 1];

		arr[zeroPos - 1] = 0;

		Puzzle* vertix = new Puzzle(arr, this);

		delete[] arr;

		return vertix;

	}

	return NULL;

}



Puzzle* Puzzle::mooveUp() {

	int zeroPos = this->getZeropos();

	if (zeroPos + 3 < 9) {

		int* arr = new int[9];

		int* oldArr = this->getArr();



		for (int i = 0; i < 9; i++)

			arr[i] = oldArr[i];

		arr[zeroPos] = arr[zeroPos + 3];

		arr[zeroPos + 3] = 0;

		Puzzle* vertix = new Puzzle(arr, this);

		delete[] arr;

		return vertix;

	}

	return NULL;

}



Puzzle* Puzzle::mooveDown() {

	int zeroPos = this->getZeropos();

	if (zeroPos - 3 >= 0) {

		int* arr = new int[9];

		int* oldArr = this->getArr();



		for (int i = 0; i < 9; i++)

			arr[i] = oldArr[i];

		arr[zeroPos] = arr[zeroPos - 3];

		arr[zeroPos - 3] = 0;

		Puzzle* vertix = new Puzzle(arr, this);

		delete[] arr;

		return vertix;

	}

	return NULL;

}