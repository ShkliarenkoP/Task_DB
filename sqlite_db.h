#ifndef SQLITE_DB_H
#define SQLITE_DB_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "sqlite3.h"

#define NUM_OF_COLUMN            6


int checkStatus(sqlite3* check_db, std::string check_actn, int check_rc);
int genSQLiteDB(sqlite3* db, std::ifstream& csv_file);
int deleteRowSql(sqlite3* csv_db);

#endif SQLITE_DB_H
