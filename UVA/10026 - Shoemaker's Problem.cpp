#include<bits/stdc++.h>
using namespace std;

struct node
{
    int indx;
    long long tym,fin;
    node(){}
    node(int ix,long long tm,long long fn)
    {
        indx = ix;
        tym = tm;
        fin = fn;
    }
};
vector<node>v;

bool compare(node a,node b)
{
    return  ((a.fin*b.tym)>(b.fin*a.tym));
}

int main()
{
    int t,n,i;
    long long x,y;
    bool f = false;
    scanf("%d",&t);
    while(t--)
    {
        if(f)   puts("");
        f = true;
        scanf("%d",&n);
        v.clear();
        for(i=0; i<n; i++)
        {
            scanf("%lld %lld",&x,&y);
            v.push_back(node(i,x,y));
        }
        sort(v.begin(),v.end(),compare);
        for(i=0; i<v.size(); i++)
        {
            if(i)   printf(" ");
            printf("%d",(v[i].indx+1));
        }
        puts("");
    }
    return  0;
}
