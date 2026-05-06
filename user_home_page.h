#pragma once
#include <msclr/marshal_cppstd.h>
#include "sign_in.h"
#include "add_flights.h"
#include "sign_up_users_form.h"
#include "admin_home_page.h"
#include "chatBot.h"
#include "flight_result.h"
#include "view_user_tickets.h"
#include "view_booked.h"
#include "sort_functions.h"
#include "booking.h"
using namespace msclr::interop;

extern string current_sort_criteria;
namespace skyPort {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	
	/// <summary>
	/// Summary for user_home_page
	/// </summary>
	public ref class user_home_page : public System::Windows::Forms::Form
	{
	public:
		user_home_page(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
	private: System::Windows::Forms::Button^ customer_service;
	private: System::Windows::Forms::Panel^ chat_panel;
	private: System::Windows::Forms::Button^ send_button;
	private: System::Windows::Forms::FlowLayoutPanel^ chatbox;
	private: System::Windows::Forms::TextBox^ txtMessage;


	private: System::Windows::Forms::Panel^ panel_booked;
	public:
	private: System::Windows::Forms::PictureBox^ booked_icon_ticket;
	private: System::Windows::Forms::Label^ hook_booked_label;
	private: System::Windows::Forms::FlowLayoutPanel^ booked_layout;


	public: System::Windows::Forms::FlowLayoutPanel^ data_booking_panal;
	private: System::Windows::Forms::RadioButton^ sort_by_faster;
	public:
	private: System::Windows::Forms::RadioButton^ sort_by_cheaper;
	private: System::Windows::Forms::Timer^ timer1;
	public: System::Windows::Forms::Panel^ check_out_panal;
	public: System::Windows::Forms::Label^ label1;
	public: System::Windows::Forms::Label^ cnt_adult;
	public: System::Windows::Forms::Label^ cnt_infant;


	public: System::Windows::Forms::Label^ cnt_child;
	public: System::Windows::Forms::Label^ total_price;


	public: System::Windows::Forms::Label^ Total;


	public: System::Windows::Forms::Label^ price_infant;
	public: System::Windows::Forms::Label^ price_child;
	public: System::Windows::Forms::Label^ price_adult;

	public: System::Windows::Forms::Button^ get_discount_button;





	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Panel^ mst_panel;
	private: System::Windows::Forms::Button^ mst2;
	private: System::Windows::Forms::Button^ mst4;
	private: System::Windows::Forms::Button^ mst5;
	private: System::Windows::Forms::Button^ mst1;
	private: System::Windows::Forms::Label^ mst_gft;
	private: System::Windows::Forms::Button^ mst_start;
	private: System::Windows::Forms::Button^ mst3;
	private: System::Windows::Forms::Button^ mst6;
	private: System::Windows::Forms::Label^ mst_hook;
	private: System::Windows::Forms::Timer^ mst_timer;

	public:







	public:

	public:

	public:

		flight_result^ flight_card;
		void view_flight_search_result(int i)
		{
			flight_card = gcnew flight_result(false, this);
			int price = 0;
			if (category->SelectedItem->ToString() == "Economy") price = flights[i].price.economy_price;
			else if (category->SelectedItem->ToString() == "Premium Economy") price = flights[i].price.premium_economy_price;
			else if (category->SelectedItem->ToString() == "Business") price = flights[i].price.business_price;
			else if (category->SelectedItem->ToString() == "First Class") price = flights[i].price.first_class_price;
			flight_card->SetFlightData(
				marshal_as<String^>(flights[i].plane_model),
				marshal_as<String^>(to_string(i)),
				marshal_as<String^>(flights[i].d_iata),
				marshal_as<String^>(flights[i].departure_airport),
				marshal_as<String^>(flights[i].time_departure),
				marshal_as<String^>(flights[i].departure_date),
				marshal_as<String^>(flights[i].a_iata),
				marshal_as<String^>(flights[i].arrival_airport),
				marshal_as<String^>(flights[i].time_arrival),
				marshal_as<String^>(flights[i].arrival_date),
				marshal_as<String^>(flights[i].state),
				marshal_as<String^>(to_string(price)));
			if(flights[i].state!="open to book")
				flight_card->hide_book_button();
		}

		void view_user_booked(int i)
		{

			for (int j = 0; j < tickets[i].travelers.size(); j++) {

				string gender;

				if (tickets[i].travelers[j].male) 
					gender = "male";
				else gender = "female";

				int flight_index = tickets[i].flight_index;

				view_booked^ card = gcnew view_booked(this);

				card->viewbooked(
					marshal_as<String^>(tickets[i].travelers[j].first_name),
					marshal_as<String^>(tickets[i].travelers[j].middle_name),
					marshal_as<String^>(tickets[i].travelers[j].last_name),
					marshal_as<String^>(tickets[i].travelers[j].date_of_birth),
					marshal_as<String^>(tickets[i].travelers[j].passport_number),
					marshal_as<String^>(gender),
					marshal_as<String^>(tickets[i].travelers[j].number_seats),
					marshal_as<String^>(flights[flight_index].d_iata + "->" + (flights[flight_index].a_iata)),
					marshal_as<String^>(flights[flight_index].departure_date + " " + (flights[flight_index].time_departure)),
					marshal_as<String^>(tickets[i].category),
					marshal_as<String^>(tickets[i].travelers[j].meal_preference),
					marshal_as<String^>(flights[flight_index].number_flight),
					marshal_as<String^>(to_string(tickets[i].travelers[j].price)),
					i.ToString(),j.ToString(), flight_index.ToString());

				booked_layout->Controls->Add(card);
				if (flights[flight_index].state != "open to book") {
					card->cancel_button->Visible = false;
				}
			}
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~user_home_page()
		{
			if (components)
			{
				delete components;
			}
		}
		property virtual System::Windows::Forms::CreateParams^ CreateParams {
			System::Windows::Forms::CreateParams^ get() override {
				System::Windows::Forms::CreateParams^ cp = __super::CreateParams;
				cp->ExStyle |= 0x02000000;  // WS_EX_COMPOSITED
				return cp;
			}
		}
		
	private: System::Windows::Forms::Panel^ home_user_panal;
	protected:
	private: System::Windows::Forms::Button^ sign_in_button;
	private: System::Windows::Forms::Button^ Exit_button;
	private: System::Windows::Forms::Button^ favourite_flights_button;
	private: System::Windows::Forms::Button^ Booked_tickets_button;
	private: System::Windows::Forms::Button^ Flights_button;
	private: System::Windows::Forms::Label^ skyport_title;
	private: System::Windows::Forms::Label^ welcome_user;
	public: System::Windows::Forms::Panel^ search_flights_panel;
	private: System::Windows::Forms::Panel^ travler_panel;
	private: System::Windows::Forms::TextBox^ infants_cnt;
	private: System::Windows::Forms::Button^ infants_inc;
	private: System::Windows::Forms::Button^ infants_dec;
	private: System::Windows::Forms::Label^ infants_age;
	private: System::Windows::Forms::Label^ infants;
	private: System::Windows::Forms::TextBox^ children_cnt;
	private: System::Windows::Forms::Button^ children_inc;
	private: System::Windows::Forms::Button^ childeren_dec;
	private: System::Windows::Forms::Label^ children_age;
	private: System::Windows::Forms::Label^ children;
	private: System::Windows::Forms::TextBox^ adult_cnt;
	private: System::Windows::Forms::Button^ adult_inc;
	private: System::Windows::Forms::Button^ adult_decrease;
	private: System::Windows::Forms::Label^ adult_age;
	private: System::Windows::Forms::Label^ adult;
	private: System::Windows::Forms::Button^ drop_down;
	private: System::Windows::Forms::Label^ traveler_label;
	private: System::Windows::Forms::PictureBox^ transfer_pictureBox;
	private: System::Windows::Forms::Label^ no_results;
	public: System::Windows::Forms::ComboBox^ category;
	private: System::Windows::Forms::Button^ search;
	private: System::Windows::Forms::DateTimePicker^ departure_date;
	private: System::Windows::Forms::FlowLayoutPanel^ flight_layout_panel;

	private: System::Windows::Forms::Label^ dep_city_label;
	private: System::Windows::Forms::Label^ dep_date_label;
	private: System::Windows::Forms::Label^ arrival_city_label;
	private: System::Windows::Forms::TextBox^ d_airport;
	private: System::Windows::Forms::TextBox^ a_airport;
	private: System::Windows::Forms::Button^ log_out;
	public: System::Windows::Forms::Panel^ fav_view_panel;
	private: System::Windows::Forms::Label^ no_fav_label;
	private: System::Windows::Forms::Label^ fav_describe_label;

	private: int currentIndex;
	private: int stopIndex;
	private: int steps;
	private: int timerInterval;
	private: bool spinning;
	private: System::Random^ rng;

	private: System::Windows::Forms::Label^ fav_label;
	private: System::Windows::Forms::FlowLayoutPanel^ fav_flights_layout_panel;
private: System::ComponentModel::IContainer^ components;


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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(user_home_page::typeid));
			this->home_user_panal = (gcnew System::Windows::Forms::Panel());
			this->customer_service = (gcnew System::Windows::Forms::Button());
			this->welcome_user = (gcnew System::Windows::Forms::Label());
			this->Exit_button = (gcnew System::Windows::Forms::Button());
			this->favourite_flights_button = (gcnew System::Windows::Forms::Button());
			this->Booked_tickets_button = (gcnew System::Windows::Forms::Button());
			this->Flights_button = (gcnew System::Windows::Forms::Button());
			this->skyport_title = (gcnew System::Windows::Forms::Label());
			this->sign_in_button = (gcnew System::Windows::Forms::Button());
			this->log_out = (gcnew System::Windows::Forms::Button());
			this->search_flights_panel = (gcnew System::Windows::Forms::Panel());
			this->sort_by_faster = (gcnew System::Windows::Forms::RadioButton());
			this->sort_by_cheaper = (gcnew System::Windows::Forms::RadioButton());
			this->travler_panel = (gcnew System::Windows::Forms::Panel());
			this->infants_cnt = (gcnew System::Windows::Forms::TextBox());
			this->infants_inc = (gcnew System::Windows::Forms::Button());
			this->infants_dec = (gcnew System::Windows::Forms::Button());
			this->infants_age = (gcnew System::Windows::Forms::Label());
			this->infants = (gcnew System::Windows::Forms::Label());
			this->children_cnt = (gcnew System::Windows::Forms::TextBox());
			this->children_inc = (gcnew System::Windows::Forms::Button());
			this->childeren_dec = (gcnew System::Windows::Forms::Button());
			this->children_age = (gcnew System::Windows::Forms::Label());
			this->children = (gcnew System::Windows::Forms::Label());
			this->adult_cnt = (gcnew System::Windows::Forms::TextBox());
			this->adult_inc = (gcnew System::Windows::Forms::Button());
			this->adult_decrease = (gcnew System::Windows::Forms::Button());
			this->adult_age = (gcnew System::Windows::Forms::Label());
			this->adult = (gcnew System::Windows::Forms::Label());
			this->drop_down = (gcnew System::Windows::Forms::Button());
			this->traveler_label = (gcnew System::Windows::Forms::Label());
			this->transfer_pictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->no_results = (gcnew System::Windows::Forms::Label());
			this->category = (gcnew System::Windows::Forms::ComboBox());
			this->search = (gcnew System::Windows::Forms::Button());
			this->departure_date = (gcnew System::Windows::Forms::DateTimePicker());
			this->flight_layout_panel = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->dep_city_label = (gcnew System::Windows::Forms::Label());
			this->dep_date_label = (gcnew System::Windows::Forms::Label());
			this->arrival_city_label = (gcnew System::Windows::Forms::Label());
			this->d_airport = (gcnew System::Windows::Forms::TextBox());
			this->a_airport = (gcnew System::Windows::Forms::TextBox());
			this->fav_view_panel = (gcnew System::Windows::Forms::Panel());
			this->no_fav_label = (gcnew System::Windows::Forms::Label());
			this->fav_describe_label = (gcnew System::Windows::Forms::Label());
			this->fav_label = (gcnew System::Windows::Forms::Label());
			this->fav_flights_layout_panel = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->chat_panel = (gcnew System::Windows::Forms::Panel());
			this->chatbox = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->send_button = (gcnew System::Windows::Forms::Button());
			this->txtMessage = (gcnew System::Windows::Forms::TextBox());
			this->panel_booked = (gcnew System::Windows::Forms::Panel());
			this->booked_layout = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->booked_icon_ticket = (gcnew System::Windows::Forms::PictureBox());
			this->hook_booked_label = (gcnew System::Windows::Forms::Label());
			this->data_booking_panal = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->check_out_panal = (gcnew System::Windows::Forms::Panel());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->total_price = (gcnew System::Windows::Forms::Label());
			this->Total = (gcnew System::Windows::Forms::Label());
			this->price_infant = (gcnew System::Windows::Forms::Label());
			this->price_child = (gcnew System::Windows::Forms::Label());
			this->price_adult = (gcnew System::Windows::Forms::Label());
			this->cnt_infant = (gcnew System::Windows::Forms::Label());
			this->cnt_child = (gcnew System::Windows::Forms::Label());
			this->cnt_adult = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->mst_panel = (gcnew System::Windows::Forms::Panel());
			this->mst2 = (gcnew System::Windows::Forms::Button());
			this->mst4 = (gcnew System::Windows::Forms::Button());
			this->mst5 = (gcnew System::Windows::Forms::Button());
			this->mst1 = (gcnew System::Windows::Forms::Button());
			this->mst_gft = (gcnew System::Windows::Forms::Label());
			this->mst_start = (gcnew System::Windows::Forms::Button());
			this->mst3 = (gcnew System::Windows::Forms::Button());
			this->mst6 = (gcnew System::Windows::Forms::Button());
			this->mst_hook = (gcnew System::Windows::Forms::Label());
			this->mst_timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->get_discount_button = (gcnew System::Windows::Forms::Button());
			this->home_user_panal->SuspendLayout();
			this->search_flights_panel->SuspendLayout();
			this->travler_panel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->transfer_pictureBox))->BeginInit();
			this->fav_view_panel->SuspendLayout();
			this->chat_panel->SuspendLayout();
			this->panel_booked->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->booked_icon_ticket))->BeginInit();
			this->check_out_panal->SuspendLayout();
			this->mst_panel->SuspendLayout();
			this->SuspendLayout();
			// 
			// home_user_panal
			// 
			this->home_user_panal->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(10)), static_cast<System::Int32>(static_cast<System::Byte>(25)),
				static_cast<System::Int32>(static_cast<System::Byte>(40)));
			this->home_user_panal->Controls->Add(this->customer_service);
			this->home_user_panal->Controls->Add(this->welcome_user);
			this->home_user_panal->Controls->Add(this->Exit_button);
			this->home_user_panal->Controls->Add(this->favourite_flights_button);
			this->home_user_panal->Controls->Add(this->Booked_tickets_button);
			this->home_user_panal->Controls->Add(this->Flights_button);
			this->home_user_panal->Controls->Add(this->skyport_title);
			this->home_user_panal->Controls->Add(this->sign_in_button);
			this->home_user_panal->Controls->Add(this->log_out);
			this->home_user_panal->Dock = System::Windows::Forms::DockStyle::Left;
			this->home_user_panal->Location = System::Drawing::Point(0, 0);
			this->home_user_panal->Name = L"home_user_panal";
			this->home_user_panal->Size = System::Drawing::Size(284, 894);
			this->home_user_panal->TabIndex = 1;
			// 
			// customer_service
			// 
			this->customer_service->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(55)),
				static_cast<System::Int32>(static_cast<System::Byte>(85)));
			this->customer_service->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->customer_service->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->customer_service->FlatAppearance->BorderSize = 2;
			this->customer_service->FlatAppearance->MouseOverBackColor = System::Drawing::Color::DodgerBlue;
			this->customer_service->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->customer_service->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->customer_service->ForeColor = System::Drawing::Color::White;
			this->customer_service->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"customer_service.Image")));
			this->customer_service->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->customer_service->Location = System::Drawing::Point(-1, 521);
			this->customer_service->Name = L"customer_service";
			this->customer_service->Size = System::Drawing::Size(284, 100);
			this->customer_service->TabIndex = 5;
			this->customer_service->Text = L"Customer\r\nservice";
			this->customer_service->UseVisualStyleBackColor = false;
			this->customer_service->Click += gcnew System::EventHandler(this, &user_home_page::customer_service_Click);
			// 
			// welcome_user
			// 
			this->welcome_user->AutoSize = true;
			this->welcome_user->BackColor = System::Drawing::Color::Transparent;
			this->welcome_user->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->welcome_user->ForeColor = System::Drawing::Color::White;
			this->welcome_user->Location = System::Drawing::Point(-4, 784);
			this->welcome_user->Name = L"welcome_user";
			this->welcome_user->Size = System::Drawing::Size(139, 32);
			this->welcome_user->TabIndex = 3;
			this->welcome_user->Text = L"Welcome";
			this->welcome_user->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->welcome_user->Visible = false;
			// 
			// Exit_button
			// 
			this->Exit_button->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->Exit_button->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(55)),
				static_cast<System::Int32>(static_cast<System::Byte>(85)));
			this->Exit_button->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->Exit_button->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->Exit_button->FlatAppearance->BorderSize = 2;
			this->Exit_button->FlatAppearance->MouseOverBackColor = System::Drawing::Color::DodgerBlue;
			this->Exit_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Exit_button->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Exit_button->ForeColor = System::Drawing::Color::White;
			this->Exit_button->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Exit_button.Image")));
			this->Exit_button->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->Exit_button->Location = System::Drawing::Point(34, 821);
			this->Exit_button->Name = L"Exit_button";
			this->Exit_button->Size = System::Drawing::Size(201, 61);
			this->Exit_button->TabIndex = 2;
			this->Exit_button->Text = L"Exit\r\n";
			this->Exit_button->UseVisualStyleBackColor = false;
			this->Exit_button->Click += gcnew System::EventHandler(this, &user_home_page::Exit_button_Click);
			// 
			// favourite_flights_button
			// 
			this->favourite_flights_button->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)),
				static_cast<System::Int32>(static_cast<System::Byte>(55)), static_cast<System::Int32>(static_cast<System::Byte>(85)));
			this->favourite_flights_button->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->favourite_flights_button->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->favourite_flights_button->FlatAppearance->BorderSize = 2;
			this->favourite_flights_button->FlatAppearance->MouseOverBackColor = System::Drawing::Color::DodgerBlue;
			this->favourite_flights_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->favourite_flights_button->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->favourite_flights_button->ForeColor = System::Drawing::Color::White;
			this->favourite_flights_button->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"favourite_flights_button.Image")));
			this->favourite_flights_button->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->favourite_flights_button->Location = System::Drawing::Point(0, 396);
			this->favourite_flights_button->Name = L"favourite_flights_button";
			this->favourite_flights_button->Size = System::Drawing::Size(284, 100);
			this->favourite_flights_button->TabIndex = 1;
			this->favourite_flights_button->Text = L"  Favourite flights";
			this->favourite_flights_button->UseVisualStyleBackColor = false;
			this->favourite_flights_button->Click += gcnew System::EventHandler(this, &user_home_page::favourite_flights_button_Click);
			// 
			// Booked_tickets_button
			// 
			this->Booked_tickets_button->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)),
				static_cast<System::Int32>(static_cast<System::Byte>(55)), static_cast<System::Int32>(static_cast<System::Byte>(85)));
			this->Booked_tickets_button->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->Booked_tickets_button->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->Booked_tickets_button->FlatAppearance->BorderSize = 2;
			this->Booked_tickets_button->FlatAppearance->MouseOverBackColor = System::Drawing::Color::DodgerBlue;
			this->Booked_tickets_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Booked_tickets_button->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Booked_tickets_button->ForeColor = System::Drawing::Color::White;
			this->Booked_tickets_button->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Booked_tickets_button.Image")));
			this->Booked_tickets_button->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->Booked_tickets_button->Location = System::Drawing::Point(0, 269);
			this->Booked_tickets_button->Name = L"Booked_tickets_button";
			this->Booked_tickets_button->Size = System::Drawing::Size(284, 102);
			this->Booked_tickets_button->TabIndex = 1;
			this->Booked_tickets_button->Text = L"Booked tickets";
			this->Booked_tickets_button->UseVisualStyleBackColor = false;
			this->Booked_tickets_button->Click += gcnew System::EventHandler(this, &user_home_page::Booked_tickets_button_Click);
			// 
			// Flights_button
			// 
			this->Flights_button->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(55)),
				static_cast<System::Int32>(static_cast<System::Byte>(85)));
			this->Flights_button->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->Flights_button->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->Flights_button->FlatAppearance->BorderSize = 2;
			this->Flights_button->FlatAppearance->MouseOverBackColor = System::Drawing::Color::DodgerBlue;
			this->Flights_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Flights_button->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Flights_button->ForeColor = System::Drawing::Color::White;
			this->Flights_button->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Flights_button.Image")));
			this->Flights_button->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->Flights_button->Location = System::Drawing::Point(0, 144);
			this->Flights_button->Name = L"Flights_button";
			this->Flights_button->Size = System::Drawing::Size(284, 100);
			this->Flights_button->TabIndex = 1;
			this->Flights_button->Text = L"Flights";
			this->Flights_button->UseVisualStyleBackColor = false;
			this->Flights_button->Click += gcnew System::EventHandler(this, &user_home_page::Flights_button_Click);
			// 
			// skyport_title
			// 
			this->skyport_title->Font = (gcnew System::Drawing::Font(L"Segoe UI", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->skyport_title->ForeColor = System::Drawing::Color::White;
			this->skyport_title->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"skyport_title.Image")));
			this->skyport_title->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->skyport_title->Location = System::Drawing::Point(0, 0);
			this->skyport_title->Name = L"skyport_title";
			this->skyport_title->Size = System::Drawing::Size(302, 123);
			this->skyport_title->TabIndex = 0;
			this->skyport_title->Text = L"SkyPort";
			this->skyport_title->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// sign_in_button
			// 
			this->sign_in_button->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->sign_in_button->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(55)),
				static_cast<System::Int32>(static_cast<System::Byte>(85)));
			this->sign_in_button->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->sign_in_button->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->sign_in_button->FlatAppearance->BorderSize = 2;
			this->sign_in_button->FlatAppearance->MouseOverBackColor = System::Drawing::Color::DodgerBlue;
			this->sign_in_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->sign_in_button->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->sign_in_button->ForeColor = System::Drawing::Color::White;
			this->sign_in_button->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"sign_in_button.Image")));
			this->sign_in_button->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->sign_in_button->Location = System::Drawing::Point(34, 734);
			this->sign_in_button->Name = L"sign_in_button";
			this->sign_in_button->Size = System::Drawing::Size(201, 72);
			this->sign_in_button->TabIndex = 2;
			this->sign_in_button->Text = L"sign in";
			this->sign_in_button->UseVisualStyleBackColor = false;
			this->sign_in_button->Click += gcnew System::EventHandler(this, &user_home_page::sign_in_click);
			// 
			// log_out
			// 
			this->log_out->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->log_out->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(55)),
				static_cast<System::Int32>(static_cast<System::Byte>(85)));
			this->log_out->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->log_out->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->log_out->FlatAppearance->BorderSize = 2;
			this->log_out->FlatAppearance->MouseOverBackColor = System::Drawing::Color::DodgerBlue;
			this->log_out->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->log_out->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->log_out->ForeColor = System::Drawing::Color::White;
			this->log_out->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"log_out.Image")));
			this->log_out->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->log_out->Location = System::Drawing::Point(34, 734);
			this->log_out->Name = L"log_out";
			this->log_out->Size = System::Drawing::Size(201, 72);
			this->log_out->TabIndex = 4;
			this->log_out->Text = L"Log out";
			this->log_out->UseVisualStyleBackColor = false;
			this->log_out->Visible = false;
			this->log_out->Click += gcnew System::EventHandler(this, &user_home_page::log_out_Click);
			// 
			// search_flights_panel
			// 
			this->search_flights_panel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(210)), static_cast<System::Int32>(static_cast<System::Byte>(216)), static_cast<System::Int32>(static_cast<System::Byte>(228)));
			this->search_flights_panel->Controls->Add(this->sort_by_faster);
			this->search_flights_panel->Controls->Add(this->sort_by_cheaper);
			this->search_flights_panel->Controls->Add(this->travler_panel);
			this->search_flights_panel->Controls->Add(this->drop_down);
			this->search_flights_panel->Controls->Add(this->traveler_label);
			this->search_flights_panel->Controls->Add(this->transfer_pictureBox);
			this->search_flights_panel->Controls->Add(this->no_results);
			this->search_flights_panel->Controls->Add(this->category);
			this->search_flights_panel->Controls->Add(this->search);
			this->search_flights_panel->Controls->Add(this->departure_date);
			this->search_flights_panel->Controls->Add(this->flight_layout_panel);
			this->search_flights_panel->Controls->Add(this->dep_city_label);
			this->search_flights_panel->Controls->Add(this->dep_date_label);
			this->search_flights_panel->Controls->Add(this->arrival_city_label);
			this->search_flights_panel->Controls->Add(this->d_airport);
			this->search_flights_panel->Controls->Add(this->a_airport);
			this->search_flights_panel->Location = System::Drawing::Point(285, 0);
			this->search_flights_panel->Name = L"search_flights_panel";
			this->search_flights_panel->Size = System::Drawing::Size(1642, 1004);
			this->search_flights_panel->TabIndex = 19;
			this->search_flights_panel->Visible = false;
			this->search_flights_panel->Click += gcnew System::EventHandler(this, &user_home_page::search_flights_panel_Click);
			// 
			// sort_by_faster
			// 
			this->sort_by_faster->AutoSize = true;
			this->sort_by_faster->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold));
			this->sort_by_faster->Location = System::Drawing::Point(784, 162);
			this->sort_by_faster->Name = L"sort_by_faster";
			this->sort_by_faster->Size = System::Drawing::Size(152, 26);
			this->sort_by_faster->TabIndex = 28;
			this->sort_by_faster->TabStop = true;
			this->sort_by_faster->Text = L"Sort by faster";
			this->sort_by_faster->UseVisualStyleBackColor = true;
			this->sort_by_faster->Visible = false;
			this->sort_by_faster->CheckedChanged += gcnew System::EventHandler(this, &user_home_page::sort_by_faster_CheckedChanged);
			// 
			// sort_by_cheaper
			// 
			this->sort_by_cheaper->AutoSize = true;
			this->sort_by_cheaper->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold));
			this->sort_by_cheaper->Location = System::Drawing::Point(620, 162);
			this->sort_by_cheaper->Name = L"sort_by_cheaper";
			this->sort_by_cheaper->Size = System::Drawing::Size(145, 26);
			this->sort_by_cheaper->TabIndex = 27;
			this->sort_by_cheaper->TabStop = true;
			this->sort_by_cheaper->Text = L"Sort by price";
			this->sort_by_cheaper->UseVisualStyleBackColor = true;
			this->sort_by_cheaper->Visible = false;
			this->sort_by_cheaper->CheckedChanged += gcnew System::EventHandler(this, &user_home_page::sort_by_cheaper_CheckedChanged);
			// 
			// travler_panel
			// 
			this->travler_panel->BackColor = System::Drawing::Color::White;
			this->travler_panel->Controls->Add(this->infants_cnt);
			this->travler_panel->Controls->Add(this->infants_inc);
			this->travler_panel->Controls->Add(this->infants_dec);
			this->travler_panel->Controls->Add(this->infants_age);
			this->travler_panel->Controls->Add(this->infants);
			this->travler_panel->Controls->Add(this->children_cnt);
			this->travler_panel->Controls->Add(this->children_inc);
			this->travler_panel->Controls->Add(this->childeren_dec);
			this->travler_panel->Controls->Add(this->children_age);
			this->travler_panel->Controls->Add(this->children);
			this->travler_panel->Controls->Add(this->adult_cnt);
			this->travler_panel->Controls->Add(this->adult_inc);
			this->travler_panel->Controls->Add(this->adult_decrease);
			this->travler_panel->Controls->Add(this->adult_age);
			this->travler_panel->Controls->Add(this->adult);
			this->travler_panel->Location = System::Drawing::Point(31, 45);
			this->travler_panel->Name = L"travler_panel";
			this->travler_panel->Size = System::Drawing::Size(444, 145);
			this->travler_panel->TabIndex = 22;
			this->travler_panel->Visible = false;
			// 
			// infants_cnt
			// 
			this->infants_cnt->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->infants_cnt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->infants_cnt->Location = System::Drawing::Point(327, 97);
			this->infants_cnt->Name = L"infants_cnt";
			this->infants_cnt->Size = System::Drawing::Size(63, 27);
			this->infants_cnt->TabIndex = 14;
			this->infants_cnt->Text = L"0";
			this->infants_cnt->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// infants_inc
			// 
			this->infants_inc->BackColor = System::Drawing::Color::Transparent;
			this->infants_inc->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->infants_inc->Location = System::Drawing::Point(396, 97);
			this->infants_inc->Name = L"infants_inc";
			this->infants_inc->Size = System::Drawing::Size(35, 35);
			this->infants_inc->TabIndex = 13;
			this->infants_inc->Text = L"+";
			this->infants_inc->UseVisualStyleBackColor = false;
			this->infants_inc->Click += gcnew System::EventHandler(this, &user_home_page::infants_inc_Click);
			// 
			// infants_dec
			// 
			this->infants_dec->BackColor = System::Drawing::Color::Transparent;
			this->infants_dec->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->infants_dec->Location = System::Drawing::Point(286, 97);
			this->infants_dec->Name = L"infants_dec";
			this->infants_dec->Size = System::Drawing::Size(35, 35);
			this->infants_dec->TabIndex = 12;
			this->infants_dec->Text = L"-\r\n.\r\n";
			this->infants_dec->UseVisualStyleBackColor = false;
			this->infants_dec->Click += gcnew System::EventHandler(this, &user_home_page::infants_dec_Click);
			// 
			// infants_age
			// 
			this->infants_age->AutoSize = true;
			this->infants_age->BackColor = System::Drawing::Color::Transparent;
			this->infants_age->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->infants_age->ForeColor = System::Drawing::SystemColors::ControlDark;
			this->infants_age->Location = System::Drawing::Point(166, 100);
			this->infants_age->Name = L"infants_age";
			this->infants_age->Size = System::Drawing::Size(94, 29);
			this->infants_age->TabIndex = 11;
			this->infants_age->Text = L"under 2";
			// 
			// infants
			// 
			this->infants->AutoSize = true;
			this->infants->BackColor = System::Drawing::Color::Transparent;
			this->infants->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->infants->Location = System::Drawing::Point(13, 100);
			this->infants->Name = L"infants";
			this->infants->Size = System::Drawing::Size(154, 29);
			this->infants->TabIndex = 10;
			this->infants->Text = L"Infants on lap";
			// 
			// children_cnt
			// 
			this->children_cnt->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->children_cnt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->children_cnt->Location = System::Drawing::Point(327, 51);
			this->children_cnt->Name = L"children_cnt";
			this->children_cnt->Size = System::Drawing::Size(63, 27);
			this->children_cnt->TabIndex = 9;
			this->children_cnt->Text = L"0";
			this->children_cnt->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// children_inc
			// 
			this->children_inc->BackColor = System::Drawing::Color::Transparent;
			this->children_inc->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->children_inc->Location = System::Drawing::Point(396, 51);
			this->children_inc->Name = L"children_inc";
			this->children_inc->Size = System::Drawing::Size(35, 35);
			this->children_inc->TabIndex = 8;
			this->children_inc->Text = L"+";
			this->children_inc->UseVisualStyleBackColor = false;
			this->children_inc->Click += gcnew System::EventHandler(this, &user_home_page::children_inc_Click);
			// 
			// childeren_dec
			// 
			this->childeren_dec->BackColor = System::Drawing::Color::Transparent;
			this->childeren_dec->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->childeren_dec->Location = System::Drawing::Point(286, 51);
			this->childeren_dec->Name = L"childeren_dec";
			this->childeren_dec->Size = System::Drawing::Size(35, 35);
			this->childeren_dec->TabIndex = 7;
			this->childeren_dec->Text = L"-";
			this->childeren_dec->UseVisualStyleBackColor = false;
			this->childeren_dec->Click += gcnew System::EventHandler(this, &user_home_page::childeren_dec_Click);
			// 
			// children_age
			// 
			this->children_age->AutoSize = true;
			this->children_age->BackColor = System::Drawing::Color::Transparent;
			this->children_age->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->children_age->ForeColor = System::Drawing::SystemColors::ControlDark;
			this->children_age->Location = System::Drawing::Point(116, 54);
			this->children_age->Name = L"children_age";
			this->children_age->Size = System::Drawing::Size(60, 29);
			this->children_age->TabIndex = 6;
			this->children_age->Text = L"0-17";
			// 
			// children
			// 
			this->children->AutoSize = true;
			this->children->BackColor = System::Drawing::Color::Transparent;
			this->children->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->children->Location = System::Drawing::Point(13, 54);
			this->children->Name = L"children";
			this->children->Size = System::Drawing::Size(104, 29);
			this->children->TabIndex = 5;
			this->children->Text = L"Children";
			// 
			// adult_cnt
			// 
			this->adult_cnt->BackColor = System::Drawing::SystemColors::Window;
			this->adult_cnt->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->adult_cnt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->adult_cnt->Location = System::Drawing::Point(327, 6);
			this->adult_cnt->Name = L"adult_cnt";
			this->adult_cnt->Size = System::Drawing::Size(63, 27);
			this->adult_cnt->TabIndex = 4;
			this->adult_cnt->Text = L"1";
			this->adult_cnt->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// adult_inc
			// 
			this->adult_inc->BackColor = System::Drawing::Color::Transparent;
			this->adult_inc->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->adult_inc->Location = System::Drawing::Point(396, 6);
			this->adult_inc->Name = L"adult_inc";
			this->adult_inc->Size = System::Drawing::Size(35, 35);
			this->adult_inc->TabIndex = 3;
			this->adult_inc->Text = L"+";
			this->adult_inc->UseVisualStyleBackColor = false;
			this->adult_inc->Click += gcnew System::EventHandler(this, &user_home_page::adult_inc_Click);
			// 
			// adult_decrease
			// 
			this->adult_decrease->BackColor = System::Drawing::Color::Transparent;
			this->adult_decrease->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->adult_decrease->Location = System::Drawing::Point(286, 6);
			this->adult_decrease->Name = L"adult_decrease";
			this->adult_decrease->Size = System::Drawing::Size(35, 35);
			this->adult_decrease->TabIndex = 2;
			this->adult_decrease->Text = L"-\r\n.\r\n";
			this->adult_decrease->UseVisualStyleBackColor = false;
			this->adult_decrease->Click += gcnew System::EventHandler(this, &user_home_page::adult_decrease_Click);
			// 
			// adult_age
			// 
			this->adult_age->AutoSize = true;
			this->adult_age->BackColor = System::Drawing::Color::Transparent;
			this->adult_age->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->adult_age->ForeColor = System::Drawing::SystemColors::ControlDark;
			this->adult_age->Location = System::Drawing::Point(87, 9);
			this->adult_age->Name = L"adult_age";
			this->adult_age->Size = System::Drawing::Size(53, 29);
			this->adult_age->TabIndex = 1;
			this->adult_age->Text = L"18+";
			// 
			// adult
			// 
			this->adult->AutoSize = true;
			this->adult->BackColor = System::Drawing::Color::Transparent;
			this->adult->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->adult->Location = System::Drawing::Point(13, 9);
			this->adult->Name = L"adult";
			this->adult->Size = System::Drawing::Size(79, 29);
			this->adult->TabIndex = 0;
			this->adult->Text = L"Adults";
			// 
			// drop_down
			// 
			this->drop_down->BackColor = System::Drawing::SystemColors::Window;
			this->drop_down->FlatAppearance->BorderSize = 0;
			this->drop_down->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->drop_down->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->drop_down->Location = System::Drawing::Point(132, 46);
			this->drop_down->Name = L"drop_down";
			this->drop_down->Size = System::Drawing::Size(29, 32);
			this->drop_down->TabIndex = 24;
			this->drop_down->Text = L"˅";
			this->drop_down->UseVisualStyleBackColor = false;
			this->drop_down->Click += gcnew System::EventHandler(this, &user_home_page::drop_down_Click_1);
			// 
			// traveler_label
			// 
			this->traveler_label->AutoSize = true;
			this->traveler_label->BackColor = System::Drawing::SystemColors::Window;
			this->traveler_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->traveler_label->Location = System::Drawing::Point(31, 46);
			this->traveler_label->Name = L"traveler_label";
			this->traveler_label->Size = System::Drawing::Size(100, 32);
			this->traveler_label->TabIndex = 23;
			this->traveler_label->Text = L"1 adult";
			// 
			// transfer_pictureBox
			// 
			this->transfer_pictureBox->BackColor = System::Drawing::Color::Transparent;
			this->transfer_pictureBox->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"transfer_pictureBox.Image")));
			this->transfer_pictureBox->Location = System::Drawing::Point(480, 123);
			this->transfer_pictureBox->Name = L"transfer_pictureBox";
			this->transfer_pictureBox->Size = System::Drawing::Size(40, 35);
			this->transfer_pictureBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->transfer_pictureBox->TabIndex = 18;
			this->transfer_pictureBox->TabStop = false;
			this->transfer_pictureBox->Click += gcnew System::EventHandler(this, &user_home_page::transfer_pictureBox_Click);
			// 
			// no_results
			// 
			this->no_results->AutoSize = true;
			this->no_results->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(150)), static_cast<System::Int32>(static_cast<System::Byte>(250)),
				static_cast<System::Int32>(static_cast<System::Byte>(250)), static_cast<System::Int32>(static_cast<System::Byte>(250)));
			this->no_results->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 25.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->no_results->ForeColor = System::Drawing::SystemColors::ActiveBorder;
			this->no_results->Location = System::Drawing::Point(643, 578);
			this->no_results->Name = L"no_results";
			this->no_results->Size = System::Drawing::Size(337, 51);
			this->no_results->TabIndex = 21;
			this->no_results->Text = L"No flights found";
			this->no_results->Visible = false;
			// 
			// category
			// 
			this->category->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->category->FormattingEnabled = true;
			this->category->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"Economy", L"Premium Economy", L"Business", L"First Class" });
			this->category->Location = System::Drawing::Point(252, 46);
			this->category->Name = L"category";
			this->category->Size = System::Drawing::Size(223, 37);
			this->category->TabIndex = 20;
			this->category->Text = L"Economy";
			this->category->SelectedIndexChanged += gcnew System::EventHandler(this, &user_home_page::category_SelectedIndexChanged);
			// 
			// search
			// 
			this->search->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(7)), static_cast<System::Int32>(static_cast<System::Byte>(85)),
				static_cast<System::Int32>(static_cast<System::Byte>(184)));
			this->search->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->search->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->search->ForeColor = System::Drawing::Color::White;
			this->search->Location = System::Drawing::Point(1342, 123);
			this->search->Name = L"search";
			this->search->Size = System::Drawing::Size(184, 34);
			this->search->TabIndex = 19;
			this->search->Text = L"Search";
			this->search->UseVisualStyleBackColor = false;
			this->search->Click += gcnew System::EventHandler(this, &user_home_page::search_Click);
			// 
			// departure_date
			// 
			this->departure_date->CalendarFont = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->departure_date->CustomFormat = L"ddd,dd/MMM/yyyy";
			this->departure_date->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->departure_date->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->departure_date->Location = System::Drawing::Point(1002, 123);
			this->departure_date->MinDate = System::DateTime(2026, 4, 12, 16, 14, 30, 260);
			this->departure_date->Name = L"departure_date";
			this->departure_date->Size = System::Drawing::Size(309, 34);
			this->departure_date->TabIndex = 17;
			this->departure_date->Value = System::DateTime(2026, 4, 12, 16, 14, 30, 260);
			// 
			// flight_layout_panel
			// 
			this->flight_layout_panel->AutoScroll = true;
			this->flight_layout_panel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(150)),
				static_cast<System::Int32>(static_cast<System::Byte>(250)), static_cast<System::Int32>(static_cast<System::Byte>(250)), static_cast<System::Int32>(static_cast<System::Byte>(250)));
			this->flight_layout_panel->Location = System::Drawing::Point(31, 194);
			this->flight_layout_panel->Name = L"flight_layout_panel";
			this->flight_layout_panel->Size = System::Drawing::Size(1576, 768);
			this->flight_layout_panel->TabIndex = 14;
			// 
			// dep_city_label
			// 
			this->dep_city_label->AutoSize = true;
			this->dep_city_label->BackColor = System::Drawing::Color::Transparent;
			this->dep_city_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->dep_city_label->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(49)), static_cast<System::Int32>(static_cast<System::Byte>(52)),
				static_cast<System::Int32>(static_cast<System::Byte>(69)));
			this->dep_city_label->Location = System::Drawing::Point(26, 95);
			this->dep_city_label->Name = L"dep_city_label";
			this->dep_city_label->Size = System::Drawing::Size(218, 22);
			this->dep_city_label->TabIndex = 0;
			this->dep_city_label->Text = L"Departure City / Airport";
			// 
			// dep_date_label
			// 
			this->dep_date_label->AutoSize = true;
			this->dep_date_label->BackColor = System::Drawing::Color::Transparent;
			this->dep_date_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->dep_date_label->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(49)), static_cast<System::Int32>(static_cast<System::Byte>(52)),
				static_cast<System::Int32>(static_cast<System::Byte>(69)));
			this->dep_date_label->Location = System::Drawing::Point(1002, 95);
			this->dep_date_label->Name = L"dep_date_label";
			this->dep_date_label->Size = System::Drawing::Size(147, 22);
			this->dep_date_label->TabIndex = 2;
			this->dep_date_label->Text = L"Departure Date";
			// 
			// arrival_city_label
			// 
			this->arrival_city_label->AutoSize = true;
			this->arrival_city_label->BackColor = System::Drawing::Color::Transparent;
			this->arrival_city_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->arrival_city_label->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(49)),
				static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(69)));
			this->arrival_city_label->Location = System::Drawing::Point(528, 95);
			this->arrival_city_label->Name = L"arrival_city_label";
			this->arrival_city_label->Size = System::Drawing::Size(187, 22);
			this->arrival_city_label->TabIndex = 13;
			this->arrival_city_label->Text = L"Arrival City / Airport";
			// 
			// d_airport
			// 
			this->d_airport->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::SuggestAppend;
			this->d_airport->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::CustomSource;
			this->d_airport->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->d_airport->ForeColor = System::Drawing::Color::Black;
			this->d_airport->Location = System::Drawing::Point(31, 123);
			this->d_airport->Name = L"d_airport";
			this->d_airport->Size = System::Drawing::Size(439, 34);
			this->d_airport->TabIndex = 0;
			// 
			// a_airport
			// 
			this->a_airport->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::SuggestAppend;
			this->a_airport->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::CustomSource;
			this->a_airport->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->a_airport->ForeColor = System::Drawing::Color::Black;
			this->a_airport->Location = System::Drawing::Point(532, 123);
			this->a_airport->Name = L"a_airport";
			this->a_airport->Size = System::Drawing::Size(439, 34);
			this->a_airport->TabIndex = 2;
			// 
			// fav_view_panel
			// 
			this->fav_view_panel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(250)),
				static_cast<System::Int32>(static_cast<System::Byte>(250)), static_cast<System::Int32>(static_cast<System::Byte>(250)));
			this->fav_view_panel->Controls->Add(this->no_fav_label);
			this->fav_view_panel->Controls->Add(this->fav_describe_label);
			this->fav_view_panel->Controls->Add(this->fav_label);
			this->fav_view_panel->Controls->Add(this->fav_flights_layout_panel);
			this->fav_view_panel->Location = System::Drawing::Point(289, 0);
			this->fav_view_panel->Name = L"fav_view_panel";
			this->fav_view_panel->Size = System::Drawing::Size(1600, 970);
			this->fav_view_panel->TabIndex = 20;
			this->fav_view_panel->Visible = false;
			// 
			// no_fav_label
			// 
			this->no_fav_label->AutoSize = true;
			this->no_fav_label->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->no_fav_label->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->no_fav_label->Location = System::Drawing::Point(656, 124);
			this->no_fav_label->Name = L"no_fav_label";
			this->no_fav_label->Size = System::Drawing::Size(235, 41);
			this->no_fav_label->TabIndex = 0;
			this->no_fav_label->Text = L"No favorites yet\r\n";
			this->no_fav_label->Visible = false;
			// 
			// fav_describe_label
			// 
			this->fav_describe_label->AutoSize = true;
			this->fav_describe_label->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->fav_describe_label->Location = System::Drawing::Point(626, 101);
			this->fav_describe_label->Name = L"fav_describe_label";
			this->fav_describe_label->Size = System::Drawing::Size(295, 28);
			this->fav_describe_label->TabIndex = 2;
			this->fav_describe_label->Text = L"Your saved trips in one place ✈️";
			// 
			// fav_label
			// 
			this->fav_label->AutoSize = true;
			this->fav_label->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->fav_label->Location = System::Drawing::Point(448, 42);
			this->fav_label->Name = L"fav_label";
			this->fav_label->Size = System::Drawing::Size(651, 38);
			this->fav_label->TabIndex = 1;
			this->fav_label->Text = L" __________ ❤️ your favourite flight ❤️ __________ ";
			// 
			// fav_flights_layout_panel
			// 
			this->fav_flights_layout_panel->AutoScroll = true;
			this->fav_flights_layout_panel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(250)), static_cast<System::Int32>(static_cast<System::Byte>(250)), static_cast<System::Int32>(static_cast<System::Byte>(250)));
			this->fav_flights_layout_panel->Location = System::Drawing::Point(7, 154);
			this->fav_flights_layout_panel->Name = L"fav_flights_layout_panel";
			this->fav_flights_layout_panel->Size = System::Drawing::Size(1579, 810);
			this->fav_flights_layout_panel->TabIndex = 0;
			// 
			// chat_panel
			// 
			this->chat_panel->BackColor = System::Drawing::Color::Transparent;
			this->chat_panel->Controls->Add(this->chatbox);
			this->chat_panel->Controls->Add(this->send_button);
			this->chat_panel->Controls->Add(this->txtMessage);
			this->chat_panel->Location = System::Drawing::Point(284, 0);
			this->chat_panel->Name = L"chat_panel";
			this->chat_panel->Size = System::Drawing::Size(1640, 1001);
			this->chat_panel->TabIndex = 21;
			this->chat_panel->Visible = false;
			// 
			// chatbox
			// 
			this->chatbox->AutoScroll = true;
			this->chatbox->BackColor = System::Drawing::Color::Transparent;
			this->chatbox->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
			this->chatbox->ForeColor = System::Drawing::SystemColors::Highlight;
			this->chatbox->Location = System::Drawing::Point(7, 0);
			this->chatbox->Name = L"chatbox";
			this->chatbox->Size = System::Drawing::Size(1610, 840);
			this->chatbox->TabIndex = 4;
			this->chatbox->WrapContents = false;
			// 
			// send_button
			// 
			this->send_button->BackColor = System::Drawing::Color::Transparent;
			this->send_button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"send_button.BackgroundImage")));
			this->send_button->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->send_button->Location = System::Drawing::Point(1180, 904);
			this->send_button->Name = L"send_button";
			this->send_button->Size = System::Drawing::Size(56, 40);
			this->send_button->TabIndex = 2;
			this->send_button->UseVisualStyleBackColor = false;
			this->send_button->Visible = false;
			this->send_button->Click += gcnew System::EventHandler(this, &user_home_page::send_Click);
			// 
			// txtMessage
			// 
			this->txtMessage->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->txtMessage->BackColor = System::Drawing::SystemColors::Menu;
			this->txtMessage->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtMessage->Location = System::Drawing::Point(308, 904);
			this->txtMessage->Name = L"txtMessage";
			this->txtMessage->Size = System::Drawing::Size(859, 38);
			this->txtMessage->TabIndex = 1;
			this->txtMessage->TextChanged += gcnew System::EventHandler(this, &user_home_page::txtMessage_TextChanged);
			this->txtMessage->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &user_home_page::txtMessage_KeyDown);
			// 
			// panel_booked
			// 
			this->panel_booked->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(210)),
				static_cast<System::Int32>(static_cast<System::Byte>(216)), static_cast<System::Int32>(static_cast<System::Byte>(228)));
			this->panel_booked->Controls->Add(this->booked_layout);
			this->panel_booked->Controls->Add(this->booked_icon_ticket);
			this->panel_booked->Controls->Add(this->hook_booked_label);
			this->panel_booked->Location = System::Drawing::Point(285, 0);
			this->panel_booked->Name = L"panel_booked";
			this->panel_booked->Size = System::Drawing::Size(1650, 1004);
			this->panel_booked->TabIndex = 22;
			this->panel_booked->Visible = false;
			// 
			// booked_layout
			// 
			this->booked_layout->AutoScroll = true;
			this->booked_layout->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(150)), static_cast<System::Int32>(static_cast<System::Byte>(250)),
				static_cast<System::Int32>(static_cast<System::Byte>(250)), static_cast<System::Int32>(static_cast<System::Byte>(250)));
			this->booked_layout->Location = System::Drawing::Point(76, 64);
			this->booked_layout->Name = L"booked_layout";
			this->booked_layout->Size = System::Drawing::Size(1505, 900);
			this->booked_layout->TabIndex = 0;
			// 
			// booked_icon_ticket
			// 
			this->booked_icon_ticket->BackColor = System::Drawing::Color::Transparent;
			this->booked_icon_ticket->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"booked_icon_ticket.BackgroundImage")));
			this->booked_icon_ticket->Location = System::Drawing::Point(819, 0);
			this->booked_icon_ticket->Name = L"booked_icon_ticket";
			this->booked_icon_ticket->Size = System::Drawing::Size(60, 57);
			this->booked_icon_ticket->TabIndex = 2;
			this->booked_icon_ticket->TabStop = false;
			// 
			// hook_booked_label
			// 
			this->hook_booked_label->AutoSize = true;
			this->hook_booked_label->BackColor = System::Drawing::Color::Transparent;
			this->hook_booked_label->Font = (gcnew System::Drawing::Font(L"Segoe UI", 22.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->hook_booked_label->Location = System::Drawing::Point(424, 3);
			this->hook_booked_label->Name = L"hook_booked_label";
			this->hook_booked_label->Size = System::Drawing::Size(374, 50);
			this->hook_booked_label->TabIndex = 1;
			this->hook_booked_label->Text = L"Your booked Tickets";
			// 
			// data_booking_panal
			// 
			this->data_booking_panal->AutoScroll = true;
			this->data_booking_panal->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(150)),
				static_cast<System::Int32>(static_cast<System::Byte>(250)), static_cast<System::Int32>(static_cast<System::Byte>(250)), static_cast<System::Int32>(static_cast<System::Byte>(250)));
			this->data_booking_panal->Dock = System::Windows::Forms::DockStyle::Fill;
			this->data_booking_panal->Location = System::Drawing::Point(284, 0);
			this->data_booking_panal->Name = L"data_booking_panal";
			this->data_booking_panal->Size = System::Drawing::Size(1235, 894);
			this->data_booking_panal->TabIndex = 5;
			this->data_booking_panal->Visible = false;
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 1000;
			this->timer1->Tick += gcnew System::EventHandler(this, &user_home_page::timer1_Tick);
			// 
			// check_out_panal
			// 
			this->check_out_panal->BackColor = System::Drawing::Color::White;
			this->check_out_panal->Controls->Add(this->label11);
			this->check_out_panal->Controls->Add(this->label10);
			this->check_out_panal->Controls->Add(this->total_price);
			this->check_out_panal->Controls->Add(this->Total);
			this->check_out_panal->Controls->Add(this->price_infant);
			this->check_out_panal->Controls->Add(this->price_child);
			this->check_out_panal->Controls->Add(this->price_adult);
			this->check_out_panal->Controls->Add(this->cnt_infant);
			this->check_out_panal->Controls->Add(this->cnt_child);
			this->check_out_panal->Controls->Add(this->cnt_adult);
			this->check_out_panal->Controls->Add(this->label1);
			this->check_out_panal->Dock = System::Windows::Forms::DockStyle::Right;
			this->check_out_panal->Font = (gcnew System::Drawing::Font(L"Segoe UI", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->check_out_panal->Location = System::Drawing::Point(1519, 0);
			this->check_out_panal->Name = L"check_out_panal";
			this->check_out_panal->Size = System::Drawing::Size(405, 894);
			this->check_out_panal->TabIndex = 23;
			this->check_out_panal->Visible = false;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Segoe UI", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->Location = System::Drawing::Point(65, 213);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(282, 41);
			this->label11->TabIndex = 11;
			this->label11->Text = L"----------------------";
			this->label11->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Segoe UI", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->Location = System::Drawing::Point(65, 437);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(282, 41);
			this->label10->TabIndex = 10;
			this->label10->Text = L"______________________";
			this->label10->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// total_price
			// 
			this->total_price->AutoSize = true;
			this->total_price->Font = (gcnew System::Drawing::Font(L"Segoe UI", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->total_price->Location = System::Drawing::Point(233, 496);
			this->total_price->Name = L"total_price";
			this->total_price->Size = System::Drawing::Size(0, 45);
			this->total_price->TabIndex = 8;
			this->total_price->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// Total
			// 
			this->Total->AutoSize = true;
			this->Total->Font = (gcnew System::Drawing::Font(L"Segoe UI", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Total->Location = System::Drawing::Point(30, 496);
			this->Total->Name = L"Total";
			this->Total->Size = System::Drawing::Size(181, 45);
			this->Total->TabIndex = 7;
			this->Total->Text = L"Total Price";
			this->Total->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// price_infant
			// 
			this->price_infant->AutoSize = true;
			this->price_infant->Font = (gcnew System::Drawing::Font(L"Segoe UI", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->price_infant->Location = System::Drawing::Point(195, 396);
			this->price_infant->Name = L"price_infant";
			this->price_infant->Size = System::Drawing::Size(170, 41);
			this->price_infant->TabIndex = 6;
			this->price_infant->Text = L"price_infant";
			this->price_infant->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// price_child
			// 
			this->price_child->AutoSize = true;
			this->price_child->Font = (gcnew System::Drawing::Font(L"Segoe UI", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->price_child->Location = System::Drawing::Point(195, 345);
			this->price_child->Name = L"price_child";
			this->price_child->Size = System::Drawing::Size(158, 41);
			this->price_child->TabIndex = 5;
			this->price_child->Text = L"price_child";
			this->price_child->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// price_adult
			// 
			this->price_adult->AutoSize = true;
			this->price_adult->Font = (gcnew System::Drawing::Font(L"Segoe UI", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->price_adult->Location = System::Drawing::Point(195, 297);
			this->price_adult->Name = L"price_adult";
			this->price_adult->Size = System::Drawing::Size(162, 41);
			this->price_adult->TabIndex = 4;
			this->price_adult->Text = L"price_adult";
			this->price_adult->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// cnt_infant
			// 
			this->cnt_infant->AutoSize = true;
			this->cnt_infant->Font = (gcnew System::Drawing::Font(L"Segoe UI", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cnt_infant->Location = System::Drawing::Point(31, 396);
			this->cnt_infant->Name = L"cnt_infant";
			this->cnt_infant->Size = System::Drawing::Size(102, 41);
			this->cnt_infant->TabIndex = 3;
			this->cnt_infant->Text = L"Infant ";
			this->cnt_infant->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// cnt_child
			// 
			this->cnt_child->AutoSize = true;
			this->cnt_child->Font = (gcnew System::Drawing::Font(L"Segoe UI", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cnt_child->Location = System::Drawing::Point(31, 345);
			this->cnt_child->Name = L"cnt_child";
			this->cnt_child->Size = System::Drawing::Size(102, 41);
			this->cnt_child->TabIndex = 2;
			this->cnt_child->Text = L"Child  ";
			this->cnt_child->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// cnt_adult
			// 
			this->cnt_adult->AutoSize = true;
			this->cnt_adult->Font = (gcnew System::Drawing::Font(L"Segoe UI", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cnt_adult->Location = System::Drawing::Point(31, 297);
			this->cnt_adult->Name = L"cnt_adult";
			this->cnt_adult->Size = System::Drawing::Size(97, 41);
			this->cnt_adult->TabIndex = 1;
			this->cnt_adult->Text = L"Adult ";
			this->cnt_adult->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"label1.Image")));
			this->label1->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->label1->Location = System::Drawing::Point(92, 19);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(211, 203);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Check Out";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// mst_panel
			// 
			this->mst_panel->BackColor = System::Drawing::Color::Transparent;
			this->mst_panel->Controls->Add(this->mst2);
			this->mst_panel->Controls->Add(this->mst4);
			this->mst_panel->Controls->Add(this->mst5);
			this->mst_panel->Controls->Add(this->mst1);
			this->mst_panel->Controls->Add(this->mst_gft);
			this->mst_panel->Controls->Add(this->mst_start);
			this->mst_panel->Controls->Add(this->mst3);
			this->mst_panel->Controls->Add(this->mst6);
			this->mst_panel->Controls->Add(this->mst_hook);
			this->mst_panel->Location = System::Drawing::Point(285, 0);
			this->mst_panel->Name = L"mst_panel";
			this->mst_panel->Size = System::Drawing::Size(1872, 1054);
			this->mst_panel->TabIndex = 24;
			this->mst_panel->Visible = false;
			// 
			// mst2
			// 
			this->mst2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->mst2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"mst2.BackgroundImage")));
			this->mst2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->mst2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 30, System::Drawing::FontStyle::Bold));
			this->mst2->Location = System::Drawing::Point(850, 132);
			this->mst2->Name = L"mst2";
			this->mst2->Size = System::Drawing::Size(277, 237);
			this->mst2->TabIndex = 5;
			this->mst2->UseVisualStyleBackColor = false;
			// 
			// mst4
			// 
			this->mst4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->mst4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"mst4.BackgroundImage")));
			this->mst4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->mst4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 30, System::Drawing::FontStyle::Bold));
			this->mst4->Location = System::Drawing::Point(305, 452);
			this->mst4->Name = L"mst4";
			this->mst4->Size = System::Drawing::Size(277, 237);
			this->mst4->TabIndex = 4;
			this->mst4->UseVisualStyleBackColor = false;
			// 
			// mst5
			// 
			this->mst5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->mst5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"mst5.BackgroundImage")));
			this->mst5->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->mst5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 30, System::Drawing::FontStyle::Bold));
			this->mst5->Location = System::Drawing::Point(850, 452);
			this->mst5->Name = L"mst5";
			this->mst5->Size = System::Drawing::Size(277, 237);
			this->mst5->TabIndex = 2;
			this->mst5->UseVisualStyleBackColor = false;
			// 
			// mst1
			// 
			this->mst1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->mst1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"mst1.BackgroundImage")));
			this->mst1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->mst1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 30, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mst1->Location = System::Drawing::Point(306, 132);
			this->mst1->Name = L"mst1";
			this->mst1->Size = System::Drawing::Size(277, 237);
			this->mst1->TabIndex = 1;
			this->mst1->UseVisualStyleBackColor = false;
			// 
			// mst_gft
			// 
			this->mst_gft->AutoSize = true;
			this->mst_gft->BackColor = System::Drawing::Color::Transparent;
			this->mst_gft->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 35, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mst_gft->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->mst_gft->Location = System::Drawing::Point(0, 0);
			this->mst_gft->Name = L"mst_gft";
			this->mst_gft->Size = System::Drawing::Size(0, 67);
			this->mst_gft->TabIndex = 8;
			// 
			// mst_start
			// 
			this->mst_start->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->mst_start->Font = (gcnew System::Drawing::Font(L"Bernard MT Condensed", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mst_start->Location = System::Drawing::Point(418, 841);
			this->mst_start->Name = L"mst_start";
			this->mst_start->Size = System::Drawing::Size(93, 50);
			this->mst_start->TabIndex = 7;
			this->mst_start->Text = L"start";
			this->mst_start->UseVisualStyleBackColor = false;
			this->mst_start->Click += gcnew System::EventHandler(this, &user_home_page::mst_start_Click);
			// 
			// mst3
			// 
			this->mst3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->mst3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"mst3.BackgroundImage")));
			this->mst3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->mst3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 30, System::Drawing::FontStyle::Bold));
			this->mst3->Location = System::Drawing::Point(1401, 132);
			this->mst3->Name = L"mst3";
			this->mst3->Size = System::Drawing::Size(277, 237);
			this->mst3->TabIndex = 6;
			this->mst3->UseVisualStyleBackColor = false;
			// 
			// mst6
			// 
			this->mst6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->mst6->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"mst6.BackgroundImage")));
			this->mst6->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->mst6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 30, System::Drawing::FontStyle::Bold));
			this->mst6->Location = System::Drawing::Point(1401, 452);
			this->mst6->Name = L"mst6";
			this->mst6->Size = System::Drawing::Size(277, 237);
			this->mst6->TabIndex = 3;
			this->mst6->UseVisualStyleBackColor = false;
			// 
			// mst_hook
			// 
			this->mst_hook->AutoSize = true;
			this->mst_hook->BackColor = System::Drawing::Color::Transparent;
			this->mst_hook->Font = (gcnew System::Drawing::Font(L"Segoe UI", 22.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mst_hook->ForeColor = System::Drawing::SystemColors::MenuText;
			this->mst_hook->Location = System::Drawing::Point(409, 51);
			this->mst_hook->Name = L"mst_hook";
			this->mst_hook->Size = System::Drawing::Size(1000, 50);
			this->mst_hook->TabIndex = 0;
			this->mst_hook->Text = L"________Get exclusive discounts on your next flight________";
			// 
			// mst_timer
			// 
			this->mst_timer->Tick += gcnew System::EventHandler(this, &user_home_page::mst_timer_Tick);
			// 
			// get_discount_button
			// 
			this->get_discount_button->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(85)), static_cast<System::Int32>(static_cast<System::Byte>(170)));
			this->get_discount_button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->get_discount_button->Font = (gcnew System::Drawing::Font(L"Segoe UI", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->get_discount_button->ForeColor = System::Drawing::Color::White;
			this->get_discount_button->Location = System::Drawing::Point(88, 578);
			this->get_discount_button->Name = L"get_discount_button";
			this->get_discount_button->Size = System::Drawing::Size(235, 68);
			this->get_discount_button->TabIndex = 9;
			this->get_discount_button->Text = L"Get Discount";
			this->get_discount_button->UseVisualStyleBackColor = false;
			this->get_discount_button->Click += gcnew System::EventHandler(this, &user_home_page::get_discount_button_Click);
			// 
			// user_home_page
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->ClientSize = System::Drawing::Size(1924, 894);
			this->Controls->Add(this->fav_view_panel);
			this->Controls->Add(this->chat_panel);
			this->Controls->Add(this->data_booking_panal);
			this->Controls->Add(this->home_user_panal);
			this->Controls->Add(this->panel_booked);
			this->Controls->Add(this->check_out_panal);
			this->Controls->Add(this->mst_panel);
			this->Controls->Add(this->search_flights_panel);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"user_home_page";
			this->Text = L"Home page";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &user_home_page::user_home_page_Load);
			this->home_user_panal->ResumeLayout(false);
			this->home_user_panal->PerformLayout();
			this->search_flights_panel->ResumeLayout(false);
			this->search_flights_panel->PerformLayout();
			this->travler_panel->ResumeLayout(false);
			this->travler_panel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->transfer_pictureBox))->EndInit();
			this->fav_view_panel->ResumeLayout(false);
			this->fav_view_panel->PerformLayout();
			this->chat_panel->ResumeLayout(false);
			this->chat_panel->PerformLayout();
			this->panel_booked->ResumeLayout(false);
			this->panel_booked->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->booked_icon_ticket))->EndInit();
			this->check_out_panal->ResumeLayout(false);
			this->check_out_panal->PerformLayout();
			this->mst_panel->ResumeLayout(false);
			this->mst_panel->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void user_home_page_Load(System::Object^ sender, System::EventArgs^ e) {
			AutoCompleteStringCollection^ collection = gcnew AutoCompleteStringCollection();

			for (int i = 0; i < airports.size(); i++)
			{
				collection->Add(gcnew String(airports[i].name.c_str()));
			}
			d_airport->AutoCompleteCustomSource = collection;
			a_airport->AutoCompleteCustomSource = collection;
			//fav_describe_label->Left = (fav_view_panel->Width - fav_describe_label->Width) / 2;
			//fav_describe_label->Top = (fav_view_panel->Height - fav_describe_label->Height) / 2;
			no_fav_label->Top = (fav_view_panel->Height - no_fav_label->Height) / 2;


			hook_booked_label->Left = (this->panel_booked->Width - hook_booked_label->Width) / 2;
			booked_icon_ticket->Left = hook_booked_label->Left + hook_booked_label->Width - 2;

			System::String^ path1 = System::IO::Path::Combine(System::Windows::Forms::Application::StartupPath, L"img1.png");
			System::String^ path2 = System::IO::Path::Combine(System::Windows::Forms::Application::StartupPath, L"img2.png");
			System::String^ path3 = System::IO::Path::Combine(System::Windows::Forms::Application::StartupPath, L"img3.png");
			System::String^ path4 = System::IO::Path::Combine(System::Windows::Forms::Application::StartupPath, L"img4.png");
			System::String^ path5 = System::IO::Path::Combine(System::Windows::Forms::Application::StartupPath, L"img5.png");
			System::String^ path6 = System::IO::Path::Combine(System::Windows::Forms::Application::StartupPath, L"img6.png");

			if (System::IO::File::Exists(path1)) mst1->BackgroundImage = System::Drawing::Image::FromFile(path1);
			if (System::IO::File::Exists(path2)) mst2->BackgroundImage = System::Drawing::Image::FromFile(path2);
			if (System::IO::File::Exists(path3)) mst3->BackgroundImage = System::Drawing::Image::FromFile(path3);
			if (System::IO::File::Exists(path4)) mst4->BackgroundImage = System::Drawing::Image::FromFile(path4);
			if (System::IO::File::Exists(path5)) mst5->BackgroundImage = System::Drawing::Image::FromFile(path5);
			if (System::IO::File::Exists(path6)) mst6->BackgroundImage = System::Drawing::Image::FromFile(path6);

			mst1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			mst2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			mst3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			mst4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			mst5->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			mst6->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;

			mst1->Text = L"";
			mst2->Text = L"";
			mst3->Text = L"";
			mst4->Text = L"";
			mst5->Text = L"";
			mst6->Text = L"";

			mst1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			mst2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			mst3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			mst4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			mst5->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			mst6->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;

			rng = gcnew System::Random();
			currentIndex = 0;
			stopIndex = 0;
			steps = 0;
			timerInterval = 80;
			spinning = false;
	}
	
	private: System::Void messages_Load(System::Object^ sender, System::EventArgs^ e)
	{
		chatbox->Controls->Clear();
		open_chat(current_user_name);

		for (int i = 0; i < chat_messages.size(); i++)
		{
			Label^ bubble = gcnew Label();

			bubble->AutoSize = true;
			bubble->MaximumSize = System::Drawing::Size(500, 0);
			bubble->Padding = System::Windows::Forms::Padding(10);
			bubble->BorderStyle = BorderStyle::FixedSingle;
			bubble->Font = gcnew System::Drawing::Font("Segoe UI", 16);
			bubble->Margin = System::Windows::Forms::Padding(10, 5, 10, 5);

			if (chat_messages[i].if_admin)
			{
				bubble->Text = gcnew String("Bot: ");
				bubble->BackColor = System::Drawing::Color::White;
				bubble->ForeColor = System::Drawing::Color::Black;
			}
			else
			{
				bubble->Text = gcnew String("You: ");
				bubble->BackColor = System::Drawing::Color::FromArgb(7, 85, 184);
				bubble->ForeColor = System::Drawing::Color::White;
			}
			bubble->Text += gcnew String(chat_messages[i].message.c_str());
			chatbox->Controls->Add(bubble);
		}
		chatbox->VerticalScroll->Value = chatbox->VerticalScroll->Maximum;
		chatbox->PerformLayout();
	}

		   //functions
		void ResetButtonsColor() {
			Flights_button->BackColor = System::Drawing::Color::FromArgb(28, 55, 85);
			favourite_flights_button->BackColor = System::Drawing::Color::FromArgb(28, 55, 85);
			Booked_tickets_button->BackColor = System::Drawing::Color::FromArgb(28, 55, 85);
			customer_service->BackColor = System::Drawing::Color::FromArgb(28, 55, 85);
		}
	private: System::Void sign_in_click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		sign_up_users_form^ f = gcnew sign_up_users_form();
		f->ShowDialog();
		if (is_admin && is_signed_in) {
			admin_home_page^ admin_page = gcnew admin_home_page();
			admin_page->ShowDialog();
			if (is_admin) this->Close();
			else this->Show();
			return;
		}
		if (is_signed_in) {
			sign_in_button->Visible = false;
			welcome_user->Visible = true;
			log_out->Visible = true;
			search_flights_panel->Visible = false;
			panel_booked->Visible = false;
			fav_view_panel->Visible = false;
			chat_panel->Visible = false;
			this->Show();
			welcome_user->Text = "Welcome, " + marshal_as<String^>(first_name);
		}
		else this->Close();
	}
	private: System::Void Flights_button_Click(System::Object^ sender, System::EventArgs^ e) {
		ResetButtonsColor();
		Flights_button->BackColor = System::Drawing::Color::FromArgb(0, 120, 215);
		search_flights_panel->Visible = true;
		fav_view_panel->Visible = false;
		chat_panel->Visible = false;
		panel_booked->Visible = false;
		data_booking_panal->Visible = false;
		check_out_panal->Visible = false;
		getUserFavorites(current_user_name);
		
		 search_Click(sender, e);
	}
	public: System::Void Booked_tickets_button_Click(System::Object^ sender, System::EventArgs^ e) {
		if (!is_signed_in) {
			MessageBox::Show("Please sign in to show your favourite flights.", "Not Signed In", MessageBoxButtons::OK, MessageBoxIcon::Information);
			return;
		}
		ResetButtonsColor();
		Booked_tickets_button->BackColor = System::Drawing::Color::FromArgb(0, 120, 215);
		panel_booked->Visible = true;
		search_flights_panel->Visible = false;
		fav_view_panel->Visible = false;
		chat_panel->Visible = false;
		data_booking_panal->Visible = false;
		check_out_panal->Visible = false;
		booked_layout->Controls->Clear();
		getUserTickets(current_user_name);
		for (int i = 0; i < user_tickets.size(); i++)
		{
			view_user_booked(user_tickets[i]);
		}
	}
	private: System::Void favourite_flights_button_Click(System::Object^ sender, System::EventArgs^ e) {
		if (!is_signed_in) {
			MessageBox::Show("Please sign in to show your favourite flights.", "Not Signed In", MessageBoxButtons::OK, MessageBoxIcon::Information);
			return;
		}
		ResetButtonsColor();
		favourite_flights_button->BackColor = System::Drawing::Color::FromArgb(0, 120, 215);
		search_flights_panel->Visible = false;
		chat_panel->Visible = false;
		panel_booked->Visible = false;
		data_booking_panal->Visible = false;
		check_out_panal->Visible = false;
		fav_view_panel->Visible = true;
		fav_view_panel->BringToFront();

		fav_flights_layout_panel->Controls->Clear();

		getUserFavorites(current_user_name);
		if (user_favourite.size() == 0) {
			no_fav_label->Visible = true;
			return;
		}
		else no_fav_label->Visible = false;
		for (int i = 0; i < user_favourite.size(); i++)
		{
			view_flight_search_result(user_favourite[i]);
			fav_flights_layout_panel->Controls->Add(flight_card);

			flight_card->add_to_fav->Visible = false;
			flight_card->remove_from_fav->Visible = true;
		}
	}
	private: System::Void customer_service_Click(System::Object^ sender, System::EventArgs^ e) {
		if (!is_signed_in) {
			MessageBox::Show("Please sign in to access customer service.", "Not Signed In", MessageBoxButtons::OK, MessageBoxIcon::Information);
			return;
		}
		ResetButtonsColor();
		chat_panel->BringToFront();
		customer_service->BackColor = System::Drawing::Color::FromArgb(0, 120, 215);
		chat_panel->Visible = true;
		search_flights_panel->Visible = false;
		fav_view_panel->Visible = false;
		panel_booked->Visible = false;
		data_booking_panal->Visible = false;
		check_out_panal->Visible = false;

		messages_Load(sender, e);
		
	}
	private: System::Void Exit_button_Click(System::Object^ sender, System::EventArgs^ e) {
		search_flights_panel->Visible = false;
		Close();
	}
	private: System::Void log_out_Click(System::Object^ sender, System::EventArgs^ e) {
		is_signed_in = false;
		is_admin = false;
		first_name = "";
		current_user_name = "null";
		sign_in_button->Visible = true;
		welcome_user->Visible = false;
		log_out->Visible = false; 
		search_flights_panel->Visible = false;
		panel_booked->Visible = false;
		fav_view_panel->Visible = false;
		chat_panel->Visible = false;
		check_out_panal->Visible = false;

	}

		   //search flights panel events
		   bool in_fav(int index) {
			   int left = 0;
			   int right = user_favourite.size() - 1;

			   while (left <= right) {

				   int mid = (left + right) / 2;

				   if (user_favourite[mid] == index) {
					   return true;
				   }
				   else if (user_favourite[mid] < index) {
					   left = mid + 1;
				   }
				   else {
					   right = mid - 1;
				   }
			   }

			   return false;
		   }
	private: System::Void transfer_pictureBox_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ temp = d_airport->Text;
		d_airport->Text = a_airport->Text;
		a_airport->Text = temp;

		Image^ img = transfer_pictureBox->Image;
		img->RotateFlip(RotateFlipType::Rotate180FlipNone);
		transfer_pictureBox->Image = img;
		transfer_pictureBox->Refresh();
	}

		   
	private: System::Void search_Click(System::Object^ sender, System::EventArgs^ e) {
		if (d_airport->Text != "" && a_airport->Text != "") {

			flight_layout_panel->Controls->Clear();
			skyPort_array <pair<int, flight_struct>> temp_flights;
			string d_airport_str = marshal_as<string>(d_airport->Text);
			string a_airport_str = marshal_as<string>(a_airport->Text);
			string date_str = marshal_as<string>(departure_date->Value.ToString("ddd,dd/MMM/yyyy"));
			int traveleres = (adult_cnt_value + children_cnt_value);
			total_travelers = traveleres + infants_cnt_value;

			for (int i = 0; i < flights.size(); i++) {

				if (flights[i].departure_airport == d_airport_str &&
					flights[i].arrival_airport == a_airport_str &&
					flights[i].departure_date == date_str && 
					flights[i].state == "open to book") {
					if (category->Text == "Economy" && flights[i].seats_in_economy >= traveleres) {
						temp_flights.push_back(make_pair(i, flights[i]));
					}
					else if (category->Text == "Premium Economy" && flights[i].seats_in_premium_economy >= traveleres) {
						temp_flights.push_back(make_pair(i, flights[i]));
					}
					else if (category->Text == "Business" && flights[i].seats_in_business >= traveleres) {
						temp_flights.push_back(make_pair(i, flights[i]));
					}
					else if (category->Text == "First Class" && flights[i].seats_in_first_class >= traveleres) {
						temp_flights.push_back(make_pair(i, flights[i]));
					}
				}
			}

			if (temp_flights.size() == 0) no_results->Visible = true;
			else no_results->Visible = false;

			if (temp_flights.size() > 1) {
				sort_by_faster->Visible = true;
				sort_by_cheaper->Visible = true;
			}
			else {
				sort_by_faster->Visible = false;
				sort_by_cheaper->Visible = false;
			}

			if (sort_by_cheaper->Checked) {
				sort_flights(temp_flights, current_sort_criteria);
			}
			if (sort_by_faster->Checked) {
				sort_flights(temp_flights, current_sort_criteria);
			}

			for (int i = 0; i < temp_flights.size(); i++) {
				view_flight_search_result(temp_flights[i].first);

				flight_layout_panel->Controls->Add(flight_card);
				if (in_fav(temp_flights[i].first)) {
					flight_card->add_to_fav->Visible = false;
					flight_card->remove_from_fav->Visible = true;
				}
				else {
					flight_card->add_to_fav->Visible = true;
					flight_card->remove_from_fav->Visible = false;
				}
			}
		}
		else {

			flight_layout_panel->Controls->Clear();
			skyPort_array <pair<int, flight_struct>> temp_flights;
			
			int traveleres = (adult_cnt_value + children_cnt_value);
			total_travelers = traveleres + infants_cnt_value;

			for (int i = 0; i < flights.size(); i++) {

				
					
					if (category->Text == "Economy" && flights[i].seats_in_economy >= traveleres) {
						temp_flights.push_back(make_pair(i, flights[i]));
					}
					else if (category->Text == "Premium Economy" && flights[i].seats_in_premium_economy >= traveleres) {
						temp_flights.push_back(make_pair(i, flights[i]));
					}
					else if (category->Text == "Business" && flights[i].seats_in_business >= traveleres) {
						temp_flights.push_back(make_pair(i, flights[i]));
					}
					else if (category->Text == "First Class" && flights[i].seats_in_first_class >= traveleres) {
						temp_flights.push_back(make_pair(i, flights[i]));
					}
				
			}

			if (temp_flights.size() == 0) no_results->Visible = true;
			else no_results->Visible = false;

			if (temp_flights.size() > 1) {
				sort_by_faster->Visible = true;
				sort_by_cheaper->Visible = true;
			}
			else {
				sort_by_faster->Visible = false;
				sort_by_cheaper->Visible = false;
			}

			if (sort_by_cheaper->Checked) {
				sort_flights(temp_flights, current_sort_criteria);
			}
			if (sort_by_faster->Checked) {
				sort_flights(temp_flights, current_sort_criteria);
			}

			for (int i = 0; i < temp_flights.size(); i++) {
				view_flight_search_result(temp_flights[i].first);

				flight_layout_panel->Controls->Add(flight_card);
				if (in_fav(temp_flights[i].first)) {
					flight_card->add_to_fav->Visible = false;
					flight_card->remove_from_fav->Visible = true;
				}
				else {
					flight_card->add_to_fav->Visible = true;
					flight_card->remove_from_fav->Visible = false;
				}
			}
		}
	}

	private: System::Void sort_by_cheaper_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		current_sort_criteria = "price";
		search_Click(sender, e);
	}
	private: System::Void sort_by_faster_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		current_sort_criteria = "flight_duration";
		search_Click(sender, e);
	}
		   
	private: System::Void adult_inc_Click(System::Object^ sender, System::EventArgs^ e) {
		adult_cnt->Text = marshal_as<String^>(to_string(++adult_cnt_value));
		search_Click(sender, e);
	}
	private: System::Void children_inc_Click(System::Object^ sender, System::EventArgs^ e) {
		children_cnt->Text = marshal_as<String^>(to_string(++children_cnt_value));
		search_Click(sender, e);
	}
	private: System::Void infants_inc_Click(System::Object^ sender, System::EventArgs^ e) {
		if (infants_cnt_value < adult_cnt_value)
			infants_cnt->Text = marshal_as<String^>(to_string(++infants_cnt_value));
		search_Click(sender, e);
	}
	private: System::Void infants_dec_Click(System::Object^ sender, System::EventArgs^ e) {
		if (infants_cnt_value > 0) {
			infants_cnt->Text = marshal_as<String^>(to_string(--infants_cnt_value));
		}
		search_Click(sender, e);
	}
	private: System::Void childeren_dec_Click(System::Object^ sender, System::EventArgs^ e) {
		if (children_cnt_value > 0) {
			children_cnt->Text = marshal_as<String^>(to_string(--children_cnt_value));
		}
		search_Click(sender, e);
	}
	private: System::Void adult_decrease_Click(System::Object^ sender, System::EventArgs^ e) {
		if (adult_cnt_value > 1) {
			adult_cnt->Text = marshal_as<String^>(to_string(--adult_cnt_value));
			if (infants_cnt_value > adult_cnt_value) {
				infants_cnt->Text = marshal_as<String^>(to_string(--infants_cnt_value));
			}
		}
		search_Click(sender, e);
	}
	private: System::Void drop_down_Click_1(System::Object^ sender, System::EventArgs^ e) {
		travler_panel->Visible = true;
		adult_cnt_value = stoi(marshal_as<string>(adult_cnt->Text));
		children_cnt_value = stoi(marshal_as<string>(children_cnt->Text));
		infants_cnt_value = stoi(marshal_as<string>(infants_cnt->Text));

	}
	private: System::Void search_flights_panel_Click(System::Object^ sender, System::EventArgs^ e) {
		travler_panel->Visible = false;
		if (children_cnt_value == 0 && infants_cnt_value == 0) {
			if (adult_cnt_value > 1)
				traveler_label->Text = adult_cnt_value + " adults";
			else traveler_label->Text = "1 adult";
		}
		else traveler_label->Text = ((adult_cnt_value + children_cnt_value + infants_cnt_value) + " travelers");
		drop_down->Location = System::Drawing::Point(traveler_label->Right, drop_down->Location.Y);
	}
	private: System::Void category_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		flight_category = marshal_as<string>(user_home_page::category->Text);
		search_Click(sender, e);
	}


		   //customer service panel events
		   
	private: System::Void send_Click(System::Object^ sender, System::EventArgs^ e)	{

		messageStruct msg;
		msg.user_name = current_user_name;
		msg.message = marshal_as<string>(txtMessage->Text);
		msg.replied = false;
		msg.if_admin = is_admin;

		messages_array.push_back(msg);

		Label^ bubble = gcnew Label();
		bubble->Font = gcnew System::Drawing::Font("Segoe UI", 16, System::Drawing::FontStyle::Regular);
		bubble->Text = "You: " + txtMessage->Text;
		bubble->AutoSize = true;
		bubble->MaximumSize = System::Drawing::Size(800, 1000);
		bubble->Margin = System::Windows::Forms::Padding(10, 5, 10, 5);
		bubble->Padding = System::Windows::Forms::Padding(10);
		bubble->BackColor = System::Drawing::Color::FromArgb(7, 85, 184);
		bubble->ForeColor = System::Drawing::Color::White;

		chatbox->Controls->Add(bubble);
		chatbox->ScrollControlIntoView(bubble);

		txtMessage->Clear();
	}
	private: System::Void txtMessage_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		if (txtMessage->Text->Length > 0) {
			send_button->Visible = true;
		}
		else {
			send_button->Visible = false;
		}
	}
	private: System::Void txtMessage_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (txtMessage->Text->Length > 0 && e->KeyCode == Keys::Enter) {
			send_Click(sender, e);
			e->SuppressKeyPress = true;
		}
	}

	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		for (int i = 0; i < flights.size(); i++)
		{
			String^ departure_date_str = gcnew String(flights[i].departure_date.c_str());
			String^ departure_time_str = gcnew String(flights[i].time_departure.c_str());
			String^ arrival_date_str = gcnew String(flights[i].arrival_date.c_str());
			String^ arrival_time_str = gcnew String(flights[i].time_arrival.c_str());
			DateTime departure = DateTime::ParseExact(departure_date_str + " " + departure_time_str, "ddd,dd/MMM/yyyy hh:mm tt", nullptr);
			DateTime arrival = DateTime::ParseExact(arrival_date_str + " " + arrival_time_str, "ddd,dd/MMM/yyyy hh:mm tt", nullptr);
			DateTime now = DateTime::Now;
			if(arrival < now && flights[i].state != "arrived") {
				flights[i].state = "arrived";
			}
			if (departure <= now && now <= arrival && flights[i].state != "in air") {
				flights[i].state = "in air";
			}
		}
	}

		   void ResetButtons() {
			   mst1->BackColor = System::Drawing::Color::FromArgb(192, 255, 255);
			   mst2->BackColor = System::Drawing::Color::FromArgb(192, 255, 255);
			   mst3->BackColor = System::Drawing::Color::FromArgb(192, 255, 255);
			   mst4->BackColor = System::Drawing::Color::FromArgb(192, 255, 255);
			   mst5->BackColor = System::Drawing::Color::FromArgb(192, 255, 255);
			   mst6->BackColor = System::Drawing::Color::FromArgb(192, 255, 255);

			   mst1->ForeColor = System::Drawing::Color::Black;
			   mst2->ForeColor = System::Drawing::Color::Black;
			   mst3->ForeColor = System::Drawing::Color::Black;
			   mst4->ForeColor = System::Drawing::Color::Black;
			   mst5->ForeColor = System::Drawing::Color::Black;
			   mst6->ForeColor = System::Drawing::Color::Black;
		   }

		   // Get button by index
		   System::Windows::Forms::Button^ GetButton(int index) {
			   switch (index) {
			   case 0: return mst1;
			   case 1: return mst2;
			   case 2: return mst3;
			   case 3: return mst4;
			   case 4: return mst5;
			   case 5: return mst6;
			   default: return mst1;
			   }
		   }

		   // Get discount text by index
		   System::String^ GetDiscountText(int index) {
			   switch (index) {
			   case 0: return "20";
			   case 1: return "50";
			   case 2: return "10";
			   case 3: return "30";
			   case 4: return "40";
			   case 5: return "Hard Luck";
			   default: return "0";
			   }
		   }

		   void mst_timer_Tick(System::Object^ sender, System::EventArgs^ e) {
			   ResetButtons();

			   System::Windows::Forms::Button^ currentButton = GetButton(currentIndex);
			   currentButton->BackColor = System::Drawing::Color::Yellow;
			   currentButton->ForeColor = System::Drawing::Color::Black;

			   steps++;

			   if (steps > 30 && currentIndex == stopIndex) {
				   mst_timer->Stop();
				   spinning = false;

				   System::Windows::Forms::Button^ winner = GetButton(currentIndex);
				   winner->BackgroundImage = nullptr;
				   winner->Text = GetDiscountText(currentIndex);
				   winner->BackColor = System::Drawing::Color::LimeGreen;
				   winner->ForeColor = System::Drawing::Color::White;
				   winner->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;

				   if (currentIndex == 5) {
					   MessageBox::Show("Hard Luck", "may be next time", MessageBoxButtons::OK, MessageBoxIcon::Information);
				   }
				   else {
					   MessageBox::Show("you saved " + GetDiscountText(currentIndex) + "%", "Congratulations !", MessageBoxButtons::OK, MessageBoxIcon::Information);
				   
					   int disc = safe_cast<int>(Int32::Parse(GetDiscountText(currentIndex)));
					   double Total_price = safe_cast<double>(Double::Parse(total_price->Text));
					   Total_price = Total_price * (100 - disc) / 100.0;
					   total_price->Text = Total_price.ToString("F2");
				   }


				   mst_panel->Visible = false;
				   check_out_panal->Visible = true;
				   data_booking_panal->Visible = true;
				   get_discount_button->Visible = false;

				   mst_gft->BackColor = System::Drawing::Color::LightYellow;
				   mst_start->Enabled = true;
				   mst_start->Text = L"start";
				   return;
			   }

			   currentIndex = (currentIndex + 1) % 6;
		   }

		   void mst_start_Click(System::Object^ sender, System::EventArgs^ e) {
			   if (spinning) return;

			   ResetButtons();

			   stopIndex = rng->Next(0, 6);
			   currentIndex = 0;
			   steps = 0;
			   timerInterval = 80;
			   spinning = true;

			   mst_hook->Text = L"________Get exclusive discounts on your next flight________";
			   mst_gft->Text = L"";

			   mst_timer->Stop();
			   mst_timer->Interval = timerInterval;
			   mst_timer->Start();

			   mst_start->Enabled = false;
			   mst_start->Text = L"wait";
		   }

private: System::Void get_discount_button_Click(System::Object^ sender, System::EventArgs^ e) {

	mst_panel->Visible = true;
	check_out_panal->Visible = false;
	data_booking_panal->Visible = false;

}
};
}
