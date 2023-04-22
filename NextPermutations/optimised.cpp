#include<iostream>
#include<vector>



using namespace std;

void nextpermutation(vector<int>&arr,int n)
{
     
        int i=n-1;
        while(i>0 && arr[i-1]>=arr[i])
        {
            i--;
        }
        int j=n-1;
        if(i<=0)
        {
            while(i<j)
            {
                swap(arr[i],arr[j]);
                i++;
                j--;
            }
            return;
        }
     
     
        while(arr[j]<=arr[i-1])
        {
            j--;
        }
    
        swap(arr[i-1],arr[j]);
        j=n-1;
        while(i<j)
        {
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
        return;


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
    nextpermutation(arr,n);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

   

}