#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;

    ListNode(int x)
    {
        val = x;
        next = NULL;
    }
};

class Solution
{
public:
    ListNode* remNth(ListNode* head, int n)
    {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* fast = dummy;
        ListNode* slow = dummy;

        // Move fast pointer n+1 steps ahead
        for(int i = 0; i <= n; i++)
        {
            fast = fast->next;
        }

        // Move both pointers
        while(fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }

        // Remove nth node
        ListNode* temp = slow->next;
        slow->next = slow->next->next;

        delete temp;

        return dummy->next;
    }
};

void insertNode(ListNode*& head, int value)
{
    ListNode* newNode = new ListNode(value);

    if(head == NULL)
    {
        head = newNode;
    }
    else
    {
        ListNode* temp = head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }
}

void display(ListNode* head)
{
    while(head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }

    cout << endl;
}

int main()
{
    ListNode* head = NULL;

    int size, value, n;

    cout << "Enter number of nodes: ";
    cin >> size;

    cout << "Enter linked list values:" << endl;

    for(int i = 0; i < size; i++)
    {
        cin >> value;
        insertNode(head, value);
    }

    cout << "Enter the position of the node to be removed from the end: ";
    cin >> n;

    Solution s;
    head = s.remNth(head, n);

    cout << "Linked list after removing the nth node from the end:" << endl;
    display(head);

    return 0;
}