# Program
Linked list implementation 
#include <iostream>
using namespace std;

struct Node {
    int coach;
    Node* next;
};

Node* head = NULL;

void addBeginning(int coach) {
    Node* newNode = new Node();
    newNode->coach = coach;
    newNode->next = head;
    head = newNode;
}

void addEnd(int coach) {
    Node* newNode = new Node();
    newNode->coach = coach;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

void removeCoach(int coach) {
    if (head == NULL)
        return;

    if (head->coach == coach) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL && temp->next->coach != coach)
        temp = temp->next;

    if (temp->next != NULL) {
        Node* del = temp->next;
        temp->next = del->next;
        delete del;
    }
}

void display() {
    Node* temp = head;

    while (temp != NULL) {
        cout << "Coach" << temp->coach << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

int main() {
    int choice, coach;

    addEnd(1);
    addEnd(2);
    addEnd(3);
    addEnd(5);

    do {
        cout << "\n1. Add a coach at beginning";
        cout << "\n2. Add a coach at end";
        cout << "\n3. Remove a coach";
        cout << "\n4. Display all coaches";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter coach number: ";
                cin >> coach;
                addBeginning(coach);
                break;

            case 2:
                cout << "Enter coach number: ";
                cin >> coach;
                addEnd(coach);
                break;

            case 3:
                cout << "Enter coach number to remove: ";
                cin >> coach;
                removeCoach(coach);
                break;

            case 4:
                display();
                break;

            case 5:
                cout << "Program ended.";
                break;

            default:
                cout << "Invalid choice.";
        }

    } while (choice != 5);

    return 0;
}
