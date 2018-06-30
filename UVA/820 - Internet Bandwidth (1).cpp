#include<bits/stdc++.h>
using namespace std;

#define MX 105
long long residual_Capacity[MX][MX],max_flow;
int augmented_path[MX];
bool vis[MX];
int n,m,s,t;

bool BFS()
{
    int x,i;
    queue<int>q;
    q.push(s);
    augmented_path[s] = -1;
    memset(vis,false,sizeof(vis));
    vis[s] = true;
    while(!q.empty())
    {
        x = q.front();
        q.pop();
        for(i=1; i<=n; i++)
        {
            if(!vis[i] && residual_Capacity[x][i]>0)
            {
                vis[i] = true;
                augmented_path[i] = x;
                q.push(i);
                if(i==t)    return  true;
            }
        }
    }
    return  false;
}

void augmentation()
{
    int x=t;
    long long flow=INT_MAX;
    while(1)
    {
        if(augmented_path[x]==-1)   break;
        flow = min(flow,residual_Capacity[augmented_path[x]][x]);
        x = augmented_path[x];
    }
    x = t;
    max_flow += flow;
    while(1)
    {
        if(augmented_path[x]==-1)   break;
        residual_Capacity[augmented_path[x]][x] -= flow;
        residual_Capacity[x][augmented_path[x]] += flow;
        x = augmented_path[x];
    }
}

void Ford_Fulkerson()
{
    max_flow = 0;
    while(BFS())
    {
        augmentation();
    }
}

int main()
{
    int cs=0,x,y,i;
    long long w;
    while(1)
    {
        if(cs)  puts("");
        cs++;
        memset(residual_Capacity,0,sizeof(residual_Capacity));
        scanf("%d",&n);
        if(!n)  break;
        scanf("%d %d %d",&s,&t,&m);
        for(i=0; i<m; i++)
        {
            scanf("%d %d %lld",&x,&y,&w);
            residual_Capacity[x][y] += w;
            residual_Capacity[y][x] += w;
        }
        Ford_Fulkerson();
        printf("Network %d\nThe bandwidth is %lld.\n",cs,max_flow);
    }
    return  0;
}
