#pragma once
#include <msclr/marshal_cppstd.h>
#include <string>
#include "fav_flights.h"
#include "sign_in.h"
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace std;
using namespace msclr::interop;

extern bool flight_update;

extern int selected_flight_idx;

namespace skyPort {

	/// <summary>
	/// Summary for flight_result
	/// </summary>
	
	public delegate void FlightActionHandler(int idx);
	//ref class user_home_page;

	public ref class flight_result : public System::Windows::Forms::UserControl
	{
	public:
		event FlightActionHandler^ OnEditButtonClicked;
		Form^ userForm;

		flight_result(bool is_admin, Form^ f)
		{
			userForm = f;
			InitializeComponent();
			if (is_admin) {
				admin_search_flights_panel->Visible = true;
				user_search_flights_panel->Visible = false;

			}
			else {
				admin_search_flights_panel->Visible = false;
				user_search_flights_panel->Visible = true;
			}
			//
			//TODO: Add the constructor code here
			//
		}
		void hide_book_button() {
			book_button->Visible = false;
		}
		void SetFlightData(String^ model, String^ index,
			String^ d_iata, String^ d_airport, String^ d_time, String^ d_date,
			String^ a_iata, String^ a_airport, String^ a_time, String^ a_date, String^ state, String^ price) {

			this->plane_model->Text = model;
			this->index->Text = index;
			this->d_iata->Text = d_iata;
			this->d_airport->Text = d_airport;
			this->d_time->Text = d_time;
			this->d_date->Text = d_date;
			this->a_iata->Text = a_iata;
			this->a_airport->Text = a_airport;
			this->a_time->Text = a_time;
			this->a_date->Text = a_date;
			this->State_label->Text=state;
			this->price->Text = price + " $";
		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~flight_result()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ d_iata;
	private: System::Windows::Forms::Label^ a_iata;
	protected:

	protected:

	private: System::Windows::Forms::Label^ a_time;

	private: System::Windows::Forms::Label^ d_time;

	private: System::Windows::Forms::Label^ plane_model;
	private: System::Windows::Forms::Label^ a_airport;


	private: System::Windows::Forms::Label^ d_airport;
	private: System::Windows::Forms::Label^ a_date;


	private: System::Windows::Forms::Label^ d_date;

	private: System::Windows::Forms::Label^ arrival_date;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ book_button;




	private: System::Windows::Forms::Label^ index;
	private: System::Windows::Forms::Label^ price;
	private: System::Windows::Forms::Panel^ admin_search_flights_panel;
	private: System::Windows::Forms::Panel^ user_search_flights_panel;


	private: System::Windows::Forms::PictureBox^ trash;
	private: System::Windows::Forms::PictureBox^ edit;
	public: System::Windows::Forms::PictureBox^ add_to_fav;
	public: System::Windows::Forms::PictureBox^ remove_from_fav;
	private: System::Windows::Forms::Label^ State_label;
	public:

	public:

	public:

	private:

	public:


	private:
















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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(flight_result::typeid));
			this->d_iata = (gcnew System::Windows::Forms::Label());
			this->a_iata = (gcnew System::Windows::Forms::Label());
			this->a_time = (gcnew System::Windows::Forms::Label());
			this->d_time = (gcnew System::Windows::Forms::Label());
			this->plane_model = (gcnew System::Windows::Forms::Label());
			this->a_airport = (gcnew System::Windows::Forms::Label());
			this->d_airport = (gcnew System::Windows::Forms::Label());
			this->a_date = (gcnew System::Windows::Forms::Label());
			this->d_date = (gcnew System::Windows::Forms::Label());
			this->arrival_date = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->book_button = (gcnew System::Windows::Forms::Button());
			this->index = (gcnew System::Windows::Forms::Label());
			this->price = (gcnew System::Windows::Forms::Label());
			this->admin_search_flights_panel = (gcnew System::Windows::Forms::Panel());
			this->trash = (gcnew System::Windows::Forms::PictureBox());
			this->edit = (gcnew System::Windows::Forms::PictureBox());
			this->user_search_flights_panel = (gcnew System::Windows::Forms::Panel());
			this->add_to_fav = (gcnew System::Windows::Forms::PictureBox());
			this->remove_from_fav = (gcnew System::Windows::Forms::PictureBox());
			this->State_label = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->admin_search_flights_panel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trash))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->edit))->BeginInit();
			this->user_search_flights_panel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->add_to_fav))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->remove_from_fav))->BeginInit();
			this->SuspendLayout();
			// 
			// d_iata
			// 
			this->d_iata->AutoSize = true;
			this->d_iata->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->d_iata->Location = System::Drawing::Point(20, 82);
			this->d_iata->Name = L"d_iata";
			this->d_iata->Size = System::Drawing::Size(257, 38);
			this->d_iata->TabIndex = 0;
			this->d_iata->Text = L"Departure IATA";
			// 
			// a_iata
			// 
			this->a_iata->AutoSize = true;
			this->a_iata->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->a_iata->Location = System::Drawing::Point(902, 85);
			this->a_iata->Name = L"a_iata";
			this->a_iata->Size = System::Drawing::Size(203, 38);
			this->a_iata->TabIndex = 1;
			this->a_iata->Text = L"Arrival IATA";
			// 
			// a_time
			// 
			this->a_time->AutoSize = true;
			this->a_time->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->a_time->Location = System::Drawing::Point(902, 158);
			this->a_time->Name = L"a_time";
			this->a_time->Size = System::Drawing::Size(154, 29);
			this->a_time->TabIndex = 3;
			this->a_time->Text = L"Arrival Time";
			// 
			// d_time
			// 
			this->d_time->AutoSize = true;
			this->d_time->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->d_time->Location = System::Drawing::Point(22, 156);
			this->d_time->Name = L"d_time";
			this->d_time->Size = System::Drawing::Size(196, 29);
			this->d_time->TabIndex = 2;
			this->d_time->Text = L"Departure Time";
			// 
			// plane_model
			// 
			this->plane_model->AutoSize = true;
			this->plane_model->Font = (gcnew System::Drawing::Font(L"Segoe UI", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->plane_model->Location = System::Drawing::Point(20, 17);
			this->plane_model->Name = L"plane_model";
			this->plane_model->Size = System::Drawing::Size(183, 41);
			this->plane_model->TabIndex = 4;
			this->plane_model->Text = L"Plane model";
			// 
			// a_airport
			// 
			this->a_airport->AutoSize = true;
			this->a_airport->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->a_airport->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->a_airport->Location = System::Drawing::Point(902, 124);
			this->a_airport->Name = L"a_airport";
			this->a_airport->Size = System::Drawing::Size(129, 25);
			this->a_airport->TabIndex = 6;
			this->a_airport->Text = L"Arrival Airport";
			// 
			// d_airport
			// 
			this->d_airport->AutoSize = true;
			this->d_airport->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->d_airport->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->d_airport->Location = System::Drawing::Point(22, 122);
			this->d_airport->Name = L"d_airport";
			this->d_airport->Size = System::Drawing::Size(160, 25);
			this->d_airport->TabIndex = 5;
			this->d_airport->Text = L"Departure Airport";
			// 
			// a_date
			// 
			this->a_date->AutoSize = true;
			this->a_date->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->a_date->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->a_date->Location = System::Drawing::Point(902, 195);
			this->a_date->Name = L"a_date";
			this->a_date->Size = System::Drawing::Size(113, 25);
			this->a_date->TabIndex = 8;
			this->a_date->Text = L"Arrival Date";
			// 
			// d_date
			// 
			this->d_date->AutoSize = true;
			this->d_date->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->d_date->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->d_date->Location = System::Drawing::Point(22, 193);
			this->d_date->Name = L"d_date";
			this->d_date->Size = System::Drawing::Size(144, 25);
			this->d_date->TabIndex = 7;
			this->d_date->Text = L"Departure Date";
			// 
			// arrival_date
			// 
			this->arrival_date->AutoSize = true;
			this->arrival_date->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->arrival_date->Location = System::Drawing::Point(646, 93);
			this->arrival_date->Name = L"arrival_date";
			this->arrival_date->Size = System::Drawing::Size(176, 16);
			this->arrival_date->TabIndex = 9;
			this->arrival_date->Text = L"________                   ________";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(722, 82);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(56, 52);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 10;
			this->pictureBox1->TabStop = false;
			// 
			// book_button
			// 
			this->book_button->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(7)), static_cast<System::Int32>(static_cast<System::Byte>(85)),
				static_cast<System::Int32>(static_cast<System::Byte>(184)));
			this->book_button->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->book_button->Cursor = System::Windows::Forms::Cursors::Default;
			this->book_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->book_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->book_button->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->book_button->Location = System::Drawing::Point(47, 133);
			this->book_button->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->book_button->Name = L"book_button";
			this->book_button->Size = System::Drawing::Size(145, 38);
			this->book_button->TabIndex = 12;
			this->book_button->Text = L"Book";
			this->book_button->UseVisualStyleBackColor = false;
			this->book_button->Click += gcnew System::EventHandler(this, &flight_result::book_Click);
			// 
			// index
			// 
			this->index->AutoSize = true;
			this->index->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->index->Location = System::Drawing::Point(902, 46);
			this->index->Name = L"index";
			this->index->Size = System::Drawing::Size(76, 29);
			this->index->TabIndex = 15;
			this->index->Text = L"index";
			this->index->Visible = false;
			// 
			// price
			// 
			this->price->AutoSize = true;
			this->price->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 28.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->price->Location = System::Drawing::Point(92, 22);
			this->price->Name = L"price";
			this->price->Size = System::Drawing::Size(135, 54);
			this->price->TabIndex = 16;
			this->price->Text = L"Price";
			// 
			// admin_search_flights_panel
			// 
			this->admin_search_flights_panel->BackColor = System::Drawing::Color::Transparent;
			this->admin_search_flights_panel->Controls->Add(this->trash);
			this->admin_search_flights_panel->Controls->Add(this->edit);
			this->admin_search_flights_panel->Location = System::Drawing::Point(1423, 24);
			this->admin_search_flights_panel->Name = L"admin_search_flights_panel";
			this->admin_search_flights_panel->Size = System::Drawing::Size(135, 196);
			this->admin_search_flights_panel->TabIndex = 17;
			// 
			// trash
			// 
			this->trash->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(76)),
				static_cast<System::Int32>(static_cast<System::Byte>(60)));
			this->trash->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"trash.Image")));
			this->trash->Location = System::Drawing::Point(53, 130);
			this->trash->Name = L"trash";
			this->trash->Size = System::Drawing::Size(54, 51);
			this->trash->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->trash->TabIndex = 10;
			this->trash->TabStop = false;
			this->trash->Click += gcnew System::EventHandler(this, &flight_result::trash_Click);
			// 
			// edit
			// 
			this->edit->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(46)), static_cast<System::Int32>(static_cast<System::Byte>(204)),
				static_cast<System::Int32>(static_cast<System::Byte>(113)));
			this->edit->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"edit.Image")));
			this->edit->Location = System::Drawing::Point(53, 44);
			this->edit->Name = L"edit";
			this->edit->Size = System::Drawing::Size(54, 51);
			this->edit->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->edit->TabIndex = 9;
			this->edit->TabStop = false;
			this->edit->Click += gcnew System::EventHandler(this, &flight_result::edit_Click);
			// 
			// user_search_flights_panel
			// 
			this->user_search_flights_panel->Controls->Add(this->add_to_fav);
			this->user_search_flights_panel->Controls->Add(this->price);
			this->user_search_flights_panel->Controls->Add(this->book_button);
			this->user_search_flights_panel->Controls->Add(this->remove_from_fav);
			this->user_search_flights_panel->Location = System::Drawing::Point(1287, 24);
			this->user_search_flights_panel->Name = L"user_search_flights_panel";
			this->user_search_flights_panel->Size = System::Drawing::Size(272, 196);
			this->user_search_flights_panel->TabIndex = 17;
			// 
			// add_to_fav
			// 
			this->add_to_fav->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"add_to_fav.Image")));
			this->add_to_fav->Location = System::Drawing::Point(197, 134);
			this->add_to_fav->Name = L"add_to_fav";
			this->add_to_fav->Size = System::Drawing::Size(43, 35);
			this->add_to_fav->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->add_to_fav->TabIndex = 17;
			this->add_to_fav->TabStop = false;
			this->add_to_fav->Click += gcnew System::EventHandler(this, &flight_result::add_to_favorite_Click);
			// 
			// remove_from_fav
			// 
			this->remove_from_fav->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"remove_from_fav.Image")));
			this->remove_from_fav->Location = System::Drawing::Point(197, 134);
			this->remove_from_fav->Name = L"remove_from_fav";
			this->remove_from_fav->Size = System::Drawing::Size(43, 35);
			this->remove_from_fav->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->remove_from_fav->TabIndex = 18;
			this->remove_from_fav->TabStop = false;
			this->remove_from_fav->Click += gcnew System::EventHandler(this, &flight_result::remove_from_favorite_Click);
			// 
			// State_label
			// 
			this->State_label->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->State_label->ForeColor = System::Drawing::Color::Black;
			this->State_label->Location = System::Drawing::Point(1083, 24);
			this->State_label->Name = L"State_label";
			this->State_label->Size = System::Drawing::Size(198, 37);
			this->State_label->TabIndex = 19;
			this->State_label->Text = L"State";
			this->State_label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// flight_result
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::AliceBlue;
			this->Controls->Add(this->State_label);
			this->Controls->Add(this->user_search_flights_panel);
			this->Controls->Add(this->admin_search_flights_panel);
			this->Controls->Add(this->index);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->arrival_date);
			this->Controls->Add(this->a_date);
			this->Controls->Add(this->d_date);
			this->Controls->Add(this->a_airport);
			this->Controls->Add(this->d_airport);
			this->Controls->Add(this->plane_model);
			this->Controls->Add(this->a_time);
			this->Controls->Add(this->d_time);
			this->Controls->Add(this->a_iata);
			this->Controls->Add(this->d_iata);
			this->Name = L"flight_result";
			this->Size = System::Drawing::Size(1570, 235);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->admin_search_flights_panel->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trash))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->edit))->EndInit();
			this->user_search_flights_panel->ResumeLayout(false);
			this->user_search_flights_panel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->add_to_fav))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->remove_from_fav))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		
	private: System::Void add_to_favorite_Click(System::Object^ sender, System::EventArgs^ e) {
		if (current_user_name == "null") {
			MessageBox::Show("Please sign in to add to favorites.", "Sign In Required", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}
		this->add_to_fav->Visible = false;
		this->remove_from_fav->Visible = true;
		int idx = stoi(marshal_as<string>(this->index->Text));
		saveToFavorite(current_user_name, idx);
	}
	private: System::Void remove_from_favorite_Click(System::Object^ sender, System::EventArgs^ e) {
		this->add_to_fav->Visible = true;
		this->remove_from_fav->Visible = false;
		int idx = stoi(marshal_as<string>(this->index->Text));
		deleteFromFavorite(current_user_name, idx);
	}
	
	private: System::Void edit_Click(System::Object^ sender, System::EventArgs^ e) {
		int idx = stoi(marshal_as<string>(this->index->Text));

		OnEditButtonClicked(idx);
	}
		
	private: System::Void book_Click(System::Object^ sender, System::EventArgs^ e);
	
	private: System::Void trash_Click(System::Object^ sender, System::EventArgs^ e) {
		int idx = stoi(marshal_as<string>(index->Text));
		flights[idx].state = "Canceled";
		MessageBox::Show("Flight Canceled Successfully.", "Done", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
};
}
