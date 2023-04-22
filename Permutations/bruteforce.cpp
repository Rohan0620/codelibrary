#include<iostream>
#include<string>

using namespace std;

void permute(string a[],int i,int n)
{
    if(i==n-1)
    {
       for(int i=0;i<n;i++)
       {
        cout<<a[i]<<" ";
       }
       cout<<endl;

        return;
    }
    for(int j=i;j<n;j++)
    {
        string temp=a[i];
        a[i]=a[j];
        a[j]=temp;
        permute(a,i+1,n);
        string temps=a[i];
        a[i]=a[j];
        a[j]=temps;

    }

}

int main()
{
   string array[3];
   for(int i=0;i<3;i++)
   {
    string in;
    cin>>in;
    array[i]=in;

   }
     for(int i=0;i<3;i++)
   {
  
    cout<<array[i]<<" ";
   }
   permute(array,0,3);

}
