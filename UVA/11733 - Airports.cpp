#include<bits/stdc++.h>
using namespace std;

int node,edge,cnt,w;
long long sum;

struct data
{
    int u,v,w;
    bool operator < (data a)const
    {
        return  (w<a.w);
    }
};
vector<data>v;

struct nod
{
    int p;
    long long c;
};

int find(nod a[],int x)
{
    if(a[x].p==x) return  x;
    else    return  a[x].p = find(a,a[x].p);
}

void minimum_spaning_tree_kruskal_algorithm()
{
    int i,x,y,airport=0;
    long long c1,c2;
    cnt=0;
    sum = 0;
    sort(v.begin(),v.end());
    nod parent[node+1];
    for(i=1; i<=node; i++)
    {
        parent[i].p = i;
        parent[i].c = w;
    }
    for(i=0; i<v.size(); i++)
    {
        x = find(parent,v[i].u);
        y = find(parent,v[i].v);
        if(x!=y)
        {
            c1 = parent[x].c+parent[y].c;
            c2 = v[i].w+parent[x].c+parent[y].c-w;
            if(c1>c2)
            {
                parent[x].c = v[i].w+parent[x].c+parent[y].c-w;
                parent[y].p = x;
            }
            cnt++;
            if(cnt==node-1) break;
        }
    }
    cnt = 0;
    for(i=1; i<=node; i++)
    {
        x = find(parent,i);
        if(parent[x].c) cnt++;
        sum += parent[x].c;
        parent[x].c = 0;
    }
}

int main()
{
    int t,cs=0,i;
    scanf("%d",&t);
    while(t--)
    {
        cs++;
        v.clear();
        scanf("%d %d %d",&node,&edge,&w);
        data d;
        for(i=0; i<edge; i++)
        {
            scanf("%d %d %d",&d.u,&d.v,&d.w);
            v.push_back(d);
        }
        minimum_spaning_tree_kruskal_algorithm();
        printf("Case #%d: %lld %d\n",cs,sum,cnt);
    }
    return 0;
}
