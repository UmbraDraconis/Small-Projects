#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;

// Function prototypes
static void displayMenu();

class Polynomial {
	private:
		int size;
		int *coefficient;
		bool checkSize();
		void toArray(string);
		void displayPolynomial();
	public:
		Polynomial ();
		Polynomial (int, string);
		Polynomial (const Polynomial &);
		~Polynomial ();
		void getPolynomial()
			{return displayPolynomial();}
		Polynomial operator + (const Polynomial&) const;
		Polynomial operator - (const Polynomial&) const;
		Polynomial operator = (const Polynomial&) const;
		Polynomial operator * (const Polynomial&) const;
};

int main(){
	int size,option;
	const int ADD = 1,
			SUB = 2,
			ASSIGN = 4,
			MULT = 3,
			EXIT = 5;
	string poly;
	cout << "Please enter the number of terms in the first polynomial." << endl;
	cin >> size;
	cout << "Please enter the polynomial itself." << endl;
	cin.ignore();
	cin >> poly;
	Polynomial poly1(size, poly);
	cout << "Please enter the number of terms in the second polynomial." << endl;
	cin.ignore();
	cin >> size;
	cout << "Enter the polynomial itself." << endl;
	cin.ignore();
	cin >> poly;
	Polynomial poly2(size,poly);
	do {
        Polynomial temp;
		system("cls");
		displayMenu();
		switch(option) {
			case ADD:
				temp = poly1 + poly2;
				break;
			case SUB:
				temp = poly2 - poly1;
				break;
			case ASSIGN:
				poly1 = poly2;
				break;
			case MULT:
				temp = poly1 * poly2;
				break;
			case EXIT:
				cout << "Bye~!" << endl;
				exit(0);
				break;
			default:
				cout << "Invalid option." << endl;
				system("pause");
		}
	} while (option != EXIT);
	return 0;
}

static void displayMenu(){
	cout << "\n(1) Addition\n"
		<< "\n(2) Subtraction\n"
		<< "\n(3) Multiplication\n"
		<< "\n(4) Assignment\n"
		<< "\n(5) Exit" << endl;
}

Polynomial::Polynomial() {
	size = 50;
	coefficient = new int[size];
}
Polynomial::Polynomial(int s, string poly) {
	size = s;
    if(!checkSize()) {
        cout << "Invalid size." << endl;
        exit(0);
    }
    coefficient = new int[size];
    toArray(poly);
}
Polynomial::Polynomial(const Polynomial &obj) {
	coefficient = new int;
	*coefficient = *obj.coefficient;
}
Polynomial::~Polynomial() {
	cout << "Emptying memory" << endl;
	delete [] coefficient;
}

bool Polynomial::checkSize() {
	if(size <= 0) {
		cout << "Invalid size" << endl;
		return false;
	}
	return true;
}
void Polynomial::toArray(string poly) {
	bool negative = false, coef = true;
	int coefA[10], indA[10], j = 0;
	for(int i = 0; i < poly.length(); i++) {
		if(poly[i] == '-')
			negative = true;
		else if(isdigit(poly[i]) && coef) {
			if(negative) {
				coefA[j] = poly[i] - '0';
				coefA[j] = -coefA[j];
			}
			else
				coefA[j] = poly[i] - '0';
			coef = false;
		} else if (isdigit(poly[i]) && coef == false) {
			indA[j] = poly[i];
			coef = true;
			j++;
		}
	}
	for(int i = 0; i < size; i++) {
		for(j = 0; j < size; i++) {
			if(indA[j] == i)
				*(coefficient + i) = coefA[j];
		}
	}
}
void Polynomial::displayPolynomial(){
    for(int i = 0; i < size; i++)
		cout << coefficient[i] << "x^" << i << " + ";
}
Polynomial Polynomial::operator + (const Polynomial &poly) const {
	Polynomial temp;
	for(int i = 0; i < size; i++)
		temp.coefficient[i] = coefficient[i] + poly.coefficient[i];
	return temp;
}
Polynomial Polynomial::operator - (const Polynomial &poly) const {
	Polynomial temp;
	for(int i = 0; i < size; i++)
		temp.coefficient[i] = coefficient[i] - poly.coefficient[i];
	return temp;
}
Polynomial Polynomial::operator = (const Polynomial &poly) const {
	Polynomial temp;
	for(int i = 0; i < size; i++)
		temp.coefficient[i] = poly.coefficient[i];
	return temp;
}
Polynomial Polynomial::operator * (const Polynomial &poly) const {
	Polynomial temp;
	for(int i = 0; i < size; i++)
		temp.coefficient[i] = coefficient[i] * poly.coefficient[i];
	return temp;
}
