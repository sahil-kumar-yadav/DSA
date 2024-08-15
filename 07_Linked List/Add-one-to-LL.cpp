Node* addOne(Node* head) {
        // Your Code here
        // return head of list after adding one
        if(!head) 
        {
            return head;
        }
        
        stack<Node*>st;

        Node *temp = head;
        
        while(temp){
            st.push(temp);
            temp = temp->next;
        }
        long long int carry = 0;
        long long int digit = 0;
        if(!st.empty()){
            Node *last  = st.top();
            digit = last->data + 1;
            if(digit > 9) {
                carry = 1;
                digit = 0;
            }
            last->data = digit;
            st.pop();
        }
        
        
        
        while(!st.empty()){
            Node *last  = st.top();
            int sum = last->data + carry;
            digit = sum%10;
            carry = sum/10;
            last->data = digit;
            st.pop();
        }
        
        if(head->data == 0 && carry == 1)
        {
               Node *newNode = new Node(1);
               newNode->next = head;
               head = newNode;
               return head;
        }
        
        return head;
    }