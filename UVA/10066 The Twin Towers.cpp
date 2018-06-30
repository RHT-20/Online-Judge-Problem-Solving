#include<bits/stdc++.h>
using namespace std;

int n1,n2,a[105],b[105],dp[105][105];

int solve(int i,int j)
{
    if(i==n1 || j==n2)    return 0;
    if(dp[i][j]!=-1)    return dp[i][j];
    int ans=0;
    if(a[i]==b[j])  ans = 1+solve(i+1,j+1);
    else    ans = max(solve(i+1,j),solve(i,j+1));
    return  dp[i][j] = ans;
}

/*int c[105],k=0;

void print(int i,int j)
{
    if(i==n1 || j==n2)
    {
        for(i=0; i<k; i++)
        {
            printf("%d ",c[i]);
        }
        printf("\n");
        return;
    }
    if(a[i]==b[j])
    {
        c[k++] = a[i];
        print(i+1,j+1);
    }
    else if(dp[i+1][j]>=dp[i][j+1]) print(i+1,j);
    else    print(i,j+1);
}*/

int main()
{
    int cs = 0,i;
    while(1)
    {
        if(cs)  puts("");
        cs++;
        scanf("%d %d",&n1,&n2);
        if(n1==0 && n2==0)  break;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        for(i=0; i<n1; i++)
        {
            scanf("%d",&a[i]);
        }
        for(i=0; i<n2; i++)
        {
            scanf("%d",&b[i]);
        }
        memset(dp,-1,sizeof(dp));
        printf("Twin Towers #%d\nNumber of Tiles : %d\n",cs,solve(0,0));
        //memset(c,0,sizeof(c));
        //print(0,0);
    }
    return 0;
}
