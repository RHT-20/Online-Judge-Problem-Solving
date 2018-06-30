#include<bits/stdc++.h>
using namespace std;

int path[1005][1005],v;
long long a[1005][1005],tax[1005];

void floyd_warshall()
{
    for(int k=1; k<=v; k++)
    {
        for(int i=1; i<=v; i++)
        {
            for(int j=1; j<=v; j++)
            {
                if(a[i][j]>(a[i][k]+a[k][j]+tax[k]))
                {
                    a[i][j] = a[i][k]+a[k][j]+tax[k];
                    path[i][j] = path[i][k];
                }
            }
        }
    }
}

void str_to_a(int n,char str[])
{
    char temp[105];
    int k=0,l=1;
    long long x;
    for(int i=0; str[i]; i++)
    {
        if(str[i]==' ')
        {
            temp[k] = '\0';
            x = atoi(temp);
            if(x==-1)   a[n][l++] = INT_MAX;
            else    a[n][l++] = x;
            k = 0;
        }
        else    temp[k++] = str[i];
    }
    temp[k] = '\0';
    x = atoi(temp);
    if(x==-1)   a[n][l] = INT_MAX;
    else    a[n][l] = x;
    v = l;
}

void str_to_tax(char str[])
{
    char temp[105];
    int k=0,j=1;
    for(int i=0; str[i]; i++)
    {
        if(str[i]==' ')
        {
            temp[k] = '\0';
            tax[j++] = atoi(temp);
            k = 0;
        }
        else    temp[k++] = str[i];
    }
    temp[k] = '\0';
    tax[j] = atoi(temp);
}

void clr()
{
    memset(a,0,sizeof(a));
    memset(path,0,sizeof(path));
    memset(tax,0,sizeof(tax));
}

int main()
{
    int t,i,j,k,x,y,c;
    long long w;
    char str[1005],temp[105];
    scanf("%d",&t);
    while(t--)
    {
        clr();
        while(gets(str) && !str[0]);
        str_to_a(1,str);
        for(i=2; i<=v; i++)
        {
            while(gets(str) && !str[0]);
            str_to_a(i,str);
        }
        while(gets(str) && !str[0]);
        str_to_tax(str);
        for(i=1; i<=v; i++)
        {
            for(j=1; j<=v; j++)
            {
                if(a[i][j]!=INT_MAX) path[i][j] = j;
            }
        }
        floyd_warshall();
        c = 0;
        while(gets(str) && str[0])
        {
            if(c++)   puts("");
            k = 0;
            for(i=0; str[i]; i++)
            {
                if(str[i]==' ')
                {
                    temp[k] = '\0';
                    x = atoi(temp);
                    k = 0;
                }
                else    temp[k++] = str[i];
            }
            temp[k] = '\0';
            y = atoi(temp);
            printf("From %d to %d :\n",x,y);
            printf("Path: %d",x);
            w = a[x][y];
            while(x!=y)
            {
                x = path[x][y];
                printf("-->%d",x);
            }
            printf("\nTotal cost : %lld\n",w);
        }
    }
    return 0;
}
