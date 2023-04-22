
#include <iostream>
#include<vector>
#include<math.h>

using namespace std;


void mergebuild(vector<int> &arr,int ind,int low,int high,vector<vector<int> >&mseg)
{
    if(low==high)
    {
        mseg[ind].push_back(arr[low]);
        return;
    }
    int mid=(low+high)/2;
    mergebuild(arr,2*ind+1,low,mid,mseg);
    mergebuild(arr,2*ind+2,mid+1,high,mseg);
    int i=0,j=0;
    while(i<mseg[2*ind+1].size() && j<mseg[2*ind+2].size())
    {
        if(mseg[2*ind+1][i]<=mseg[2*ind+2][j])
        {
            mseg[ind].push_back(mseg[2*ind+1][i]);
            i++;
        }else{
            mseg[ind].push_back(mseg[2*ind+2][j]);
            j++;
        }
    }

        while(i<mseg[2*ind+1].size())
        {
            mseg[ind].push_back(mseg[2*ind+1][i]);
            i++;

        }
          while(j<mseg[2*ind+2].size())
        {
            mseg[ind].push_back(mseg[2*ind+2][j]);
            j++;

        }
 

    
}
void build(int ind,int low,int high,int seg[],int arr[])
{
    if(low==high)
    {
        seg[ind]=arr[low];
        return ;
    }
    int mid=(low+high)/2;
    build(2*ind+1,low,mid,seg,arr);
    build(2*ind+2,mid+1,high,seg,arr);
    seg[ind]=min(seg[2*ind+1],seg[2*ind+2]);
   
    return;


}

vector<int> mergequery(int low,int high,int l,int r,int ind,int k,vector<vector<int> >&mseg)
{
      if (low >= l and high <= r)
  {
      return mseg[ind];
  }
    if (r < low or l > high)
  {
      return vector<int>();
  }
   int mid = (low + high) / 2;

  /*
  Fetch sorted subarray from the left and the right subtrees
  and merge them to get a sorted array in the range [l, r]
  */
  vector<int> left = mergequery(low,mid,l,r,2 * ind + 1,k,mseg);
  vector<int> right =mergequery(mid+1,high,l,r,2 * ind + 2,k,mseg);
  
  int i=0,j=0;
  vector<int>ar;
  while(i<left.size() && j<right.size())
  {
     if(left[i]<=right[j])
     {
        ar.push_back(left[i]);
        i++;
     }else{
        ar.push_back(right[j]);
        j++;
     }
  }
  while(i<left.size())
  {
    ar.push_back(left[i]);
    i++;
  }
   while(j<right.size())
  {
    ar.push_back(right[j]);
    j++;
  }
  return ar;


}

void mergeupdate(vector<int> &arr,int idx,int val,vector<vector<int> > &mseg,int n)
{
    
    mseg.erase(mseg.begin(),mseg.end());
    mergebuild(arr,0,0,n-1,mseg);
  
 

    

}

void update(int ind,int val,int upi,int seg[ ],int low,int high)
{
    if(low==high)
    {
        seg[ind]=val;
        return;
    }
    int mid=(low+high)/2;
    int left=INT_MAX,right=INT_MAX;
    if(upi<=mid)
    {
       update(2*ind+1,val,upi,seg,low,mid);
    }
    else{
       update(2*ind+2,val,upi,seg,mid+1,high);
    }
    seg[ind]=min(seg[2*ind+1],seg[2*ind+2]);
    
    return;
}

int query(int ind,int low,int high,int l,int r,int seg[ ])
{
    if(high<l || r<low)
    {
        return INT_MAX;
    } if(low>=l && high<=r)
    {
        return seg[ind];
    }
    int mid=(high+low)/2;
    int left=query(2*ind+1,low,mid,l,r,seg);
    int right=query(2*ind+2,mid+1,high,l,r,seg);
    return min(left,right);
    
}
int main(){
    int n;
    cin>>n;
    // vector<int>arr;
    int arr[n];
    int seg[4*n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    build(0,0,n-1,seg,arr);
    //  for(int i=0;i<4*n;i++)
    // {
    //     cout<<seg[i]<<" ";
    // }

    cout<<query(0,0,n-1,0,n-1,seg)<<endl;
    // update(0,9,3,seg,0,n-1);

    // cout<<query(0,0,n-1,3,5,seg)<<endl;
    // vector<vector<int> > mseg;
    // mergebuild(arr,0,0,n-1,mseg);
    
    // int k=13;
    // arr[0]=1;
    // mseg.erase(mseg.begin(),mseg.end());
    // mergebuild(arr,0,0,n-1,mseg);
    // vector<int>ans=mergequery(0,n-1,0,0,1,k,mseg);
    // cout<<ans[ans.size()-k]<<endl;


   

  
    // k=3;
    // vector<int>ansd=mergequery(0,n-1,0,3,0,k,mseg);
    // cout<<ansd[ans.size()-k]<<endl;


   


    
    
}