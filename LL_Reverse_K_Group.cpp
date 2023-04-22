    ListNode* reverseKGroup(ListNode* head, int k) {
        int count = 1;

        ListNode *cur = head;

        while(cur->next != NULL)
        {
            count++;
            cur = cur->next;
        }
cout<<count<<endl;
        ListNode *dummy = new ListNode(1),*pre = dummy,*nex=dummy;
        dummy->next = head;

        while(count >= k)
        {
            cur =  pre->next;
            nex = cur->next;

            for(int i=1;i<k;i++)
            {
                cur->next = nex->next;
                nex->next = pre->next;
                pre->next = nex;
                nex = cur->next;
            }
            pre = cur;
            count -= k;
        }

        return dummy->next;
    }
