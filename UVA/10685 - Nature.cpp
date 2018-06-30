#include<bits/stdc++.h>
using namespace std;

struct node
{
    int p,d;
};

int Find(node g[],int a)
{
    if(g[a].p==a) return  a;
    else    return  g[a].p = Find(g,g[a].p);
}

void Union(node g[],int n,int a,int b)
{
    int x,y;
    x = Find(g,a);
    y = Find(g,b);
    if(x==y)    return;
    else
    {
        if(g[x].d>g[y].d)
        {
            g[y].p = x;
            g[x].d += g[y].d;
        }
        else
        {
            g[x].p = y;
            g[y].d += g[x].d;
        }
    }
}

bool compare(node a,node b)
{
    return  (a.d>b.d);
}

int main()
{
    int c,r,i;
    map<string,int>mp;
    while(1)
    {
        mp.clear();
        scanf("%d %d",&c,&r);
        if(c==0 && r==0)    break;
        char a[c][35],b[35],d[35];
        node graph[c];
        for(i=0; i<c; i++)
        {
            graph[i].p = i;
            graph[i].d = 1;
        }
        for(i=0; i<c; i++)
        {
            scanf("%s",a[i]);
            mp[a[i]] = i;
        }
        for(i=0; i<r; i++)
        {
            scanf("%s %s",b,d);
            Union(graph,c,mp[b],mp[d]);
        }
        sort(graph,graph+c,compare);
        printf("%d\n",graph[0].d);
    }
    return 0;
}
