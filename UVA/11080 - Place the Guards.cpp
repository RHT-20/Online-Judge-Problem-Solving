#include<bits/stdc++.h>
using namespace std;

#define MX 205
vector<int>v[MX];
int visited[MX],c[MX],zero,one,ans;

bool bfs(int s)
{
    queue<int>q;
    visited[s] = 1;
    c[s] = 0;
    zero++;
    q.push(s);
    while(!q.empty())
    {
        s = q.front();
        q.pop();
        for(int i=0; i<v[s].size(); i++)
        {
            if(visited[v[s][i]]==0)
            {
                visited[v[s][i]] = 1;
                c[v[s][i]] = c[s]^1;
                q.push(v[s][i]);
                if(c[v[s][i]]==0)   zero++;
                else    one++;
            }
            else if(c[v[s][i]]==c[s])   return  false;
        }
    }
    if(one==0 && zero!=0)   ans += zero;
    else if(one!=0 && zero==0)  ans += one;
    else    ans += min(one,zero);
    return  true;
}

void clr()
{
    for(int i=0; i<MX; i++) v[i].clear();
    memset(visited,0,sizeof(visited));
    memset(c,0,sizeof(c));
    ans = zero = one = 0;
}

int main()
{
    int t,n,m,i,x,y,f;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        clr();
        for(i=0; i<m; i++)
        {
            scanf("%d %d",&x,&y);
            v[x].push_back(y);
            v[y].push_back(x);
        }
        f = 0;
        for(i=0; i<n; i++)
        {
            if(visited[i]==0)
            {
                zero = one = 0;
                if(!bfs(i))
                {
                    f = 1;
                    break;
                }
            }
        }
        if(f)   printf("-1\n");
        else    printf("%d\n",ans);
    }
    return  0;
}
