#include <bits/stdc++.h>

#define MAX 1000000007
using namespace std;

long long gcd(long long u, long long v) {
  long long t;
  while (v) {
    t = u; 
    u = v; 
    v = t % v;
  }
  return u < 0 ? -u : u; 
}

void multiply(long long F[2][2], long long M[2][2])
{
  long long x =  F[0][0]*M[0][0] + F[0][1]*M[1][0];
  long long y =  F[0][0]*M[0][1] + F[0][1]*M[1][1];
  long long z =  F[1][0]*M[0][0] + F[1][1]*M[1][0];
  long long w =  F[1][0]*M[0][1] + F[1][1]*M[1][1];

  F[0][0] = x%MAX;
  F[0][1] = y%MAX;
  F[1][0] = z%MAX;
  F[1][1] = w%MAX;
}

void power(long long F[2][2], long long n)
{
  if( n == 0 || n == 1)
      return;
  long long M[2][2] = {{1,1},{1,0}};

  power(F, n/2);
  multiply(F, F);

  if (n%2 != 0)
     multiply(F, M);
}

long long fib(long long n)
{
  long long F[2][2] = {{1,1},{1,0}};
  if (n == 0)
    return 0;
  power(F, n-1);
  return F[0][0];
}

int main() {
    long n;
    long long t=0,a,temp;
    cin>>n;
    for(long i = 0;i<n;i++)
    {
        cin>>a;
        temp = t;
        t = gcd(temp,a);
    }
    
    cout<<fib(t);
    return 0;
}
