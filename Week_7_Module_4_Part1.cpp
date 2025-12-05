#include <iostream>

using namespace std;

int main() {
    int choice;
    cout << "Type 1 to start" << endl;
    cout << "Type 2 to open setting" << endl;
    cout << "type 3 to exit" << endl;
    cin >> choice;
    if (choice == 1){
        cout << "starting..." << endl;
    }
    else if (choice == 2){
        cout << "Opening Setting" << endl;
    }
    else if (choice == 3){
        cout << "exiting..." << endl;
    }
    else{
        cout << "invalid option" << endl;
    }
}