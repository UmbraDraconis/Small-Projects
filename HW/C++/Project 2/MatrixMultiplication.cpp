#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Global Variables
int row1, row2, col1, col2;

// Function prototypes
void addition(int **matrix1, int **matrix2);
void multiplication(int **matrix1, int **matrix2);
void subtraction(int **matrix1, int **matrix2);
void transpose1(int **matrix1), transpose2(int **matrix2);
void displayInputMenu(), displayArithmeticMenu(), displayTransposeMenu();
void displayMatrice(int **matrix1, int **matrix2);
void displayMatrix(int **matrix);

int main()
{
    int choice, option, option2;
    int **matrix1, **matrix2;
	const int ADD = 1,
			MINUS = 2,
			MULTIPLY = 3,
			TRANSPOSE = 4,
			EXIT = 5,
			TMATRIX1 = 1,
			TMATRIX2 = 2;
    
    displayInputMenu();
    cin >> choice;
    if(choice == 1)
    {
        cout << "Enter the number of rows and columns"
            << " of the first matrix respectively: " << endl;
        cin >> row1 >> col1;
        matrix1 = new int*[row1];
        for(int i = 0; i < row1; i++)
        {
			cout << "Please enter the value for each cell: ";
            matrix1[i] = new int[col1];
            for(int j = 0; j < col1; j++)
				cin >> matrix1[i][j];
            system("cls");
        }
        cout << "Enter the number of rows and columns of the "
             << "second matrix respectively: " << endl;
        cin >> row2 >> col2;
        matrix2 = new int*[row2];
        for(int i = 0; i < row2; i++)
        {
			cout << "Please enter the value for each cell: ";
			matrix2[i] = new int[col2];
			for(int j = 0; j < col2; j++)
				cin >> matrix2[i][j];
			system("cls");
        }
    } else
    {
		ifstream infile;
		string fileName;
		cout << "Please enter the name of the file: " << endl;
		cin >> fileName;
		infile.open(fileName.c_str());
		infile >> row1;
		infile >> col1;
		matrix1 = new int*[row1];
		for(int i = 0; i < row1; i++)
		{
			matrix1[i] = new int[col1];
			for(int j = 0; j < col1; j++)
				infile >> matrix1[i][j];
		}
		infile >> row2;
		infile >> col2;
		matrix2 = new int*[row2];
		for(int i = 0; i < row2; i++)
		{
			matrix2[i] = new int[col2];
			for(int j = 0; j < col2; j++)
				infile >> matrix2[i][j];
		}
		infile.close();
    }
	do
	{
		system("cls");
		cout << "Please input your choice: " << endl;
		displayArithmeticMenu();
		cin >> option;
		switch(option)
		{
			case ADD:
				addition(matrix1, matrix2);
				break;
			case MINUS:
				subtraction(matrix1, matrix2);
				break;
			case MULTIPLY:
				multiplication(matrix1, matrix2);
				break;
			case TRANSPOSE:
				displayTransposeMenu();
				cin >> option2;
				switch (option2)
				{
					case TMATRIX1:
						transpose1(matrix1);
						break;
					case TMATRIX2:
						transpose2(matrix2);
						break;
					default:
						cout << "Invalid Input." << endl;
				}
				break;
			case EXIT:
				break;
			default:
				cout << "Invalid Input." << endl;
		}
		system("pause");
	} while(option != EXIT);
    return 0;
}

void addition(int **matrix1, int **matrix2)
{
	system("cls");
	int **matrix3;
	if(row1 != row2 || col1 != col2)
		cout << "The matrices are not equal in size." << endl;
	else
	{
		matrix3 = new int*[row1];
		for(int i = 0; i < row1; i++)
		{
			matrix3[i] = new int[col1];
			for(int j = 0; j < col1; j++)
				matrix3[i][j] = matrix1[i][j] + matrix2[i][j];
		}
		displayMatrix(matrix3);
	}
	
}

void multiplication(int **matrix1, int **matrix2)
{
	system("cls");
	int **matrix3;
	if(col1 != row2)
		cout << "The matrices are not the right size." << endl;
	else
	{
		matrix3 = new int*[row1];
		for(int i = 0; i < row1; i++)
		{
			matrix3[i] = new int[col2];
			for(int j = 0; j < col2; j++)
			{
				int sum = 0;
				for(int k = 0; k < row2; k++)
					sum += matrix1[i][k] * matrix2[k][j];
				matrix3[i][j] = sum;
			}
		}
		displayMatrix(matrix3);
	}
}

void subtraction(int **matrix1, int **matrix2)
{
	system("cls");
	int **matrix3;
	if(row1 != row2 || col1 != col2)
		cout << "The matrices are not equal in size." << endl;
	else
	{
		matrix3 = new int*[row1];
		for(int i = 0; i < row1; i++)
		{
			matrix3[i] = new int[col1];
			for(int j = 0; j < col1; j++)
				matrix3[i][j] = matrix1[i][j] - matrix2[i][j];
		}
		displayMatrix(matrix3);
	}
}

void transpose1(int **matrix1)
{
	system("cls");
	int **matrix3;
	matrix3 = new int*[col1];
	for(int i = 0; i < col1; i++)
	{
		matrix3[i] = new int[row1];
		for(int j = 0; j < row1; j++)
			matrix3[i][j] = matrix1[j][i];
	}
	for(int i = 0; i < col1; i++)
	{
		for(int j = 0; j < row1; j++)
			cout << matrix3[i][j] << " ";
		cout << endl;
	}
}

void transpose2(int **matrix2)
{
	system("cls");
	int **matrix3;
	matrix3 = new int*[col2];
	for(int i = 0; i < col2; i++)
	{
		matrix3[i] = new int[row2];
		for(int j = 0; j < row2; j++)
			matrix3[i][j] = matrix2[j][i];
	}
	for(int i = 0; i < col2; i++)
	{
		for(int j = 0; j < row2; j++)
			cout << matrix3[i][j] << " ";
		cout << endl;
	}
}

void displayMatrix(int **matrix)
{
	system("cls");
	for(int i = 0; i < row1; i++)
	{
		for(int j = 0; j < col2; j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
}

void displayMatrice(int **matrix1, int **matrix2)
{
	system("cls");
    for(int i = 0; i < row1; i++)
	{
		for(int j = 0; j < col1; j++)
			cout << matrix1[i][j] << " ";
		cout << endl;
	}
    for(int i = 0; i < row2; i++)
    {
		for(int j = 0; j < col2; j++)
			cout << matrix2[i][j] << " ";
		cout << endl;
	}
}

void displayInputMenu()
{
    cout << "--------------------------"
         << "\nPlease choose input choice"
         << "\n1. User Input"
         << "\n2. File Input"
         << "\n--------------------------" << endl;
}

void displayArithmeticMenu()
{
	system("cls");
    cout << "----------------------------"
         << "\nChoose Mathematical Operation"
         << "\n1. Addition"
         << "\n2. Subtraction"
         << "\n3. Multiplication"
         << "\n4. Transpose"
		 << "\n5. Exit"
         << "\n----------------------------" << endl;
}

void displayTransposeMenu()
{
	system("cls");
	cout << "------------------------------"
		<< "\nChoose Transpose Matrix"
		<< "\n1. Matrix #1"
		<< "\n2. Matrix #2"
		<< "\n------------------------------" << endl;
}
