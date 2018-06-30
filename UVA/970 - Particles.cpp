#include<bits/stdc++.h>
using namespace std;

int w[5][5] = {{1,0,2},{0,1,1},{2,1,0}};
bool dp[105][105][5];
int visited[105][105][5],a[105],c;

bool solve(int b,int e,int id)
{
    if(b==e)    return  (id==a[b]);
    else if(e==(b+1))   return  (w[a[b]][a[e]]==id);
    else if(visited[b][e][id]==c)   return  dp[b][e][id];
    visited[b][e][id] = c;
    bool res=false;
    if(id==2)
    {
        for(int i=b; i<e; i++)
        {
            if(solve(b,i,0) && solve(i+1,e,2))  res = true;
            else if(solve(b,i,2) && solve(i+1,e,0)) res = true;
            if(res) break;
        }
    }
    else if(id==1)
    {
        for(int i=b; i<e; i++)
        {
            if(solve(b,i,0) && solve(i+1,e,0))  res = true;
            else if(solve(b,i,1) && solve(i+1,e,1))  res = true;
            else if(solve(b,i,1) && solve(i+1,e,2))  res = true;
            else if(solve(b,i,2) && solve(i+1,e,1))  res = true;
            if(res) break;
        }
    }
    else
    {
        for(int i=b; i<e; i++)
        {
            if(solve(b,i,0) && solve(i+1,e,1))  res = true;
            else if(solve(b,i,1) && solve(i+1,e,0))  res = true;
            else if(solve(b,i,2) && solve(i+1,e,2))  res = true;
            if(res) break;
        }
    }
    return  dp[b][e][id] = res;
}

int main()
{
    int t,i;
    string str;
    scanf("%d",&t);
    while(t--)
    {
        c++;
        cin >> str;
        memset(a,0,sizeof(a));
        memset(dp,false,sizeof(dp));
        for(i=0; i<str.size(); i++) a[i] = (int)str[i]-88;
        if(solve(0,str.size()-1,2)) puts("Z");
        else if(solve(0,str.size()-1,1))    puts("Y");
        else    puts("X");
    }
    return  0;
}

