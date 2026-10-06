#include <iostream>
using namespace std;

#define MAX 100

string list[MAX];
int n = 0;

void addItem() {
    string item;
    if (n == MAX) {
        cout << "Shopping list is full" << endl;
    } else {
        cout << "Enter item: ";
        cin >> item;
        list[n] = item;
        n++;
        cout << "Item added" << endl;
    }
}

void removeItem() {
    string item;
    cout << "Enter item to remove: ";
    cin >> item;

    for (int i = 0; i < n; i++) {
        if (list[i] == item) {
            for (int j = i; j < n - 1; j++)
                list[j] = list[j + 1];

            n--;
            cout << "Item removed" << endl;
            return;
        }
    }

    cout << "Item not found" << endl;
}

void searchItem() {
    string item;
    cout << "Enter item to search: ";
    cin >> item;

    for (int i = 0; i < n; i++) {
        if (list[i] == item) {
            cout << "Item found" << endl;
            return;
        }
    }

    cout << "Item not found" << endl;
}

void display() {
    if (n == 0) {
        cout << "Shopping list is empty" << endl;
    } else {
        cout << "Shopping List:" << endl;
        for (int i = 0; i < n; i++)
            cout << i + 1 << ". " << list[i] << endl;
    }
}

int main() {
    int choice;

    do {
        cout << "\n1. Store items in shopping list";
        cout << "\n2. Add an item";
        cout << "\n3. Remove an item";
        cout << "\n4. Search for an item";
        cout << "\n5. Display all items";
        cout << "\n6. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addItem();
                break;

            case 2:
                addItem();
                break;

            case 3:
                removeItem();
                break;

            case 4:
                searchItem();
                break;

            case 5:
                display();
                break;

            case 6:
                cout << "Program ended" << endl;
                break;

            default:
                cout << "Invalid choice" << endl;
        }

    } while (choice != 6);

    return 0;
}
