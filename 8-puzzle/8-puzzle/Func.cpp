#include "pch.h" 

#include "Header.h" 

#include <string> 

#include <ctime> 

#include <fstream> 

#include <msclr\marshal_cppstd.h> 



using namespace std;



void mooveButton(System::Windows::Forms::Button^ curButt, cli::array<System::Windows::Forms::Button^, 1>^ arr) { // ���������� ������ ������ 

	int currTag = stoi(msclr::interop::marshal_as<string>(curButt->Tag->ToString())); // ������� ������ 

	if (currTag + 1 < 9) // �� �� �������� �� ���� 

		if (arr[currTag + 1]->Text == "" && currTag / 3 == (currTag + 1) / 3) { // �� ����� ������ �� ������ 

			string text = msclr::interop::marshal_as<string>(curButt->Text->ToString()); // ����� �� ������ 

			curButt->Text = ""; // ���������� 0 �� ���� ������� ������ 

			arr[currTag + 1]->Text = stoi(text) + ""; // �������� �� ���� 0 ����� ������� ������ 

			curButt->Enabled = false; // ������� 0 ����������� ��� ���������� 

			arr[currTag + 1]->Enabled = true; // ³������� ��������� ���������� �� ������ �� ���� 0 

		}

	if (currTag - 1 >= 0) // �� �� �������� �� ���� 

		if (arr[currTag - 1]->Text == "" && currTag / 3 == (currTag - 1) / 3) {// �� ����� ������ �� ������ 

			string text = msclr::interop::marshal_as<string>(curButt->Text->ToString());

			curButt->Text = "";

			arr[currTag - 1]->Text = stoi(text) + "";

			curButt->Enabled = false;

			arr[currTag - 1]->Enabled = true;

		}

	if (currTag + 3 < 9) // �� �� �������� �� ���� 

		if (arr[currTag + 3]->Text == "" && currTag / 3 + 1 == (currTag + 3) / 3) {// �� ����� ������ �� ������ 

			string text = msclr::interop::marshal_as<string>(curButt->Text->ToString());

			curButt->Text = "";

			arr[currTag + 3]->Text = stoi(text) + "";

			curButt->Enabled = false;

			arr[currTag + 3]->Enabled = true;

		}

	if (currTag - 3 >= 0) // �� �� �������� �� ���� 

		if (arr[currTag - 3]->Text == "" && currTag / 3 - 1 == (currTag - 3) / 3) {// �� ����� ������ �� ������ 

			string text = msclr::interop::marshal_as<string>(curButt->Text->ToString());

			curButt->Text = "";

			arr[currTag - 3]->Text = stoi(text) + "";

			curButt->Enabled = false;

			arr[currTag - 3]->Enabled = true;

		}

}



vector<int*> BFS(int* ar, System::Windows::Forms::TextBox^ text) { // ��� �������� 



	unsigned int start_time = clock(); // ��� ������� ������ ��������� 



	Puzzle* vert = new Puzzle(ar); // ����� ������ 

	vector<Puzzle*> bfs; // ����� 

	vector<Puzzle*> closed; // �������� �� ���� ������������ 

	bfs.push_back(vert); // ��������� ����� �� ����� 

	Puzzle* pointTmp = vert; // �������� �� �������� ����� 





	while (!chack(pointTmp->getArr())) { // ���� �� �������� ������ 

		closed.push_back(pointTmp); // ����� ��������� 

		pointTmp = bfs[0];  // ������ ������� ����� 

		bfs.erase(bfs.begin()); // ��������� ������� �������� ����� 



		vector<Puzzle*> mooves = pointTmp->mooves(); // �� ������ ���������� 

		for (Puzzle* vert : mooves) { // ������� ��� ��������� 

			if (!Contains(closed, vert->getArr()) && !Contains(bfs, vert->getArr())) // �������� �� ��� ������ ���������� ��� ����� 

				bfs.push_back(vert); // ������ ����� �� ����� 

			else

				delete vert; // ��������� �� ������� ������� 

		}

	}



	vector<int*> solution = SolutionPath(pointTmp); // ���� �� ��������a 

	unsigned int finish_time = clock(); // ��� ��������� ������ ��������� 

	Display(solution, text, "BFS", finish_time - start_time); // ���� ���������� ������ �������� � TextBox  



	removeData(closed);

	removeData(bfs);





	Info write(solution.size() - 1, finish_time - start_time, "BFS", solution[solution.size() - 1], solution[0], getCurDate(), 0); // ��������� ��'���� ��� ������ � ���� 

	WriteToFile(write); // ����� ��'���� � ���� 



	return solution;

}



char* getCurDate() { // �������� ��� � ���� 

	time_t seconds = time(NULL);

	tm* timeinfo = localtime(&seconds);

	string date = addZero(to_string(timeinfo->tm_mday)) + "." + addZero(to_string(timeinfo->tm_mon + 1)) + "." + to_string(timeinfo->tm_year + 1900); // ������� ���� 

	string time = addZero(to_string(timeinfo->tm_hour)) + ":" + addZero(to_string(timeinfo->tm_min)); // �������� ��� 

	string TimeDate = date + " --- " + time;

	char* data = new char[20];

	strcpy(data, TimeDate.c_str());

	return data;

}



string addZero(string Date) { // ��������� ���� �� ��������� 

	if (Date.size() == 1)

		return "0" + Date;

	return Date;

}



bool chack(int* arr) { // �������� �� ��������� ������� 

	bool checked = true;

	for (int i = 0; i < 8; i++)

		if (arr[i] != i + 1)

			checked = false;

	return checked;

}



bool Contains(vector<Puzzle*> list, int* element) { // �� � ������� � ������ 

	bool isEquel = true;

	for (int i = 0; i < list.size(); i++) { // ����� ������� 

		isEquel = true;

		int* arrVec = list[i]->getArr();

		for (int j = 0; j < 9; j++)

			if (element[j] != arrVec[j]) // ��������� �������� 

				isEquel = false;

		if (isEquel)

			break;

	}

	if (list.size() == 0)

		isEquel = false;

	return isEquel;

}



void removeData(vector<Puzzle*> del) { // ��������� ���������� ����� 

	for (int i = 1; i < del.size(); i++)

		delete del[i];

}



vector<int*> SolutionPath(Puzzle* solution) { // ���������� ������� � ������ �� ����� ���� �� �������� 

	vector<int*> Path; // ���� �� �������� 

	Puzzle* point = solution;

	while (point->getAnc()) { // ���� ���� ������ 

		int* newArr = new int[9];

		for (int i = 0; i < 9; i++)

			newArr[i] = point->getArr()[i];

		Path.push_back(newArr); // �������� ����� �� ����� 

		point = point->getAnc();

	}

	int* newArr = new int[9];

	for (int i = 0; i < 9; i++)

		newArr[i] = point->getArr()[i];

	Path.push_back(newArr); // �������� ��������� ������� �� ����� 

	return Path;

}



void Display(vector<int*> solutionArr, System::Windows::Forms::TextBox^ text, string name, int sec) { // ���� ���������� � TextBox 



	int minuts = sec / 60000; // ������� 

	int seconds = (sec % 60000) / 1000; // ������� 

	int milisec = sec % 1000; // ̳�������� 

	string time = to_string(minuts) + "m. " + to_string(seconds) + "s. " + to_string(milisec) + "ms.--";



	text->Text = " Result: ";

	text->Text += "\r\n" + "-" + gcnew System::String(name.c_str()) + "\r\n--" + gcnew System::String(to_string(solutionArr.size() - 1).c_str()) + " steps--\r\n--took " + gcnew System::String(time.c_str());

	string oneT, secT, serdT; // ��� ����� ������� 8-puzzle 



	for (int j = 0; j < solutionArr.size(); j++) { // ���� ����� �� �������� ����������  

		oneT = secT = serdT = "";

		for (int i = 0; i < 9; i++) {

			if (i / 3 == 0)

				oneT += to_string(solutionArr[solutionArr.size() - 1 - j][i]) + "   "; // ����� � ������ ����� 

			if (i / 3 == 1)

				secT += to_string(solutionArr[solutionArr.size() - 1 - j][i]) + "   "; // ����� � ������ ����� 

			if (i / 3 == 2)

				serdT += to_string(solutionArr[solutionArr.size() - 1 - j][i]) + "   "; // ����� � ����� ����� 

		}

		text->Text += "\r\n" + gcnew System::String(to_string(j).c_str()) + ".";

		text->Text += "\r\n     " + gcnew System::String(oneT.c_str());

		text->Text += "\r\n     " + gcnew System::String(secT.c_str());

		text->Text += "\r\n     " + gcnew System::String(serdT.c_str()) + "\r\n";

	}

}



Puzzle* DLS(Puzzle* element, vector<Puzzle*> visited, int tmpDepth, int maxDepth) { // DLS �������� 

	if (tmpDepth >= maxDepth) // �������� �� ����������� ������� 

		return element;

	if (chack(element->getArr())) // �� � ������� ������� 

		return element;

	visited.push_back(element); // ������ � �������� ������� 

	vector<Puzzle*> mooves = element->mooves(); // �� ������ ���� 

	for (Puzzle* vert : mooves) {

		if (chack(vert->getArr())) // �� � ������� 

			return vert;

		if (Contains(visited, vert->getArr())) // �� ��� ��� ������� ������ ��� ���������� 

			delete vert;

		else {

			element = DLS(vert, visited, tmpDepth + 1, maxDepth); // ������� ������ �������� 

			if (chack(element->getArr())) // �� � ������� �������	 

				return element;

		}

	}

	return element;

}



void WriteToFile(Info result) { // ����� � ���� 

	ofstream File("Results.txt", ios::binary | ios::app); // ³������� �������� ����� ��� ������ 

	if (!File.is_open())

		System::Windows::Forms::MessageBox::Show("File is not open!", "Error!");

	else

		File.write((char*)&result, sizeof(Info)); // ����� � ���� 

	File.close();

}



void ReadFile(System::Windows::Forms::TextBox^ text) { // ������� �� ����� � ��������� ���������� � TextBox 

	ifstream File1("Results.txt", ios::binary); // ³������ �������� ����� ��� ������� 



	long file_size; // ������� ����� 

	File1.seekg(0, ios::end); // ���������� ��������� ��������� �� ������ ����� 

	file_size = File1.tellg(); // ������� ��������� � ���� 

	string one, two, three;

	File1.seekg(0, ios::beg); // ���������� ��������� ��������� �� ������� ����� 



	if (file_size != 0) {

		Info output;

		text->Text = "Results.txt:\r\n";

		int i = 1;

		while (File1.read((char*)&output, sizeof(Info))) { // ������� �� ����� 

			string Date = output.getDate();

			Date = Date.substr(0, 20);

			text->Text += "\r\n" + gcnew System::String(to_string(i).c_str()) + ". " + gcnew System::String(Date.c_str()); // ���� ������ 

			text->Text += "\r\n" + gcnew System::String(output.getName()); // ����� ��������� 

			if (output.getName()[0] == 'L')

				text->Text += "\r\nDepth: " + output.getDepth(); // ������� ��� LDFS 

			text->Text += "\r\n" + "--" + gcnew System::String(to_string(output.getSteps()).c_str()) + " steps--"; // ʳ������ ����� ��� �������� 

			text->Text += "\r\n" + "--took " + gcnew System::String(output.getWorkTime().c_str()) + "--\r\nStart:"; // ��� ������ ��������� 

			int* arr = output.getArrStart();

			one = two = three = "";

			for (int i = 0; i < 9; i++) {

				if (i / 3 == 0) one += to_string(arr[i]) + "   ";

				if (i / 3 == 1) two += to_string(arr[i]) + "   ";

				if (i / 3 == 2) three += to_string(arr[i]) + "   ";

			}

			text->Text += "  " + gcnew System::String(one.c_str());                // ��������� ������� ������ 

			text->Text += "\r\n          " + gcnew System::String(two.c_str());	   // ��� ������� ��������� 

			text->Text += "\r\n          " + gcnew System::String(three.c_str());  // 

			text->Text += "\r\n";

			arr = output.getArrFinish();

			one = two = three = "";

			for (int i = 0; i < 9; i++) {

				if (i / 3 == 0) one += to_string(arr[i]) + "   ";

				if (i / 3 == 1) two += to_string(arr[i]) + "   ";

				if (i / 3 == 2) three += to_string(arr[i]) + "   ";

			}

			text->Text += "\r\nFiish:";

			text->Text += "  " + gcnew System::String(one.c_str());                // ��������� ������� ������ 

			text->Text += "\r\n          " + gcnew System::String(two.c_str());	   // ��� �������� ������� 

			text->Text += "\r\n          " + gcnew System::String(three.c_str());  // 

			text->Text += "\r\n";

			i++;

		}

	}

	else

		System::Windows::Forms::MessageBox::Show("File is empty!", "Error!", System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Error);



	File1.close();

}