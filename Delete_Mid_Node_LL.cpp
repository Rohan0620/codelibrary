    ListNode* deleteMiddle(ListNode* head) {
       ListNode *slow = head, *fast = head, *prev = NULL; 
       if(head == NULL)
         return head;

        if(head->next ==NULL)
          return NULL;
       while(fast && fast->next)
       {
         prev = slow;
           fast = fast->next->next;
           slow = slow->next;
       }


       prev->next = slow->next;

       return head;
    }
