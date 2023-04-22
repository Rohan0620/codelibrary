class Solution{
    
    void insert(int ele , stack<int> &s)
   {
    if(s.empty())
    {
        s.push(ele);
        return;
    }
    
    int temp = s.top();
    s.pop();
    
    insert(ele,s);
    s.push(temp);
   }
   
public:
    void Reverse(stack<int> &st){
        if(st.empty())
          return;
          
        int temp = st.top();
        st.pop();
        
        Reverse(st);
        
        insert(temp, st);
    }
};
