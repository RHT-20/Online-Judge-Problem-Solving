#include<bits/stdc++.h>
using namespace std;

#define MX 10000
int movement[8][4] = {{1,0,0,0},{-1,0,0,0},{0,1,0,0},{0,-1,0,0},{0,0,1,0},{0,0,-1,0},{0,0,0,1},{0,0,0,-1}};
int visited[MX],dist[MX];
int source,dest,temp;

int cal(int x,int i)
{
    int t1 = x%10;
    x /= 10;
    int t2 = x%10;
    x /= 10;
    int t3 = x%10;
    x /= 10;
    int t4 = x;
    x = 0;
    t1 += movement[i][3];
    if(t1<0)    t1 = 9;
    else if(t1>9)   t1 = 0;
    t2 += movement[i][2];
    if(t2<0)    t2 = 9;
    else if(t2>9)   t2 = 0;
    t3 += movement[i][1];
    if(t3<0)    t3 = 9;
    else if(t3>9)   t3 = 0;
    t4 += movement[i][0];
    if(t4<0)    t4 = 9;
    else if(t4>9)   t4 = 0;
    x = (t4*1000)+(t3*100)+(t2*10)+t1;
    return  x;
}

bool bfs()
{
    queue<int>q;
    dist[source] = 0;
    visited[source] = 1;
    q.push(source);
    while(!q.empty())
    {
        source = q.front();
        q.pop();
        if(source==dest)    return  true;
        for(int i=0; i<8; i++)
        {
            temp = source;
            temp = cal(temp,i);
            if(visited[temp]==0)
            {
                visited[temp] = 1;
                dist[temp] = dist[source]+1;
                q.push(temp);
            }
        }
    }
    return  false;
}

void clr()
{
    memset(visited,0,sizeof(visited));
    memset(dist,0,sizeof(dist));
    source = 0;
    dest = 0;
}

int main()
{
    int t,i,j,x,n;
    scanf("%d",&t);
    while(t--)
    {
        clr();
        for(i=0; i<4; i++)
        {
            scanf("%d",&x);
            source = (source*10)+x;
        }
        for(i=0; i<4; i++)
        {
            scanf("%d",&x);
            dest = (dest*10)+x;
        }
        scanf("%d",&n);
        for(i=0; i<n; i++)
        {
            temp = 0;
            for(j=0; j<4; j++)
            {
                scanf("%d",&x);
                temp = (temp*10)+x;
            }
            visited[temp] = 1;
        }
        if(bfs())   printf("%d\n",dist[dest]);
        else    printf("-1\n");
    }
    return  0;
}

