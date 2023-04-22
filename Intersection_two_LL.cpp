  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *cur1 = headA, *cur2 = headB;

        while(cur1->next && cur2->next)
        {
            cur1 = cur1->next;
            cur2 = cur2->next;
        }

        if(cur1->next == NULL )
        {
            ListNode *start = headB;
            while(cur2->next)
            {
                  cur2 = cur2->next;
                  start = start->next;
            }

            cur1 = headA;

            while(cur1 && start)
            {
                if(cur1 == start)
                  return cur1;

                cur1 = cur1->next;
                start = start->next;
            }

            return NULL;

        
        }else 
        {
            ListNode *start = headA;
            while(cur1->next)
            {
                  cur1 = cur1->next;
                  start = start->next;
            }

            cur2 = headB;

            while(cur2 && start)
            {
                if(cur2 == start)
                  return cur2;

                cur2 = cur2->next;
                start = start->next;
            }

            return NULL;
        }
        return NULL;
    }
