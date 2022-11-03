#ifndef BANK_SYSTEM_H
#define BANK_SYSTEM_H
#include <iostream>
using namespace std;

class BankingApplication{
private:
public:
    BankingApplication();
};

class BankAccount : public BankingApplication{
private:
    string ID;
protected:
    double balance;
public:
    BankAccount();
    BankAccount(double bal);
    double get_balance();
    void set_balance(double bal);
    string get_ID();
    void set_ID(string id);
    void withdraw(double withdrawal);
    void deposit(double added);
};

class SavingsBankAccount : public BankAccount{
private:
    double minimumBalance = 1000;
public:
    SavingsBankAccount(double bal, double min);
    void set_minimumBalance(double min);
    double get_minimumBalance();
    //void withdraw_min(double withdrawal);
    //void deposit2(double added);
};

class Client : public BankingApplication{
private:
    string name;
    string address;
    string phone;
    //BankAccount* userAccount;
public:
    Client();
};


#endif //BANK_SYSTEM_H
