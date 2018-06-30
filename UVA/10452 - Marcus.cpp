#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define MX 10
int a[MX][MX],visited[MX][MX],n,m,f;
pii strt,ed,b[MX];
int fx[] = {1,-1,0};
int fy[] = {0,0,-1};

void dfs(int y,int x,int k)
{
    visited[y][x] = 1;
    for(int i=0; i<3; i++)
    {
        int dx = x+fx[i];
        int dy = y+fy[i];
        if(dy==ed.first && dx==ed.second) return;
        if(dx>=0 && dx<m && dy>=0 && dy<n && visited[dy][dx]==0 && a[dy][dx]==k+1)
        {
            b[k+1].first = dx;
            b[k+1].second = dy;
            visited[dy][dx] = 1;
            dfs(dy,dx,k+1);
        }
    }
}

int main()
{
    int t,i,x,y,j;
    string s;
    scanf("%d",&t);
    while(t--)
    {
        memset(a,0,sizeof(a));
        memset(visited,0,sizeof(visited));
        memset(b,0,sizeof(b));
        scanf("%d %d",&n,&m);
        for(i=0; i<n; i++)
        {
            cin >> s;
            for(j=0; j<s.size(); j++)
            {
                if(s[j]=='I')   a[i][j] = 2;
                else if(s[j]=='E')   a[i][j] = 3;
                else if(s[j]=='H')   a[i][j] = 4;
                else if(s[j]=='O')   a[i][j] = 5;
                else if(s[j]=='V')   a[i][j] = 6;
                else if(s[j]=='A')   a[i][j] = 7;
                else if(s[j]=='@')
                {
                    strt.first = i;
                    strt.second = j;
                    a[i][j] = 1;
                }
                else if(s[j]=='#')
                {
                    ed.first = i;
                    ed.second = j;
                    a[i][j] = 1;
                }
            }
        }
        dfs(strt.first,strt.second,1);
        y = strt.first;
        x = strt.second;
        for(i=2; i<8; i++)
        {
            if(b[i].second==y && b[i].first<x)  printf("left ");
            else if(b[i].second==y && b[i].first>x) printf("right ");
            else    printf("forth ");
            x = b[i].first;
            y = b[i].second;
        }
        if(ed.second<x && ed.first==y)  printf("left\n");
        else if(ed.second>x && ed.first==y) printf("right\n");
        else    printf("forth\n");
    }
    return 0;
}
