#include<bits/stdc++.h>
using namespace std;

#define MX 1125
vector<int>prime;
bool mark[MX];
int dp[200][20][MX],visited[200][20][MX],cs;

void init()
{
    prime.push_back(2);
    for(int i=4; i<MX; i+=2)    mark[i] = true;
    for(int i=3; i<MX; i+=2)
    {
        if(mark[i]==false)
        {
            prime.push_back(i);
            for(int j=(i+i); j<MX; j+=i)    mark[j] = true;
        }
    }
}

int solve(int i,int k,int w)
{
    if(k==0 && w==0)    return  1;
    else if(i>=prime.size() || k==0 || w==0)    return  0;
    else if(visited[i][k][w]==cs)    return  dp[i][k][w];
    visited[i][k][w] = cs;
    int res1=0,res2=0;
    res1 = solve(i+1,k,w);
    if(prime[i]<=w) res2 = solve(i+1,k-1,w-prime[i]);
    return  dp[i][k][w] = res1+res2;
}

int main()
{
    int n,k;
    init();
    cs=0;
    while(1)
    {
        cs++;
        scanf("%d %d",&n,&k);
        if(!n && !k)    break;
        printf("%d\n",solve(0,k,n));
    }
    return  0;
}
