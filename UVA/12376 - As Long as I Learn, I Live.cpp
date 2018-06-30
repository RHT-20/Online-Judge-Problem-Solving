#include<bits/stdc++.h>
using namespace std;

#define MX 105
vector<int>v[MX];
long long g[MX],learn[MX],ans;
int n,pos,visited[MX];

void bfs()
{
    int s=0,f;
    queue<int>q;
    learn[s] = 0;
    q.push(s);
    while(!q.empty())
    {
        s = q.front();
        q.pop();
        visited[s] = 1;
        ans = INT_MIN;
        f = 0;
        for(int i=0; i<v[s].size(); i++)
        {
            if(visited[v[s][i]]==0)
            {
                f = 1;
                if(ans<g[v[s][i]])
                {
                    ans = g[v[s][i]];
                    pos = v[s][i];
                }
            }
        }
        if(f)
        {
            learn[pos] = learn[s]+ans;
            q.push(pos);
            visited[pos] = 1;
        }
    }
    ans = INT_MIN;
    pos = 0;
    for(int i=0; i<n; i++)
    {
        if(ans<learn[i])
        {
            ans = learn[i];
            pos = i;
        }
    }
}

void clr()
{
    for(int i=0; i<MX; i++) v[i].clear();
    memset(g,0,sizeof(g));
    memset(visited,0,sizeof(visited));
    memset(learn,0,sizeof(learn));
}

int main()
{
    int t,cs=0,m,x,y,i;
    scanf("%d",&t);
    while(t--)
    {
        cs++;
        scanf("%d %d",&n,&m);
        clr();
        for(i=0; i<n; i++)  scanf("%lld",&g[i]);
        for(i=0; i<m; i++)
        {
            scanf("%d %d",&x,&y);
            v[x].push_back(y);
        }
        bfs();
        printf("Case %d: %lld %d\n",cs,ans,pos);
    }
    return 0;
}
