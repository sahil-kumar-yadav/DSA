int findLenght(Node *head){
    if(!head) return 0;

    int count = 0;
    while(head){
        head = head->next;
        count++;
    }

    return count;
}

Node *solve(Node *firstHead, Node *secondHead){
    if(firstHead == NULL || secondHead == NULL) return NULL;

    int lenA = findLenght(firstHead);
    int lenB = findLenght(secondHead);

    if(lenA>lenB){
        // A bada hai

        int aage = lenA-lenB;

        while(aage--){
            firstHead = firstHead->next;
        }

        while(firstHead != secondHead){
            firstHead = firstHead->next;
            secondHead = secondHead->next;

            if(firstHead == NULL || secondHead == NULL) return NULL;
        }

        return firstHead;


    }
    else{
        int aage = lenB-lenA;

        while(aage--){
            secondHead = secondHead->next;
        }

        while(firstHead != secondHead){
            firstHead = firstHead->next;
            secondHead = secondHead->next;

            if(firstHead == NULL || secondHead == NULL) return NULL;
        }

        return firstHead;
    }

}

Node* findIntersection(Node *firstHead, Node *secondHead)
{
    //Write your code here
    Node *ans = solve(firstHead,secondHead);

    return ans;
}