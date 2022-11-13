#include "BankSystem.h"
#include <bits/stdc++.h>

map <string, list<string>> accounts;
map <string, list<string>> clients;

BankingApplication::BankingApplication(int ch){
    int choice;
    int countMap = 0;
    string user_ID, lineMap;
    fstream ClientFile;
    fstream accountFile;
    int choiceAccount;
    double accountBalance, minimumBalance;
    string name, address, phone;
    cout << "Welcome to FCAI Banking Application \n 1. Create a New Account \n 2. List Clients and Accounts \n 3. Withdraw Money \n 4. Deposit Money \n"
            "Please enter Choice:";
    cin >> choice;
    ClientFile.open("Client.txt", ios::in);
    while(!ClientFile.eof()){
        if(countMap == 0){
            getline(ClientFile, lineMap);
        }
        countMap++;
        getline(ClientFile, lineMap);
        getline(ClientFile, lineMap);
        string line1 = lineMap;
        getline(ClientFile, lineMap);
        string line2 = lineMap;
        getline(ClientFile, lineMap);
        string line3 = lineMap;
        getline(ClientFile, lineMap);
        string line4 = lineMap;
        clients.insert(pair<string, list<string>>(lineMap, {line1, line2, line3, line4}));
    }
    ClientFile.close();
    if(choice == 1){
        ClientFile.open("Client.txt", ios::app);
        accountFile.open("Account.txt", ios::app);
        BankAccount initalize;
        initalize.set_ID(initalize.increment_ID());
        ClientFile << initalize.get_ID() << endl;
        accountFile << initalize.get_ID() << endl;
        cout << "Please Enter Client Name: ";
        cin.ignore();
        getline(cin, name);
        ClientFile << name << endl;
        cout << "Please Enter Client Address: ";
        getline(cin, address);
        ClientFile << address << endl;
        cout << "Please Enter Client Phone: ";
        getline(cin, phone);
        ClientFile << phone << endl;
        Client user(name,address,phone);
        cout << "What Type of Account Do You Like? (1) Basic (2) Saving, Type 1 or 2: ";
        cin >> choiceAccount;
        if(choiceAccount == 1){
            cout << "Please Enter the Starting Balance: ";
            cin >> accountBalance;
            BankAccount basic(accountBalance);
            ClientFile << accountBalance << endl;
            accountFile << accountBalance << endl;
            accountFile << "Basic" << endl;
            accounts.insert(pair<string, list<string>>(initalize.get_ID(), {to_string(accountBalance), "Basic"}));
            clients.insert(pair<string, list<string>>(initalize.get_ID(), {name, address, phone, to_string(accountBalance)}));
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
            ClientFile << accountBalance << endl;
            accountFile << accountBalance << endl;
            accountFile << "Saving" << endl;
            accounts.insert(pair<string, list<string>>(initalize.get_ID(), {to_string(accountBalance), "Saving"}));
            clients.insert(pair<string, list<string>>(initalize.get_ID(), {name, address, phone, to_string(accountBalance)}));
        }
        ClientFile << endl;
        accountFile << endl;
        ClientFile.close();
        accountFile.close();
    } else if(choice == 2){

//        ifstream list;
//        list.open("Client.txt", ios::in);
//        int count = 0;
//        string word;
//        string line;

//        list<int>::iterator it = li.begin();
//
//        // Move the iterator by 5 elements
//        advance(it, 5);
//
//        // Print the element at the it
//        cout << *it;
        int count = 0;
        cout << "Please Enter Account ID (e.g., FCAI-015): ";
        cin >> user_ID;
        for (auto item:clients) {
            if(user_ID == item.first){
                cout << "ID: " << user_ID << endl;
            }
            for(auto item2: item.second){
                if(count == 0)
                    cout << "Name: ";
                if(count == 1)
                    cout << "Address: ";
                if(count == 2)
                    cout << "Phone: ";
                if(count == 3)
                    cout << "Balance: ";
                cout << item2 << endl;
                count++;
            }
        }
//        while(!list.eof() && count <= 5){
//            getline(list, line);
//            if(line.find(user_ID) != -1){
//               count++;
//            }
//            if(count >= 1){
//                cout << line << endl;
//                count++;
//            }
//        }
//        list.close();
    }else if(choice == 3) {
        cout << "Please Enter Account ID (e.g., FCAI-015): ";
        cin >> user_ID;
        fstream list;
        string balanceLine;
        list.open("Account.txt", ios::in | ios::out);
        int count = 0;
        string word;
        string line;
        while(!list.eof() && count <= 3){
            getline(list, line);
            if(line.find(user_ID) != -1) {
                count++;
            }
            if(count >= 1){
                cout << line << endl;
                if(count == 2){
                    balanceLine = line;
                }
                count++;
            }
        }

        list.close();
    } else if(choice == 4){
        cout << "Please Enter Account ID (e.g., FCAI-015): ";
    } else {
        cout << "Invalid input, please try again ";
        BankingApplication();
    }

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
    string word;
    while(!file.eof()){
        file >> word;
        if(word.substr(0,5) == "FCAI-"){
            count++;
        }
    }
    file.close();
    this->ID = this->ID + to_string(count);
    return this->ID;
}