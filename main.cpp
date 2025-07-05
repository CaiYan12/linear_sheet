#include <iostream>
#include "linear.h"
using namespace std;

void show_main_menu() {
    cout << "=============================================" << endl;
    cout << "1. Print the List" << endl;
    cout << "2. Push a item in the List" << endl;
    cout << "3. Pop a item in the List" << endl;
    cout << "4. Sort the List" << endl;
    cout << "5. Reverse the List" << endl;
    cout << "6. Exit" << endl;
    cout << "=============================================" << endl;
    cout << "Enter your choice: ";
}

void push_menu(LinearSheet<int>& arr) {
    cout << "=============================================" << endl;
    cout << "1. Push Back" << endl;
    cout << "2. Push Front" << endl;
    cout << "3. Push At A Specified Index" << endl;
    cout << "=============================================" << endl;
    cout << "Enter your choice: ";
    
    int c;
    cin >> c;
    
    int item, index;
    switch (c) {
    case 1:
        cout << "Enter the item to be pushed: ";
        cin >> item;
        arr.push_back(item);
        break;
    case 2:
        cout << "Enter the item to be pushed: ";
        cin >> item;
        arr.push_front(item);
        break;
    case 3:
        cout << "Enter the item to be pushed: ";
        cin >> item;
        cout << "Enter the index at which the item to be pushed: ";
        cin >> index;
        arr.insert_at(item, index);
        break;
    default:
        cout << "Invalid choice" << endl;
        push_menu(arr);
    }
}

void pop_menu(LinearSheet<int>& arr) {
    cout << "=============================================" << endl;
    cout << "1. Pop Back" << endl;
    cout << "2. Pop Front" << endl;
    cout << "3. Pop At A Specified Index" << endl;
    cout << "=============================================" << endl;
    cout << "Enter your choice: ";
    
    int b;
    cin >> b;
    
    int index;
    switch (b) {
    case 1:
        arr.pop_back();
        break;
    case 2:
        arr.pop_front();
        break;
    case 3:
        cout << "Enter the index at which the item to be popped: ";
        cin >> index;
        arr.erase_at(index);
        break;
    default:
        cout << "Invalid choice" << endl;
        pop_menu(arr);
    }
}

void sort_menu(LinearSheet<int>& arr) {
    cout << "=============================================" << endl;
    cout << "1. Sort All Items" << endl;
    cout << "2. Sort Items In a Range" << endl;
    cout << "=============================================" << endl;
    cout << "Enter your choice: ";
    
    int d;
    cin >> d;
    
    int l, r;
    switch (d) {
    case 1:
        arr.sort_in_range(0, arr.length() - 1);
        break;
    case 2:
        cout << "Enter the left index: ";
        cin >> l;
        cout << "Enter the right index: ";
        cin >> r;
        if (l < 0 || r >= arr.length() || l > r) {
            cout << "Invalid range" << endl;
            sort_menu(arr);
            return;
        }
        arr.sort_in_range(l, r);
        break;
    default:
        cout << "Invalid choice" << endl;
        sort_menu(arr);
    }
}

void reverse_menu(LinearSheet<int>& arr) {
    cout << "=============================================" << endl;
    cout << "1. Reverse All Items" << endl;
    cout << "2. Reverse Items In a Range" << endl;
    cout << "=============================================" << endl;
    cout << "Enter your choice: ";
    
    int e;
    cin >> e;
    
    int l, r;
    switch (e) {
    case 1:
        arr.reverse_in_range(0, arr.length() - 1);
        break;
    case 2:
        cout << "Enter the left index: ";
        cin >> l;
        cout << "Enter the right index: ";
        cin >> r;
        if (l < 0 || r >= arr.length() || l > r) {
            cout << "Invalid range" << endl;
            reverse_menu(arr);
            return;
        }
        arr.reverse_in_range(l, r);
        break;
    default:
        cout << "Invalid choice" << endl;
        reverse_menu(arr);
    }
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
    
    LinearSheet<int> arr;
    // Initialise a list

    arr.push_back(96);
    arr.push_back(81);
    arr.push_back(34);
    arr.push_back(63);
    arr.push_back(90);
    arr.push_back(100);
    arr.push_back(50);
    arr.push_back(25);
    arr.push_back(75);

    while (true) {
        cout << "\nLinearSheet Datastructure Management" << endl;
        show_main_menu();
        
        int choice;
        cin >> choice;
        
        switch (choice) {
        case 1:
            cout << "\nThe List is: " << endl;
            arr.print();
            break;
        case 2:
            push_menu(arr);
            break;
        case 3:
            pop_menu(arr);
            break;
        case 4:
            sort_menu(arr);
            break;
        case 5:
            reverse_menu(arr);
            break;
        case 6:
            return 0;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    }
    return 0;
}