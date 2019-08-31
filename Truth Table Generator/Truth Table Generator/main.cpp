#include <iostream>
#include <iomanip>
#include "parser.h"
#include <string>
using namespace std;

#define MAX_ROWS 8
#define MAX_COLS 10

///Initialize the table for all possible truth values of p, q, and r
///Give each symbol its own column, as we have done in class
///You can assign truth values manually or use nested loops.  I used a triple nested loop.
///returns the number of columns currently in the table (3)
bool evaluate(bool p, bool q, bool r, string statement);

int initTable(string symbols[], bool table[MAX_ROWS][MAX_COLS])
{
	symbols[0] = "p";
	symbols[1] = "q";
	symbols[2] = "r";

	//generates truth and false values for each symbol

	//controls the rows
	for (int i = 0; i < 3; i++) {
		//controls the columns 
		for (int j = 0; j < MAX_ROWS; j++) {

			//first row condition 
			if (i == 0) {
				if (j < 4) {
					table[j][i] = true;
				}
				else {
					table[j][i] = false;
				}
			}

			//first row condition 
			if (i == 1) {


				if ((j == 0 || j == 1) || (j == 4 || j == 5)) {
					table[j][i] = true;

				}
				else {
					table[j][i] = false;
				}


			}

			if (i == 2) {

				if (j % 2 == 0) {
					table[j][i] = true;
				}
				else {
					table[j][i] = false;
				}
			}
		}
	}

	return 3;
}

///output the contents of the table with number of columns equal to numProps
///the table should contain p, q, r, each hypothesis, and the conclusion in the last column
///I would recommend using cout << setw(symbols[j].size() + 2) to set the width of each column
void printTable(string symbols[], bool table[MAX_ROWS][MAX_COLS], int numProps)
{
	for (int i = 0; i < MAX_ROWS; i++) {
		for (int j = 0; j < numProps; j++) {
			if (table[i][j] == true) {
				cout << setw(symbols[j].size() + 2) << "T";
			}
			else {
				cout << setw(symbols[j].size() + 2) << "F";
			}
		}
		cout << endl;
	}
}

///Append a new column to the table.  Returns the new total number of columns.
///Assign the statement to the next column in symbols to act as a column header
///loop through each row and plug the current row's values for p, q, and r into evaluate
///Assign the return value from evaluate to the corresponding new cell in the table
int appendColumn(string statement, string symbols[], bool table[MAX_ROWS][MAX_COLS], int numProps)
{
	//increment the number of props so we can use it as an index
	//put statement inside symbols next available spots, depend on numProps to do this
	symbols[numProps] = statement;





	for (int i = 0; i < MAX_ROWS; i++) {
		//initiate 3 variables to keep track of the truth values on current row
		bool p = false, q = false, r = false;
		for (int j = 0; j < numProps; j++) {

			//set our conditions
			if (j == 0) {
				p = table[i][j];
			}
			if (j == 1) {
				q = table[i][j];
			}
			if (j == 2) {
				r = table[i][j];
			}


		}

		//check all of our values and return the answer
		table[i][numProps] = evaluate(p, q, r, statement);

	}
	cout << "num props test" << numProps << endl;

	//increment the number of props so we can update
	numProps++;


	return numProps;
}

///Determine if the argument represented by the truth table is valid or invalid
///As described in class, an argument is valid if when all the hypotheses are true, the conclusion is also true
///If there is a case where each hypothesis is true but the conclusion is false, the argument is invalid
///Use nested loops to examine each row.  If you find a row where all hypotheses are T and conclusion is F, return false
///If your code makes it through the loop without returning false, then return true
bool isValid(bool table[MAX_ROWS][MAX_COLS], int numProps)
{
	cout << table[0][0] << endl;
	return false;
}

///This one is done, no need to change it.
void printro()
{
	cout << "Welcome to the truth table generator" << endl;
	cout << "Valid symbols are p, q, and r" << endl;
	cout << "Valid operators are \\/, /\\, ~, =>, and <=>" << endl;
	cout << "Whitespace is ignored" << endl;
	cout << "Example:  (p \\/ q) => r" << endl;
}

///main is done, no changes needed.
int main()
{
	//defines a 2d array
	bool table[MAX_ROWS][MAX_COLS];

	//defines an array of the  allowed symbols
	string symbols[MAX_COLS];

	//generates a table
	int numProps = initTable(symbols, table);

	printro();

	//holds our statement
	string statement = "";

	cout << "Enter a hypothesis or type \"therefore\" when done: ";

	//allows us to store string in quick efficent way
	getline(cin, statement);

	//while we did not type therefore
	while (statement != "therefore")
	{
		cout << "this is the statement: " << statement << endl;
		//append another column 
		numProps = appendColumn(statement, symbols, table, numProps);

		//print out the table
		printTable(symbols, table, numProps);
		cout << "Enter a hypothesis or type \"therefore\" when done: ";
		getline(cin, statement);
	}

	cout << "Enter the conclusion: ";
	getline(cin, statement);
	numProps = appendColumn(statement, symbols, table, numProps);
	printTable(symbols, table, numProps);

	bool valid = isValid(table, numProps);
	if (valid) cout << "The argument IS valid" << endl;
	else cout << "The argument is NOT valid" << endl;

	return 0;
}