#include<bits/stdc++.h>
using namespace std;

#define MX 100005
struct node
{
    int mxh,lc,lh,rc,rh;
};
node tree[4*MX];
int a[MX];

node merge_lr(node x,node y)
{
    node temp;
    temp.mxh = INT_MIN;
    if(x.rc==y.lc)
    {
        if(x.lc==x.rc)
        {
            if(y.lc==y.rc)
            {
                temp.lc = temp.rc = x.lc;
                temp.lh = temp.rh = x.rh+y.lh;
            }
            else
            {
                temp.lc = x.lc;
                temp.rc = y.rc;
                temp.lh = x.rh+y.lh;
                temp.rh = y.rh;
            }
        }
        else
        {
            if(y.lc==y.rc)
            {
                temp.lc = x.lc;
                temp.rc = y.rc;
                temp.lh = x.lh;
                temp.rh = x.rh+y.lh;
            }
            else
            {
                temp.lc = x.lc;
                temp.rc = y.rc;
                temp.lh = x.lh;
                temp.rh = y.rh;
                temp.mxh = x.rh+y.lh;
            }
        }
    }
    else
    {
        if(x.lc==x.rc)
        {
            if(y.lc==y.rc)
            {
                temp.lc = x.lc;
                temp.rc = y.rc;
                temp.lh = x.lh;
                temp.rh = y.rh;
            }
            else
            {
                temp.lc = x.lc;
                temp.rc = y.rc;
                temp.lh = x.lh;
                temp.rh = y.rh;
            }
        }
        else
        {
            if(y.lc==y.rc)
            {
                temp.lc = x.lc;
                temp.rc = y.rc;
                temp.lh = x.lh;
                temp.rh = y.rh;
            }
            else
            {
                temp.lc = x.lc;
                temp.rc = y.rc;
                temp.lh = x.lh;
                temp.rh = y.rh;
            }
        }
    }
    temp.mxh = max(temp.mxh,max(x.lh,x.rh));
    temp.mxh = max(temp.mxh,max(y.lh,y.rh));
    temp.mxh = max(temp.mxh,max(temp.lh,temp.rh));
    temp.mxh = max(temp.mxh,max(x.mxh,y.mxh));
    return  temp;
}

void init(int n,int b,int e)
{
    if(b==e)
    {
        tree[n].mxh = 1;
        tree[n].lc = tree[n].rc = a[b];
        tree[n].lh = tree[n].rh = 1;
        return;
    }
    int l = (b+e)/2;
    init(2*n,b,l);
    init((2*n)+1,l+1,e);
    tree[n] = merge_lr(tree[2*n],tree[(2*n)+1]);
    return;
}

node query(int n,int b,int e,int i,int j)
{
    if(b>=i && e<=j)    return  tree[n];
    int l = (b+e)/2;
    if(l<i) return  query((2*n)+1,l+1,e,i,j);
    else if((l+1)>j)    return  query(2*n,b,l,i,j);
    else
    {
        node x = query(2*n,b,l,i,j);
        node y = query((2*n)+1,l+1,e,i,j);
        return  merge_lr(x,y);
    }
}

int main()
{
    int n,q,i,j;
    while(1)
    {
        scanf("%d",&n);
        if(!n)  break;
        scanf("%d",&q);
        for(i=1; i<=n; i++) scanf("%d",&a[i]);
        init(1,1,n);
        while(q--)
        {
            scanf("%d %d",&i,&j);
            printf("%d\n",query(1,1,n,i,j).mxh);
        }
    }
    return  0;
}
