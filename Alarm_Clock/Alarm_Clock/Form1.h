#pragma once
#include <string>
#include <thread>
#include <ctime>

namespace CppCLRWinformsProjekt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;// Для многопоточности
	/// <summary>
	/// Zusammenfassung f�r Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
		start:
			InitializeComponent();
			//
			//TODO: Konstruktorcode hier hinzuf�gen.
			//
		}

		void PlayMusic()// Воспроизвести звонок
		{

			simpleSound->Play();//Начать проигрыш музыки
			_sleep(5000);
			simpleSound->Stop();//Конец через 5 секунд

		}

		void CheckTime() {
			time_t now = time(0);
			tm* ltm = localtime(&now);
			while (now_hours != hours)
			{
				now_hours = ltm->tm_hour;
				textBox3->Text = Convert::ToString(now_hours);
			}
			while (now_minute != minutes)
			{
				now_minute = ltm->tm_min;
				textBox2->Text = Convert::ToString(now_minute);
			}
			simpleSound->Play();
			MessageBox::Show("Время вышло", "Внимание", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~Form1()
		{
			simpleSound->Stop();
			playDemo->Abort();
			play->Abort();
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::ComboBox^ comboBox2;

	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Label^ label1;


	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ textBox5;




	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>
		System::ComponentModel::Container^ components;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode f�r die Designerunterst�tzung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor ge�ndert werden.
		/// </summary>


		void InitializeComponent(void)
		{
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(60) {
				L"0", L"1", L"2", L"3", L"4", L"5", L"6", L"7",
					L"8", L"9", L"10", L"11", L"12", L"13", L"14", L"15", L"16", L"17", L"18", L"19", L"20", L"21", L"22", L"23", L"24", L"25", L"26",
					L"27", L"28", L"29", L"30", L"31", L"32", L"33", L"34", L"35", L"36", L"37", L"38", L"39", L"40", L"41", L"42", L"43", L"44",
					L"45", L"46", L"47", L"48", L"49", L"50", L"51", L"52", L"53", L"54", L"55", L"56", L"57", L"58", L"59"
			});
			this->comboBox1->Location = System::Drawing::Point(158, 173);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(50, 21);
			this->comboBox1->TabIndex = 1;
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(24) {
				L"0", L"1", L"2", L"3", L"4", L"5", L"6", L"7",
					L"8", L"9", L"10", L"11", L"12", L"13", L"14", L"15", L"16", L"17", L"18", L"19", L"20", L"21", L"22", L"23"
			});
			this->comboBox2->Location = System::Drawing::Point(101, 173);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(50, 21);
			this->comboBox2->TabIndex = 2;
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 41);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(281, 20);
			this->textBox1->TabIndex = 4;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(281, 26);
			this->button1->TabIndex = 5;
			this->button1->Text = L"Выбрать мелодию для звонка";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(12, 67);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(140, 20);
			this->button2->TabIndex = 6;
			this->button2->Text = L"Прослушать";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(158, 67);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(135, 20);
			this->button3->TabIndex = 7;
			this->button3->Text = L"Остановить";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(77, 127);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(164, 13);
			this->label1->TabIndex = 8;
			this->label1->Text = L"Время для звонка";
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(80, 213);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(161, 23);
			this->button4->TabIndex = 11;
			this->button4->Text = L"Завести будильник";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(162, 157);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(46, 13);
			this->label2->TabIndex = 12;
			this->label2->Text = L"Минуты";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(114, 157);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(35, 13);
			this->label3->TabIndex = 13;
			this->label3->Text = L"Часы	";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(118, 298);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 14;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(12, 298);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 20);
			this->textBox3->TabIndex = 15;
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(101, 243);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(107, 23);
			this->button5->TabIndex = 16;
			this->button5->Text = L"Выключить";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Form1::button5_Click);
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(118, 272);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(100, 20);
			this->textBox4->TabIndex = 18;
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(12, 272);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(100, 20);
			this->textBox5->TabIndex = 17;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(306, 330);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->comboBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"Form1";
			this->Text = L"Clock";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		String^ melodyPath = nullptr;
		bool stop = false;
		System::Media::SoundPlayer^ simpleSound;
		int now_minute, now_hours;
		int	minutes, hours;


#pragma endregion
	private: System::Threading::Thread^ playDemo;
	private: System::Threading::Thread^ play;
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) { // выбор музыкального файла
		openFileDialog1->DefaultExt = ".wav"; //ограничитель расширений
		openFileDialog1->Filter = "Music document|*.wav";//фильтр отображений
		openFileDialog1->ShowDialog();//Показать проводник
		melodyPath = openFileDialog1->FileName;//указать путь к файлу
		textBox1->Text = melodyPath;
		simpleSound = gcnew	System::Media::SoundPlayer(melodyPath);
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) { //���������� �������	

		if (melodyPath == nullptr)
		{
			MessageBox::Show("Путь к файлу не указан", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		playDemo = gcnew Thread(gcnew ThreadStart(this, &Form1::PlayMusic));
		if (!playDemo->IsAlive)
		{
			playDemo->Start();
		}
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		if (melodyPath == nullptr)
		{
			MessageBox::Show("Путь к файлу не указан", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}
		else if (playDemo->IsAlive)
		{
			simpleSound->Stop();
			playDemo->Abort();
		}
		else
		{
			MessageBox::Show("Сейчас ничего не играет", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}
	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		if (comboBox1->Text == "" || comboBox2->Text == "")
		{
			MessageBox::Show("Время не указано", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		minutes = Convert::ToInt32(comboBox1->Text);
		textBox4->Text = Convert::ToString(minutes);
		hours = Convert::ToInt32(comboBox2->Text);
		textBox5->Text = Convert::ToString(hours);

		if ((minutes < 0 && minutes > 59) || (hours < 0 && hours > 23))
		{
			MessageBox::Show("Неверно указано время", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		play = gcnew Thread(gcnew ThreadStart(this, &Form1::CheckTime));
		play->Start();
	}
	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
		simpleSound->Stop();

	}
	};
}
