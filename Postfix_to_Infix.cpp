  string postToInfix(string post) {
        stack<string> st;
        
        string ans = "";
        
        int n = post.size();
        
        for(int i=0;i<n;i++)
        {
            string c(1,post[i]);
            if((c>="a" && c<="z") || (c>="A" && c<="Z"))
              st.push(c);
            else
            {
                string two = st.top();
                st.pop();
                
                string one = st.top();
                st.pop();
                
                st.push("(" + one + c + two + ")");
            }
        }
        
        return st.top();
    }
