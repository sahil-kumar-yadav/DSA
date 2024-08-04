#include <iostream>

using namespace std;

// Given the head of a Singly Linked List and a number k, the task is to find the modular node of the linked list. If no such index is present return -1.

// A modular node is defined as the last node in the linked list whose index is divisible by k (i%k==0).

// Note: 1-based indexing is followed

int modularNode(Node *head, int k)
{
    // Code here
    int ans = -1;
    int index = 1;
    while (head != NULL)
    {

        if ((index % k) == 0)
        {
            ans = head->data;
        }
        head = head->next;
        index++;
    }

    return ans;
}
int main()
{

    return 0;
}