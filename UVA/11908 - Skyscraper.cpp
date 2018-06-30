#include<bits/stdc++.h>
using namespace std;

#define MX 30005
struct node
{
    int low,hi,cost;
    node(int l,int h,int c)
    {
        low = l;
        hi = h;
        cost = c;
    }
};
vector<node>v;
int dp[MX];

bool compare(node a,node b)
{
    if(a.low==b.low)
    {
        if(a.hi==b.hi)  return  (a.cost>b.cost);
        else    return  (a.hi<b.hi);
    }
    else    return  (a.low<b.low);
}

int binary_srch(int lo)
{
    int hi,md,x,pos=-1;
    hi = v.size()-1;
    x = v[lo-1].hi;
    while(lo<=hi)
    {
        md = (lo+hi)/2;
        if(v[md].low>=x)
        {
            pos = md;
            hi = md-1;
        }
        else    lo = md+1;
    }
    return  pos;
}

int solve(int i)
{
    if(i>=v.size()) return  0;
    else if(dp[i]!=-1)  return  dp[i];
    int res1=0,res2=0;
    res1 = solve(i+1);
    res2 += v[i].cost;
    int j = binary_srch(i+1);
    if(j!=-1)   res2 += solve(j);
    return  dp[i] = max(res1,res2);
}

int main()
{
    int t,cs=0,x,y,w,i,n;
    scanf("%d",&t);
    while(t--)
    {
        cs++;
        scanf("%d",&n);
        v.clear();
        memset(dp,-1,sizeof(dp));
        for(i=0; i<n; i++)
        {
            scanf("%d %d %d",&x,&y,&w);
            v.push_back(node(x,(x+y),w));
        }
        sort(v.begin(),v.end(),compare);
        printf("Case %d: %d\n",cs,solve(0));
    }
    return  0;
}
