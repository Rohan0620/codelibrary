    Node * nodeRoot(Node * root, int n1, int n2)
    {
        if(root == NULL)
           return NULL;
           
        if(root->data == n1 || root->data == n2)
          return root;
        Node *leftNode = nodeRoot(root->left, n1,n2);
        Node *rightNode = nodeRoot(root->right,n1,n2);
        
        
        if(leftNode==NULL)
           return rightNode;
        else if(rightNode == NULL)
           return leftNode;
        else
           return root;
    }
   
    
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 )
    {
       vector<int> v1,v2;
       
       Node * node = nodeRoot(root,n1,n2);
       return node;
    }
