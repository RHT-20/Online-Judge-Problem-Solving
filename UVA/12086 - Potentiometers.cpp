#include<bits/stdc++.h>
using namespace std;

#define MX 200005
struct node
{
    int b,e;
    long long sum;
};
node bucket[500];
long long a[MX];
int bucket_size,n;

void init()
{
    int cnt=0,current_bucket=0;

    bucket_size = sqrt(n);

    bucket[current_bucket].b = 0;
    bucket[current_bucket].sum = 0;

    for(int i=0; i<n; i++)
    {
        if(cnt==bucket_size)
        {
            cnt = 0;
            bucket[current_bucket].e = i-1;
            current_bucket++;
            bucket[current_bucket].b = i;
            bucket[current_bucket].sum = 0;
        }
        bucket[current_bucket].sum += a[i];
        cnt++;
    }
    bucket[current_bucket].e = n-1;
    return;
}

void update_index(int i,long long x)
{
    int indx = i/bucket_size;

    bucket[indx].sum -= a[i];
    bucket[indx].sum += x;
    a[i] = x;

    return;
}

long long query(int b,int e)
{
    int i,lb,rb;
    long long ans=0;

    lb = b/bucket_size;
    rb = e/bucket_size;

    /// left side
    for(i=b; i<=min(e,bucket[lb].e); i++)   ans += a[i];

    if(lb==rb)  return  ans;

    /// middle
    for(i=(lb+1); i<rb; i++)    ans += bucket[i].sum;

    /// right side
    for(i=bucket[rb].b; i<=e; i++)  ans += a[i];
    return  ans;
}

int main()
{
    int cs=0,i,j;
    long long x;
    char str[5];
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(1)
    {
        scanf("%d",&n);
        if(!n)  break;
        if(cs)  puts("");
        cs++;
        for(i=0; i<n; i++)  scanf("%lld",&a[i]);
        init();
        printf("Case %d:\n",cs);
        while(1)
        {
            scanf("%s",str);
            if(str[0]=='S')
            {
                scanf("%d %lld",&i,&x);
                update_index(i-1,x);
            }
            else if(str[0]=='M')
            {
                scanf("%d %d",&i,&j);
                printf("%lld\n",query(i-1,j-1));
            }
            else    break;
        }
    }
    return  0;
}
