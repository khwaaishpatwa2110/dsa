#include <iostream>
using namespace std;

// node structure
struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

// function to segregate the linked list
// segregate means: separate and arrange all 0s first, then 1s,then 2s.

Node* segregate(Node* head) {

    int count0 = 0, count1 = 0, count2 = 0;

    Node* temp = head;

    // count number of 0s, 1s and 2s
    while (temp != NULL) {

        if (temp->data == 0)
            count0++;

        else if (temp->data == 1)
            count1++;

        else
            count2++;

        temp = temp->next;
    }

    temp = head;

    // replace values in sorted order
    while (temp != NULL) {

        if (count0 > 0) {
            temp->data = 0;
            count0--;
        }

        else if (count1 > 0) {
            temp->data = 1;
            count1--;
        }

        else {
            temp->data = 2;
            count2--;
        }

        temp = temp->next;
    }

    return head;
}

// function to insert node at the end
void insert(Node*& head, int val) {

    Node* newNode = new Node(val);

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// function to display linked list
void display(Node* head) {

    Node* temp = head;

    while (temp != NULL) {

        cout << temp->data;

        if (temp->next != NULL)
            cout << " -> ";

        temp = temp->next;
    }

    cout << endl;
}

int main() {

    Node* head = NULL;

    int n, value;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter elements (0, 1, 2 only):\n";

    for (int i = 0; i < n; i++) {
        cin >> value;
        insert(head, value);
    }

    cout << "\nOriginal Linked List:\n";
    display(head);

    head = segregate(head);

    cout << "\nLinked List after segregation:\n";
    display(head);

    return 0;
}