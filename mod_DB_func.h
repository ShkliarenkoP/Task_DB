#ifndef MOD_DB_FUNC_H
#define MOD_DB_FUNC_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include "sqlite3.h"


//using namespace std;

#define MAX_CHAR_IN_LINE          48
#define MAX_LINE                  1024
#define NUM_OF_CHAR	           36
#define ASCII_START_DIG           48 
#define ASCII_START_LET           97 
#define RANGE_OF_NUM              10
#define NUM_OF_VOWELS             6
#define NUM_OF_COL                6


void generationDB(std::ofstream& File_csv);
char generationSymbol(void);

void changeOddNum(std::ofstream& Change_file, std::ifstream& Read_file);
void removeLine(std::ofstream& Change_file, std::ifstream& Read_file);


#endif MOD_DB_FUNC_H
