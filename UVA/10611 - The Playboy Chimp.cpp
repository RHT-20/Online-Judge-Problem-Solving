#include<bits/stdc++.h>
using namespace std;

void binary_srchx(long long a[],long long hi,long long p)
{
    long long md,lo=0;
    while(lo<=hi)
    {
        md = (lo+hi)/2;
        if(a[md]<p) lo = md+1;
        else if(a[md]>=p)   hi = md-1;
    }
    if(hi<0)    printf("X");
    else    printf("%lld",a[hi]);
}

void binary_srchy(long long a[],long long hi,long long p)
{
    long long md,lo=0,n;
    n = hi;
    while(lo<=hi)
    {
        md = (lo+hi)/2;
        if(a[md]<=p) lo = md+1;
        else if(a[md]>p)   hi = md-1;
    }
    if(lo>n)   printf(" X\n");
    else    printf(" %lld\n",a[lo]);
}

int main()
{
    long long n,i,p,q,x,y;
    scanf("%lld",&n);
    long long a[n];
    for(i=0; i<n; i++)
    {
        scanf("%lld",&a[i]);
    }
    scanf("%lld",&q);
    for(i=0; i<q; i++)
    {
        scanf("%lld",&p);
        binary_srchx(a,n-1,p);
        binary_srchy(a,n-1,p);
    }
    return 0;
}
