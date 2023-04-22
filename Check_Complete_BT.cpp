    int left(TreeNode *root)
    {
        int c = 0;

        while(root != NULL)
        {
            c++;
            root = root->left;
        }
        return c;
    }

    int right(TreeNode *root)
    {
        int c = 0;

        while(root != NULL)
        {
            c++;
            root = root->right;
        }
        return c;
    }


    int solve(TreeNode *root)
    {
        
        if(root->left == NULL && root->right == NULL)
          return 1;
        
          
        int lh = left(root->left);
        int rh = right(root->right);

        if(lh<rh)
          return 0;
        int x=1;

        if(root->left)
          x = x && solve(root->left);

        if(root->right)
          x = x && solve(root->right);
        return  x;
    }
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;

        bool emptyFound = false;

        q.push(root);

        while(!q.empty())
        {
            TreeNode *cur = q.front();
            q.pop();

            if(cur == NULL)
            {
                emptyFound = true;
                continue;
            }else if(emptyFound)
              return false;
            q.push(cur->left);
            q.push(cur->right);
        }
        return true;
    }
