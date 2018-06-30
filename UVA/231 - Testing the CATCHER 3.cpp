#include<bits/stdc++.h>
using namespace std;

#define MX 35000
vector<int>v;
int value[MX];

int solve()
{
    int lo,hi,md,i,l=0;
    fill(value,value+MX,INT_MAX);
    value[0] = INT_MIN;
    for(i=0; i<v.size(); i++)
    {
        lo = 0;
        hi = l;
        while(lo<=hi)
        {
            md = (lo+hi)/2;
            if(value[md]<=v[i])  lo = md+1;
            else    hi = md-1;
        }
        value[lo] = v[i];
        if(lo>l)    l = lo;
    }
    return  l;
}

int main()
{
    int cs=0,x;
    while(1)
    {
        v.clear();
        while(1)
        {
            scanf("%d",&x);
            if(x==-1)   break;
            v.push_back(x);
        }
        if(v.size()==0) break;
        if(cs)  puts("");
        cs++;
        reverse(v.begin(),v.end());
        printf("Test #%d:\n  maximum possible interceptions: %d\n",cs,solve());
    }
    return  0;
}
