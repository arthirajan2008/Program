#include <iostream>
using namespace std;

#define MAX 10

string stack[MAX];
int top = -1;

void push(string page) {
    if (top == MAX - 1) {
        cout << "History is full" << endl;
    } else {
        stack[++top] = page;
        cout << "Page added" << endl;
    }
}

void pop() {
    if (top == -1) {
        cout << "History is empty" << endl;
    } else {
        cout << "Back from: " << stack[top] << endl;
        top--;
    }
}

void display() {
    if (top == -1) {
        cout << "History is empty" << endl;
    } else {
        cout << "Current page: " << stack[top] << endl;
    }
}

int main() {
    int choice;
    string page;

    do {
        cout << "\n1. Visit a page";
        cout << "\n2. Back";
        cout << "\n3. Display current page";
        cout << "\n4. Display history";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter page: ";
                cin >> page;
                push(page);
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                if (top == -1) {
                    cout << "History is empty" << endl;
                } else {
                    cout << "Browser history:" << endl;
                    for (int i = top; i >= 0; i--)
                        cout << stack[i] << endl;
                }
                break;

            case 5:
                cout << "Program ended" << endl;
                break;

            default:
                cout << "Invalid choice" << endl;
        }

    } while (choice != 5);

    return 0;
}
