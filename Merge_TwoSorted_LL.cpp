Node* sortedMerge(Node* h1, Node* h2)  
{  
    if(h1== NULL)
     return h2;
    if(h2== NULL)
      return h1;
      
    if(h2->data< h1->data)
    {
        swap(h1,h2);
    }
    
    Node * res = h1;
    
    while(h1 != NULL && h2!=NULL)
    {
        Node *tmp = NULL;
        while(h1!= NULL && h1->data <= h2->data)
        {
            tmp = h1;
            h1 = h1->next;
        }
        tmp->next = h2;
        swap(h1,h2);
    }
    
    return res;
} 
