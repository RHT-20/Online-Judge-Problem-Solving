#include<bits/stdc++.h>
using namespace std;

#define MX 105
#define pii pair<int,int>
vector<int>v[MX];
pii dist[MX];

pii solve(int s)
{
    if(dist[s].first!=-1)   return  dist[s];
    pii p;
    int mx=0,d=0,pos=INT_MAX;
    for(int i=0; i<v[s].size(); i++)
    {
        p = solve(v[s][i]);
        d = p.first+1;
        if(d>mx)
        {
            mx = d;
            pos = p.second;
        }
        else if(d==mx && p.second<pos)  pos = p.second;
    }
    if(pos==INT_MAX)    pos = s;
    dist[s] = pii(mx,pos);
    return  dist[s];
}

int main()
{
    int n,cs=0,i,s,x,y;
    while(1)
    {
        if(cs)  puts("");
        cs++;
        for(i=0; i<MX; i++) v[i].clear();
        memset(dist,-1,sizeof(dist));
        scanf("%d",&n);
        if(!n)  break;
        scanf("%d",&s);
        while(1)
        {
            scanf("%d %d",&x,&y);
            if(!x && !y)    break;
            v[x].push_back(y);
        }
        printf("Case %d: The longest path from %d has length %d, finishing at %d.\n",cs,s,solve(s).first,solve(s).second);
    }
    return  0;
}
