#include<bits/stdc++.h>
using namespace std;

int a[20][20],b[20][20],n;

int calc()
{
    int x;
    for(int i=2; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            x = (b[i-1][j-1]^b[i-1][j+1]^b[i-2][j]);
            if((a[i][j] && x) || !a[i][j])    b[i][j] = x;
            else    return  INT_MAX;
        }
    }
    int c = 0;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            //printf("%d ",b[i][j]);
            if(b[i][j] && !a[i][j]) c++;
            else if(!b[i][j] && a[i][j])    return  INT_MAX;
        }
        //puts("");
    }
    return  c;
}

int solve(int pos)
{
    if(pos>n)  return  calc();

    int res=INT_MAX;
    if(!a[1][pos])
    {
        b[1][pos] = 0;
        res = solve(pos+1);
    }

    b[1][pos] = 1;
    res = min(res,solve(pos+1));
    return  res;
}

int main()
{
    //freopen("in.txt","w",stdout);
    int t,cs=0,i,j,x;
    scanf("%d",&t);
    while(t--)
    {
        cs++;
        scanf("%d",&n);
        memset(b,0,sizeof(b));
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)  scanf("%d",&a[i][j]);
        }
        x = solve(1);
        printf("Case %d: ",cs);
        if(x==INT_MAX)  puts("-1");
        else    printf("%d\n",x);
    }
    return  0;
}
