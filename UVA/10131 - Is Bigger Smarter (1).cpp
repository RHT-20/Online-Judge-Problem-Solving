#include<bits/stdc++.h>
using namespace std;

#define MX 1005
struct node
{
    int w,iq,p;
    node(int we,int iqe,int pe)
    {
        w = we;
        iq = iqe;
        p = pe;
    }
    bool operator < (node a) const
    {
        if(w==a.w)  return  (iq<a.iq);
        else    return  (w>a.w);
    }
};
vector<node>v;
int dp[MX],nxt[MX];

int main()
{
    int w,q,pos=0,i,j,ans=-1;
    while(scanf("%d %d",&w,&q)==2)
    {
        pos++;
        v.push_back(node(w,q,pos));
    }
    sort(v.begin(),v.end());
    memset(nxt,-1,sizeof(nxt));
    for(i=0; i<v.size(); i++)
    {
        dp[i] = 1;
        for(j=0; j<i; j++)
        {
            if(v[i].w<v[j].w && v[i].iq>v[j].iq && (dp[j]+1)>dp[i])
            {
                dp[i] = dp[j]+1;
                nxt[i] = j;
            }
        }
        if(ans<dp[i])
        {
            ans = dp[i];
            pos = i;
        }
    }
    printf("%d\n",ans);
    while(1)
    {
        printf("%d\n",v[pos].p);
        if(nxt[pos]==-1)   break;
        pos = nxt[pos];
    }
    return  0;
}
