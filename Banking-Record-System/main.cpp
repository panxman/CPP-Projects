#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "BankAccount.h"

using std::cout;
using std::endl;

void WriteFile(std::ostream &&o, std::vector<BankAccount> &list);
std::vector<BankAccount> ReadFile(std::istream &&i);
std::vector<std::string> SplitString(const std::string &s, char delim);
void SearchForRecord(std::vector<BankAccount> &list);
void UpdateRecord(std::vector<BankAccount> &list);
void DeleteRecord(std::vector<BankAccount> &list);

int main() {
    int choice {};
    BankAccount acc{};
    std::vector<BankAccount> rec_list;
    do{
        rec_list = ReadFile(std::ifstream{"Records.txt"});
        cout << "Account Information" << endl;
        cout << "Press 1 to 5 to select an option" << endl;
        cout << "\t\t1 - Add an Account" << endl;
        cout << "\t\t2 - Search for Record" << endl;
        cout << "\t\t3 - Update a Record" << endl;
        cout << "\t\t4 - Delete a Record" << endl;
        cout << "\t\t5- Exit" << endl;
        cout << "Selection :";
        std::cin >> choice;
        switch(choice){
            case 1:
                cout << "Creating new Account" << endl;
                try{
                    acc.CreateData();
                }catch (std::exception &e) {
                    cout << "Wrong format, please use the correct types." << endl;
                    break;
                }
                rec_list.emplace_back(acc);
                WriteFile(std::ofstream{"Records.txt"}, rec_list);
                cout << endl;
                break;
            case 2:
                SearchForRecord(rec_list);
                cout << endl;
                break;
            case 3:
                UpdateRecord(rec_list);
                break;
            case 4:
                DeleteRecord(rec_list);
                break;
            case 5:
                cout << "Exiting" << endl;
                break;
            default:
                cout << "Wrong option, try again" << endl;
        }
    }while(choice != 5);


    return 0;
}
// Write Data to File
void WriteFile(std::ostream &o, std::vector<BankAccount> &list){
    for (auto &rec : list){
        o << rec.GetNumber() << ";" << rec.GetName() << ";"
          << rec.GetSurname() << ";" << rec.GetBalance() << "\n";
    }
}
void WriteFile(std::ostream &&o, std::vector<BankAccount> &list){
    WriteFile(o, list);
}
//Read Data from File
auto ReadFile(std::istream &i) -> std::vector<BankAccount> {
    std::vector<BankAccount> list;
    std::string line{};

    while(std::getline(i, line)){
        int num;
        std::string name, surname;
        double balance;
        std::vector<std::string> split_string;

        split_string = SplitString(line, ';');

        num = std::stoi(split_string[0]);
        name = split_string[1];
        surname = split_string[2];
        balance = std::stod(split_string[3]);

        BankAccount temp_acc {num, name, surname, balance};
        list.emplace_back(temp_acc);
    }
    return list;
}
auto ReadFile(std::istream &&i) -> std::vector<BankAccount> {
    return ReadFile(i);
}
// Split strings
template<typename Out>
void SplitString(const std::string &s, char delim, Out result){
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        *(result++) = item;
    }
}
std::vector<std::string> SplitString(const std::string &s, char delim){
    std::vector<std::string> items;
    SplitString(s, delim, std::back_inserter(items));
    return items;
}

// Search for Record
void SearchForRecord(std::vector<BankAccount> &list){
    long count = list.size();
    cout << "There are " << count << " records in the file." << endl;
    cout << "Enter Account Number to Search: ";
    int num{};
    std::cin >> num;
    for (const auto &item : list){
        if (item.GetNumber() == num) {
            item.ShowData();
            return;
        }
    }
    cout << "Record not found." << endl;
}

// Update Record
void UpdateRecord(std::vector<BankAccount> &list){
    long count = list.size();
    cout << "There are " << count << " records in the file." << endl;
    cout << "Enter Account Number to Update: ";
    int num{};
    std::cin >> num;
    for (auto &item : list){
        if (item.GetNumber() == num) {
            item.ShowData();
            item.CreateData();
            WriteFile(std::ofstream{"Records.txt"}, list);
            return;
        }
    }
    cout << "Record not found." << endl;
}

// Delete a Record
void DeleteRecord(std::vector<BankAccount> &list){
    long count = list.size();
    cout << "There are " << count << " records in the file." << endl;
    cout << "Enter Account Number to Delete: ";
    int num{};
    std::cin >> num;
    for (std::vector<BankAccount>::iterator it=list.begin(); it!=list.end();){
        if (it->GetNumber() == num) {
            it->ShowData();
            list.erase(it);
            WriteFile(std::ofstream{"Records.txt"}, list);
            return;
        } else ++it;
    }
    cout << "Record not found." << endl;
}