 #include <iostream>
using namespace std;

#define MAX 100

int stack[MAX];
int top = -1;

void push(int car) {
    if (top == MAX - 1) {
        cout << "Parking garage is full" << endl;
    } else {
        top++;
        stack[top] = car;
        cout << "Car parked successfully" << endl;
    }
}

void pop() {
    if (top == -1) {
        cout << "Parking garage is empty" << endl;
    } else {
        cout << "Car " << stack[top] << " left the garage" << endl;
        top--;
    }
}

void display() {
    if (top == -1) {
        cout << "Parking garage is empty" << endl;
    } else {
        cout << "Cars in parking garage:" << endl;
        for (int i = top; i >= 0; i--) {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int choice, car;

    do {
        cout << "\n1. Park a car";
        cout << "\n2. Remove a car";
        cout << "\n3. Display cars";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter car number: ";
                cin >> car;
                push(car);
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                cout << "Program ended";
                break;

            default:
                cout << "Invalid choice";
        }

    } while (choice != 4);

    return 0;
}
