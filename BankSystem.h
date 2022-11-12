#ifndef BANK_SYSTEM_H
#define BANK_SYSTEM_H
#include <iostream>
using namespace std;

class BankingApplication{
public:
    BankingApplication(int ch);
    BankingApplication(){}
};

class BankAccount : public BankingApplication{
protected:
    string ID = "FCAI-";
    double balance;
    static int countID;
    //Client* ptr2;
public:
    BankAccount();
    BankAccount(double bal);
    double get_balance();
    void set_balance(double bal);
    string get_ID();
    string increment_ID();
    void set_ID(string id);
    virtual void withdraw(double withdrawal);
    virtual void deposit(double added);
};

class SavingsBankAccount : public BankAccount{
private:
    double minimumBalance;
public:
    SavingsBankAccount(double bal,double minBalance);
    void set_minimumBalance(double minBalance);
    double get_minimumBalance();
    void withdraw(double withdrawal);
    void deposit(double added);
};

class Client : public BankingApplication{
protected:
    string name;
    string address;
    string phone;
    BankAccount* ptr;
public:
    Client();
    Client(string name, string address, string phone);
    void set_name(string clientName);
    string get_name();
    void set_address(string clientAddress);
    string get_address();
    void set_phone(string clientPhone);
    string get_phone();
};


#endif //BANK_SYSTEM_H
