#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// function to insert at beginning
Node* insertAtBeginning(Node* head, int x) {
    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = head;
    head = newNode;
    return head;
}

// function to print list
void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data;
        if (temp->next != NULL)
            cout << " -> ";
        temp = temp->next;
    }
}

int main() {
    // creating sample list: 20 -> 30
    Node* head = new Node;
    head->data = 20;
    head->next = new Node;
    head->next->data = 30;
    head->next->next = NULL;

    int x;
    cout << "Enter value to insert: ";
    cin >> x;

    head = insertAtBeginning(head, x);

    cout << "Output: ";
    display(head);

    return 0;
}