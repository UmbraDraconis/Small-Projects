/*
** This program was designed by Simon Lam of Cal Poly Pomona. This is a practice
** problem from the book to implement a small program to tutor people in math.
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

int main()
{
	srand(time(NULL));
	
	char ch;
	double value1, value2, answer, input, option;
	const int ADD_OPTION = 1,
	          SUB_OPTION = 2,
              MULT_OPTION = 3,
              DIV_OPTION = 4,
              QUIT_OPTION = 5;
              
	do
    {
         cout << "\n\t\tSimon's Math Question Menu\n\n";
         cout << "1. Addition Problem\n"
              << "2. Subtraction Problem\n"
              << "3. Multiplication Problem\n"
              << "4. Division Problem\n"
              << "5. Exit Program\n"
              << "Please enter your choice: ";
         cin >> option;
         
         value1 = rand() % 12;
         value2 = rand() % 12;
         switch(static_cast<int>(option))
         {
             case ADD_OPTION:
                  answer = value1 + value2;
                  
                  cout << setw(6) << value1 << endl;
          	      cout << "+ " << setw(4) << value2 << endl;
            	  cout << setw(6) << "-------\n";
            	  cin >> input;
            	  
                  if ( input == answer)
                     cout << "Congratulations! You got the right answer!" << endl;
                  else
                     cout << "Sorry, you got the wrong answer. The answer is:  " << answer << endl;
                  break;
             case SUB_OPTION:
                  answer = value1 - value2;
                  
                  cout << setw(6) << value1 << endl;
          	      cout << "- " << setw(4) << value2 << endl;
            	  cout << setw(6) << "-------\n";
            	  cin >> input;
            	  
                  if ( input == answer)
                     cout << "Congratulations! You got the right answer!" << endl;
                  else
                     cout << "Sorry, you got the wrong answer. The answer is:  " << answer << endl;
                  break;
             case MULT_OPTION:
                  answer = value1 * value2;
                  
                  cout << setw(6) << value1 << endl;
          	      cout << "* " << setw(4) << value2 << endl;
            	  cout << setw(6) << "-------\n";
            	  cin >> input;
            	  
                  if ( input == answer)
                     cout << "Congratulations! You got the right answer!" << endl;
                  else
                     cout << "Sorry, you got the wrong answer. The answer is:  " << answer << endl;
                  break;
             case DIV_OPTION:
                  answer = value1 / value2;
                  
                  cout << setw(6) << value1 << endl;
          	      cout << "/ " << setw(4) << value2 << endl;
            	  cout << setw(6) << "-------\n";
            	  cin >> input;
            	  
                  if (input == answer)
                     cout << "Congratulations! You got the right answer!" << endl;
                  else
                     cout << "Sorry, you got the wrong answer. The answer is:  " << answer << endl;
                  break;
             case QUIT_OPTION:
                  cout << "Exiting.";
                  break;
             default:
                  cout << "Invalid input.\n";
                  break;
         }
         cin.ignore();
    } while (option != QUIT_OPTION);
    
	return 0;
}
