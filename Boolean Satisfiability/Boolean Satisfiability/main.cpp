#include <iostream>
using namespace std;

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



	bool arrayTest[10] = {1, 0, 0, 1, 0, 1, 1, 0, 1, 0};


	bool result = isRowSat(arrayTest);

	cout << "result: " << result << endl;
	return 0;
}