#include<bits/stdc++.h>
using namespace std;

#define MX  105
vector<int>v[MX];
int visited[MX],ans,accessible[MX];

void dfs(int s)
{
    visited[s] = 1;
    for(int i=0; i<v[s].size(); i++)
    {
        if(visited[v[s][i]]==0)
        {
            accessible[v[s][i]] = 1;
            ans++;
            dfs(v[s][i]);
        }
        else if(visited[v[s][i]] && accessible[v[s][i]]==0)
        {
            accessible[v[s][i]] = 1;
            ans++;
        }
    }
}

int main()
{
    int i,x,y,n;
    while(1)
    {
        for(i=0; i<MX; i++) v[i].clear();
        scanf("%d",&n);
        if(n==0)    break;
        while(1)
        {
            scanf("%d",&x);
            if(x==0)    break;
            while(1)
            {
                scanf("%d",&y);
                if(y==0)    break;
                v[x].push_back(y);
            }
        }
        scanf("%d",&x);
        for(i=0; i<x; i++)
        {
            scanf("%d",&y);
            ans = 0;
            memset(visited,0,sizeof(visited));
            memset(accessible,0,sizeof(accessible));
            dfs(y);
            ans = n-ans;
            printf("%d",ans);
            for(int j=1; j<=n; j++) if(accessible[j]==0)  printf(" %d",j);
            puts("");
        }
    }
    return 0;
}
