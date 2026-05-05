#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    int n, value, key;

    cout << "Enter number of nodes: ";
    cin >> n;

    Node* head = NULL;
    Node* temp = NULL;
    Node* newNode = NULL;

    cout << "Enter node values: "; 
    // enter the values by putting SPACE in between them. so when ENTER is clicked, next step will be displayed
    for(int i = 0; i < n; i++) {
        cin >> value;

        newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
        } else {
            temp->next = newNode;
        }
        temp = newNode;
    }

    cout << "Enter key to search: ";
    cin >> key;

    temp = head;
    int found = 0;   // 0 = not found, 1 = found

    while(temp != NULL) {
        if(temp->data == key) {
            found = 1;
            break;
        }
        temp = temp->next;
    }

    if(found == 1)
        cout << "Output: true";
    else
        cout << "Output: false";

    return 0;
}