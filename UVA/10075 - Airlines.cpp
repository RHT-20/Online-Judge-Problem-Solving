#include<bits/stdc++.h>
using namespace std;

#define pi 3.141592653589793/180
#define ER 6378.0
#define pii pair<double,double>
pii point[105];
long long a[105][105];
int n;
map<string,int>mp;

void floyd_warshall()
{
    for(int k=0; k<n; k++)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)  a[i][j] = min(a[i][j],(a[i][k]+a[k][j]));
        }
    }
}

void clr()
{
    for(int i=0; i<105; i++)
    {
        for(int j=0; j<105; j++)
        {
            if(i==j)    a[i][j] = 0;
            else    a[i][j] = INT_MAX;
        }
    }
    mp.clear();
    memset(point,0,sizeof(point));
}

int main()
{
    int m,q,i,u,v,cs=0;
    double x,y;
    char str[25],str2[25];
    while(1)
    {
        scanf("%d %d %d",&n,&m,&q);
        if(n==0 && m==0 && q==0)    break;
        clr();
        if(cs)  puts("");
        cs++;
        for(i=0; i<n; i++)
        {
            scanf("%s %lf %lf",str,&x,&y);
            mp[str] = i;
            point[i].first = pi*x;
            point[i].second = pi*y;
        }
        for(i=0; i<m; i++)
        {
            scanf("%s %s",str,str2);
            u = mp[str];
            v = mp[str2];
            x = (cos(point[u].first)*cos(point[v].first)*cos(point[u].second-point[v].second))+(sin(point[u].first)*sin(point[v].first));
            y = ER*acos(x);
            a[u][v] = (int)round(y);
        }
        floyd_warshall();
        printf("Case #%d\n",cs);
        for(i=0; i<q; i++)
        {
            scanf("%s %s",str,str2);
            u = mp[str];
            v = mp[str2];
            if(a[u][v]==INT_MAX)    printf("no route exists\n");
            else    printf("%lld km\n",a[u][v]);
        }
    }
    return  0;
}

