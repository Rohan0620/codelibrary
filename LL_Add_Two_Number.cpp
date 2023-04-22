/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

struct Node* reverse(struct Node* head)
{
    struct Node *cur1 = head, *cur2 , *prev = NULL;
    while(cur1!=NULL)
    {
        cur2 = cur1->next;
        cur1->next = prev;
        prev = cur1;
        cur1=cur2;
    }
    return prev;
}

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        first = reverse(first);
        second = reverse(second);
        struct Node *cur1 = first , *cur2 = second, *final=NULL,*temp=NULL,*cur=NULL;
        int s=0;
        int c=0;
        while(cur1!=NULL || cur2!=NULL)
        {
            s = c + (cur1?cur1->data:0) + (cur2?cur2->data:0);
            if(s>=10)
            {
              c=1; 
              s = s%10;
            }
            else
             c=0;
            
            temp = new Node(s);
            if(final == NULL)
            {
                final = temp;
            }
            else
            cur->next = temp;
            
            cur = temp;
            if(cur1) cur1 = cur1->next;
            
            if(cur2) cur2=cur2->next;
        }
        
        if(c>0)
        {
           temp = new Node(c);
           cur->next = temp;
           cur=temp;
        }
        final = reverse(final);
        return final;
    }
};
