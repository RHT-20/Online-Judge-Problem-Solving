#include<bits/stdc++.h>
using namespace std;

#define MX 205
int mark[MX];
vector<long long>mx;
long long sum;
int taken;

struct node
{
    int x,y;
    long long w;
    bool operator < (node a) const
    {
        return  (w<a.w);
    }
};

int find(int a[],int x)
{
    if(a[x]==x)   return  x;
    else    return  a[x] = find(a,a[x]);
}

int main()
{
    int t,cs=0,x,y,i,j,n,e,p,q;
    long long w;
    scanf("%d",&t);
    while(t--)
    {
        cs++;
        mx.clear();
        scanf("%d %d",&n,&e);
        node a[e+2];
        int b[n+2];
        for(i=1; i<=n; i++) b[i] = i;
        for(i=1; i<=e; i++)
        {
            scanf("%d %d %lld",&a[i].x,&a[i].y,&a[i].w);
        }
        sort(a+1,a+e+1);
        taken = 0;
        memset(mark,0,sizeof(mark));
        for(i=1; i<=e; i++)
        {
            p = find(b,a[i].x);
            q = find(b,a[i].y);
            if(p!=q)
            {
                b[q] = p;
                taken++;
                mark[i] = 1;
            }
        }
        if(taken!=n-1)
        {
            printf("Case #%d : No way\n",cs);
            continue;
        }
        for(i=1; i<=e; i++)
        {
            if(mark[i])
            {
                sum = 0;
                taken = 0;
                for(j=1; j<=n; j++) b[j] = j;
                for(j=1; j<=e; j++)
                {
                    p = find(b,a[j].x);
                    q = find(b,a[j].y);
                    if(p!=q && j!=i)
                    {
                        b[q] = p;
                        taken++;
                        sum += a[j].w;
                    }
                }
                if(taken==n-1)  mx.push_back(sum);
            }
        }
        if(mx.size()==0)
        {
            printf("Case #%d : No second way\n",cs);
            continue;
        }
        sort(mx.begin(),mx.end());
        printf("Case #%d : %lld\n",cs,mx[0]);
    }
    return 0;
}

