#include<bits/stdc++.h>
using namespace std;

#define MX 105
#define pii pair<int,int>
#define pdd pair<double,double>
#define ppi pair<pii,double>
vector<ppi>edge;
vector<pdd>temp;
int parent[MX],n;
double sum;

double dist(pdd a,pdd b)
{
    return  sqrt(((a.first-b.first)*(a.first-b.first))+((a.second-b.second)*(a.second-b.second)));
}

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
    double w;
    sum = 0.0;
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
    temp.clear();
    for(int i=0; i<MX; i++) parent[i] = i;
}

int main()
{
    int t,i,j,f=0;
    double w;
    pdd pd;
    scanf("%d",&t);
    while(t--)
    {
        if(f)   puts("");
        f = 1;
        clr();
        scanf("%d",&n);
        for(i=0; i<n; i++)
        {
            scanf("%lf %lf",&pd.first,&pd.second);
            temp.push_back(pd);
            for(j=0; j<i; j++)
            {
                w = dist(temp[i],temp[j]);
                edge.push_back(ppi(pii(j,i),w));
            }
        }
        sort(edge.begin(),edge.end(),comapre);
        kruskal();
        printf("%0.2lf\n",sum);
    }
    return  0;
}
