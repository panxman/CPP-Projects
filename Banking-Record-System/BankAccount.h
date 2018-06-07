//
// Created by Panos N on 7/6/2018.
//
#include <string>
#include <fstream>

#ifndef UNTITLED_BANKACCOUNT_H
#define UNTITLED_BANKACCOUNT_H


class BankAccount {
private:
    int account_number_;
    std::string account_name_;
    std::string account_surname_;
    double account_balance_;

public:
    BankAccount();
    BankAccount(int num, std::string name, std::string surname, double balance);

    int GetNumber() const {return account_number_;}
    double GetBalance() const {return account_balance_;}
    std::string GetName() const {return account_name_;}
    std::string GetSurname() const {return account_surname_;}

    void ShowData() const;
    void CreateData();
};


#endif //UNTITLED_BANKACCOUNT_H
