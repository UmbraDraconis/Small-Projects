#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
	int gasChoice, counter = 0, time;
	double carbonDioxide = 258.0,
			air = 331.5,
			helium = 972.0,
			hydrogen = 1270.0;
	double distance;
	const int CARBON = 1,
			AIR = 2,
			HELIUM = 3,
			HYDROGEN = 4;
	
	do
	{
		cout << setw(12) << "Medium\t"
			<< setw(10) << "Speed(Meters per Second)\n";
		cout << setw(2) << "1.\t" << setw(12) << "Carbon Dioxide\t"
			<< setw(10) << "258.0\n"
			<< setw(2) << "2.\t" << setw(12) << "Air\t"
			<< setw(10) << "331.5\n"
			<< setw(2) << "3.\t" << setw(12) << "Helium\t"
			<< setw(10) << "972.0\n"
			<< setw(2) << "4.\t" << setw(12) << "Hydrogen\t"
			<< setw(10) << "1,270.0\n";
		
		if(counter > 0)
			cout << "Invalid Input.\n";
		cout << "Enter the number you selected for the gas: ";
		cin >> gasChoice;
		counter++;
		system("cls");
	} while (gasChoice == 0 || gasChoice > 4);
	
	counter = 0;
	
	do
	{
		if (counter > 0)
			cout << "Invalid time." << endl;
		cout << "Enter the number of seconds it took for the sound to travel (0-30): ";
		cin >> time;
		counter++;
		system("cls");
	} while (time < 0 || time > 30);
	
	switch (gasChoice)
	{
		case CARBON:
			cout << "Distance: " << time * carbonDioxide << endl;
			break;
		case AIR:
			cout << "Distance: " << time * air << endl;
			break;
		case HELIUM:
			cout << "Distance: " << time * helium << endl;
			break;
		case HYDROGEN:
			cout << "Distance: " << time * hydrogen << endl;
			break;
	}
	cout << "Press enter to terminate the program..." << endl;
	cin.get();
	return 0;
}
