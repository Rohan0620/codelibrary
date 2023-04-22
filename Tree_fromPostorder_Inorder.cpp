    Node * bT(int inorder[], int postorder[], int postStart, int postEnd, int inStart, int inEnd, map<int,int> &mp)
    {
        if(postStart<0 || inStart<0 || inStart>inEnd || postStart>postEnd || postEnd<0)
            return NULL;
        
        int index = mp[postorder[postEnd]];
        Node *node = new Node(postorder[postEnd]);
        int remainEles = index-inStart;
        
        node->left = bT(inorder, postorder, postStart, postStart+remainEles-1, inStart, index-1,mp);
        node->right = bT(inorder, postorder, postStart+remainEles, postEnd-1, index+1,inEnd,mp);
        
        return node;
    }

//Function to return a tree created from postorder and inoreder traversals.
Node *buildTree(int in[], int post[], int n) {
      map<int,int> mp;
        
  
        
      for(int i=0;i<n;i++)
      {
          mp[in[i]] = i;
      }
        
      return bT(in, post, 0,n-1,0,n-1, mp);    
}
