#include "mod_DB_func.h"
#include "sqlite_db.h"


using namespace std;

int main()
{
	srand(time(NULL));
	
	ofstream Database_g("Database.csv");                           //Create the file for recording
	if(!Database_g)                                                //Сheck whether the file has been opened
	{
		cerr << "Faild open file \"DataBase.csv\"" << endl;
		exit(1);
	}
	
	generationDB(Database_g);                                      //Generate a csv file with 1024 lines, 6 columns of 8 characters each
	Database_g.close();                                            //Сlose the file
	
	ofstream Change_DB("Change_Database.csv");                     //Сreate a new csv file for the modified values
	ifstream Read_DB("Database.csv");                              //Оpen the generated csv file to modify the values ​​and 
	                                                               //record them in the newly created file
	
	changeOddNum(Change_DB, Read_DB);				 //Change odd numbers to "#"
	removeLine(Change_DB, Read_DB);                                //Вelete the row in which each column begins with a vowel
	
	Change_DB.close();                                             //Сlose the new file
	Read_DB.close();                                               //Сlose the old file
	
/*##############################################################################################*/

	ifstream Read_csv("Database.csv");				  //Оpen the first generated csv file
	if(!Read_csv.is_open())                                         //Сheck whether the file has been opened
	{
		std::cerr << "Faild to open \"Change_Database.csv\"" << std::endl;
		return 1;
	}	
	
	sqlite3* DataBs;                                                //Create an sqlite database
	
	genSQLiteDB(DataBs, Read_csv);                                  //Еransfer the data from the first csv file to the database

	
	sqlite3_close(DataBs);                                          //Сlose the database
	Read_csv.close();                                               //Close the csv file
	
	sqlite3* ChangeDB;                                              //Оpen the database
	deleteRowSql(ChangeDB);                                         //Вelete lines in which 
	                                                                //the first character in the second column is a number

	sqlite3_close(ChangeDB);                                        //Close the database
	return 0;
}


			

