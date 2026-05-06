#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    Node *head = NULL, *temp = NULL;

    cout << "Enter the nodes: ";
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;

        Node* newNode = new Node{val, NULL, NULL};

        if (head == NULL) {
            head = temp = newNode;
        } else {
            temp->next = newNode;
            newNode->prev = temp;
            temp = newNode;
        }
    }

    int p, x;
    cout << "Enter position: ";
    cin >> p;
    cout << "Enter value to insert: ";
    cin >> x;

    temp = head;
    for (int i = 0; i < p; i++) {
        temp = temp->next;
    }

    Node* newNode = new Node{x, temp, temp->next};

    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;

    cout << "Updated list: ";
    temp = head;
    while (temp != NULL) {
        cout << temp->data;
        if (temp->next) cout << " <-> ";
        temp = temp->next;
    }

    return 0;
}