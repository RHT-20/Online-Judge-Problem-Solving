#include<bits/stdc++.h>
using namespace std;

#define MX 505
#define INF 999999
#define FREE 0

vector<int>v[MX];
int match[MX],dist[MX];
int n,m,e;
char str1[MX][5],str2[MX][5];

bool BFS()
{
    queue<int>q;
    for(int i=1; i<=e; i++)
    {
        if(match[i]==FREE)
        {
            dist[i] = 0;
            q.push(i);
        }
        else    dist[i] = INF;
    }
    dist[FREE] = INF;

    while(!q.empty())
    {
        int x = q.front();
        q.pop();

        if(x!=FREE)
        {
            for(int i=0; i<(int)v[x].size(); i++)
            {
                int y = v[x][i];
                if(dist[match[y]]==INF)
                {
                    dist[match[y]] = dist[x]+1;
                    q.push(match[y]);
                }
            }
        }
    }
    return  (dist[FREE]!=INF);
}

bool DFS(int x)
{
    if(x!=FREE)
    {
        for(int i=0; i<(int)v[x].size(); i++)
        {
            int y = v[x][i];
            if(dist[match[y]]==(dist[x]+1))
            {
                if(DFS(match[y]))
                {
                    match[y] = x;
                    match[x] = y;
                    return  true;
                }
            }
        }
        dist[x] = INF;
        return  false;
    }
    return  true;
}

void HOPCROFT_KARP()
{
    int matching=0;

    while(BFS())
    {
        for(int i=1; i<=e; i++)
        {
            if(match[i]==FREE && DFS(i))    matching++;
        }
    }

    printf("%d\n",(e-matching));
    return;
}

void build()
{
    for(int i=1; i<=e; i++)
    {
        for(int j=(i+1); j<=e; j++)
        {
            if(strcmp(str1[i],str2[j])==0 || strcmp(str2[i],str1[j])==0)
            {
                v[i].push_back(j);
                v[j].push_back(i);
            }
        }
    }
    return;
}

void clr()
{
    for(int i=1; i<=e; i++) v[i].clear();
    memset(match,0,sizeof(match));
    memset(dist,0,sizeof(dist));
    return;
}

int main()
{
    int t,i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d",&n,&m,&e);
        clr();
        for(i=1; i<=e; i++) scanf("%s %s",str1[i],str2[i]);
        build();
        HOPCROFT_KARP();
    }
    return  0;
}
