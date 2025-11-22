#include <iostream>
#include <string>
using namespace std;

class Product {
    private:
        int id;
        string name;
        double price;
    public:
        Product(int x, string y, double z){
            id = x;
            name = y;
            price = z;
            cout << "Constructor Called" << endl;
        }
        ~Product() {
            cout << "Destructor Called" << endl;
        }
        void printDetails() {
            cout << "ID: " << id  << endl;
            cout << "Name: " << name << endl;
            cout << "Price: $" << price << endl;
        }
};
int main(){
    Product Calculator(1234,"calculator",10.99);
    Calculator.printDetails();
    return 0;
}