#include<bits/stdc++.h>
using namespace std;

#define MX 35
#define pii pair<int,int>
#define ppi pair<int,pii>

int fx[] = {1,-1,0,0,0,0};
int fy[] = {0,0,1,-1,0,0};
int fz[] = {0,0,0,0,1,-1};
int a[MX][MX][MX],visited[MX][MX][MX],x,y,z,sx,sy,sz,ex,ey,ez;

bool bfs()
{
    ppi p;
    queue<ppi>q;
    visited[sx][sy][sz] = 1;
    q.push(make_pair(sx,make_pair(sy,sz)));
    while(!q.empty())
    {
        p = q.front();
        q.pop();
        int u = p.first;
        int v = p.second.first;
        int w = p.second.second;
        if(u==ex && v==ey && w==ez)  return true;
        for(int i=0; i<6; i++)
        {
            int dx = u+fx[i];
            int dy = v+fy[i];
            int dz = w+fz[i];
            if(dx>=0 && dx<x && dy>=0 && dy<y && dz>=0 && dz<z && visited[dx][dy][dz]==0 && a[dx][dy][dz]!=-1)
            {
                visited[dx][dy][dz] = 1;
                a[dx][dy][dz] = a[u][v][w]+1;
                q.push(make_pair(dx,make_pair(dy,dz)));
            }
        }
    }
    return false;
}

void clr()
{
    memset(a,0,sizeof(a));
    memset(visited,0,sizeof(visited));
}

int main()
{
    int i,j,k;
    char str[40];
    while(1)
    {
        scanf("%d %d %d",&x,&y,&z);
        if(!x && !y && !z)    break;
        clr();
        for(i=0; i<x; i++)
        {
            for(j=0; j<y; j++)
            {
                while(gets(str) && !str[0]);
                for(k=0; str[k]; k++)
                {
                    if(str[k]=='#')    a[i][j][k] = -1;
                    else if(str[k]=='S')
                    {
                        sx = i;
                        sy = j;
                        sz = k;
                    }
                    else if(str[k]=='E')
                    {
                        ex = i;
                        ey = j;
                        ez = k;
                    }
                }
            }
        }
        if(bfs())   printf("Escaped in %d minute(s).\n",a[ex][ey][ez]);
        else    printf("Trapped!\n");
    }
    return  0;
}
