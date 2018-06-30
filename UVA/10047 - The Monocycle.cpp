#include<bits/stdc++.h>
using namespace std;

#define MX 30
int a[MX][MX],visited[MX][MX][MX][MX],level[MX][MX][MX][MX],n,m,ex,ey,ec,ans;  /** x,y,direction,color */
int fx[] = {1,0,-1,0};
int fy[] = {0,-1,0,1};
string direction[] = {"up","down","left","right"};  /** north,south,west,east */
string color[] = {"green","black","red","blue","white"};
struct node
{
    int x,y,d,c;
};

bool bfs(int sx,int sy,int d,int c)
{
    node nd;
    queue<node>q;
    nd.x = sx;
    nd.y = sy;
    nd.d = d;
    nd.c = c;
    q.push(nd);
    level[sx][sy][d][c] = 0;
    visited[sx][sy][d][c] = 1;
    while(!q.empty())
    {
        nd = q.front();
        q.pop();
        sx = nd.x;
        sy = nd.y;
        d = nd.d;
        c = nd.c;
        if(ex==sx && ey==sy && ec==c)
        {
            ans = level[sx][sy][d][c];
            return true;
        }
        /** can only move forward */
        if(d==0)
        {
            nd.x = sx-1;
            nd.y = sy;
        }
        else if(d==1)
        {
            nd.x = sx+1;
            nd.y = sy;
        }
        else if(d==2)
        {
            nd.x = sx;
            nd.y = sy-1;
        }
        else
        {
            nd.x = sx;
            nd.y = sy+1;
        }
        nd.d = d;
        nd.c = (c+1)%5;
        if(nd.x>=0 && nd.x<n && nd.y>=0 && nd.y<m && visited[nd.x][nd.y][nd.d][nd.c]==0 && a[nd.x][nd.y]==1)
        {
            q.push(nd);
            visited[nd.x][nd.y][nd.d][nd.c] = 1;
            level[nd.x][nd.y][nd.d][nd.c] = level[sx][sy][d][c]+1;
        }
        /** can turns 90 degree left or right */
        nd.x = sx;
        nd.y = sy;
        nd.c = c;
        if(d==0 || d==1)
        {
            nd.d = 2;
            if(nd.x>=0 && nd.x<n && nd.y>=0 && nd.y<m && visited[nd.x][nd.y][nd.d][nd.c]==0 && a[nd.x][nd.y]==1)
            {
                q.push(nd);
                visited[nd.x][nd.y][nd.d][nd.c] = 1;
                level[nd.x][nd.y][nd.d][nd.c] = level[sx][sy][d][c]+1;
            }
            nd.d = 3;
            if(nd.x>=0 && nd.x<n && nd.y>=0 && nd.y<m && visited[nd.x][nd.y][nd.d][nd.c]==0 && a[nd.x][nd.y]==1)
            {
                q.push(nd);
                visited[nd.x][nd.y][nd.d][nd.c] = 1;
                level[nd.x][nd.y][nd.d][nd.c] = level[sx][sy][d][c]+1;
            }
        }
        else if(d==2 || d==3)
        {
            nd.d = 0;
            if(nd.x>=0 && nd.x<n && nd.y>=0 && nd.y<m && visited[nd.x][nd.y][nd.d][nd.c]==0 && a[nd.x][nd.y]==1)
            {
                q.push(nd);
                visited[nd.x][nd.y][nd.d][nd.c] = 1;
                level[nd.x][nd.y][nd.d][nd.c] = level[sx][sy][d][c]+1;
            }
            nd.d = 1;
            if(nd.x>=0 && nd.x<n && nd.y>=0 && nd.y<m && visited[nd.x][nd.y][nd.d][nd.c]==0 && a[nd.x][nd.y]==1)
            {
                q.push(nd);
                visited[nd.x][nd.y][nd.d][nd.c] = 1;
                level[nd.x][nd.y][nd.d][nd.c] = level[sx][sy][d][c]+1;
            }
        }
    }
    return  false;
}

void clr()
{
    ec = 0;
    memset(a,0,sizeof(a));
    memset(visited,0,sizeof(visited));
    memset(level,0,sizeof(level));
}

int main()
{
    int i,j,cs=0,sx,sy;
    char s[30];
    while(1)
    {
        scanf("%d %d",&n,&m);
        if(!n && !m)    break;
        if(cs)  puts("");
        cs++;
        clr();
        for(i=0; i<n; i++)
        {
            while(gets(s) && !s[0]);
            for(j=0; s[j]; j++)
            {
                if(s[j]=='#')   a[i][j] = -1;
                else if(s[j]=='S')
                {
                    sx = i;
                    sy = j;
                    a[i][j] = 1;
                }
                else if(s[j]=='T')
                {
                    ex = i;
                    ey = j;
                    a[i][j] = 1;
                }
                else    a[i][j] = 1;
            }
        }
        printf("Case #%d\n",cs);
        if(!bfs(sx,sy,0,0))  puts("destination not reachable");
        else    printf("minimum time = %d sec\n",ans);
    }
    return 0;
}
