#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define MX 1005
int a[MX][MX];
int visited[MX][MX],level[MX][MX],row,column;
int fx[] = {1,0,-1,0};
int fy[] = {0,-1,0,1};

void bfs(int r,int c)
{
    queue<pii>q;
    q.push(pii(r,c));
    level[r][c] = 0;
    while(!q.empty())
    {
        pii s = q.front();
        q.pop();
        r = s.first;
        c = s.second;
        visited[r][c] = 1;
        for(int i=0; i<4; i++)
        {
            r = s.first+fx[i];
            c = s.second+fy[i];
            if(r>=0 && r<=row && c>=0 && c<=column && visited[r][c]==0 && a[r][c]==0)
            {
                q.push(pii(r,c));
                visited[r][c] = 1;
                level[r][c] = level[s.first][s.second]+1;
            }
        }
    }
}

int main()
{
    int n,r,c,m,s,e;
    while(1)
    {
        scanf("%d %d",&row,&column);
        if(row==0 && column==0)    break;
        scanf("%d",&n);
        while(n--)
        {
            scanf("%d %d",&r,&m);
            while(m--)
            {
                scanf("%d",&c);
                a[r][c] = 1;
            }
        }
        scanf("%d %d %d %d",&r,&c,&s,&e);
        bfs(r,c);
        printf("%d\n",level[s][e]);
        memset(a,0,sizeof(a));
        memset(visited,0,sizeof(visited));
        memset(level,0,sizeof(level));
    }
    return 0;
}
