#include<bits/stdc++.h>
using namespace std;

#define MX 1005
vector<int>v;
int dp[MX][MX];

int solve(int bg,int ed)
{
    if(bg+1==ed)  return  0;
    else if(dp[bg][ed]!=-1) return  dp[bg][ed];
    int left=0,right=0,both=0,ans=INT_MAX;
    for(int md=bg+1; md<ed; md++)
    {
        left = solve(bg,md);
        right = solve(md,ed);
        both = (left+right)+(v[ed]-v[bg]);
        ans = min(ans,both);
    }
    return  dp[bg][ed] = ans;
}

int main()
{
    int l,n,x,i;
    while(1)
    {
        v.clear();
        memset(dp,-1,sizeof(dp));
        scanf("%d",&l);
        if(!l)  break;
        scanf("%d",&n);
        v.push_back(0);
        for(i=0; i<n; i++)
        {
            scanf("%d",&x);
            v.push_back(x);
        }
        v.push_back(l);
        printf("The minimum cutting is %d.\n",solve(0,v.size()-1));
    }
    return  0;
}

