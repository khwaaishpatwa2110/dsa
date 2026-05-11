#include <iostream>
using namespace std;

class ListNode
{
public:
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
    ListNode* detectCycle(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head;

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

            // cycle detected
            if(slow == fast)
            {
                ListNode* start = head;

                while(start != slow)
                {
                    start = start->next;
                    slow = slow->next;
                }

                return start;
            }
        }

        return NULL;
    }
};

int main()
{
    int n, value, pos;

    cout << "Enter no of values: ";
    cin >> n;

    if(n == 0)
    {
        cout << "Empty linked list";
        return 0;
    }

    cout << "Enter values: ";

    ListNode* head = NULL;
    ListNode* tail = NULL;
    ListNode* cycleNode = NULL;

    for(int i = 0; i < n; i++)
    {
        cin >> value;

        ListNode* newNode = new ListNode(value);

        if(head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }

        // save cycle starting node
        if(i == 0)
        {
            cycleNode = head;
        }
    }

    cout << "Enter position to create cycle: ";
    cin >> pos;
    // if a negative number is entered then the output will be 'No Cycle' as the positions start from 0

    if(pos != -1)
    {
        ListNode* temp = head;

        for(int i = 0; i < pos; i++)
        {
            temp = temp->next;
        }

        tail->next = temp;
    }

    Solution obj;

    ListNode* result = obj.detectCycle(head);

    if(result != NULL)
    {
        cout << "Cycle starts at node with value: " << result->val;
    }
    else
    {
        cout << "No cycle";
    }

    return 0;
}