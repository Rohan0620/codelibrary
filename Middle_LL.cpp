    ListNode* middleNode(ListNode* head) {
       ListNode *slow = head, *fast=head;

      

       if(head == NULL || head->next == NULL)
         return head;

       while(fast->next)
       {
           fast = fast->next;

           if(fast->next)
             fast =fast->next;
         

           slow = slow->next;
       }

       return slow;
          
    }
