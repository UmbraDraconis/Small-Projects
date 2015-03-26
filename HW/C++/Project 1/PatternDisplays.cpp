/*
** This program was designed by Simon Lam. This program creates a pattern of 
** asterisks.
*/
#include <iostream>
using namespace std;

int main()
{
	int input;
	bool inputValidity = false;
	
	cout << "\n\t\tSimon's Pattern Display\n\n";
	do{
		cout << "Enter the number of lines you want (1-20): ";
		cin >> input;
		if (input <= 20 && input > 0) inputValidity = true;
		else cout << "Invalid input.\n";
	} while (inputValidity != true);
	
	cout << "\nPattern A\n\n";
	for (int i = 1; i <= input; i++) //Pattern A
	{
		for (int j = 0; j < i; j++) 
		{
			cout << "*";
		}
		cout << endl;
	}
	cout << "\nPattern B\n\n";
	for (int i = input; i > 0; i--) //Pattern B
	{
        for (int j = 0; j < i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
	cout << "Press enter to exit the program.";
	cin.get();
	cin.ignore();
	return 0;
}
