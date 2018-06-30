#include<bits/stdc++.h>
using namespace std;

#define MX 105
char str[10][10] = {"XXL", "XL", "L", "M", "S", "XS"};
int residual_Capacity[MX][MX],level[MX],max_flow,n,m,s,t;
bool vis[MX];

bool BFS()
{
    memset(vis,false,sizeof(vis));
    memset(level,-1,sizeof(level));
    queue<int>q;
    q.push(s);
    vis[s] = true;
    level[s] = 0;
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        for(int i=1; i<=t; i++)
        {
            if(!vis[i] && residual_Capacity[x][i]>0)
            {
                level[i] = level[x]+1;
                vis[i] = true;
                q.push(i);
            }
        }
    }
    if(level[t]!=-1)    return  true;
    return  false;
}

int augmentation(int x,int flow)
{
    if(x==t)    return  flow;
    for(int i=1; i<=t; i++)
    {
        if(level[i]==(level[x]+1) && residual_Capacity[x][i]>0)
        {
            int current = min(flow,residual_Capacity[x][i]);
            int temp = augmentation(i,current);
            if(temp>0)
            {
                residual_Capacity[x][i] -= temp;
                residual_Capacity[i][x] += temp;
                return  temp;
            }
        }
    }
    return  0;
}

void DINIC()
{
    max_flow = 0;
    while(BFS())
    {
        int temp = augmentation(s,100);
        if(temp<=0) break;
        max_flow += temp;
    }
    if(max_flow==m) puts("YES");
    else    puts("NO");
}

void init(int w)
{
    memset(residual_Capacity,0,sizeof(residual_Capacity));
    for(int i=0; i<6; i++)
    {
        residual_Capacity[s][i+2] = w;
        residual_Capacity[i+2][s] = 0;
    }
}

int main()
{
    int ts,i,j,k,w;
    char str1[5],str2[5];
    s = 1;  /// Super source
    scanf("%d",&ts);
    while(ts--)
    {
        scanf("%d %d",&n,&m);
        w = n/6;
        init(w);
        k = 8;
        t = m+8;
        for(i=0; i<m; i++)
        {
            scanf("%s %s",str1,str2);
            for(j=0; j<6; j++)
            {
                if(strcmp(str[j],str1)==0)
                {
                    residual_Capacity[j+2][k] = 1;
                    residual_Capacity[k][t] = 1;
                    break;
                }
            }
            for(j=0; j<6; j++)
            {
                if(strcmp(str[j],str2)==0)
                {
                    residual_Capacity[j+2][k] = 1;
                    residual_Capacity[k][t] = 1;
                    break;
                }
            }
            k++;
        }
        DINIC();
    }
    return  0;
}
