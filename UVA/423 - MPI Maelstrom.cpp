#include<bits/stdc++.h>
using namespace std;

long long a[105][105],ans;
int n;

void floyd_warshall()
{
    int f;
    while(1)
    {
        f = 0;
        for(int k=1; k<=n; k++)
        {
            for(int i=1; i<=n; i++)
            {
                for(int j=1; j<=n; j++)
                {
                    if(a[i][j]>(a[i][k]+a[k][j]))
                    {
                        a[j][i] = a[i][j] = a[i][k]+a[k][j];
                        f = 1;
                    }
                }
            }
        }
        if(f==0)    break;
    }
    ans = INT_MIN;
    for(int i=2; i<=n; i++) ans = max(ans,a[1][i]);
}

void str_to_a(int x,char str[])
{
    char temp[105];
    int k=0,l=1;
    for(int i=0; str[i]; i++)
    {
        if(str[i]==' ')
        {
            temp[k] = '\0';
            if(temp[0]=='x')    a[x][l] = a[l][x] = INT_MAX;
            else    a[x][l] = a[l][x] = atoi(temp);
            k = 0;
            l++;
        }
        else    temp[k++] = str[i];
    }
    temp[k] = '\0';
    if(temp[0]=='x')    a[x][l] = a[l][x] = INT_MAX;
    else    a[x][l] = a[l][x] = atoi(temp);
}

int main()
{
    int i;
    char str[1005];
    while(scanf("%d",&n)!=EOF)
    {
        memset(a,0,sizeof(a));
        for(i=2; i<=n; i++)
        {
            while(gets(str) && !str[0]);
            str_to_a(i,str);
        }
        floyd_warshall();
        printf("%lld\n",ans);
    }
    return 0;
}
