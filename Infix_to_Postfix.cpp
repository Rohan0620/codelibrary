class Solution {
    
    int prec(char c)
    {
        switch(c)
        {
            case '^':
            return 3;
            case '*':
             return 2;
            case '/':
            return 2;
            case '+':
            return 1;
            case'-' : return 1;
            
            default: return 0;        
        }
    }
  public:
    // Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string s) {
       stack<char> st;
       string ans = "";
       for(int i=0;i<s.size();i++)
       {
           char c = s[i];
           
           if((c>='a' && c<='z') || (c>='A' && c<='Z'))
              ans += c;
           else if(c=='(')
            st.push(c);
           else if(c==')')
           {
               while(st.top() != '(')
                 {
                     ans += st.top();
                     st.pop();
                 }
                 st.pop();
            }
            else{
                while(!st.empty() && prec(st.top()) >= prec(c))
                {
                    ans += st.top();
                    st.pop();
                }
                
                st.push(c);
            }
           
       }
       
       while(!st.empty())
       {
           ans += st.top();
           st.pop();
       }
       
       return ans;
    }
};
