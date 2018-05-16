#include <iostream>
using namespace std;

// function prototypes
void SeatTheStudents(int*, int, int, int);

int main()
{
	//variables
    int seats;
    int students;   
    int SeatedStudents = 0;
    
    //get user input
    cout << "Enter amount of seats: \n" << endl;
    cin >> seats;
    cout << "\nEnter amount of students: \n" << endl;
    cin >> students;
    
    //make the row of seats in array form
    int row[seats] = {0}; 
   
   //call the function to perform the seating
    SeatTheStudents(row, seats, students, SeatedStudents);
    
    return 0;
}

void SeatTheStudents(int *RowStudents, int NumberOfSeats, int NumberOfStudents, int SeatedStudents)
{
	//initialize the variables needed for the function
	//EndOfArray is the index of the last seat of the row
	int EndOfArray = NumberOfSeats - 1;
	//StartingIndex will be the index of the beginning of the longest segment of unseated chairs
	int StartingIndex = 0;
	//NewStartingIndex is a temporary version of StartingIndex, used to hold potential new values of StartingIndex
	int NewStartingIndex = 0;
	//Counter stores the length of the current longest row of unseated chairs
	int Counter = 0;
	//NewCounter is a temporary version of Counter, used to hold potential new values of Counter
	//Increments each time the While loop lands on a zero, resets after each For loop
	int NewCounter = 0;
	//Midpoint is the calculated index of halfway through the unseated segment of chairs --- it is right side dominant
	int Midpoint = 0;
	//Print the unseated row of chairs as 0s in an array
	if(!(SeatedStudents > 0))
	{
		cout << "\nThe array before seating is: \n" << endl;
		for(int i = 0; i < NumberOfSeats; i++)
		{
    		cout << RowStudents[i];
		}
	}
	
	//If theres 2+ students to be seated, this greedy code places the first 2 students at the beginning and end of the row
	if((RowStudents[0] != 1 || RowStudents[EndOfArray] != 1) && NumberOfStudents > 1)
	{
		if(RowStudents[0] != 1) {RowStudents[0] = 1; SeatedStudents++;}
		if(RowStudents[EndOfArray] != 1) {RowStudents[EndOfArray] = 1; SeatedStudents++;}
	}
	
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
	//calculate midpoint
	Midpoint = (StartingIndex + (Counter / 2));
	
	//check to see that we haven't seated too many students, then seat the next student
	if(SeatedStudents < NumberOfStudents) {RowStudents[Midpoint] = 1;}
	//increment amount of students seated
	SeatedStudents++;
	//checks if we're finished, and prints the new row when confirmed
	if(SeatedStudents >= NumberOfStudents)
	{
		cout << endl << "\nThe array after seating is: \n" << endl;
   		for(int i = 0; i < NumberOfSeats; i++)
   	{
		cout << RowStudents[i];
	}
	return;
	}
	//recursive call of the function, calls itself when we have not seated all of the students.
	if(SeatedStudents < NumberOfStudents)
	{
		SeatTheStudents(RowStudents, NumberOfSeats, NumberOfStudents, SeatedStudents);
	}
}
