    ListNode* rotateRight(ListNode* head, int k) {

        if(head == NULL || head->next == NULL || k==0)
          return head;
        int count = 1;
        ListNode *cur = head;
        while(cur->next!=NULL)
        {
            count++;
            cur = cur->next;
        }

        k = k%count;
        k = count-k;
        cur->next = head;
        if(k == 0)
          return head;
        

        while(k--)
        {
            cur = cur->next;
        }

        head = cur->next;
        cur->next = NULL;

        return head;
        

    }
