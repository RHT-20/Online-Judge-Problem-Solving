#include<bits/stdc++.h>
using namespace std;

#define MX 100005
vector<int>v[MX];
int visited[MX],level[MX];

void bfs(int s)
{
    queue<int>q;
    q.push(s);
    level[s] = 0;
    while(!q.empty())
    {
        s = q.front();
        q.pop();
        visited[s] = 1;
        for(int i=0; i<v[s].size(); i++)
        {
            if(visited[v[s][i]]==0)
            {
                q.push(v[s][i]);
                visited[v[s][i]] = 1;
                level[v[s][i]] = level[s]+1;
            }
        }
    }
}

int main()
{
    int n,x,y,i,cs=0;
    while(scanf("%d",&n)!=EOF)
    {
        while(n--)
        {
            scanf("%d",&x);
            v[1].push_back(x);
            v[x].push_back(1);
        }
        for(i=2; i<20; i++)
        {
            scanf("%d",&n);
            while(n--)
            {
                scanf("%d",&x);
                v[i].push_back(x);
                v[x].push_back(i);
            }
        }
        cs++;
        printf("Test Set #%d\n",cs);
        scanf("%d",&n);
        while(n--)
        {
            scanf("%d %d",&x,&y);
            printf("%2d to %2d: ",x,y);
            if(x==y)    printf("0\n");
            else
            {
                bfs(x);
                printf("%d\n",level[y]);
            }
            memset(visited,0,sizeof(visited));
            memset(level,0,sizeof(level));
        }
        for(i=0; i<22; i++) v[i].clear();
        puts("");
    }
    return 0;
}
