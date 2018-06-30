#include<bits/stdc++.h>
using namespace std;

#define MX 2005
vector<int>v[MX],rev[MX];
stack<int>top;
int visited[MX];

void dfs1(int s)
{
    visited[s] = 1;
    for(int i=0; i<v[s].size(); i++)
    {
        if(visited[v[s][i]]==0) dfs1(v[s][i]);
    }
    top.push(s);
}

void dfs2(int s)
{
    visited[s] = 1;
    for(int i=0; i<rev[s].size(); i++)
    {
        if(visited[rev[s][i]]==0) dfs2(rev[s][i]);
    }
}

void clr()
{
    memset(visited,0,sizeof(visited));
    for(int i=0; i<MX; i++)
    {
        v[i].clear();
        rev[i].clear();
    }
}

int main()
{
    int n,m,i,x,y,p;
    while(1)
    {
        scanf("%d %d",&n,&m);
        if(!n && !m)    break;
        clr();
        for(i=0; i<m; i++)
        {
            scanf("%d %d %d",&x,&y,&p);
            v[x].push_back(y);
            rev[y].push_back(x);
            if(p==2)
            {
                v[y].push_back(x);
                rev[x].push_back(y);
            }
        }
        p = 0;
        for(i=1; i<=n; i++)
        {
            if(visited[i]==0)
            {
                p++;
                dfs1(i);
            }
            if(p>1) break;
        }
        if(p>1) puts("0");
        else
        {
            p = 0;
            memset(visited,0,sizeof(visited));
            while(!top.empty())
            {
                if(visited[top.top()]==0)
                {
                    dfs2(top.top());
                    p++;
                }
                top.pop();
            }
            if(p>1) puts("0");
            else    puts("1");
        }
    }
    return 0;
}

