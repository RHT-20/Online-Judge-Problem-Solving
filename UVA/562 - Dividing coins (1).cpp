#include<bits/stdc++.h>
using namespace std;

#define MX1 105
#define MX2 50005
vector<int>v;
int dp[MX1][MX2],amount;

int solve(int i,int w)
{
    if(i>=v.size()) return  0;
    else if(dp[i][w]!=-1)  return  dp[i][w];
    int res1=0,res2=0;
    res1 = solve(i+1,w);
    if(v[i]<=w)    res2 = v[i]+solve(i+1,(w-v[i]));
    return  dp[i][w] = max(res1,res2);
}

int main()
{
    int t,n,w,i,ans1,ans2;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        v.clear();
        amount = 0;
        for(i=0; i<n; i++)
        {
            scanf("%d",&w);
            v.push_back(w);
            amount += w;
        }
        memset(dp,-1,sizeof(dp));
        ans1 = solve(0,amount/2);
        ans2 = abs(amount-ans1);
        printf("%d\n",abs(ans1-ans2));
    }
    return  0;
}
