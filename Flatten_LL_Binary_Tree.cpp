    void flatten(Node *root)
    {
         Node * cur = root;
       if(root == NULL)
         return;
         
        while(cur)
        {
            if(cur->left)
            {
                Node * prev = cur->left;
                
                while(prev->right)
                 prev = prev->right;
                 
                prev->right = cur->right;
                cur->right = cur->left;
                
                 cur->left = NULL;
            }
                cur = cur->right;
            
        }
    }
