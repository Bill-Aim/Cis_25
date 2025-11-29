#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Item {
    string name;
    int id;
};

int binary_search(Item array[], int size, int target){
    int low = 0;
    int high = size-1;
    while (low <= high){
        int middle = (high+low)/2;
        if (array[middle].id == target){
            return middle;
        }
        else if (array[middle].id > target){
            high = middle -1;
        }
        else{
            low = middle +1;
        }
    }
    return -1;
}
bool sort_by_name(const Item& a, const Item& b){
    return a.name<b.name;
}
int main() {
    Item* inventory = new Item[100];
    for (int i=0; i < 100; i++){
        inventory[i].id = 100 + i;
        inventory[i].name = "Item_" + to_string(i+1);
    }
    sort(inventory, inventory+100, sort_by_name);
    int search_id;
    cout << "Enter the item id: " << endl;
    cin >> search_id;
    int search_result = binary_search (inventory, 100, search_id);
    if (search_result == -1){
        cout << "Item not found" << endl;
    }
    else{
        cout << "ID: " << search_id << endl;
        cout << "Name: " << inventory[search_result].name << endl;
    }
    delete[] inventory;
    return 0;
}