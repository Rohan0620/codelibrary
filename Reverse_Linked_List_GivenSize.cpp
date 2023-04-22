    struct node *reverse (struct node *head, int k)
    { 
        // If head is NULL or K is 1 then return head
      if(head == NULL || k == 1)
            return head;
        struct  node *dummy = new node(2);
        dummy->next = head;
        
        struct  node *pre = dummy, *cur = dummy, *nex = dummy;
        

          int count = 0;
        while(cur->next)
        {
            count ++ ;
            cur = cur->next;
        }
        cur = dummy;
        while(nex)
        {
            cur = pre->next;
            nex = cur->next;
           // cout<<count<< " "<<k<<endl;
            int toloop = (count>=k)?k:count;
            for(int i=1;i<toloop;i++)
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
