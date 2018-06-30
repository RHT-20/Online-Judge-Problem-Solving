#include<bits/stdc++.h>
using namespace std;

#define MX 100005
struct node
{
    long long sum,tot_sum,prop_val;
    bool lazy;
};
node tree[4*MX];

node merge_lr(node x,node y,int b,int e)
{
    node temp;
    long long m = (b+e)/2;
    m = (m-b)+1;
    long long z = m*y.sum;
    temp.tot_sum = x.tot_sum+z+y.tot_sum;
    temp.sum = x.sum+y.sum;
    temp.prop_val = 0;
    temp.lazy = false;
    return  temp;
}

void push_down(int n,int b,int e)
{
    if(tree[n].lazy)
    {
        long long m = (b+e)/2;
        long long l = (m-b)+1;
        tree[2*n].sum += (l*tree[n].prop_val);
        l = (l*(l+1))/2;
        tree[2*n].tot_sum += (l*tree[n].prop_val);
        tree[2*n].prop_val += tree[n].prop_val;
        tree[2*n].lazy = true;

        l = e-m;
        tree[(2*n)+1].sum += (l*tree[n].prop_val);
        l = (l*(l+1))/2;
        tree[(2*n)+1].tot_sum += (l*tree[n].prop_val);
        tree[(2*n)+1].prop_val += tree[n].prop_val;
        tree[(2*n)+1].lazy = true;

        tree[n].prop_val = 0;
        tree[n].lazy = false;
    }
    return;
}

void init(int n,int b,int e)
{
    if(b==e)
    {
        tree[n].sum = 100;
        tree[n].tot_sum = 100;
        tree[n].prop_val = 0;
        tree[n].lazy = false;
        return;
    }
    int l = (b+e)/2;
    init(2*n,b,l);
    init((2*n)+1,l+1,e);
    tree[n] = merge_lr(tree[2*n],tree[(2*n)+1],b,e);
    return;
}

void update(int n,int b,int e,int i,int j,long long x)
{
    if(b>j || e<i)  return;
    else if(b>=i && e<=j)
    {
        long long p = (e-b)+1;
        tree[n].sum += (p*x);
        p = (p*(p+1))/2;
        tree[n].tot_sum += (p*x);
        tree[n].prop_val += x;
        tree[n].lazy = true;
        return;
    }
    push_down(n,b,e);
    int l = (b+e)/2;
    update(2*n,b,l,i,j,x);
    update((2*n)+1,l+1,e,i,j,x);
    tree[n] = merge_lr(tree[2*n],tree[(2*n)+1],b,e);
    return;
}

node query(int n,int b,int e,int i,int j)
{
    if(b>=i && e<=j)    return  tree[n];
    push_down(n,b,e);
    int l = (b+e)/2;
    node temp;
    if(l<i) temp = query((2*n)+1,l+1,e,i,j);
    else if((l+1)>j)    temp = query(2*n,b,l,i,j);
    else
    {
        node x = query(2*n,b,l,i,j);
        node y = query((2*n)+1,l+1,e,i,j);
        long long p = (l-max(i,b))+1;
        temp.tot_sum = x.tot_sum+(p*y.sum)+y.tot_sum;
        temp.sum = x.sum+y.sum;
        temp.prop_val = 0;
        temp.lazy = false;
    }
    tree[n] = merge_lr(tree[2*n],tree[(2*n)+1],b,e);
    return  temp;
}

int main()
{
    int t,cs=0,n,q,i,j;
    long long x;
    char str[20];
    scanf("%d",&t);
    while(t--)
    {
        cs++;
        scanf("%d %d",&n,&q);
        init(1,1,n);
        printf("Case %d:\n",cs);
        while(q--)
        {
            scanf("%s",str);
            if(strcmp(str,"query")==0)
            {
                scanf("%d %d",&i,&j);
                printf("%lld\n",query(1,1,n,i,j).tot_sum);
            }
            else if(strcmp(str,"change")==0)
            {
                scanf("%d %d %lld",&i,&j,&x);
                update(1,1,n,i,j,x);
            }
        }
    }
    return  0;
}
