#include<bits/stdc++.h>
using namespace std;

#define MX 200005
#define pii pair<int,int>
#define ppi pair<pii,long long>
vector<ppi>edge;
int parent[MX],n;
long long sum;

bool comapre(ppi a,ppi b)
{
    return  (a.second<b.second);
}

int find_p(int x)
{
    if(parent[x]==x)    return  x;
    else    return  parent[x] = find_p(parent[x]);
}

void kruskal()
{
    int x,y,p,q,taken=0;
    long long w;
    sum = 0;
    for(int i=0; i<edge.size(); i++)
    {
        x = edge[i].first.first;
        y = edge[i].first.second;
        w = edge[i].second;
        p = find_p(x);
        q = find_p(y);
        if(p!=q)
        {
            parent[q] = p;
            taken++;
            sum += w;
            if(taken==(n-1))    break;
        }
    }
}

void clr()
{
    edge.clear();
    for(int i=0; i<MX; i++) parent[i] = i;
}

int main()
{
    int m,i,x,y;
    long long w,res;
    while(1)
    {
        clr();
        scanf("%d %d",&n,&m);
        if(!n && !m)    break;
        res = 0;
        for(i=0; i<m; i++)
        {
            scanf("%d %d %lld",&x,&y,&w);
            edge.push_back(ppi(pii(x,y),w));
            res += w;
        }
        sort(edge.begin(),edge.end(),comapre);
        kruskal();
        printf("%lld\n",abs(sum-res));
    }
    return  0;
}
