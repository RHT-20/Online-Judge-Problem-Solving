#include<bits/stdc++.h>
using namespace std;

#define MX 105
vector<int>v[MX];
int visited[MX];

int bfs(int s)
{
    int d=0;
    queue<int>q;
    q.push(s);
    while(!q.empty())
    {
        s = q.front();
        q.pop();
        visited[s] = 1;
        for(int i=0; i<v[s].size(); i++)
        {
            if(visited[v[s][i]]==0)
            {
                d++;
                visited[v[s][i]] = 1;
                q.push(v[s][i]);
            }
        }
    }
    return  d;
}

void clr()
{
    for(int i=0; i<MX; i++) v[i].clear();
    memset(visited,0,sizeof(visited));
}

int main()
{
    int i,j,k,n,x,mx,pos;
    while(1)
    {
        clr();
        scanf("%d",&n);
        if(!n)  break;
        for(i=1; i<=n; i++)
        {
            scanf("%d",&k);
            for(j=0; j<k; j++)
            {
                scanf("%d",&x);
                v[i].push_back(x);
            }
        }
        mx = -1;
        pos = 0;
        for(i=1; i<=n; i++)
        {
            memset(visited,0,sizeof(visited));
            x = bfs(i);
            if(x>mx)
            {
                mx = x;
                pos = i;
            }
        }
        printf("%d\n",pos);
    }
    return  0;
}
