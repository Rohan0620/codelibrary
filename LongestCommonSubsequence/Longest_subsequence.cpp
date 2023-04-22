#include<iostream>
#include<vector>
using namespace std;

vector<vector<int> > LCS(string a,string b)
{
  vector<vector<int> >vec(a.size()+1,vector<int>(b.size()+1));
  for(int i=0;i<a.size()+1;i++)
  {
    vec[i][0]=0;
  }
   for(int i=0;i<b.size()+1;i++)
  {
    vec[0][i]=0;
  }
  for(int i=1;i<a.size()+1;i++)
  {
    for(int j=1;j<b.size()+1;j++)
    {
        if(a[i-1]==b[j-1])
        {
            vec[i][j]=vec[i-1][j-1]+1;
        }else{
            if(vec[i-1][j]>vec[i][j-1])
            {
                vec[i][j]=vec[i-1][j];
            }else{
                vec[i][j]=vec[i][j-1];
            }
        }
    }
  }

  return vec;
  


}

int main()
{
    string a,b;
    cin>>a>>b;
    vector<vector<int> >ans;
    ans=LCS(a,b);
    for(int i=0;i<a.size()+1;i++)
    {
        for(int j=0;j<b.size()+1;j++)
        {
           cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }



}