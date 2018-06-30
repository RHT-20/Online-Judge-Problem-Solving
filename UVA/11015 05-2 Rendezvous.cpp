#include<bits/stdc++.h>
using namespace std;

#define MX 25
long long a[MX][MX];
int v;
map<int,string>mp;

int floyd_warshall()
{
    long long res,ans=INT_MAX,pos;
    for(int k=1; k<=v; k++)
    {
        for(int i=1; i<=v; i++)
        {
            for(int j=1; j<=v; j++)
            {
                a[i][j] = min(a[i][j],(a[i][k]+a[k][j]));
            }
        }
    }
    for(int i=1; i<=v; i++)
    {
        res = 0;
        for(int j=1; j<=v; j++)
        {
            res += a[i][j];
        }
        if(res<ans)
        {
            ans = res;
            pos = i;
        }
    }
    return  pos;
}

void clr()
{
    mp.clear();
    memset(a,0,sizeof(a));
    for(int i=0; i<MX; i++)
    {
        for(int j=0; j<MX; j++)
        {
            if(i==j)    continue;
            a[i][j] = INT_MAX;
        }
    }
}

int main()
{
    int x,y,w,e,i,cs=0;
    string str;
    while(1)
    {
        cs++;
        clr();
        scanf("%d %d",&v,&e);
        if(v==0)    break;
        for(i=1; i<=v; i++)
        {
            cin >> str;
            mp[i] = str;
        }
        for(i=0; i<e; i++)
        {
            scanf("%d %d %d",&x,&y,&w);
            a[x][y] = w;
            a[y][x] = w;
        }
        x = floyd_warshall();
        printf("Case #%d : ",cs);
        cout << mp[x] << endl;
    }
    return 0;
}
