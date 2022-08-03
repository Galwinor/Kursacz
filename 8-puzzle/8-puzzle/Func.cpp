#include "pch.h" 

#include "Header.h" 

#include <string> 

#include <ctime> 

#include <fstream> 

#include <msclr\marshal_cppstd.h> 



using namespace std;



void mooveButton(System::Windows::Forms::Button^ curButt, cli::array<System::Windows::Forms::Button^, 1>^ arr) { // Переміщення кнопок вручну 

	int currTag = stoi(msclr::interop::marshal_as<string>(curButt->Tag->ToString())); // Поточна кнопка 

	if (currTag + 1 < 9) // Чи не виходить за поле 

		if (arr[currTag + 1]->Text == "" && currTag / 3 == (currTag + 1) / 3) { // Чи можна рухати цю кнопку 

			string text = msclr::interop::marshal_as<string>(curButt->Text->ToString()); // Напис на кнопці 

			curButt->Text = ""; // Пересунути 0 на місце поточної кнопки 

			arr[currTag + 1]->Text = stoi(text) + ""; // Записати на місце 0 текст поточної кнопки 

			curButt->Enabled = false; // Зробити 0 недоступним для натискання 

			arr[currTag + 1]->Enabled = true; // Відновити можливість натимнення на кнопку де немає 0 

		}

	if (currTag - 1 >= 0) // Чи не виходить за поле 

		if (arr[currTag - 1]->Text == "" && currTag / 3 == (currTag - 1) / 3) {// Чи можна рухати цю кнопку 

			string text = msclr::interop::marshal_as<string>(curButt->Text->ToString());

			curButt->Text = "";

			arr[currTag - 1]->Text = stoi(text) + "";

			curButt->Enabled = false;

			arr[currTag - 1]->Enabled = true;

		}

	if (currTag + 3 < 9) // Чи не виходить за поле 

		if (arr[currTag + 3]->Text == "" && currTag / 3 + 1 == (currTag + 3) / 3) {// Чи можна рухати цю кнопку 

			string text = msclr::interop::marshal_as<string>(curButt->Text->ToString());

			curButt->Text = "";

			arr[currTag + 3]->Text = stoi(text) + "";

			curButt->Enabled = false;

			arr[currTag + 3]->Enabled = true;

		}

	if (currTag - 3 >= 0) // Чи не виходить за поле 

		if (arr[currTag - 3]->Text == "" && currTag / 3 - 1 == (currTag - 3) / 3) {// Чи можна рухати цю кнопку 

			string text = msclr::interop::marshal_as<string>(curButt->Text->ToString());

			curButt->Text = "";

			arr[currTag - 3]->Text = stoi(text) + "";

			curButt->Enabled = false;

			arr[currTag - 3]->Enabled = true;

		}

}



vector<int*> BFS(int* ar, System::Windows::Forms::TextBox^ text) { // БФС алгоритм 



	unsigned int start_time = clock(); // Час початку роботи алгоритму 



	Puzzle* vert = new Puzzle(ar); // Вузол дерева 

	vector<Puzzle*> bfs; // Черга 

	vector<Puzzle*> closed; // Елементи які були проаналізовані 

	bfs.push_back(vert); // Додавання вузла до черги 

	Puzzle* pointTmp = vert; // Покажчик на поточний вузол 





	while (!chack(pointTmp->getArr())) { // Поки не знайдено рішення 

		closed.push_back(pointTmp); // Вузол оброблено 

		pointTmp = bfs[0];  // Перший елемент черги 

		bfs.erase(bfs.begin()); // Видалення першого елементу черги 



		vector<Puzzle*> mooves = pointTmp->mooves(); // Всі можливі переміщення 

		for (Puzzle* vert : mooves) { // Обробка всіх переміщень 

			if (!Contains(closed, vert->getArr()) && !Contains(bfs, vert->getArr())) // Перевірка чи був колись оброблений цей вузол 

				bfs.push_back(vert); // Додати вузол до черги 

			else

				delete vert; // Видалення не потрібної вершини 

		}

	}



	vector<int*> solution = SolutionPath(pointTmp); // Шлях до вирішенняa 

	unsigned int finish_time = clock(); // Час закінчення роботи алгоритму 

	Display(solution, text, "BFS", finish_time - start_time); // Вивід результату роботи програми у TextBox  



	removeData(closed);

	removeData(bfs);





	Info write(solution.size() - 1, finish_time - start_time, "BFS", solution[solution.size() - 1], solution[0], getCurDate(), 0); // Створення об'єкту для запису у файл 

	WriteToFile(write); // Запис об'єкта у файл 



	return solution;

}



char* getCurDate() { // Поточний час і дата 

	time_t seconds = time(NULL);

	tm* timeinfo = localtime(&seconds);

	string date = addZero(to_string(timeinfo->tm_mday)) + "." + addZero(to_string(timeinfo->tm_mon + 1)) + "." + to_string(timeinfo->tm_year + 1900); // Поточна дата 

	string time = addZero(to_string(timeinfo->tm_hour)) + ":" + addZero(to_string(timeinfo->tm_min)); // Поточний час 

	string TimeDate = date + " --- " + time;

	char* data = new char[20];

	strcpy(data, TimeDate.c_str());

	return data;

}



string addZero(string Date) { // Додавання нуля за відсутності 

	if (Date.size() == 1)

		return "0" + Date;

	return Date;

}



bool chack(int* arr) { // Перевірка на правильну відповідь 

	bool checked = true;

	for (int i = 0; i < 8; i++)

		if (arr[i] != i + 1)

			checked = false;

	return checked;

}



bool Contains(vector<Puzzle*> list, int* element) { // Чи є елемент у векторі 

	bool isEquel = true;

	for (int i = 0; i < list.size(); i++) { // Обхід вектора 

		isEquel = true;

		int* arrVec = list[i]->getArr();

		for (int j = 0; j < 9; j++)

			if (element[j] != arrVec[j]) // Порівнення елементів 

				isEquel = false;

		if (isEquel)

			break;

	}

	if (list.size() == 0)

		isEquel = false;

	return isEquel;

}



void removeData(vector<Puzzle*> del) { // Видалення непотрібних вузлів 

	for (int i = 1; i < del.size(); i++)

		delete del[i];

}



vector<int*> SolutionPath(Puzzle* solution) { // Формування вектору з масиву на кожен крок до вирішення 

	vector<int*> Path; // Шлях до вирішення 

	Puzzle* point = solution;

	while (point->getAnc()) { // Поки існує балько 

		int* newArr = new int[9];

		for (int i = 0; i < 9; i++)

			newArr[i] = point->getArr()[i];

		Path.push_back(newArr); // Записуємо масив до шляху 

		point = point->getAnc();

	}

	int* newArr = new int[9];

	for (int i = 0; i < 9; i++)

		newArr[i] = point->getArr()[i];

	Path.push_back(newArr); // Записуємо кореневий елемент до шляху 

	return Path;

}



void Display(vector<int*> solutionArr, System::Windows::Forms::TextBox^ text, string name, int sec) { // Вивід інформації у TextBox 



	int minuts = sec / 60000; // Хвилини 

	int seconds = (sec % 60000) / 1000; // Секунди 

	int milisec = sec % 1000; // Мілісекунди 

	string time = to_string(minuts) + "m. " + to_string(seconds) + "s. " + to_string(milisec) + "ms.--";



	text->Text = " Result: ";

	text->Text += "\r\n" + "-" + gcnew System::String(name.c_str()) + "\r\n--" + gcnew System::String(to_string(solutionArr.size() - 1).c_str()) + " steps--\r\n--took " + gcnew System::String(time.c_str());

	string oneT, secT, serdT; // Три рядки матриці 8-puzzle 



	for (int j = 0; j < solutionArr.size(); j++) { // Вивід шляху до кінцевого результату  

		oneT = secT = serdT = "";

		for (int i = 0; i < 9; i++) {

			if (i / 3 == 0)

				oneT += to_string(solutionArr[solutionArr.size() - 1 - j][i]) + "   "; // Запис у перший рядок 

			if (i / 3 == 1)

				secT += to_string(solutionArr[solutionArr.size() - 1 - j][i]) + "   "; // Запис у другий рядок 

			if (i / 3 == 2)

				serdT += to_string(solutionArr[solutionArr.size() - 1 - j][i]) + "   "; // Запис у третій рядок 

		}

		text->Text += "\r\n" + gcnew System::String(to_string(j).c_str()) + ".";

		text->Text += "\r\n     " + gcnew System::String(oneT.c_str());

		text->Text += "\r\n     " + gcnew System::String(secT.c_str());

		text->Text += "\r\n     " + gcnew System::String(serdT.c_str()) + "\r\n";

	}

}



Puzzle* DLS(Puzzle* element, vector<Puzzle*> visited, int tmpDepth, int maxDepth) { // DLS алгоритм 

	if (tmpDepth >= maxDepth) // Перевірка на максимальну глубину 

		return element;

	if (chack(element->getArr())) // Чи є елемент шуканим 

		return element;

	visited.push_back(element); // Додати у оброблені вершини 

	vector<Puzzle*> mooves = element->mooves(); // Всі можливі рухи 

	for (Puzzle* vert : mooves) {

		if (chack(vert->getArr())) // Чи є шуканим 

			return vert;

		if (Contains(visited, vert->getArr())) // Чи був цей елемент колись вже перевірений 

			delete vert;

		else {

			element = DLS(vert, visited, tmpDepth + 1, maxDepth); // Обробка нового елементу 

			if (chack(element->getArr())) // Чи є елемент шуканим	 

				return element;

		}

	}

	return element;

}



void WriteToFile(Info result) { // Запис у файл 

	ofstream File("Results.txt", ios::binary | ios::app); // Відкриття бінарного файла для запису 

	if (!File.is_open())

		System::Windows::Forms::MessageBox::Show("File is not open!", "Error!");

	else

		File.write((char*)&result, sizeof(Info)); // Запис у файл 

	File.close();

}



void ReadFile(System::Windows::Forms::TextBox^ text) { // Читання із файла і виведення результатів у TextBox 

	ifstream File1("Results.txt", ios::binary); // Відриття бінарного файла для читання 



	long file_size; // Довжина файла 

	File1.seekg(0, ios::end); // Переміщення файлового покажчика на цінець файлу 

	file_size = File1.tellg(); // Позиція покажчика у файлі 

	string one, two, three;

	File1.seekg(0, ios::beg); // Переміщення файлового покажчика на початок файлу 



	if (file_size != 0) {

		Info output;

		text->Text = "Results.txt:\r\n";

		int i = 1;

		while (File1.read((char*)&output, sizeof(Info))) { // Читання із файлу 

			string Date = output.getDate();

			Date = Date.substr(0, 20);

			text->Text += "\r\n" + gcnew System::String(to_string(i).c_str()) + ". " + gcnew System::String(Date.c_str()); // Дата запису 

			text->Text += "\r\n" + gcnew System::String(output.getName()); // Назва алгоритму 

			if (output.getName()[0] == 'L')

				text->Text += "\r\nDepth: " + output.getDepth(); // Глибина для LDFS 

			text->Text += "\r\n" + "--" + gcnew System::String(to_string(output.getSteps()).c_str()) + " steps--"; // Кількість кроків для вирішення 

			text->Text += "\r\n" + "--took " + gcnew System::String(output.getWorkTime().c_str()) + "--\r\nStart:"; // Час роботи алгоритму 

			int* arr = output.getArrStart();

			one = two = three = "";

			for (int i = 0; i < 9; i++) {

				if (i / 3 == 0) one += to_string(arr[i]) + "   ";

				if (i / 3 == 1) two += to_string(arr[i]) + "   ";

				if (i / 3 == 2) three += to_string(arr[i]) + "   ";

			}

			text->Text += "  " + gcnew System::String(one.c_str());                // Виведення позицій кнопок 

			text->Text += "\r\n          " + gcnew System::String(two.c_str());	   // при запуску алгоритму 

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

			text->Text += "  " + gcnew System::String(one.c_str());                // Виведення позицій кнопок 

			text->Text += "\r\n          " + gcnew System::String(two.c_str());	   // при закінченні обробки 

			text->Text += "\r\n          " + gcnew System::String(three.c_str());  // 

			text->Text += "\r\n";

			i++;

		}

	}

	else

		System::Windows::Forms::MessageBox::Show("File is empty!", "Error!", System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Error);



	File1.close();

}