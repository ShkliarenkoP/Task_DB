#include "sqlite_db.h"

/*
In this function, we are going to check the efficiency of database operations


*/
int checkStatus(sqlite3* check_db, std::string check_actn, int check_rc)
{
	if(check_rc != SQLITE_OK)
	{
		std::cerr << "Faild to create SQLite " << check_actn << "\n\r" << sqlite3_errmsg(check_db) << std::endl;
		sqlite3_close(check_db);
		return 1;
	}
}

/*
This function is responsible for opening a database, creating a table in it, and moving data from a csv file to a table in the database
*/
int genSQLiteDB(sqlite3* csv_db, std::ifstream& csv_file)
{	

	int rc = sqlite3_open("DB_SQL.db", &csv_db);
	checkStatus(csv_db, "DATABASE", rc);
		
	const char* create_table = "CREATE TABLE IF NOT EXISTS DB_SQL_Table (column1 TEXT, column2 TEXT, column3 TEXT, column4 TEXT, column5 TEXT, column6 TEXT);";
	rc = sqlite3_exec(csv_db, create_table, nullptr, nullptr, nullptr);
	checkStatus(csv_db, "TABLE", rc);
	
	std::string line;
	std::string col[6];
	
	int num = 0;
	while(std::getline(csv_file, line))
	{
		std::istringstream subline(line);
		for(int count = 0; count < 6; count++)
		{
			std::getline(subline, col[count], ',');
		}
		std::string sql = sqlite3_mprintf("INSERT INTO DB_SQL_Table (column1, column2, column3, column4, column5, column6)" 
		                                  "VALUES ('%q', '%q', '%q', '%q', '%q', '%q');",
		                                  col[0].c_str(), col[1].c_str(), col[2].c_str(), col[3].c_str(), col[4].c_str(), col[5].c_str());
		
		
		rc = sqlite3_exec(csv_db, sql.c_str(), NULL, NULL, NULL);
		if(rc != SQLITE_OK)
		{
			std::cerr << "Faild to ADD DATA" << sqlite3_errmsg(csv_db) << std::endl;
			sqlite3_close(csv_db);
			return 1;
		}
	}
}

/*

In this function, we create a request to delete records in which the first character of the second column is a number


*/
int deleteRowSql(sqlite3* csv_db)
{
	int rc = sqlite3_open("DB_SQL.db", &csv_db);
	checkStatus(csv_db, "DATABASE", rc);
	
	const char* delete_row = "DELETE FROM DB_SQL_Table WHERE SUBSTR(column2, 1, 1) IN ('0', '1', '2', '3', '4', '5', '6', '7', '8', '9');";
	rc = sqlite3_exec(csv_db, delete_row, nullptr, nullptr, nullptr);
	checkStatus(csv_db, "DELETE ROW", rc);
}
