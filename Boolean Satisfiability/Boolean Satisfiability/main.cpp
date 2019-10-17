#include <iostream>
using namespace std;


const int MAX_ROW = 1024;
const int MAX_COLUMN = 10;


void displayColumn(bool row[MAX_COLUMN]) {
	for (int i = 0; i < MAX_COLUMN; i++) {
		cout << row[i] << " ";
	}
}

void initTable(bool table[MAX_ROW][MAX_COLUMN]) {

	//a sential variable to help us write truth values
	int limit = MAX_ROW;



	for (int i = 0; i < MAX_COLUMN; i++) {

		//automate the limit
		limit = limit / 2;

		//a count variable to keep track of when to write truth values
		int count = 0;
		for (int j = 0; j < MAX_ROW; j++) {

			if (count < limit) {
				table[j][i] = true;
			}
			else
			{
				table[j][i] = false;
			}

			//increment count
			count++;
		}
	}

}

bool isRowSat(bool row[10]) {

	//status variable to keep track of logic, assume that it is false first
	bool status = false;

	//a series of checks to see if the row is sat
	if (
		//A AND B
		((row[0] == 1 && row[2] == 0) || (row[0] == 0 && row[2] == 1)) &&
		((row[1] == 1 && row[3] == 0) || (row[1] == 0 && row[3] == 1)) &&

		//B AND E
		((row[2] == 1 && row[8] == 0) || (row[2] == 0 && row[8] == 1)) &&
		((row[3] == 1 && row[9] == 0) || (row[3] == 0 && row[9] == 1)) &&

		//D AND C
		((row[6] == 1 && row[4] == 0) || (row[6] == 0 && row[4] == 1)) &&
		((row[7] == 1 && row[5] == 0) || (row[7] == 0 && row[5] == 1)) &&

		//C AND E
		((row[4] == 1 && row[8] == 0) || (row[4] == 0 && row[8] == 1)) &&
		((row[5] == 1 && row[9] == 0) || (row[5] == 0 && row[9] == 1))
		)
	{
		status = true;
	}

	return status;
}

int main() {

	//2d array 
	bool table[MAX_ROW][MAX_COLUMN];

	//initalize the table with truth values
	initTable(table);


	return 0;
}