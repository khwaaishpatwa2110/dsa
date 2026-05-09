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

void insert(Node* &head, int val)
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

int hasCycle(Node* head)
{
    Node* slow = head;
    Node* fast = head;
    /*
    the slow and fast pointers are used to detect a cycle efficiently.
        1. slow moves 1 step
        2. fast moves 2 steps
    if there is no cycle, then fast will eventually become NULL because it reaches the end of the linked list.
    */

    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)
        {
            return 1;
        }
    }

    return 0;
}

int main()
{
    Node* head = NULL;

    int n, value;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter values:\n";

    for(int i = 0; i < n; i++)
    {
        cin >> value;
        insert(head, value);
    }

    int pos;
    cout << "Enter position to create cycle: "; 
    cin >> pos;
    // if a negative number is entered then the output will be 'No Cycle' as the positions start from 0

    if(pos != -1)
    {
        Node* temp = head;
        Node* cycleNode = NULL;
        Node* last = head;

        int index = 0;

        while(last->next != NULL)
        {
            if(index == pos)
            {
                cycleNode = last;
            }

            last = last->next;
            index++;
        }

        if(index == pos)
        {
            cycleNode = last;
        }

        last->next = cycleNode;
    }

    if(hasCycle(head))
    {
        cout << "Cycle Found";
    }
    else
    {
        cout << "No Cycle";
    }

    return 0;
}