#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define ppi pair<pii,int>
struct node
{
    int x,y;
};
int dp[1<<15][17],grid[22][22],dist[17][17],cnt,n,m;
bool visited[22][22];
int fx[] = {-1,-1,-1,0,1,1,1,0};
int fy[] = {-1,0,1,1,1,0,-1,-1};

int set_bit(int n,int pos){ return  n = n|(1<<pos);}
int reset_bit(int n,int pos){ return  n = n&(~(1<<pos));}
bool check_bit(int n,int pos){ return  (bool)(n&(1<<pos));}

void bfs(int sx,int sy,int pos)
{
    int w,dx,dy,i;
    queue<ppi>q;
    q.push(ppi(pii(sx,sy),0));
    memset(visited,false,sizeof(visited));
    while(!q.empty())
    {
        sx = q.front().first.first;
        sy = q.front().first.second;
        w = q.front().second;
        visited[sx][sy] = true;
        q.pop();
        for(i=0; i<8; i++)
        {
            dx = sx+fx[i];
            dy = sy+fy[i];
            if(dx>=0 && dx<n && dy>=0 && dy<m && visited[dx][dy]==false)
            {
                visited[dx][dy] = true;
                q.push(ppi(pii(dx,dy),(w+1)));
                if(grid[dx][dy]!=-1)
                {
                    dist[pos][grid[dx][dy]] = w+1;
                }
            }
        }
    }
}

int solve(int mask,int pos)
{
    if(mask==((1<<cnt)-1))  return  dist[cnt][pos];
    else if(dp[mask][pos]!=-1)   return  dp[mask][pos];
    int res,ans=INT_MAX;
    for(int i=0; i<cnt; i++)
    {
        if(check_bit(mask,i)==false)
        {
            res = dist[pos][i]+solve(set_bit(mask,i),i);
            ans = min(ans,res);
        }
    }
    return  dp[mask][pos] = ans;
}

int main()
{
    int x,y,i,j;
    string str;
    node a[16];
    while(scanf("%d %d",&n,&m)==2)
    {
        cnt = 0;
        memset(a,0,sizeof(a));
        memset(grid,0,sizeof(grid));
        memset(dp,-1,sizeof(dp));
        for(i=0; i<n; i++)
        {
            cin >> str;
            for(j=0; j<str.size(); j++)
            {
                if(str[j]=='L')
                {
                    x = i;
                    y = j;
                    grid[i][j] = -1;
                }
                else if(str[j]=='#')
                {
                    a[cnt].x = i;
                    a[cnt].y = j;
                    grid[i][j] = cnt;
                    cnt++;
                }
                else    grid[i][j] = -1;
            }
        }
        bfs(x,y,cnt);
        for(i=0; i<cnt; i++)
        {
            bfs(a[i].x,a[i].y,i);
        }
        /*for(i=0; i<=cnt; i++)
        {
            for(j=0; j<=cnt; j++)   cout << dist[i][j]<<" ";
            puts("");
        }*/
        printf("%d\n",solve(0,cnt));
    }
    return  0;
}

