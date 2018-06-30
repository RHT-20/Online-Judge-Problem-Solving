#include<bits/stdc++.h>
using namespace std;

#define DMX 100000000.0
double dist[105][105];
int n;
pair<double,double>pr[105];

double floyd_warshall()
{
    double mx = -1.0,x;
    for(int i=0; i<n; i++)
    {
        dist[i][i] = 0.0;
        for(int j=i+1; j<n; j++)
        {
            x = sqrt(((pr[i].first-pr[j].first)*(pr[i].first-pr[j].first))+((pr[i].second-pr[j].second)*(pr[i].second-pr[j].second)));
            if(x<=10.0) dist[i][j] = dist[j][i] = x;
            else    dist[i][j] = dist[j][i] = DMX;
        }
    }
    for(int k=0; k<n; k++)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                dist[i][j] = min(dist[i][j],(dist[i][k]+dist[k][j]));
            }
        }
    }
    int f = 0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(dist[i][j]==DMX)
            {
                f = 1;
                break;
            }
            else    mx = max(mx,dist[i][j]);
        }
        if(f)   return  -1.0;
    }
    return  mx;
}

int main()
{
    int t,cs=0,i;
    double x;
    scanf("%d",&t);
    while(t--)
    {
        cs++;
        scanf("%d",&n);
        for(i=0; i<n; i++)  scanf("%lf %lf",&pr[i].first,&pr[i].second);
        x = floyd_warshall();
        printf("Case #%d:\n",cs);
        if(x==-1.0) printf("Send Kurdy\n\n");
        else    printf("%0.4lf\n\n",x);
    }
    return 0;
}
