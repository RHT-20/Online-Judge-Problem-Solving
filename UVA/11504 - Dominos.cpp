#include<bits/stdc++.h>
using namespace std;

#define MX 100005
vector<int>v[MX];
int visited[MX];
stack<int>stk;

void topsort(int s,int k)
{
    visited[s] = 1;
    for(int i=0; i<v[s].size(); i++)
    {
        if(visited[v[s][i]]==0) topsort(v[s][i],k);
    }
    if(k)    stk.push(s);
}

void clr()
{
    for(int i=0; i<MX; i++) v[i].clear();
    memset(visited,0,sizeof(visited));
}

int main()
{
    int t,i,x,y,n,m;
    scanf("%d",&t);
    while(t--)
    {
        clr();
        scanf("%d %d",&n,&m);
        for(i=0; i<m; i++)
        {
            scanf("%d %d",&x,&y);
            v[x].push_back(y);
        }
        for(i=1; i<=n; i++) if(visited[i]==0)   topsort(i,1);
        memset(visited,0,sizeof(visited));
        x = 0;
        while(!stk.empty())
        {
            if(visited[stk.top()]==0)
            {
                x++;
                topsort(stk.top(),0);
            }
            stk.pop();
        }
        printf("%d\n",x);
    }
    return 0;
}
