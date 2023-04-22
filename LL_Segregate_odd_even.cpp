// Input: 
// N = 7
// Link List:
// 17 -> 15 -> 8 -> 9 -> 2 -> 4 -> 6 -> NULL

// Output: 8 2 4 6 17 15 9   

Node* divide(int N, Node *head){
        Node *odd = NULL , *even = NULL, *oddcur=   NULL, *evencur=NULL;
        
        Node *cur = head,*nex = cur->next;
        while(cur != NULL)
        {
            if(cur->data & 1)
            {
                if(odd ==NULL)
                {
                    odd = cur;
                    oddcur = odd;
                }else
                {
                    oddcur->next = cur;
                    oddcur = oddcur->next;
                }
            }else
            {
                 if(even ==NULL)
                {
                    even = cur;
                    evencur = even;
                }else
                {
                    evencur->next = cur;
                    evencur = evencur->next;
                }               
            }
              cur = cur->next;
        }
        if(oddcur)
        {
            oddcur->next = NULL;
        }
        if(even != NULL)
        {
            evencur->next= odd;
            return even;
        }
        
        return odd;
    }
