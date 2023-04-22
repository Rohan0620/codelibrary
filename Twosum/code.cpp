#include<iostream>
#include<vector>

using namespace std;


vector<int> rec(vector<int>nums,int i,int target,vector<int>&ans)
    {
        if(ans.size()==2)
        {
            return ans;
        }
        if(i==nums.size())
        {
            return ans;
        }
        ans.push_back(i);
        ans=rec(nums,i+1,target,ans);
        if(ans.size()==2)
        {
        if(nums[ans[0]]+nums[ans[1]]==target)
            {
                return ans;
            }
        }
        ans.pop_back();
        return rec(nums,i+1,target,ans);
    
        
    }


int main()
{
    vector<int>nums;
    int n,target;
    cout<<"Enter n\n";
    cin>>n;
    cout<<"Enter array contents\n";
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    cout<<"Enter Target\n";
    cin>>target;
    vector<int>ans;

    ans=rec(nums,0,target,ans);
    cout<<"Ans is -";
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i];
    }


}