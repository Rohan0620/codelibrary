    ListNode * findMid(ListNode *head)
    {
        ListNode* fast = head->next, *slow = head;

        while(fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
      //  cout<<"-----"<<slow->val<<endl;
        return slow;
    }


    ListNode *merge(ListNode *left, ListNode *right)
    {

        if(left == NULL)
         return right;

        if(right == NULL)
          return left;
        ListNode *temp = new ListNode(1);
        ListNode *result = temp;
        while(left!=NULL && right != NULL)
        {
            if(left->val < right->val)
            {
                temp->next= left;
                temp = temp->next;
                left = left->next;
            }else{
                temp->next = right;
                temp = temp->next;
                right = right->next;
            }
        }

        if(left)
          temp->next = left;

        if(right)
          temp->next = right;

        return result->next;
    }



    ListNode* sortList(ListNode* head) {

        if(head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode *middle = findMid(head);
       cout<<middle->val<<endl;
        ListNode *left = head;
        ListNode *right = middle->next;
        middle->next = NULL;

        left = sortList(left);
        right = sortList(right);

        ListNode *result = merge(left,right);
        return result;
    }
