#include<bits/stdc++.h>
using namespace std;

#define pdd pair<double,double>
#define pii pair<int,int>
vector<pair<double,pii> >edge;
vector<pdd>outpost;
int parent[505],satellite;

double dist(int i,int j)
{
    double x = sqrt(((outpost[i].first-outpost[j].first)*(outpost[i].first-outpost[j].first))+((outpost[i].second-outpost[j].second)*(outpost[i].second-outpost[j].second)));
    return  x;
}

void setparent(int p)
{
    outpost.clear();
    edge.clear();
    memset(parent,0,sizeof(parent));
    for(int i=0; i<=p; i++)
    {
        parent[i] = i;
    }
    satellite = p;
}

int find(int x)
{
    if(parent[x]==x)    return  x;
    else    return  parent[x] = find(parent[x]);
}

void setunion(int i,int j)
{
    int x = find(i);
    int y = find(j);
    if(x==y)    return;
    else
    {
        parent[x] = y;
        satellite--;
    }
}

int main()
{
    int t,s,p,i,j,x,y;
    double ans,u,v;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&s,&p);
        setparent(p);
        for(i=0; i<p; i++)
        {
            scanf("%lf %lf",&u,&v);
            outpost.push_back(pdd(u,v));
        }
        for(i=0; i<outpost.size(); i++)
        {
            for(j=i+1; j<p; j++)
            {
                ans = dist(i,j);
                edge.push_back(make_pair(ans,pii(i,j)));
            }
        }
        sort(edge.begin(),edge.end());
        pair<double,pii> temp;
        ans = 0.0;
        for(i=0; i<edge.size(); i++)
        {
            if(satellite==s)    break;
            temp = edge[i];
            x = find(temp.second.first);
            y = find(temp.second.second);
            if(x!=y)
            {
                setunion(temp.second.first,temp.second.second);
                ans = temp.first;
            }
        }
        printf("%0.2lf\n",ans);
    }
    return 0;
}
