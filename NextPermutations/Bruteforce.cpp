#include<iostream>
#include<vector>
#include<unordered_map>


using namespace std;

int nextpermutation(vector<vector<int> >&final,vector<int>arr)
{
    for(int i=0;i<final.size();i++)
    {
        

    
        int eq=0;
        for(int j=0;j<final[i].size();j++)
        {
           if(arr[j]!=final[i][j]) break;
           eq++;
        }
       
        if(eq==arr.size()){
            if(i==final.size()-1) return 0;
            else{
                return i+1;
            }
        
        }
    }
     
}

void permutations(vector<int>arr,vector<int>&check,vector<int>&ans ,vector<vector<int> >&final)
{
    if(ans.size()==arr.size())
    {
        final.push_back(ans);
        return;
    }

    for(int i=0;i<arr.size();i++)
    {
        if(check[i]==0)
        {
          check[i]=1;
          ans.push_back(arr[i]);
          permutations(arr,check,ans,final);
          ans.pop_back();
          check[i]=0;


        }
    }
   

}

int main()
{
    int n;
    cout<<"Enter array size"<<endl;
    cin>>n;
    vector<int>arr;
    for(int i=0;i<n;i++)
    {
        int b;
        cin>>b;
        arr.push_back(b);
    }
    vector<int> check(n,0);
    vector<vector<int > >final;
    vector<int>ans;
  
    permutations(arr,check,ans,final);
   int ind= nextpermutation(final,arr);
    for(int i=0;i<final[ind].size();i++)
    {
        cout<<final[ind][i]<<" ";
    }


    
  

}