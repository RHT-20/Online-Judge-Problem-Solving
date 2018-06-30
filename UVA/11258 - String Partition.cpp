#include<bits/stdc++.h>
using namespace std;

#define MX 205
string str;
long long dp[MX][MX],IMX;

bool check(int i,int j)
{
    long long x=0;
    for(int k=i; k<=j; k++)
    {
        x = (x*10)+(str[k]-48);
        if(x>IMX)   return  false;
    }
    return  true;
}

long long str_to_int(int i,int j)
{
    long long x=0;
    for(int k=i; k<=j; k++) x = (x*10)+(str[k]-48);
    return  x;
}

long long solve(int i,int j)
{
    if(i>j) return  0;
    else if(check(i,j))   return  str_to_int(i,j);
    else if(dp[i][j]!=-1)   return  dp[i][j];
    long long res=0,ans=INT_MIN;
    for(int k=i; k<j; k++)
    {
        if(check(i,k)==false)   break;
        res = str_to_int(i,k)+solve(k+1,j);
        ans = max(ans,res);
    }
    return  dp[i][j] = ans;
}

int main()
{
    int t;
    scanf("%d",&t);
    IMX = INT_MAX;
    while(t--)
    {
        cin >> str;
        memset(dp,-1,sizeof(dp));
        printf("%lld\n",solve(0,str.size()-1));
    }
    return  0;
}
