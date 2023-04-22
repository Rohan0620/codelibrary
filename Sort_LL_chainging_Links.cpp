   Node* segregate(Node *head) {
        
        Node *zero = NULL, *one = NULL, *two = NULL, *zc = NULL, *oc = NULL, *tc = NULL;
        
        Node *cur = head;
        
        while(cur)
        {
            if(cur->data == 0)
            {
                if(zero)
                {
                    zc->next= cur;
                    zc = zc->next;
                }else
                {
                    zero = cur;
                    zc = cur;
                }
            }else if(cur->data == 1)
            {
                if(one)
                {
                    oc->next = cur;
                    oc = oc->next;
                }else{
                    one = cur;
                    oc = cur;
                }
            }else{
                if(two)
                {
                    tc->next = cur;
                    tc = tc->next;
                    
                }else{
                    two = cur;
                    tc = cur;
                }
            }
           // cout<<cur->data<<endl;
            cur = cur->next;
            
        }
        
        if(oc)
        oc->next = NULL;
        if(zc)
        zc->next = NULL;
        if(tc)
        tc->next = NULL;
        
        Node * res = NULL,*last = NULL;
        
        if(zero)
        {
            res = zero;
            last = zc;
        }
        
        if(one)
        {
            if(res == NULL)
            {
                res = one;
                last = oc;
            }else{
                last->next = one;
                last = oc;
            }
        }
        

        if(two)
        {
            if(res == NULL)
            {
                res = two;
                last = tc;
            }else{
                last->next = two;
                last = tc;
            }           
        }
        
        return res;
        
    }
