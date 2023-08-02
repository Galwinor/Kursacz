#include "pch.h"
#include "Form1.h"
#include <random>
#include <fstream>
#include <msclr\marshal_cppstd.h>
namespace CppCLRWinFormsProject {
	using namespace std;
	cli::array<Button^, 1>^ Form1::createArr() { // Створення масиву кнопок
		cli::array<Button^, 1>^ arr = gcnew cli::array<Button^, 1>(9);
		arr[0] = button1;
		arr[1] = button2;
		arr[2] = button3;
		arr[3] = button4;
		arr[4] = button5;
		arr[5] = button6;
		arr[6] = button7;
		arr[7] = button8;
		arr[8] = button9;
		return arr;
	}

	cli::array<TextBox^, 1>^ Form1::createTextArr() { // Створення масиву текстових полів
		cli::array<TextBox^, 1>^ arr1 = gcnew cli::array<TextBox^, 1>(9);
		arr1[0] = textBox1;
		arr1[1] = textBox2;
		arr1[2] = textBox3;
		arr1[3] = textBox4;
		arr1[4] = textBox5;
		arr1[5] = textBox6;
		arr1[6] = textBox7;
		arr1[7] = textBox8;
		arr1[8] = textBox9;
		return arr1;
	}

    System::Void Form1::Apply_Click(System::Object^ sender, System::EventArgs^ e) { // Кнопка для перенесення написів з текстових полів на кнопки
		for (int i = 0; i < 9; i++) { // Перевірка всіх чисел текстових полів
			char curText = (msclr::interop::marshal_as<string>(arrText[i]->Text->ToString()))[0];
			if (isdigit(curText)) { // Чи є символ цифрою
				if (atoi(&curText) != 9) { // Чи не є символ девяткою
					for (int j = 0; j < 9; j++)
						if (curText == (msclr::interop::marshal_as<string>(arrText[j]->Text->ToString()))[0] && arrText[i]->Tag != arrText[j]->Tag) // Перевірка на однакові цифри
							arrText[i]->Text = "";
				}
				else
					arrText[i]->Text = "";
			}
			else
				arrText[i]->Text = "";
		}

		int arrNum[9];
		bool fill = true;
		for (int i = 0; i < 9; i++) {
			if (arrText[i]->Text == "") { // Перевірка чи всі цифри введені коректно
				MessageBox::Show("Invalid values!", "Error!", MessageBoxButtons::OK, MessageBoxIcon::Error);
				fill = false;
				break;
			}
			arrNum[i] = stoi(msclr::interop::marshal_as<string>(arrText[i]->Text->ToString()));
		}

		if (fill) // Перенесення значень на кнопки
			for (int i = 0; i < 9; i++) {
				if (arrNum[i] == 0) {
					arr[i]->Text = "";
					arr[i]->Enabled = false;
				}
				else {
					arr[i]->Text = arrNum[i].ToString();
					arr[i]->Enabled = true;
				}
			}

	}

	System::Void Form1::Start_Click(System::Object^ sender, System::EventArgs^ e) { // Кнопка для вирішення 8-puzzle

		int depth = 0; // Максимальна глибина для LDFS алгоритму
		if (textBox11->Text != "")
			depth = stoi(msclr::interop::marshal_as<string>(textBox11->Text->ToString()));

		int *arrNumer = new int[9]; // Масив для цифр з поля 8-puzzle
		for (int i = 0; i < 9; i++) {
			string an = msclr::interop::marshal_as<string>(arr[i]->Text->ToString());
			if (an != "")
				arrNumer[i] = stoi(an);
			else
				arrNumer[i] = 0;
		}
		vector<int*> sol; // Шлях до вирішення задачі
		if (radioButton1->Checked)
			sol = BFS(arrNumer, textBox10); // BFS алгоритм
		else {
			Puzzle* root = new Puzzle(arrNumer); // Перший елемент
			vector<Puzzle*> visited; // Елементи які були оброблені
			int time_start = clock(); // Час початку роботи алгоритму
			root = DLS(root, visited, 0, depth); // LDFS(DLS) алгоритм
			int time_finish = clock(); // Час закінчення роботи алгоритму
			sol = SolutionPath(root); // Шлях до вирішення
			Display(sol, textBox10, "LDFS", time_finish - time_start); // Вивід результатів

			Info write(sol.size() - 1, time_finish - time_start, "LDFS", sol[sol.size() - 1], sol[0], getCurDate(), depth); // Об'єкт де зберігаються результати роботи алгоритму
			WriteToFile(write); // Запис результатів у файл
		}
		if (!chack(sol[0]))
			MessageBox::Show("Too small depth!", "Error!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		for (int i = 0; i < 9; i++) { // Відображення результату на кнопки
			if (sol[0][i] != 0) {
				arr[i]->Text = sol[0][i].ToString();
				arr[i]->Enabled = true;
			}
			else {
				arr[i]->Text = "";
				arr[i]->Enabled = false;
			}
		}
	}

	System::Void Form1::Clear_Click(System::Object^ sender, System::EventArgs^ e) { // Вернути 8-puzzle в початкове положення
		for (int i = 1; i < 9; i++) { 
			arr[i - 1]->Text = i.ToString();
			arr[i - 1]->Enabled = true;
		}
		arr[8]->Enabled = false;
		arr[8]->Text = "";
	}

	System::Void Form1::textBox11_TextChanged(System::Object^ sender, System::EventArgs^ e) { // Поле для введення глубини
		if (textBox11->Text != "") { //Первірка чи не пусте поле
			string line = msclr::interop::marshal_as<string>(textBox11->Text->ToString());
			for(int i = 0; i < line.size(); i++)
				if (!isdigit(line[i])) { // Перевірка чи є символ цифрою
					line = line.substr(0, i) + line.substr(i + 1);
					textBox11->Text = gcnew System::String(line.c_str());
					textBox11->Select(i, 0);
				}
		}
	}

	System::Void Form1::Form1_Load(System::Object^ sender, System::EventArgs^ e) {
		textBox11->Text = "10"; // Значення за замовчуванням
		textBox11->Enabled = false;
	}

	System::Void Form1::Read_Click(System::Object^ sender, System::EventArgs^ e) {
		ReadFile(textBox10);
	}

	System::Void Form1::ClearFile_Click(System::Object^ sender, System::EventArgs^ e) {
		ofstream File("Results.txt", ios::binary);
		File.close();
		MessageBox::Show("File is empty now!");
	}

	System::Void Form1::radioButton1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		textBox11->Enabled = !textBox11->Enabled;
	}
}