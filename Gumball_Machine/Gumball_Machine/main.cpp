#include <iostream>
using namespace std;

//all of these enums are indexed like an array

enum Q
{
	q0,
	q5,
	q10,
	q15,
	q20
};
enum O
{
	GUMBALL,
	RETURN,
	MESSAGE,
	NONE,
	INVALID
};
enum I
{
	NICKEL,
	DIME,
	BUY,
	QUIT
};

const string Q_STRINGS[] = {"q0", "q5", "q10", "q15", "q20"};
const string O_STRINGS[] = {"Gumball dispensed.  Have a nice day.\n",
							"Exact change required.  Returning coin.\n",
							"Insufficient funds.  Cannot buy.\n",
							"",
							"Invalid input.\n"};
const string I_STRINGS[] = {"NICKEL", "DIME", "BUY", "QUIT"};

const string PROMPT_STRING = "NICKEL, DIME, BUY, or QUIT: ";

int main()
{
	//an enum that will hold the current state
	//this is our state variable that we need to update
	Q q = q0;

	//holds current user input
	string input = "";

	//what we output to the screen based off the user choice
	string output = "";

	cout << PROMPT_STRING;
	cin >> input;

	while (input != I_STRINGS[QUIT])
	{

		if (input == I_STRINGS[BUY])
		{

			//check to see if the current state is at q20
			if (q == q20)
			{

				//reset the q to inital state
				q = q0;

				//set message variable
				output = O_STRINGS[GUMBALL];
			}
			else
			{

				//set the message variable to insufficient funds if they are not at that state
				output = O_STRINGS[MESSAGE];
			}
		}

		///assign output and q based on current state and input
		else if (input == I_STRINGS[NICKEL])
		{

			//reset the output
			output = O_STRINGS[NONE];

			//a series of checks for nickel based decisions
			//we will update state accordingly
			if (q == q5)
			{
				q = q10;
			}
			else if (q == q10)
			{
				q = q15;
			}
			else if (q == q15)
			{
				q = q20;
			}
			else if (q == q20)
			{
				output = O_STRINGS[RETURN];
			}
			else
			{
				q = q5;
			}
		}

		else if (input == I_STRINGS[DIME])
		{
			//reset the output
			output = O_STRINGS[NONE];

			if (q == q5)
			{
				q = q15;
			}
			else if (q == q10)
			{
				q = q20;
			}
			else if (q == q15 || q == q20)
			{
				output = O_STRINGS[RETURN];
			}
			else
			{
				q = q10;
			}
		}
		else
		{
			output = O_STRINGS[INVALID];
		}

		cout << output << endl;
		cout << "Current state: " << Q_STRINGS[q] << endl;
		cout << PROMPT_STRING;
		cin >> input;
	}

	return 0;
}
