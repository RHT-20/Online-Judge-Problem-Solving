#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
int fx[] = {1,-1,0,0,-1,-1,1,1};
int fy[] = {0,0,1,-1,-1,1,-1,1};
int a[30][30],visited[30][30],n;

void bfs(int x,int y)
{
    pii p;
    queue<pii>q;
    visited[x][y] = 1;
    q.push(make_pair(x,y));
    while(!q.empty())
    {
        p = q.front();
        q.pop();
        for(int i=0; i<8; i++)
        {
            x = p.first+fx[i];
            y = p.second+fy[i];
            if(x>=0 && x<n && y>=0 && y<n && a[x][y] && visited[x][y]==0)
            {
                visited[x][y] = 1;
                q.push(make_pair(x,y));
            }
        }
    }
}

int main()
{
    int i,j,cs=0,c;
    while(scanf("%d",&n)==1)
    {
        cs++;
        c = 0;
        memset(a,0,sizeof(a));
        memset(visited,0,sizeof(visited));
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                scanf("%1d",&a[i][j]);
            }
        }
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                if(a[i][j] && visited[i][j]==0)
                {
                    c++;
                    bfs(i,j);
                }
            }
        }
        printf("Image number %d contains %d war eagles.\n",cs,c);
    }
    return  0;
}
