    ListNode* reverseList(ListNode* head) {
        if(head == NULL)
            return head;
        ListNode *d = NULL, *next = NULL;
        
        while(head != NULL)
        {
            next = head->next;
            head->next = d;
            d = head;
            head = next;
        }
        
        return d;
    }


    bool isPalindrome(ListNode* head) {
        ListNode *fast = head, *slow = head;
    
        while(fast!=NULL && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        
        slow = reverseList(slow);



         
        ListNode *cur = head;

        while(slow!=NULL)

        {
            if(cur->val != slow->val)
              return false;
            cur = cur->next;
            slow = slow->next;
        }

        return true;
    }
