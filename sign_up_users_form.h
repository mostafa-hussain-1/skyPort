#pragma once
#include <msclr/marshal_cppstd.h>
#include"sign_up_users.h"
#include"sign_in.h"
#include"forget_pass.h"
using namespace msclr::interop;
using namespace System::Text::RegularExpressions;
using namespace std;
namespace skyPort {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for sign_up_users_form
	/// </summary>
	public ref class sign_up_users_form : public System::Windows::Forms::Form
	{
	public:
		sign_up_users_form(void)
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
		~sign_up_users_form()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

		property virtual System::Windows::Forms::CreateParams^ CreateParams {
			System::Windows::Forms::CreateParams^ get() override {
				System::Windows::Forms::CreateParams^ cp = __super::CreateParams;
				cp->ExStyle |= 0x02000000;  // WS_EX_COMPOSITED
				return cp;
			}
		}











	private: System::Windows::Forms::Label^ sign_up_label;
	private: System::Windows::Forms::Panel^ sign_up_panel;
	private: System::Windows::Forms::PictureBox^ view_confirm_pass;













	private: System::Windows::Forms::PictureBox^ view_signup_pass;
	private: System::Windows::Forms::Label^ have_account;



	private: System::Windows::Forms::Button^ sign_up_button;
	private: System::Windows::Forms::Label^ confirm_label;


	private: System::Windows::Forms::Label^ name_signup_label;

	private: System::Windows::Forms::TextBox^ user_name_textBox;
	private: System::Windows::Forms::Label^ phone_label;


	private: System::Windows::Forms::Label^ password_signup_label;

	private: System::Windows::Forms::TextBox^ phone_textBox;
	private: System::Windows::Forms::Label^ username_signup_label;


	private: System::Windows::Forms::TextBox^ name_textBox;
	private: System::Windows::Forms::PictureBox^ hide_signup_pass;
	private: System::Windows::Forms::PictureBox^ hide_confirm_pass;



	private: System::Windows::Forms::TextBox^ password_textBox;
	private: System::Windows::Forms::TextBox^ confirm_textBox;
	private: System::Windows::Forms::LinkLabel^ sign_in_link;




	private: System::Windows::Forms::Panel^ sign_in_panel;
	private: System::Windows::Forms::Label^ password_signin_label;

	private: System::Windows::Forms::Label^ username_signin_label;

	private: System::Windows::Forms::Label^ welcome_back;

	private: System::Windows::Forms::PictureBox^ pictureBox7;
	private: System::Windows::Forms::LinkLabel^ sign_up_link;

	private: System::Windows::Forms::PictureBox^ pictureBox10;
	private: System::Windows::Forms::Label^ didnot_have_acc;

	private: System::Windows::Forms::Button^ Login;

	private: System::Windows::Forms::LinkLabel^ forget_pass;
private: System::Windows::Forms::TextBox^ name;
private: System::Windows::Forms::TextBox^ password;
private: System::Windows::Forms::PictureBox^ view_password_signin;
private: System::Windows::Forms::PictureBox^ hide_password_signin;
private: System::Windows::Forms::Panel^ forgetPassword_panel;

private: System::Windows::Forms::Button^ change_password_Button;

private: System::Windows::Forms::PictureBox^ pictureBoxPH;
private: System::Windows::Forms::PictureBox^ pictureBoxCH;
private: System::Windows::Forms::PictureBox^ pictureBoxPS;
private: System::Windows::Forms::PictureBox^ pictureBoxCS;
private: System::Windows::Forms::TextBox^ confirmpassword;
private: System::Windows::Forms::TextBox^ password_forget;


private: System::Windows::Forms::Label^ label4;
private: System::Windows::Forms::Label^ label3;
private: System::Windows::Forms::TextBox^ phonenumber;
private: System::Windows::Forms::Label^ add_flight_label;
private: System::Windows::Forms::TextBox^ username_forget;

private: System::Windows::Forms::Label^ label1;
private: System::Windows::Forms::Label^ forgetpass_label;
private: System::Windows::Forms::CheckBox^ admin_checkBox;
private: System::Windows::Forms::LinkLabel^ sign_in;
private: System::Windows::Forms::Label^ remember_password;















	protected:





















	protected:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(sign_up_users_form::typeid));
			this->sign_up_label = (gcnew System::Windows::Forms::Label());
			this->sign_up_panel = (gcnew System::Windows::Forms::Panel());
			this->sign_in_link = (gcnew System::Windows::Forms::LinkLabel());
			this->view_confirm_pass = (gcnew System::Windows::Forms::PictureBox());
			this->view_signup_pass = (gcnew System::Windows::Forms::PictureBox());
			this->have_account = (gcnew System::Windows::Forms::Label());
			this->sign_up_button = (gcnew System::Windows::Forms::Button());
			this->confirm_label = (gcnew System::Windows::Forms::Label());
			this->name_signup_label = (gcnew System::Windows::Forms::Label());
			this->user_name_textBox = (gcnew System::Windows::Forms::TextBox());
			this->phone_label = (gcnew System::Windows::Forms::Label());
			this->password_signup_label = (gcnew System::Windows::Forms::Label());
			this->phone_textBox = (gcnew System::Windows::Forms::TextBox());
			this->username_signup_label = (gcnew System::Windows::Forms::Label());
			this->name_textBox = (gcnew System::Windows::Forms::TextBox());
			this->hide_signup_pass = (gcnew System::Windows::Forms::PictureBox());
			this->hide_confirm_pass = (gcnew System::Windows::Forms::PictureBox());
			this->password_textBox = (gcnew System::Windows::Forms::TextBox());
			this->confirm_textBox = (gcnew System::Windows::Forms::TextBox());
			this->sign_in_panel = (gcnew System::Windows::Forms::Panel());
			this->admin_checkBox = (gcnew System::Windows::Forms::CheckBox());
			this->view_password_signin = (gcnew System::Windows::Forms::PictureBox());
			this->hide_password_signin = (gcnew System::Windows::Forms::PictureBox());
			this->password = (gcnew System::Windows::Forms::TextBox());
			this->name = (gcnew System::Windows::Forms::TextBox());
			this->password_signin_label = (gcnew System::Windows::Forms::Label());
			this->username_signin_label = (gcnew System::Windows::Forms::Label());
			this->welcome_back = (gcnew System::Windows::Forms::Label());
			this->pictureBox7 = (gcnew System::Windows::Forms::PictureBox());
			this->sign_up_link = (gcnew System::Windows::Forms::LinkLabel());
			this->pictureBox10 = (gcnew System::Windows::Forms::PictureBox());
			this->didnot_have_acc = (gcnew System::Windows::Forms::Label());
			this->Login = (gcnew System::Windows::Forms::Button());
			this->forget_pass = (gcnew System::Windows::Forms::LinkLabel());
			this->forgetPassword_panel = (gcnew System::Windows::Forms::Panel());
			this->forgetpass_label = (gcnew System::Windows::Forms::Label());
			this->change_password_Button = (gcnew System::Windows::Forms::Button());
			this->pictureBoxPH = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxCH = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxPS = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxCS = (gcnew System::Windows::Forms::PictureBox());
			this->confirmpassword = (gcnew System::Windows::Forms::TextBox());
			this->password_forget = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->phonenumber = (gcnew System::Windows::Forms::TextBox());
			this->add_flight_label = (gcnew System::Windows::Forms::Label());
			this->username_forget = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->sign_in = (gcnew System::Windows::Forms::LinkLabel());
			this->remember_password = (gcnew System::Windows::Forms::Label());
			this->sign_up_panel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->view_confirm_pass))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->view_signup_pass))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->hide_signup_pass))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->hide_confirm_pass))->BeginInit();
			this->sign_in_panel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->view_password_signin))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->hide_password_signin))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox10))->BeginInit();
			this->forgetPassword_panel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxPH))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxCH))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxPS))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxCS))->BeginInit();
			this->SuspendLayout();
			// 
			// sign_up_label
			// 
			this->sign_up_label->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->sign_up_label->AutoSize = true;
			this->sign_up_label->BackColor = System::Drawing::Color::Transparent;
			this->sign_up_label->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->sign_up_label->ForeColor = System::Drawing::Color::White;
			this->sign_up_label->Location = System::Drawing::Point(176, 20);
			this->sign_up_label->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->sign_up_label->Name = L"sign_up_label";
			this->sign_up_label->Size = System::Drawing::Size(253, 76);
			this->sign_up_label->TabIndex = 12;
			this->sign_up_label->Text = L"Sign Up";
			// 
			// sign_up_panel
			// 
			this->sign_up_panel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)), static_cast<System::Int32>(static_cast<System::Byte>(210)),
				static_cast<System::Int32>(static_cast<System::Byte>(216)), static_cast<System::Int32>(static_cast<System::Byte>(228)));
			this->sign_up_panel->Controls->Add(this->sign_in_link);
			this->sign_up_panel->Controls->Add(this->sign_up_label);
			this->sign_up_panel->Controls->Add(this->view_confirm_pass);
			this->sign_up_panel->Controls->Add(this->view_signup_pass);
			this->sign_up_panel->Controls->Add(this->have_account);
			this->sign_up_panel->Controls->Add(this->sign_up_button);
			this->sign_up_panel->Controls->Add(this->confirm_label);
			this->sign_up_panel->Controls->Add(this->name_signup_label);
			this->sign_up_panel->Controls->Add(this->user_name_textBox);
			this->sign_up_panel->Controls->Add(this->phone_label);
			this->sign_up_panel->Controls->Add(this->password_signup_label);
			this->sign_up_panel->Controls->Add(this->phone_textBox);
			this->sign_up_panel->Controls->Add(this->username_signup_label);
			this->sign_up_panel->Controls->Add(this->name_textBox);
			this->sign_up_panel->Controls->Add(this->hide_signup_pass);
			this->sign_up_panel->Controls->Add(this->hide_confirm_pass);
			this->sign_up_panel->Controls->Add(this->password_textBox);
			this->sign_up_panel->Controls->Add(this->confirm_textBox);
			this->sign_up_panel->Location = System::Drawing::Point(1, 80);
			this->sign_up_panel->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->sign_up_panel->Name = L"sign_up_panel";
			this->sign_up_panel->Size = System::Drawing::Size(531, 560);
			this->sign_up_panel->TabIndex = 11;
			this->sign_up_panel->Visible = false;
			// 
			// sign_in_link
			// 
			this->sign_in_link->BackColor = System::Drawing::Color::Transparent;
			this->sign_in_link->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->sign_in_link->Location = System::Drawing::Point(343, 493);
			this->sign_in_link->Name = L"sign_in_link";
			this->sign_in_link->Size = System::Drawing::Size(62, 20);
			this->sign_in_link->TabIndex = 22;
			this->sign_in_link->TabStop = true;
			this->sign_in_link->Text = L"sign in";
			this->sign_in_link->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &sign_up_users_form::sign_in_link_LinkClicked);
			// 
			// view_confirm_pass
			// 
			this->view_confirm_pass->BackColor = System::Drawing::Color::White;
			this->view_confirm_pass->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"view_confirm_pass.Image")));
			this->view_confirm_pass->Location = System::Drawing::Point(476, 326);
			this->view_confirm_pass->Name = L"view_confirm_pass";
			this->view_confirm_pass->Size = System::Drawing::Size(33, 30);
			this->view_confirm_pass->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->view_confirm_pass->TabIndex = 14;
			this->view_confirm_pass->TabStop = false;
			this->view_confirm_pass->Click += gcnew System::EventHandler(this, &sign_up_users_form::view_confirm_pass_Click);
			// 
			// view_signup_pass
			// 
			this->view_signup_pass->BackColor = System::Drawing::Color::White;
			this->view_signup_pass->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"view_signup_pass.Image")));
			this->view_signup_pass->Location = System::Drawing::Point(476, 257);
			this->view_signup_pass->Name = L"view_signup_pass";
			this->view_signup_pass->Size = System::Drawing::Size(33, 30);
			this->view_signup_pass->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->view_signup_pass->TabIndex = 13;
			this->view_signup_pass->TabStop = false;
			this->view_signup_pass->Click += gcnew System::EventHandler(this, &sign_up_users_form::view_signup_pass_click);
			// 
			// have_account
			// 
			this->have_account->AutoSize = true;
			this->have_account->BackColor = System::Drawing::Color::Transparent;
			this->have_account->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->have_account->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(49)), static_cast<System::Int32>(static_cast<System::Byte>(52)),
				static_cast<System::Int32>(static_cast<System::Byte>(69)));
			this->have_account->Location = System::Drawing::Point(120, 493);
			this->have_account->Name = L"have_account";
			this->have_account->Size = System::Drawing::Size(223, 20);
			this->have_account->TabIndex = 11;
			this->have_account->Text = L"already have an account\?";
			// 
			// sign_up_button
			// 
			this->sign_up_button->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->sign_up_button->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(7)), static_cast<System::Int32>(static_cast<System::Byte>(85)),
				static_cast<System::Int32>(static_cast<System::Byte>(184)));
			this->sign_up_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->sign_up_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->sign_up_button->ForeColor = System::Drawing::Color::White;
			this->sign_up_button->Location = System::Drawing::Point(50, 445);
			this->sign_up_button->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->sign_up_button->Name = L"sign_up_button";
			this->sign_up_button->Size = System::Drawing::Size(428, 45);
			this->sign_up_button->TabIndex = 5;
			this->sign_up_button->Text = L"Sign up";
			this->sign_up_button->UseVisualStyleBackColor = false;
			this->sign_up_button->Click += gcnew System::EventHandler(this, &sign_up_users_form::sign_up_button_Click);
			// 
			// confirm_label
			// 
			this->confirm_label->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->confirm_label->AutoSize = true;
			this->confirm_label->BackColor = System::Drawing::Color::Transparent;
			this->confirm_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->confirm_label->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(49)), static_cast<System::Int32>(static_cast<System::Byte>(52)),
				static_cast<System::Int32>(static_cast<System::Byte>(69)));
			this->confirm_label->Location = System::Drawing::Point(19, 301);
			this->confirm_label->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->confirm_label->Name = L"confirm_label";
			this->confirm_label->Size = System::Drawing::Size(129, 22);
			this->confirm_label->TabIndex = 10;
			this->confirm_label->Text = L"Confirm Pass";
			// 
			// name_signup_label
			// 
			this->name_signup_label->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->name_signup_label->AutoSize = true;
			this->name_signup_label->BackColor = System::Drawing::Color::Transparent;
			this->name_signup_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->name_signup_label->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(49)),
				static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(69)));
			this->name_signup_label->Location = System::Drawing::Point(19, 94);
			this->name_signup_label->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->name_signup_label->Name = L"name_signup_label";
			this->name_signup_label->Size = System::Drawing::Size(61, 22);
			this->name_signup_label->TabIndex = 4;
			this->name_signup_label->Text = L"Name";
			// 
			// user_name_textBox
			// 
			this->user_name_textBox->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->user_name_textBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->user_name_textBox->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->user_name_textBox->Location = System::Drawing::Point(23, 188);
			this->user_name_textBox->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->user_name_textBox->Name = L"user_name_textBox";
			this->user_name_textBox->Size = System::Drawing::Size(486, 38);
			this->user_name_textBox->TabIndex = 1;
			this->user_name_textBox->Text = L"Enter Your Username";
			this->user_name_textBox->Enter += gcnew System::EventHandler(this, &sign_up_users_form::user_name_textBox_Enter);
			this->user_name_textBox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &sign_up_users_form::name_textBox_KeyDown);
			this->user_name_textBox->Leave += gcnew System::EventHandler(this, &sign_up_users_form::user_name_textBox_Leave);
			// 
			// phone_label
			// 
			this->phone_label->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->phone_label->AutoSize = true;
			this->phone_label->BackColor = System::Drawing::Color::Transparent;
			this->phone_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->phone_label->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(49)), static_cast<System::Int32>(static_cast<System::Byte>(52)),
				static_cast<System::Int32>(static_cast<System::Byte>(69)));
			this->phone_label->Location = System::Drawing::Point(19, 370);
			this->phone_label->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->phone_label->Name = L"phone_label";
			this->phone_label->Size = System::Drawing::Size(67, 22);
			this->phone_label->TabIndex = 7;
			this->phone_label->Text = L"Phone";
			// 
			// password_signup_label
			// 
			this->password_signup_label->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->password_signup_label->AutoSize = true;
			this->password_signup_label->BackColor = System::Drawing::Color::Transparent;
			this->password_signup_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->password_signup_label->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(49)),
				static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(69)));
			this->password_signup_label->Location = System::Drawing::Point(19, 232);
			this->password_signup_label->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->password_signup_label->Name = L"password_signup_label";
			this->password_signup_label->Size = System::Drawing::Size(97, 22);
			this->password_signup_label->TabIndex = 6;
			this->password_signup_label->Text = L"Password";
			// 
			// phone_textBox
			// 
			this->phone_textBox->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->phone_textBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->phone_textBox->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->phone_textBox->Location = System::Drawing::Point(23, 395);
			this->phone_textBox->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->phone_textBox->Name = L"phone_textBox";
			this->phone_textBox->Size = System::Drawing::Size(486, 38);
			this->phone_textBox->TabIndex = 4;
			this->phone_textBox->Text = L"Enter Phone Number";
			this->phone_textBox->Enter += gcnew System::EventHandler(this, &sign_up_users_form::phone_textBox_Enter);
			this->phone_textBox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &sign_up_users_form::name_textBox_KeyDown);
			this->phone_textBox->Leave += gcnew System::EventHandler(this, &sign_up_users_form::phone_textBox_Leave);
			// 
			// username_signup_label
			// 
			this->username_signup_label->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->username_signup_label->AutoSize = true;
			this->username_signup_label->BackColor = System::Drawing::Color::Transparent;
			this->username_signup_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->username_signup_label->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(49)),
				static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(69)));
			this->username_signup_label->Location = System::Drawing::Point(19, 163);
			this->username_signup_label->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->username_signup_label->Name = L"username_signup_label";
			this->username_signup_label->Size = System::Drawing::Size(106, 22);
			this->username_signup_label->TabIndex = 5;
			this->username_signup_label->Text = L"User name";
			// 
			// name_textBox
			// 
			this->name_textBox->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->name_textBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->name_textBox->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->name_textBox->Location = System::Drawing::Point(23, 119);
			this->name_textBox->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->name_textBox->Name = L"name_textBox";
			this->name_textBox->Size = System::Drawing::Size(486, 38);
			this->name_textBox->TabIndex = 0;
			this->name_textBox->Text = L"Enter Your Name";
			this->name_textBox->Enter += gcnew System::EventHandler(this, &sign_up_users_form::name_textBox_Enter);
			this->name_textBox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &sign_up_users_form::name_textBox_KeyDown);
			this->name_textBox->Leave += gcnew System::EventHandler(this, &sign_up_users_form::name_textBox_Leave);
			// 
			// hide_signup_pass
			// 
			this->hide_signup_pass->BackColor = System::Drawing::Color::White;
			this->hide_signup_pass->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"hide_signup_pass.Image")));
			this->hide_signup_pass->Location = System::Drawing::Point(476, 257);
			this->hide_signup_pass->Name = L"hide_signup_pass";
			this->hide_signup_pass->Size = System::Drawing::Size(33, 30);
			this->hide_signup_pass->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->hide_signup_pass->TabIndex = 21;
			this->hide_signup_pass->TabStop = false;
			this->hide_signup_pass->Click += gcnew System::EventHandler(this, &sign_up_users_form::hide_signup_pass_Click);
			// 
			// hide_confirm_pass
			// 
			this->hide_confirm_pass->BackColor = System::Drawing::Color::White;
			this->hide_confirm_pass->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"hide_confirm_pass.Image")));
			this->hide_confirm_pass->Location = System::Drawing::Point(476, 326);
			this->hide_confirm_pass->Name = L"hide_confirm_pass";
			this->hide_confirm_pass->Size = System::Drawing::Size(33, 30);
			this->hide_confirm_pass->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->hide_confirm_pass->TabIndex = 20;
			this->hide_confirm_pass->TabStop = false;
			this->hide_confirm_pass->Click += gcnew System::EventHandler(this, &sign_up_users_form::hide_confirm_pass_Click);
			// 
			// password_textBox
			// 
			this->password_textBox->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->password_textBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->password_textBox->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->password_textBox->Location = System::Drawing::Point(23, 257);
			this->password_textBox->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->password_textBox->Name = L"password_textBox";
			this->password_textBox->Size = System::Drawing::Size(486, 38);
			this->password_textBox->TabIndex = 2;
			this->password_textBox->Text = L"Enter Password";
			this->password_textBox->Enter += gcnew System::EventHandler(this, &sign_up_users_form::password_textBox_Enter);
			this->password_textBox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &sign_up_users_form::name_textBox_KeyDown);
			this->password_textBox->Leave += gcnew System::EventHandler(this, &sign_up_users_form::password_textBox_Leave);
			// 
			// confirm_textBox
			// 
			this->confirm_textBox->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->confirm_textBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->confirm_textBox->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->confirm_textBox->Location = System::Drawing::Point(23, 326);
			this->confirm_textBox->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->confirm_textBox->Name = L"confirm_textBox";
			this->confirm_textBox->Size = System::Drawing::Size(486, 38);
			this->confirm_textBox->TabIndex = 3;
			this->confirm_textBox->Text = L"Confirm Password";
			this->confirm_textBox->Enter += gcnew System::EventHandler(this, &sign_up_users_form::confirm_textBox_Enter);
			this->confirm_textBox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &sign_up_users_form::name_textBox_KeyDown);
			this->confirm_textBox->Leave += gcnew System::EventHandler(this, &sign_up_users_form::confirm_textBox_Leave);
			// 
			// sign_in_panel
			// 
			this->sign_in_panel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)), static_cast<System::Int32>(static_cast<System::Byte>(210)),
				static_cast<System::Int32>(static_cast<System::Byte>(216)), static_cast<System::Int32>(static_cast<System::Byte>(228)));
			this->sign_in_panel->Controls->Add(this->admin_checkBox);
			this->sign_in_panel->Controls->Add(this->view_password_signin);
			this->sign_in_panel->Controls->Add(this->hide_password_signin);
			this->sign_in_panel->Controls->Add(this->password);
			this->sign_in_panel->Controls->Add(this->name);
			this->sign_in_panel->Controls->Add(this->password_signin_label);
			this->sign_in_panel->Controls->Add(this->username_signin_label);
			this->sign_in_panel->Controls->Add(this->welcome_back);
			this->sign_in_panel->Controls->Add(this->pictureBox7);
			this->sign_in_panel->Controls->Add(this->sign_up_link);
			this->sign_in_panel->Controls->Add(this->pictureBox10);
			this->sign_in_panel->Controls->Add(this->didnot_have_acc);
			this->sign_in_panel->Controls->Add(this->Login);
			this->sign_in_panel->Controls->Add(this->forget_pass);
			this->sign_in_panel->Location = System::Drawing::Point(539, 24);
			this->sign_in_panel->MaximumSize = System::Drawing::Size(568, 412);
			this->sign_in_panel->Name = L"sign_in_panel";
			this->sign_in_panel->Size = System::Drawing::Size(568, 412);
			this->sign_in_panel->TabIndex = 16;
			// 
			// admin_checkBox
			// 
			this->admin_checkBox->AutoSize = true;
			this->admin_checkBox->BackColor = System::Drawing::Color::Transparent;
			this->admin_checkBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->admin_checkBox->Location = System::Drawing::Point(61, 259);
			this->admin_checkBox->Name = L"admin_checkBox";
			this->admin_checkBox->Size = System::Drawing::Size(187, 24);
			this->admin_checkBox->TabIndex = 23;
			this->admin_checkBox->Text = L"Are you an admin\?";
			this->admin_checkBox->UseVisualStyleBackColor = false;
			this->admin_checkBox->CheckStateChanged += gcnew System::EventHandler(this, &sign_up_users_form::admin_checkBox_CheckStateChanged);
			// 
			// view_password_signin
			// 
			this->view_password_signin->BackColor = System::Drawing::Color::White;
			this->view_password_signin->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"view_password_signin.Image")));
			this->view_password_signin->Location = System::Drawing::Point(513, 213);
			this->view_password_signin->Name = L"view_password_signin";
			this->view_password_signin->Size = System::Drawing::Size(33, 30);
			this->view_password_signin->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->view_password_signin->TabIndex = 21;
			this->view_password_signin->TabStop = false;
			this->view_password_signin->Click += gcnew System::EventHandler(this, &sign_up_users_form::password_signin_view_Click);
			// 
			// hide_password_signin
			// 
			this->hide_password_signin->BackColor = System::Drawing::Color::White;
			this->hide_password_signin->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"hide_password_signin.Image")));
			this->hide_password_signin->Location = System::Drawing::Point(513, 213);
			this->hide_password_signin->Name = L"hide_password_signin";
			this->hide_password_signin->Size = System::Drawing::Size(33, 30);
			this->hide_password_signin->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->hide_password_signin->TabIndex = 22;
			this->hide_password_signin->TabStop = false;
			this->hide_password_signin->Click += gcnew System::EventHandler(this, &sign_up_users_form::hide_password_signin_Click);
			// 
			// password
			// 
			this->password->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->password->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->password->Location = System::Drawing::Point(60, 213);
			this->password->Name = L"password";
			this->password->Size = System::Drawing::Size(486, 38);
			this->password->TabIndex = 1;
			this->password->Text = L"Password";
			this->password->Enter += gcnew System::EventHandler(this, &sign_up_users_form::password_Enter);
			this->password->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &sign_up_users_form::name_KeyDown);
			this->password->Leave += gcnew System::EventHandler(this, &sign_up_users_form::password_Leave);
			// 
			// name
			// 
			this->name->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->name->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->name->Location = System::Drawing::Point(60, 137);
			this->name->Name = L"name";
			this->name->Size = System::Drawing::Size(486, 38);
			this->name->TabIndex = 0;
			this->name->Text = L"Username";
			this->name->Enter += gcnew System::EventHandler(this, &sign_up_users_form::name_Enter);
			this->name->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &sign_up_users_form::name_KeyDown);
			this->name->Leave += gcnew System::EventHandler(this, &sign_up_users_form::name_Leave);
			// 
			// password_signin_label
			// 
			this->password_signin_label->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->password_signin_label->AutoSize = true;
			this->password_signin_label->BackColor = System::Drawing::Color::Transparent;
			this->password_signin_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->password_signin_label->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(49)),
				static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(69)));
			this->password_signin_label->Location = System::Drawing::Point(23, 187);
			this->password_signin_label->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->password_signin_label->Name = L"password_signin_label";
			this->password_signin_label->Size = System::Drawing::Size(97, 22);
			this->password_signin_label->TabIndex = 15;
			this->password_signin_label->Text = L"Password";
			// 
			// username_signin_label
			// 
			this->username_signin_label->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->username_signin_label->AutoSize = true;
			this->username_signin_label->BackColor = System::Drawing::Color::Transparent;
			this->username_signin_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->username_signin_label->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(49)),
				static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(69)));
			this->username_signin_label->Location = System::Drawing::Point(23, 110);
			this->username_signin_label->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->username_signin_label->Name = L"username_signin_label";
			this->username_signin_label->Size = System::Drawing::Size(106, 22);
			this->username_signin_label->TabIndex = 14;
			this->username_signin_label->Text = L"User name";
			// 
			// welcome_back
			// 
			this->welcome_back->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->welcome_back->AutoSize = true;
			this->welcome_back->BackColor = System::Drawing::Color::Transparent;
			this->welcome_back->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->welcome_back->ForeColor = System::Drawing::Color::White;
			this->welcome_back->Location = System::Drawing::Point(102, 34);
			this->welcome_back->Name = L"welcome_back";
			this->welcome_back->Size = System::Drawing::Size(444, 76);
			this->welcome_back->TabIndex = 13;
			this->welcome_back->Text = L"Welcome Back";
			this->welcome_back->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// pictureBox7
			// 
			this->pictureBox7->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox7->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->pictureBox7->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox7.Image")));
			this->pictureBox7->Location = System::Drawing::Point(27, 136);
			this->pictureBox7->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox7->Name = L"pictureBox7";
			this->pictureBox7->Size = System::Drawing::Size(32, 38);
			this->pictureBox7->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox7->TabIndex = 8;
			this->pictureBox7->TabStop = false;
			// 
			// sign_up_link
			// 
			this->sign_up_link->BackColor = System::Drawing::Color::Transparent;
			this->sign_up_link->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->sign_up_link->Location = System::Drawing::Point(323, 365);
			this->sign_up_link->Name = L"sign_up_link";
			this->sign_up_link->Size = System::Drawing::Size(68, 26);
			this->sign_up_link->TabIndex = 12;
			this->sign_up_link->TabStop = true;
			this->sign_up_link->Text = L"sign up";
			this->sign_up_link->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &sign_up_users_form::sign_up_link_LinkClicked);
			// 
			// pictureBox10
			// 
			this->pictureBox10->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox10->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox10->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox10.Image")));
			this->pictureBox10->Location = System::Drawing::Point(27, 212);
			this->pictureBox10->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox10->Name = L"pictureBox10";
			this->pictureBox10->Size = System::Drawing::Size(32, 38);
			this->pictureBox10->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox10->TabIndex = 10;
			this->pictureBox10->TabStop = false;
			// 
			// didnot_have_acc
			// 
			this->didnot_have_acc->BackColor = System::Drawing::Color::Transparent;
			this->didnot_have_acc->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->didnot_have_acc->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(49)), static_cast<System::Int32>(static_cast<System::Byte>(52)),
				static_cast<System::Int32>(static_cast<System::Byte>(69)));
			this->didnot_have_acc->Location = System::Drawing::Point(122, 365);
			this->didnot_have_acc->Name = L"didnot_have_acc";
			this->didnot_have_acc->Size = System::Drawing::Size(208, 26);
			this->didnot_have_acc->TabIndex = 11;
			this->didnot_have_acc->Text = L"didn\'t have an acount\?";
			// 
			// Login
			// 
			this->Login->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(7)), static_cast<System::Int32>(static_cast<System::Byte>(85)),
				static_cast<System::Int32>(static_cast<System::Byte>(184)));
			this->Login->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->Login->Cursor = System::Windows::Forms::Cursors::Default;
			this->Login->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Login->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Login->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->Login->Location = System::Drawing::Point(51, 320);
			this->Login->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Login->Name = L"Login";
			this->Login->Size = System::Drawing::Size(467, 43);
			this->Login->TabIndex = 2;
			this->Login->Text = L"Sign in";
			this->Login->UseVisualStyleBackColor = false;
			this->Login->Click += gcnew System::EventHandler(this, &sign_up_users_form::Login_Click);
			// 
			// forget_pass
			// 
			this->forget_pass->BackColor = System::Drawing::Color::Transparent;
			this->forget_pass->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->forget_pass->Location = System::Drawing::Point(179, 293);
			this->forget_pass->Name = L"forget_pass";
			this->forget_pass->Size = System::Drawing::Size(211, 25);
			this->forget_pass->TabIndex = 4;
			this->forget_pass->TabStop = true;
			this->forget_pass->Text = L"Forget password\?";
			this->forget_pass->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->forget_pass->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &sign_up_users_form::forget_pass_LinkClicked);
			// 
			// forgetPassword_panel
			// 
			this->forgetPassword_panel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)),
				static_cast<System::Int32>(static_cast<System::Byte>(210)), static_cast<System::Int32>(static_cast<System::Byte>(216)), static_cast<System::Int32>(static_cast<System::Byte>(228)));
			this->forgetPassword_panel->Controls->Add(this->sign_in);
			this->forgetPassword_panel->Controls->Add(this->remember_password);
			this->forgetPassword_panel->Controls->Add(this->forgetpass_label);
			this->forgetPassword_panel->Controls->Add(this->change_password_Button);
			this->forgetPassword_panel->Controls->Add(this->pictureBoxPH);
			this->forgetPassword_panel->Controls->Add(this->pictureBoxCH);
			this->forgetPassword_panel->Controls->Add(this->pictureBoxPS);
			this->forgetPassword_panel->Controls->Add(this->pictureBoxCS);
			this->forgetPassword_panel->Controls->Add(this->confirmpassword);
			this->forgetPassword_panel->Controls->Add(this->password_forget);
			this->forgetPassword_panel->Controls->Add(this->label4);
			this->forgetPassword_panel->Controls->Add(this->label3);
			this->forgetPassword_panel->Controls->Add(this->phonenumber);
			this->forgetPassword_panel->Controls->Add(this->add_flight_label);
			this->forgetPassword_panel->Controls->Add(this->username_forget);
			this->forgetPassword_panel->Controls->Add(this->label1);
			this->forgetPassword_panel->Location = System::Drawing::Point(1113, 11);
			this->forgetPassword_panel->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->forgetPassword_panel->MaximumSize = System::Drawing::Size(648, 491);
			this->forgetPassword_panel->Name = L"forgetPassword_panel";
			this->forgetPassword_panel->Size = System::Drawing::Size(648, 491);
			this->forgetPassword_panel->TabIndex = 17;
			this->forgetPassword_panel->Visible = false;
			// 
			// forgetpass_label
			// 
			this->forgetpass_label->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->forgetpass_label->AutoSize = true;
			this->forgetpass_label->BackColor = System::Drawing::Color::Transparent;
			this->forgetpass_label->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->forgetpass_label->ForeColor = System::Drawing::Color::White;
			this->forgetpass_label->Location = System::Drawing::Point(125, 30);
			this->forgetpass_label->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->forgetpass_label->MaximumSize = System::Drawing::Size(500, 76);
			this->forgetpass_label->Name = L"forgetpass_label";
			this->forgetpass_label->Size = System::Drawing::Size(500, 76);
			this->forgetpass_label->TabIndex = 9;
			this->forgetpass_label->Text = L"Forget Password";
			// 
			// change_password_Button
			// 
			this->change_password_Button->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(7)),
				static_cast<System::Int32>(static_cast<System::Byte>(85)), static_cast<System::Int32>(static_cast<System::Byte>(184)));
			this->change_password_Button->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->change_password_Button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->change_password_Button->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->change_password_Button->Location = System::Drawing::Point(62, 408);
			this->change_password_Button->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->change_password_Button->Name = L"change_password_Button";
			this->change_password_Button->Size = System::Drawing::Size(524, 49);
			this->change_password_Button->TabIndex = 4;
			this->change_password_Button->Text = L"Change password";
			this->change_password_Button->UseVisualStyleBackColor = false;
			this->change_password_Button->Click += gcnew System::EventHandler(this, &sign_up_users_form::change_password_Button_Click);
			// 
			// pictureBoxPH
			// 
			this->pictureBoxPH->BackColor = System::Drawing::Color::White;
			this->pictureBoxPH->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->pictureBoxPH->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxPH.Image")));
			this->pictureBoxPH->Location = System::Drawing::Point(574, 289);
			this->pictureBoxPH->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBoxPH->Name = L"pictureBoxPH";
			this->pictureBoxPH->Size = System::Drawing::Size(31, 28);
			this->pictureBoxPH->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBoxPH->TabIndex = 13;
			this->pictureBoxPH->TabStop = false;
			this->pictureBoxPH->Click += gcnew System::EventHandler(this, &sign_up_users_form::pictureBoxPH_Click);
			// 
			// pictureBoxCH
			// 
			this->pictureBoxCH->BackColor = System::Drawing::Color::White;
			this->pictureBoxCH->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->pictureBoxCH->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxCH.Image")));
			this->pictureBoxCH->Location = System::Drawing::Point(574, 357);
			this->pictureBoxCH->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBoxCH->Name = L"pictureBoxCH";
			this->pictureBoxCH->Size = System::Drawing::Size(31, 28);
			this->pictureBoxCH->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBoxCH->TabIndex = 12;
			this->pictureBoxCH->TabStop = false;
			this->pictureBoxCH->Click += gcnew System::EventHandler(this, &sign_up_users_form::pictureBoxCH_Click);
			// 
			// pictureBoxPS
			// 
			this->pictureBoxPS->BackColor = System::Drawing::Color::White;
			this->pictureBoxPS->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->pictureBoxPS->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxPS.Image")));
			this->pictureBoxPS->Location = System::Drawing::Point(575, 289);
			this->pictureBoxPS->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBoxPS->Name = L"pictureBoxPS";
			this->pictureBoxPS->Size = System::Drawing::Size(31, 28);
			this->pictureBoxPS->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBoxPS->TabIndex = 11;
			this->pictureBoxPS->TabStop = false;
			this->pictureBoxPS->Click += gcnew System::EventHandler(this, &sign_up_users_form::pictureBoxPS_Click);
			// 
			// pictureBoxCS
			// 
			this->pictureBoxCS->BackColor = System::Drawing::Color::White;
			this->pictureBoxCS->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->pictureBoxCS->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxCS.Image")));
			this->pictureBoxCS->Location = System::Drawing::Point(574, 357);
			this->pictureBoxCS->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBoxCS->Name = L"pictureBoxCS";
			this->pictureBoxCS->Size = System::Drawing::Size(31, 28);
			this->pictureBoxCS->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBoxCS->TabIndex = 10;
			this->pictureBoxCS->TabStop = false;
			this->pictureBoxCS->Click += gcnew System::EventHandler(this, &sign_up_users_form::pictureBoxCS_Click);
			// 
			// confirmpassword
			// 
			this->confirmpassword->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->confirmpassword->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->confirmpassword->Location = System::Drawing::Point(44, 357);
			this->confirmpassword->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->confirmpassword->Name = L"confirmpassword";
			this->confirmpassword->Size = System::Drawing::Size(561, 38);
			this->confirmpassword->TabIndex = 3;
			this->confirmpassword->Text = L"Confirm Your Password";
			this->confirmpassword->Enter += gcnew System::EventHandler(this, &sign_up_users_form::confirm_forget_Enter);
			this->confirmpassword->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &sign_up_users_form::username_forget_KeyDown);
			this->confirmpassword->Leave += gcnew System::EventHandler(this, &sign_up_users_form::confirm_forget_Leave);
			// 
			// password_forget
			// 
			this->password_forget->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->password_forget->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->password_forget->Location = System::Drawing::Point(44, 289);
			this->password_forget->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->password_forget->Name = L"password_forget";
			this->password_forget->Size = System::Drawing::Size(561, 38);
			this->password_forget->TabIndex = 2;
			this->password_forget->Text = L"Enter Your Password";
			this->password_forget->Enter += gcnew System::EventHandler(this, &sign_up_users_form::password_forget_Enter);
			this->password_forget->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &sign_up_users_form::username_forget_KeyDown);
			this->password_forget->Leave += gcnew System::EventHandler(this, &sign_up_users_form::password_forget_Leave);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(49)), static_cast<System::Int32>(static_cast<System::Byte>(52)),
				static_cast<System::Int32>(static_cast<System::Byte>(69)));
			this->label4->Location = System::Drawing::Point(40, 335);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(170, 22);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Confirm password";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(49)), static_cast<System::Int32>(static_cast<System::Byte>(52)),
				static_cast<System::Int32>(static_cast<System::Byte>(69)));
			this->label3->Location = System::Drawing::Point(40, 267);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(97, 22);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Password";
			// 
			// phonenumber
			// 
			this->phonenumber->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->phonenumber->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->phonenumber->Location = System::Drawing::Point(44, 220);
			this->phonenumber->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->phonenumber->Name = L"phonenumber";
			this->phonenumber->Size = System::Drawing::Size(561, 38);
			this->phonenumber->TabIndex = 1;
			this->phonenumber->Text = L"Enter Your Phone Number";
			this->phonenumber->Enter += gcnew System::EventHandler(this, &sign_up_users_form::phonenumber_Enter);
			this->phonenumber->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &sign_up_users_form::username_forget_KeyDown);
			this->phonenumber->Leave += gcnew System::EventHandler(this, &sign_up_users_form::phonenumber_Leave);
			// 
			// add_flight_label
			// 
			this->add_flight_label->AutoSize = true;
			this->add_flight_label->BackColor = System::Drawing::Color::Transparent;
			this->add_flight_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->add_flight_label->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(49)), static_cast<System::Int32>(static_cast<System::Byte>(52)),
				static_cast<System::Int32>(static_cast<System::Byte>(69)));
			this->add_flight_label->Location = System::Drawing::Point(40, 197);
			this->add_flight_label->Name = L"add_flight_label";
			this->add_flight_label->Size = System::Drawing::Size(139, 22);
			this->add_flight_label->TabIndex = 6;
			this->add_flight_label->Text = L"Phone number";
			// 
			// username_forget
			// 
			this->username_forget->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->username_forget->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->username_forget->Location = System::Drawing::Point(44, 148);
			this->username_forget->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->username_forget->Name = L"username_forget";
			this->username_forget->Size = System::Drawing::Size(561, 38);
			this->username_forget->TabIndex = 0;
			this->username_forget->Text = L"Enter Your User Name";
			this->username_forget->Enter += gcnew System::EventHandler(this, &sign_up_users_form::username_forget_Enter);
			this->username_forget->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &sign_up_users_form::username_forget_KeyDown);
			this->username_forget->Leave += gcnew System::EventHandler(this, &sign_up_users_form::username_forget_Leave);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(49)), static_cast<System::Int32>(static_cast<System::Byte>(52)),
				static_cast<System::Int32>(static_cast<System::Byte>(69)));
			this->label1->Location = System::Drawing::Point(40, 123);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(106, 22);
			this->label1->TabIndex = 5;
			this->label1->Text = L"User name";
			// 
			// sign_in
			// 
			this->sign_in->BackColor = System::Drawing::Color::Transparent;
			this->sign_in->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->sign_in->Location = System::Drawing::Point(431, 459);
			this->sign_in->Name = L"sign_in";
			this->sign_in->Size = System::Drawing::Size(62, 20);
			this->sign_in->TabIndex = 24;
			this->sign_in->TabStop = true;
			this->sign_in->Text = L"sign in";
			this->sign_in->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &sign_up_users_form::sign_in_link_LinkClicked);
			// 
			// remember_password
			// 
			this->remember_password->AutoSize = true;
			this->remember_password->BackColor = System::Drawing::Color::Transparent;
			this->remember_password->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->remember_password->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(49)),
				static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(69)));
			this->remember_password->Location = System::Drawing::Point(126, 459);
			this->remember_password->Name = L"remember_password";
			this->remember_password->Size = System::Drawing::Size(301, 20);
			this->remember_password->TabIndex = 23;
			this->remember_password->Text = L"Did you remember your password\?";
			// 
			// sign_up_users_form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->ClientSize = System::Drawing::Size(1924, 737);
			this->Controls->Add(this->forgetPassword_panel);
			this->Controls->Add(this->sign_in_panel);
			this->Controls->Add(this->sign_up_panel);
			this->DoubleBuffered = true;
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->Name = L"sign_up_users_form";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Sign up";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &sign_up_users_form::sign_up_users_form_Load);
			this->Resize += gcnew System::EventHandler(this, &sign_up_users_form::sign_up_users_form_Resize);
			this->sign_up_panel->ResumeLayout(false);
			this->sign_up_panel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->view_confirm_pass))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->view_signup_pass))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->hide_signup_pass))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->hide_confirm_pass))->EndInit();
			this->sign_in_panel->ResumeLayout(false);
			this->sign_in_panel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->view_password_signin))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->hide_password_signin))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox10))->EndInit();
			this->forgetPassword_panel->ResumeLayout(false);
			this->forgetPassword_panel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxPH))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxCH))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxPS))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxCS))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	///form functions///
	private: System::Void sign_up_users_form_Load(System::Object^ sender, System::EventArgs^ e) {
		sign_up_panel->Left = (this->ClientSize.Width - sign_up_panel->Width) / 2;
		sign_up_panel->Top = (this->ClientSize.Height - sign_up_panel->Height) / 2;

		sign_in_panel->Left = (this->ClientSize.Width - sign_in_panel->Width) / 2;
		sign_in_panel->Top = (this->ClientSize.Height - sign_in_panel->Height) / 2;

		forgetPassword_panel->Left = (this->ClientSize.Width - forgetPassword_panel->Width) / 2;
		forgetPassword_panel->Top = (this->ClientSize.Height - forgetPassword_panel->Height) / 2;

	}
	private: System::Void sign_up_users_form_Resize(System::Object^ sender, System::EventArgs^ e) {
		sign_up_panel->Left = (this->ClientSize.Width - sign_up_panel->Width) / 2;
		sign_up_panel->Top = (this->ClientSize.Height - sign_up_panel->Height) / 2;

		sign_in_panel->Left = (this->ClientSize.Width - sign_in_panel->Width) / 2;
		sign_in_panel->Top = (this->ClientSize.Height - sign_in_panel->Height) / 2;

		forgetPassword_panel->Left = (this->ClientSize.Width - forgetPassword_panel->Width) / 2;
		forgetPassword_panel->Top = (this->ClientSize.Height - forgetPassword_panel->Height) / 2;
	}

	////sign up users functions////
	private: System::Void name_textBox_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::Enter)
		{
			this->SelectNextControl((Control^)sender, true, true, true, true);
			e->SuppressKeyPress = true;
		}
	}
	void password_textBox_leave() {
		if (password_textBox->Text == "")
		{
			password_textBox->Text = "Enter Password";
			password_textBox->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->password_textBox->PasswordChar = 0;
		}
	}
	void name_textBox_leave() {
		if (name_textBox->Text == "")
		{
			name_textBox->Text = "Enter Your Name";
			name_textBox->ForeColor = System::Drawing::SystemColors::ScrollBar;
		}
	}
	void user_name_textBox_leave() {
		if (user_name_textBox->Text == "")
		{
			user_name_textBox->Text = "Enter Your Username";
			user_name_textBox->ForeColor = System::Drawing::SystemColors::ScrollBar;
		}
	}
	void confirm_textBox_leave() {
		if (confirm_textBox->Text == "")
		{
			confirm_textBox->Text = "Confirm Password";
			confirm_textBox->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->confirm_textBox->PasswordChar = 0;
		}
	}
	void phone_textBox_leave() {
		if (phone_textBox->Text == "")
		{
			phone_textBox->Text = "Enter Phone Number";
			phone_textBox->ForeColor = System::Drawing::SystemColors::ScrollBar;
		}
	}
	private: System::Void sign_up_button_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ user_name = user_name_textBox->Text;
		Regex^ u_name_pattern = gcnew Regex("^[a-zA-Z0-9_]+$");

		String^ name = name_textBox->Text;
		Regex^ name_pattern = gcnew Regex("^[a-zA-Z ]+$");

		String^ pass = password_textBox->Text;
		Regex^ pass_pattern = gcnew Regex("^(?=.*[a-z])(?=.*[A-Z])(?=.*[0-9])(?=.*[!@#$%^&*()\\-_=+{}\\[\\]|\\\\:;\"'<>,.?/~]).+$");

		String^ phone = phone_textBox->Text;
		Regex^ phone_pattern = gcnew Regex("^[0-9 \\- +()]+$");

		if (name_textBox->Text == "Enter Your Name" ||
			user_name_textBox->Text == "Enter Your Username" ||
			password_textBox->Text == "Enter Password" ||
			confirm_textBox->Text == "Confirm Password" ||
			phone_textBox->Text == "Enter Phone Number")
		{
			MessageBox::Show("Please Enter All Data", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			new_user = false;
		}
		else if (!u_name_pattern->IsMatch(user_name) ||
			!name_pattern->IsMatch(name) || !pass_pattern->IsMatch(pass) ||
			!phone_pattern->IsMatch(phone)) 
		{
			MessageBox::Show("Invalid name or user name or password, phone. Please note that the password must contain at least: A capital letter, a small letter, a number and a special character(!,@,#,$,%,^,&,*...) and must be at least 8 characters!", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
		else if (password_textBox->Text != confirm_textBox->Text)
		{
			MessageBox::Show("Password doesn't match", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			new_user = false;
		}
		else {
			sign_up_user(name_textBox->Text, user_name_textBox->Text, password_textBox->Text, phone_textBox->Text);
			if (new_user == true)
			{
				MessageBox::Show("Account created successfully", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);

				name_textBox->Clear();
				user_name_textBox->Clear();
				password_textBox->Clear();
				confirm_textBox->Clear();
				phone_textBox->Clear();
				name_textBox_leave();
				user_name_textBox_leave();
				password_textBox_leave();
				confirm_textBox_leave();
				phone_textBox_leave();
				sign_up_panel->Visible = false;
				sign_in_panel->Visible = true;

				if (hide_signup_pass->Visible) {
					hide_signup_pass->Visible = false;
					view_signup_pass->Visible = true;
				}
				if (hide_confirm_pass->Visible) {
					hide_confirm_pass->Visible = false;
					view_confirm_pass->Visible = true;
				}
			}
			else if (!new_user)
			{
				MessageBox::Show("This account is already exist", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
		}
	}
	private: System::Void password_textBox_Enter(System::Object^ sender, System::EventArgs^ e) {

		if (password_textBox->Text == "Enter Password")
		{
			password_textBox->Text = "";
			password_textBox->ForeColor = System::Drawing::Color::Black;
			this->password_textBox->PasswordChar = '*';
		}
	}
	private: System::Void password_textBox_Leave(System::Object^ sender, System::EventArgs^ e) {
		password_textBox_leave();
	}
	private: System::Void name_textBox_Enter(System::Object^ sender, System::EventArgs^ e) {

		if (name_textBox->Text == "Enter Your Name")
		{
			name_textBox->Text = "";
			name_textBox->ForeColor = System::Drawing::Color::Black;
		}
	}
	private: System::Void name_textBox_Leave(System::Object^ sender, System::EventArgs^ e) {
		name_textBox_leave();
	}
	private: System::Void user_name_textBox_Leave(System::Object^ sender, System::EventArgs^ e) {
		user_name_textBox_leave();
	}
	private: System::Void user_name_textBox_Enter(System::Object^ sender, System::EventArgs^ e) {
		if (user_name_textBox->Text == "Enter Your Username")
		{
			user_name_textBox->Text = "";
			user_name_textBox->ForeColor = System::Drawing::Color::Black;
		}
	}
	private: System::Void confirm_textBox_Leave(System::Object^ sender, System::EventArgs^ e) {
		confirm_textBox_leave();
	}
	private: System::Void confirm_textBox_Enter(System::Object^ sender, System::EventArgs^ e) {
		if (confirm_textBox->Text == "Confirm Password")
		{
			confirm_textBox->Text = "";
			confirm_textBox->ForeColor = System::Drawing::Color::Black;
			this->confirm_textBox->PasswordChar = '*';
		}
	}
	private: System::Void phone_textBox_Leave(System::Object^ sender, System::EventArgs^ e) {
		phone_textBox_leave();
	}
	private: System::Void phone_textBox_Enter(System::Object^ sender, System::EventArgs^ e) {
		if (phone_textBox->Text == "Enter Phone Number")
		{
			phone_textBox->Text = "";
			phone_textBox->ForeColor = System::Drawing::Color::Black;
		}
	}
	private: System::Void view_signup_pass_click(System::Object^ sender, System::EventArgs^ e) {
		if (password_textBox->PasswordChar == '*')
		{
			this->password_textBox->PasswordChar = '\0';
			view_signup_pass->Visible = false;
			hide_signup_pass->Visible = true;
		}
	}
	private: System::Void hide_signup_pass_Click(System::Object^ sender, System::EventArgs^ e) {
		if (password_textBox->PasswordChar == '\0')
		{
			this->password_textBox->PasswordChar = '*';
			hide_signup_pass->Visible = false;
			view_signup_pass->Visible = true;
		}
	}
	private: System::Void view_confirm_pass_Click(System::Object^ sender, System::EventArgs^ e) {
		if (confirm_textBox->PasswordChar == '*')
		{
			this->confirm_textBox->PasswordChar = '\0';
			view_confirm_pass->Visible = false;
			hide_confirm_pass->Visible = true;
		}
	
	}
	private: System::Void hide_confirm_pass_Click(System::Object^ sender, System::EventArgs^ e) {
		if (confirm_textBox->PasswordChar == '\0')
		{
			this->confirm_textBox->PasswordChar = '*';
			hide_confirm_pass->Visible = false;
			view_confirm_pass->Visible = true;
		}
	}
	private: System::Void sign_in_link_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
		forgetPassword_panel->Visible = false;
		sign_up_panel->Visible = false;
		sign_in_panel->Visible = true;
		name_textBox->Text = "";
		user_name_textBox->Text = "";
		password_textBox->Text = "";
		confirm_textBox->Text = "";
		phone_textBox->Text = "";
		name_textBox_leave();
		user_name_textBox_leave();
		password_textBox_leave();
		confirm_textBox_leave();
		phone_textBox_leave();
		view_confirm_pass->Visible = true;
		view_signup_pass->Visible = true;
	}
	
	///sign in users functions///
	void name_enter() {
		if (name->Text == "Username")
		{
			name->Text = "";
			name->ForeColor = System::Drawing::Color::Black;
		}
	}
	void name_leave() {
		if (name->Text == "")
		{
			name->Text = "Username";
			name->ForeColor = System::Drawing::SystemColors::ScrollBar;
		}
	}
	void password_enter() {
		if (password->Text == "Password")
		{
			password->Text = "";
			this->password->PasswordChar = '*';
			password->ForeColor = System::Drawing::Color::Black;
		}
	}
	void password_leave() {
		if (password->Text == "")
		{
			password->Text = "Password";
			this->password->PasswordChar = '\0';
			password->ForeColor = System::Drawing::SystemColors::ScrollBar;
		}
	}
	private: System::Void name_Enter(System::Object^ sender, System::EventArgs^ e) {
		name_enter();
	}
	private: System::Void name_Leave(System::Object^ sender, System::EventArgs^ e) {
		name_leave();
	}
	private: System::Void password_Enter(System::Object^ sender, System::EventArgs^ e) {
		password_enter();
	}
	private: System::Void password_Leave(System::Object^ sender, System::EventArgs^ e) {
		password_leave();
	}
	private: System::Void sign_up_link_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
		sign_in_panel->Visible = false;
		sign_up_panel->Visible = true;
		password->Text = "";
		password_leave();
		name->Text = "";
		name_leave();
		view_password_signin->Visible = true;
	}
	private: System::Void forget_pass_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
		sign_in_panel->Visible = false;
		forgetPassword_panel->Visible = true;
		name->Text = "";
		name_leave();
		password->Text = "";
		password_leave();
	}
	private: System::Void name_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::Enter)
		{
			this->SelectNextControl((Control^)sender, true, true, true, true);
			e->SuppressKeyPress = true;
		}
	}
	private: System::Void password_signin_view_Click(System::Object^ sender, System::EventArgs^ e) {
		if (password->PasswordChar == '*')
		{
			this->password->PasswordChar = '\0';
			view_password_signin->Visible = false;
			hide_password_signin->Visible = true;
		}
	}
	private: System::Void hide_password_signin_Click(System::Object^ sender, System::EventArgs^ e) {
		if (password->PasswordChar == '\0')
		{
			this->password->PasswordChar = '*';
			hide_password_signin->Visible = false;
			view_password_signin->Visible = true;
		}
	}
	private: System::Void Login_Click(System::Object^ sender, System::EventArgs^ e) {
		if (name->Text == "Username" ||
			password->Text == "Password")
		{
			MessageBox::Show("Please Enter All Data", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
		else {
			if (admin_checkBox->Checked) {
				if (sign_in_admin(marshal_as<string>(name->Text), marshal_as<string>(password->Text))) {
					name->Text = "";
					name_leave();
					password->Text = "";
					password_leave();
					is_signed_in = true;
					this->Close();

				}
				else 
					MessageBox::Show("Invalid username or password", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
			else {
				if (sign_in_user(marshal_as<string>(name->Text), marshal_as<string>(password->Text))) {
					name->Text = "";
					name_leave();
					password->Text = "";
					password_leave();
					is_signed_in = true;
					this->Close();
				}
				else
					MessageBox::Show("Invalid username or password", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
		}
	}
	private: System::Void admin_checkBox_CheckStateChanged(System::Object^ sender, System::EventArgs^ e) {
		if (admin_checkBox->Checked)
		{
			is_admin = true;
			didnot_have_acc->Visible = false;
			sign_up_link->Visible = false;
		}
		else {
			is_admin = false;
			didnot_have_acc->Visible = true;
			sign_up_link->Visible = true;
		}
}


	///forget password functions///
	private: System::Void username_forget_Enter(System::Object^ sender, System::EventArgs^ e) {
		if (username_forget->Text == "Enter Your User Name")
		{
			username_forget->Text = "";
			username_forget->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
		}
	}
	private: System::Void username_forget_Leave(System::Object^ sender, System::EventArgs^ e) {
		if (username_forget->Text == "")
		{
			username_forget->Text = "Enter Your User Name";
			username_forget->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(169)), static_cast<System::Int32>(static_cast<System::Byte>(169)), static_cast<System::Int32>(static_cast<System::Byte>(169)));
		}
	}
	private: System::Void phonenumber_Enter(System::Object^ sender, System::EventArgs^ e) {
		if (phonenumber->Text == "Enter Your Phone Number")
		{
			phonenumber->Text = "";
			phonenumber->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
		}
	}
	private: System::Void phonenumber_Leave(System::Object^ sender, System::EventArgs^ e) {
		if (phonenumber->Text == "")
		{
			phonenumber->Text = "Enter Your Phone Number";
			phonenumber->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(169)), static_cast<System::Int32>(static_cast<System::Byte>(169)), static_cast<System::Int32>(static_cast<System::Byte>(169)));
		}
	}
	private: System::Void password_forget_Enter(System::Object^ sender, System::EventArgs^ e) {
		if (password_forget->Text == "Enter Your Password")
		{
			password_forget->Text = "";
			password_forget->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			password_forget->PasswordChar = '*';
		}
	}
	private: System::Void password_forget_Leave(System::Object^ sender, System::EventArgs^ e) {
		if (password_forget->Text == "")
		{
			password_forget->Text = "Enter Your Password";
			password_forget->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(169)), static_cast<System::Int32>(static_cast<System::Byte>(169)), static_cast<System::Int32>(static_cast<System::Byte>(169)));
			password_forget->PasswordChar = '\0';
		}
	}
	private: System::Void confirm_forget_Enter(System::Object^ sender, System::EventArgs^ e) {
		if (confirmpassword->Text == "Confirm Your Password")
		{
			confirmpassword->Text = "";
			confirmpassword->PasswordChar = '*';
			confirmpassword->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
		}
	}
	private: System::Void confirm_forget_Leave(System::Object^ sender, System::EventArgs^ e) {
		if (confirmpassword->Text == "")
		{
			confirmpassword->Text = "Confirm Your Password";
			confirmpassword->PasswordChar = '\0';
			confirmpassword->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(169)), static_cast<System::Int32>(static_cast<System::Byte>(169)), static_cast<System::Int32>(static_cast<System::Byte>(169)));
		}
	}
	private: System::Void pictureBoxPH_Click(System::Object^ sender, System::EventArgs^ e) {
		if (password_forget->PasswordChar == '*')
		{
			this->password_forget->PasswordChar = '\0';
			pictureBoxPH->Visible = false;
			pictureBoxPS->Visible = true;
		}
	}
	private: System::Void pictureBoxPS_Click(System::Object^ sender, System::EventArgs^ e) {
		if (password_forget->PasswordChar == '\0')
		{
			this->password_forget->PasswordChar = '*';
			pictureBoxPH->Visible = true;
			pictureBoxPS->Visible = false;
		}
	}
	private: System::Void pictureBoxCS_Click(System::Object^ sender, System::EventArgs^ e) {
		if (confirmpassword->PasswordChar == '\0')
		{
			this->confirmpassword->PasswordChar = '*';
			pictureBoxCH->Visible = true;
			pictureBoxCS->Visible = false;
		}
	}
	private: System::Void pictureBoxCH_Click(System::Object^ sender, System::EventArgs^ e) {
		if (confirmpassword->PasswordChar == '*')
		{
			this->confirmpassword->PasswordChar = '\0';
			pictureBoxCH->Visible = false;
			pictureBoxCS->Visible = true;
		}
	}
	private: System::Void username_forget_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::Enter)
		{
			this->SelectNextControl((Control^)sender, true, true, true, true);
			e->SuppressKeyPress = true;
		}
	}
	
	private: System::Void change_password_Button_Click(System::Object^ sender, System::EventArgs^ e) {
		string user_name = marshal_as<string>(username_forget->Text);
		string phone = marshal_as<string>(phonenumber->Text);
		string pass = marshal_as<string>(password_forget->Text);
		string confirm_pass = marshal_as<string>(confirmpassword->Text);

		String^ p = password_forget->Text;
		Regex^ pass_pattern = gcnew Regex("^(?=.*[a-z])(?=.*[A-Z])(?=.*[0-9])(?=.*[!@#$%^&*()\\-_=+{}\\[\\]|\\\\:;\"'<>,.?/~]).+$");


		if (username_forget->Text == "Enter Your User Name" ||
			password_forget->Text == "Enter Your Password" ||
			confirmpassword->Text == "Confirm Your Password" ||
			phonenumber->Text == "Enter Your Phone Number")
		{
			MessageBox::Show("Please Enter All Data", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
		else {
			if (!pass_pattern->IsMatch(p))
			{
				MessageBox::Show("Invalid password. Please note that the password must contain at least: A capital letter, a small letter, a number and a special character(!,@,#,$,%,^,&,*...) and must be at least 8 characters!", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
			else if (pass != confirm_pass) {
				MessageBox::Show("Password doesn't match", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
			else if (forget_password(is_admin, user_name, phone, pass, confirm_pass)) {
				MessageBox::Show("Password changed successfully", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
				username_forget->Text = "";
				username_forget_Leave(sender, e);
				phonenumber->Text = "";
				phonenumber_Leave(sender, e);
				password_forget->Text = "";
				password_forget_Leave(sender, e);
				confirmpassword->Text = "";
				confirm_forget_Leave(sender, e);
				forgetPassword_panel->Visible = false;
				if (pictureBoxPH->Visible) {
					pictureBoxPH->Visible = false;
					pictureBoxPS->Visible = true;
				}
				if (pictureBoxCH->Visible) {
					pictureBoxCH->Visible = false;
					pictureBoxCS->Visible = true;
				}
				sign_in_panel->Visible = true;
			}
			else {
				MessageBox::Show("User name or phone number is incorrect", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
	}
};
}
