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
	/// Description résumée de FFournisseur
	/// </summary>
	public ref class FFournisseur : public System::Windows::Forms::Form
	{
	public:
		FFournisseur(Database^ database)
		{
			InitializeComponent();
			_database = database;
		}

	private: Database^ _database;
	private: MySqlClient::MySqlDataReader^ DataReader;
	private: System::Data::DataTable^ FournisseurDatatable;
	private: System::Windows::Forms::BindingSource^  FournisseurBindingSource;
	private: System::Windows::Forms::RadioButton^  ConnectedModeRadioButton;
	private: System::Windows::Forms::Button^  UpdateTableButton;
	private: System::Windows::Forms::RadioButton^  DisconnectedModeRadioButton;
	private: System::Windows::Forms::TableLayoutPanel^  FournisseurTableLayoutPanel;
	private: System::Windows::Forms::GroupBox^  CRUDGroupBox;
	private: System::Windows::Forms::ComboBox^  CRUDCategorieComboBox;
	private: System::Windows::Forms::Button^  ModifyFournisseurButton;
	private: System::Windows::Forms::TextBox^  CRUDSocieteTextBox;
	private: System::Windows::Forms::Label^  CRUDMailLabel;
	private: System::Windows::Forms::Label^  CRUDSocieteLabel;
	private: System::Windows::Forms::TextBox^  CRUDMailTextBox;
	private: System::Windows::Forms::Button^  AddFournisseurButton;
	private: System::Windows::Forms::Label^  CRUDPhoneLabel;
	private: System::Windows::Forms::Button^  ClearBoxesButton;
	private: System::Windows::Forms::TextBox^  CRUDPhoneTextBox;
	private: System::Windows::Forms::Label^  CRUDPaysLabel;
	private: System::Windows::Forms::Label^  CRUDCategorieLabel;
	private: System::Windows::Forms::TextBox^  CRUDAdresseTextBox;
	private: System::Windows::Forms::Label^  CRUDVilleLabel;
	private: System::Windows::Forms::Label^  CRUDAdresseLabel;
	private: System::Windows::Forms::TextBox^  CRUDVilleTextBox;
	private: System::Windows::Forms::TextBox^  CRUDCodeTextBox;
	private: System::Windows::Forms::Label^  CRUDCodeLabel;
	private: System::Windows::Forms::DataGridView^  FournisseurDataGridView;
	private: System::Windows::Forms::Label^  FournisseurTitleLabel;
	private: System::Windows::Forms::Button^  DeleteFournisseurButton;
	private: System::Windows::Forms::ComboBox^  CRUDPaysComboBox;
			 bool bMode = false;
			 int Index = 0;
			 Generic::List<int> ^DelIndex;

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~FFournisseur()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Variable nécessaire au concepteur.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->FournisseurBindingSource = (gcnew System::Windows::Forms::BindingSource(this->components));
			this->ConnectedModeRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->UpdateTableButton = (gcnew System::Windows::Forms::Button());
			this->DisconnectedModeRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->FournisseurTableLayoutPanel = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->CRUDGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->CRUDPaysComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->DeleteFournisseurButton = (gcnew System::Windows::Forms::Button());
			this->CRUDCategorieComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->ModifyFournisseurButton = (gcnew System::Windows::Forms::Button());
			this->CRUDSocieteTextBox = (gcnew System::Windows::Forms::TextBox());
			this->CRUDMailLabel = (gcnew System::Windows::Forms::Label());
			this->CRUDSocieteLabel = (gcnew System::Windows::Forms::Label());
			this->CRUDMailTextBox = (gcnew System::Windows::Forms::TextBox());
			this->AddFournisseurButton = (gcnew System::Windows::Forms::Button());
			this->CRUDPhoneLabel = (gcnew System::Windows::Forms::Label());
			this->ClearBoxesButton = (gcnew System::Windows::Forms::Button());
			this->CRUDPhoneTextBox = (gcnew System::Windows::Forms::TextBox());
			this->CRUDPaysLabel = (gcnew System::Windows::Forms::Label());
			this->CRUDCategorieLabel = (gcnew System::Windows::Forms::Label());
			this->CRUDAdresseTextBox = (gcnew System::Windows::Forms::TextBox());
			this->CRUDVilleLabel = (gcnew System::Windows::Forms::Label());
			this->CRUDAdresseLabel = (gcnew System::Windows::Forms::Label());
			this->CRUDVilleTextBox = (gcnew System::Windows::Forms::TextBox());
			this->CRUDCodeTextBox = (gcnew System::Windows::Forms::TextBox());
			this->CRUDCodeLabel = (gcnew System::Windows::Forms::Label());
			this->FournisseurDataGridView = (gcnew System::Windows::Forms::DataGridView());
			this->FournisseurTitleLabel = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->FournisseurBindingSource))->BeginInit();
			this->FournisseurTableLayoutPanel->SuspendLayout();
			this->CRUDGroupBox->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->FournisseurDataGridView))->BeginInit();
			this->SuspendLayout();
			// 
			// ConnectedModeRadioButton
			// 
			this->ConnectedModeRadioButton->AutoSize = true;
			this->ConnectedModeRadioButton->Location = System::Drawing::Point(198, 15);
			this->ConnectedModeRadioButton->Margin = System::Windows::Forms::Padding(2);
			this->ConnectedModeRadioButton->Name = L"ConnectedModeRadioButton";
			this->ConnectedModeRadioButton->Size = System::Drawing::Size(85, 17);
			this->ConnectedModeRadioButton->TabIndex = 38;
			this->ConnectedModeRadioButton->Text = L"Auto Update";
			this->ConnectedModeRadioButton->UseVisualStyleBackColor = true;
			this->ConnectedModeRadioButton->CheckedChanged += gcnew System::EventHandler(this, &FFournisseur::ConnectedModeRadioButton_CheckedChanged);
			// 
			// UpdateTableButton
			// 
			this->UpdateTableButton->Location = System::Drawing::Point(381, 10);
			this->UpdateTableButton->Margin = System::Windows::Forms::Padding(2);
			this->UpdateTableButton->Name = L"UpdateTableButton";
			this->UpdateTableButton->Size = System::Drawing::Size(99, 25);
			this->UpdateTableButton->TabIndex = 36;
			this->UpdateTableButton->Text = L"Update Changes";
			this->UpdateTableButton->UseVisualStyleBackColor = true;
			this->UpdateTableButton->Click += gcnew System::EventHandler(this, &FFournisseur::UpdateTableButton_Click);
			// 
			// DisconnectedModeRadioButton
			// 
			this->DisconnectedModeRadioButton->AutoSize = true;
			this->DisconnectedModeRadioButton->Checked = true;
			this->DisconnectedModeRadioButton->Location = System::Drawing::Point(285, 15);
			this->DisconnectedModeRadioButton->Margin = System::Windows::Forms::Padding(2);
			this->DisconnectedModeRadioButton->Name = L"DisconnectedModeRadioButton";
			this->DisconnectedModeRadioButton->Size = System::Drawing::Size(98, 17);
			this->DisconnectedModeRadioButton->TabIndex = 37;
			this->DisconnectedModeRadioButton->TabStop = true;
			this->DisconnectedModeRadioButton->Text = L"Manual Update";
			this->DisconnectedModeRadioButton->UseVisualStyleBackColor = true;
			this->DisconnectedModeRadioButton->CheckedChanged += gcnew System::EventHandler(this, &FFournisseur::DisconnectedModeRadioButton_CheckedChanged);
			// 
			// FournisseurTableLayoutPanel
			// 
			this->FournisseurTableLayoutPanel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->FournisseurTableLayoutPanel->ColumnCount = 2;
			this->FournisseurTableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				52.5F)));
			this->FournisseurTableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				47.5F)));
			this->FournisseurTableLayoutPanel->Controls->Add(this->CRUDGroupBox, 1, 0);
			this->FournisseurTableLayoutPanel->Controls->Add(this->FournisseurDataGridView, 0, 0);
			this->FournisseurTableLayoutPanel->Location = System::Drawing::Point(8, 35);
			this->FournisseurTableLayoutPanel->Margin = System::Windows::Forms::Padding(2);
			this->FournisseurTableLayoutPanel->Name = L"FournisseurTableLayoutPanel";
			this->FournisseurTableLayoutPanel->RowCount = 1;
			this->FournisseurTableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->FournisseurTableLayoutPanel->Size = System::Drawing::Size(752, 372);
			this->FournisseurTableLayoutPanel->TabIndex = 35;
			// 
			// CRUDGroupBox
			// 
			this->CRUDGroupBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->CRUDGroupBox->Controls->Add(this->CRUDPaysComboBox);
			this->CRUDGroupBox->Controls->Add(this->DeleteFournisseurButton);
			this->CRUDGroupBox->Controls->Add(this->CRUDCategorieComboBox);
			this->CRUDGroupBox->Controls->Add(this->ModifyFournisseurButton);
			this->CRUDGroupBox->Controls->Add(this->CRUDSocieteTextBox);
			this->CRUDGroupBox->Controls->Add(this->CRUDMailLabel);
			this->CRUDGroupBox->Controls->Add(this->CRUDSocieteLabel);
			this->CRUDGroupBox->Controls->Add(this->CRUDMailTextBox);
			this->CRUDGroupBox->Controls->Add(this->AddFournisseurButton);
			this->CRUDGroupBox->Controls->Add(this->CRUDPhoneLabel);
			this->CRUDGroupBox->Controls->Add(this->ClearBoxesButton);
			this->CRUDGroupBox->Controls->Add(this->CRUDPhoneTextBox);
			this->CRUDGroupBox->Controls->Add(this->CRUDPaysLabel);
			this->CRUDGroupBox->Controls->Add(this->CRUDCategorieLabel);
			this->CRUDGroupBox->Controls->Add(this->CRUDAdresseTextBox);
			this->CRUDGroupBox->Controls->Add(this->CRUDVilleLabel);
			this->CRUDGroupBox->Controls->Add(this->CRUDAdresseLabel);
			this->CRUDGroupBox->Controls->Add(this->CRUDVilleTextBox);
			this->CRUDGroupBox->Controls->Add(this->CRUDCodeTextBox);
			this->CRUDGroupBox->Controls->Add(this->CRUDCodeLabel);
			this->CRUDGroupBox->Location = System::Drawing::Point(397, 3);
			this->CRUDGroupBox->Name = L"CRUDGroupBox";
			this->CRUDGroupBox->Size = System::Drawing::Size(352, 365);
			this->CRUDGroupBox->TabIndex = 24;
			this->CRUDGroupBox->TabStop = false;
			this->CRUDGroupBox->Text = L"CRUD";
			// 
			// CRUDPaysComboBox
			// 
			this->CRUDPaysComboBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->CRUDPaysComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->CRUDPaysComboBox->FormattingEnabled = true;
			this->CRUDPaysComboBox->Location = System::Drawing::Point(232, 172);
			this->CRUDPaysComboBox->Name = L"CRUDPaysComboBox";
			this->CRUDPaysComboBox->Size = System::Drawing::Size(100, 21);
			this->CRUDPaysComboBox->TabIndex = 27;
			// 
			// DeleteFournisseurButton
			// 
			this->DeleteFournisseurButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->DeleteFournisseurButton->Location = System::Drawing::Point(29, 289);
			this->DeleteFournisseurButton->Name = L"DeleteFournisseurButton";
			this->DeleteFournisseurButton->Size = System::Drawing::Size(138, 36);
			this->DeleteFournisseurButton->TabIndex = 26;
			this->DeleteFournisseurButton->Text = L"Delete";
			this->DeleteFournisseurButton->UseVisualStyleBackColor = true;
			this->DeleteFournisseurButton->Visible = false;
			this->DeleteFournisseurButton->Click += gcnew System::EventHandler(this, &FFournisseur::DeleteFournisseurButton_Click);
			// 
			// CRUDCategorieComboBox
			// 
			this->CRUDCategorieComboBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->CRUDCategorieComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->CRUDCategorieComboBox->FormattingEnabled = true;
			this->CRUDCategorieComboBox->Location = System::Drawing::Point(232, 45);
			this->CRUDCategorieComboBox->Name = L"CRUDCategorieComboBox";
			this->CRUDCategorieComboBox->Size = System::Drawing::Size(100, 21);
			this->CRUDCategorieComboBox->TabIndex = 25;
			// 
			// ModifyFournisseurButton
			// 
			this->ModifyFournisseurButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->ModifyFournisseurButton->Location = System::Drawing::Point(194, 289);
			this->ModifyFournisseurButton->Name = L"ModifyFournisseurButton";
			this->ModifyFournisseurButton->Size = System::Drawing::Size(138, 36);
			this->ModifyFournisseurButton->TabIndex = 23;
			this->ModifyFournisseurButton->Text = L"Modify";
			this->ModifyFournisseurButton->UseVisualStyleBackColor = true;
			this->ModifyFournisseurButton->Visible = false;
			this->ModifyFournisseurButton->Click += gcnew System::EventHandler(this, &FFournisseur::ModifyFournisseurButton_Click);
			// 
			// CRUDSocieteTextBox
			// 
			this->CRUDSocieteTextBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->CRUDSocieteTextBox->Location = System::Drawing::Point(66, 45);
			this->CRUDSocieteTextBox->MaxLength = 20;
			this->CRUDSocieteTextBox->Name = L"CRUDSocieteTextBox";
			this->CRUDSocieteTextBox->Size = System::Drawing::Size(100, 20);
			this->CRUDSocieteTextBox->TabIndex = 5;
			// 
			// CRUDMailLabel
			// 
			this->CRUDMailLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->CRUDMailLabel->AutoSize = true;
			this->CRUDMailLabel->Location = System::Drawing::Point(200, 239);
			this->CRUDMailLabel->Name = L"CRUDMailLabel";
			this->CRUDMailLabel->Size = System::Drawing::Size(26, 13);
			this->CRUDMailLabel->TabIndex = 22;
			this->CRUDMailLabel->Text = L"Mail";
			// 
			// CRUDSocieteLabel
			// 
			this->CRUDSocieteLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->CRUDSocieteLabel->AutoSize = true;
			this->CRUDSocieteLabel->Location = System::Drawing::Point(17, 48);
			this->CRUDSocieteLabel->Name = L"CRUDSocieteLabel";
			this->CRUDSocieteLabel->Size = System::Drawing::Size(43, 13);
			this->CRUDSocieteLabel->TabIndex = 6;
			this->CRUDSocieteLabel->Text = L"Societé";
			// 
			// CRUDMailTextBox
			// 
			this->CRUDMailTextBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->CRUDMailTextBox->Location = System::Drawing::Point(232, 235);
			this->CRUDMailTextBox->MaxLength = 40;
			this->CRUDMailTextBox->Name = L"CRUDMailTextBox";
			this->CRUDMailTextBox->Size = System::Drawing::Size(100, 20);
			this->CRUDMailTextBox->TabIndex = 21;
			// 
			// AddFournisseurButton
			// 
			this->AddFournisseurButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->AddFournisseurButton->Location = System::Drawing::Point(195, 289);
			this->AddFournisseurButton->Name = L"AddFournisseurButton";
			this->AddFournisseurButton->Size = System::Drawing::Size(138, 36);
			this->AddFournisseurButton->TabIndex = 7;
			this->AddFournisseurButton->Text = L"Add";
			this->AddFournisseurButton->UseVisualStyleBackColor = true;
			this->AddFournisseurButton->Click += gcnew System::EventHandler(this, &FFournisseur::AddFournisseurButton_Click);
			// 
			// CRUDPhoneLabel
			// 
			this->CRUDPhoneLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->CRUDPhoneLabel->AutoSize = true;
			this->CRUDPhoneLabel->Location = System::Drawing::Point(22, 239);
			this->CRUDPhoneLabel->Name = L"CRUDPhoneLabel";
			this->CRUDPhoneLabel->Size = System::Drawing::Size(38, 13);
			this->CRUDPhoneLabel->TabIndex = 20;
			this->CRUDPhoneLabel->Text = L"Phone";
			// 
			// ClearBoxesButton
			// 
			this->ClearBoxesButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->ClearBoxesButton->Location = System::Drawing::Point(29, 289);
			this->ClearBoxesButton->Name = L"ClearBoxesButton";
			this->ClearBoxesButton->Size = System::Drawing::Size(138, 36);
			this->ClearBoxesButton->TabIndex = 8;
			this->ClearBoxesButton->Text = L"Clear";
			this->ClearBoxesButton->UseVisualStyleBackColor = true;
			this->ClearBoxesButton->Click += gcnew System::EventHandler(this, &FFournisseur::ClearBoxesButton_Click);
			// 
			// CRUDPhoneTextBox
			// 
			this->CRUDPhoneTextBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->CRUDPhoneTextBox->Location = System::Drawing::Point(66, 235);
			this->CRUDPhoneTextBox->MaxLength = 10;
			this->CRUDPhoneTextBox->Name = L"CRUDPhoneTextBox";
			this->CRUDPhoneTextBox->Size = System::Drawing::Size(100, 20);
			this->CRUDPhoneTextBox->TabIndex = 19;
			this->CRUDPhoneTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &FFournisseur::CRUDPhoneTextBox_KeyPress);
			// 
			// CRUDPaysLabel
			// 
			this->CRUDPaysLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->CRUDPaysLabel->AutoSize = true;
			this->CRUDPaysLabel->Location = System::Drawing::Point(196, 175);
			this->CRUDPaysLabel->Name = L"CRUDPaysLabel";
			this->CRUDPaysLabel->Size = System::Drawing::Size(30, 13);
			this->CRUDPaysLabel->TabIndex = 18;
			this->CRUDPaysLabel->Text = L"Pays";
			// 
			// CRUDCategorieLabel
			// 
			this->CRUDCategorieLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->CRUDCategorieLabel->AutoSize = true;
			this->CRUDCategorieLabel->Location = System::Drawing::Point(174, 48);
			this->CRUDCategorieLabel->Name = L"CRUDCategorieLabel";
			this->CRUDCategorieLabel->Size = System::Drawing::Size(52, 13);
			this->CRUDCategorieLabel->TabIndex = 10;
			this->CRUDCategorieLabel->Text = L"Categorie";
			// 
			// CRUDAdresseTextBox
			// 
			this->CRUDAdresseTextBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->CRUDAdresseTextBox->Location = System::Drawing::Point(66, 109);
			this->CRUDAdresseTextBox->MaxLength = 50;
			this->CRUDAdresseTextBox->Name = L"CRUDAdresseTextBox";
			this->CRUDAdresseTextBox->Size = System::Drawing::Size(100, 20);
			this->CRUDAdresseTextBox->TabIndex = 11;
			// 
			// CRUDVilleLabel
			// 
			this->CRUDVilleLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->CRUDVilleLabel->AutoSize = true;
			this->CRUDVilleLabel->Location = System::Drawing::Point(34, 175);
			this->CRUDVilleLabel->Name = L"CRUDVilleLabel";
			this->CRUDVilleLabel->Size = System::Drawing::Size(26, 13);
			this->CRUDVilleLabel->TabIndex = 16;
			this->CRUDVilleLabel->Text = L"Ville";
			// 
			// CRUDAdresseLabel
			// 
			this->CRUDAdresseLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->CRUDAdresseLabel->AutoSize = true;
			this->CRUDAdresseLabel->Location = System::Drawing::Point(15, 110);
			this->CRUDAdresseLabel->Name = L"CRUDAdresseLabel";
			this->CRUDAdresseLabel->Size = System::Drawing::Size(45, 13);
			this->CRUDAdresseLabel->TabIndex = 12;
			this->CRUDAdresseLabel->Text = L"Adresse";
			// 
			// CRUDVilleTextBox
			// 
			this->CRUDVilleTextBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->CRUDVilleTextBox->Location = System::Drawing::Point(66, 174);
			this->CRUDVilleTextBox->MaxLength = 20;
			this->CRUDVilleTextBox->Name = L"CRUDVilleTextBox";
			this->CRUDVilleTextBox->Size = System::Drawing::Size(100, 20);
			this->CRUDVilleTextBox->TabIndex = 15;
			// 
			// CRUDCodeTextBox
			// 
			this->CRUDCodeTextBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->CRUDCodeTextBox->Location = System::Drawing::Point(232, 109);
			this->CRUDCodeTextBox->MaxLength = 5;
			this->CRUDCodeTextBox->Name = L"CRUDCodeTextBox";
			this->CRUDCodeTextBox->Size = System::Drawing::Size(100, 20);
			this->CRUDCodeTextBox->TabIndex = 13;
			this->CRUDCodeTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &FFournisseur::CRUDCodeTextBox_KeyPress);
			// 
			// CRUDCodeLabel
			// 
			this->CRUDCodeLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->CRUDCodeLabel->AutoSize = true;
			this->CRUDCodeLabel->Location = System::Drawing::Point(194, 110);
			this->CRUDCodeLabel->Name = L"CRUDCodeLabel";
			this->CRUDCodeLabel->Size = System::Drawing::Size(32, 13);
			this->CRUDCodeLabel->TabIndex = 14;
			this->CRUDCodeLabel->Text = L"Code";
			// 
			// FournisseurDataGridView
			// 
			this->FournisseurDataGridView->AllowUserToAddRows = false;
			this->FournisseurDataGridView->AllowUserToDeleteRows = false;
			this->FournisseurDataGridView->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->FournisseurDataGridView->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->FournisseurDataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->FournisseurDataGridView->Cursor = System::Windows::Forms::Cursors::Hand;
			this->FournisseurDataGridView->GridColor = System::Drawing::SystemColors::ActiveCaption;
			this->FournisseurDataGridView->Location = System::Drawing::Point(2, 2);
			this->FournisseurDataGridView->Margin = System::Windows::Forms::Padding(2);
			this->FournisseurDataGridView->MultiSelect = false;
			this->FournisseurDataGridView->Name = L"FournisseurDataGridView";
			this->FournisseurDataGridView->ReadOnly = true;
			this->FournisseurDataGridView->RowHeadersVisible = false;
			this->FournisseurDataGridView->RowTemplate->Height = 28;
			this->FournisseurDataGridView->Size = System::Drawing::Size(390, 368);
			this->FournisseurDataGridView->TabIndex = 0;
			this->FournisseurDataGridView->CellMouseDoubleClick += gcnew System::Windows::Forms::DataGridViewCellMouseEventHandler(this, &FFournisseur::FournisseurDataGridView_CellMouseDoubleClick);
			// 
			// FournisseurTitleLabel
			// 
			this->FournisseurTitleLabel->AutoSize = true;
			this->FournisseurTitleLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->FournisseurTitleLabel->Location = System::Drawing::Point(8, 7);
			this->FournisseurTitleLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->FournisseurTitleLabel->Name = L"FournisseurTitleLabel";
			this->FournisseurTitleLabel->Size = System::Drawing::Size(184, 26);
			this->FournisseurTitleLabel->TabIndex = 39;
			this->FournisseurTitleLabel->Text = L"FOURNISSEUR";
			// 
			// FFournisseur
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(768, 421);
			this->Controls->Add(this->FournisseurTitleLabel);
			this->Controls->Add(this->ConnectedModeRadioButton);
			this->Controls->Add(this->FournisseurTableLayoutPanel);
			this->Controls->Add(this->UpdateTableButton);
			this->Controls->Add(this->DisconnectedModeRadioButton);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"FFournisseur";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"FFournisseur";
			this->Shown += gcnew System::EventHandler(this, &FFournisseur::FFournisseur_Shown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->FournisseurBindingSource))->EndInit();
			this->FournisseurTableLayoutPanel->ResumeLayout(false);
			this->CRUDGroupBox->ResumeLayout(false);
			this->CRUDGroupBox->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->FournisseurDataGridView))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

			 // Set the Produit table in the datagrid when showed
	private: System::Void FFournisseur_Shown(System::Object^  sender, System::EventArgs^  e)
	{
		DelIndex = gcnew Generic::List<int>();
		FournisseurDatatable = _database->SendCommand("SELECT * FROM fournisseur");
		FournisseurBindingSource->DataSource = FournisseurDatatable;
		FournisseurDataGridView->DataSource = FournisseurBindingSource;

		DataReader = _database->ReadDatabase("SELECT * FROM categorie");
		if (DataReader != nullptr)
		{
			while (DataReader->Read())
			{
				CRUDCategorieComboBox->Items->Add(DataReader->GetString(1));
			}
		}
		delete(DataReader);
		DataReader = _database->ReadDatabase("SELECT * FROM pays");
		if (DataReader != nullptr)
		{
			while (DataReader->Read())
			{
				CRUDPaysComboBox->Items->Add(DataReader->GetString(1));
			}
		}
		delete(DataReader);
	}


			 // Parts for Connected or Disconnected Mode
			 void UpdateTable()
			 {
				 _database->UpdateTable(FournisseurDatatable, "SELECT * FROM fournisseur");
				 for (int i = 0; i < DelIndex->Count; i++)
				 {
					 _database->SendCommand("DELETE FROM `fournisseur` WHERE `fournisseur`.`ID` = " + (DelIndex[i] - 1));
				 }
				 DelIndex->Clear();
			 }

	private: System::Void UpdateTableButton_Click(System::Object^  sender, System::EventArgs^  e)
	{
		UpdateTable();
	}

	private: System::Void ConnectedModeRadioButton_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
	{
		UpdateTableButton->Enabled = false;
		bMode = true;
	}

	private: System::Void DisconnectedModeRadioButton_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
	{
		UpdateTableButton->Enabled = true;
		bMode = false;
	}

			
			 // Parts for edit datatable
			 void ClearBoxes()
			 {
				 CRUDSocieteTextBox->Clear();
				 CRUDCategorieComboBox->SelectedItem = nullptr;
				 CRUDAdresseTextBox->Clear();
				 CRUDCodeTextBox->Clear();
				 CRUDVilleTextBox->Clear();
				 CRUDPaysComboBox->SelectedItem = nullptr;
				 CRUDPhoneTextBox->Clear();
				 CRUDMailTextBox->Clear();
			 }

	private: System::Void ClearBoxesButton_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		ClearBoxes();
	}

	private: System::Void AddFournisseurButton_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (IsSyntaxCorrect())
		{
			FournisseurDatatable->Rows->Add(nullptr, CRUDSocieteTextBox->Text, CRUDAdresseTextBox->Text, CRUDCodeTextBox->Text, CRUDVilleTextBox->Text, CRUDPhoneTextBox->Text, CRUDMailTextBox->Text, CRUDPaysComboBox->SelectedIndex, CRUDCategorieComboBox->SelectedIndex);
			if (bMode) { UpdateTable(); }
		}
		else { MessageBox::Show("Erreur: Syntaxe incorrecte ou informations manquantes d'un ou plusieurs éléments"); }
	}

	private: System::Void ModifyFournisseurButton_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		if (IsSyntaxCorrect())
		{
			DataRow^ ModifiedRow = FournisseurDatatable->Rows[Index];
			ModifiedRow["Societe"] = CRUDSocieteTextBox->Text;
			ModifiedRow["Adresse"] = CRUDAdresseTextBox->Text;
			ModifiedRow["Code"] = CRUDCodeTextBox->Text;
			ModifiedRow["Ville"] = CRUDVilleTextBox->Text;
			ModifiedRow["Phone"] = CRUDPhoneTextBox->Text;
			ModifiedRow["Mail"] = CRUDMailTextBox->Text;
			ModifiedRow["Pays_ID"] = CRUDPaysComboBox->SelectedIndex + 1;
			ModifiedRow["Categorie_ID"] = CRUDCategorieComboBox->SelectedIndex + 1;
			ClearBoxes();
			DeleteFournisseurButton->Visible = false;
			ModifyFournisseurButton->Visible = false;
			if (bMode) { UpdateTable(); }
		}
		else { MessageBox::Show("Erreur: Syntaxe incorrecte ou informations manquantes d'un ou plusieurs éléments"); }
	}
			 
	private: System::Void DeleteFournisseurButton_Click(System::Object^  sender, System::EventArgs^  e)
	{
		FournisseurDatatable->Rows[Index]->Delete();
		DelIndex->Add(Index);
		ClearBoxes();
		DeleteFournisseurButton->Visible = false;
		ModifyFournisseurButton->Visible = false;
		if (bMode) { UpdateTable(); }
	}

	private: System::Void FournisseurDataGridView_CellMouseDoubleClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellMouseEventArgs^  e) 
	{
		DataGridViewCellCollection^ SelectedFournisseurData = FournisseurDataGridView->SelectedCells[0]->OwningRow->Cells;
		Index = SelectedFournisseurData[1]->RowIndex;
		CRUDSocieteTextBox->Text = SelectedFournisseurData[1]->Value->ToString();
		CRUDAdresseTextBox->Text = SelectedFournisseurData[2]->Value->ToString();
		CRUDCodeTextBox->Text = SelectedFournisseurData[3]->Value->ToString();
		CRUDVilleTextBox->Text = SelectedFournisseurData[4]->Value->ToString();
		CRUDPhoneTextBox->Text = SelectedFournisseurData[5]->Value->ToString();
		CRUDMailTextBox->Text = SelectedFournisseurData[6]->Value->ToString();
		CRUDPaysComboBox->SelectedIndex = SelectedFournisseurData[7]->Value->GetHashCode() - 1;
		CRUDCategorieComboBox->SelectedIndex = SelectedFournisseurData[8]->Value->GetHashCode() - 1;
		DeleteFournisseurButton->Visible = true;
		ModifyFournisseurButton->Visible = true;
	}


			 // Part for control data syntax
			 bool IsSyntaxCorrect()
			 {
				 if ((CRUDCodeTextBox->Text->Length < 5 && CRUDCodeTextBox->Text->Length > 0) || (CRUDPhoneTextBox->Text->Length < 10 && CRUDPhoneTextBox->Text->Length > 0) 
					 || CRUDSocieteTextBox->Text->Length < 2 || CRUDCategorieComboBox->SelectedIndex == -1 || CRUDPaysComboBox->SelectedIndex == -1)
				 { return false; }
				 return true;
			 }

	private: System::Void CRUDCodeTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) 
	{
		if (!Char::IsControl(e->KeyChar) && !Char::IsDigit(e->KeyChar)) { e->Handled = true; }
	}

	private: System::Void CRUDPhoneTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) 
	{
		if (!Char::IsControl(e->KeyChar) && !Char::IsDigit(e->KeyChar)) { e->Handled = true; }
	}
};
}
