#include<bits/stdc++.h>
using namespace std;

#define MX 1005
string str;
int dp[MX][MX];

int solve(int i,int j)
{
    if(i>j) return  0;
    else if(dp[i][j]!=-1)   return  dp[i][j];
    int res=0;
    if(str[i]==str[j])  res = solve(i+1,j-1);
    else    res = 1+min(solve(i+1,j),solve(i,j-1));
    return  dp[i][j] = res;
}

void make_str(int l)
{
    string res="",ans="";
    int i,j,temp;
    i = 0;
    j = str.size()-1;
    temp = l;
    while(1)
    {
        if(!l || i>j) break;
        else if(i==j)
        {
            res += str[i];
            break;
        }
        else if(str[i]==str[j])
        {
            res += str[i];
            i++;
            j--;
            l -= 2;
        }
        else
        {
            if(dp[i][j]==dp[i+1][j]+1)
            {
                res += str[i];
                i++;
                l -= 2;
            }
            else if(dp[i][j]==dp[i][j-1]+1)
            {
                res += str[j];
                j--;
                l -= 2;
            }
        }
    }
    ans = res;
    reverse(ans.begin(),ans.end());
    if(temp%2)  ans = ans.substr(1,ans.size());
    res += ans;
    cout << res << endl;
}

int main()
{
    int l;
    while(cin>>str)
    {
        memset(dp,-1,sizeof(dp));
        l = solve(0,str.size()-1);
        printf("%d ",l);
        l += str.size();
        make_str(l);
    }
    return  0;
}
