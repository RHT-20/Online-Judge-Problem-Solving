#include<bits/stdc++.h>
using namespace std;

#define MX 1000005
int a[MX],res1,res2;
vector<int>v;

void sieve()
{
    a[0] = a[1] = 1;
    for(int i=2; i<MX; i+=2) a[i] = 1;
    for(int i=3; i<MX; i+=2)
    {
        if(a[i]==0)
        {
            v.push_back(i);
            for(int j=i+i; j<MX; j+=i)
            {
                a[j] = 1;
            }
        }
    }
}

bool solve(int x)
{
    int f=0;
    for(int i=v.size()-1; i>=0; i--)
    {
        if(v[i]>=x)  continue;
        else if(a[x-v[i]]==0)
        {
            f = 1;
            res1 = v[i];
            res2 = x-v[i];
            break;
        }
    }
    return  (f==1);
}

int main()
{
    int n;
    sieve();
    while(1)
    {
        scanf("%d",&n);
        if(n==0)    break;
        if(solve(n)==false) printf("Goldbach's conjecture is wrong.\n");
        else    printf("%d = %d + %d\n",n,res2,res1);
    }
    return 0;
}
