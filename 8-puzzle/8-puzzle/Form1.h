#pragma once
#include "Header.h"
#include <iostream>
using namespace std;
namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			arr = createArr(); // Заповнення масиву кнопок
			arrText = createTextArr(); // Заповнення масиву текстових полів
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	protected:
	private: System::Windows::Forms::Button^ button9;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox9;
	private: System::Windows::Forms::TextBox^ textBox8;
	private: System::Windows::Forms::TextBox^ textBox7;	
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Button^ Apply;



	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel1;

	private: cli::array<Button^, 1>^ arr; // Масив кнопок
	private: cli::array<TextBox^, 1>^ arrText; // Масив текстових полів

	private: System::Windows::Forms::RadioButton^ radioButton1;
	private: System::Windows::Forms::RadioButton^ radioButton2;
	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel2;
	private: System::Windows::Forms::Button^ Start;

	private: System::Windows::Forms::Button^ Clear;

	private: System::Windows::Forms::TextBox^ textBox10;


	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel3;
	private: System::Windows::Forms::TextBox^ textBox11;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ Read;
	private: System::Windows::Forms::Button^ ClearFile;






	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->Apply = (gcnew System::Windows::Forms::Button());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->flowLayoutPanel2 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->Start = (gcnew System::Windows::Forms::Button());
			this->Clear = (gcnew System::Windows::Forms::Button());
			this->textBox10 = (gcnew System::Windows::Forms::TextBox());
			this->flowLayoutPanel3 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->textBox11 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->Read = (gcnew System::Windows::Forms::Button());
			this->ClearFile = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel1->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->BackColor = System::Drawing::SystemColors::ControlDark;
			this->tableLayoutPanel1->ColumnCount = 3;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				33.33333F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				33.33333F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				33.33333F)));
			this->tableLayoutPanel1->Controls->Add(this->button8, 1, 2);
			this->tableLayoutPanel1->Controls->Add(this->button5, 1, 1);
			this->tableLayoutPanel1->Controls->Add(this->button4, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->button2, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->button1, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->button6, 2, 1);
			this->tableLayoutPanel1->Controls->Add(this->button7, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->button9, 2, 2);
			this->tableLayoutPanel1->Controls->Add(this->button3, 2, 0);
			this->tableLayoutPanel1->Location = System::Drawing::Point(12, 223);
			this->tableLayoutPanel1->Margin = System::Windows::Forms::Padding(0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 3;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 88)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(265, 265);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// button8
			// 
			this->button8->FlatAppearance->BorderColor = System::Drawing::Color::Silver;
			this->button8->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Silver;
			this->button8->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Silver;
			this->button8->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->button8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20));
			this->button8->Location = System::Drawing::Point(91, 179);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(82, 82);
			this->button8->TabIndex = 8;
			this->button8->TabStop = false;
			this->button8->Tag = L"7";
			this->button8->Text = L"8";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &Form1::button8_Click);
			// 
			// button5
			// 
			this->button5->FlatAppearance->BorderColor = System::Drawing::Color::Silver;
			this->button5->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Silver;
			this->button5->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Silver;
			this->button5->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20));
			this->button5->Location = System::Drawing::Point(91, 91);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(82, 82);
			this->button5->TabIndex = 5;
			this->button5->TabStop = false;
			this->button5->Tag = L"4";
			this->button5->Text = L"5";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Form1::button5_Click);
			// 
			// button4
			// 
			this->button4->FlatAppearance->BorderColor = System::Drawing::Color::Silver;
			this->button4->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Silver;
			this->button4->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Silver;
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20));
			this->button4->Location = System::Drawing::Point(3, 91);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(82, 82);
			this->button4->TabIndex = 4;
			this->button4->TabStop = false;
			this->button4->Tag = L"3";
			this->button4->Text = L"4";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// button2
			// 
			this->button2->FlatAppearance->BorderColor = System::Drawing::Color::Silver;
			this->button2->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Silver;
			this->button2->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Silver;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20));
			this->button2->Location = System::Drawing::Point(91, 3);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(82, 82);
			this->button2->TabIndex = 2;
			this->button2->TabStop = false;
			this->button2->Tag = L"1";
			this->button2->Text = L"2";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button1
			// 
			this->button1->FlatAppearance->BorderColor = System::Drawing::Color::Silver;
			this->button1->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Silver;
			this->button1->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Silver;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20));
			this->button1->Location = System::Drawing::Point(3, 3);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(82, 82);
			this->button1->TabIndex = 1;
			this->button1->TabStop = false;
			this->button1->Tag = L"0";
			this->button1->Text = L"1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button6
			// 
			this->button6->FlatAppearance->BorderColor = System::Drawing::Color::Silver;
			this->button6->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Silver;
			this->button6->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Silver;
			this->button6->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->button6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20));
			this->button6->Location = System::Drawing::Point(179, 91);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(82, 82);
			this->button6->TabIndex = 6;
			this->button6->TabStop = false;
			this->button6->Tag = L"5";
			this->button6->Text = L"6";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &Form1::button6_Click);
			// 
			// button7
			// 
			this->button7->FlatAppearance->BorderColor = System::Drawing::Color::Silver;
			this->button7->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Silver;
			this->button7->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Silver;
			this->button7->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->button7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20));
			this->button7->Location = System::Drawing::Point(3, 179);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(82, 82);
			this->button7->TabIndex = 7;
			this->button7->TabStop = false;
			this->button7->Tag = L"6";
			this->button7->Text = L"7";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &Form1::button7_Click);
			// 
			// button9
			// 
			this->button9->Enabled = false;
			this->button9->FlatAppearance->BorderColor = System::Drawing::Color::Silver;
			this->button9->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Silver;
			this->button9->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Silver;
			this->button9->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->button9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20));
			this->button9->Location = System::Drawing::Point(179, 179);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(83, 83);
			this->button9->TabIndex = 9;
			this->button9->TabStop = false;
			this->button9->Tag = L"8";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &Form1::button9_Click);
			// 
			// button3
			// 
			this->button3->FlatAppearance->BorderColor = System::Drawing::Color::Silver;
			this->button3->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Silver;
			this->button3->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Silver;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20));
			this->button3->Location = System::Drawing::Point(179, 3);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(82, 82);
			this->button3->TabIndex = 3;
			this->button3->TabStop = false;
			this->button3->Tag = L"2";
			this->button3->Text = L"3";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->BackColor = System::Drawing::SystemColors::ButtonShadow;
			this->tableLayoutPanel2->ColumnCount = 3;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				33.33333F)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				33.33334F)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				33.33334F)));
			this->tableLayoutPanel2->Controls->Add(this->textBox9, 2, 2);
			this->tableLayoutPanel2->Controls->Add(this->textBox8, 1, 2);
			this->tableLayoutPanel2->Controls->Add(this->textBox7, 0, 2);
			this->tableLayoutPanel2->Controls->Add(this->textBox6, 2, 1);
			this->tableLayoutPanel2->Controls->Add(this->textBox5, 1, 1);
			this->tableLayoutPanel2->Controls->Add(this->textBox4, 0, 1);
			this->tableLayoutPanel2->Controls->Add(this->textBox3, 2, 0);
			this->tableLayoutPanel2->Controls->Add(this->textBox2, 1, 0);
			this->tableLayoutPanel2->Controls->Add(this->textBox1, 0, 0);
			this->tableLayoutPanel2->Location = System::Drawing::Point(63, 12);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 3;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(165, 165);
			this->tableLayoutPanel2->TabIndex = 1;
			// 
			// textBox9
			// 
			this->textBox9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 22));
			this->textBox9->Location = System::Drawing::Point(112, 113);
			this->textBox9->MaxLength = 1;
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(48, 49);
			this->textBox9->TabIndex = 10;
			this->textBox9->Tag = L"8";
			this->textBox9->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox8
			// 
			this->textBox8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 22));
			this->textBox8->Location = System::Drawing::Point(57, 113);
			this->textBox8->MaxLength = 1;
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(48, 49);
			this->textBox8->TabIndex = 9;
			this->textBox8->Tag = L"7";
			this->textBox8->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox7
			// 
			this->textBox7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 22));
			this->textBox7->Location = System::Drawing::Point(3, 113);
			this->textBox7->MaxLength = 1;
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(48, 49);
			this->textBox7->TabIndex = 8;
			this->textBox7->Tag = L"6";
			this->textBox7->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox6
			// 
			this->textBox6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 22));
			this->textBox6->Location = System::Drawing::Point(112, 58);
			this->textBox6->MaxLength = 1;
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(48, 49);
			this->textBox6->TabIndex = 7;
			this->textBox6->Tag = L"5";
			this->textBox6->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox5
			// 
			this->textBox5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 22));
			this->textBox5->Location = System::Drawing::Point(57, 58);
			this->textBox5->MaxLength = 1;
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(48, 49);
			this->textBox5->TabIndex = 6;
			this->textBox5->Tag = L"4";
			this->textBox5->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox4
			// 
			this->textBox4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 22));
			this->textBox4->Location = System::Drawing::Point(3, 58);
			this->textBox4->MaxLength = 1;
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(48, 49);
			this->textBox4->TabIndex = 5;
			this->textBox4->Tag = L"3";
			this->textBox4->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox3
			// 
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 22));
			this->textBox3->Location = System::Drawing::Point(112, 3);
			this->textBox3->MaxLength = 1;
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(48, 49);
			this->textBox3->TabIndex = 4;
			this->textBox3->Tag = L"2";
			this->textBox3->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 22));
			this->textBox2->Location = System::Drawing::Point(57, 3);
			this->textBox2->MaxLength = 1;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(48, 49);
			this->textBox2->TabIndex = 3;
			this->textBox2->Tag = L"1";
			this->textBox2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 22));
			this->textBox1->Location = System::Drawing::Point(3, 3);
			this->textBox1->MaxLength = 1;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(48, 49);
			this->textBox1->TabIndex = 2;
			this->textBox1->Tag = L"0";
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// Apply
			// 
			this->Apply->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->Apply->Location = System::Drawing::Point(15, 183);
			this->Apply->Name = L"Apply";
			this->Apply->Size = System::Drawing::Size(82, 32);
			this->Apply->TabIndex = 2;
			this->Apply->TabStop = false;
			this->Apply->Text = L"Apply";
			this->Apply->UseVisualStyleBackColor = true;
			this->Apply->Click += gcnew System::EventHandler(this, &Form1::Apply_Click);
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->flowLayoutPanel1->Location = System::Drawing::Point(3, 5);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(284, 490);
			this->flowLayoutPanel1->TabIndex = 3;
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Checked = true;
			this->radioButton1->Location = System::Drawing::Point(321, 12);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(54, 20);
			this->radioButton1->TabIndex = 4;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"BFS";
			this->radioButton1->UseVisualStyleBackColor = true;
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(321, 41);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(62, 20);
			this->radioButton2->TabIndex = 5;
			this->radioButton2->Text = L"LDFS";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// flowLayoutPanel2
			// 
			this->flowLayoutPanel2->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->flowLayoutPanel2->Location = System::Drawing::Point(310, 5);
			this->flowLayoutPanel2->Name = L"flowLayoutPanel2";
			this->flowLayoutPanel2->Size = System::Drawing::Size(314, 67);
			this->flowLayoutPanel2->TabIndex = 6;
			// 
			// Start
			// 
			this->Start->Location = System::Drawing::Point(502, 25);
			this->Start->Name = L"Start";
			this->Start->Size = System::Drawing::Size(98, 27);
			this->Start->TabIndex = 7;
			this->Start->Text = L"Start!";
			this->Start->UseVisualStyleBackColor = true;
			this->Start->Click += gcnew System::EventHandler(this, &Form1::Start_Click);
			// 
			// Clear
			// 
			this->Clear->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->Clear->Location = System::Drawing::Point(191, 183);
			this->Clear->Name = L"Clear";
			this->Clear->Size = System::Drawing::Size(82, 32);
			this->Clear->TabIndex = 8;
			this->Clear->TabStop = false;
			this->Clear->Text = L"Clear";
			this->Clear->UseVisualStyleBackColor = true;
			this->Clear->Click += gcnew System::EventHandler(this, &Form1::Clear_Click);
			// 
			// textBox10
			// 
			this->textBox10->Location = System::Drawing::Point(321, 89);
			this->textBox10->Multiline = true;
			this->textBox10->Name = L"textBox10";
			this->textBox10->ReadOnly = true;
			this->textBox10->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBox10->Size = System::Drawing::Size(292, 356);
			this->textBox10->TabIndex = 9;
			this->textBox10->TabStop = false;
			// 
			// flowLayoutPanel3
			// 
			this->flowLayoutPanel3->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->flowLayoutPanel3->Location = System::Drawing::Point(310, 78);
			this->flowLayoutPanel3->Name = L"flowLayoutPanel3";
			this->flowLayoutPanel3->Size = System::Drawing::Size(314, 417);
			this->flowLayoutPanel3->TabIndex = 7;
			// 
			// textBox11
			// 
			this->textBox11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->textBox11->Location = System::Drawing::Point(389, 38);
			this->textBox11->Name = L"textBox11";
			this->textBox11->Size = System::Drawing::Size(98, 24);
			this->textBox11->TabIndex = 10;
			this->textBox11->TextChanged += gcnew System::EventHandler(this, &Form1::textBox11_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label1->Location = System::Drawing::Point(385, 12);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(59, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Depth:";
			// 
			// Read
			// 
			this->Read->Location = System::Drawing::Point(321, 451);
			this->Read->Name = L"Read";
			this->Read->Size = System::Drawing::Size(138, 33);
			this->Read->TabIndex = 0;
			this->Read->Text = L"Read File";
			this->Read->UseVisualStyleBackColor = true;
			this->Read->Click += gcnew System::EventHandler(this, &Form1::Read_Click);
			// 
			// ClearFile
			// 
			this->ClearFile->Location = System::Drawing::Point(480, 451);
			this->ClearFile->Name = L"ClearFile";
			this->ClearFile->Size = System::Drawing::Size(133, 33);
			this->ClearFile->TabIndex = 11;
			this->ClearFile->Text = L"Clear File";
			this->ClearFile->UseVisualStyleBackColor = true;
			this->ClearFile->Click += gcnew System::EventHandler(this, &Form1::ClearFile_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(636, 500);
			this->Controls->Add(this->ClearFile);
			this->Controls->Add(this->Read);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox11);
			this->Controls->Add(this->textBox10);
			this->Controls->Add(this->Clear);
			this->Controls->Add(this->Start);
			this->Controls->Add(this->radioButton2);
			this->Controls->Add(this->radioButton1);
			this->Controls->Add(this->Apply);
			this->Controls->Add(this->tableLayoutPanel2);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Controls->Add(this->flowLayoutPanel1);
			this->Controls->Add(this->flowLayoutPanel2);
			this->Controls->Add(this->flowLayoutPanel3);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"8-puzzle";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel2->ResumeLayout(false);
			this->tableLayoutPanel2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion



	private: cli::array<Button^, 1>^ createArr(); // Заповнення масиву кнопок
	private: cli::array<TextBox^, 1>^ createTextArr(); // Заповнення масиву текстових полів

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) { mooveButton(button1, arr); }
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) { mooveButton(button2, arr); }
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) { mooveButton(button3, arr); }
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) { mooveButton(button4, arr); }
	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) { mooveButton(button5, arr); }
	private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) { mooveButton(button6, arr); }
	private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) { mooveButton(button7, arr); }
	private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) { mooveButton(button8, arr); }
	private: System::Void button9_Click(System::Object^ sender, System::EventArgs^ e) { mooveButton(button9, arr); }
	private: System::Void Apply_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Start_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Clear_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void textBox11_TextChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Read_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void ClearFile_Click(System::Object^ sender, System::EventArgs^ e);
};
}
