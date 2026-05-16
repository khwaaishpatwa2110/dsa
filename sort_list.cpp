#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

// function to find middle of linked list
// slow pointer moves one step at a time
// fast pointer moves two steps at a time
// when fast reaches the end, slow will be at the middle

Node* findMiddle(Node* head)
{
    Node* slow = head;
    Node* fast = head->next;

    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // slow is now at the middle node
    return slow;
}

// function to merge two sorted linked lists

Node* merge(Node* left, Node* right)
{
    if(left == NULL)
        return right;

    if(right == NULL)
        return left;

    Node* result = NULL;

    if(left->data < right->data)
    {
        result = left;
        result->next = merge(left->next, right);
    }
    else
    {
        result = right;
        result->next = merge(left, right->next);
    }

    return result;
}

// merge sort function
Node* sortList(Node* head)
{
    if(head == NULL || head->next == NULL)
        return head;

    // find middle
    Node* mid = findMiddle(head);

    Node* left = head;
    Node* right = mid->next;

    mid->next = NULL;

    // recursive sorting
    left = sortList(left);
    right = sortList(right);

    // merge sorted halves
    return merge(left, right);
}

// function to insert node at end
void insert(Node*& head, int val)
{
    Node* newNode = new Node(val);

    if(head == NULL)
    {
        head = newNode;
        return;
    }

    Node* temp = head;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

// function to display linked list
void display(Node* head)
{
    Node* temp = head;

    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main()
{
    Node* head = NULL;

    int n;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter elements: ";

    for(int i = 0; i < n; i++)
    {
        int val;
        cin >> val;

        insert(head, val);
    }

    cout << "Original Linked List: ";
    display(head);

    head = sortList(head);

    cout << "Sorted Linked List: ";
    display(head);

    return 0;
}