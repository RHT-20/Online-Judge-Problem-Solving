#include<bits/stdc++.h>
using namespace std;

#define MX 300005
#define pii pair<int,long long>
struct node
{
    int b,e;
    pii ara[550];
};
node bucket[550];
long long a[MX],w;
int bucket_size,n;

bool comp(pii pa,pii pb)
{
    if(pa.second==pb.second)    return  (pa.first<pb.first);
    return  (pa.second<pb.second);
}

void init()
{
    int cnt=0,current_bucket=0;

    bucket_size = sqrt(n);

    bucket[current_bucket].b = 0;

    for(int i=0; i<n; i++)
    {
        if(cnt==bucket_size)
        {
            bucket[current_bucket].e = i-1;
            sort(bucket[current_bucket].ara,bucket[current_bucket].ara+cnt,comp);
            cnt = 0;
            current_bucket++;
            bucket[current_bucket].b = i;
        }
        bucket[current_bucket].ara[cnt].first = i;
        bucket[current_bucket].ara[cnt].second = a[i];
        cnt++;
    }
    bucket[current_bucket].e = n-1;
    sort(bucket[current_bucket].ara,bucket[current_bucket].ara+cnt,comp);
    return;
}

void update_index(int i,long long x)
{
    int b_indx = i/bucket_size;
    int l = bucket[b_indx].e-bucket[b_indx].b+1;

    for(int j=0; j<l; j++)
    {
        if(bucket[b_indx].ara[j].first==i)
        {
            bucket[b_indx].ara[j].second = x;
            a[bucket[b_indx].ara[j].first] = x;
            break;
        }
    }

    sort(bucket[b_indx].ara,bucket[b_indx].ara+l,comp);

    return;
}

long long BS(int indx,int l,int r,long long x)
{
    int lo,hi,md;
    long long cnt=0;
    lo = l;
    hi = r;
    while(lo<=hi)
    {
        md = (lo+hi)/2;
        if(bucket[indx].ara[md].second<x)
        {
            cnt = (md-l+1);
            lo = md+1;
        }
        else    hi = md-1;
    }
    return  cnt;
}

long long query(int b,int e,long long x)
{
    int i,lb,rb;
    long long ans=0;

    lb = b/bucket_size;
    rb = e/bucket_size;

    /// left side
    int l = bucket[lb].e-bucket[lb].b;
    for(i=0; i<=l; i++)
    {
        if(bucket[lb].ara[i].first>=b && bucket[lb].ara[i].first<=e && bucket[lb].ara[i].second<x)  ans++;
    }

    if(lb==rb)  return  ans;

    /// middle
    for(i=(lb+1); i<rb; i++)
    {
        ans += BS(i,0,(bucket[i].e-bucket[i].b),x);
    }

    /// right side
    l = bucket[rb].e-bucket[rb].b;
    for(i=0; i<=l; i++)
    {
        if(bucket[rb].ara[i].first>=b && bucket[rb].ara[i].first<=e && bucket[rb].ara[i].second<x)  ans++;
    }

    return  ans;
}

void print()
{
    for(int i=0; i<n; i++)  printf("%lld\n",a[i]);
    return;
}

int main()
{
    int p,q,i,j;
    long long x,res;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(scanf("%d %d %lld",&n,&q,&w)==3)
    {
        for(i=0; i<n; i++)  scanf("%lld",&a[i]);
        init();
        while(q--)
        {
            scanf("%d %d %lld %d",&i,&j,&x,&p);
            res = query(i-1,j-1,x);
            res = (w*res)/(long long)(j-i+1);
            update_index(p-1,res);
        }
        print();
    }
    return  0;
}
