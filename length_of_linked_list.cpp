#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int findLength(Node* head) {
    int count = 0;
    Node* temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    return count;
}

int main() {
    Node* head = NULL;
    Node* temp = NULL;

    int value;

    cout << "Enter the nodes: ";

     while (cin >> value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }

        if (cin.peek() == '\n') break;  // stop at end of line
    }

    int length = findLength(head);

    cout << "Length of the nodes: " << length;

     /*
        reads until user presses ENTER
        means, nodes are entered by a space between them. when the user will click ENTER, then the length of the written node will be displayed
        ex:
        Enter the nodes: 2 3 4 5 6 (don't leave space after the last node otherwise the final result (i.e. length) won't be showed)
        Length of the nodes: 5
    */

    return 0;
}