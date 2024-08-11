#include <iostream>

using namespace std;

bool areIdentical(struct Node *head1, struct Node *head2)
{

    if (head1->data != head2->data)
    {
        return false;
    }
    while (head1->next && head2->next)
    {
        if (head1->data != head2->data)
        {
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    if (head1->data != head2->data)
    {

        return false;
    }
    else
    {
        head1 = head1->next;
        head2 = head2->next;
    }

    if (head1 == NULL && head2 != NULL)
    {
        // length not equal
        return false;
    }

    if (head1 != NULL && head2 == NULL)
    {
        // length not equal
        return false;
    }

    return true;
}

int main()
{

    return 0;
}