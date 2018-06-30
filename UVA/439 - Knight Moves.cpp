#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define MX 20
int visited[MX][MX],level[MX][MX],row,column;
int fx[] = {2,2,-2,-2,1,-1,1,-1};
int fy[] = {1,-1,1,-1,2,2,-2,-2};

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
        for(int i=0; i<8; i++)
        {
            r = s.first+fx[i];
            c = s.second+fy[i];
            if(r>0 && r<=row && c>0 && c<=column && visited[r][c]==0)
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
    char c1,c2;
    int r1,r2,c,e;
    while(scanf("%c%d %c%d",&c1,&r1,&c2,&r2)!=EOF)
    {
        c = c1-96;
        e = c2-96;
        row = 8;
        column = 8;
        bfs(r1,c);
        printf("To get from %c%d to %c%d takes %d knight moves.\n",c1,r1,c2,r2,level[r2][e]);
        memset(level,0,sizeof(level));
        memset(visited,0,sizeof(visited));
        getchar();
    }
    return 0;
}
