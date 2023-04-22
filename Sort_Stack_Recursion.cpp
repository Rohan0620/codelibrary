void insert(int ele, stack<int> &st)
{
    if(st.empty() || st.top() <= ele)
    {
        st.push(ele);
        return;
    }
    
    int temp = st.top();
    st.pop();
    insert(ele,st);
    st.push(temp);
}
void solve(stack<int> &st)
{
    if(st.empty())
      return;
      
    int temp = st.top();
    st.pop();
    solve(st);
    insert(temp,st);
    
}
void SortedStack :: sort()
{
    solve(s);
}
