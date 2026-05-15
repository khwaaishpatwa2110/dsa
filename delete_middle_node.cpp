#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

void insertAtEnd(Node* &head, int val) {

    Node* newNode = new Node(val);

    if(head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;

    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

void display(Node* head) {

    Node* temp = head;

    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

Node* deleteMiddle(Node* head) {

    // If list has only one node
    if(head == NULL || head->next == NULL) {
        return NULL;
    }

    Node* slow = head;
    Node* fast = head;
    Node* prev = NULL;

    // Find middle node
    while(fast != NULL && fast->next != NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    // Delete middle node
    prev->next = slow->next;

    return head;
}

int main() {

    Node* head = NULL;

    int n, value;

    cout << "Enter number of nodes: ";
    cin >> n;

    for(int i = 1; i <= n; i++) {

        cout << "Enter value of node " << i << ": ";
        cin >> value;

        insertAtEnd(head, value);
    }

    cout << "\nOriginal Linked List: ";
    display(head);

    head = deleteMiddle(head);

    cout << "Linked List after deleting middle node: ";
    display(head);

    return 0;
}