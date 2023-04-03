#include "mod_DB_func.h"

using namespace std;


/*
In this function generate symbols for a csv file. 
This happens as follows: the first cycle generates a line of 48 characters (since there are 6 stacks, each of which has 8 characters)
a comma is added every eight characters, according to the csv file specification
*/
void generationDB(std::ofstream& File_csv)
{
	for(int line_count = 0; line_count < MAX_LINE; line_count++)
	{
		for(int colum_count = 1; colum_count <= MAX_CHAR_IN_LINE; colum_count++)
		{
			File_csv << generationSymbol();
			
			if((colum_count % 8 == 0) && (colum_count != 48))
			{
				File_csv << ",";
			}
		}
		
		File_csv << endl;
	}
}


/*
In this function generate characters 0-9 and a-z. We use a total of 36 characters, which are selected from the ASCII table.
Each character has its own numerical value, first we select the position of our character using the rand() function 
and then add the initial value in the ASCII table
*/
char generationSymbol(void)
{	
	int value = rand() % NUM_OF_CHAR;
	
	if(value < RANGE_OF_NUM)
	{
		return static_cast<char>(value + ASCII_START_DIG);
	}
	else
	{
		return static_cast<char>(value + ASCII_START_LET - RANGE_OF_NUM);
	}
}


/*
In this function change odd numbers to "#". We read the line from the csv file to the mailbox, 
then search for the number, check it for oddness, and replace it with the symbol #
*/
void changeOddNum(std::ofstream& Change_file, std::ifstream& Read_file)
{
	while(Read_file)
	{
		string parse_line;
		getline(Read_file, parse_line);
		
		int symbol_count = 0;
		while(parse_line[symbol_count] != '\0')
		{
			if(isdigit(parse_line[symbol_count]))
			{
				if(stoi(parse_line.substr(symbol_count, 1)) % 2 == 1)
				{
					parse_line[symbol_count] = '#';
				}
				
			}
			
			symbol_count++;
		}
	
		Change_file << parse_line << endl;
	}
}


/*
This function deletes the record in which the first character of each column begins with a vowel. To do this, an array was created in which all vowels are listed, after which the line is read and a comma character is searched for, as soon as a comma is found, the next character after it will be compared with all the values ​​of the array

(But first the null element of the string will be checked in a separate loop, if it is not a vowel character, then the next string is checked)
*/
void removeLine(std::ofstream& Change_file, std::ifstream& Read_file)
{
	char symbol[NUM_OF_VOWELS] = {'a', 'e', 'i', 'o', 'u', 'y'};
	
	while(Read_file)
	{
		string read_line;
		getline(Read_file, read_line);
		
		int symbol_count = 0;
		int vowels = 0;
		while(read_line[symbol_count] != '\0')
		{
			for(int count1 = 0; count1 < NUM_OF_VOWELS; count1++)
			{
				if(read_line[symbol_count] == symbol[count1] && symbol_count < 1)
				{
					vowels++;
				}
			}
			
			if(first_vowels < 1)
			{
				break;
			}
				
			
			if(read_line[symbol_count] == ',')
			{
				for(int count2 = 0; count2 < NUM_OF_VOWELS); count2++)
				{
					if(read_line[symbol_count+1] == symbol[count2])
					{
						vowels++;
					}
				}
			}
			
			symbol_count++;
		}
		
		if(vowels == NUM_OF_COL)
		{
			read_line.clear();
		}
	
		Change_file << read_line << endl;
	}
}
