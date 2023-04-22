#include <bits/stdc++.h>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define N  1000000



using namespace std;


int seg[4*N+1];
void build(int ind, int low , int high, int v[])
{
    if(low == high)
    {
        seg[ind] = v[low];
        return;
    }
    
    int mid = (low+high)>>1;
    
    build(2*ind+1, low, mid, v);
    build(2*ind+2, mid+1, high, v);
    
    seg[ind] = seg[2*ind+1] + seg[2*ind+2];
}


void update(int ind, int low, int high,  int i, int val)
{
    if(low == high)
    {
        seg[ind] += val;
        return;
    }
    
    int mid = (low+high)>>1;
    
    if(i<=mid)
        update(2*ind+1,low, mid,   i, val);
    else
        update(2*ind+2, mid+1,high, i ,val);
    seg[ind] = seg[2*ind+1] + seg[2*ind+2];
    
}


int query(int ind, int low, int high, int l, int r)
{
    // No overlap
    
    if(high<l || r<low)
        return 0;
    
    //complete overlap
    
    if(low>=l && high<=r)
        return seg[ind];
    
    // partial overlap
    int mid = (low+high)>>1;
    
    int left = query(2*ind+1, low ,mid, l,r);
    int right = query(2*ind+2, mid+1,high, l, r);
    
    return left+right;
}




void solve()
{
    int n;
    cin>>n;
    
    int v[n];
    int maxi = -1;
    for(int i=0;i<n;i++)
    {
         cin>>v[i];
        maxi = max(maxi, v[i]);
    }
    
    maxi+=1;
    
    int freq[maxi];
    memset(freq,0,sizeof freq);
    
    for(int i=0;i<n;i++)
        freq[v[i]]++;

    
  //  int seg[4*maxi+1];
    
    build(0, 0, maxi-1, freq);
    int cnt = 0;
    for(int i=0;i<n;i++)
    {
        freq[v[i]]--;
        update(0,0,maxi-1,v[i],-1);
        
        cnt += query(0,0,maxi-1,1,v[i]-1);
    }
    cout<<cnt<<endl;
    if(cnt >= n)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    
}

int main() {
    int t;
    cin>>t;
    
    while(t--)
        solve();
    return 0;
}
