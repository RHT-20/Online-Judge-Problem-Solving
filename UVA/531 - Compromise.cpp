#include<bits/stdc++.h>
using namespace std;

#define MX 105
vector<string>vs1,vs2;
int dp[MX][MX];
string ans;

int solve_dp(int i,int j)
{
    if(i>=vs1.size() || j>=vs2.size())  return  0;
    else if(dp[i][j]!=-1)   return  dp[i][j];
    int res=0;
    if(vs1[i]==vs2[j])  res = 1+solve_dp(i+1,j+1);
    else    res = max(solve_dp(i+1,j),solve_dp(i,j+1));
    return  dp[i][j] = res;
}

void solve_str(int i,int j)
{
    if(i>=vs1.size() || j>=vs2.size())
    {
        cout <<ans <<endl;
        return;
    }
    if(vs1[i]==vs2[j])
    {
        if(!ans.empty())    ans += " ";
        ans += vs1[i];
        solve_str(i+1,j+1);
    }
    else
    {
        if(dp[i+1][j]>dp[i][j+1])   solve_str(i+1,j);
        else    solve_str(i,j+1);
    }
}

int main()
{
    char str[35];
    while(1)
    {
        memset(dp,-1,sizeof(dp));
        vs1.clear();
        vs2.clear();
        ans.clear();
        while(scanf("%s",str)==1 && str[0]!='#')    vs1.push_back((string)str);
        if(vs1.size()==0)   break;
        while(scanf("%s",str)==1 && str[0]!='#')    vs2.push_back((string)str);
        solve_dp(0,0);
        solve_str(0,0);
    }
    return  0;
}
