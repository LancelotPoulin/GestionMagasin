#pragma once

#include "Database.h"

namespace GestionMagasin {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de FConfig
	/// </summary>
	public ref class FConfig : public System::Windows::Forms::Form
	{
	public:
		FConfig(Database^ database)
		{
			InitializeComponent();
			_database = database;
		}

	private: System::Windows::Forms::TextBox^  ServerTextBox;
	private: System::Windows::Forms::TextBox^  UserTextBox;
	private: System::Windows::Forms::TextBox^  DBNameTextBox;
	private: System::Windows::Forms::TextBox^  PasswordTextBox;
	private: System::Windows::Forms::Button^  ConnectButton;
	private: System::Windows::Forms::Label^  ServerLabel;
	private: System::Windows::Forms::Label^  DBNameLabel;
	private: System::Windows::Forms::Label^  UserLabel;
	private: System::Windows::Forms::Label^  PasswordLabel;
	private: System::Windows::Forms::Label^  ConfigTitleLabel;
	private: System::Windows::Forms::GroupBox^  DBConfigGroupBox;
	private: Database^ _database;

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~FConfig()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Variable nécessaire au concepteur.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			this->ServerTextBox = (gcnew System::Windows::Forms::TextBox());
			this->UserTextBox = (gcnew System::Windows::Forms::TextBox());
			this->DBNameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->PasswordTextBox = (gcnew System::Windows::Forms::TextBox());
			this->ConnectButton = (gcnew System::Windows::Forms::Button());
			this->ServerLabel = (gcnew System::Windows::Forms::Label());
			this->DBNameLabel = (gcnew System::Windows::Forms::Label());
			this->UserLabel = (gcnew System::Windows::Forms::Label());
			this->PasswordLabel = (gcnew System::Windows::Forms::Label());
			this->ConfigTitleLabel = (gcnew System::Windows::Forms::Label());
			this->DBConfigGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->DBConfigGroupBox->SuspendLayout();
			this->SuspendLayout();
			// 
			// ServerTextBox
			// 
			this->ServerTextBox->Location = System::Drawing::Point(144, 56);
			this->ServerTextBox->Name = L"ServerTextBox";
			this->ServerTextBox->Size = System::Drawing::Size(267, 26);
			this->ServerTextBox->TabIndex = 0;
			// 
			// UserTextBox
			// 
			this->UserTextBox->Location = System::Drawing::Point(144, 204);
			this->UserTextBox->Name = L"UserTextBox";
			this->UserTextBox->Size = System::Drawing::Size(267, 26);
			this->UserTextBox->TabIndex = 1;
			// 
			// DBNameTextBox
			// 
			this->DBNameTextBox->Location = System::Drawing::Point(144, 132);
			this->DBNameTextBox->Name = L"DBNameTextBox";
			this->DBNameTextBox->Size = System::Drawing::Size(267, 26);
			this->DBNameTextBox->TabIndex = 2;
			// 
			// PasswordTextBox
			// 
			this->PasswordTextBox->Location = System::Drawing::Point(144, 281);
			this->PasswordTextBox->Name = L"PasswordTextBox";
			this->PasswordTextBox->Size = System::Drawing::Size(267, 26);
			this->PasswordTextBox->TabIndex = 3;
			// 
			// ConnectButton
			// 
			this->ConnectButton->Location = System::Drawing::Point(76, 347);
			this->ConnectButton->Name = L"ConnectButton";
			this->ConnectButton->Size = System::Drawing::Size(325, 77);
			this->ConnectButton->TabIndex = 4;
			this->ConnectButton->Text = L"Connect";
			this->ConnectButton->UseVisualStyleBackColor = true;
			this->ConnectButton->Click += gcnew System::EventHandler(this, &FConfig::ConnectButton_Click);
			// 
			// ServerLabel
			// 
			this->ServerLabel->AutoSize = true;
			this->ServerLabel->Location = System::Drawing::Point(82, 59);
			this->ServerLabel->Name = L"ServerLabel";
			this->ServerLabel->Size = System::Drawing::Size(55, 20);
			this->ServerLabel->TabIndex = 5;
			this->ServerLabel->Text = L"Server";
			// 
			// DBNameLabel
			// 
			this->DBNameLabel->AutoSize = true;
			this->DBNameLabel->Location = System::Drawing::Point(58, 135);
			this->DBNameLabel->Name = L"DBNameLabel";
			this->DBNameLabel->Size = System::Drawing::Size(79, 20);
			this->DBNameLabel->TabIndex = 6;
			this->DBNameLabel->Text = L"Database";
			// 
			// UserLabel
			// 
			this->UserLabel->AutoSize = true;
			this->UserLabel->Location = System::Drawing::Point(94, 207);
			this->UserLabel->Name = L"UserLabel";
			this->UserLabel->Size = System::Drawing::Size(43, 20);
			this->UserLabel->TabIndex = 7;
			this->UserLabel->Text = L"User";
			// 
			// PasswordLabel
			// 
			this->PasswordLabel->AutoSize = true;
			this->PasswordLabel->Location = System::Drawing::Point(60, 284);
			this->PasswordLabel->Name = L"PasswordLabel";
			this->PasswordLabel->Size = System::Drawing::Size(78, 20);
			this->PasswordLabel->TabIndex = 8;
			this->PasswordLabel->Text = L"Password";
			// 
			// ConfigTitleLabel
			// 
			this->ConfigTitleLabel->AutoSize = true;
			this->ConfigTitleLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->ConfigTitleLabel->Location = System::Drawing::Point(12, 9);
			this->ConfigTitleLabel->Name = L"ConfigTitleLabel";
			this->ConfigTitleLabel->Size = System::Drawing::Size(299, 37);
			this->ConfigTitleLabel->TabIndex = 44;
			this->ConfigTitleLabel->Text = L"CONFIGURATION";
			// 
			// DBConfigGroupBox
			// 
			this->DBConfigGroupBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->DBConfigGroupBox->Controls->Add(this->ConnectButton);
			this->DBConfigGroupBox->Controls->Add(this->ServerTextBox);
			this->DBConfigGroupBox->Controls->Add(this->PasswordLabel);
			this->DBConfigGroupBox->Controls->Add(this->UserTextBox);
			this->DBConfigGroupBox->Controls->Add(this->UserLabel);
			this->DBConfigGroupBox->Controls->Add(this->DBNameTextBox);
			this->DBConfigGroupBox->Controls->Add(this->DBNameLabel);
			this->DBConfigGroupBox->Controls->Add(this->PasswordTextBox);
			this->DBConfigGroupBox->Controls->Add(this->ServerLabel);
			this->DBConfigGroupBox->Location = System::Drawing::Point(338, 98);
			this->DBConfigGroupBox->MaximumSize = System::Drawing::Size(477, 465);
			this->DBConfigGroupBox->Name = L"DBConfigGroupBox";
			this->DBConfigGroupBox->Size = System::Drawing::Size(477, 465);
			this->DBConfigGroupBox->TabIndex = 45;
			this->DBConfigGroupBox->TabStop = false;
			this->DBConfigGroupBox->Text = L"Database";
			// 
			// FConfig
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1152, 648);
			this->Controls->Add(this->DBConfigGroupBox);
			this->Controls->Add(this->ConfigTitleLabel);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"FConfig";
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"FConfig";
			this->Shown += gcnew System::EventHandler(this, &FConfig::FConfig_Shown);
			this->DBConfigGroupBox->ResumeLayout(false);
			this->DBConfigGroupBox->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		// When form is load, textboxes get connection informations from props file
	private: System::Void FConfig_Shown(System::Object^  sender, System::EventArgs^  e)
	{
		ConfigurationManager::RefreshSection("appSettings");
		ServerTextBox->Text = ConfigurationManager::AppSettings["Server"];
		UserTextBox->Text = ConfigurationManager::AppSettings["User"];
		PasswordTextBox->Text = ConfigurationManager::AppSettings["Password"];
		DBNameTextBox->Text = ConfigurationManager::AppSettings["Database"];
	}

			 // When click one test button, get textboxes informations and set it in props file then try connect with textboxes connection informations
	private: System::Void ConnectButton_Click(System::Object^  sender, System::EventArgs^  e)
	{
		System::Configuration::Configuration ^ChangeConfig = ConfigurationManager::OpenExeConfiguration(ConfigurationUserLevel::None);
		ChangeConfig->AppSettings->Settings->Remove("Server");
		ChangeConfig->AppSettings->Settings->Add("Server", ServerTextBox->Text);
		ChangeConfig->AppSettings->Settings->Remove("User");
		ChangeConfig->AppSettings->Settings->Add("User", UserTextBox->Text);
		ChangeConfig->AppSettings->Settings->Remove("Password");
		ChangeConfig->AppSettings->Settings->Add("Password", PasswordTextBox->Text);
		ChangeConfig->AppSettings->Settings->Remove("Database");
		ChangeConfig->AppSettings->Settings->Add("Database", DBNameTextBox->Text);
		ChangeConfig->Save(ConfigurationSaveMode::Modified);
		ConfigurationManager::RefreshSection("appSettings");
		delete(ChangeConfig);
		if (!_database->Connect())
		{
			MessageBox::Show("Erreur de connexion à la base de données.");
		}
		else
		{
			MessageBox::Show("Connecté à la base de données avec succès.");
		}
	}
};
}
