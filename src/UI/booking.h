#pragma once
#include <msclr/marshal_cppstd.h>
#include "include/Booking_struct.h"
#include "include/add_flights.h"
#include "UI/sign_up_users_form.h"
using namespace std;
using namespace System::Text::RegularExpressions;
using namespace msclr::interop;
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

extern string flight_category;
extern int selected_flight_idx;

extern int adult_cnt_value;
extern int children_cnt_value;
extern int infants_cnt_value;
extern int total_travelers;
extern int adult_price;


namespace skyPort {

	/// <summary>
	/// Summary for booking
	/// </summary>

	//ref class user_home_page;
	public ref class booking : public System::Windows::Forms::UserControl
	{
	public:
		Form^ userForm;
		booking(Form^ f)
		{
			userForm = f;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		void show_buttton() {
			book_button->Visible = true;
		}

	public: void setpassengerNumber(int num) {
		passenger_lable->Text = "Passenger " + num.ToString();
		label8->Text = num.ToString();
	}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~booking()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ book_button;
	protected:
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ passenger_lable;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::ComboBox^ meals_comboBox;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::ComboBox^ gender_combobox;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ passport_number_textbox;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ last_name_testbox;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ middle_name_testbox;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ first_name_testbox;


	protected:

















	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(booking::typeid));
			this->book_button = (gcnew System::Windows::Forms::Button());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->passenger_lable = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->meals_comboBox = (gcnew System::Windows::Forms::ComboBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->gender_combobox = (gcnew System::Windows::Forms::ComboBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->passport_number_textbox = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->last_name_testbox = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->middle_name_testbox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->first_name_testbox = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// book_button
			// 
			this->book_button->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->book_button->BackColor = System::Drawing::Color::Navy;
			this->book_button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->book_button->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->book_button->ForeColor = System::Drawing::Color::White;
			this->book_button->Location = System::Drawing::Point(1100, 194);
			this->book_button->Name = L"book_button";
			this->book_button->Size = System::Drawing::Size(120, 42);
			this->book_button->TabIndex = 33;
			this->book_button->Text = L"Book";
			this->book_button->UseVisualStyleBackColor = false;
			this->book_button->Visible = false;
			this->book_button->Click += gcnew System::EventHandler(this, &booking::book_button_Click);
			// 
			// label8
			// 
			this->label8->BackColor = System::Drawing::Color::Transparent;
			this->label8->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->ForeColor = System::Drawing::Color::Black;
			this->label8->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"label8.Image")));
			this->label8->Location = System::Drawing::Point(22, 10);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(49, 63);
			this->label8->TabIndex = 32;
			this->label8->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// passenger_lable
			// 
			this->passenger_lable->BackColor = System::Drawing::Color::Transparent;
			this->passenger_lable->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->passenger_lable->ForeColor = System::Drawing::Color::Black;
			this->passenger_lable->Location = System::Drawing::Point(71, 26);
			this->passenger_lable->Name = L"passenger_lable";
			this->passenger_lable->Size = System::Drawing::Size(175, 30);
			this->passenger_lable->TabIndex = 31;
			this->passenger_lable->Text = L"Passenger";
			this->passenger_lable->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label7
			// 
			this->label7->BackColor = System::Drawing::Color::Transparent;
			this->label7->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::Color::Black;
			this->label7->Location = System::Drawing::Point(187, 159);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(204, 32);
			this->label7->TabIndex = 30;
			this->label7->Text = L"Meal prefernce";
			this->label7->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// meals_comboBox
			// 
			this->meals_comboBox->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::SuggestAppend;
			this->meals_comboBox->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::ListItems;
			this->meals_comboBox->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->meals_comboBox->FormattingEnabled = true;
			this->meals_comboBox->Items->AddRange(gcnew cli::array< System::Object^  >(10) {
				L"Grilled Chicken with Rice", L"Beef Steak with Potatoes",
					L"Baked Fish with Lemon Sauce", L"Vegetable Pasta", L"Chicken Alfredo Pasta", L"Seafood Mix (Shrimp & Calamari)", L"Vegan Buddha Bowl",
					L"Cheese Omelette with Bread", L"BBQ Chicken Sandwich", L"Kids Meal (Chicken Nuggets & Fries)"
			});
			this->meals_comboBox->Location = System::Drawing::Point(234, 194);
			this->meals_comboBox->Name = L"meals_comboBox";
			this->meals_comboBox->Size = System::Drawing::Size(325, 33);
			this->meals_comboBox->TabIndex = 29;
			this->meals_comboBox->Text = L"Select";
			// 
			// label6
			// 
			this->label6->BackColor = System::Drawing::Color::Transparent;
			this->label6->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::Black;
			this->label6->Location = System::Drawing::Point(33, 159);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(86, 32);
			this->label6->TabIndex = 28;
			this->label6->Text = L"Gender";
			this->label6->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// gender_combobox
			// 
			this->gender_combobox->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->gender_combobox->FormattingEnabled = true;
			this->gender_combobox->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"male", L"female" });
			this->gender_combobox->Location = System::Drawing::Point(51, 194);
			this->gender_combobox->Name = L"gender_combobox";
			this->gender_combobox->Size = System::Drawing::Size(114, 33);
			this->gender_combobox->TabIndex = 27;
			this->gender_combobox->Text = L"Select";
			// 
			// label5
			// 
			this->label5->BackColor = System::Drawing::Color::Transparent;
			this->label5->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::Black;
			this->label5->Location = System::Drawing::Point(771, 75);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(164, 32);
			this->label5->TabIndex = 26;
			this->label5->Text = L"Passport number";
			this->label5->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// passport_number_textbox
			// 
			this->passport_number_textbox->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->passport_number_textbox->ForeColor = System::Drawing::Color::Gray;
			this->passport_number_textbox->Location = System::Drawing::Point(789, 110);
			this->passport_number_textbox->Name = L"passport_number_textbox";
			this->passport_number_textbox->Size = System::Drawing::Size(248, 31);
			this->passport_number_textbox->TabIndex = 25;
			this->passport_number_textbox->Text = L"Passport number";
			this->passport_number_textbox->Enter += gcnew System::EventHandler(this, &booking::passport_number_textbox_Enter);
			this->passport_number_textbox->Leave += gcnew System::EventHandler(this, &booking::passport_number_textbox_Leave);
			// 
			// label4
			// 
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::Black;
			this->label4->Location = System::Drawing::Point(532, 74);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(141, 32);
			this->label4->TabIndex = 24;
			this->label4->Text = L"Date of birth";
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->CalendarFont = (gcnew System::Drawing::Font(L"Segoe UI", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->dateTimePicker1->CustomFormat = L"  dd / MM / yyyy";
			this->dateTimePicker1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->dateTimePicker1->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->dateTimePicker1->Location = System::Drawing::Point(559, 109);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(195, 30);
			this->dateTimePicker1->TabIndex = 23;
			// 
			// label3
			// 
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::Black;
			this->label3->Location = System::Drawing::Point(381, 73);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(86, 32);
			this->label3->TabIndex = 22;
			this->label3->Text = L"Last name";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// last_name_testbox
			// 
			this->last_name_testbox->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->last_name_testbox->ForeColor = System::Drawing::Color::Gray;
			this->last_name_testbox->Location = System::Drawing::Point(384, 108);
			this->last_name_testbox->Name = L"last_name_testbox";
			this->last_name_testbox->Size = System::Drawing::Size(137, 31);
			this->last_name_testbox->TabIndex = 21;
			this->last_name_testbox->Text = L"Last name";
			this->last_name_testbox->Enter += gcnew System::EventHandler(this, &booking::last_name_testbox_Enter);
			this->last_name_testbox->Leave += gcnew System::EventHandler(this, &booking::last_name_testbox_Leave);
			// 
			// label2
			// 
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::Black;
			this->label2->Location = System::Drawing::Point(217, 73);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(122, 32);
			this->label2->TabIndex = 20;
			this->label2->Text = L"Middle name";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// middle_name_testbox
			// 
			this->middle_name_testbox->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->middle_name_testbox->ForeColor = System::Drawing::Color::Gray;
			this->middle_name_testbox->Location = System::Drawing::Point(220, 108);
			this->middle_name_testbox->Name = L"middle_name_testbox";
			this->middle_name_testbox->Size = System::Drawing::Size(137, 31);
			this->middle_name_testbox->TabIndex = 19;
			this->middle_name_testbox->Text = L"Middle name";
			this->middle_name_testbox->Enter += gcnew System::EventHandler(this, &booking::middle_name_testbox_Enter);
			this->middle_name_testbox->Leave += gcnew System::EventHandler(this, &booking::middle_name_testbox_Leave);
			// 
			// label1
			// 
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::Black;
			this->label1->Location = System::Drawing::Point(33, 73);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(117, 32);
			this->label1->TabIndex = 18;
			this->label1->Text = L"First name";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// first_name_testbox
			// 
			this->first_name_testbox->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->first_name_testbox->ForeColor = System::Drawing::Color::Gray;
			this->first_name_testbox->Location = System::Drawing::Point(51, 108);
			this->first_name_testbox->Name = L"first_name_testbox";
			this->first_name_testbox->Size = System::Drawing::Size(137, 31);
			this->first_name_testbox->TabIndex = 17;
			this->first_name_testbox->Text = L"First name";
			this->first_name_testbox->Enter += gcnew System::EventHandler(this, &booking::first_name_testbox_Enter);
			this->first_name_testbox->Leave += gcnew System::EventHandler(this, &booking::first_name_testbox_Leave);
			// 
			// booking
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->Controls->Add(this->book_button);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->passenger_lable);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->meals_comboBox);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->gender_combobox);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->passport_number_textbox);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->dateTimePicker1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->last_name_testbox);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->middle_name_testbox);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->first_name_testbox);
			this->Name = L"booking";
			this->Size = System::Drawing::Size(1242, 246);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	private: System::Void first_name_testbox_Enter(System::Object^ sender, System::EventArgs^ e) {
		if (first_name_testbox->Text == "First name") {
			first_name_testbox->Text = "";
			first_name_testbox->ForeColor = System::Drawing::Color::Black;
		}
	}
	private: System::Void first_name_testbox_Leave(System::Object^ sender, System::EventArgs^ e) {
		if (first_name_testbox->Text == "") {
			first_name_testbox->Text = "First name";
			first_name_testbox->ForeColor = System::Drawing::Color::Gray;
		}
	}
	private: System::Void middle_name_testbox_Enter(System::Object^ sender, System::EventArgs^ e) {
		if (middle_name_testbox->Text == "Middle name") {
			middle_name_testbox->Text = "";
			middle_name_testbox->ForeColor = System::Drawing::Color::Black;
		}
	}
	private: System::Void middle_name_testbox_Leave(System::Object^ sender, System::EventArgs^ e) {
		if (middle_name_testbox->Text == "") {
			middle_name_testbox->Text = "Middle name";
			middle_name_testbox->ForeColor = System::Drawing::Color::Gray;
		}
	}
	private: System::Void last_name_testbox_Enter(System::Object^ sender, System::EventArgs^ e) {
		if (last_name_testbox->Text == "Last name") {
			last_name_testbox->Text = "";
			last_name_testbox->ForeColor = System::Drawing::Color::Black;
		}
	}
	private: System::Void last_name_testbox_Leave(System::Object^ sender, System::EventArgs^ e) {
		if (last_name_testbox->Text == "") {
			last_name_testbox->Text = "Last name";
			last_name_testbox->ForeColor = System::Drawing::Color::Gray;
		}
	}


	private: System::Void passport_number_textbox_Enter(System::Object^ sender, System::EventArgs^ e) {
		if (passport_number_textbox->Text == "Passport number") {
			passport_number_textbox->Text = "";
			passport_number_textbox->ForeColor = System::Drawing::Color::Black;
		}
	}
	private: System::Void passport_number_textbox_Leave(System::Object^ sender, System::EventArgs^ e) {
		if (passport_number_textbox->Text == "") {
			passport_number_textbox->Text = "Passport number";
			passport_number_textbox->ForeColor = System::Drawing::Color::Gray;
		}
	}
	private: System::Void book_button_Click(System::Object^ sender, System::EventArgs^ e);

};
}
