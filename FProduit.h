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
	/// Description résumée de FProduit
	/// </summary>
	public ref class FProduit : public System::Windows::Forms::Form
	{
	public:
		FProduit(Database^ database)
		{
			InitializeComponent();
			_database = database;
		}

	private: Database^ _database;
	private: System::Data::DataTable^ ProduitDatatable;
	private: MySqlClient::MySqlDataReader^ DataReader;
	private: System::Windows::Forms::BindingSource^  ProduitBindingSource;
	private: System::Windows::Forms::GroupBox^  CRUDGroupBox;
	private: System::Windows::Forms::Button^  ModifyProduitButton;
	private: System::Windows::Forms::TextBox^  CRUDProduitTextBox;
	private: System::Windows::Forms::Label^  CRUDPerteLabel;
	private: System::Windows::Forms::Label^  CRUDProduitLabel;
	private: System::Windows::Forms::TextBox^  CRUDPerteTextBox;
	private: System::Windows::Forms::Button^  AddProduitButton;
	private: System::Windows::Forms::Label^  CRUDPrixLabel;
	private: System::Windows::Forms::Button^  ClearBoxesButton;
	private: System::Windows::Forms::TextBox^  CRUDPrixTextBox;
	private: System::Windows::Forms::Label^  CRUDEnRayonLabel;
	private: System::Windows::Forms::Label^  CRUDTypeLabel;
	private: System::Windows::Forms::TextBox^  CRUDEnRayonTextBox;
	private: System::Windows::Forms::Label^  CRUDStockLabel;
	private: System::Windows::Forms::Label^  CRUDSocieteLabel;

	private: System::Windows::Forms::TextBox^  CRUDStockTextBox;
	private: System::Windows::Forms::TextBox^  CRUDReferenceTextBox;
	private: System::Windows::Forms::Label^  CRUDReferenceLabel;
	private: System::Windows::Forms::ComboBox^  CRUDSocieteComboBox;

	private: System::Windows::Forms::ComboBox^  CRUDTypeComboBox;
	private: System::Windows::Forms::DataGridView^  ProduitDataGridView;
	private: System::Windows::Forms::Label^  ProduitTitleLabel;
	private: System::Windows::Forms::RadioButton^  ConnectedModeRadioButton;
	private: System::Windows::Forms::Button^  UpdateTableButton;
	private: System::Windows::Forms::RadioButton^  DisconnectedModeRadioButton;
	private: System::Windows::Forms::TableLayoutPanel^  FournisseurTableLayoutPanel;
	private: System::Windows::Forms::Button^  DeleteProduitButton;
			 bool bMode = false;
			 int Index = 0;
			 Generic::List<int> ^DelIndex;

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~FProduit()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::IContainer^  components;
	protected:

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
			this->ProduitBindingSource = (gcnew System::Windows::Forms::BindingSource(this->components));
			this->CRUDGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->DeleteProduitButton = (gcnew System::Windows::Forms::Button());
			this->CRUDSocieteComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->CRUDTypeComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->ModifyProduitButton = (gcnew System::Windows::Forms::Button());
			this->CRUDProduitTextBox = (gcnew System::Windows::Forms::TextBox());
			this->CRUDPerteLabel = (gcnew System::Windows::Forms::Label());
			this->CRUDProduitLabel = (gcnew System::Windows::Forms::Label());
			this->CRUDPerteTextBox = (gcnew System::Windows::Forms::TextBox());
			this->AddProduitButton = (gcnew System::Windows::Forms::Button());
			this->CRUDPrixLabel = (gcnew System::Windows::Forms::Label());
			this->ClearBoxesButton = (gcnew System::Windows::Forms::Button());
			this->CRUDPrixTextBox = (gcnew System::Windows::Forms::TextBox());
			this->CRUDEnRayonLabel = (gcnew System::Windows::Forms::Label());
			this->CRUDTypeLabel = (gcnew System::Windows::Forms::Label());
			this->CRUDEnRayonTextBox = (gcnew System::Windows::Forms::TextBox());
			this->CRUDStockLabel = (gcnew System::Windows::Forms::Label());
			this->CRUDSocieteLabel = (gcnew System::Windows::Forms::Label());
			this->CRUDStockTextBox = (gcnew System::Windows::Forms::TextBox());
			this->CRUDReferenceTextBox = (gcnew System::Windows::Forms::TextBox());
			this->CRUDReferenceLabel = (gcnew System::Windows::Forms::Label());
			this->ProduitDataGridView = (gcnew System::Windows::Forms::DataGridView());
			this->ProduitTitleLabel = (gcnew System::Windows::Forms::Label());
			this->ConnectedModeRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->UpdateTableButton = (gcnew System::Windows::Forms::Button());
			this->DisconnectedModeRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->FournisseurTableLayoutPanel = (gcnew System::Windows::Forms::TableLayoutPanel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ProduitBindingSource))->BeginInit();
			this->CRUDGroupBox->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ProduitDataGridView))->BeginInit();
			this->FournisseurTableLayoutPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// CRUDGroupBox
			// 
			this->CRUDGroupBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->CRUDGroupBox->Controls->Add(this->DeleteProduitButton);
			this->CRUDGroupBox->Controls->Add(this->CRUDSocieteComboBox);
			this->CRUDGroupBox->Controls->Add(this->CRUDTypeComboBox);
			this->CRUDGroupBox->Controls->Add(this->ModifyProduitButton);
			this->CRUDGroupBox->Controls->Add(this->CRUDProduitTextBox);
			this->CRUDGroupBox->Controls->Add(this->CRUDPerteLabel);
			this->CRUDGroupBox->Controls->Add(this->CRUDProduitLabel);
			this->CRUDGroupBox->Controls->Add(this->CRUDPerteTextBox);
			this->CRUDGroupBox->Controls->Add(this->AddProduitButton);
			this->CRUDGroupBox->Controls->Add(this->CRUDPrixLabel);
			this->CRUDGroupBox->Controls->Add(this->ClearBoxesButton);
			this->CRUDGroupBox->Controls->Add(this->CRUDPrixTextBox);
			this->CRUDGroupBox->Controls->Add(this->CRUDEnRayonLabel);
			this->CRUDGroupBox->Controls->Add(this->CRUDTypeLabel);
			this->CRUDGroupBox->Controls->Add(this->CRUDEnRayonTextBox);
			this->CRUDGroupBox->Controls->Add(this->CRUDStockLabel);
			this->CRUDGroupBox->Controls->Add(this->CRUDSocieteLabel);
			this->CRUDGroupBox->Controls->Add(this->CRUDStockTextBox);
			this->CRUDGroupBox->Controls->Add(this->CRUDReferenceTextBox);
			this->CRUDGroupBox->Controls->Add(this->CRUDReferenceLabel);
			this->CRUDGroupBox->Location = System::Drawing::Point(397, 3);
			this->CRUDGroupBox->Name = L"CRUDGroupBox";
			this->CRUDGroupBox->Size = System::Drawing::Size(352, 365);
			this->CRUDGroupBox->TabIndex = 28;
			this->CRUDGroupBox->TabStop = false;
			this->CRUDGroupBox->Text = L"CRUD";
			// 
			// DeleteProduitButton
			// 
			this->DeleteProduitButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->DeleteProduitButton->Location = System::Drawing::Point(27, 291);
			this->DeleteProduitButton->Name = L"DeleteProduitButton";
			this->DeleteProduitButton->Size = System::Drawing::Size(138, 36);
			this->DeleteProduitButton->TabIndex = 45;
			this->DeleteProduitButton->Text = L"Delete";
			this->DeleteProduitButton->UseVisualStyleBackColor = true;
			this->DeleteProduitButton->Visible = false;
			this->DeleteProduitButton->Click += gcnew System::EventHandler(this, &FProduit::DeleteProduitButton_Click);
			// 
			// CRUDSocieteComboBox
			// 
			this->CRUDSocieteComboBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->CRUDSocieteComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->CRUDSocieteComboBox->FormattingEnabled = true;
			this->CRUDSocieteComboBox->Location = System::Drawing::Point(66, 109);
			this->CRUDSocieteComboBox->Name = L"CRUDSocieteComboBox";
			this->CRUDSocieteComboBox->Size = System::Drawing::Size(100, 21);
			this->CRUDSocieteComboBox->TabIndex = 25;
			// 
			// CRUDTypeComboBox
			// 
			this->CRUDTypeComboBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->CRUDTypeComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->CRUDTypeComboBox->FormattingEnabled = true;
			this->CRUDTypeComboBox->Location = System::Drawing::Point(241, 48);
			this->CRUDTypeComboBox->Name = L"CRUDTypeComboBox";
			this->CRUDTypeComboBox->Size = System::Drawing::Size(100, 21);
			this->CRUDTypeComboBox->TabIndex = 24;
			// 
			// ModifyProduitButton
			// 
			this->ModifyProduitButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->ModifyProduitButton->Location = System::Drawing::Point(202, 291);
			this->ModifyProduitButton->Name = L"ModifyProduitButton";
			this->ModifyProduitButton->Size = System::Drawing::Size(138, 36);
			this->ModifyProduitButton->TabIndex = 23;
			this->ModifyProduitButton->Text = L"Modify";
			this->ModifyProduitButton->UseVisualStyleBackColor = true;
			this->ModifyProduitButton->Visible = false;
			this->ModifyProduitButton->Click += gcnew System::EventHandler(this, &FProduit::ModifyProduitButton_Click);
			// 
			// CRUDProduitTextBox
			// 
			this->CRUDProduitTextBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->CRUDProduitTextBox->Location = System::Drawing::Point(66, 48);
			this->CRUDProduitTextBox->MaxLength = 30;
			this->CRUDProduitTextBox->Name = L"CRUDProduitTextBox";
			this->CRUDProduitTextBox->Size = System::Drawing::Size(100, 20);
			this->CRUDProduitTextBox->TabIndex = 5;
			// 
			// CRUDPerteLabel
			// 
			this->CRUDPerteLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->CRUDPerteLabel->AutoSize = true;
			this->CRUDPerteLabel->Location = System::Drawing::Point(203, 237);
			this->CRUDPerteLabel->Name = L"CRUDPerteLabel";
			this->CRUDPerteLabel->Size = System::Drawing::Size(32, 13);
			this->CRUDPerteLabel->TabIndex = 22;
			this->CRUDPerteLabel->Text = L"Perte";
			// 
			// CRUDProduitLabel
			// 
			this->CRUDProduitLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->CRUDProduitLabel->AutoSize = true;
			this->CRUDProduitLabel->Location = System::Drawing::Point(17, 51);
			this->CRUDProduitLabel->Name = L"CRUDProduitLabel";
			this->CRUDProduitLabel->Size = System::Drawing::Size(40, 13);
			this->CRUDProduitLabel->TabIndex = 6;
			this->CRUDProduitLabel->Text = L"Produit";
			// 
			// CRUDPerteTextBox
			// 
			this->CRUDPerteTextBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->CRUDPerteTextBox->Location = System::Drawing::Point(241, 233);
			this->CRUDPerteTextBox->MaxLength = 5;
			this->CRUDPerteTextBox->Name = L"CRUDPerteTextBox";
			this->CRUDPerteTextBox->Size = System::Drawing::Size(100, 20);
			this->CRUDPerteTextBox->TabIndex = 21;
			this->CRUDPerteTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &FProduit::CRUDPerteTextBox_KeyPress);
			// 
			// AddProduitButton
			// 
			this->AddProduitButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->AddProduitButton->Location = System::Drawing::Point(202, 291);
			this->AddProduitButton->Name = L"AddProduitButton";
			this->AddProduitButton->Size = System::Drawing::Size(138, 36);
			this->AddProduitButton->TabIndex = 7;
			this->AddProduitButton->Text = L"Add";
			this->AddProduitButton->UseVisualStyleBackColor = true;
			this->AddProduitButton->Click += gcnew System::EventHandler(this, &FProduit::AddProduitButton_Click);
			// 
			// CRUDPrixLabel
			// 
			this->CRUDPrixLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->CRUDPrixLabel->AutoSize = true;
			this->CRUDPrixLabel->Location = System::Drawing::Point(36, 178);
			this->CRUDPrixLabel->Name = L"CRUDPrixLabel";
			this->CRUDPrixLabel->Size = System::Drawing::Size(24, 13);
			this->CRUDPrixLabel->TabIndex = 20;
			this->CRUDPrixLabel->Text = L"Prix";
			// 
			// ClearBoxesButton
			// 
			this->ClearBoxesButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->ClearBoxesButton->Location = System::Drawing::Point(27, 291);
			this->ClearBoxesButton->Name = L"ClearBoxesButton";
			this->ClearBoxesButton->Size = System::Drawing::Size(138, 36);
			this->ClearBoxesButton->TabIndex = 8;
			this->ClearBoxesButton->Text = L"Clear";
			this->ClearBoxesButton->UseVisualStyleBackColor = true;
			this->ClearBoxesButton->Click += gcnew System::EventHandler(this, &FProduit::ClearBoxesButton_Click);
			// 
			// CRUDPrixTextBox
			// 
			this->CRUDPrixTextBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->CRUDPrixTextBox->Location = System::Drawing::Point(66, 175);
			this->CRUDPrixTextBox->MaxLength = 6;
			this->CRUDPrixTextBox->Name = L"CRUDPrixTextBox";
			this->CRUDPrixTextBox->Size = System::Drawing::Size(100, 20);
			this->CRUDPrixTextBox->TabIndex = 19;
			this->CRUDPrixTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &FProduit::CRUDPrixTextBox_KeyPress);
			// 
			// CRUDEnRayonLabel
			// 
			this->CRUDEnRayonLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->CRUDEnRayonLabel->AutoSize = true;
			this->CRUDEnRayonLabel->Location = System::Drawing::Point(11, 236);
			this->CRUDEnRayonLabel->Name = L"CRUDEnRayonLabel";
			this->CRUDEnRayonLabel->Size = System::Drawing::Size(49, 13);
			this->CRUDEnRayonLabel->TabIndex = 18;
			this->CRUDEnRayonLabel->Text = L"En rayon";
			// 
			// CRUDTypeLabel
			// 
			this->CRUDTypeLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->CRUDTypeLabel->AutoSize = true;
			this->CRUDTypeLabel->Location = System::Drawing::Point(199, 51);
			this->CRUDTypeLabel->Name = L"CRUDTypeLabel";
			this->CRUDTypeLabel->Size = System::Drawing::Size(31, 13);
			this->CRUDTypeLabel->TabIndex = 10;
			this->CRUDTypeLabel->Text = L"Type";
			// 
			// CRUDEnRayonTextBox
			// 
			this->CRUDEnRayonTextBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->CRUDEnRayonTextBox->Location = System::Drawing::Point(66, 233);
			this->CRUDEnRayonTextBox->MaxLength = 5;
			this->CRUDEnRayonTextBox->Name = L"CRUDEnRayonTextBox";
			this->CRUDEnRayonTextBox->Size = System::Drawing::Size(100, 20);
			this->CRUDEnRayonTextBox->TabIndex = 17;
			this->CRUDEnRayonTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &FProduit::CRUDEnRayonTextBox_KeyPress);
			// 
			// CRUDStockLabel
			// 
			this->CRUDStockLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->CRUDStockLabel->AutoSize = true;
			this->CRUDStockLabel->Location = System::Drawing::Point(200, 178);
			this->CRUDStockLabel->Name = L"CRUDStockLabel";
			this->CRUDStockLabel->Size = System::Drawing::Size(35, 13);
			this->CRUDStockLabel->TabIndex = 16;
			this->CRUDStockLabel->Text = L"Stock";
			// 
			// CRUDSocieteLabel
			// 
			this->CRUDSocieteLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->CRUDSocieteLabel->AutoSize = true;
			this->CRUDSocieteLabel->Location = System::Drawing::Point(11, 113);
			this->CRUDSocieteLabel->Name = L"CRUDSocieteLabel";
			this->CRUDSocieteLabel->Size = System::Drawing::Size(43, 13);
			this->CRUDSocieteLabel->TabIndex = 12;
			this->CRUDSocieteLabel->Text = L"Societe";
			// 
			// CRUDStockTextBox
			// 
			this->CRUDStockTextBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->CRUDStockTextBox->Location = System::Drawing::Point(241, 175);
			this->CRUDStockTextBox->MaxLength = 5;
			this->CRUDStockTextBox->Name = L"CRUDStockTextBox";
			this->CRUDStockTextBox->Size = System::Drawing::Size(100, 20);
			this->CRUDStockTextBox->TabIndex = 15;
			this->CRUDStockTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &FProduit::CRUDStockTextBox_KeyPress);
			// 
			// CRUDReferenceTextBox
			// 
			this->CRUDReferenceTextBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->CRUDReferenceTextBox->Location = System::Drawing::Point(241, 110);
			this->CRUDReferenceTextBox->MaxLength = 13;
			this->CRUDReferenceTextBox->Name = L"CRUDReferenceTextBox";
			this->CRUDReferenceTextBox->Size = System::Drawing::Size(100, 20);
			this->CRUDReferenceTextBox->TabIndex = 13;
			this->CRUDReferenceTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &FProduit::CRUDReferenceTextBox_KeyPress);
			// 
			// CRUDReferenceLabel
			// 
			this->CRUDReferenceLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->CRUDReferenceLabel->AutoSize = true;
			this->CRUDReferenceLabel->Location = System::Drawing::Point(178, 113);
			this->CRUDReferenceLabel->Name = L"CRUDReferenceLabel";
			this->CRUDReferenceLabel->Size = System::Drawing::Size(57, 13);
			this->CRUDReferenceLabel->TabIndex = 14;
			this->CRUDReferenceLabel->Text = L"Reference";
			// 
			// ProduitDataGridView
			// 
			this->ProduitDataGridView->AllowUserToAddRows = false;
			this->ProduitDataGridView->AllowUserToDeleteRows = false;
			this->ProduitDataGridView->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->ProduitDataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->ProduitDataGridView->Dock = System::Windows::Forms::DockStyle::Fill;
			this->ProduitDataGridView->GridColor = System::Drawing::SystemColors::ActiveCaption;
			this->ProduitDataGridView->Location = System::Drawing::Point(2, 2);
			this->ProduitDataGridView->Margin = System::Windows::Forms::Padding(2);
			this->ProduitDataGridView->MultiSelect = false;
			this->ProduitDataGridView->Name = L"ProduitDataGridView";
			this->ProduitDataGridView->RowTemplate->Height = 28;
			this->ProduitDataGridView->Size = System::Drawing::Size(390, 368);
			this->ProduitDataGridView->TabIndex = 1;
			this->ProduitDataGridView->CellMouseDoubleClick += gcnew System::Windows::Forms::DataGridViewCellMouseEventHandler(this, &FProduit::ProduitDataGridView_CellMouseDoubleClick);
			// 
			// ProduitTitleLabel
			// 
			this->ProduitTitleLabel->AutoSize = true;
			this->ProduitTitleLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->ProduitTitleLabel->Location = System::Drawing::Point(8, 6);
			this->ProduitTitleLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->ProduitTitleLabel->Name = L"ProduitTitleLabel";
			this->ProduitTitleLabel->Size = System::Drawing::Size(133, 26);
			this->ProduitTitleLabel->TabIndex = 43;
			this->ProduitTitleLabel->Text = L"PRODUITS";
			// 
			// ConnectedModeRadioButton
			// 
			this->ConnectedModeRadioButton->AutoSize = true;
			this->ConnectedModeRadioButton->Location = System::Drawing::Point(170, 13);
			this->ConnectedModeRadioButton->Margin = System::Windows::Forms::Padding(2);
			this->ConnectedModeRadioButton->Name = L"ConnectedModeRadioButton";
			this->ConnectedModeRadioButton->Size = System::Drawing::Size(85, 17);
			this->ConnectedModeRadioButton->TabIndex = 42;
			this->ConnectedModeRadioButton->Text = L"Auto Update";
			this->ConnectedModeRadioButton->UseVisualStyleBackColor = true;
			this->ConnectedModeRadioButton->CheckedChanged += gcnew System::EventHandler(this, &FProduit::ConnectedModeRadioButton_CheckedChanged);
			// 
			// UpdateTableButton
			// 
			this->UpdateTableButton->Location = System::Drawing::Point(353, 9);
			this->UpdateTableButton->Margin = System::Windows::Forms::Padding(2);
			this->UpdateTableButton->Name = L"UpdateTableButton";
			this->UpdateTableButton->Size = System::Drawing::Size(99, 25);
			this->UpdateTableButton->TabIndex = 40;
			this->UpdateTableButton->Text = L"Update Changes";
			this->UpdateTableButton->UseVisualStyleBackColor = true;
			this->UpdateTableButton->Click += gcnew System::EventHandler(this, &FProduit::UpdateTableButton_Click);
			// 
			// DisconnectedModeRadioButton
			// 
			this->DisconnectedModeRadioButton->AutoSize = true;
			this->DisconnectedModeRadioButton->Checked = true;
			this->DisconnectedModeRadioButton->Location = System::Drawing::Point(257, 13);
			this->DisconnectedModeRadioButton->Margin = System::Windows::Forms::Padding(2);
			this->DisconnectedModeRadioButton->Name = L"DisconnectedModeRadioButton";
			this->DisconnectedModeRadioButton->Size = System::Drawing::Size(98, 17);
			this->DisconnectedModeRadioButton->TabIndex = 41;
			this->DisconnectedModeRadioButton->TabStop = true;
			this->DisconnectedModeRadioButton->Text = L"Manual Update";
			this->DisconnectedModeRadioButton->UseVisualStyleBackColor = true;
			this->DisconnectedModeRadioButton->CheckedChanged += gcnew System::EventHandler(this, &FProduit::DisconnectedModeRadioButton_CheckedChanged);
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
			this->FournisseurTableLayoutPanel->Controls->Add(this->ProduitDataGridView, 0, 0);
			this->FournisseurTableLayoutPanel->Controls->Add(this->CRUDGroupBox, 1, 0);
			this->FournisseurTableLayoutPanel->Location = System::Drawing::Point(8, 35);
			this->FournisseurTableLayoutPanel->Margin = System::Windows::Forms::Padding(2);
			this->FournisseurTableLayoutPanel->Name = L"FournisseurTableLayoutPanel";
			this->FournisseurTableLayoutPanel->RowCount = 1;
			this->FournisseurTableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->FournisseurTableLayoutPanel->Size = System::Drawing::Size(752, 372);
			this->FournisseurTableLayoutPanel->TabIndex = 44;
			// 
			// FProduit
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(768, 421);
			this->ControlBox = false;
			this->Controls->Add(this->FournisseurTableLayoutPanel);
			this->Controls->Add(this->ProduitTitleLabel);
			this->Controls->Add(this->ConnectedModeRadioButton);
			this->Controls->Add(this->UpdateTableButton);
			this->Controls->Add(this->DisconnectedModeRadioButton);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"FProduit";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"FProduit";
			this->Shown += gcnew System::EventHandler(this, &FProduit::FProduit_Shown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ProduitBindingSource))->EndInit();
			this->CRUDGroupBox->ResumeLayout(false);
			this->CRUDGroupBox->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ProduitDataGridView))->EndInit();
			this->FournisseurTableLayoutPanel->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		// Set the Produit table in the datagrid when showed
	private: System::Void FProduit_Shown(System::Object^  sender, System::EventArgs^  e)
	{
		DelIndex = gcnew Generic::List<int>();
		ProduitDatatable = _database->SendCommand("SELECT p.Produit, t.Type, f.Societe, p.Reference, p.Prix, p.Stock, p.EnRayon, p.Perte FROM produit p, fournisseur f, type t WHERE p.Type_ID = t.ID && p.Fournisseur_ID = f.ID");
		ProduitBindingSource->DataSource = ProduitDatatable;
		ProduitDataGridView->DataSource = ProduitBindingSource;

		DataReader = _database->ReadDatabase("SELECT * FROM type");
		if (DataReader != nullptr)
		{
			while (DataReader->Read())
			{
				CRUDTypeComboBox->Items->Add(DataReader->GetString(1));
			}
		}
		delete(DataReader);
		DataReader = _database->ReadDatabase("SELECT * FROM fournisseur");
		if (DataReader != nullptr)
		{
			while (DataReader->Read())
			{
				CRUDSocieteComboBox->Items->Add(DataReader->GetString(1));
			}
		}
		delete(DataReader);
	}


			 // Parts for Connected or Disconnected Mode
			 void UpdateTable()
			 {
				 _database->UpdateTable(ProduitDatatable, "SELECT p.Produit, t.Type, f.Societe, p.Reference, p.Prix, p.Stock, p.EnRayon, p.Perte FROM produit p, fournisseur f, type t WHERE p.Type_ID = t.ID && p.Fournisseur_ID = f.ID");
				 for (int i = 0; i < DelIndex->Count; i++)
				 {
					 _database->SendCommand("DELETE FROM `produit` WHERE `produit`.`ID` = " + (DelIndex[i] - 1));
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
				 CRUDProduitTextBox->Clear();
				 CRUDTypeComboBox->SelectedItem = nullptr;
				 CRUDSocieteComboBox->SelectedItem = nullptr;
				 CRUDReferenceTextBox->Clear();
				 CRUDPrixTextBox->Clear();
				 CRUDEnRayonTextBox->Clear();
				 CRUDStockTextBox->Clear();
				 CRUDPerteTextBox->Clear();
			 }

	private: System::Void ClearBoxesButton_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		ClearBoxes();
	}

	private: System::Void AddProduitButton_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (IsSyntaxCorrect())
		{
			ProduitDatatable->Rows->Add(CRUDProduitTextBox->Text, CRUDTypeComboBox->SelectedItem, CRUDSocieteComboBox->SelectedItem, CRUDReferenceTextBox->Text, (float)Convert::ToDouble(CRUDPrixTextBox->Text), Convert::ToInt32(CRUDStockTextBox->Text), Convert::ToInt32(CRUDEnRayonTextBox->Text), Convert::ToInt32(CRUDPerteTextBox->Text));
			if (bMode) { UpdateTable(); }
		}
		else { MessageBox::Show("Erreur: Syntaxe incorrecte ou informations manquantes d'un ou plusieurs éléments"); }
	}

	private: System::Void ModifyProduitButton_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		if (IsSyntaxCorrect())
		{
			DataRow^ ModifiedRow = ProduitDatatable->Rows[Index];
			ModifiedRow["Produit"] = CRUDProduitTextBox->Text;
			ModifiedRow["Type"] = CRUDTypeComboBox->SelectedItem;
			ModifiedRow["Societe"] = CRUDSocieteComboBox->SelectedItem;
			ModifiedRow["Reference"] = CRUDReferenceTextBox->Text;
			ModifiedRow["Prix"] = (float)Convert::ToDouble(CRUDPrixTextBox->Text);
			ModifiedRow["Stock"] = Convert::ToInt32(CRUDStockTextBox->Text);
			ModifiedRow["EnRayon"] = Convert::ToInt32(CRUDEnRayonTextBox->Text);
			ModifiedRow["Perte"] = Convert::ToInt32(CRUDPerteTextBox->Text);
			ClearBoxes();
			DeleteProduitButton->Visible = false;
			ModifyProduitButton->Visible = false;
			if (bMode) { UpdateTable(); }
		}
		else { MessageBox::Show("Erreur: Syntaxe incorrecte ou informations manquantes d'un ou plusieurs éléments"); }
	}

	private: System::Void DeleteProduitButton_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		ProduitDatatable->Rows[Index]->Delete();
		DelIndex->Add(Index);
		ClearBoxes();
		DeleteProduitButton->Visible = false;
		ModifyProduitButton->Visible = false;
		if (bMode) { UpdateTable(); }
	}

	private: System::Void ProduitDataGridView_CellMouseDoubleClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellMouseEventArgs^  e)
	{
		DataGridViewCellCollection^ SelectedFournisseurData = ProduitDataGridView->SelectedCells[0]->OwningRow->Cells;
		Index = SelectedFournisseurData[0]->RowIndex;
		CRUDProduitTextBox->Text = SelectedFournisseurData[0]->Value->ToString();
		CRUDTypeComboBox->SelectedItem = SelectedFournisseurData[1]->Value;
		CRUDSocieteComboBox->SelectedItem = SelectedFournisseurData[2]->Value;
		CRUDReferenceTextBox->Text = SelectedFournisseurData[3]->Value->ToString();
		CRUDPrixTextBox->Text = SelectedFournisseurData[4]->Value->ToString();
		CRUDStockTextBox->Text = SelectedFournisseurData[5]->Value->ToString();
		CRUDEnRayonTextBox->Text = SelectedFournisseurData[6]->Value->ToString();
		CRUDPerteTextBox->Text = SelectedFournisseurData[7]->Value->ToString();
		DeleteProduitButton->Visible = true;
		ModifyProduitButton->Visible = true;
	}


			 // Part for control data syntax
			 bool IsSyntaxCorrect()
			 {
				 if (CRUDReferenceTextBox->Text->Length != 13 || (CRUDPrixTextBox->Text->Length < 3 || !CRUDPrixTextBox->Text->Contains(","))
					 || CRUDProduitTextBox->Text->Length < 2 || CRUDTypeComboBox->SelectedIndex == -1 || CRUDSocieteComboBox->SelectedIndex == -1
					 || CRUDPrixTextBox->Text == "" || CRUDStockTextBox->Text == "" || CRUDEnRayonTextBox->Text == "" || CRUDPerteTextBox->Text == "")
				 {
					 return false;
				 }
				 return true;
			 }

	private: System::Void CRUDReferenceTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) 
	{
		if (!Char::IsControl(e->KeyChar) && !Char::IsDigit(e->KeyChar)) { e->Handled = true; }
	}

	private: System::Void CRUDEnRayonTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) 
	{
		if (!Char::IsControl(e->KeyChar) && !Char::IsDigit(e->KeyChar)) { e->Handled = true; }
	}

	private: System::Void CRUDPerteTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) 
	{
		if (!Char::IsControl(e->KeyChar) && !Char::IsDigit(e->KeyChar)) { e->Handled = true; }
	}

	private: System::Void CRUDStockTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) 
	{
		if (!Char::IsControl(e->KeyChar) && !Char::IsDigit(e->KeyChar)) { e->Handled = true; }
	}

	private: System::Void CRUDPrixTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) 
	{
		if (!Char::IsControl(e->KeyChar) && !Char::IsDigit(e->KeyChar) && (e->KeyChar != ',')) { e->Handled = true; }
	}
};
}
