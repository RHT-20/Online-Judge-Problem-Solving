#include<bits/stdc++.h>
using namespace std;

long long a[105][105],ans;
vector<int>v;
int n;

void floyd_warshall()
{
    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++) a[i][j] = min(a[i][j],(a[i][k]+a[k][j]));
        }
    }
    for(int i=6; i<=n; i++)
    {
        if(a[1][i]==INT_MAX || a[2][i]==INT_MAX || a[3][i]==INT_MAX || a[4][i]==INT_MAX || a[5][i]==INT_MAX)    continue;
        if(a[1][i]==a[2][i] && a[2][i]==a[3][i] && a[3][i]==a[4][i] && a[4][i]==a[5][i])    v.push_back(i);
    }
    ans = INT_MAX;
    long long res;
    for(int i=0; i<v.size(); i++)
    {
        res = INT_MIN;
        for(int j=1; j<=n; j++)
        {
            if(v[i]==j) continue;
            res = max(res,a[v[i]][j]);
        }
        ans = min(res,ans);
    }
    if(ans==INT_MAX)    ans = -1;
}

void clr()
{
    for(int i=0; i<105; i++)
    {
        for(int j=0; j<105; j++)
        {
            if(i==j)    a[i][j] = 0;
            else    a[i][j] = INT_MAX;
        }
    }
    v.clear();
}

int main()
{
    int t,cs=0,m,x,y,i;
    long long w;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        cs++;
        clr();
        for(i=0; i<m; i++)
        {
            scanf("%d %d %lld",&x,&y,&w);
            a[x][y] = a[y][x] = min(a[x][y],w);
        }
        floyd_warshall();
        printf("Map %d: %lld\n",cs,ans);
    }
    return  0;
}
