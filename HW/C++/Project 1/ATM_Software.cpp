/*
** This program is designed by Simon Lam. This program is similar to the ATM
** machines. This programs does what an ATM machine would do, just in text
** format.
*/
#include <iostream>
#include <cstdlib>
using namespace std;

void transferToChecking(), transferToSavings();
double getSavings(), getChecking();
void withdrawal(), displayMenu();
bool testPIN(int);
double checkingAccount = 1000.00, savingsAccount = 1000.00;
const int PIN = 111;

int main()
{
    double optionInput;
    int counter = 0, pin;
    const int TRANSFER_TO_SAVING = 1,
              TRANSFER_TO_CHECKING = 2,
              SAVINGS_BALANCE = 3,
              CHECKING_BALANCE = 4,
              WITHDRAWAL = 5,
              EXIT_OPTION = 6;
    
    while (counter < 3)
    {
          cout << "\n***Welcome to Cal Poly's ATM***\n";
          if (counter != 0)
          cout << "Invalid PIN. Number of tries left: " << 3 - counter << endl;
          else if (counter == 0) cout << endl;
          cout << "Please enter your PIN: ";
          cin >> pin;
          
          if(testPIN(pin)) break;
          else counter++;
          
          if(counter == 3) exit(0);
          system("cls");
    }
    system("cls");
    
    do
    {
          displayMenu();
          cin >> optionInput;
          system("cls");
          switch (static_cast<int>(optionInput))
          {
                 case TRANSFER_TO_SAVING:
                      transferToSavings();
                      break;
                 case TRANSFER_TO_CHECKING:
                      transferToChecking();
                      break;
                 case SAVINGS_BALANCE:
                      cout << "\n\nYour Savings Account's Balance is: $"
                           << getSavings() << endl;
                      break;
                 case CHECKING_BALANCE:
                      cout << "\n\nYour Checking Account's Balance is: $"
                           << getChecking() << endl;
                      break;
                 case WITHDRAWAL:
                      withdrawal();
                      break;
                 case EXIT_OPTION: 
                      cout << "\nThank you for using the ATM System.";
                      break;
                 default: break;
          }
          cout << "\n\nPress any key to continue...";
          cin.get();
          cin.ignore();
          system("cls");
    } while(optionInput != EXIT_OPTION);
}

/*
** This function transfers money from the Savings Account
** to the Checking Account. This function asks the user to
** declare the amount of money that is being transferred.
** Then, depending whether the account has sufficient funds,
** will proceed to transfer the amount to the other account.
*/
void transferToChecking()
{
     double amount;
     
     cout << "How much would you like to transfer: ";
     cin >> amount;
     
     if (savingsAccount < amount) 
     {
         cout << "Transaction not completed. Insufficient funds."
              << "\nSavings Account's Balance : " << savingsAccount << endl;
     } else
     {
         checkingAccount += amount;
         savingsAccount -= amount;
         
         cout << "\n\n\t\tCurrent Balances"
              << "\n\nChecking Account Balance:  $" << checkingAccount
              << "\nSavings Account Balance:  $" << savingsAccount;
     }
}

/*
** This function transfers money from the Checking Account
** to the Savings Account. This function asks the user to
** declare the amount of money that is being transferred.
** Then, depending whether the account has sufficient funds,
** will proceed to transfer the amount to the other account.
*/
void transferToSavings()
{
     double amount;
     
     cout << "How much would you like to transfer: ";
     cin >> amount;
     if (checkingAccount < amount)
     {
         cout << "Transaction not completed. Insufficient funds."
              << "\nChecking Account's Balance : " << checkingAccount;
     }
     else
     {
         checkingAccount -= amount;
         savingsAccount += amount;
         
         cout << "\n\n\t\tCurrent Balances"
              << "\n\nChecking Account Balance:  $" << checkingAccount
              << "\nSavings Account Balance:  $" << savingsAccount;
     }
}

/*
** This function allows the user to withdraw money from different accounts.
** Once the account is chosen and the designated amount inputted, the function will
** withdraw the money.
*/
void withdrawal()
{
     double amount, option;
     
     const int CHECKING = 1,
               SAVINGS = 2;
     
     cout << "\n\t\tWithdrawal Options\n\n"
          << "1. Checking Account\n"
          << "2. Savings Account\n"
          << "Enter your choice number: ";
     cin >> option;
     cout << "\nEnter the amount you wish to withdraw: ";
     cin >> amount;
     
     switch (static_cast<int>(option))
     {
            case CHECKING:
                 if (checkingAccount < amount)
                    cout << "Withdrawal failed. Insufficient funds." << endl;
                 else
                 {
                     checkingAccount -= amount;
                     cout << "Withdrew:  $" << amount << "\n"
                          << "Checking Account Balance:  $" << checkingAccount;
                 }
                 break;
            case SAVINGS:
                 if (savingsAccount < amount)
                    cout << "Withdrawal failed. Insufficient funds." << endl;
                 else
                 {
                     savingsAccount -= amount;
                     cout << "Withdrew:  $" << amount << "\n"
                          << "Checking Account Balance:  $" << savingsAccount;
                 }
                 break;
            default:
                    cout << "Invalid Input. Re-directing back to Main Menu.";
     }
}

/*
** This function compares the user's inputted PIN with
** the correct PIN. The function will return true if the 
** inputted PIN is correct, or false if the PIN is not
** the correct PIN.
*/
bool testPIN(int inputPIN)
{
	if (PIN == inputPIN) return true;
	else return false;
}

/*
** This function returns the amount of cash that is within
** the Savings Account. There are no parameters.
*/
double getSavings()
{
	return savingsAccount;
}

/*
** This function returns the amount of cash that is within
** the Checking Account. There are no parameters.
*/
double getChecking()
{
	return checkingAccount;
}

/* 
** This function displays the Menu for the ATM System.
** No parameters is necessary and there will be no value returned.
*/
void displayMenu()
{
	cout << "*** Welcome To Cal Poly's ATM System ***\n\n"
	     << "(1) Transfer from checking account to savings account\n"
	     << "(2) Transfer from savings account to checking account\n"
	     << "(3) Savings account balance\n"
	     << "(4) Checking account balance\n"
	     << "(5) Withdraw Cash from either account\n"
	     << "(6) Exit\n"
         << "==> Please select option (1-6):";
}
