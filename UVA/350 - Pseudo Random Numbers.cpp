#include<bits/stdc++.h>
using namespace std;

int a[100000];

struct node
{
    int v;
    node *next;
};

struct link
{
    node *head=NULL;
    void insert(int x)
    {
        node *temp = (node *)malloc(sizeof(node));
        temp->v = x;
        temp->next = NULL;
        if(head==NULL)
        {
            head = temp;
            return;
        }
        else
        {
            node *p = head;
            while(head->next!=NULL)
            {
                head = head->next;
            }
            head->next = temp;
            head = p;
            return;
        }
    }

    int srch(node *temp,int x)
    {
        int c=0;
        while(temp->v!=x)
        {
            temp = temp->next;
        }
        while(temp!=NULL)
        {
            c++;
            temp = temp->next;
        }
        return c;
    }
};

int main()
{
    int z,i,m,l,cs=0,c=0;
    while(1)
    {
        cs++;
        scanf("%d %d %d %d",&z,&i,&m,&l);
        if(z==0 && i==0 && m==0 && l==0)    break;
        memset(a,0,sizeof(a));
        link L;
        a[l]++;
        L.insert(l);
        while(1)
        {
            l = ((z*l)+i)%m;
            if(a[l])    break;
            else
            {
                a[l]++;
                L.insert(l);
            }
        }
        c = L.srch(L.head,l);
        printf("Case %d: %d\n",cs,c);
    }
    return 0;
}
