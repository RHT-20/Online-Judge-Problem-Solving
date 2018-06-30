#include<bits/stdc++.h>
using namespace std;

#define MX 3250
struct node
{
    int x,y,prnt;
};
int n,m,c1,c2,mx;
char str[50][50];
int level[MX][MX],tlevel[MX][50][50],val[50][50];
bool vis[MX][50][50];
queue<node>qq;
int fx[] = {-1,0,1,0};
int fy[] = {0,1,0,-1};
int dp[16][1<<16];

void BFS1()
{
    for(int i=1; i<=c1; i++)
    {
        for(int j=(c1+1); j<=(c1+c2); j++)    level[i][j] = 99999;
    }
    while(!qq.empty())
    {
        node nd = qq.front();
        qq.pop();
        for(int i=0; i<4; i++)
        {
            int dx = nd.x+fx[i];
            int dy = nd.y+fy[i];
            if(dx>=0 && dx<n && dy>=0 && dy<m && !vis[nd.prnt][dx][dy] && str[dx][dy]!='#')
            {
                vis[nd.prnt][dx][dy] = true;
                tlevel[nd.prnt][dx][dy] = tlevel[nd.prnt][nd.x][nd.y]+1;
                qq.push(node({dx,dy,nd.prnt}));
                if(str[dx][dy]=='X')    level[nd.prnt][val[dx][dy]] = tlevel[nd.prnt][dx][dy];
            }
        }
    }
    /*for(int i=1; i<=c1; i++)
    {
        for(int j=(c1+1); j<=(c1+c2); j++)  cout<<i<<" "<<j<<" "<<level[i][j]<<endl;
    }*/
    return;
}

int set_bit(int pos,int mask){  return  (mask | (1<<pos));}
bool check_bit(int pos,int mask){   return  (mask & (1<<pos));}

int solve(int pos,int mask)
{
    if(pos>c1) return  0;
    else if(dp[pos][mask]!=-1)  return  dp[pos][mask];

    int res,ans=INT_MAX;
    for(int i=(c1+1); i<=(c1+c2); i++)
    {
        if(!check_bit(i-c1-1,mask))
        {
            res = level[pos][i]+solve(pos+1,set_bit(i-c1-1,mask));
            ans = min(ans,res);
        }
    }
    return  dp[pos][mask] = ans;
}

int main()
{
    int t,i,j,c;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        c = 0;
        memset(vis,false,sizeof(vis));

        for(i=0; i<n; i++)  scanf("%s",str[i]);
        for(i=0; i<n; i++)
        {
            for(j=0; str[i][j]; j++)
            {
                if(str[i][j]=='B')
                {
                    val[i][j] = ++c;
                    level[c][c] = 0;
                    tlevel[c][i][j] = 0;
                    vis[c][i][j] = true;
                    qq.push(node({i,j,c}));
                }
            }
        }
        c1 = c;
        for(i=0; i<n; i++)
        {
            for(j=0; str[i][j]; j++)
            {
                if(str[i][j]=='X')  val[i][j] = ++c;
            }
        }
        c2 = c-c1;
        BFS1();
        memset(dp,-1,sizeof(dp));
        printf("%d\n",solve(1,0));
    }
    return  0;
}
