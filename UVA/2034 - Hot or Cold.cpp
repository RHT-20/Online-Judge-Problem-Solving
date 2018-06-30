#include<bits/stdc++.h>
using namespace std;

double power(double x,int p)
{
    double r=1.0;
    while(p)
    {
        if(p%2)
        {
            r = r*x;
            p--;
        }
        else
        {
            x = x*x;
            p = p/2;
        }
    }
    return  r;
}

double  polynomial(double a[],double x,int n)
{
    double y = 0.0;
    int j=n+1,i;
    for(i=0; i<=n; i++)
    {
        y += a[i]*(power(x,j)/(double)j);
        j--;
    }
    return  y;
}

int main()
{
    int n,i;
    double x,y,s,e;
    while(1)
    {
        scanf("%d",&n);
        if(n==0)    break;
        double a[n+1];
        for(i=0; i<n+1; i++)
        {
            scanf("%lf",&a[i]);
        }
        scanf("%lf %lf",&s,&e);
        x = polynomial(a,e,n);
        y = polynomial(a,s,n);
        x = fabs(x-y)/(fabs(e-s));
        printf("%0.3lf\n",x);
    }
    return 0;
}
