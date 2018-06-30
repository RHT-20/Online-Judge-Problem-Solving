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
    if(str[i]==str[j])  res = 1+(i!=j)+solve(i+1,j-1);
    else    res = max(solve(i+1,j),solve(i,j-1));
    return  dp[i][j] = res;
}

void get_str(int l)
{
    string res="",temp="";
    int i,s,e,p,q,c=0,x;
    s = 0;
    e = str.size()-1;
    for(i='a'; i<='z'; i++)
    {
        if(c==l)    break;
        p = s;
        q = e;
        while(p<str.size())
        {
            if(str[p]==i)   break;
            p++;
        }
        while(q>=0)
        {
            if(str[q]==i)   break;
            q--;
        }
        if(p>q) continue;
        x = l-c;
        if(dp[p][q]==x)
        {
            res += i;
            s = p+1;
            e = q-1;
            i = 'a'-1;
            c = c+1+(p!=q);
        }
    }
    temp = res;
    reverse(temp.begin(),temp.end());
    if(l%2) temp = temp.substr(1,temp.size());
    res += temp;
    cout << res << endl;
}

int main()
{
    int l;
    while(cin>>str)
    {
        memset(dp,-1,sizeof(dp));
        l = solve(0,str.size()-1);
        get_str(l);
    }
    return  0;
}
