#pragma once

#include "view_user_tickets.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace skyPort {

	/// <summary>
	/// Summary for view_booked
	/// </summary>
	public ref class view_booked : public System::Windows::Forms::UserControl
	{
	public:
		Form^ userForm;
		view_booked(Form^ f)
		{
			userForm = f;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		void viewbooked(String^ fname, String^ mname,
			String^ lname, String^ date, String^ passport, String^ gender,
			String^ seat, String^ from_to, String^ time, String^ category, String^ meal, String^ flight_num, String^ price, String^ ticket_idx, String^ traveler_idx, String^ flight_idx) {

			this->fname_label->Text = fname + " " + mname + " " + lname;
			this->date_view_label->Text = date;
			this->passport_label->Text = passport;
			this->gender_label->Text = gender;
			this->seat_number->Text = seat;
			this->from_to_label->Text = from_to;
			this->departure_date->Text = time;
			this->meal_view_label->Text = meal;
			this->price_view_label->Text = price + " $";
			this->flight_num_label->Text = flight_num;
			this->category_view_label->Text = category;
			this->ticket_idx->Text = ticket_idx;
			this->traveler_idx->Text = traveler_idx;
			this->flight_idx->Text = flight_idx;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~view_booked()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ category_view_label;
	protected:
	private: System::Windows::Forms::Label^ category_label;
	private: System::Windows::Forms::Label^ price_view_label;
	private: System::Windows::Forms::Label^ departure_date;

	private: System::Windows::Forms::Label^ time_label;
	private: System::Windows::Forms::Label^ seat_number;

	private: System::Windows::Forms::Label^ from_to_label;
	private: System::Windows::Forms::Label^ seat_num_label;
	private: System::Windows::Forms::Label^ meal_view_label;
	private: System::Windows::Forms::Label^ gender_label;
	private: System::Windows::Forms::Label^ passport_label;
	private: System::Windows::Forms::Label^ date_view_label;
	private: System::Windows::Forms::Label^ fname_label;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ flight_num_label;
	private: System::Windows::Forms::Label^ flight_num;
	public: System::Windows::Forms::Button^ cancel_button;
	private: System::Windows::Forms::Label^ ticket_idx;
	private: System::Windows::Forms::Label^ traveler_idx;
	private: System::Windows::Forms::Label^ flight_idx;


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
			this->category_view_label = (gcnew System::Windows::Forms::Label());
			this->category_label = (gcnew System::Windows::Forms::Label());
			this->price_view_label = (gcnew System::Windows::Forms::Label());
			this->departure_date = (gcnew System::Windows::Forms::Label());
			this->time_label = (gcnew System::Windows::Forms::Label());
			this->seat_number = (gcnew System::Windows::Forms::Label());
			this->from_to_label = (gcnew System::Windows::Forms::Label());
			this->seat_num_label = (gcnew System::Windows::Forms::Label());
			this->meal_view_label = (gcnew System::Windows::Forms::Label());
			this->gender_label = (gcnew System::Windows::Forms::Label());
			this->passport_label = (gcnew System::Windows::Forms::Label());
			this->date_view_label = (gcnew System::Windows::Forms::Label());
			this->fname_label = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->flight_num_label = (gcnew System::Windows::Forms::Label());
			this->flight_num = (gcnew System::Windows::Forms::Label());
			this->cancel_button = (gcnew System::Windows::Forms::Button());
			this->ticket_idx = (gcnew System::Windows::Forms::Label());
			this->traveler_idx = (gcnew System::Windows::Forms::Label());
			this->flight_idx = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// category_view_label
			// 
			this->category_view_label->AutoSize = true;
			this->category_view_label->BackColor = System::Drawing::Color::Transparent;
			this->category_view_label->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.8F));
			this->category_view_label->Location = System::Drawing::Point(1004, 118);
			this->category_view_label->Name = L"category_view_label";
			this->category_view_label->Size = System::Drawing::Size(48, 25);
			this->category_view_label->TabIndex = 51;
			this->category_view_label->Text = L"a,b,c";
			// 
			// category_label
			// 
			this->category_label->AutoSize = true;
			this->category_label->BackColor = System::Drawing::Color::Transparent;
			this->category_label->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->category_label->ForeColor = System::Drawing::Color::Black;
			this->category_label->Location = System::Drawing::Point(1004, 75);
			this->category_label->Name = L"category_label";
			this->category_label->Size = System::Drawing::Size(73, 20);
			this->category_label->TabIndex = 50;
			this->category_label->Text = L"Category";
			this->category_label->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// price_view_label
			// 
			this->price_view_label->AutoSize = true;
			this->price_view_label->BackColor = System::Drawing::Color::Transparent;
			this->price_view_label->Font = (gcnew System::Drawing::Font(L"Segoe UI", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->price_view_label->Location = System::Drawing::Point(1282, 104);
			this->price_view_label->Name = L"price_view_label";
			this->price_view_label->Size = System::Drawing::Size(116, 54);
			this->price_view_label->TabIndex = 49;
			this->price_view_label->Text = L"price";
			// 
			// departure_date
			// 
			this->departure_date->AutoSize = true;
			this->departure_date->BackColor = System::Drawing::Color::Transparent;
			this->departure_date->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.8F));
			this->departure_date->Location = System::Drawing::Point(968, 196);
			this->departure_date->Name = L"departure_date";
			this->departure_date->Size = System::Drawing::Size(93, 25);
			this->departure_date->TabIndex = 48;
			this->departure_date->Text = L"flight date";
			// 
			// time_label
			// 
			this->time_label->AutoSize = true;
			this->time_label->BackColor = System::Drawing::Color::Transparent;
			this->time_label->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->time_label->ForeColor = System::Drawing::Color::Black;
			this->time_label->Location = System::Drawing::Point(968, 161);
			this->time_label->Name = L"time_label";
			this->time_label->Size = System::Drawing::Size(115, 20);
			this->time_label->TabIndex = 47;
			this->time_label->Text = L"Departure date";
			this->time_label->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// seat_number
			// 
			this->seat_number->AutoSize = true;
			this->seat_number->BackColor = System::Drawing::Color::Transparent;
			this->seat_number->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.8F));
			this->seat_number->Location = System::Drawing::Point(228, 196);
			this->seat_number->Name = L"seat_number";
			this->seat_number->Size = System::Drawing::Size(85, 25);
			this->seat_number->TabIndex = 46;
			this->seat_number->Text = L"seat num";
			// 
			// from_to_label
			// 
			this->from_to_label->AutoSize = true;
			this->from_to_label->BackColor = System::Drawing::Color::Transparent;
			this->from_to_label->Font = (gcnew System::Drawing::Font(L"Segoe UI", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->from_to_label->Location = System::Drawing::Point(99, 26);
			this->from_to_label->Name = L"from_to_label";
			this->from_to_label->Size = System::Drawing::Size(166, 41);
			this->from_to_label->TabIndex = 45;
			this->from_to_label->Text = L"from -> to";
			// 
			// seat_num_label
			// 
			this->seat_num_label->AutoSize = true;
			this->seat_num_label->BackColor = System::Drawing::Color::Transparent;
			this->seat_num_label->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->seat_num_label->ForeColor = System::Drawing::Color::Black;
			this->seat_num_label->Location = System::Drawing::Point(228, 161);
			this->seat_num_label->Name = L"seat_num_label";
			this->seat_num_label->Size = System::Drawing::Size(75, 20);
			this->seat_num_label->TabIndex = 44;
			this->seat_num_label->Text = L"Seat num";
			this->seat_num_label->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// meal_view_label
			// 
			this->meal_view_label->AutoSize = true;
			this->meal_view_label->BackColor = System::Drawing::Color::Transparent;
			this->meal_view_label->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.8F));
			this->meal_view_label->Location = System::Drawing::Point(627, 196);
			this->meal_view_label->Name = L"meal_view_label";
			this->meal_view_label->Size = System::Drawing::Size(50, 25);
			this->meal_view_label->TabIndex = 43;
			this->meal_view_label->Text = L"meal";
			// 
			// gender_label
			// 
			this->gender_label->AutoSize = true;
			this->gender_label->BackColor = System::Drawing::Color::Transparent;
			this->gender_label->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.8F));
			this->gender_label->Location = System::Drawing::Point(101, 196);
			this->gender_label->Name = L"gender_label";
			this->gender_label->Size = System::Drawing::Size(68, 25);
			this->gender_label->TabIndex = 42;
			this->gender_label->Text = L"gender";
			// 
			// passport_label
			// 
			this->passport_label->AutoSize = true;
			this->passport_label->BackColor = System::Drawing::Color::Transparent;
			this->passport_label->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.8F));
			this->passport_label->Location = System::Drawing::Point(722, 118);
			this->passport_label->Name = L"passport_label";
			this->passport_label->Size = System::Drawing::Size(89, 25);
			this->passport_label->TabIndex = 41;
			this->passport_label->Text = L"pass num";
			// 
			// date_view_label
			// 
			this->date_view_label->AutoSize = true;
			this->date_view_label->BackColor = System::Drawing::Color::Transparent;
			this->date_view_label->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.8F));
			this->date_view_label->Location = System::Drawing::Point(517, 118);
			this->date_view_label->Name = L"date_view_label";
			this->date_view_label->Size = System::Drawing::Size(47, 25);
			this->date_view_label->TabIndex = 40;
			this->date_view_label->Text = L"date";
			// 
			// fname_label
			// 
			this->fname_label->AutoSize = true;
			this->fname_label->BackColor = System::Drawing::Color::Transparent;
			this->fname_label->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.8F));
			this->fname_label->Location = System::Drawing::Point(101, 118);
			this->fname_label->Name = L"fname_label";
			this->fname_label->Size = System::Drawing::Size(81, 25);
			this->fname_label->TabIndex = 39;
			this->fname_label->Text = L"fst name";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::Color::Transparent;
			this->label7->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::Color::Black;
			this->label7->Location = System::Drawing::Point(627, 161);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(114, 20);
			this->label7->TabIndex = 38;
			this->label7->Text = L"Meal prefernce";
			this->label7->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::Transparent;
			this->label6->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::Black;
			this->label6->Location = System::Drawing::Point(101, 161);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(60, 20);
			this->label6->TabIndex = 37;
			this->label6->Text = L"Gender";
			this->label6->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::Transparent;
			this->label5->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::Black;
			this->label5->Location = System::Drawing::Point(722, 75);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(129, 20);
			this->label5->TabIndex = 36;
			this->label5->Text = L"Passport number";
			this->label5->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::Black;
			this->label4->Location = System::Drawing::Point(517, 75);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(99, 20);
			this->label4->TabIndex = 35;
			this->label4->Text = L"Date of birth";
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::Black;
			this->label1->Location = System::Drawing::Point(101, 75);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(51, 20);
			this->label1->TabIndex = 34;
			this->label1->Text = L"Name";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// flight_num_label
			// 
			this->flight_num_label->AutoSize = true;
			this->flight_num_label->BackColor = System::Drawing::Color::Transparent;
			this->flight_num_label->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.8F));
			this->flight_num_label->Location = System::Drawing::Point(372, 196);
			this->flight_num_label->Name = L"flight_num_label";
			this->flight_num_label->Size = System::Drawing::Size(94, 25);
			this->flight_num_label->TabIndex = 53;
			this->flight_num_label->Text = L"flight num";
			// 
			// flight_num
			// 
			this->flight_num->AutoSize = true;
			this->flight_num->BackColor = System::Drawing::Color::Transparent;
			this->flight_num->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->flight_num->ForeColor = System::Drawing::Color::Black;
			this->flight_num->Location = System::Drawing::Point(372, 161);
			this->flight_num->Name = L"flight_num";
			this->flight_num->Size = System::Drawing::Size(108, 20);
			this->flight_num->TabIndex = 52;
			this->flight_num->Text = L"Flight number";
			this->flight_num->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// cancel_button
			// 
			this->cancel_button->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(7)), static_cast<System::Int32>(static_cast<System::Byte>(85)),
				static_cast<System::Int32>(static_cast<System::Byte>(184)));
			this->cancel_button->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->cancel_button->Cursor = System::Windows::Forms::Cursors::Default;
			this->cancel_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->cancel_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cancel_button->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->cancel_button->Location = System::Drawing::Point(1262, 190);
			this->cancel_button->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->cancel_button->Name = L"cancel_button";
			this->cancel_button->Size = System::Drawing::Size(175, 41);
			this->cancel_button->TabIndex = 54;
			this->cancel_button->Text = L"Cancel ticket";
			this->cancel_button->UseVisualStyleBackColor = false;
			this->cancel_button->Click += gcnew System::EventHandler(this, &view_booked::cancel_button_Click);
			// 
			// ticket_idx
			// 
			this->ticket_idx->AutoSize = true;
			this->ticket_idx->Location = System::Drawing::Point(1126, 37);
			this->ticket_idx->Name = L"ticket_idx";
			this->ticket_idx->Size = System::Drawing::Size(62, 16);
			this->ticket_idx->TabIndex = 55;
			this->ticket_idx->Text = L"ticket_idx";
			this->ticket_idx->Visible = false;
			// 
			// traveler_idx
			// 
			this->traveler_idx->AutoSize = true;
			this->traveler_idx->Location = System::Drawing::Point(1211, 37);
			this->traveler_idx->Name = L"traveler_idx";
			this->traveler_idx->Size = System::Drawing::Size(76, 16);
			this->traveler_idx->TabIndex = 56;
			this->traveler_idx->Text = L"traveler_idx";
			this->traveler_idx->Visible = false;
			// 
			// flight_idx
			// 
			this->flight_idx->AutoSize = true;
			this->flight_idx->Location = System::Drawing::Point(1144, 75);
			this->flight_idx->Name = L"flight_idx";
			this->flight_idx->Size = System::Drawing::Size(58, 16);
			this->flight_idx->TabIndex = 57;
			this->flight_idx->Text = L"flight_idx";
			this->flight_idx->Visible = false;
			// 
			// view_booked
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->flight_idx);
			this->Controls->Add(this->traveler_idx);
			this->Controls->Add(this->ticket_idx);
			this->Controls->Add(this->cancel_button);
			this->Controls->Add(this->flight_num_label);
			this->Controls->Add(this->flight_num);
			this->Controls->Add(this->category_view_label);
			this->Controls->Add(this->category_label);
			this->Controls->Add(this->price_view_label);
			this->Controls->Add(this->departure_date);
			this->Controls->Add(this->time_label);
			this->Controls->Add(this->seat_number);
			this->Controls->Add(this->from_to_label);
			this->Controls->Add(this->seat_num_label);
			this->Controls->Add(this->meal_view_label);
			this->Controls->Add(this->gender_label);
			this->Controls->Add(this->passport_label);
			this->Controls->Add(this->date_view_label);
			this->Controls->Add(this->fname_label);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label1);
			this->Name = L"view_booked";
			this->Size = System::Drawing::Size(1500, 246);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void cancel_button_Click(System::Object^ sender, System::EventArgs^ e);
};
}
