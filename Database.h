#pragma once
#include <iostream>

using namespace System;
using namespace MySql::Data;
using namespace System::Configuration;

ref class Database
{
public:
	Database(); // Instance required objects

	System::Data::ConnectionState GetConnectionState(); // Get the connection state (Open/Closed)
	void UpdateConnectionInfo(); // Build the connection string with props file
	bool Connect(); // Connect to the DB - Return IsWorked

	MySqlClient::MySqlDataReader^ ReadDatabase(String^ CommandLine); // Return DataReader with all tables of the DB
	System::Data::DataTable^ SendCommand(String^ CommandLine); // Send a specified command and return DataTable
	void UpdateTable(System::Data::DataTable^ DataTable, String^ CommandTable); // Make changes to the DB of the specified DataTable

	// ODBC connection type
	void ODBCConnect(); // Connect to the DB
	Data::Odbc::OdbcDataReader ^ OdbcSendCommand(String^ CommandLine); // Send a specified command and return DataReader 
	
private:
	// /NET
	String^ ConnectionInfo;
	MySqlClient::MySqlConnection^ Connection;
	MySqlClient::MySqlCommand^ Command;
	MySqlClient::MySqlDataAdapter^ DataAdaptator;
	MySqlClient::MySqlCommandBuilder^ CommandBuilder;
	System::Data::DataTable^ DataTable;

	// Odbc
	String^ OdbcConnectionInfo;
	Data::Odbc::OdbcConnection^ OdbcConnection;
	Data::Odbc::OdbcCommand^ OdbcCommand;
};