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

    ListNode* oddEvenList(ListNode* head)
    {
        if(head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even;

        while(even != NULL && even->next != NULL)
        {
            odd->next = even->next;
            odd = odd->next;

            even->next = odd->next;
            even = even->next;
        }

        odd->next = evenHead;

        return head;
    }
};

void insertNode(ListNode* &head, int value)
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
    ListNode* temp = head;

    while(temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
}

int main()
{
    ListNode* head = NULL;

    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter values: ";

    for(int i = 0; i < n; i++)
    {
        int value;
        cin >> value;

        insertNode(head, value);
    }

    Solution obj;

    head = obj.oddEvenList(head);

    cout << "Output Linked List: ";
    display(head);

    return 0;
}