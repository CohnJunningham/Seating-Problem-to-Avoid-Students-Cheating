#include <iostream>
#include <string>
using namespace std;

// function prototypes
int getSeats();
int getStudents(int);
void printRow(int*, int, int);
void SeatTheStudents(int*, int, int, int);

int main()
{

	//boolean variables to repeat functions
    bool repeat = true;
    
    while (repeat)
    {
    	
    	//declare variables for main function
    	int seats = getSeats();
    	int students = getStudents(seats);
    	int SeatedStudents;
    	
    	int row[seats] = {0};
   
   		//call the function to perform the seating
    	SeatTheStudents(row, seats, students, SeatedStudents);
    
    	//print the row
    	printRow(row, seats, SeatedStudents);
    	cout << "\n--------------------------------------------------\n\n";
    }
    
	return 0;
	}

//get user input
int getSeats()
{
	
	//declare needed input variable
	int seats;
	
    cout << "Enter amount of seats: ";
    cin >> seats;
	
	return seats;
}

int getStudents(int NumberOfSeats)
{
	
	//declare needed input variable
	int students;
	
	cout << "\nEnter amount of students: ";
    cin >> students;
    
    if(students > NumberOfSeats)
    {
    	cout << "\nToo many students.\n";
    	getStudents(NumberOfSeats);
	}
    else return students;
}

void printRow(int *RowStudents, int seats, int SeatedStudents)
{
	
	cout << "\nThe proposed seating arrangement will look like:\n\n";
	
	//loop through the array indexes and print their value
	for(int a = 0; a < seats; a++)
	{
		cout << RowStudents[a];
	}
	
	cout << "\n";
}

void SeatTheStudents(int *RowStudents, int NumberOfSeats, int NumberOfStudents, int SeatedStudents)
{
	
	//EndOfArray is the index of the last seat of the row
	int EndOfArray = NumberOfSeats - 1;
	
	//If theres 2+ students to be seated, this greedy code places the first 2 students at the beginning and end of the row
	if((RowStudents[0] != 1 || RowStudents[EndOfArray] != 1) && NumberOfStudents > 1)
	{
		if(RowStudents[0] != 1) {RowStudents[0] = 1; SeatedStudents++;}
		if(RowStudents[EndOfArray] != 1) {RowStudents[EndOfArray] = 1; SeatedStudents++;}
	}
	
	while(SeatedStudents < NumberOfStudents)
	{
		
		//initialize the variables needed for the function
		//StartingIndex will be the index of the beginning of the longest segment of unseated chairs
		int StartingIndex = 0;
		//NewStartingIndex is a temporary version of StartingIndex, used to hold potential new values of StartingIndex
		int NewStartingIndex = 0;
		//Counter stores the length of the current longest row of unseated chairs
		int Counter = 0;
		//NewCounter is a temporary version of Counter, used to hold potential new values of Counter
		//Increments each time the While loop lands on a zero, resets after each For loop
		int NewCounter = 0;
		
		/*this for loop iterates through each index, if the array's value at the index is 0, the inside while
		loop iterates through the following indexes counting how many consecutive 0s there are*/
		for(int i = 0; i < NumberOfSeats; i++)
		{
			//reset the function
			NewCounter = 0;
			NewStartingIndex = i;
		
			//checks to make sure the seat is empty
			while(RowStudents[i] != 1)
			{
				NewCounter++;
			
				/*if the counter of the current While loop is bigger than the current For loop counter, replace
				the old one with the new one*/
				if(NewCounter >= Counter)
				{
					StartingIndex = NewStartingIndex;
					Counter = NewCounter;
				}
				i++;
			}
		}
	
		////Midpoint is the calculated index of halfway through the unseated segment of chairs --- it is right side dominant
		int Midpoint = (StartingIndex + (Counter / 2));
		
		//Seat a student
		RowStudents[Midpoint] = 1;
		SeatedStudents++;
	}
	
	//return to main
	return;
}
