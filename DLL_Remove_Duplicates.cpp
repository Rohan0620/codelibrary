    Node * removeDuplicates(struct Node *head)
    {
       Node *prev =NULL, *cur = head;
       
       while(cur != NULL)
       {
           if(prev != NULL && prev->data == cur->data)
           {
               cur->prev->next = cur->next;
               if(cur->next)
                 cur->next->prev = cur->prev;
           }
           prev = cur;
           cur = cur->next;
       }
       return head;
       
    }
