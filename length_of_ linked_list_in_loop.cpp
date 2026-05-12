#include <iostream>
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

class Solution
{
public:
    int countLoop(Node *head)
    {
        Node *slow = head;
        Node *fast = head;

        // detect loop
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        // slow and fast pointers are used to detect the loop efficiently without using extra memory.

            // loop found
            if (slow == fast)
            {
                int count = 1;
                Node *temp = slow->next;

                while (temp != slow)
                {
                    count++;
                    temp = temp->next;
                }

                return count;
            }
        }

        // No loop
        return 0;
    }
};

int main()
{
    int n, pos;

    cout << "Enter number of nodes: ";
    cin >> n;

    Node *head = NULL;
    Node *tail = NULL;

    cout << "Enter node values:\n";

    for (int i = 1; i <= n; i++)
    {
        int value;
        cin >> value;

        Node *newNode = new Node(value);

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    cout << "Enter position to create loop: ";
    cin >> pos;
   /*
        enter 0 for no loop
        positions for numbers start from 1
        example:
        values: 12, 53, 64, 23, 93
        pos:    (1) (2) (3) (4) (5)
        position to create loop: 2
        length of loop: 4
   
   */

    // create loop
    if (pos != 0)
    {
        Node *loopNode = head;

        for (int i = 1; i < pos; i++)
        {
            loopNode = loopNode->next;
        }

        tail->next = loopNode;
    }

    Solution obj;

    int result = obj.countLoop(head);

    cout << "Length of loop: " << result;

    return 0;
}