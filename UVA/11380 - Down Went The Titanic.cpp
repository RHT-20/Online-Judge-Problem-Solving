#include<bits/stdc++.h>
using namespace std;

#define MX 5005
#define IMX 10005

struct node
{
    int x,cf,i;
    node(){}
    node(int nx,int ncf,int ni)
    {
        x = nx;
        cf = ncf;
        i = ni;
    }
};
vector<node>v[MX];
char str[MX][MX];
bool vis[MX];
int level[MX],max_flow,sink;
int n,m,p,s,t;

bool BFS()
{
    int x,y,w,i;
    queue<int>q;
    q.push(s);
    memset(level,-1,sizeof(level));
    memset(vis,false,sizeof(vis));
    level[s] = 0;
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
                level[y] = level[x]+1;
            }
        }
    }
    if(level[t]==-1)    return  false;
    return  true;
}

int augmentation(int x,int flow)
{
    if(x==t)    return  flow;
    int current=0,temp=0;
    for(int i=0; i<v[x].size(); i++)
    {
        int y = v[x][i].x;
        if(level[y]==level[x]+1 && v[x][i].cf>0)
        {
            current = min(flow,v[x][i].cf);
            temp = augmentation(y,current);
            if(temp>0)
            {
                v[x][i].cf -= temp;
                v[y][v[x][i].i].cf += temp;
                return  temp;
            }
        }
    }
    return  0;
}

void Dinic()
{
    max_flow = 0;
    while(BFS())
    {
        while(1)
        {
            int flow = augmentation(s,100);
            if(flow<=0) break;
            max_flow += flow;
        }
    }
}

void input()
{
    char temp[MX];
    sink = 0;
    for(int i=1; i<=n; i++)
    {
        while(gets(temp) && !temp[0]);
        for(int j=1; j<=m; j++)
        {
            if(str[i][j]=='#')  sink++;
            str[i][j] = temp[j-1];
        }
    }
    for(int i=0; i<=(m+1); i++) str[0][i] = '~';
    str[0][m+2] = '\0';
    for(int i=0; i<=(m+1); i++) str[n+1][i] = '~';
    str[n+1][m+2] = '\0';
    for(int i=0; i<=(n+1); i++) str[i][0] = '~';
    for(int i=0; i<=(n+1); i++)
    {
        str[i][m+1] = '~';
        str[i][m+2] = '\0';
    }
/**
fill outside of the grid with water.

input:
*@##
*@~#
*@~~

my grid:
~~~~~~
~*@##~
~*@~#~
~*@~~~
~~~~~~
*/
}

void build_graph()
{
    int x,y,k;
    /// split each node
    for(int i=1; i<=n; i++)
    {
        k = (i-1)*m;
        for(int j=1; j<=m; j++)
        {
            if(str[i][j]!='~')
            {
                x = k+j;
                if(str[i][j]=='#' || str[i][j]=='@')
                {
                    v[x].push_back(node(t+x,IMX,v[t+x].size()));
                    v[t+x].push_back(node(x,0,v[x].size()-1));
                }
                else
                {
                    v[x].push_back(node(t+x,1,v[t+x].size()));
                    v[t+x].push_back(node(x,0,v[x].size()-1));
                }
            }
        }
    }

    /// connect each node with it's adjacent node's
    for(int i=1; i<=n; i++)
    {
        k = (i-1)*m;
        for(int j=1; j<=m; j++)
        {
            x = k+j;
            if(str[i][j]=='~')  continue;
            else
            {
                if(str[i][j]=='#') /// connect sink with super sink
                {
                    v[t+x].push_back(node(t,p,v[t].size()));
                    v[t].push_back(node(t+x,0,v[t+x].size()-1));
                }
                else if(str[i][j]=='*')  /// connect source with super source
                {
                    v[s].push_back(node(x,1,v[x].size()));
                    v[x].push_back(node(s,0,v[s].size()-1));
                }

                /// check each node's adjacent node's
                if(str[i-1][j]!='~' && str[i-1][j]!='*')    /// up
                {
                    y = ((i-2)*m)+j;
                    v[t+x].push_back(node(y,IMX,v[y].size()));
                    v[y].push_back(node(t+x,0,v[t+x].size()-1));
                }
                if(str[i][j-1]!='~' && str[i][j-1]!='*')    /// left
                {
                    y = ((i-1)*m)+(j-1);
                    v[t+x].push_back(node(y,IMX,v[y].size()));
                    v[y].push_back(node(t+x,0,v[t+x].size()-1));
                }
                if(str[i][j+1]!='~' && str[i][j+1]!='*')    /// right
                {
                    y = ((i-1)*m)+(j+1);
                    v[t+x].push_back(node(y,IMX,v[y].size()));
                    v[y].push_back(node(t+x,0,v[t+x].size()-1));
                }
                if(str[i+1][j]!='~' && str[i+1][j]!='*')    /// down
                {
                    y = (i*m)+j;
                    v[t+x].push_back(node(y,IMX,v[y].size()));
                    v[y].push_back(node(t+x,0,v[t+x].size()-1));
                }
            }
        }
    }
}

void clr()
{
    for(int i=0; i<MX; i++) v[i].clear();
}

int main()
{
    int i,j;
    s = t = 0;
    while(scanf("%d %d %d",&n,&m,&p)==3)
    {
        clr();
        s = 0;  /// super source
        t = (n*m)+1;  /// super sink
        input();
        build_graph();
        Dinic();
        printf("%d\n",max_flow);
    }
    return  0;
}

/**
3 4 1
*@##
*@~#
*@~~
*/
