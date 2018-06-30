#include<bits/stdc++.h>
using namespace std;

struct node
{
    int p,d;
};

int find(node a[],int x)
{
    if(a[x].p == x) return  x;
    else    return  a[x].p = find(a,a[x].p);
}

void Set(node a[],int x,int y)
{
    int r = find(a,x);
    int s = find(a,y);
    if(r!=s)
    {
        a[s].p = r;
        a[r].d += a[s].d;
    }
}

int main()
{
    int t,n,i,x;
    map<string,int>mp;
    scanf("%d",&t);
    char a[25],b[25];
    while(t--)
    {
        mp.clear();
        scanf("%d",&n);
        node frnd[2*n+1];
        for(i=1; i<=(2*n); i++)
        {
            frnd[i].p = i;
            frnd[i].d = 1;
        }
        i = 1;
        while(n--)
        {
            scanf("%s %s",a,b);
            if(mp[(string)a]==0)    mp[(string)a] = i++;
            if(mp[(string)b]==0)    mp[(string)b] = i++;
            Set(frnd,mp[(string)a],mp[(string)b]);
            x = find(frnd,mp[(string)a]);
            x = frnd[x].d;
            printf("%d\n",x);
        }
    }
    return 0;
}
