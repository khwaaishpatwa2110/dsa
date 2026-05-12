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

    // reverse linked list
    Node* reverse(Node* head)
    {
        Node* prev = NULL;
        Node* curr = head;
        Node* nextNode;

        while (curr != NULL)
        {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
    }

    int isPalindrome(Node* head)
    {
        if (head == NULL || head->next == NULL)
        {
            return 1;
        }

        Node* slow = head;
        Node* fast = head;

        // find middle
        while (fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // reverse second half
        Node* secondHalf = reverse(slow->next);

        Node* firstHalf = head;
        Node* temp = secondHalf;

        // compare both halves
        while (temp != NULL)
        {
            if (firstHalf->data != temp->data)
            {
                return 0;
            }

            firstHalf = firstHalf->next;
            temp = temp->next;
        }

        return 1;
    }
};

int main()
{
    int n;

    cout << "Enter number of nodes: ";
    cin >> n;

    Node* head = NULL;
    Node* tail = NULL;

    cout << "Enter node values:\n";

    for (int i = 1; i <= n; i++)
    {
        int value;
        cin >> value;

        Node* newNode = new Node(value);

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

    Solution obj;

    if (obj.isPalindrome(head) == 1)
    {
        cout << "Linked list is Palindrome";
    }
    else
    {
        cout << "Linked list is Not Palindrome";
    }

    return 0;
}