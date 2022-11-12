#include "BankSystem.h"
#include <bits/stdc++.h>

//int BankAccount::countID = 0;

BankingApplication::BankingApplication(int ch){
    int choice;
    string user_ID;
    fstream ClientFile;
    fstream accountFile;
    ClientFile.open("Client.txt", ios::app);
    accountFile.open("Account.txt", ios::app);
    int choiceAccount;
    double accountBalance, minimumBalance;
    string name, address, phone;
    cout << "Welcome to FCAI Banking Application \n 1. Create a New Account \n 2. List Clients and Accounts \n 3. Withdraw Money \n 4. Deposit Money \n"
            "Please enter Choice:";
    cin >> choice;
    if(choice == 1){
        BankAccount initalize;
        initalize.set_ID(initalize.increment_ID());
        ClientFile << "Account ID: " << initalize.get_ID() << endl;
        accountFile << "Account ID: " << initalize.get_ID() << endl;
        cout << "Please Enter Client Name: ";
        cin.ignore();
        getline(cin, name);
        ClientFile << "Name: " << name << endl;
        cout << "Please Enter Client Address: ";
        getline(cin, address);
        ClientFile << "Address: " << address << endl;
        cout << "Please Enter Client Phone: ";
        getline(cin, phone);
        ClientFile << "Phone: " << phone << endl;
        Client user(name,address,phone);
        cout << "What Type of Account Do You Like? (1) Basic (2) Saving, Type 1 or 2: ";
        cin >> choiceAccount;
        if(choiceAccount == 1){
            cout << "Please Enter the Starting Balance: ";
            cin >> accountBalance;
            BankAccount basic(accountBalance);
            ClientFile << "Balance: " << accountBalance << endl;
            accountFile << "Balance: " << accountBalance << endl;
            accountFile << "Account Type: Basic" << endl;
        } else if(choiceAccount == 2){
            cout << "Please Enter the Starting Balance: ";
            cin >> accountBalance;
            cout << "Please Enter the Minimum Balance, if not specified enter Minimum Balance of value 1000: ";
            cin >> minimumBalance;
            while(accountBalance < minimumBalance){
                cout << "The initial balance shouldn't be less than the minimum balance, please try again!" << endl;
                cin >> accountBalance;
            }
            SavingsBankAccount savingAccount(accountBalance,minimumBalance);
            ClientFile << "Balance: " << accountBalance << endl;
            accountFile << "Balance: " << accountBalance << endl;
            accountFile << "Account Type: Saving" << endl;
        }
    } else if(choice == 2){
//        string word;
//        string line;
//        cout << "Please Please Enter Account ID (e.g., FCAI-015): ";
//        cin >> user_ID;
//        while(ClientFile >> word){
//            if(word == user_ID){
//                for (int i = 0; i < 5; ++i) {
//                    getline(ClientFile, line);
//                    cout << line;
//                }
//            }
//        }
    }else if(choice == 3) {
        cout << "Please Enter Account ID (e.g., FCAI-015): ";
    }else if(choice == 4){
        cout << "Please Enter Account ID (e.g., FCAI-015): ";
    } else {
        cout << "Invalid input, please try again ";
        BankingApplication();
    }
    ClientFile << endl;
    accountFile << endl;
    ClientFile.close();
    accountFile.close();
}

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

SavingsBankAccount::SavingsBankAccount(double bal,double minBalance = 1000.0){
    minimumBalance = minBalance;
    balance = bal;
}

void SavingsBankAccount::set_minimumBalance(double minBalance){
    minimumBalance = minBalance;
}

double SavingsBankAccount::get_minimumBalance() {
    return minimumBalance;
}

void SavingsBankAccount::withdraw(double withdrawal) {
    if(balance-withdrawal>= minimumBalance) {
        balance -= withdrawal;
    } else {
        cout << "Withdrawal is greater than the minimum amount that should be left in bank, please try again!" << endl;
    }
}

void SavingsBankAccount::deposit(double added) {
    if (added < 100){
        cout << "The minimum amount to be deposited in 100, please try again!" << endl;
    } else {
        balance += added;
    }
}
Client::Client()
:name("none"), address("None"), phone("0"){

}

Client::Client(string name, string address, string phone) {
    this->name = name;
    this->address = address;
    this->phone = phone;
}

void Client::set_name(string clientName){
    name = clientName;
}
string Client::get_name(){
    return name;
}
void Client::set_address(string clientAddress){
    address = clientAddress;
}
string Client::get_address(){
    return address;
}
void Client::set_phone(string clientPhone){
    phone = clientPhone;
}
string Client::get_phone(){
    return phone;
}

string BankAccount::increment_ID(){
    ifstream file;
    file.open("Account.txt");
    int count = 0;
    string line;
    while(!file.eof()){
        getline(file, line);
        count++;
    }
    count --;
    count /= 4;
    this->ID = this->ID + to_string(count);
    return this->ID;
}