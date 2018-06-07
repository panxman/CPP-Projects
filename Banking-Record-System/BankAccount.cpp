//
// Created by Panos N on 7/6/2018.
//

#include <iostream>
#include <fstream>
#include "BankAccount.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;

BankAccount::BankAccount() {
    account_number_ = 0;
    account_name_ = "John";
    account_surname_ = "Doe";
    account_balance_ = 0;

}
BankAccount::BankAccount(int num, std::string name, std::string surname, double balance){
    account_number_ = num;
    account_name_ = name;
    account_surname_ = surname;
    account_balance_ = balance;
}

void BankAccount::ShowData() const{
    cout << "Account Number: " << GetNumber() << endl;
    cout << "Account Name: " << GetName() << endl;
    cout << "Account Surname: " << GetSurname() << endl;
    cout << "Account Balance: " << GetBalance() << endl;
}
void BankAccount::CreateData() {
    cout << "Enter the Account Number: ";
    cin >> account_number_;
    cout << "Enter Name: ";
    cin >> account_name_;
    cout << "Enter Surname: ";
    cin >> account_surname_;
    cout << "Enter Balance: ";
    cin >> account_balance_;
    cout << "Done." << endl;
}

