#include <iostream>
using namespace std;
#include <iomanip>
#include <cstdlib> 
#include <time.h>

//global variables
double initbalance; //initial balance for checking
double balance; //checking balance
string firstname; //firstname of user
string lastname; //lastname of user
double savingsbalance; //savings balance


//savings
void savings(){ 
  //ask users name
  cout << "Enter your first name: " << endl;
  cin >> firstname;
  //last name
  cout << "Enter your Last name: " << endl;
  cin >> lastname;
  //initial balance
  cout << "Please enter the balance of your saving account: " << endl;
  cin >> savingsbalance;
  //display name/account type/current balance for said accoutn
  cout << firstname << " " << lastname << " " << "current balance is: " << savingsbalance << endl;
}
//checking
void checking()
{
//ask users name
  //last name
  //inital balance
  //display name/account type/current balance for said accoutn
  cout << "Enter your first name: " << endl;
  cin >> firstname;
  cout << "Enter your last name: " << endl;
  cin >> lastname;
  cout << "Enter checking balance"<< endl;
  cin >> balance;
  cout << firstname << " " << lastname << " " << "current balance is: " << balance << endl;
}

// deposit
void depo()
{
string user_choice;
  int user_choice2;
  double deposit_amount;

    while (true) {
        cout << "Would you like to make a deposit? [yes/no]: " << endl;
        cin >> user_choice;

        if ((user_choice != "Yes") && (user_choice != "yes")) {
            break;
        }

        cout << "1) Checkings" << endl;
        cout << "2) Savings" << endl;
        cout << "Enter: " << endl;
        cin >> user_choice2;


        switch (user_choice2) {
            case 1: {
                cout << "Enter an amount: " << endl;
                cin >> deposit_amount;
                balance += deposit_amount;
                cout << "Checkings Balance: " << balance << endl;
                break;
            }
            case 2: {
                cout << "Enter an amount: ";
                cin >> deposit_amount;
                savingsbalance += deposit_amount;
                cout << "Savings Balance: " << savingsbalance << endl;
                break;
            }
        }
    }
    cout << "Would you like to check your balance? [yes/no] " << endl;
    cin >> user_choice;

    cout << "1) Checkings" << endl;
    cout << "2) Savings" << endl;
    cout << "Enter: << endl";
    cin >> user_choice2;

    if (user_choice2 == 1) {
        cout << "Checkings Balance: " << balance << endl;
    }
    else if (user_choice2 == 2) {
        cout << "Savings Balance: " << savingsbalance << endl;
    }
}

void withdraw()
{
//withdrawal for either check or savings
  //repeat this withdrawal until user says no
  //show current balance once ended

  //create a loop that will repeat until the user says no
  //var--->
  string user_choice;
  string user_balance;
  double widthdraw_amount;
  double current_balance;
  double current_savings;
  cout << "Would you like to make a withdrawl?" << endl;
  cin >> user_choice;
  cout << "Which account do you want to proceed with, balance or savings?" << endl;
  cin >> user_balance;

  if(user_balance=="balance" || "Balance")
  {
    while(user_choice=="yes" || user_choice== "Yes")
      {
         cout << "Enter the amount: ";
         cin >> widthdraw_amount;
         current_balance = balance - widthdraw_amount;
         cout << "Do you want to make another withdrawl" << endl;
         cin >> user_choice;
         if(user_choice == "no" || user_choice == "No")
         {
           break;
         }
      }

  }

  if(user_balance=="savings" || "Savings")
  {
    while(user_choice=="yes" || user_choice== "Yes")
      {
        cout << "Enter the amount: " << endl;
        cin >> widthdraw_amount;
        current_savings= savingsbalance - widthdraw_amount;
        cout << "Do you wish to make another withdrawl?" << endl;
        cin >> user_choice;
        if(user_choice == "no" || user_choice == "No")
         {
           break;
        }
      }
  }

  cout << "The total checking balance in your account is" << current_balance << "and total savings " << current_savings;

}

//withdrawal

void transfer()
{
  double transfr;
  string ask;
  //Asking which account you want to transfer money from
  cout<< "Enter 'checking' or 'saving': " << endl;
  cin >> ask;
  cout << "Type your Transfer amount: " << endl;
  cin >> transfr;
  if (ask == "checking"){
      balance = balance - transfr;
      savingsbalance = savingsbalance + transfr;
    cout<< "Checking amount: " <<balance <<endl;

    cout<< "Saving amount: " << balance <<endl;
  }else if(ask == "saving"){
      savingsbalance = savingsbalance - transfr;
     // balance = balance - transfr;
    cout<< "Saving amount: "<< savingsbalance <<endl;
    cout<< "Checking amount: " << balance <<endl;
  }
//display(balance inquiry/account(s) summary)
}
void display(){
     cout << "Account Inquiry for: " << firstname << " " << lastname << endl;
      cout << "Checking Account summary: " << endl;
      cout << "Current Balance: $" << balance << endl;

      cout << endl;

        cout << "Savings Summary:" << endl;
        cout << "Current Savings Balance: $" << savingsbalance << endl;
    //display account summary of both savings/checkings
      //account inquiry
}
 
//main fuction
int main(){
    string response;

  do {
        cout << "Select one of the following. 1.checkings 2.savings 3.deposit 4.transfer. 5.withdrawal. 6. display. 7.exit. Please enter number or the word"<<endl;
            cin>> response;

      if(response == "checkings" || response == "1"){
          checking();
          
      }else if(response == "savings" || response == "2"){
          savings();

      }else if(response == "deposit" || response == "3"){
          depo();
      }else if(response == "transfer" || response == "4"){
          transfer();
      }else if(response == "withdrawal" || response == "5"){
          
          withdraw();
      }else if(response == "display" || response == "6"){
         display();
      }else if(response == "exit" || response == "7"){
          break;
      }
    
  }while(true);
 cout << "Thank you for banking at Manhattan College Banking and Co!" << endl;
 
}
