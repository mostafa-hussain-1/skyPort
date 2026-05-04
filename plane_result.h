#pragma once
#include <msclr/marshal_cppstd.h>
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace msclr::interop;


extern bool plane_update;
extern int plane_idx;

namespace skyPort {

	/// <summary>
	/// Summary for plane_result
	/// </summary>
	
	public delegate void PlaneActionHandler(int idx);

	public ref class plane_result : public System::Windows::Forms::UserControl
	{
	public:
		event PlaneActionHandler^ OnEditButtonClicked;
		plane_result(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		void SetPlaneData(String^ model, String^ code, String^ place, String^ capacity, String^ index) {

			this->plane_model->Text = "Model: " + model;
			this->plane_code->Text = "Code: " + code;
			this->plane_place->Text = "Air port: " + place;
			this->plane_rows->Text = "Capacity: " + capacity;
			this->index->Text = index;
		}
		
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~plane_result()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ plane_model;
	private: System::Windows::Forms::Label^ plane_code;
	private: System::Windows::Forms::Label^ plane_place;





	private: System::Windows::Forms::Label^ plane_rows;
	private: System::Windows::Forms::PictureBox^ edit;

	public: System::Windows::Forms::Label^ index;




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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(plane_result::typeid));
			this->plane_model = (gcnew System::Windows::Forms::Label());
			this->plane_code = (gcnew System::Windows::Forms::Label());
			this->plane_place = (gcnew System::Windows::Forms::Label());
			this->plane_rows = (gcnew System::Windows::Forms::Label());
			this->edit = (gcnew System::Windows::Forms::PictureBox());
			this->index = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->edit))->BeginInit();
			this->SuspendLayout();
			// 
			// plane_model
			// 
			this->plane_model->AutoSize = true;
			this->plane_model->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 22.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->plane_model->Location = System::Drawing::Point(22, 27);
			this->plane_model->Name = L"plane_model";
			this->plane_model->Size = System::Drawing::Size(225, 42);
			this->plane_model->TabIndex = 0;
			this->plane_model->Text = L"Plane model";
			// 
			// plane_code
			// 
			this->plane_code->AutoSize = true;
			this->plane_code->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->plane_code->Location = System::Drawing::Point(26, 88);
			this->plane_code->Name = L"plane_code";
			this->plane_code->Size = System::Drawing::Size(135, 29);
			this->plane_code->TabIndex = 1;
			this->plane_code->Text = L"Plane code";
			// 
			// plane_place
			// 
			this->plane_place->AutoSize = true;
			this->plane_place->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->plane_place->Location = System::Drawing::Point(26, 126);
			this->plane_place->Name = L"plane_place";
			this->plane_place->Size = System::Drawing::Size(140, 29);
			this->plane_place->TabIndex = 2;
			this->plane_place->Text = L"Plane place";
			// 
			// plane_rows
			// 
			this->plane_rows->AutoSize = true;
			this->plane_rows->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->plane_rows->Location = System::Drawing::Point(390, 88);
			this->plane_rows->Name = L"plane_rows";
			this->plane_rows->Size = System::Drawing::Size(105, 29);
			this->plane_rows->TabIndex = 5;
			this->plane_rows->Text = L"Capacity";
			// 
			// edit
			// 
			this->edit->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(46)), static_cast<System::Int32>(static_cast<System::Byte>(204)),
				static_cast<System::Int32>(static_cast<System::Byte>(113)));
			this->edit->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"edit.Image")));
			this->edit->Location = System::Drawing::Point(659, 79);
			this->edit->Name = L"edit";
			this->edit->Size = System::Drawing::Size(54, 51);
			this->edit->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->edit->TabIndex = 7;
			this->edit->TabStop = false;
			this->edit->Click += gcnew System::EventHandler(this, &plane_result::edit_Click);
			// 
			// index
			// 
			this->index->AutoSize = true;
			this->index->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->index->Location = System::Drawing::Point(390, 56);
			this->index->Name = L"index";
			this->index->Size = System::Drawing::Size(71, 29);
			this->index->TabIndex = 9;
			this->index->Text = L"Index";
			this->index->Visible = false;
			// 
			// plane_result
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::AliceBlue;
			this->Controls->Add(this->index);
			this->Controls->Add(this->edit);
			this->Controls->Add(this->plane_rows);
			this->Controls->Add(this->plane_place);
			this->Controls->Add(this->plane_code);
			this->Controls->Add(this->plane_model);
			this->Name = L"plane_result";
			this->Size = System::Drawing::Size(732, 190);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->edit))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		
#pragma endregion
		
	private: System::Void edit_Click(System::Object^ sender, System::EventArgs^ e) {
		
		int idx = stoi(marshal_as<string>(index->Text));
		
		OnEditButtonClicked(idx);
	}
};
}
