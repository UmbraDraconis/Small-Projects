#include <iostream>
using namespace std;

int main() 
{
	double length1, length2, width1, width2;
	double area1 = length1 * width1, area2 = length2 * width2;
	
	cout << "Enter Length & Width of Rectangle #1:  ";
	cin >> length1 >> width1;
	cout << "Enter Length & Width of Rectangle #2:  ";
	cin >> length2 >> width2;
	
	if (area1 > area2)
		cout << "Rectangle #1 is greater than Rectangle #2." << endl;
	else if (area1 < area2)
		cout << "Rectangle #2 is greater than Rectangle #1." << endl;
	else if (area1 == area2)
		cout << "The two rectangles are equal in size." << endl;
		
	return 0;
}