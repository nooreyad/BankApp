#include "BankSystem.h"

//BankingApplication::BankingApplication(int ch){
//    choice = ch;
//    cout << "Welcome to FCAI Banking Application \n"
//            "1. Create a New Account \n"
//            "2. List Clients and Accounts \n"
//            "3. Withdraw Money \n"
//            "4. Deposit Money \n"
//            "Please enter Choice:";
//    cin >> choice;
//}

BankAccount::BankAccount(){
    balance = 0.0;
}
BankAccount::BankAccount(double bal){
    balance = bal;
}
double BankAccount::get_balance(){
    return balance;
}
void BankAccount::set_balance(double bal){
    bal = balance;
}
string BankAccount::get_ID(){
    return ID;
}
void BankAccount::set_ID(string id){
    id = ID;
}

void BankAccount::withdraw(double withdrawal) {
    if(withdrawal > balance){
        cout << "Withdrawal is greater than the available balance, please try again!" << endl;
    } else {
        balance -= withdrawal;
    }
}

void BankAccount::deposit(double added) {
    balance += added;
}

SavingsBankAccount::SavingsBankAccount(double bal){
    balance = bal;
    if(balance < minimumBalance){
        cout << "The minimum initial balance should be 1000, please try again!" << endl;
    }
}


double SavingsBankAccount::get_minimumBalance() {
    return minimumBalance;
}

void SavingsBankAccount::withdraw(double withdrawal) {
    if(withdrawal > balance){
        cout << "Withdrawal is greater than the available balance, please try again!" << endl;
    } else if(withdrawal > minimumBalance) {
        cout << "Withdrawal is greater than the minimum amount that should be left in bank, please try again!" << endl;
        balance -= withdrawal;
    }
}

void SavingsBankAccount::deposit(double added) {
    if (added < 100 and added >= 0){
        cout << "The minimum amount to be deposited in 100, please try again!" << endl;
    } else if (added >= 100){
        balance += added;
    }
}