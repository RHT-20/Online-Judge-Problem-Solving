#include<bits/stdc++.h>
using namespace std;

#define MX 7500
int dp[10][MX];
int coin[] = {50,25,10,5,1};

int solve(int i,int amount)
{
    if(i>=5)
    {
        if(amount==0)   return  1;
        else    return  0;
    }
    else if(dp[i][amount]!=-1)  return  dp[i][amount];
    int res1,res2;
    res1 = solve(i+1,amount);
    if((amount-coin[i])>=0) res2 = solve(i,(amount-coin[i]));
    else    res2 = 0;
    dp[i][amount] = res1+res2;
    return  dp[i][amount];
}

int main()
{
    int amount;
    memset(dp,-1,sizeof(dp));
    while(scanf("%d",&amount)==1)
    {
        printf("%d\n",solve(0,amount));
    }
    return  0;
}
