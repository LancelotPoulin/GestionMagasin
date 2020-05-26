#include "Database.h"


Database::Database()
{
	Connection = gcnew MySqlClient::MySqlConnection();
	Command = gcnew MySqlClient::MySqlCommand();
	DataAdaptator = gcnew MySqlClient::MySqlDataAdapter();
	CommandBuilder = gcnew MySqlClient::MySqlCommandBuilder(DataAdaptator);
	CommandBuilder->ConflictOption = System::Data::ConflictOption::OverwriteChanges;

	OdbcConnection = gcnew Data::Odbc::OdbcConnection();
	OdbcCommand = gcnew Data::Odbc::OdbcCommand();
}


System::Data::ConnectionState Database::GetConnectionState() { return Connection->State; }


void Database::UpdateConnectionInfo()
{
	ConnectionInfo =
		"Server=" + ConfigurationManager::AppSettings["Server"] + ";" +
		"Port=" + ConfigurationManager::AppSettings["Port"] + ";" +
		"Uid=" + ConfigurationManager::AppSettings["User"] + ";" +
		"Pwd=" + ConfigurationManager::AppSettings["Password"] + ";" +
		"Database=" + ConfigurationManager::AppSettings["Database"] + ";";
	OdbcConnectionInfo = "DRIVER={MySQL ODBC 5.1 Driver};" +
		"SERVER=" + ConfigurationManager::AppSettings["Server"] + ";" +
		"PORT=" + ConfigurationManager::AppSettings["Port"] + ";" +
		"DATABASE=" + ConfigurationManager::AppSettings["Database"] + ";"
		"USER=" + ConfigurationManager::AppSettings["User"] + ";" +
		"PASSWORD=" + ConfigurationManager::AppSettings["Password"] + ";" +
		"OPTION=3;";
}


bool Database::Connect()
{
	if (GetConnectionState() == System::Data::ConnectionState::Open) { Connection->Close(); }
	UpdateConnectionInfo();
	Connection->ConnectionString = ConnectionInfo;
	try {
		Connection->Open();
	}
	catch (MySqlClient::MySqlException^ Ex)
	{
		return false;
	}
	Command->Connection = Connection;
	return true;
}


MySqlClient::MySqlDataReader^ Database::ReadDatabase(String^ CommandLine)
{
	Command->CommandText = CommandLine;
	try {
		return Command->ExecuteReader();
	}	
	catch (Exception ^Ex) {}
}


System::Data::DataTable^ Database::SendCommand(String^ CommandLine)
{
	DataTable = gcnew System::Data::DataTable();
	Command->CommandText = CommandLine;
	try {
		DataAdaptator->SelectCommand = Command;
		DataAdaptator->Fill(DataTable);
	}
	catch (Exception ^Ex) {}
	return DataTable;
}


void Database::UpdateTable(System::Data::DataTable^ DataTable, String^ TableCommand)
{
	Command->CommandText = TableCommand;
	try {
		DataAdaptator->UpdateCommand = CommandBuilder->GetUpdateCommand();
		DataAdaptator->Update(DataTable);
	} catch (Exception ^Ex) {}
}


#pragma region ODBC

void Database::ODBCConnect()
{
	if (OdbcConnection->State == System::Data::ConnectionState::Open) { OdbcConnection->Close(); }
	UpdateConnectionInfo();
	OdbcConnection->ConnectionString = OdbcConnectionInfo;
	try {
		OdbcConnection->Open();
	}
	catch (Data::Odbc::OdbcException^ Ex) { }
	OdbcCommand->Connection = OdbcConnection;
}


Data::Odbc::OdbcDataReader^ Database::OdbcSendCommand(String^ CommandLine)
{
	OdbcCommand->CommandText = CommandLine;
	try {
		return OdbcCommand->ExecuteReader();
	}
	catch (Exception ^Ex) {}
}

#pragma endregion