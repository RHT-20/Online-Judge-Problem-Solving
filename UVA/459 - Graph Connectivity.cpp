#include<bits/stdc++.h>
using namespace std;

#define SIZE 27
int cnt;

struct node
{
    int p,d;
};

node graph[SIZE];

int Find(int a)
{
    if(graph[a].p==a) return  a;
    else    return  graph[a].p = Find(graph[a].p);
}

void Union(int a,int b)
{
    int x,y;
    x = Find(a);
    y = Find(b);
    if(x==y)    return;
    else
    {
        cnt--;
        if(graph[x].d>graph[y].d)    graph[y].p = x;
        else if(graph[x].d<graph[y].d)  graph[x].p = y;
        else
        {
            graph[x].p = y;
            graph[y].d++;
        }
    }
}

int main()
{
    int t,i,x,p=0;
    char a[3];
    scanf("%d\n\n",&t);
    while(t--)
    {
        gets(a);
        cnt = a[0]-65+1;
        for(i=0; i<=cnt; i++)
        {
            graph[i].p = i;
            graph[i].d = 0;
        }
        while(gets(a))
        {
            if(strlen(a)==0)    break;
            Union(a[0]-65,a[1]-65);
        }
        if(p)   puts("");
        p = 1;
        printf("%d\n",cnt);
    }
    return 0;
}
