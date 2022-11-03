#include "BankSystem.h"

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

SavingsBankAccount::SavingsBankAccount(double bal, double min){
    balance = bal;
    if(min > minimumBalance){
        minimumBalance = min;
    }
}

void SavingsBankAccount::set_minimumBalance(double min) {
    minimumBalance = min;
}

double SavingsBankAccount::get_minimumBalance() {
    return minimumBalance;
}

void SavingsBankAccount::withdraw_min(double withdrawal) {

}