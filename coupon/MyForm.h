#pragma once

namespace coupon {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;


	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Timer^ timer1;
	private:
		int currentIndex;
		int stopIndex;
		int steps;
		int timerInterval;
		bool spinning;
		System::Random^ rng;
		array<System::Windows::Forms::Button^>^ choiceButtons;
	private: System::Windows::Forms::Label^ label2;

	private: System::ComponentModel::IContainer^ components;

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 22.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::MenuText;
			this->label1->Location = System::Drawing::Point(409, 51);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(1090, 50);
			this->label1->TabIndex = 0;
			this->label1->Text = L"________Get exclusive discounts on your next flight________";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.BackgroundImage")));
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 30, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(325, 152);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(277, 237);
			this->button1->TabIndex = 1;
			this->button1->UseVisualStyleBackColor = false;
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button5.BackgroundImage")));
			this->button5->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 30, System::Drawing::FontStyle::Bold));
			this->button5->Location = System::Drawing::Point(869, 472);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(277, 237);
			this->button5->TabIndex = 2;
			this->button5->UseVisualStyleBackColor = false;
			// 
			// button6
			// 
			this->button6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button6->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button6.BackgroundImage")));
			this->button6->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 30, System::Drawing::FontStyle::Bold));
			this->button6->Location = System::Drawing::Point(1401, 486);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(277, 237);
			this->button6->TabIndex = 3;
			this->button6->UseVisualStyleBackColor = false;
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button4.BackgroundImage")));
			this->button4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 30, System::Drawing::FontStyle::Bold));
			this->button4->Location = System::Drawing::Point(324, 472);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(277, 237);
			this->button4->TabIndex = 4;
			this->button4->UseVisualStyleBackColor = false;
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button2.BackgroundImage")));
			this->button2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 30, System::Drawing::FontStyle::Bold));
			this->button2->Location = System::Drawing::Point(869, 152);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(277, 237);
			this->button2->TabIndex = 5;
			this->button2->UseVisualStyleBackColor = false;
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button3.BackgroundImage")));
			this->button3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 30, System::Drawing::FontStyle::Bold));
			this->button3->Location = System::Drawing::Point(1401, 152);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(277, 237);
			this->button3->TabIndex = 6;
			this->button3->UseVisualStyleBackColor = false;
			// 
			// button7
			// 
			this->button7->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->button7->Font = (gcnew System::Drawing::Font(L"Bernard MT Condensed", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button7->Location = System::Drawing::Point(450, 850);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(92, 33);
			this->button7->TabIndex = 7;
			this->button7->Text = L"start";
			this->button7->UseVisualStyleBackColor = false;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 35, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label2->Location = System::Drawing::Point(650, 833);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(0, 67);
			this->label2->TabIndex = 8;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(1506, 966);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		private:
			array<System::Drawing::Image^>^ buttonImages;
			array<System::String^>^ couponTexts;
#pragma endregion

	private: System::Void ResetButtons() {
		for (int i = 0; i < 6; i++) {
			choiceButtons[i]->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));;
			choiceButtons[i]->ForeColor = System::Drawing::Color::Black;
		}
	}array<String^>^ originalTexts;

	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {

		choiceButtons = gcnew array<System::Windows::Forms::Button^>(6);
		choiceButtons[0] = button1;
		choiceButtons[1] = button2;
		choiceButtons[2] = button3;
		choiceButtons[3] = button4;
		choiceButtons[4] = button5;
		choiceButtons[5] = button6;

		couponTexts = gcnew array<System::String^>(6);
		couponTexts[0] = L"save 20%";
		couponTexts[1] = L"save 50%";
		couponTexts[2] = L"save 10%";
		couponTexts[3] = L"save 30%";
		couponTexts[4] = L"save 40%";
		couponTexts[5] = L"Hard Luck";

		buttonImages = gcnew array<System::Drawing::Image^>(6);

		for (int i = 0; i < 6; i++) {
			System::String^ path = System::IO::Path::Combine(
				System::Windows::Forms::Application::StartupPath,
				L"img" + (i + 1).ToString() + L".png"
			);

			if (System::IO::File::Exists(path)) {
				buttonImages[i] = System::Drawing::Image::FromFile(path);
				choiceButtons[i]->BackgroundImage = buttonImages[i];
				choiceButtons[i]->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			}

			choiceButtons[i]->Text = L"";
			choiceButtons[i]->Image = nullptr;
			choiceButtons[i]->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		}

		rng = gcnew System::Random();
		currentIndex = 0;
		stopIndex = 0;
		steps = 0;
		timerInterval = 80;
		spinning = false;

	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {

		ResetButtons();
		choiceButtons[currentIndex]->BackColor = System::Drawing::Color::Yellow;
		choiceButtons[currentIndex]->ForeColor = System::Drawing::Color::Black;

		steps++;

		if (steps > 30 && currentIndex == stopIndex) {
			timer1->Stop();
			spinning = false;

			choiceButtons[currentIndex]->BackgroundImage = nullptr;
			choiceButtons[currentIndex]->Text = couponTexts[currentIndex];

			choiceButtons[currentIndex]->BackColor = System::Drawing::Color::LimeGreen;
			choiceButtons[currentIndex]->ForeColor = System::Drawing::Color::White;
			choiceButtons[currentIndex]->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;

			if (currentIndex == 5) {
				label2->Text = couponTexts[currentIndex];
				this->label2->Location = System::Drawing::Point(645, 685);
			}
			else {
				label2->Text = L"congrats you can " + couponTexts[currentIndex];
				this->label2->Location = System::Drawing::Point(500, 675);
			}
			this->label2->BackColor = System::Drawing::Color::LightYellow;
			button7->Enabled = true;
			this->button7->Text = L"start";
			return;
		}

		currentIndex = (currentIndex + 1) % 6;
	}
	private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
		if (spinning) return;

		ResetButtons();

		stopIndex = rng->Next(0, 6);
		currentIndex = 0;
		steps = 0;
		timerInterval = 80;
		spinning = true;

		label1->Text = L"________Get exclusive discounts on your next flight________";
		label2->Text = L"";

		timer1->Stop();
		timer1->Interval = timerInterval;
		timer1->Start();

		button7->Enabled = false;
		button7->Text = L"wait";
	}
};
}