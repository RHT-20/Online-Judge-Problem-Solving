#include<bits/stdc++.h>
using namespace std;

#define MX 100005
map<long long,int>level;
map<long long,int>visited;
map<long long,vector<long long> >mpv;

void bfs(long long s)
{
    queue<long long>q;
    q.push(s);
    level[s] = 0;
    while(!q.empty())
    {
        s = q.front();
        q.pop();
        visited[s] = 1;
        for(int i=0; i<mpv[s].size(); i++)
        {
            if(visited[mpv[s][i]]==0)
            {
                q.push(mpv[s][i]);
                visited[mpv[s][i]] = 1;
                level[mpv[s][i]] = level[s]+1;
            }
        }
    }
}

void clear_graph()
{
    map<long long,int>::iterator it;
    for(it=level.begin(); it!=level.end(); it++)
    {
        level[it->first] = 0;
    }
    for(it=visited.begin(); it!=visited.end(); it++)
    {
        visited[it->first] = 0;
    }
}

int main()
{
    int n,cs=0,z,i,ans;
    long long x,y;
    while(1)
    {
        scanf("%d",&n);
        if(n==0)    break;
        for(i=0; i<n; i++)
        {
            scanf("%lld %lld",&x,&y);
            mpv[x].push_back(y);
            mpv[y].push_back(x);
            level[x] = level[y] = visited[x] = visited[y] = 0;
        }
        while(1)
        {
            scanf("%lld %d",&x,&z);
            if(x==0 && z==0)    break;
            cs++;
            bfs(x);
            ans = 0;
            map<long long,int>::iterator it;
            for(it=level.begin(); it!=level.end(); it++)
            {
                if(it->second>z)    ans++;
            }
            for(it=visited.begin(); it!=visited.end(); it++)
            {
                if(it->second==0)    ans++;
            }
            printf("Case %d: %d nodes not reachable from node %lld with TTL = %d.\n",cs,ans,x,z);
            clear_graph();
        }
        level.clear();
        visited.clear();
        mpv.clear();
    }
    return 0;
}
