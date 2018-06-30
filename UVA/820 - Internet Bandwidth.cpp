#include<bits/stdc++.h>
using namespace std;

#define MX 105
struct node
{
    int x,i;
    long long cf;
    node() {}
    node(int nx,long long ncf,int ni)
    {
        x = nx;
        cf = ncf;
        i = ni;
    }
};
vector<node>v[MX];
node augmented_path[MX];
bool vis[MX];
long long max_flow;
int n,m,s,t;

bool BFS()
{
    int x,y,w,i;
    queue<int>q;
    memset(vis,false,sizeof(vis));
    q.push(s);
    augmented_path[s] = node(-1,0,0);
    while(!q.empty())
    {
        x = q.front();
        q.pop();
        vis[x] = true;
        for(i=0; i<v[x].size(); i++)
        {
            y = v[x][i].x;
            w = v[x][i].cf;
            if(!vis[y] && w>0)
            {
                q.push(y);
                vis[y] = true;
                augmented_path[y] = node(x,w,i);
                if(y==t)    return  true;
            }
        }
    }
    return  false;
}

void augmentation()
{
    int x=t,y;
    long long flow=INT_MAX;
    vector<node>temp;
    while(1)
    {
        if(augmented_path[x].x==-1) break;
        y = augmented_path[x].x;
        flow = min(flow,augmented_path[x].cf);
        temp.push_back(node(y,x,augmented_path[x].i));
        x = y;
    }
    max_flow += flow;
    for(int i=(temp.size()-1); i>=0; i--)
    {
        v[temp[i].x][temp[i].i].cf -= flow;
        v[temp[i].cf][v[temp[i].x][temp[i].i].i].cf += flow;
    }
}

void Ford_Fulkerson()
{
    max_flow = 0;
    while(BFS())
    {
        augmentation();
    }
}

void clr()
{
    for(int i=0; i<MX; i++) v[i].clear();
}

int main()
{
    int cs=0,i,j,x,y;
    long long w;
    bool f;
    while(1)
    {
        if(cs)  puts("");
        cs++;
        clr();
        scanf("%d",&n);
        if(!n)  break;
        scanf("%d %d %d",&s,&t,&m);
        for(i=0; i<m; i++)
        {
            scanf("%d %d %lld",&x,&y,&w);
            f = false;
            for(j=0; j<v[x].size(); j++)
            {
                if(v[x][j].x==y)
                {
                    v[x][j].cf += w;
                    v[y][v[x][j].i].cf += w;
                    f = true;
                }
            }
            if(!f)
            {
                v[x].push_back(node(y,w,v[y].size()));
                v[y].push_back(node(x,w,v[x].size()-1));
            }
        }
        Ford_Fulkerson();
        printf("Network %d\nThe bandwidth is %lld.\n",cs,max_flow);
    }
    return  0;
}
