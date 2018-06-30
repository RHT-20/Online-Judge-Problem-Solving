#include<bits/stdc++.h>
using namespace std;

#define MX 1024005
struct node
{
    int pa,pb,flag;
};
node tree[4*MX];
string str;

node merge_lr(node x,node y)
{
    node temp;
    temp.pa = x.pa+y.pa;
    temp.pb = x.pb+y.pb;
    temp.flag = 0;
    return  temp;
}

void push_down(int n,int b,int e)
{
    if(tree[n].flag && b!=e)
    {
        int l = (b+e)/2;
        if(tree[n].flag==1)
        {
            tree[2*n].pa = 0;
            tree[2*n].pb = (l-b)+1;

            tree[(2*n)+1].pa = 0;
            tree[(2*n)+1].pb = e-l;
        }
        else if(tree[n].flag==2)
        {
            tree[2*n].pa = (l-b)+1;
            tree[2*n].pb = 0;

            tree[(2*n)+1].pa = e-l;
            tree[(2*n)+1].pb = 0;
        }
        else
        {
            push_down(2*n,b,l);
            push_down((2*n)+1,l+1,e);

            swap(tree[2*n].pa,tree[2*n].pb);
            swap(tree[(2*n)+1].pa,tree[(2*n)+1].pb);
        }
        tree[2*n].flag = tree[(2*n)+1].flag = tree[n].flag;
    }
    tree[n].flag = 0;
    return;
}

void init(int n,int b,int e)
{
    if(b==e)
    {
        if(str[b-1]=='0')
        {
            tree[n].pa = 1;
            tree[n].pb = 0;
        }
        else
        {
            tree[n].pa = 0;
            tree[n].pb = 1;
        }
        tree[n].flag = 0;
        return;
    }
    int l = (b+e)/2;
    init(2*n,b,l);
    init((2*n)+1,l+1,e);
    tree[n] = merge_lr(tree[2*n],tree[(2*n)+1]);
    return;
}

void update(int n,int b,int e,int i,int j,int x)
{
    if(b>j || e<i)  return;
    else if(b>=i && e<=j)
    {
        if(x==1)
        {
            tree[n].pa = 0;
            tree[n].pb = (e-b)+1;
        }
        else if(x==2)
        {
            tree[n].pa = (e-b)+1;
            tree[n].pb = 0;
        }
        else
        {
            push_down(n,b,e);
            swap(tree[n].pa,tree[n].pb);
        }
        tree[n].flag = x;
        return;
    }
    push_down(n,b,e);
    int l = (b+e)/2;
    update(2*n,b,l,i,j,x);
    update((2*n)+1,l+1,e,i,j,x);
    tree[n] = merge_lr(tree[2*n],tree[(2*n)+1]);
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
        temp = merge_lr(x,y);
    }
    tree[n] = merge_lr(tree[2*n],tree[(2*n)+1]);
    return  temp;
}

void input()
{
    int n,m;
    string sss;
    str = "";
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&m);
        cin >> sss;
        while(m--)
        {
            str += sss;
        }
    }
    return;
}

int main()
{
    int t,cs=0,qs,n,q,i,j;
    char ch;
    scanf("%d",&t);
    while(t--)
    {
        cs++;
        qs = 0;
        input();
        n = str.size();
        init(1,1,n);
        scanf("%d",&q);
        printf("Case %d:\n",cs);
        while(q--)
        {
            getchar();
            scanf("%c",&ch);
            if(ch=='F')
            {
                scanf("%d %d",&i,&j);
                update(1,1,n,i+1,j+1,1);
            }
            else if(ch=='E')
            {
                scanf("%d %d",&i,&j);
                update(1,1,n,i+1,j+1,2);
            }
            else if(ch=='I')
            {
                scanf("%d %d",&i,&j);
                update(1,1,n,i+1,j+1,3);
            }
            else
            {
                qs++;
                scanf("%d %d",&i,&j);
                printf("Q%d: %d\n",qs,query(1,1,n,i+1,j+1).pb);
            }
        }
    }
    return  0;
}
