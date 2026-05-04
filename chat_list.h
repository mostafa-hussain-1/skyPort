#pragma once
#include <msclr/marshal_cppstd.h>
#include <string>
#include "chatBot.h"
using namespace std;
using namespace msclr::interop;
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

extern string user_sender;
namespace skyPort {

	/// <summary>
	/// Summary for chat_list
	/// </summary>
	/// 
	//ref class admin_home_page;

	public ref class chat_list : public System::Windows::Forms::UserControl
	{
	public:
		Form^ adminForm;
		chat_list(Form^ f)
		{
			adminForm = f;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		void Set_chatbot_data(String^ user_name, String^ message) {
			this->user_name_label->Text = user_name;
			this->message_label->Text = message;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~chat_list()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ message_label;
	protected:
	public: System::Windows::Forms::Label^ user_name_label;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(chat_list::typeid));
			this->message_label = (gcnew System::Windows::Forms::Label());
			this->user_name_label = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// message_label
			// 
			this->message_label->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->message_label->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->message_label->Location = System::Drawing::Point(95, 66);
			this->message_label->Name = L"message_label";
			this->message_label->Size = System::Drawing::Size(337, 41);
			this->message_label->TabIndex = 3;
			this->message_label->Text = L"how much travel";
			this->message_label->Click += gcnew System::EventHandler(this, &chat_list::message_label_Click);
			// 
			// user_name_label
			// 
			this->user_name_label->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->user_name_label->ForeColor = System::Drawing::Color::White;
			this->user_name_label->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"user_name_label.Image")));
			this->user_name_label->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->user_name_label->Location = System::Drawing::Point(3, 0);
			this->user_name_label->Name = L"user_name_label";
			this->user_name_label->Size = System::Drawing::Size(347, 78);
			this->user_name_label->TabIndex = 2;
			this->user_name_label->Text = L"Ahmed mohsen";
			this->user_name_label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->user_name_label->Click += gcnew System::EventHandler(this, &chat_list::message_label_Click);
			// 
			// chat_list
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(55)),
				static_cast<System::Int32>(static_cast<System::Byte>(85)));
			this->Controls->Add(this->message_label);
			this->Controls->Add(this->user_name_label);
			this->Name = L"chat_list";
			this->Size = System::Drawing::Size(435, 107);
			this->Click += gcnew System::EventHandler(this, &chat_list::message_label_Click);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void message_label_Click(System::Object^ sender, System::EventArgs^ e);

	};
}
