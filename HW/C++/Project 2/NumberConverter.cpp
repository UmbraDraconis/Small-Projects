#include <iostream>
#include <stdlib.h>
using namespace std;

// Function Prototype
void displayConvertMenu();
void push(int *, int [], int, int);
int pop(int *, int [], int);
bool check_full(int * p), check_empty(int * p);

int main()
{
	const int SIZE = 100;
	const int BIN = 1,
			OCT = 2,
			HEX = 3;
    int array[SIZE];
	int * p;
	int quotient, option;
	
	p = array;
	
	cout << "Enter the number you wish to convert: " << endl;
	cin >> quotient;
	displayConvertMenu();
	cin >> option;
	switch(option)
	{
		case BIN:
			while(quotient != 0)
			{
				push(p, array, quotient % 2, SIZE);
				quotient /= 2;
			}
			system("pause");
			while(check_empty(p) != false)
				pop(p, array, SIZE);
			break;
		case OCT:
			while(quotient != 0)
			{
				push(p, array, quotient % 8, SIZE);
				quotient /= 8;
			}
			while(check_empty(p) != false)
				pop(p, array, SIZE);
			break;
		case HEX:
			while(quotient != 0)
			{
				int remainder = quotient % 16;
				char element;
				
				if(remainder == 10)
					element = 'A';
				else if(remainder == 11)
					element = 'B';
				else if(remainder == 12)
					element = 'C';
				else if(remainder == 13)
					element = 'D';
				else if(remainder == 14)
					element = 'E';
				else if(remainder == 15)
					element = 'F';
				else element = remainder;
				
				push(p, array, element, SIZE);
				quotient /= 16;
			}
			while(check_empty(p) != false)
				pop(p, array, SIZE);
			break;
		default:
			cout << "Invalid Input" << endl;
	}
	system("pause");
	return 0;
}

void push(int * p, int array[], int num, int size)
{
	if(check_full(p))
	{
		cout << "Array out of bounds. Good-Bye." << endl;
	} else
	{
		*p = num;
		p++;
	}
}

int pop(int * p, int array[], int size)
{
	int value;
	value = *p;
	p--;
	return value;
}

bool check_full(int * p)
{
	if(p == 99)
		return true;
	else return false;
}

bool check_empty(int * p)
{
	if(p == 0)
		return true;
	else return false;
}

void displayConvertMenu()
{
	cout << "----------------------------"
		<< "\nEnter your choice"
		<< "\n1. Binary Conversion"
		<< "\n2. Octal Conversion"
		<< "\n3. Hexadecimal Conversion"
		<< "\n----------------------------" << endl;
}
