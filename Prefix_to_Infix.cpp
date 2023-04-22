    string preToInfix(string pre) {
        
        stack<string> st;
        
        string ans = "";
        
        int n = pre.size();
        
        for(int i=n-1;i>=0;i--)
        {
            string c(1,pre[i]);
            if((c>="a" && c<="z") || (c>="A" && c<="Z"))
              st.push(c);
            else
            {
                string two = st.top();
                st.pop();
                
                string one = st.top();
                st.pop();
                
                st.push("(" + two + c + one + ")");
            }
        }
        
        return st.top();
    }
