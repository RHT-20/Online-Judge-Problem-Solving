#include<bits/stdc++.h>
using namespace std;

#define MX 10005
#define IMX 2147483647000
struct node
{
    int x,y;
    long long c;
};
vector<node>v;
long long dist[MX][2];

void solve(int s,int k)
{
    int f;
    dist[s][k] = 0;
    while(1)
    {
        f = 0;
        for(int i=0; i<v.size(); i++)
        {
            if(k==0)
            {
                if((dist[v[i].x][k]+v[i].c)<dist[v[i].y][k])
                {
                    dist[v[i].y][k] = dist[v[i].x][k]+v[i].c;
                    f = 1;
                }
            }
            else
            {
                if((dist[v[i].y][k]+v[i].c)<dist[v[i].x][k])
                {
                    dist[v[i].x][k] = dist[v[i].y][k]+v[i].c;
                    f = 1;
                }
            }
        }
        if(f==0)    break;
    }
}

int main()
{
    int t,cs=0,x,y,i,n,m,s,e;
    long long w,p,ans;
    node nd;
    scanf("%d",&t);
    while(t--)
    {
        cs++;
        ans = -1;
        v.clear();
        for(i=0; i<MX; i++)  fill(dist[i],dist[i]+2,IMX);
        scanf("%d %d %d %d %lld",&n,&m,&s,&e,&p);
        for(i=0; i<m; i++)
        {
            scanf("%d %d %lld",&x,&y,&w);
            nd.x = x;
            nd.y = y;
            nd.c = w;
            v.push_back(nd);
        }
        solve(s,0);
        solve(e,1);
        for(i=0; i<v.size(); i++)
        {
            if((dist[v[i].x][0]+dist[v[i].y][1]+v[i].c)<=p)  ans = max(ans,v[i].c);
        }
        printf("%lld\n",ans);
    }
    return  0;
}
