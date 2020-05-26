#pragma once

#include "Database.h"
#include "FFournisseur.h"
#include "FProduit.h"
#include "FConfig.h"

namespace GestionMagasin {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de FMain
	/// </summary>
	public ref class FMain : public System::Windows::Forms::Form
	{
	public:
		FMain(void)
		{
			InitializeComponent();
			//
			//TODO: ajoutez ici le code du constructeur
			//
		}

	private: Database^ database;
			 FFournisseur^ Fournisseur;
			 FProduit^ Produit;
			 FConfig^ Config;
	private: System::Windows::Forms::MenuStrip^  MenuStrip;
	private: System::Windows::Forms::ToolStripMenuItem^  FournisseurStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ProduitStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ConfigurationStripMenuItem;
			 Generic::List<Form^> ^ActiveForms;

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~FMain()
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
			this->MenuStrip = (gcnew System::Windows::Forms::MenuStrip());
			this->FournisseurStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ProduitStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ConfigurationStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->MenuStrip->SuspendLayout();
			this->SuspendLayout();
			// 
			// MenuStrip
			// 
			this->MenuStrip->ImageScalingSize = System::Drawing::Size(24, 24);
			this->MenuStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->FournisseurStripMenuItem,
					this->ProduitStripMenuItem, this->ConfigurationStripMenuItem
			});
			this->MenuStrip->Location = System::Drawing::Point(0, 0);
			this->MenuStrip->Name = L"MenuStrip";
			this->MenuStrip->Size = System::Drawing::Size(1258, 33);
			this->MenuStrip->TabIndex = 0;
			this->MenuStrip->Text = L"MenuStrip";
			// 
			// FournisseurStripMenuItem
			// 
			this->FournisseurStripMenuItem->Name = L"FournisseurStripMenuItem";
			this->FournisseurStripMenuItem->Size = System::Drawing::Size(115, 29);
			this->FournisseurStripMenuItem->Text = L"Fournisseur";
			this->FournisseurStripMenuItem->Click += gcnew System::EventHandler(this, &FMain::FournisseurStripMenuItem_Click);
			// 
			// ProduitStripMenuItem
			// 
			this->ProduitStripMenuItem->Name = L"ProduitStripMenuItem";
			this->ProduitStripMenuItem->Size = System::Drawing::Size(82, 29);
			this->ProduitStripMenuItem->Text = L"Produit";
			this->ProduitStripMenuItem->Click += gcnew System::EventHandler(this, &FMain::ProduitStripMenuItem_Click);
			// 
			// ConfigurationStripMenuItem
			// 
			this->ConfigurationStripMenuItem->Name = L"ConfigurationStripMenuItem";
			this->ConfigurationStripMenuItem->Size = System::Drawing::Size(133, 29);
			this->ConfigurationStripMenuItem->Text = L"Configuration";
			this->ConfigurationStripMenuItem->Click += gcnew System::EventHandler(this, &FMain::ConfigurationStripMenuItem_Click);
			// 
			// FMain
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1258, 694);
			this->Controls->Add(this->MenuStrip);
			this->IsMdiContainer = true;
			this->MainMenuStrip = this->MenuStrip;
			this->MinimumSize = System::Drawing::Size(1280, 750);
			this->Name = L"FMain";
			this->Text = L"Gestion Magasin";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Shown += gcnew System::EventHandler(this, &FMain::FMain_Shown);
			this->MenuStrip->ResumeLayout(false);
			this->MenuStrip->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		// When App start, instance database an try to connect. Show Database/Config in responce. 
		// If the from don't exist, we create it 
	private: System::Void FMain_Shown(System::Object^  sender, System::EventArgs^  e)
	{
		ActiveForms = gcnew Generic::List<Form^>;
		database = gcnew Database();
		if (!database->Connect())
		{
			MessageBox::Show("Erreur de connexion à la base de données.");
			if (!IsFormExist_Hide(Config))
			{
				Config = gcnew FConfig(database);
				Config->MdiParent = this;
				Config->Dock = DockStyle::Fill;
				ActiveForms->Add(Config);
			}
			Config->Show();
		}
		else
		{
			MessageBox::Show("Connecté à la base de données avec succès.");
			if (!IsFormExist_Hide(Fournisseur))
			{
				Fournisseur = gcnew FFournisseur(database);
				Fournisseur->MdiParent = this;
				Fournisseur->Dock = DockStyle::Fill;
				ActiveForms->Add(Fournisseur);
			}
			Fournisseur->Show();
		}
	}

			 // When click on DB tab, test if the DB connection is open and show the DB from or not in responce.
			 // If the from don't exist, we create it 
	private: System::Void FournisseurStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (database->GetConnectionState() == System::Data::ConnectionState::Open)
		{
			if (!IsFormExist_Hide(Fournisseur))
			{
				Fournisseur = gcnew FFournisseur(database);
				Fournisseur->MdiParent = this;
				Fournisseur->Dock = DockStyle::Fill;
				ActiveForms->Add(Fournisseur);
			}
			Fournisseur->Show();
		}
		else
		{
			MessageBox::Show("Aucune base de données connecté.");
		}
	}


			 // When click on DB tab, test if the DB connection is open and show the DB from or not in responce.
			 // If the from don't exist, we create it 
	private: System::Void ProduitStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (database->GetConnectionState() == System::Data::ConnectionState::Open)
		{
			if (!IsFormExist_Hide(Produit))
			{
				Produit = gcnew FProduit(database);
				Produit->MdiParent = this;
				Produit->Dock = DockStyle::Fill;
				ActiveForms->Add(Produit);
			}
			Produit->Show();
		}
		else
		{
			MessageBox::Show("Aucune base de données connecté.");
		}
	}


			 // When click on Config tab, show the config form
			 // If the from don't exist, we create it 
	private: System::Void ConfigurationStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (!IsFormExist_Hide(Config))
		{
			Config = gcnew FConfig(database);
			Config->MdiParent = this;
			Config->Dock = DockStyle::Fill;
			ActiveForms->Add(Config);
		}
		Config->Show();
	}

			 // Hide all forms, and test if the mdi form (parms) already exist thanks to array where is stocked all forms (when the from is created)
			 bool IsFormExist_Hide(Form^ MdiForm)
			 {
				 for (int i = 0; i < ActiveForms->Count; i++)
				 {
					 ActiveForms[i]->Hide();
				 }
				 return ActiveForms->Contains(MdiForm);
			 }
};
}
