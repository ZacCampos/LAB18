/*******************************************************************************
 * AUTHORS		: Zac Campos & Justin Blanco
 * STUDENT ID	: 1058476
 * LAB #18		: Repetition - Aunt Ellen's Egg Ranch
 * CLASS		: CS1A
 * SECTION		: MW 8am
 * DUE DATE		: 3/28/18
 ******************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/*******************************************************************************
 * Repetition - Aunt Ellen's Egg ranch
 * -----------------------------------------------------------------------------
 * This program will output the number of dozens and the number of
 * excess eggs.
 * -----------------------------------------------------------------------------
 * INPUT:
 * 		eggs 		: The number of eggs gathered.
 *
 * OUTPUT:
 * 		dozen		: The number of batches collected.
 * 		eggsLeft	: The remaining eggs that don't make up a dozen.
 * 		averageEggs : The average number of eggs gathered.
 ******************************************************************************/


int main()
{
	/***************************************************************************
	 * CONSTANTS
	 * -------------------------------------------------------------------------
	 * OUTPUT - USED FOR CLASS HEADING
	 * -------------------------------------------------------------------------
	 * PROGRAMMERS	: Programmers' Names
	 * CLASS		: Students' Course
	 * SECTION		: Class Days and Times
	 * LAB_NUM		: Lab Number (specific to this lab)
	 * LAB_NAME		: Title of the Lab
	 * ------------------------------------------------------------------------
	 * INPUT - used for number of test runs
	 * ------------------------------------------------------------------------
	 * NUM_TESTS    : number of test runs to perform
	 * ------------------------------------------------------------------------
	 * OUTPUT - used to properly indent output
	 * ------------------------------------------------------------------------
	 * TAB_COL      : tab column size
	 **************************************************************************/
	//OUTPUT - used for class heading
	const char PROGRAMMER[] = "Zac Campos & Justin Blanco";
	const char CLASS[]		= "CS1A";
	const char SECTION[]	= "MW: 8am";
	const int  LAB_NUM		= 18;
	const char LAB_NAME[]	= "Repetition - Aunt Ellen's Egg Ranch";
	//INPUT - used for number of test runs
	const int NUM_TESTS     = 3;
	//OUTPUT - used to properly indent output
	const int TAB_COL = 4;

	// variable declarations go here
	int 	eggs;			//IN & CALC  - Number of eggs gathered.
	int 	dozen;			//CALC & OUT - Total of dozens.
	int 	eggsLeft;		//CALC & OUT - Remaining eggs.
	int 	totalEggs;	    //CALC		 - Used for finding the average.
	int		runCount;       //CALC       - Used to find the average.
	float	averageEggs;	//CALC & OUT - Average eggs gathered.
	int     testCount;      //OUT        - Used to keep track of current test.

	// OUTPUT - Class Heading
	cout << left;
	cout << "***************************************************\n";
	cout << "*  PROGRAMMED BY : "	<< PROGRAMMER 	<< endl;
	cout << "*  "		<< setw(14) << "CLASS"		<< ": " << CLASS	<< endl;
	cout << "*  "		<< setw(14)	<< "SECTION"	<< ": " << SECTION  << endl;
	cout << "*  LAB #"	<< setw(9)	<< LAB_NUM		<< ": "	<< LAB_NAME	<< endl;
	cout << "***************************************************\n\n";
	cout << right;

	//for loop to run the program a specified number of times
	for(testCount = 1; testCount <= NUM_TESTS; testCount = testCount + 1)
	{
		/**********************************************************************
		 * INPUT - Uses a while loop to read in number of eggs gathered until
		 *         user inputs a negative number to exit the program. Will also
		 *         calculate and output the dozens of eggs and excess eggs
		 *         based on inputed number of eggs gathered.
		 *         (eggs, dozen, eggsLeft)
		 **********************************************************************/
		//set accumulators to zero before test run
		runCount  = 0;
		totalEggs = 0;

		//output - test # and welcome message
		cout << "TEST #" << testCount << endl;
		cout << "Welcome to Aunt Ellen's eggs to dozens converter!\n\n";

		//reads first input
		cout << setw(TAB_COL) << " " << "Enter the number of eggs gathered: ";
		cin  >> eggs;
		cin.ignore(1000, '\n');

		//reads in number of eggs gathered until user inputs a negative number
		while(eggs > -1)
		{
			//calculate dozens and remaining eggs and new total
			dozen     = eggs / 12;
			eggsLeft  = eggs % 12;
			totalEggs = totalEggs + eggs;
			runCount  = runCount + 1;

			cout << setw(TAB_COL) << " " << "You have ";
			if(dozen > 0)
			{
				cout << dozen << " dozen ";
			}
			cout << eggsLeft << " eggs.\n\n";

			cout << setw(TAB_COL) << " "
				 << "Enter the number of eggs gathered: ";
			cin  >> eggs;
			cin.ignore(1000, '\n');
		}
		/**********************************************************************
		 * PROCESSING - calculates the total of dozens and the number of
		 * 				eggs left
		 * 				(dozen, eggsLeft)
		 **********************************************************************/
		dozen    	= totalEggs / 12;
		eggsLeft    = totalEggs % 12;
		averageEggs = totalEggs / float(runCount);
		/**********************************************************************
		 * OUTPUT - outputs the the total dozens and the number of eggs left
		 **********************************************************************/
		if(totalEggs > 0)
		{
			cout << fixed << setprecision(1);
			cout << "\nTOTALS:\n";
			cout << setw(TAB_COL) << " " << "On average " << averageEggs
				 << " eggs have been gathered.\n";
			cout << setw(TAB_COL) << " " << "A total of " << dozen << " and "
				 << eggsLeft << " eggs have been gathered!\n\n" << endl;
		}
	}
		return 0;
}
