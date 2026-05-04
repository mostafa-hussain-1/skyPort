#pragma once
#include <string>
#include <msclr/marshal_cppstd.h>
#include <regex>
#include "add_flights.h"
#include "airports.h"
#include "add_plane.h"
#include "add_admin.h"
#include "search_planes.h"
#include "plane_result.h"
#include "flight_result.h"
#include "chatBot.h"
#include "chat_list.h"
using namespace msclr::interop;
using namespace std;
using namespace System::Text::RegularExpressions;
namespace skyPort {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for admin_home_page
	/// </summary>
	

	public ref class admin_home_page : public System::Windows::Forms::Form
	{
	public:
		void UpdatePlaneProcess(int idx) {

			add_plane_button->Visible = false;
			update_plane->Visible = true;
			search_plane_panel->Visible = false;
			add_plane_panel->Visible = true;

			plane_index->Text = idx.ToString();

			code_textBox->Text = marshal_as<String^>(planes[idx].code); 
			code_textBox->ForeColor = System::Drawing::Color::Black;

			plane_model_textBox->Text = marshal_as<String^>(planes[idx].model);
			plane_model_textBox->ForeColor = System::Drawing::Color::Black;

			rows_textBox->Text = planes[idx].rows.ToString();
			rows_textBox->ForeColor = System::Drawing::Color::Black;

			chairs_textBox->Text = planes[idx].nom_of_seats.ToString();
			chairs_textBox->ForeColor = System::Drawing::Color::Black;

			airport_textBox->Text = marshal_as<String^>(planes[idx].place);
			airport_textBox->ForeColor = System::Drawing::Color::Black;

		}
		void UpdateFlightProcess(int idx) {

			add_flight_button->Visible = false;
			update_flight->Visible = true;
			search_flights_panel->Visible = false;
			add_flight_panel->Visible = true;

			flight_index->Text = idx.ToString();

			departure_airport_textbox->Text = marshal_as<String^>(flights[idx].departure_airport);
			departure_airport_textbox->ForeColor = System::Drawing::Color::Black;

			plane_code_textbox->Text = marshal_as<String^>(flights[idx].plane_code);
			plane_code_textbox->ForeColor = System::Drawing::Color::Black;

			dateTimePicker_departure->Text = marshal_as<String^>(flights[idx].departure_date);

			time_departure->Text = marshal_as<String^>(flights[idx].time_departure);

			arrival_airport_textbox->Text = marshal_as<String^>(flights[idx].arrival_airport);
			arrival_airport_textbox->ForeColor = System::Drawing::Color::Black;

			dateTimePicker_arrival->Text = marshal_as<String^>(flights[idx].arrival_date);

			time_arrival->Text = marshal_as<String^>(flights[idx].time_arrival);

			economy_price_textbox->Text = flights[idx].price.economy_price.ToString();
			economy_price_textbox->ForeColor = System::Drawing::Color::Black;

			premium_economy_price_textbox->Text = flights[idx].price.premium_economy_price.ToString();
			premium_economy_price_textbox->ForeColor = System::Drawing::Color::Black;

			business_price_textbox->Text = flights[idx].price.business_price.ToString();
			business_price_textbox->ForeColor = System::Drawing::Color::Black;

			frist_class_price_textbox->Text = flights[idx].price.first_class_price.ToString();
			frist_class_price_textbox->ForeColor = System::Drawing::Color::Black;


		}

		void messages_Load(string user_name)
		{
			chatbox->Controls->Clear();
			open_chat(user_name);

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
					bubble->Text = gcnew String("You: ");
					bubble->BackColor = System::Drawing::Color::White;
					bubble->ForeColor = System::Drawing::Color::Black;
				}
				else
				{
					bubble->Text = gcnew String((user_name + ": ").c_str());
					bubble->BackColor = System::Drawing::Color::FromArgb(7, 85, 184);
					bubble->ForeColor = System::Drawing::Color::White;
				}
				bubble->Text += gcnew String(chat_messages[i].message.c_str());
				chatbox->Controls->Add(bubble);
			}
			chatbox->VerticalScroll->Value = chatbox->VerticalScroll->Maximum;
			chatbox->PerformLayout();
			chatbox->AutoScrollPosition = System::Drawing::Point(0, chatbox->DisplayRectangle.Height);
		}

		admin_home_page(void)
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
		~admin_home_page()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Panel^ add_plane_panel;

	private: System::Windows::Forms::Panel^ add_flight_panel;
	private: System::Windows::Forms::Label^ add_flight_label;
	protected:

	protected:

		property virtual System::Windows::Forms::CreateParams^ CreateParams {
			System::Windows::Forms::CreateParams^ get() override {
				System::Windows::Forms::CreateParams^ cp = __super::CreateParams;
				cp->ExStyle |= 0x02000000;
				return cp;
			}
		}


	private: System::Windows::Forms::DateTimePicker^ time_departure;

	private: System::Windows::Forms::TextBox^ business_price_textbox;

	private: System::Windows::Forms::DateTimePicker^ time_arrival;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker_departure;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker_arrival;
	private: System::Windows::Forms::Button^ add_flight_button;

	private: System::Windows::Forms::Label^ label_palne_code;
	private: System::Windows::Forms::ComboBox^ category_comboBox;

	private: System::Windows::Forms::TextBox^ arrival_airport_textbox;
	private: System::Windows::Forms::Label^ price;

	private: System::Windows::Forms::Label^ arrival_date;

	private: System::Windows::Forms::Label^ departure_date;
	private: System::Windows::Forms::Label^ arrival_airport;


	private: System::Windows::Forms::TextBox^ departure_airport_textbox;
	private: System::Windows::Forms::Label^ departure_airport;

	private: System::Windows::Forms::TextBox^ plane_code_textbox;
	private: System::Windows::Forms::TextBox^ frist_class_price_textbox;
	private: System::Windows::Forms::TextBox^ premium_economy_price_textbox;
	private: System::Windows::Forms::TextBox^ economy_price_textbox;
	private: System::Windows::Forms::Label^ add_plane_plane;
	private: System::Windows::Forms::Label^ airport_label;
	private: System::Windows::Forms::TextBox^ airport_textBox;

	private: System::Windows::Forms::Label^ chairs_label;
	private: System::Windows::Forms::Label^ rows_label;
	private: System::Windows::Forms::Label^ model_label;
	private: System::Windows::Forms::Label^ code_label;
	private: System::Windows::Forms::TextBox^ chairs_textBox;
	private: System::Windows::Forms::TextBox^ rows_textBox;
	private: System::Windows::Forms::TextBox^ plane_model_textBox;
	private: System::Windows::Forms::TextBox^ code_textBox;
	private: System::Windows::Forms::Button^ add_plane_button;






	private: System::Windows::Forms::Panel^ add_admin_panel;
	private: System::Windows::Forms::Label^ add_admin_label;
	private: System::Windows::Forms::PictureBox^ confirm_view;
	private: System::Windows::Forms::PictureBox^ pass_view;
	private: System::Windows::Forms::Button^ add_admin_button;
	private: System::Windows::Forms::Label^ ad_confirm_label;
	private: System::Windows::Forms::Label^ ad_name_label;
	private: System::Windows::Forms::TextBox^ ad_user_name_textBox;
	private: System::Windows::Forms::Label^ ad_phone_label;
	private: System::Windows::Forms::Label^ ad_password_label;
	private: System::Windows::Forms::TextBox^ ad_phone_textBox;
	private: System::Windows::Forms::Label^ ad_user_name_label;
	private: System::Windows::Forms::TextBox^ ad_name_textBox;
	private: System::Windows::Forms::PictureBox^ pass_hide;
	private: System::Windows::Forms::PictureBox^ confirm_hide;
	private: System::Windows::Forms::TextBox^ ad_password_textBox;
	private: System::Windows::Forms::TextBox^ ad_confirm_textBox;
	private: System::Windows::Forms::Panel^ search_plane_panel;
	private: System::Windows::Forms::Label^ no_results;
	private: System::Windows::Forms::Label^ search_results;
	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel1;
	private: System::Windows::Forms::RadioButton^ by_code;
	private: System::Windows::Forms::RadioButton^ by_model;
	private: System::Windows::Forms::TextBox^ search_bar;
	private: System::Windows::Forms::Panel^ search_flights_panel;
	private: System::Windows::Forms::PictureBox^ transfer_pictureBox;
	private: System::Windows::Forms::Label^ no_flights_found;

	private: System::Windows::Forms::Button^ search;
	private: System::Windows::Forms::DateTimePicker^ departure_date_search;
	private: System::Windows::Forms::FlowLayoutPanel^ flights_layout_panel;


	private: System::Windows::Forms::Label^ dep_city_label;
	private: System::Windows::Forms::Label^ dep_date_label;
	private: System::Windows::Forms::Label^ arrival_city_label;
	private: System::Windows::Forms::TextBox^ d_airport;
	private: System::Windows::Forms::TextBox^ a_airport;
	private: System::Windows::Forms::LinkLabel^ open_home_pg;
	private: System::Windows::Forms::Panel^ home_pg_panel;
	private: System::Windows::Forms::Button^ btn_add_plane;
	private: System::Windows::Forms::Label^ title;
	private: System::Windows::Forms::Button^ btn_search_flights;
	private: System::Windows::Forms::Label^ welcome;
	private: System::Windows::Forms::Button^ btn_search_planes;
	private: System::Windows::Forms::Button^ btn_add_flight;
	private: System::Windows::Forms::Button^ btn_add_admin;
private: System::Windows::Forms::Button^ btn_customer_service;

	private: System::Windows::Forms::Button^ update_plane;
	private: System::Windows::Forms::Label^ plane_index;
private: System::Windows::Forms::Label^ flight_index;
private: System::Windows::Forms::Button^ update_flight;
private: System::Windows::Forms::FlowLayoutPanel^ chat_list_panal;
private: System::Windows::Forms::Panel^ chat_bot_panal;
private: System::Windows::Forms::FlowLayoutPanel^ chatbox;
public: System::Windows::Forms::TextBox^ txtMessage;
private: System::Windows::Forms::Button^ send_button;







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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(admin_home_page::typeid));
			this->add_flight_panel = (gcnew System::Windows::Forms::Panel());
			this->flight_index = (gcnew System::Windows::Forms::Label());
			this->add_flight_label = (gcnew System::Windows::Forms::Label());
			this->time_departure = (gcnew System::Windows::Forms::DateTimePicker());
			this->business_price_textbox = (gcnew System::Windows::Forms::TextBox());
			this->time_arrival = (gcnew System::Windows::Forms::DateTimePicker());
			this->dateTimePicker_departure = (gcnew System::Windows::Forms::DateTimePicker());
			this->dateTimePicker_arrival = (gcnew System::Windows::Forms::DateTimePicker());
			this->add_flight_button = (gcnew System::Windows::Forms::Button());
			this->label_palne_code = (gcnew System::Windows::Forms::Label());
			this->category_comboBox = (gcnew System::Windows::Forms::ComboBox());
			this->arrival_airport_textbox = (gcnew System::Windows::Forms::TextBox());
			this->price = (gcnew System::Windows::Forms::Label());
			this->arrival_date = (gcnew System::Windows::Forms::Label());
			this->departure_date = (gcnew System::Windows::Forms::Label());
			this->arrival_airport = (gcnew System::Windows::Forms::Label());
			this->departure_airport_textbox = (gcnew System::Windows::Forms::TextBox());
			this->departure_airport = (gcnew System::Windows::Forms::Label());
			this->plane_code_textbox = (gcnew System::Windows::Forms::TextBox());
			this->frist_class_price_textbox = (gcnew System::Windows::Forms::TextBox());
			this->premium_economy_price_textbox = (gcnew System::Windows::Forms::TextBox());
			this->economy_price_textbox = (gcnew System::Windows::Forms::TextBox());
			this->update_flight = (gcnew System::Windows::Forms::Button());
			this->add_plane_panel = (gcnew System::Windows::Forms::Panel());
			this->plane_index = (gcnew System::Windows::Forms::Label());
			this->add_plane_plane = (gcnew System::Windows::Forms::Label());
			this->airport_label = (gcnew System::Windows::Forms::Label());
			this->airport_textBox = (gcnew System::Windows::Forms::TextBox());
			this->chairs_label = (gcnew System::Windows::Forms::Label());
			this->rows_label = (gcnew System::Windows::Forms::Label());
			this->model_label = (gcnew System::Windows::Forms::Label());
			this->code_label = (gcnew System::Windows::Forms::Label());
			this->chairs_textBox = (gcnew System::Windows::Forms::TextBox());
			this->rows_textBox = (gcnew System::Windows::Forms::TextBox());
			this->plane_model_textBox = (gcnew System::Windows::Forms::TextBox());
			this->code_textBox = (gcnew System::Windows::Forms::TextBox());
			this->add_plane_button = (gcnew System::Windows::Forms::Button());
			this->update_plane = (gcnew System::Windows::Forms::Button());
			this->add_admin_panel = (gcnew System::Windows::Forms::Panel());
			this->add_admin_label = (gcnew System::Windows::Forms::Label());
			this->confirm_view = (gcnew System::Windows::Forms::PictureBox());
			this->pass_view = (gcnew System::Windows::Forms::PictureBox());
			this->add_admin_button = (gcnew System::Windows::Forms::Button());
			this->ad_confirm_label = (gcnew System::Windows::Forms::Label());
			this->ad_name_label = (gcnew System::Windows::Forms::Label());
			this->ad_user_name_textBox = (gcnew System::Windows::Forms::TextBox());
			this->ad_phone_label = (gcnew System::Windows::Forms::Label());
			this->ad_password_label = (gcnew System::Windows::Forms::Label());
			this->ad_phone_textBox = (gcnew System::Windows::Forms::TextBox());
			this->ad_user_name_label = (gcnew System::Windows::Forms::Label());
			this->ad_name_textBox = (gcnew System::Windows::Forms::TextBox());
			this->pass_hide = (gcnew System::Windows::Forms::PictureBox());
			this->confirm_hide = (gcnew System::Windows::Forms::PictureBox());
			this->ad_password_textBox = (gcnew System::Windows::Forms::TextBox());
			this->ad_confirm_textBox = (gcnew System::Windows::Forms::TextBox());
			this->search_plane_panel = (gcnew System::Windows::Forms::Panel());
			this->no_results = (gcnew System::Windows::Forms::Label());
			this->search_results = (gcnew System::Windows::Forms::Label());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->by_code = (gcnew System::Windows::Forms::RadioButton());
			this->by_model = (gcnew System::Windows::Forms::RadioButton());
			this->search_bar = (gcnew System::Windows::Forms::TextBox());
			this->search_flights_panel = (gcnew System::Windows::Forms::Panel());
			this->transfer_pictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->no_flights_found = (gcnew System::Windows::Forms::Label());
			this->search = (gcnew System::Windows::Forms::Button());
			this->departure_date_search = (gcnew System::Windows::Forms::DateTimePicker());
			this->flights_layout_panel = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->dep_city_label = (gcnew System::Windows::Forms::Label());
			this->dep_date_label = (gcnew System::Windows::Forms::Label());
			this->arrival_city_label = (gcnew System::Windows::Forms::Label());
			this->d_airport = (gcnew System::Windows::Forms::TextBox());
			this->a_airport = (gcnew System::Windows::Forms::TextBox());
			this->open_home_pg = (gcnew System::Windows::Forms::LinkLabel());
			this->home_pg_panel = (gcnew System::Windows::Forms::Panel());
			this->btn_customer_service = (gcnew System::Windows::Forms::Button());
			this->btn_add_plane = (gcnew System::Windows::Forms::Button());
			this->title = (gcnew System::Windows::Forms::Label());
			this->btn_search_flights = (gcnew System::Windows::Forms::Button());
			this->welcome = (gcnew System::Windows::Forms::Label());
			this->btn_search_planes = (gcnew System::Windows::Forms::Button());
			this->btn_add_flight = (gcnew System::Windows::Forms::Button());
			this->btn_add_admin = (gcnew System::Windows::Forms::Button());
			this->chat_list_panal = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->chat_bot_panal = (gcnew System::Windows::Forms::Panel());
			this->send_button = (gcnew System::Windows::Forms::Button());
			this->txtMessage = (gcnew System::Windows::Forms::TextBox());
			this->chatbox = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->add_flight_panel->SuspendLayout();
			this->add_plane_panel->SuspendLayout();
			this->add_admin_panel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->confirm_view))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pass_view))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pass_hide))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->confirm_hide))->BeginInit();
			this->search_plane_panel->SuspendLayout();
			this->search_flights_panel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->transfer_pictureBox))->BeginInit();
			this->home_pg_panel->SuspendLayout();
			this->chat_bot_panal->SuspendLayout();
			this->SuspendLayout();
			// 
			// add_flight_panel
			// 
			this->add_flight_panel->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->add_flight_panel->AutoSize = true;
			this->add_flight_panel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)),
				static_cast<System::Int32>(static_cast<System::Byte>(210)), static_cast<System::Int32>(static_cast<System::Byte>(216)), static_cast<System::Int32>(static_cast<System::Byte>(228)));
			this->add_flight_panel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->add_flight_panel->Controls->Add(this->flight_index);
			this->add_flight_panel->Controls->Add(this->add_flight_label);
			this->add_flight_panel->Controls->Add(this->time_departure);
			this->add_flight_panel->Controls->Add(this->business_price_textbox);
			this->add_flight_panel->Controls->Add(this->time_arrival);
			this->add_flight_panel->Controls->Add(this->dateTimePicker_departure);
			this->add_flight_panel->Controls->Add(this->dateTimePicker_arrival);
			this->add_flight_panel->Controls->Add(this->add_flight_button);
			this->add_flight_panel->Controls->Add(this->label_palne_code);
			this->add_flight_panel->Controls->Add(this->category_comboBox);
			this->add_flight_panel->Controls->Add(this->arrival_airport_textbox);
			this->add_flight_panel->Controls->Add(this->price);
			this->add_flight_panel->Controls->Add(this->arrival_date);
			this->add_flight_panel->Controls->Add(this->departure_date);
			this->add_flight_panel->Controls->Add(this->arrival_airport);
			this->add_flight_panel->Controls->Add(this->departure_airport_textbox);
			this->add_flight_panel->Controls->Add(this->departure_airport);
			this->add_flight_panel->Controls->Add(this->plane_code_textbox);
			this->add_flight_panel->Controls->Add(this->frist_class_price_textbox);
			this->add_flight_panel->Controls->Add(this->premium_economy_price_textbox);
			this->add_flight_panel->Controls->Add(this->economy_price_textbox);
			this->add_flight_panel->Controls->Add(this->update_flight);
			this->add_flight_panel->Location = System::Drawing::Point(1, 3);
			this->add_flight_panel->Name = L"add_flight_panel";
			this->add_flight_panel->Size = System::Drawing::Size(768, 690);
			this->add_flight_panel->TabIndex = 5;
			this->add_flight_panel->Visible = false;
			// 
			// flight_index
			// 
			this->flight_index->AutoSize = true;
			this->flight_index->Location = System::Drawing::Point(53, 33);
			this->flight_index->Name = L"flight_index";
			this->flight_index->Size = System::Drawing::Size(39, 16);
			this->flight_index->TabIndex = 24;
			this->flight_index->Text = L"index";
			this->flight_index->Visible = false;
			// 
			// add_flight_label
			// 
			this->add_flight_label->AutoSize = true;
			this->add_flight_label->BackColor = System::Drawing::Color::Transparent;
			this->add_flight_label->Font = (gcnew System::Drawing::Font(L"Segoe UI", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->add_flight_label->ForeColor = System::Drawing::Color::Navy;
			this->add_flight_label->Location = System::Drawing::Point(98, 46);
			this->add_flight_label->Name = L"add_flight_label";
			this->add_flight_label->Size = System::Drawing::Size(558, 41);
			this->add_flight_label->TabIndex = 23;
			this->add_flight_label->Text = L"ـــــــــــــــــــــــــــــــ     Add Flight     ــــــــــــــــــــــــــــــ"
				L"ـ";
			// 
			// time_departure
			// 
			this->time_departure->CalendarFont = (gcnew System::Drawing::Font(L"Segoe UI", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->time_departure->CalendarTitleBackColor = System::Drawing::SystemColors::ControlText;
			this->time_departure->CalendarTitleForeColor = System::Drawing::Color::Transparent;
			this->time_departure->CustomFormat = L"hh:mm tt";
			this->time_departure->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->time_departure->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->time_departure->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->time_departure->Location = System::Drawing::Point(535, 302);
			this->time_departure->Name = L"time_departure";
			this->time_departure->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->time_departure->ShowUpDown = true;
			this->time_departure->Size = System::Drawing::Size(192, 38);
			this->time_departure->TabIndex = 22;
			// 
			// business_price_textbox
			// 
			this->business_price_textbox->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->business_price_textbox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->business_price_textbox->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->business_price_textbox->ForeColor = System::Drawing::Color::Gray;
			this->business_price_textbox->Location = System::Drawing::Point(535, 525);
			this->business_price_textbox->Name = L"business_price_textbox";
			this->business_price_textbox->Size = System::Drawing::Size(192, 38);
			this->business_price_textbox->TabIndex = 20;
			this->business_price_textbox->Text = L"Enter Price";
			this->business_price_textbox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->business_price_textbox->Visible = false;
			this->business_price_textbox->Enter += gcnew System::EventHandler(this, &admin_home_page::business_price_textbox_Enter);
			this->business_price_textbox->Leave += gcnew System::EventHandler(this, &admin_home_page::business_price_textbox_Leave);
			// 
			// time_arrival
			// 
			this->time_arrival->CalendarFont = (gcnew System::Drawing::Font(L"Segoe UI", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->time_arrival->CalendarTitleBackColor = System::Drawing::SystemColors::ControlText;
			this->time_arrival->CalendarTitleForeColor = System::Drawing::Color::Transparent;
			this->time_arrival->CustomFormat = L"hh:mm tt";
			this->time_arrival->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->time_arrival->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->time_arrival->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->time_arrival->Location = System::Drawing::Point(535, 453);
			this->time_arrival->Name = L"time_arrival";
			this->time_arrival->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->time_arrival->ShowUpDown = true;
			this->time_arrival->Size = System::Drawing::Size(192, 38);
			this->time_arrival->TabIndex = 18;
			// 
			// dateTimePicker_departure
			// 
			this->dateTimePicker_departure->CalendarFont = (gcnew System::Drawing::Font(L"Segoe UI", 13.8F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->dateTimePicker_departure->CalendarTitleBackColor = System::Drawing::SystemColors::ControlText;
			this->dateTimePicker_departure->CalendarTitleForeColor = System::Drawing::Color::Transparent;
			this->dateTimePicker_departure->CustomFormat = L"ddd,dd/MMM/yyyy";
			this->dateTimePicker_departure->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->dateTimePicker_departure->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->dateTimePicker_departure->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->dateTimePicker_departure->Location = System::Drawing::Point(258, 302);
			this->dateTimePicker_departure->Name = L"dateTimePicker_departure";
			this->dateTimePicker_departure->Size = System::Drawing::Size(262, 38);
			this->dateTimePicker_departure->TabIndex = 17;
			this->dateTimePicker_departure->Enter += gcnew System::EventHandler(this, &admin_home_page::dateTimePicker_arrival_Leave);
			// 
			// dateTimePicker_arrival
			// 
			this->dateTimePicker_arrival->CustomFormat = L"ddd,dd/MMM/yyyy";
			this->dateTimePicker_arrival->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->dateTimePicker_arrival->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->dateTimePicker_arrival->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->dateTimePicker_arrival->Location = System::Drawing::Point(258, 454);
			this->dateTimePicker_arrival->Name = L"dateTimePicker_arrival";
			this->dateTimePicker_arrival->Size = System::Drawing::Size(262, 38);
			this->dateTimePicker_arrival->TabIndex = 4;
			// 
			// add_flight_button
			// 
			this->add_flight_button->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(7)), static_cast<System::Int32>(static_cast<System::Byte>(85)),
				static_cast<System::Int32>(static_cast<System::Byte>(184)));
			this->add_flight_button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->add_flight_button->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->add_flight_button->ForeColor = System::Drawing::Color::White;
			this->add_flight_button->Location = System::Drawing::Point(234, 615);
			this->add_flight_button->Name = L"add_flight_button";
			this->add_flight_button->Size = System::Drawing::Size(286, 51);
			this->add_flight_button->TabIndex = 16;
			this->add_flight_button->Text = L"Add Flight";
			this->add_flight_button->UseVisualStyleBackColor = false;
			this->add_flight_button->Click += gcnew System::EventHandler(this, &admin_home_page::add_flight_button_Click);
			// 
			// label_palne_code
			// 
			this->label_palne_code->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->label_palne_code->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label_palne_code->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label_palne_code->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_palne_code->ForeColor = System::Drawing::Color::Navy;
			this->label_palne_code->Location = System::Drawing::Point(27, 232);
			this->label_palne_code->Name = L"label_palne_code";
			this->label_palne_code->Size = System::Drawing::Size(225, 38);
			this->label_palne_code->TabIndex = 0;
			this->label_palne_code->Text = L"Plane code";
			this->label_palne_code->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// category_comboBox
			// 
			this->category_comboBox->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::SuggestAppend;
			this->category_comboBox->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::ListItems;
			this->category_comboBox->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->category_comboBox->ForeColor = System::Drawing::Color::Black;
			this->category_comboBox->FormattingEnabled = true;
			this->category_comboBox->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->category_comboBox->ItemHeight = 31;
			this->category_comboBox->Items->AddRange(gcnew cli::array< System::Object^  >(4) {
				L"Business", L"Economy", L"First Class",
					L"Premium Economy"
			});
			this->category_comboBox->Location = System::Drawing::Point(258, 524);
			this->category_comboBox->Name = L"category_comboBox";
			this->category_comboBox->Size = System::Drawing::Size(262, 39);
			this->category_comboBox->Sorted = true;
			this->category_comboBox->TabIndex = 4;
			this->category_comboBox->Tag = L"";
			this->category_comboBox->Text = L"Select Category";
			this->category_comboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &admin_home_page::category_comboBox_SelectedIndexChanged);
			// 
			// arrival_airport_textbox
			// 
			this->arrival_airport_textbox->AutoCompleteCustomSource->AddRange(gcnew cli::array< System::String^  >(1) { L"collection" });
			this->arrival_airport_textbox->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::SuggestAppend;
			this->arrival_airport_textbox->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::CustomSource;
			this->arrival_airport_textbox->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->arrival_airport_textbox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->arrival_airport_textbox->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->arrival_airport_textbox->ForeColor = System::Drawing::Color::Gray;
			this->arrival_airport_textbox->Location = System::Drawing::Point(258, 385);
			this->arrival_airport_textbox->Name = L"arrival_airport_textbox";
			this->arrival_airport_textbox->Size = System::Drawing::Size(469, 38);
			this->arrival_airport_textbox->TabIndex = 3;
			this->arrival_airport_textbox->Text = L"Enter Arrival Airport";
			this->arrival_airport_textbox->Enter += gcnew System::EventHandler(this, &admin_home_page::arrival_airport_textbox_Enter);
			this->arrival_airport_textbox->Leave += gcnew System::EventHandler(this, &admin_home_page::arrival_airport_textbox_Leave);
			// 
			// price
			// 
			this->price->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->price->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->price->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->price->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->price->ForeColor = System::Drawing::Color::Navy;
			this->price->Location = System::Drawing::Point(27, 526);
			this->price->Name = L"price";
			this->price->Size = System::Drawing::Size(225, 38);
			this->price->TabIndex = 14;
			this->price->Text = L"Price";
			this->price->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// arrival_date
			// 
			this->arrival_date->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->arrival_date->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->arrival_date->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->arrival_date->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->arrival_date->ForeColor = System::Drawing::Color::Navy;
			this->arrival_date->Location = System::Drawing::Point(27, 453);
			this->arrival_date->Name = L"arrival_date";
			this->arrival_date->Size = System::Drawing::Size(225, 38);
			this->arrival_date->TabIndex = 9;
			this->arrival_date->Text = L"Arrival Date";
			this->arrival_date->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// departure_date
			// 
			this->departure_date->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->departure_date->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->departure_date->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->departure_date->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->departure_date->ForeColor = System::Drawing::Color::Navy;
			this->departure_date->Location = System::Drawing::Point(27, 302);
			this->departure_date->Name = L"departure_date";
			this->departure_date->Size = System::Drawing::Size(225, 38);
			this->departure_date->TabIndex = 4;
			this->departure_date->Text = L"Departure Date";
			this->departure_date->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// arrival_airport
			// 
			this->arrival_airport->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->arrival_airport->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->arrival_airport->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->arrival_airport->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->arrival_airport->ForeColor = System::Drawing::Color::Navy;
			this->arrival_airport->Location = System::Drawing::Point(27, 385);
			this->arrival_airport->Name = L"arrival_airport";
			this->arrival_airport->Size = System::Drawing::Size(225, 38);
			this->arrival_airport->TabIndex = 2;
			this->arrival_airport->Text = L"Arrival Airport";
			this->arrival_airport->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// departure_airport_textbox
			// 
			this->departure_airport_textbox->AutoCompleteCustomSource->AddRange(gcnew cli::array< System::String^  >(1) { L"collection" });
			this->departure_airport_textbox->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::SuggestAppend;
			this->departure_airport_textbox->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::CustomSource;
			this->departure_airport_textbox->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->departure_airport_textbox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->departure_airport_textbox->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->departure_airport_textbox->ForeColor = System::Drawing::Color::Gray;
			this->departure_airport_textbox->Location = System::Drawing::Point(258, 162);
			this->departure_airport_textbox->Name = L"departure_airport_textbox";
			this->departure_airport_textbox->Size = System::Drawing::Size(469, 38);
			this->departure_airport_textbox->TabIndex = 1;
			this->departure_airport_textbox->Text = L"Enter Departure Airport";
			this->departure_airport_textbox->Enter += gcnew System::EventHandler(this, &admin_home_page::departure_airport_textbox_Enter);
			this->departure_airport_textbox->Leave += gcnew System::EventHandler(this, &admin_home_page::departure_airport_textbox_Leave);
			// 
			// departure_airport
			// 
			this->departure_airport->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->departure_airport->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->departure_airport->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->departure_airport->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->departure_airport->ForeColor = System::Drawing::Color::Navy;
			this->departure_airport->Location = System::Drawing::Point(27, 162);
			this->departure_airport->Name = L"departure_airport";
			this->departure_airport->Size = System::Drawing::Size(225, 38);
			this->departure_airport->TabIndex = 2;
			this->departure_airport->Text = L"Departure Airport";
			this->departure_airport->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// plane_code_textbox
			// 
			this->plane_code_textbox->AutoCompleteCustomSource->AddRange(gcnew cli::array< System::String^  >(1) { L"collection_p" });
			this->plane_code_textbox->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::SuggestAppend;
			this->plane_code_textbox->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::CustomSource;
			this->plane_code_textbox->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->plane_code_textbox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->plane_code_textbox->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->plane_code_textbox->ForeColor = System::Drawing::Color::Gray;
			this->plane_code_textbox->Location = System::Drawing::Point(258, 232);
			this->plane_code_textbox->Name = L"plane_code_textbox";
			this->plane_code_textbox->Size = System::Drawing::Size(469, 38);
			this->plane_code_textbox->TabIndex = 2;
			this->plane_code_textbox->Text = L"Enter Plane code";
			this->plane_code_textbox->Enter += gcnew System::EventHandler(this, &admin_home_page::plane_code_textbox_Enter);
			this->plane_code_textbox->Leave += gcnew System::EventHandler(this, &admin_home_page::plane_code_textbox_Leave);
			// 
			// frist_class_price_textbox
			// 
			this->frist_class_price_textbox->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->frist_class_price_textbox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->frist_class_price_textbox->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->frist_class_price_textbox->ForeColor = System::Drawing::Color::Gray;
			this->frist_class_price_textbox->Location = System::Drawing::Point(535, 525);
			this->frist_class_price_textbox->Name = L"frist_class_price_textbox";
			this->frist_class_price_textbox->Size = System::Drawing::Size(192, 38);
			this->frist_class_price_textbox->TabIndex = 21;
			this->frist_class_price_textbox->Text = L"Enter Price";
			this->frist_class_price_textbox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->frist_class_price_textbox->Visible = false;
			this->frist_class_price_textbox->Enter += gcnew System::EventHandler(this, &admin_home_page::frist_class_price_textbox_Enter);
			this->frist_class_price_textbox->Leave += gcnew System::EventHandler(this, &admin_home_page::frist_class_price_textbox_Leave);
			// 
			// premium_economy_price_textbox
			// 
			this->premium_economy_price_textbox->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->premium_economy_price_textbox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->premium_economy_price_textbox->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->premium_economy_price_textbox->ForeColor = System::Drawing::Color::Gray;
			this->premium_economy_price_textbox->Location = System::Drawing::Point(535, 525);
			this->premium_economy_price_textbox->Name = L"premium_economy_price_textbox";
			this->premium_economy_price_textbox->Size = System::Drawing::Size(192, 38);
			this->premium_economy_price_textbox->TabIndex = 19;
			this->premium_economy_price_textbox->Text = L"Enter Price";
			this->premium_economy_price_textbox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->premium_economy_price_textbox->Visible = false;
			this->premium_economy_price_textbox->Enter += gcnew System::EventHandler(this, &admin_home_page::premium_economy_price_textbox_Enter);
			this->premium_economy_price_textbox->Leave += gcnew System::EventHandler(this, &admin_home_page::premium_economy_price_textbox_Leave);
			// 
			// economy_price_textbox
			// 
			this->economy_price_textbox->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->economy_price_textbox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->economy_price_textbox->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->economy_price_textbox->ForeColor = System::Drawing::Color::Gray;
			this->economy_price_textbox->Location = System::Drawing::Point(535, 525);
			this->economy_price_textbox->Name = L"economy_price_textbox";
			this->economy_price_textbox->Size = System::Drawing::Size(192, 38);
			this->economy_price_textbox->TabIndex = 4;
			this->economy_price_textbox->Text = L"Enter Price";
			this->economy_price_textbox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->economy_price_textbox->Visible = false;
			this->economy_price_textbox->Enter += gcnew System::EventHandler(this, &admin_home_page::economy_price_textbox_Enter);
			this->economy_price_textbox->Leave += gcnew System::EventHandler(this, &admin_home_page::economy_price_textbox_Leave);
			// 
			// update_flight
			// 
			this->update_flight->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(7)), static_cast<System::Int32>(static_cast<System::Byte>(85)),
				static_cast<System::Int32>(static_cast<System::Byte>(184)));
			this->update_flight->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->update_flight->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Blue;
			this->update_flight->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->update_flight->Font = (gcnew System::Drawing::Font(L"Segoe UI Symbol", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->update_flight->ForeColor = System::Drawing::SystemColors::Window;
			this->update_flight->Location = System::Drawing::Point(234, 615);
			this->update_flight->Name = L"update_flight";
			this->update_flight->Size = System::Drawing::Size(286, 51);
			this->update_flight->TabIndex = 25;
			this->update_flight->Text = L"Update ";
			this->update_flight->UseVisualStyleBackColor = false;
			this->update_flight->Visible = false;
			this->update_flight->Click += gcnew System::EventHandler(this, &admin_home_page::update_flight_Click);
			// 
			// add_plane_panel
			// 
			this->add_plane_panel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)), static_cast<System::Int32>(static_cast<System::Byte>(210)),
				static_cast<System::Int32>(static_cast<System::Byte>(216)), static_cast<System::Int32>(static_cast<System::Byte>(228)));
			this->add_plane_panel->Controls->Add(this->plane_index);
			this->add_plane_panel->Controls->Add(this->add_plane_plane);
			this->add_plane_panel->Controls->Add(this->airport_label);
			this->add_plane_panel->Controls->Add(this->airport_textBox);
			this->add_plane_panel->Controls->Add(this->chairs_label);
			this->add_plane_panel->Controls->Add(this->rows_label);
			this->add_plane_panel->Controls->Add(this->model_label);
			this->add_plane_panel->Controls->Add(this->code_label);
			this->add_plane_panel->Controls->Add(this->chairs_textBox);
			this->add_plane_panel->Controls->Add(this->rows_textBox);
			this->add_plane_panel->Controls->Add(this->plane_model_textBox);
			this->add_plane_panel->Controls->Add(this->code_textBox);
			this->add_plane_panel->Controls->Add(this->add_plane_button);
			this->add_plane_panel->Controls->Add(this->update_plane);
			this->add_plane_panel->Location = System::Drawing::Point(775, 3);
			this->add_plane_panel->Name = L"add_plane_panel";
			this->add_plane_panel->Size = System::Drawing::Size(498, 466);
			this->add_plane_panel->TabIndex = 8;
			this->add_plane_panel->Visible = false;
			// 
			// plane_index
			// 
			this->plane_index->AutoSize = true;
			this->plane_index->Location = System::Drawing::Point(26, 22);
			this->plane_index->Name = L"plane_index";
			this->plane_index->Size = System::Drawing::Size(39, 16);
			this->plane_index->TabIndex = 19;
			this->plane_index->Text = L"index";
			this->plane_index->Visible = false;
			// 
			// add_plane_plane
			// 
			this->add_plane_plane->AutoSize = true;
			this->add_plane_plane->BackColor = System::Drawing::Color::Transparent;
			this->add_plane_plane->Font = (gcnew System::Drawing::Font(L"Segoe UI", 18, System::Drawing::FontStyle::Bold));
			this->add_plane_plane->ForeColor = System::Drawing::Color::Navy;
			this->add_plane_plane->Location = System::Drawing::Point(108, 14);
			this->add_plane_plane->Name = L"add_plane_plane";
			this->add_plane_plane->Size = System::Drawing::Size(282, 41);
			this->add_plane_plane->TabIndex = 8;
			this->add_plane_plane->Text = L" ــــــــ  Add Plane  ــــــــ";
			this->add_plane_plane->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// airport_label
			// 
			this->airport_label->AutoSize = true;
			this->airport_label->BackColor = System::Drawing::Color::Transparent;
			this->airport_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->airport_label->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(49)), static_cast<System::Int32>(static_cast<System::Byte>(52)),
				static_cast<System::Int32>(static_cast<System::Byte>(69)));
			this->airport_label->Location = System::Drawing::Point(33, 322);
			this->airport_label->Name = L"airport_label";
			this->airport_label->Size = System::Drawing::Size(76, 22);
			this->airport_label->TabIndex = 17;
			this->airport_label->Text = L"Air port";
			// 
			// airport_textBox
			// 
			this->airport_textBox->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::SuggestAppend;
			this->airport_textBox->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::CustomSource;
			this->airport_textBox->Font = (gcnew System::Drawing::Font(L"Tahoma", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->airport_textBox->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->airport_textBox->Location = System::Drawing::Point(33, 346);
			this->airport_textBox->Name = L"airport_textBox";
			this->airport_textBox->Size = System::Drawing::Size(434, 35);
			this->airport_textBox->TabIndex = 4;
			this->airport_textBox->Text = L"Air port";
			this->airport_textBox->Enter += gcnew System::EventHandler(this, &admin_home_page::airport_textBox_Enter);
			this->airport_textBox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &admin_home_page::code_textBox_KeyDown);
			this->airport_textBox->Leave += gcnew System::EventHandler(this, &admin_home_page::airport_textBox_Leave);
			// 
			// chairs_label
			// 
			this->chairs_label->AutoSize = true;
			this->chairs_label->BackColor = System::Drawing::Color::Transparent;
			this->chairs_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->chairs_label->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(49)), static_cast<System::Int32>(static_cast<System::Byte>(52)),
				static_cast<System::Int32>(static_cast<System::Byte>(69)));
			this->chairs_label->Location = System::Drawing::Point(33, 255);
			this->chairs_label->Name = L"chairs_label";
			this->chairs_label->Size = System::Drawing::Size(68, 22);
			this->chairs_label->TabIndex = 15;
			this->chairs_label->Text = L"Chairs";
			// 
			// rows_label
			// 
			this->rows_label->AutoSize = true;
			this->rows_label->BackColor = System::Drawing::Color::Transparent;
			this->rows_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->rows_label->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(49)), static_cast<System::Int32>(static_cast<System::Byte>(52)),
				static_cast<System::Int32>(static_cast<System::Byte>(69)));
			this->rows_label->Location = System::Drawing::Point(33, 189);
			this->rows_label->Name = L"rows_label";
			this->rows_label->Size = System::Drawing::Size(59, 22);
			this->rows_label->TabIndex = 14;
			this->rows_label->Text = L"Rows";
			// 
			// model_label
			// 
			this->model_label->AutoSize = true;
			this->model_label->BackColor = System::Drawing::Color::Transparent;
			this->model_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->model_label->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(49)), static_cast<System::Int32>(static_cast<System::Byte>(52)),
				static_cast<System::Int32>(static_cast<System::Byte>(69)));
			this->model_label->Location = System::Drawing::Point(33, 123);
			this->model_label->Name = L"model_label";
			this->model_label->Size = System::Drawing::Size(63, 22);
			this->model_label->TabIndex = 13;
			this->model_label->Text = L"Model";
			// 
			// code_label
			// 
			this->code_label->AutoSize = true;
			this->code_label->BackColor = System::Drawing::Color::Transparent;
			this->code_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->code_label->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(49)), static_cast<System::Int32>(static_cast<System::Byte>(52)),
				static_cast<System::Int32>(static_cast<System::Byte>(69)));
			this->code_label->Location = System::Drawing::Point(33, 56);
			this->code_label->Name = L"code_label";
			this->code_label->Size = System::Drawing::Size(57, 22);
			this->code_label->TabIndex = 12;
			this->code_label->Text = L"Code";
			// 
			// chairs_textBox
			// 
			this->chairs_textBox->Font = (gcnew System::Drawing::Font(L"Tahoma", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->chairs_textBox->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->chairs_textBox->Location = System::Drawing::Point(33, 281);
			this->chairs_textBox->Name = L"chairs_textBox";
			this->chairs_textBox->Size = System::Drawing::Size(434, 35);
			this->chairs_textBox->TabIndex = 3;
			this->chairs_textBox->Text = L"Num of chairs";
			this->chairs_textBox->Enter += gcnew System::EventHandler(this, &admin_home_page::chairs_textBox_Enter);
			this->chairs_textBox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &admin_home_page::code_textBox_KeyDown);
			this->chairs_textBox->Leave += gcnew System::EventHandler(this, &admin_home_page::chairs_textBox_Leave);
			// 
			// rows_textBox
			// 
			this->rows_textBox->Font = (gcnew System::Drawing::Font(L"Tahoma", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->rows_textBox->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->rows_textBox->Location = System::Drawing::Point(33, 216);
			this->rows_textBox->Name = L"rows_textBox";
			this->rows_textBox->Size = System::Drawing::Size(433, 35);
			this->rows_textBox->TabIndex = 2;
			this->rows_textBox->Text = L"Num of rows";
			this->rows_textBox->Enter += gcnew System::EventHandler(this, &admin_home_page::rows_textBox_Enter);
			this->rows_textBox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &admin_home_page::code_textBox_KeyDown);
			this->rows_textBox->Leave += gcnew System::EventHandler(this, &admin_home_page::rows_textBox_Leave);
			// 
			// plane_model_textBox
			// 
			this->plane_model_textBox->Font = (gcnew System::Drawing::Font(L"Tahoma", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->plane_model_textBox->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->plane_model_textBox->Location = System::Drawing::Point(33, 147);
			this->plane_model_textBox->Name = L"plane_model_textBox";
			this->plane_model_textBox->Size = System::Drawing::Size(433, 35);
			this->plane_model_textBox->TabIndex = 1;
			this->plane_model_textBox->Text = L"Model";
			this->plane_model_textBox->Enter += gcnew System::EventHandler(this, &admin_home_page::plane_model_textBox_Enter);
			this->plane_model_textBox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &admin_home_page::code_textBox_KeyDown);
			this->plane_model_textBox->Leave += gcnew System::EventHandler(this, &admin_home_page::plane_model_textBox_Leave);
			// 
			// code_textBox
			// 
			this->code_textBox->Font = (gcnew System::Drawing::Font(L"Tahoma", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->code_textBox->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->code_textBox->Location = System::Drawing::Point(33, 82);
			this->code_textBox->Name = L"code_textBox";
			this->code_textBox->Size = System::Drawing::Size(433, 35);
			this->code_textBox->TabIndex = 0;
			this->code_textBox->Text = L"Code";
			this->code_textBox->Enter += gcnew System::EventHandler(this, &admin_home_page::code_textBox_Enter);
			this->code_textBox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &admin_home_page::code_textBox_KeyDown);
			this->code_textBox->Leave += gcnew System::EventHandler(this, &admin_home_page::code_textBox_Leave);
			// 
			// add_plane_button
			// 
			this->add_plane_button->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(7)), static_cast<System::Int32>(static_cast<System::Byte>(85)),
				static_cast<System::Int32>(static_cast<System::Byte>(184)));
			this->add_plane_button->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->add_plane_button->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Blue;
			this->add_plane_button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->add_plane_button->Font = (gcnew System::Drawing::Font(L"Segoe UI Symbol", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->add_plane_button->ForeColor = System::Drawing::SystemColors::Window;
			this->add_plane_button->Location = System::Drawing::Point(15, 398);
			this->add_plane_button->Name = L"add_plane_button";
			this->add_plane_button->Size = System::Drawing::Size(469, 49);
			this->add_plane_button->TabIndex = 5;
			this->add_plane_button->Text = L"Add Plane";
			this->add_plane_button->UseVisualStyleBackColor = false;
			this->add_plane_button->Click += gcnew System::EventHandler(this, &admin_home_page::add_plane_button_Click);
			this->add_plane_button->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &admin_home_page::code_textBox_KeyDown);
			// 
			// update_plane
			// 
			this->update_plane->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(7)), static_cast<System::Int32>(static_cast<System::Byte>(85)),
				static_cast<System::Int32>(static_cast<System::Byte>(184)));
			this->update_plane->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->update_plane->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Blue;
			this->update_plane->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->update_plane->Font = (gcnew System::Drawing::Font(L"Segoe UI Symbol", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->update_plane->ForeColor = System::Drawing::SystemColors::Window;
			this->update_plane->Location = System::Drawing::Point(15, 398);
			this->update_plane->Name = L"update_plane";
			this->update_plane->Size = System::Drawing::Size(469, 49);
			this->update_plane->TabIndex = 18;
			this->update_plane->Text = L"Update ";
			this->update_plane->UseVisualStyleBackColor = false;
			this->update_plane->Visible = false;
			this->update_plane->Click += gcnew System::EventHandler(this, &admin_home_page::update_plane_Click);
			// 
			// add_admin_panel
			// 
			this->add_admin_panel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)), static_cast<System::Int32>(static_cast<System::Byte>(210)),
				static_cast<System::Int32>(static_cast<System::Byte>(216)), static_cast<System::Int32>(static_cast<System::Byte>(228)));
			this->add_admin_panel->Controls->Add(this->add_admin_label);
			this->add_admin_panel->Controls->Add(this->confirm_view);
			this->add_admin_panel->Controls->Add(this->pass_view);
			this->add_admin_panel->Controls->Add(this->add_admin_button);
			this->add_admin_panel->Controls->Add(this->ad_confirm_label);
			this->add_admin_panel->Controls->Add(this->ad_name_label);
			this->add_admin_panel->Controls->Add(this->ad_user_name_textBox);
			this->add_admin_panel->Controls->Add(this->ad_phone_label);
			this->add_admin_panel->Controls->Add(this->ad_password_label);
			this->add_admin_panel->Controls->Add(this->ad_phone_textBox);
			this->add_admin_panel->Controls->Add(this->ad_user_name_label);
			this->add_admin_panel->Controls->Add(this->ad_name_textBox);
			this->add_admin_panel->Controls->Add(this->pass_hide);
			this->add_admin_panel->Controls->Add(this->confirm_hide);
			this->add_admin_panel->Controls->Add(this->ad_password_textBox);
			this->add_admin_panel->Controls->Add(this->ad_confirm_textBox);
			this->add_admin_panel->Location = System::Drawing::Point(775, 475);
			this->add_admin_panel->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->add_admin_panel->Name = L"add_admin_panel";
			this->add_admin_panel->Size = System::Drawing::Size(531, 577);
			this->add_admin_panel->TabIndex = 13;
			this->add_admin_panel->Visible = false;
			// 
			// add_admin_label
			// 
			this->add_admin_label->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->add_admin_label->AutoSize = true;
			this->add_admin_label->BackColor = System::Drawing::Color::Transparent;
			this->add_admin_label->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->add_admin_label->ForeColor = System::Drawing::Color::White;
			this->add_admin_label->Location = System::Drawing::Point(21, 58);
			this->add_admin_label->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->add_admin_label->Name = L"add_admin_label";
			this->add_admin_label->Size = System::Drawing::Size(496, 76);
			this->add_admin_label->TabIndex = 12;
			this->add_admin_label->Text = L"Add New Admin";
			// 
			// confirm_view
			// 
			this->confirm_view->BackColor = System::Drawing::Color::White;
			this->confirm_view->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"confirm_view.Image")));
			this->confirm_view->Location = System::Drawing::Point(479, 371);
			this->confirm_view->Name = L"confirm_view";
			this->confirm_view->Size = System::Drawing::Size(33, 30);
			this->confirm_view->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->confirm_view->TabIndex = 14;
			this->confirm_view->TabStop = false;
			this->confirm_view->Click += gcnew System::EventHandler(this, &admin_home_page::confirm_view_Click);
			// 
			// pass_view
			// 
			this->pass_view->BackColor = System::Drawing::Color::White;
			this->pass_view->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pass_view.Image")));
			this->pass_view->Location = System::Drawing::Point(479, 302);
			this->pass_view->Name = L"pass_view";
			this->pass_view->Size = System::Drawing::Size(33, 30);
			this->pass_view->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pass_view->TabIndex = 13;
			this->pass_view->TabStop = false;
			this->pass_view->Click += gcnew System::EventHandler(this, &admin_home_page::pass_view_Click);
			// 
			// add_admin_button
			// 
			this->add_admin_button->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->add_admin_button->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(7)), static_cast<System::Int32>(static_cast<System::Byte>(85)),
				static_cast<System::Int32>(static_cast<System::Byte>(184)));
			this->add_admin_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->add_admin_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->add_admin_button->ForeColor = System::Drawing::Color::White;
			this->add_admin_button->Location = System::Drawing::Point(55, 511);
			this->add_admin_button->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->add_admin_button->Name = L"add_admin_button";
			this->add_admin_button->Size = System::Drawing::Size(428, 45);
			this->add_admin_button->TabIndex = 8;
			this->add_admin_button->Text = L"Add Admin";
			this->add_admin_button->UseVisualStyleBackColor = false;
			this->add_admin_button->Click += gcnew System::EventHandler(this, &admin_home_page::add_admin_button_Click);
			this->add_admin_button->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &admin_home_page::ad_name_textBox_KeyDown);
			// 
			// ad_confirm_label
			// 
			this->ad_confirm_label->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->ad_confirm_label->AutoSize = true;
			this->ad_confirm_label->BackColor = System::Drawing::Color::Transparent;
			this->ad_confirm_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ad_confirm_label->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(49)), static_cast<System::Int32>(static_cast<System::Byte>(52)),
				static_cast<System::Int32>(static_cast<System::Byte>(69)));
			this->ad_confirm_label->Location = System::Drawing::Point(22, 346);
			this->ad_confirm_label->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->ad_confirm_label->Name = L"ad_confirm_label";
			this->ad_confirm_label->Size = System::Drawing::Size(129, 22);
			this->ad_confirm_label->TabIndex = 10;
			this->ad_confirm_label->Text = L"Confirm Pass";
			// 
			// ad_name_label
			// 
			this->ad_name_label->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->ad_name_label->AutoSize = true;
			this->ad_name_label->BackColor = System::Drawing::Color::Transparent;
			this->ad_name_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ad_name_label->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(49)), static_cast<System::Int32>(static_cast<System::Byte>(52)),
				static_cast<System::Int32>(static_cast<System::Byte>(69)));
			this->ad_name_label->Location = System::Drawing::Point(22, 139);
			this->ad_name_label->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->ad_name_label->Name = L"ad_name_label";
			this->ad_name_label->Size = System::Drawing::Size(61, 22);
			this->ad_name_label->TabIndex = 4;
			this->ad_name_label->Text = L"Name";
			// 
			// ad_user_name_textBox
			// 
			this->ad_user_name_textBox->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->ad_user_name_textBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->ad_user_name_textBox->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->ad_user_name_textBox->Location = System::Drawing::Point(26, 233);
			this->ad_user_name_textBox->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->ad_user_name_textBox->Name = L"ad_user_name_textBox";
			this->ad_user_name_textBox->Size = System::Drawing::Size(486, 38);
			this->ad_user_name_textBox->TabIndex = 1;
			this->ad_user_name_textBox->Text = L"Enter Admin Username";
			this->ad_user_name_textBox->Enter += gcnew System::EventHandler(this, &admin_home_page::ad_user_name_textBox_Enter);
			this->ad_user_name_textBox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &admin_home_page::ad_name_textBox_KeyDown);
			this->ad_user_name_textBox->Leave += gcnew System::EventHandler(this, &admin_home_page::ad_user_name_textBox_Leave);
			// 
			// ad_phone_label
			// 
			this->ad_phone_label->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->ad_phone_label->AutoSize = true;
			this->ad_phone_label->BackColor = System::Drawing::Color::Transparent;
			this->ad_phone_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ad_phone_label->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(49)), static_cast<System::Int32>(static_cast<System::Byte>(52)),
				static_cast<System::Int32>(static_cast<System::Byte>(69)));
			this->ad_phone_label->Location = System::Drawing::Point(22, 415);
			this->ad_phone_label->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->ad_phone_label->Name = L"ad_phone_label";
			this->ad_phone_label->Size = System::Drawing::Size(67, 22);
			this->ad_phone_label->TabIndex = 7;
			this->ad_phone_label->Text = L"Phone";
			// 
			// ad_password_label
			// 
			this->ad_password_label->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->ad_password_label->AutoSize = true;
			this->ad_password_label->BackColor = System::Drawing::Color::Transparent;
			this->ad_password_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ad_password_label->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(49)),
				static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(69)));
			this->ad_password_label->Location = System::Drawing::Point(22, 277);
			this->ad_password_label->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->ad_password_label->Name = L"ad_password_label";
			this->ad_password_label->Size = System::Drawing::Size(97, 22);
			this->ad_password_label->TabIndex = 6;
			this->ad_password_label->Text = L"Password";
			// 
			// ad_phone_textBox
			// 
			this->ad_phone_textBox->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->ad_phone_textBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->ad_phone_textBox->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->ad_phone_textBox->Location = System::Drawing::Point(26, 440);
			this->ad_phone_textBox->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->ad_phone_textBox->Name = L"ad_phone_textBox";
			this->ad_phone_textBox->Size = System::Drawing::Size(486, 38);
			this->ad_phone_textBox->TabIndex = 4;
			this->ad_phone_textBox->Text = L"Enter Phone Number";
			this->ad_phone_textBox->Enter += gcnew System::EventHandler(this, &admin_home_page::ad_phone_textBox_Enter);
			this->ad_phone_textBox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &admin_home_page::ad_name_textBox_KeyDown);
			this->ad_phone_textBox->Leave += gcnew System::EventHandler(this, &admin_home_page::ad_phone_textBox_Leave);
			// 
			// ad_user_name_label
			// 
			this->ad_user_name_label->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->ad_user_name_label->AutoSize = true;
			this->ad_user_name_label->BackColor = System::Drawing::Color::Transparent;
			this->ad_user_name_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ad_user_name_label->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(49)),
				static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(69)));
			this->ad_user_name_label->Location = System::Drawing::Point(22, 208);
			this->ad_user_name_label->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->ad_user_name_label->Name = L"ad_user_name_label";
			this->ad_user_name_label->Size = System::Drawing::Size(106, 22);
			this->ad_user_name_label->TabIndex = 5;
			this->ad_user_name_label->Text = L"User name";
			// 
			// ad_name_textBox
			// 
			this->ad_name_textBox->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->ad_name_textBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ad_name_textBox->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->ad_name_textBox->Location = System::Drawing::Point(26, 164);
			this->ad_name_textBox->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->ad_name_textBox->Name = L"ad_name_textBox";
			this->ad_name_textBox->Size = System::Drawing::Size(486, 38);
			this->ad_name_textBox->TabIndex = 0;
			this->ad_name_textBox->Text = L"Enter Admin Name";
			this->ad_name_textBox->Enter += gcnew System::EventHandler(this, &admin_home_page::ad_name_textBox_Enter);
			this->ad_name_textBox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &admin_home_page::ad_name_textBox_KeyDown);
			this->ad_name_textBox->Leave += gcnew System::EventHandler(this, &admin_home_page::ad_name_textBox_Leave);
			// 
			// pass_hide
			// 
			this->pass_hide->BackColor = System::Drawing::Color::White;
			this->pass_hide->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pass_hide.Image")));
			this->pass_hide->Location = System::Drawing::Point(479, 302);
			this->pass_hide->Name = L"pass_hide";
			this->pass_hide->Size = System::Drawing::Size(33, 30);
			this->pass_hide->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pass_hide->TabIndex = 21;
			this->pass_hide->TabStop = false;
			this->pass_hide->Click += gcnew System::EventHandler(this, &admin_home_page::pass_hide_Click);
			// 
			// confirm_hide
			// 
			this->confirm_hide->BackColor = System::Drawing::Color::White;
			this->confirm_hide->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"confirm_hide.Image")));
			this->confirm_hide->Location = System::Drawing::Point(479, 371);
			this->confirm_hide->Name = L"confirm_hide";
			this->confirm_hide->Size = System::Drawing::Size(33, 30);
			this->confirm_hide->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->confirm_hide->TabIndex = 20;
			this->confirm_hide->TabStop = false;
			this->confirm_hide->Click += gcnew System::EventHandler(this, &admin_home_page::confirm_hide_Click);
			// 
			// ad_password_textBox
			// 
			this->ad_password_textBox->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->ad_password_textBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->ad_password_textBox->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->ad_password_textBox->Location = System::Drawing::Point(26, 302);
			this->ad_password_textBox->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->ad_password_textBox->Name = L"ad_password_textBox";
			this->ad_password_textBox->Size = System::Drawing::Size(486, 38);
			this->ad_password_textBox->TabIndex = 2;
			this->ad_password_textBox->Text = L"Enter Password";
			this->ad_password_textBox->Enter += gcnew System::EventHandler(this, &admin_home_page::ad_password_textBox_Enter);
			this->ad_password_textBox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &admin_home_page::ad_name_textBox_KeyDown);
			this->ad_password_textBox->Leave += gcnew System::EventHandler(this, &admin_home_page::ad_password_textBox_Leave);
			// 
			// ad_confirm_textBox
			// 
			this->ad_confirm_textBox->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->ad_confirm_textBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->ad_confirm_textBox->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->ad_confirm_textBox->Location = System::Drawing::Point(26, 371);
			this->ad_confirm_textBox->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->ad_confirm_textBox->Name = L"ad_confirm_textBox";
			this->ad_confirm_textBox->Size = System::Drawing::Size(486, 38);
			this->ad_confirm_textBox->TabIndex = 3;
			this->ad_confirm_textBox->Text = L"Confirm Password";
			this->ad_confirm_textBox->Enter += gcnew System::EventHandler(this, &admin_home_page::ad_confirm_textBox_Enter);
			this->ad_confirm_textBox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &admin_home_page::ad_name_textBox_KeyDown);
			this->ad_confirm_textBox->Leave += gcnew System::EventHandler(this, &admin_home_page::ad_confirm_textBox_Leave);
			// 
			// search_plane_panel
			// 
			this->search_plane_panel->AutoSize = true;
			this->search_plane_panel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(180)),
				static_cast<System::Int32>(static_cast<System::Byte>(250)), static_cast<System::Int32>(static_cast<System::Byte>(250)), static_cast<System::Int32>(static_cast<System::Byte>(250)));
			this->search_plane_panel->Controls->Add(this->no_results);
			this->search_plane_panel->Controls->Add(this->search_results);
			this->search_plane_panel->Controls->Add(this->flowLayoutPanel1);
			this->search_plane_panel->Controls->Add(this->by_code);
			this->search_plane_panel->Controls->Add(this->by_model);
			this->search_plane_panel->Controls->Add(this->search_bar);
			this->search_plane_panel->Location = System::Drawing::Point(141, 25);
			this->search_plane_panel->Name = L"search_plane_panel";
			this->search_plane_panel->Size = System::Drawing::Size(1642, 1004);
			this->search_plane_panel->TabIndex = 14;
			this->search_plane_panel->Visible = false;
			// 
			// no_results
			// 
			this->no_results->AutoSize = true;
			this->no_results->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(180)), static_cast<System::Int32>(static_cast<System::Byte>(250)),
				static_cast<System::Int32>(static_cast<System::Byte>(250)), static_cast<System::Int32>(static_cast<System::Byte>(250)));
			this->no_results->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->no_results->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->no_results->Location = System::Drawing::Point(661, 497);
			this->no_results->Name = L"no_results";
			this->no_results->Size = System::Drawing::Size(327, 46);
			this->no_results->TabIndex = 0;
			this->no_results->Text = L"No results found";
			// 
			// search_results
			// 
			this->search_results->AutoSize = true;
			this->search_results->BackColor = System::Drawing::Color::Transparent;
			this->search_results->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->search_results->Location = System::Drawing::Point(942, 40);
			this->search_results->Name = L"search_results";
			this->search_results->Size = System::Drawing::Size(0, 32);
			this->search_results->TabIndex = 7;
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->AutoScroll = true;
			this->flowLayoutPanel1->Location = System::Drawing::Point(36, 101);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(1576, 820);
			this->flowLayoutPanel1->TabIndex = 6;
			// 
			// by_code
			// 
			this->by_code->AutoSize = true;
			this->by_code->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(250)),
				static_cast<System::Int32>(static_cast<System::Byte>(250)), static_cast<System::Int32>(static_cast<System::Byte>(250)));
			this->by_code->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->by_code->Location = System::Drawing::Point(554, 44);
			this->by_code->Name = L"by_code";
			this->by_code->Size = System::Drawing::Size(160, 24);
			this->by_code->TabIndex = 4;
			this->by_code->TabStop = true;
			this->by_code->Text = L"Search by code";
			this->by_code->UseVisualStyleBackColor = false;
			this->by_code->CheckedChanged += gcnew System::EventHandler(this, &admin_home_page::by_code_CheckedChanged);
			// 
			// by_model
			// 
			this->by_model->AutoSize = true;
			this->by_model->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(250)),
				static_cast<System::Int32>(static_cast<System::Byte>(250)), static_cast<System::Int32>(static_cast<System::Byte>(250)));
			this->by_model->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->by_model->Location = System::Drawing::Point(741, 44);
			this->by_model->Name = L"by_model";
			this->by_model->Size = System::Drawing::Size(170, 24);
			this->by_model->TabIndex = 5;
			this->by_model->TabStop = true;
			this->by_model->Text = L"Search by model";
			this->by_model->UseVisualStyleBackColor = false;
			this->by_model->CheckedChanged += gcnew System::EventHandler(this, &admin_home_page::by_model_CheckedChanged);
			// 
			// search_bar
			// 
			this->search_bar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->search_bar->Location = System::Drawing::Point(26, 37);
			this->search_bar->Name = L"search_bar";
			this->search_bar->Size = System::Drawing::Size(494, 38);
			this->search_bar->TabIndex = 2;
			this->search_bar->TextChanged += gcnew System::EventHandler(this, &admin_home_page::search_bar_TextChanged);
			// 
			// search_flights_panel
			// 
			this->search_flights_panel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)),
				static_cast<System::Int32>(static_cast<System::Byte>(210)), static_cast<System::Int32>(static_cast<System::Byte>(216)), static_cast<System::Int32>(static_cast<System::Byte>(228)));
			this->search_flights_panel->Controls->Add(this->transfer_pictureBox);
			this->search_flights_panel->Controls->Add(this->no_flights_found);
			this->search_flights_panel->Controls->Add(this->search);
			this->search_flights_panel->Controls->Add(this->departure_date_search);
			this->search_flights_panel->Controls->Add(this->flights_layout_panel);
			this->search_flights_panel->Controls->Add(this->dep_city_label);
			this->search_flights_panel->Controls->Add(this->dep_date_label);
			this->search_flights_panel->Controls->Add(this->arrival_city_label);
			this->search_flights_panel->Controls->Add(this->d_airport);
			this->search_flights_panel->Controls->Add(this->a_airport);
			this->search_flights_panel->Location = System::Drawing::Point(149, 33);
			this->search_flights_panel->Name = L"search_flights_panel";
			this->search_flights_panel->Size = System::Drawing::Size(1642, 1004);
			this->search_flights_panel->TabIndex = 19;
			this->search_flights_panel->Visible = false;
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
			this->transfer_pictureBox->Click += gcnew System::EventHandler(this, &admin_home_page::transfer_pictureBox_Click);
			// 
			// no_flights_found
			// 
			this->no_flights_found->AutoSize = true;
			this->no_flights_found->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(180)),
				static_cast<System::Int32>(static_cast<System::Byte>(250)), static_cast<System::Int32>(static_cast<System::Byte>(250)), static_cast<System::Int32>(static_cast<System::Byte>(250)));
			this->no_flights_found->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 25.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->no_flights_found->ForeColor = System::Drawing::SystemColors::ActiveBorder;
			this->no_flights_found->Location = System::Drawing::Point(643, 557);
			this->no_flights_found->Name = L"no_flights_found";
			this->no_flights_found->Size = System::Drawing::Size(337, 51);
			this->no_flights_found->TabIndex = 21;
			this->no_flights_found->Text = L"No flights found";
			this->no_flights_found->Visible = false;
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
			this->search->Click += gcnew System::EventHandler(this, &admin_home_page::search_Click);
			// 
			// departure_date_search
			// 
			this->departure_date_search->CalendarFont = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->departure_date_search->CustomFormat = L"ddd,dd/MMM/yyyy";
			this->departure_date_search->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->departure_date_search->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->departure_date_search->Location = System::Drawing::Point(1002, 123);
			this->departure_date_search->MinDate = System::DateTime(2026, 4, 12, 16, 14, 30, 260);
			this->departure_date_search->Name = L"departure_date_search";
			this->departure_date_search->Size = System::Drawing::Size(309, 34);
			this->departure_date_search->TabIndex = 17;
			this->departure_date_search->Value = System::DateTime(2026, 4, 12, 16, 14, 30, 260);
			// 
			// flights_layout_panel
			// 
			this->flights_layout_panel->AutoScroll = true;
			this->flights_layout_panel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(180)),
				static_cast<System::Int32>(static_cast<System::Byte>(250)), static_cast<System::Int32>(static_cast<System::Byte>(250)), static_cast<System::Int32>(static_cast<System::Byte>(250)));
			this->flights_layout_panel->Location = System::Drawing::Point(31, 173);
			this->flights_layout_panel->Name = L"flights_layout_panel";
			this->flights_layout_panel->Size = System::Drawing::Size(1576, 768);
			this->flights_layout_panel->TabIndex = 14;
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
			// open_home_pg
			// 
			this->open_home_pg->AutoSize = true;
			this->open_home_pg->BackColor = System::Drawing::Color::Transparent;
			this->open_home_pg->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->open_home_pg->LinkColor = System::Drawing::Color::Navy;
			this->open_home_pg->Location = System::Drawing::Point(15, 50);
			this->open_home_pg->Name = L"open_home_pg";
			this->open_home_pg->Size = System::Drawing::Size(167, 31);
			this->open_home_pg->TabIndex = 20;
			this->open_home_pg->TabStop = true;
			this->open_home_pg->Text = L"<--home page";
			this->open_home_pg->Visible = false;
			this->open_home_pg->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &admin_home_page::open_home_pg_LinkClicked);
			// 
			// home_pg_panel
			// 
			this->home_pg_panel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)), static_cast<System::Int32>(static_cast<System::Byte>(210)),
				static_cast<System::Int32>(static_cast<System::Byte>(216)), static_cast<System::Int32>(static_cast<System::Byte>(228)));
			this->home_pg_panel->Controls->Add(this->btn_customer_service);
			this->home_pg_panel->Controls->Add(this->btn_add_plane);
			this->home_pg_panel->Controls->Add(this->title);
			this->home_pg_panel->Controls->Add(this->btn_search_flights);
			this->home_pg_panel->Controls->Add(this->welcome);
			this->home_pg_panel->Controls->Add(this->btn_search_planes);
			this->home_pg_panel->Controls->Add(this->btn_add_flight);
			this->home_pg_panel->Controls->Add(this->btn_add_admin);
			this->home_pg_panel->Location = System::Drawing::Point(222, 58);
			this->home_pg_panel->Name = L"home_pg_panel";
			this->home_pg_panel->Size = System::Drawing::Size(1612, 938);
			this->home_pg_panel->TabIndex = 21;
			// 
			// btn_customer_service
			// 
			this->btn_customer_service->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn_customer_service->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(85)), static_cast<System::Int32>(static_cast<System::Byte>(170)));
			this->btn_customer_service->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_customer_service->FlatAppearance->BorderSize = 0;
			this->btn_customer_service->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_customer_service->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_customer_service->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->btn_customer_service->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_customer_service.Image")));
			this->btn_customer_service->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->btn_customer_service->Location = System::Drawing::Point(1231, 581);
			this->btn_customer_service->Name = L"btn_customer_service";
			this->btn_customer_service->Size = System::Drawing::Size(308, 272);
			this->btn_customer_service->TabIndex = 7;
			this->btn_customer_service->Text = L"Chats\r\n__________\r\nCustomer service";
			this->btn_customer_service->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->btn_customer_service->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageAboveText;
			this->btn_customer_service->UseVisualStyleBackColor = false;
			this->btn_customer_service->Click += gcnew System::EventHandler(this, &admin_home_page::btn_customer_service_Click);
			// 
			// btn_add_plane
			// 
			this->btn_add_plane->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn_add_plane->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(85)),
				static_cast<System::Int32>(static_cast<System::Byte>(170)));
			this->btn_add_plane->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_add_plane->FlatAppearance->BorderSize = 0;
			this->btn_add_plane->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_add_plane->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_add_plane->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->btn_add_plane->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_add_plane.Image")));
			this->btn_add_plane->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->btn_add_plane->Location = System::Drawing::Point(673, 232);
			this->btn_add_plane->Name = L"btn_add_plane";
			this->btn_add_plane->Size = System::Drawing::Size(308, 272);
			this->btn_add_plane->TabIndex = 3;
			this->btn_add_plane->Text = L"Add Plane\r\n__________\r\nregister new aircraft";
			this->btn_add_plane->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->btn_add_plane->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageAboveText;
			this->btn_add_plane->UseVisualStyleBackColor = false;
			this->btn_add_plane->Click += gcnew System::EventHandler(this, &admin_home_page::btn_add_plane_Click);
			// 
			// title
			// 
			this->title->AutoSize = true;
			this->title->BackColor = System::Drawing::Color::Transparent;
			this->title->Font = (gcnew System::Drawing::Font(L"Segoe UI", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->title->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->title->Location = System::Drawing::Point(361, 44);
			this->title->Name = L"title";
			this->title->Size = System::Drawing::Size(947, 54);
			this->title->TabIndex = 0;
			this->title->Text = L"___________Airline Management System____________";
			// 
			// btn_search_flights
			// 
			this->btn_search_flights->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn_search_flights->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(85)), static_cast<System::Int32>(static_cast<System::Byte>(170)));
			this->btn_search_flights->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_search_flights->FlatAppearance->BorderSize = 0;
			this->btn_search_flights->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_search_flights->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_search_flights->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->btn_search_flights->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_search_flights.Image")));
			this->btn_search_flights->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->btn_search_flights->Location = System::Drawing::Point(673, 586);
			this->btn_search_flights->Name = L"btn_search_flights";
			this->btn_search_flights->Size = System::Drawing::Size(308, 272);
			this->btn_search_flights->TabIndex = 6;
			this->btn_search_flights->Text = L"\r\nsearch flights\r\n__________\r\nsearch in flights";
			this->btn_search_flights->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->btn_search_flights->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageAboveText;
			this->btn_search_flights->UseVisualStyleBackColor = false;
			this->btn_search_flights->Click += gcnew System::EventHandler(this, &admin_home_page::btn_search_flights_Click);
			// 
			// welcome
			// 
			this->welcome->AutoSize = true;
			this->welcome->BackColor = System::Drawing::Color::Transparent;
			this->welcome->Font = (gcnew System::Drawing::Font(L"Segoe UI", 28.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->welcome->ForeColor = System::Drawing::SystemColors::Window;
			this->welcome->Location = System::Drawing::Point(579, 143);
			this->welcome->Name = L"welcome";
			this->welcome->Size = System::Drawing::Size(257, 62);
			this->welcome->TabIndex = 2;
			this->welcome->Text = L"Welcome, ";
			// 
			// btn_search_planes
			// 
			this->btn_search_planes->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn_search_planes->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(85)),
				static_cast<System::Int32>(static_cast<System::Byte>(170)));
			this->btn_search_planes->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_search_planes->FlatAppearance->BorderSize = 0;
			this->btn_search_planes->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_search_planes->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_search_planes->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->btn_search_planes->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_search_planes.Image")));
			this->btn_search_planes->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->btn_search_planes->Location = System::Drawing::Point(115, 586);
			this->btn_search_planes->Name = L"btn_search_planes";
			this->btn_search_planes->Size = System::Drawing::Size(308, 272);
			this->btn_search_planes->TabIndex = 5;
			this->btn_search_planes->Text = L"search planes\r\n__________\r\nsearch in planes";
			this->btn_search_planes->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->btn_search_planes->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageAboveText;
			this->btn_search_planes->UseVisualStyleBackColor = false;
			this->btn_search_planes->Click += gcnew System::EventHandler(this, &admin_home_page::btn_search_planes_Click);
			// 
			// btn_add_flight
			// 
			this->btn_add_flight->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn_add_flight->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(85)),
				static_cast<System::Int32>(static_cast<System::Byte>(170)));
			this->btn_add_flight->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_add_flight->FlatAppearance->BorderSize = 0;
			this->btn_add_flight->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_add_flight->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_add_flight->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->btn_add_flight->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_add_flight.Image")));
			this->btn_add_flight->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->btn_add_flight->Location = System::Drawing::Point(1231, 232);
			this->btn_add_flight->Name = L"btn_add_flight";
			this->btn_add_flight->Size = System::Drawing::Size(308, 272);
			this->btn_add_flight->TabIndex = 4;
			this->btn_add_flight->Text = L"Add flight\r\n__________\r\nregister new flight\r\n";
			this->btn_add_flight->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->btn_add_flight->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageAboveText;
			this->btn_add_flight->UseVisualStyleBackColor = false;
			this->btn_add_flight->Click += gcnew System::EventHandler(this, &admin_home_page::btn_add_flight_Click);
			// 
			// btn_add_admin
			// 
			this->btn_add_admin->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn_add_admin->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(85)),
				static_cast<System::Int32>(static_cast<System::Byte>(170)));
			this->btn_add_admin->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_add_admin->FlatAppearance->BorderSize = 0;
			this->btn_add_admin->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_add_admin->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_add_admin->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->btn_add_admin->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_add_admin.Image")));
			this->btn_add_admin->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->btn_add_admin->Location = System::Drawing::Point(115, 232);
			this->btn_add_admin->Name = L"btn_add_admin";
			this->btn_add_admin->Size = System::Drawing::Size(308, 272);
			this->btn_add_admin->TabIndex = 1;
			this->btn_add_admin->Text = L"Add admin\r\n__________\r\nregister new admin";
			this->btn_add_admin->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->btn_add_admin->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageAboveText;
			this->btn_add_admin->UseVisualStyleBackColor = false;
			this->btn_add_admin->Click += gcnew System::EventHandler(this, &admin_home_page::btn_add_admin_Click);
			// 
			// chat_list_panal
			// 
			this->chat_list_panal->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(10)), static_cast<System::Int32>(static_cast<System::Byte>(25)),
				static_cast<System::Int32>(static_cast<System::Byte>(40)));
			this->chat_list_panal->Location = System::Drawing::Point(0, 0);
			this->chat_list_panal->Name = L"chat_list_panal";
			this->chat_list_panal->Size = System::Drawing::Size(317, 884);
			this->chat_list_panal->TabIndex = 0;
			// 
			// chat_bot_panal
			// 
			this->chat_bot_panal->BackColor = System::Drawing::Color::Transparent;
			this->chat_bot_panal->Controls->Add(this->send_button);
			this->chat_bot_panal->Controls->Add(this->txtMessage);
			this->chat_bot_panal->Controls->Add(this->chatbox);
			this->chat_bot_panal->Controls->Add(this->chat_list_panal);
			this->chat_bot_panal->Location = System::Drawing::Point(0, 0);
			this->chat_bot_panal->Name = L"chat_bot_panal";
			this->chat_bot_panal->Size = System::Drawing::Size(1400, 884);
			this->chat_bot_panal->TabIndex = 22;
			this->chat_bot_panal->Visible = false;
			// 
			// send_button
			// 
			this->send_button->BackColor = System::Drawing::Color::Transparent;
			this->send_button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"send_button.BackgroundImage")));
			this->send_button->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->send_button->Location = System::Drawing::Point(1242, 824);
			this->send_button->Name = L"send_button";
			this->send_button->Size = System::Drawing::Size(56, 40);
			this->send_button->TabIndex = 3;
			this->send_button->UseVisualStyleBackColor = false;
			this->send_button->Visible = false;
			this->send_button->Click += gcnew System::EventHandler(this, &admin_home_page::send_button_Click);
			// 
			// txtMessage
			// 
			this->txtMessage->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->txtMessage->BackColor = System::Drawing::SystemColors::Menu;
			this->txtMessage->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtMessage->Location = System::Drawing::Point(367, 824);
			this->txtMessage->Name = L"txtMessage";
			this->txtMessage->Size = System::Drawing::Size(859, 38);
			this->txtMessage->TabIndex = 2;
			this->txtMessage->Visible = false;
			this->txtMessage->TextChanged += gcnew System::EventHandler(this, &admin_home_page::txtMessage_TextChanged);
			this->txtMessage->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &admin_home_page::txtMessage_KeyDown);
			// 
			// chatbox
			// 
			this->chatbox->AutoScroll = true;
			this->chatbox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)), static_cast<System::Int32>(static_cast<System::Byte>(210)),
				static_cast<System::Int32>(static_cast<System::Byte>(216)), static_cast<System::Int32>(static_cast<System::Byte>(228)));
			this->chatbox->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
			this->chatbox->Location = System::Drawing::Point(323, 3);
			this->chatbox->Name = L"chatbox";
			this->chatbox->Size = System::Drawing::Size(1059, 815);
			this->chatbox->TabIndex = 1;
			this->chatbox->WrapContents = false;
			// 
			// admin_home_page
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1924, 1055);
			this->Controls->Add(this->add_flight_panel);
			this->Controls->Add(this->add_admin_panel);
			this->Controls->Add(this->add_plane_panel);
			this->Controls->Add(this->home_pg_panel);
			this->Controls->Add(this->chat_bot_panal);
			this->Controls->Add(this->search_flights_panel);
			this->Controls->Add(this->search_plane_panel);
			this->Controls->Add(this->open_home_pg);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"admin_home_page";
			this->Text = L"Admin home page";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &admin_home_page::admin_home_page_Load);
			this->Resize += gcnew System::EventHandler(this, &admin_home_page::admin_home_page_Resize);
			this->add_flight_panel->ResumeLayout(false);
			this->add_flight_panel->PerformLayout();
			this->add_plane_panel->ResumeLayout(false);
			this->add_plane_panel->PerformLayout();
			this->add_admin_panel->ResumeLayout(false);
			this->add_admin_panel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->confirm_view))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pass_view))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pass_hide))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->confirm_hide))->EndInit();
			this->search_plane_panel->ResumeLayout(false);
			this->search_plane_panel->PerformLayout();
			this->search_flights_panel->ResumeLayout(false);
			this->search_flights_panel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->transfer_pictureBox))->EndInit();
			this->home_pg_panel->ResumeLayout(false);
			this->home_pg_panel->PerformLayout();
			this->chat_bot_panal->ResumeLayout(false);
			this->chat_bot_panal->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		void SetRoundedButton(Button^ btn, int radius)
		{
			System::Drawing::Drawing2D::GraphicsPath^ path =
				gcnew System::Drawing::Drawing2D::GraphicsPath();

			path->AddArc(0, 0, radius, radius, 180, 90);
			path->AddArc(btn->Width - radius, 0, radius, radius, 270, 90);
			path->AddArc(btn->Width - radius, btn->Height - radius, radius, radius, 0, 90);
			path->AddArc(0, btn->Height - radius, radius, radius, 90, 90);
			path->CloseAllFigures();

			btn->Region = gcnew System::Drawing::Region(path);
		}
			// form load and resize events
	private: System::Void admin_home_page_Load(System::Object^ sender, System::EventArgs^ e) {
		AutoCompleteStringCollection^ collection = gcnew AutoCompleteStringCollection();

		for (int i = 0; i < airports.size(); i++)
		{
			collection->Add(gcnew String(airports[i].name.c_str()));
		}

		// add flights panel load
		departure_airport_textbox->AutoCompleteCustomSource = collection;
		arrival_airport_textbox->AutoCompleteCustomSource = collection;
		add_flight_panel->Left = (this->ClientSize.Width - add_flight_panel->Width) / 2;
		add_flight_panel->Top = (this->ClientSize.Height - add_flight_panel->Height) / 2;


		// add plane panel load
		airport_textBox->AutoCompleteCustomSource = collection;
		add_plane_panel->Left = (this->ClientSize.Width - add_plane_panel->Width) / 2;
		add_plane_panel->Top = (this->ClientSize.Height - add_plane_panel->Height) / 2;


		// add admin panel load
		add_admin_panel->Left = (this->ClientSize.Width - add_admin_panel->Width) / 2;
		add_admin_panel->Top = (this->ClientSize.Height - add_admin_panel->Height) / 2;
		add_admin_label->Left = (this->add_admin_panel->Width - add_admin_label->Width) / 2;

		// search plane panel load
		int x = (this->ClientSize.Width - search_plane_panel->Width) / 2;
		int y = 20;
		search_plane_panel->Location = System::Drawing::Point(x, y);
		by_code->Checked = true;
		
		//search flights panel load
		x = (this->ClientSize.Width - search_flights_panel->Width) / 2;
		y = 20;
		search_flights_panel->Location = System::Drawing::Point(x, y);
		d_airport->AutoCompleteCustomSource = collection;
		a_airport->AutoCompleteCustomSource = collection;

		// home page panel load
		title->Left = (home_pg_panel->Width - title->Width) / 2;
		welcome->Text = "Welcome, " + marshal_as<String^>(first_name);
		welcome->Left = (home_pg_panel->Width - welcome->Width) / 2;
		home_pg_panel->Left = (this->ClientSize.Width - home_pg_panel->Width) / 2;
		SetRoundedButton(btn_add_admin, 30);
		SetRoundedButton(btn_add_plane, 30);
		SetRoundedButton(btn_add_flight, 30);
		SetRoundedButton(btn_search_planes, 30);
		SetRoundedButton(btn_search_flights, 30);
		SetRoundedButton(btn_customer_service, 30);


		// chatBot panel load
		chat_bot_panal->Left = (this->ClientSize.Width - chat_bot_panal->Width) / 2;
		chat_bot_panal->Top = (this->ClientSize.Height - chat_bot_panal->Height) / 2;


	}
	private: System::Void admin_home_page_Resize(System::Object^ sender, System::EventArgs^ e) {
		// add flight panel resize
		add_flight_panel->Left = (this->ClientSize.Width - add_flight_panel->Width) / 2;
		add_flight_panel->Top = (this->ClientSize.Height - add_flight_panel->Height) / 2;


		// add plane panel resize
		add_plane_panel->Left = (this->ClientSize.Width - add_plane_panel->Width) / 2;
		add_plane_panel->Top = (this->ClientSize.Height - add_plane_panel->Height) / 2;

		// add admin panel resize
		add_admin_panel->Left = (this->ClientSize.Width - add_admin_panel->Width) / 2;
		add_admin_panel->Top = (this->ClientSize.Height - add_admin_panel->Height) / 2;
		add_admin_label->Left = (this->add_admin_panel->Width - add_admin_label->Width) / 2;

		// search plane panel resize
		int x = (this->ClientSize.Width - search_plane_panel->Width) / 2;
		int y = 20;
		search_plane_panel->Location = System::Drawing::Point(x, y);


		//search flights panel resize
		x = (this->ClientSize.Width - search_flights_panel->Width) / 2;
		y = 20;
		search_flights_panel->Location = System::Drawing::Point(x, y);

		// home page panel resize
		title->Left = (home_pg_panel->Width - title->Width) / 2;
		welcome->Left = (home_pg_panel->Width - welcome->Width) / 2;
		home_pg_panel->Left = (this->ClientSize.Width - home_pg_panel->Width) / 2;


		// chatBot panel resize
		chat_bot_panal->Left = (this->ClientSize.Width - chat_bot_panal->Width) / 2;
		chat_bot_panal->Top = (this->ClientSize.Height - chat_bot_panal->Height) / 2;

	}

			//add flights events

	private: System::Void plane_code_textbox_Enter(System::Object^ sender, System::EventArgs^ e) {
		if (departure_airport_textbox->Text == "Enter Departure Airport") {
			MessageBox::Show("please Enter Departure Airport first! ", "warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			this->ActiveControl = nullptr;
			return;
		}
		if (plane_code_textbox->Text == "Enter Plane code") {
			plane_code_textbox->Text = "";
			plane_code_textbox->ForeColor = System::Drawing::Color::Black;
		}
	}

	private: System::Void plane_code_textbox_Leave(System::Object^ sender, System::EventArgs^ e) {
		if (plane_code_textbox->Text == "") {
			plane_code_textbox->Text = "Enter Plane code";
			plane_code_textbox->ForeColor = System::Drawing::Color::Gray;
		}

	}

	private: System::Void departure_airport_textbox_Enter(System::Object^ sender, System::EventArgs^ e) {
		if (departure_airport_textbox->Text == "Enter Departure Airport") {
			departure_airport_textbox->Text = "";
			departure_airport_textbox->ForeColor = System::Drawing::Color::Black;
		}
	}
	private: System::Void departure_airport_textbox_Leave(System::Object^ sender, System::EventArgs^ e) {
		if (departure_airport_textbox->Text == "") {
			departure_airport_textbox->Text = "Enter Departure Airport";
			departure_airport_textbox->ForeColor = System::Drawing::Color::Gray;
		}
		AutoCompleteStringCollection^ collection_p = gcnew AutoCompleteStringCollection();
		string departure = marshal_as<string>(departure_airport_textbox->Text);
		for (int i = 0; i < planes.size(); i++)
		{
			if (planes[i].place == departure)
				collection_p->Add(gcnew String(planes[i].code.c_str()));
		}


		plane_code_textbox->AutoCompleteCustomSource = collection_p;

	}
	private: System::Void arrival_airport_textbox_Enter(System::Object^ sender, System::EventArgs^ e) {
		if (arrival_airport_textbox->Text == "Enter Arrival Airport") {
			arrival_airport_textbox->Text = "";
			arrival_airport_textbox->ForeColor = System::Drawing::Color::Black;
		}
	}
	private: System::Void arrival_airport_textbox_Leave(System::Object^ sender, System::EventArgs^ e) {
		if (arrival_airport_textbox->Text == "") {
			arrival_airport_textbox->Text = "Enter Arrival Airport";
			arrival_airport_textbox->ForeColor = System::Drawing::Color::Gray;
		}
		if (arrival_airport_textbox->Text == departure_airport_textbox->Text) {
			MessageBox::Show("Arrival Airport cannot be the same as Departure Airport! ", "warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			arrival_airport_textbox->Text = "Enter Arrival Airport";
			arrival_airport_textbox->ForeColor = System::Drawing::Color::Gray;
		}
	}

	private: System::Void economy_price_textbox_Enter(System::Object^ sender, System::EventArgs^ e) {
		if (economy_price_textbox->Text == "Enter Price") {
			economy_price_textbox->Text = "";
			economy_price_textbox->ForeColor = System::Drawing::Color::Black;
		}
	}
	private: System::Void economy_price_textbox_Leave(System::Object^ sender, System::EventArgs^ e) {
		if (economy_price_textbox->Text == "") {
			economy_price_textbox->Text = "Enter Price";
			economy_price_textbox->ForeColor = System::Drawing::Color::Gray;
		}
	}
	private: System::Void add_flight_button_Click(System::Object^ sender, System::EventArgs^ e) {
		
		if (departure_airport_textbox->Text == "Enter Departure Airport" || arrival_airport_textbox->Text == "Enter Arrival Airport" || plane_code_textbox->Text == "Enter Plane code" || (economy_price_textbox->Visible && economy_price_textbox->Text == "Enter Price") || (business_price_textbox->Visible && business_price_textbox->Text == "Enter Price") || (frist_class_price_textbox->Visible && frist_class_price_textbox->Text == "Enter Price") || (premium_economy_price_textbox->Visible && premium_economy_price_textbox->Text == "Enter Price")) {
			MessageBox::Show("Please fill in all the required fields!", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		if (arrival_airport_textbox->Text == departure_airport_textbox->Text) {
			MessageBox::Show("Arrival Airport cannot be the same as Departure Airport! ", "warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		if (dateTimePicker_arrival->Value < dateTimePicker_departure->Value || (dateTimePicker_arrival->Value == dateTimePicker_departure->Value && time_arrival->Value <= time_departure->Value)) {
			MessageBox::Show("Arrival date cannot be before departure date! ", "warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		// Retrieve and convert input values
		string plane_code = marshal_as<string>(plane_code_textbox->Text);
		string departure = marshal_as<string>(departure_airport_textbox->Text);
		string arrival = marshal_as<string>(arrival_airport_textbox->Text);
		string economy_price = marshal_as<string>(economy_price_textbox->Text);
		string business_price = marshal_as<string>(business_price_textbox->Text);
		string frist_class_price = marshal_as<string>(frist_class_price_textbox->Text);
		string premium_economy_price = marshal_as<string>(premium_economy_price_textbox->Text);
		int economy_price_value = stoi(economy_price);
		int business_price_value = stoi(business_price);
		int frist_class_price_value = stoi(frist_class_price);
		int premium_economy_price_value = stoi(premium_economy_price);
		DateTime departure_date = dateTimePicker_departure->Value;

		DateTime time_departure_value = time_departure->Value;
		DateTime final_date_departure = departure_date.Date + time_departure_value.TimeOfDay;
		DateTime arrival_date = dateTimePicker_arrival->Value;
		DateTime time_arrival_value = time_arrival->Value;
		DateTime final_date_arrival = arrival_date.Date + time_arrival_value.TimeOfDay;
		string number_flight = plane_code;
		string s = marshal_as<string>(final_date_departure.ToString("yyyyMMddHHmm"));
		number_flight.append(s);

		//flight duration calculation
		
		TimeSpan difference = final_date_arrival - final_date_departure;

		int flight_duration = (int)difference.TotalMinutes;


		add_flight(number_flight, plane_code, departure, arrival, final_date_departure, final_date_arrival, economy_price_value, business_price_value, frist_class_price_value, premium_economy_price_value, flight_duration);

		// Clear the input fields after adding the flight

		if (flight_update) {
			MessageBox::Show("Flight updated successfully", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		else {
			MessageBox::Show("Flight added successfully\n\nFlight number: " + marshal_as<String^>(number_flight), "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		departure_airport_textbox->Text = "Enter Departure Airport";
		departure_airport_textbox->ForeColor = System::Drawing::Color::Gray;
		arrival_airport_textbox->Text = "Enter Arrival Airport";
		arrival_airport_textbox->ForeColor = System::Drawing::Color::Gray;
		plane_code_textbox->Text = "Enter Plane code";
		plane_code_textbox->ForeColor = System::Drawing::Color::Gray;
		category_comboBox->SelectedIndex = -1;
		category_comboBox->Text = "Select Category";
		economy_price_textbox->Text = "Enter Price";
		economy_price_textbox->ForeColor = System::Drawing::Color::Gray;
		premium_economy_price_textbox->Text = "Enter Price";
		premium_economy_price_textbox->ForeColor = System::Drawing::Color::Gray;
		frist_class_price_textbox->Text = "Enter Price";
		frist_class_price_textbox->ForeColor = System::Drawing::Color::Gray;
		business_price_textbox->Text = "Enter Price";
		economy_price_textbox->Visible = false;
		business_price_textbox->Visible = false;
		frist_class_price_textbox->Visible = false;
		premium_economy_price_textbox->Visible = false;
		business_price_textbox->ForeColor = System::Drawing::Color::Gray;
		dateTimePicker_arrival->Value = DateTime::Now;
		dateTimePicker_departure->Value = DateTime::Now;
		time_departure->Value = DateTime::Now;
		time_arrival->Value = DateTime::Now;
	}

	private: System::Void dateTimePicker_arrival_Leave(System::Object^ sender, System::EventArgs^ e) {
		DateTime a = dateTimePicker_arrival->Value;
		DateTime d = dateTimePicker_departure->Value;
		if (a < d) {
			MessageBox::Show("Choose a date in the future! ", "warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			//dateTimePicker_arrival->Value = dateTimePicker_departure->Value.AddDays(1);
		}
	}
	private: System::Void category_comboBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		String^ selected = category_comboBox->Text;
		if (selected == "Economy") {
			economy_price_textbox->Visible = true;
			business_price_textbox->Visible = false;
			frist_class_price_textbox->Visible = false;
			premium_economy_price_textbox->Visible = false;
		}
		else if (selected == "Business") {
			economy_price_textbox->Visible = false;
			business_price_textbox->Visible = true;
			frist_class_price_textbox->Visible = false;
			premium_economy_price_textbox->Visible = false;
		}
		else if (selected == "First Class") {
			economy_price_textbox->Visible = false;
			business_price_textbox->Visible = false;
			frist_class_price_textbox->Visible = true;
			premium_economy_price_textbox->Visible = false;
		}
		else if (selected == "Premium Economy") {
			economy_price_textbox->Visible = false;
			business_price_textbox->Visible = false;
			frist_class_price_textbox->Visible = false;
			premium_economy_price_textbox->Visible = true;
		}
		
	}
	private: System::Void business_price_textbox_Enter(System::Object^ sender, System::EventArgs^ e) {
		if (business_price_textbox->Text == "Enter Price") {
			business_price_textbox->Text = "";
			business_price_textbox->ForeColor = System::Drawing::Color::Black;
		}
	}
	private: System::Void business_price_textbox_Leave(System::Object^ sender, System::EventArgs^ e) {
		if (business_price_textbox->Text == "") {
			business_price_textbox->Text = "Enter Price";
			business_price_textbox->ForeColor = System::Drawing::Color::Gray;
		}
	}
	private: System::Void frist_class_price_textbox_Enter(System::Object^ sender, System::EventArgs^ e) {
		if (frist_class_price_textbox->Text == "Enter Price") {
			frist_class_price_textbox->Text = "";
			frist_class_price_textbox->ForeColor = System::Drawing::Color::Black;
		}
	}
	private: System::Void frist_class_price_textbox_Leave(System::Object^ sender, System::EventArgs^ e) {
		if (frist_class_price_textbox->Text == "") {
			frist_class_price_textbox->Text = "Enter Price";
			frist_class_price_textbox->ForeColor = System::Drawing::Color::Gray;
		}
	}
	private: System::Void premium_economy_price_textbox_Enter(System::Object^ sender, System::EventArgs^ e) {
		if (premium_economy_price_textbox->Text == "Enter Price") {
			premium_economy_price_textbox->Text = "";
			premium_economy_price_textbox->ForeColor = System::Drawing::Color::Black;
		}
	}
	private: System::Void premium_economy_price_textbox_Leave(System::Object^ sender, System::EventArgs^ e) {
		if (premium_economy_price_textbox->Text == "") {
			premium_economy_price_textbox->Text = "Enter Price";
			premium_economy_price_textbox->ForeColor = System::Drawing::Color::Gray;
		}
	}
	private: System::Void update_flight_Click(System::Object^ sender, System::EventArgs^ e) {

			   selected_flight_idx = stoi(marshal_as<string>(flight_index->Text));

			   flight_update = true;
			   add_flight_button_Click(sender, e);

			   search_flights_panel->Visible = true;
			   add_flight_panel->Visible = false;

			   search_bar_TextChanged(sender, e);
			   flight_update = false;
		   }


			//add plane events


	private: System::Void code_textBox_Enter(System::Object^ sender, System::EventArgs^ e) {
		if (code_textBox->Text == "Code")
		{
			code_textBox->Text = "";
			code_textBox->ForeColor = System::Drawing::Color::Black;
		}
	}
	private: System::Void code_textBox_Leave(System::Object^ sender, System::EventArgs^ e) {
		if (code_textBox->Text == "")
		{
			code_textBox->Text = "Code";
			code_textBox->ForeColor = System::Drawing::SystemColors::ScrollBar;
		}
	}
	private: System::Void plane_model_textBox_Enter(System::Object^ sender, System::EventArgs^ e) {
		if (plane_model_textBox->Text == "Model")
		{
			plane_model_textBox->Text = "";
			plane_model_textBox->ForeColor = System::Drawing::Color::Black;
		}
	}
	private: System::Void plane_model_textBox_Leave(System::Object^ sender, System::EventArgs^ e) {
		if (plane_model_textBox->Text == "")
		{
			plane_model_textBox->Text = "Model";
			plane_model_textBox->ForeColor = System::Drawing::SystemColors::ScrollBar;
		}
	}
	private: System::Void rows_textBox_Enter(System::Object^ sender, System::EventArgs^ e) {
		if (rows_textBox->Text == "Num of rows")
		{
			rows_textBox->Text = "";
			rows_textBox->ForeColor = System::Drawing::Color::Black;
		}
	}
	private: System::Void rows_textBox_Leave(System::Object^ sender, System::EventArgs^ e) {
		if (rows_textBox->Text == "")
		{
			rows_textBox->Text = "Num of rows";
			rows_textBox->ForeColor = System::Drawing::SystemColors::ScrollBar;
		}
	}
	private: System::Void chairs_textBox_Enter(System::Object^ sender, System::EventArgs^ e) {
		if (chairs_textBox->Text == "Num of chairs")
		{
			chairs_textBox->Text = "";
			chairs_textBox->ForeColor = System::Drawing::Color::Black;
		}
	}

	private: System::Void chairs_textBox_Leave(System::Object^ sender, System::EventArgs^ e) {
		if (chairs_textBox->Text == "")
		{
			chairs_textBox->Text = "Num of chairs";
			chairs_textBox->ForeColor = System::Drawing::SystemColors::ScrollBar;
		}
	}
	private: System::Void airport_textBox_Enter(System::Object^ sender, System::EventArgs^ e) {
		if (airport_textBox->Text == "Air port")
		{
			airport_textBox->Text = "";
			airport_textBox->ForeColor = System::Drawing::Color::Black;
		}
	}
	private: System::Void airport_textBox_Leave(System::Object^ sender, System::EventArgs^ e) {
		if (airport_textBox->Text == "")
		{
			airport_textBox->Text = "Air port";
			airport_textBox->ForeColor = System::Drawing::SystemColors::ScrollBar;
		}
	}
	private: System::Void code_textBox_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::Enter)
		{
			this->SelectNextControl((Control^)sender, true, true, true, true);
			e->SuppressKeyPress = true;
		}
	}
	private: System::Void add_plane_button_Click(System::Object^ sender, System::EventArgs^ e) {
		
		if (code_textBox->Text == "Code" || plane_model_textBox->Text == "Model" || rows_textBox->Text == "Num of rows" || chairs_textBox->Text == "Num of chairs" || airport_textBox->Text == "Air port") {
			MessageBox::Show("Please fill in all the required fields!", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}
		
		string code = msclr::interop::marshal_as<std::string>(code_textBox->Text);
		string model = msclr::interop::marshal_as<std::string>(plane_model_textBox->Text);
		int rows = stoi(msclr::interop::marshal_as<std::string>(rows_textBox->Text));
		int chairs = stoi(msclr::interop::marshal_as<std::string>(chairs_textBox->Text));
		string airport = msclr::interop::marshal_as<std::string>(airport_textBox->Text);
		if (!plane_update) {
			for (int i = 0; i < planes.size(); i++) {
				if (planes[i].code == code) {
					MessageBox::Show("Plane code already exists! ", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
					return;
				}
			}
		}
		add_planes(code, model, rows, chairs, airport);
		if (plane_update)
			MessageBox::Show("Plane updated successfully", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
		else
			MessageBox::Show("Plane added successfully", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
		code_textBox->Text = "";
		code_textBox_Leave(sender, e);
		plane_model_textBox->Text = "";
		plane_model_textBox_Leave(sender, e);
		rows_textBox->Text = "";
		rows_textBox_Leave(sender, e);
		chairs_textBox->Text = "";
		chairs_textBox_Leave(sender, e);
		airport_textBox->Text = "";
		airport_textBox_Leave(sender, e);
	}
	private: System::Void update_plane_Click(System::Object^ sender, System::EventArgs^ e) {
		
		plane_idx = stoi(marshal_as<string>(plane_index->Text));

		plane_update = true;

		add_plane_button_Click(sender, e);

		search_plane_panel->Visible = true;
		add_plane_panel->Visible = false;
		search_bar_TextChanged(sender, e);
	}


			//add admin events


	private: System::Void ad_name_textBox_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::Enter)
		{
			this->SelectNextControl((Control^)sender, true, true, true, true);
			e->SuppressKeyPress = true;
		}
	}
	private: System::Void add_admin_button_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ ad_user_name = ad_user_name_textBox->Text;
		Regex^ ad_u_name_pattern = gcnew Regex("^[a-zA-Z0-9_]+$");

		String^ ad_name = ad_name_textBox->Text;
		Regex^ ad_name_pattern = gcnew Regex("^[a-zA-Z ]+$");

		String^ ad_pass = ad_password_textBox->Text;
		Regex^ ad_pass_pattern = gcnew Regex("^(?=.*[a-z])(?=.*[A-Z])(?=.*[0-9])(?=.*[!@#$%^&*()\\-_=+{}\\[\\]|\\\\:;\"'<>,.?/~]).+$");

		String^ ad_phone = ad_phone_textBox->Text;
		Regex^ ad_phone_pattern = gcnew Regex("^[0-9 \\- +()]+$");

		if (ad_name_textBox->Text == "Enter Your Name" ||
			ad_user_name_textBox->Text == "Enter Your Username" ||
			ad_password_textBox->Text == "Enter Password" ||
			ad_confirm_textBox->Text == "Confirm Password" ||
			ad_phone_textBox->Text == "Enter Phone Number")
		{
			MessageBox::Show("Please Enter All Data", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			new_admin = false;
		}
		else if (!ad_u_name_pattern->IsMatch(ad_user_name) ||
			!ad_name_pattern->IsMatch(ad_name) || !ad_pass_pattern->IsMatch(ad_pass) ||
			!ad_phone_pattern->IsMatch(ad_phone))
		{
			MessageBox::Show("Invalid name or user name or password, phone. Please note that the password must contain at least: A capital letter, a small letter, a number and a special character(!,@,#,$,%,^,&,*...) and must be at least 8 characters!", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
		else if (ad_password_textBox->Text != ad_confirm_textBox->Text)
		{
			MessageBox::Show("Password doesn't match", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			new_admin = false;
		}
		else {
			add_new_admin(ad_name_textBox->Text, ad_user_name_textBox->Text, ad_password_textBox->Text, ad_phone_textBox->Text);
			if (new_admin == true)
			{
				MessageBox::Show("Admin added successfully", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);

				ad_name_textBox->Clear();
				ad_name_textBox_Leave(sender, e);
				ad_user_name_textBox->Clear();
				ad_user_name_textBox_Leave(sender, e);
				ad_password_textBox->Clear();
				ad_password_textBox_Leave(sender, e);
				ad_confirm_textBox->Clear();
				ad_confirm_textBox_Leave(sender, e);
				ad_phone_textBox->Clear();
				ad_phone_textBox_Leave(sender, e);
			}
			else if (!new_admin)
			{
				MessageBox::Show("This user name is already exist", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
		}
	}
	private: System::Void ad_password_textBox_Enter(System::Object^ sender, System::EventArgs^ e) {

		if (ad_password_textBox->Text == "Enter Password")
		{
			ad_password_textBox->Text = "";
			ad_password_textBox->ForeColor = System::Drawing::Color::Black;
			this->ad_password_textBox->PasswordChar = '*';
		}
	}
	private: System::Void ad_password_textBox_Leave(System::Object^ sender, System::EventArgs^ e) {

		if (ad_password_textBox->Text == "")
		{
			ad_password_textBox->Text = "Enter Password";
			ad_password_textBox->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->ad_password_textBox->PasswordChar = 0;
		}
	}
	private: System::Void ad_name_textBox_Enter(System::Object^ sender, System::EventArgs^ e) {

		if (ad_name_textBox->Text == "Enter Admin Name")
		{
			ad_name_textBox->Text = "";
			ad_name_textBox->ForeColor = System::Drawing::Color::Black;
		}
	}
	private: System::Void ad_name_textBox_Leave(System::Object^ sender, System::EventArgs^ e) {

		if (ad_name_textBox->Text == "")
		{
			ad_name_textBox->Text = "Enter Admin Name";
			ad_name_textBox->ForeColor = System::Drawing::SystemColors::ScrollBar;
		}
	}
	private: System::Void ad_user_name_textBox_Leave(System::Object^ sender, System::EventArgs^ e) {
		if (ad_user_name_textBox->Text == "")
		{
			ad_user_name_textBox->Text = "Enter Admin Username";
			ad_user_name_textBox->ForeColor = System::Drawing::SystemColors::ScrollBar;
		}
	}
	private: System::Void ad_user_name_textBox_Enter(System::Object^ sender, System::EventArgs^ e) {
		if (ad_user_name_textBox->Text == "Enter Admin Username")
		{
			ad_user_name_textBox->Text = "";
			ad_user_name_textBox->ForeColor = System::Drawing::Color::Black;
		}
	}
	private: System::Void ad_confirm_textBox_Leave(System::Object^ sender, System::EventArgs^ e) {
		if (ad_confirm_textBox->Text == "")
		{
			ad_confirm_textBox->Text = "Confirm Password";
			ad_confirm_textBox->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->ad_confirm_textBox->PasswordChar = 0;
		}
	}
	private: System::Void ad_confirm_textBox_Enter(System::Object^ sender, System::EventArgs^ e) {
		if (ad_confirm_textBox->Text == "Confirm Password")
		{
			ad_confirm_textBox->Text = "";
			ad_confirm_textBox->ForeColor = System::Drawing::Color::Black;
			this->ad_confirm_textBox->PasswordChar = '*';
		}
	}
	private: System::Void ad_phone_textBox_Leave(System::Object^ sender, System::EventArgs^ e) {
		if (ad_phone_textBox->Text == "")
		{
			ad_phone_textBox->Text = "Enter Phone Number";
			ad_phone_textBox->ForeColor = System::Drawing::SystemColors::ScrollBar;
		}
	}
	private: System::Void ad_phone_textBox_Enter(System::Object^ sender, System::EventArgs^ e) {
		if (ad_phone_textBox->Text == "Enter Phone Number")
		{
			ad_phone_textBox->Text = "";
			ad_phone_textBox->ForeColor = System::Drawing::Color::Black;
		}
	}
	private: System::Void pass_view_Click(System::Object^ sender, System::EventArgs^ e) {
		if (ad_password_textBox->PasswordChar == '*')
		{
			this->ad_password_textBox->PasswordChar = '\0';
			pass_view->Visible = false;
			pass_hide->Visible = true;
		}
	}
	private: System::Void pass_hide_Click(System::Object^ sender, System::EventArgs^ e) {
		if (ad_password_textBox->PasswordChar == '\0')
		{
			this->ad_password_textBox->PasswordChar = '*';
			pass_view->Visible = true;
			pass_hide->Visible = false;
		}
	}
	private: System::Void confirm_view_Click(System::Object^ sender, System::EventArgs^ e) {
		if (ad_confirm_textBox->PasswordChar == '*')
		{
			this->ad_confirm_textBox->PasswordChar = '\0';
			confirm_view->Visible = false;
			confirm_hide->Visible = true;
		}
	}
	private: System::Void confirm_hide_Click(System::Object^ sender, System::EventArgs^ e) {
		if (ad_confirm_textBox->PasswordChar == '\0')
		{
			this->ad_confirm_textBox->PasswordChar = '*';
			confirm_view->Visible = true;
			confirm_hide->Visible = false;
		}
	}

		   //search plane events


		   void view_plane_search_result(int i)
		   {
			   plane_result^ card = gcnew plane_result();

			   card->OnEditButtonClicked += gcnew PlaneActionHandler(this, &admin_home_page::UpdatePlaneProcess);

			   card->SetPlaneData(marshal_as<String^>(planes[i].model),
				   marshal_as<String^>(planes[i].code),
				   marshal_as<String^>(planes[i].place),
				   ((planes[i].rows * planes[i].nom_of_seats).ToString()),
				   i.ToString());

			   flowLayoutPanel1->Controls->Add(card);
		   }
	private: System::Void search_bar_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		this->flowLayoutPanel1->Controls->Clear();
		plane_search_result.clear();
		if (search_bar->Text->Length == 0) {
			no_results->Visible = true;
			search_results->Text = "";
			return;
		}
		string query = marshal_as<string>(search_bar->Text);

		if (by_code->Checked) search_by_code(query);
		else if (by_model->Checked) searchByModel(query);


		if (plane_search_result.size() == 0) {
			no_results->Visible = true;
			search_results->Text = "";
		}
		else {
			no_results->Visible = false;
			search_results->Text = "Search results: " + marshal_as<String^>(to_string(plane_search_result.size()));
		}

		for (int i = 0; i < plane_search_result.size(); ++i) {
			view_plane_search_result(plane_search_result[i]);
		}
	}
	private: System::Void by_code_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		search_bar_TextChanged(sender, e);
	}
	private: System::Void by_model_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		search_bar_TextChanged(sender, e);
	}


		   //search flights events

		   void view_flight_search_result(int i)
		   {
			   int price = 0;
			   flight_result^ card = gcnew flight_result(true, this);

			   card->OnEditButtonClicked += gcnew FlightActionHandler(this, &admin_home_page::UpdateFlightProcess);

			   card->SetFlightData(
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

			   flights_layout_panel->Controls->Add(card);
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
		flights_layout_panel->Controls->Clear();
		string d_airport_str = marshal_as<string>(d_airport->Text);
		string a_airport_str = marshal_as<string>(a_airport->Text);
		string date_str = marshal_as<string>(departure_date_search->Value.ToString("ddd,dd/MMM/yyyy"));
		skyPort_array <int> flights_search_result;
		for (int i = 0; i < flights.size(); i++) {
			if (flights[i].departure_airport == d_airport_str &&
				flights[i].arrival_airport == a_airport_str &&
				flights[i].departure_date == date_str) {
				flights_search_result.push_back(i);
			}
		}
		if (flights_search_result.size() == 0) no_results->Visible = true;
		else no_results->Visible = false;
		for (int i = 0; i < flights_search_result.size(); i++) {
			view_flight_search_result(flights_search_result[i]);
		}
	}

		   
		   //admin home page events

	private: System::Void btn_add_admin_Click(System::Object^ sender, System::EventArgs^ e) {
		add_admin_panel->Visible = true;
		home_pg_panel->Visible = false;
		open_home_pg->Visible = true;
		open_home_pg->BringToFront();
	}
	private: System::Void btn_add_flight_Click(System::Object^ sender, System::EventArgs^ e) {
		add_flight_panel->Visible = true;
		this->add_flight_button->Visible = true;
		this->add_flight_button->BringToFront();
		this->update_flight->Visible = false;
		home_pg_panel->Visible = false;
		open_home_pg->Visible = true;
		open_home_pg->BringToFront();

	}
	private: System::Void btn_add_plane_Click(System::Object^ sender, System::EventArgs^ e) {
		
		add_plane_panel->Visible = true;
		home_pg_panel->Visible = false;
		open_home_pg->Visible = true;
		open_home_pg->BringToFront();
		add_plane_button->Visible = true;
		update_plane->Visible = false;
	}
	private: System::Void btn_search_planes_Click(System::Object^ sender, System::EventArgs^ e) {
		search_plane_panel->Visible = true;
		home_pg_panel->Visible = false;
		open_home_pg->Visible = true;
		open_home_pg->Location.X = search_plane_panel->Left - 167;
		open_home_pg->BringToFront();
	}
	private: System::Void btn_search_flights_Click(System::Object^ sender, System::EventArgs^ e) {
		search_flights_panel->Visible = true;
		home_pg_panel->Visible = false;
		open_home_pg->Visible = true;
		open_home_pg->Location.X = search_flights_panel->Left - 167;
		open_home_pg->BringToFront();
	}
	private: System::Void btn_customer_service_Click(System::Object^ sender, System::EventArgs^ e) {
		chat_bot_panal->Visible = true;
		home_pg_panel->Visible = false;
		open_home_pg->Visible = true; 
		chat_list_panal->Controls->Clear();
		chatbox->Controls->Clear();
		show_chats();
		for (int i = 0; i < chats.size(); i++)
		{
			chat_list^ chat = gcnew chat_list(this);
			chat->Set_chatbot_data(gcnew String(chats[i].user_name.c_str()), gcnew String(chats[i].message.c_str()));
			chat_list_panal->Controls->Add(chat);
		}
	}
	private: System::Void open_home_pg_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
		add_admin_panel->Visible = false;
		add_plane_panel->Visible = false;
		add_flight_panel->Visible = false;
		search_plane_panel->Visible = false;
		search_flights_panel->Visible = false;
		open_home_pg->Visible = false;
		chat_bot_panal->Visible = false;
		home_pg_panel->Visible = true;
		open_home_pg->BringToFront();
	}

		   // chat bot events
	private: System::Void send_button_Click(System::Object^ sender, System::EventArgs^ e) {
		messageStruct msg;
		msg.user_name = user_sender;
		msg.message = marshal_as<string>(txtMessage->Text);
		msg.replied = true;
		msg.if_admin = is_admin;

		messages_array.push_back(msg);

		for (int i = messages_array.size() - 2; i >= 0; i--) {
			if (messages_array[i].user_name == user_sender) {
				if (!messages_array[i].replied) messages_array[i].replied = true;
				else break;
			}
		}

		Label^ bubble = gcnew Label();
		bubble->Font = gcnew System::Drawing::Font("Segoe UI", 16, System::Drawing::FontStyle::Regular);
		bubble->Text = "You: " + txtMessage->Text;
		bubble->AutoSize = true;
		bubble->MaximumSize = System::Drawing::Size(800, 1000);
		bubble->Margin = System::Windows::Forms::Padding(10, 5, 10, 5);
		bubble->Padding = System::Windows::Forms::Padding(10);
		bubble->BackColor = System::Drawing::Color::White;
		bubble->ForeColor = System::Drawing::Color::Black;

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
			send_button_Click(sender, e);
			e->SuppressKeyPress = true;
		}
	}
		   
};
}
