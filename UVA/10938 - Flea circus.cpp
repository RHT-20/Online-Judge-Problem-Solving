#include<bits/stdc++.h>
using namespace std;

#define MX1 5005
#define MX2 30
vector<int>v[MX1];
int sparse_table[MX2][MX1];
int parent[MX1],level[MX1];
int n;

void DFS(int s)
{
    for(int i=0; i<v[s].size(); i++)
    {
        if(parent[v[s][i]]==-1 && parent[s]!=v[s][i])
        {
            level[v[s][i]] = level[s]+1;
            parent[v[s][i]] = s;
            DFS(v[s][i]);
        }
    }
    return;
}

void init()
{
    int x;
    for(int i=1; i<=n; i++) sparse_table[0][i] = parent[i];
    for(int j=1; (1<<j)<=n; j++)
    {
        for(int i=1; i<=n; i++)
        {
            x = sparse_table[j-1][i];
            if(x!=-1)   sparse_table[j][i] = sparse_table[j-1][x];
        }
    }
    return;
}

int find_lca(int x,int y)
{
    if(level[x]>level[y])   swap(x,y);  /// level[x]<level[y]
    int lg=0,t1,t2;
    while(1)
    {
        if((1<<lg)>level[y])    break;
        lg++;
    }
    lg--;
    for(int i=lg; i>=0; i--)
    {
        if((level[y]-(1<<i))>=level[x])
        {
            y = sparse_table[i][y];
        }
    }
    if(x==y)    return  x;
    for(int i=lg; i>=0; i--)
    {
        t1 = sparse_table[i][x];
        t2 = sparse_table[i][y];
        if(t1!=-1 && t1!=t2)
        {
            x = t1;
            y = t2;
        }
    }
    return  parent[x];
}

int find_parent(int x,int k)
{
    if(!k)  return  x;
    int lg=0;
    while(1)
    {
        if((1<<lg)>k)   break;
        lg++;
    }
    lg--;
    for(int i=lg; i>=0; i--)
    {
        if(sparse_table[i][x]!=-1 && (k-(1<<i))>0)
        {
            x = sparse_table[i][x];
            k -= (1<<i);
        }
    }
    return  parent[x];
}

void solve(int x,int y)
{
    int t1,t2;
    int temp = find_lca(x,y);
    int dist = level[x]+level[y]-(2*level[temp]);
    if(dist&1)
    {
        dist /= 2;
        if((level[x]-level[temp])>=dist)    t1 = find_parent(x,dist);
        else
        {
            t1 = dist-(level[x]-level[temp]);
            t1 = (level[y]-level[temp])-t1;
            t1 = find_parent(y,t1);
        }
        if((level[y]-level[temp])>=dist)    t2 = find_parent(y,dist);
        else
        {
            t2 = dist-(level[y]-level[temp]);
            t2 = (level[x]-level[temp])-t2;
            t2 = find_parent(x,t2);
        }
        printf("The fleas jump forever between %d and %d.\n",min(t1,t2),max(t1,t2));
    }
    else
    {
        dist /= 2;
        if((level[x]-level[temp])>=dist)    temp = find_parent(x,dist);
        else
        {
            t1 = dist-(level[x]-level[temp]);
            t1 = (level[y]-level[temp])-t1;
            t1 = find_parent(y,t1);
            temp = t1;
        }
        printf("The fleas meet at %d.\n",temp);
    }
    return;
}

void clr()
{
    for(int i=0; i<MX1; i++) v[i].clear();
    memset(parent,-1,sizeof(parent));
    memset(sparse_table,-1,sizeof(sparse_table));
    return;
}

int main()
{
    int i,x,y,q;
    while(1)
    {
        clr();
        scanf("%d",&n);
        if(!n)  break;
        for(i=1; i<n; i++)
        {
            scanf("%d %d",&x,&y);
            v[x].push_back(y);
            v[y].push_back(x);
        }
        DFS(1);
        init();
        scanf("%d",&q);
        while(q--)
        {
            scanf("%d %d",&x,&y);
            solve(x,y);
        }
    }
    return  0;
}
