class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head_ref, int x) {
       if(*head_ref == NULL)
         return ;
   
       Node *cur = *head_ref,*pre=NULL;
       
       
       while(cur!= NULL)
       {
           
           if(cur->data == x)
           {
               if(cur->prev != NULL)
                  cur->prev->next = cur->next;
               else
                  *head_ref = (*head_ref)->next;
               if(cur->next)
                  cur->next->prev = cur->prev;
               else
               {
                   if(pre != NULL)
                   {
                       pre->next = NULL;
                   }
               }
                  
           }
           pre = cur;
           cur = cur->next;
       }
       
      
    }
};
