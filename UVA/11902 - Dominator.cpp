#include<bits/stdc++.h>
using namespace std;

#define MX 105
vector<int>v[MX];
bool visited_check[MX],visited[MX],flag[MX][MX];
int n,skip;

void dfs_check(int s)
{
    visited_check[s] = true;
    for(int i=0; i<v[s].size(); i++)
    {
        if(visited_check[v[s][i]]==false)   dfs_check(v[s][i]);
    }
}

void dfs(int s)
{
    visited[s] = true;
    for(int i=0; i<v[s].size(); i++)
    {
        if(visited[v[s][i]]==false && skip!=v[s][i])    dfs(v[s][i]);
    }
}

void clr()
{
    for(int i=0; i<MX; i++) v[i].clear();
    memset(flag,false,sizeof(flag));
    memset(visited,false,sizeof(visited));
    memset(visited_check,false,sizeof(visited_check));
}

int main()
{
    int t,cs=0,n,i,j,x;
    scanf("%d",&t);
    while(t--)
    {
        cs++;
        clr();
        scanf("%d",&n);
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                scanf("%d",&x);
                if(x)   v[i].push_back(j);
            }
        }
        dfs_check(0);
        for(i=0; i<n; i++)
        {
            if(visited_check[i])    flag[0][i] = true;
        }
        for(i=1; i<n; i++)
        {
            memset(visited,false,sizeof(visited));
            skip = i;
            dfs(0);
            for(j=0; j<n; j++)
            {
                if(visited[j]==false && visited_check[j])
                    flag[i][j] = true;
            }
        }
        x = (2*n)-1;
        printf("Case %d:\n",cs);
        for(i=0; i<n; i++)
        {
            printf("+");
            for(j=0; j<x; j++)  printf("-");
            puts("+");
            for(j=0; j<n; j++)
            {
                printf("|");
                if(flag[i][j])  printf("Y");
                else    printf("N");
            }
            puts("|");
        }
        printf("+");
        for(j=0; j<x; j++)  printf("-");
        puts("+");
    }
    return  0;
}

