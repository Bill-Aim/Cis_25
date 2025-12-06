#include <iostream>
#include <fstream>
#include <string>
using namespace std;


class Bank_Account {
    private:
        double balance;
    public:
        Bank_Account(){
            balance = 0;
        }
        void make_purchase(string item, double amount){
            if (balance < amount){
                cout << "Not enough money in the account to make a purchase" << endl;
                save_transaction("Failed Purchase " + item + " : ", amount);         
            }
            else{
                balance -= amount;
                cout << "Purchase: " << item << endl;
                save_transaction("Purchase " + item + " : ", amount);                
            }
        }
        void deposit(double amount){
            balance += amount;
            cout << "Add $" << amount << " to the balance" << endl;
            save_transaction("Deposit: ", amount);
        }
        void print_balance(){
            cout << "Remaining Balance: $" << balance << endl;
        }
        void save_transaction(string type, double amount){
            ofstream outputFile("transactions.txt", ios::app);
            if (outputFile.is_open()) {
                outputFile << type << "$" << amount << endl;
                outputFile << "Remaining Balance: $" << balance << endl;
                outputFile.close();
            } 
        }
};
int main(){
    Bank_Account Account;
    Account.deposit(100);
    Account.make_purchase("Calculator", 15);
    Account.make_purchase("Textbook", 30);
    Account.print_balance();
    return 0;
}