#include<bits/stdc++.h>
using namespace std;

#define MX 105
#define IMX 1000000
vector<int>u[MX],v[MX],cost1[MX],cost2[MX];
int dist1[MX],dist2[MX];

struct node
{
    int v,c;
    bool operator < (node a) const
    {
        return  (c<a.c);
    }
};
priority_queue<node>pq;

void dijkstra1(int s)
{
    int w;
    node nd;
    nd.v = s;
    nd.c = 0;
    dist1[s] = 0;
    pq.push(nd);
    while(!pq.empty())
    {
        nd = pq.top();
        pq.pop();
        s = nd.v;
        w = nd.c;
        for(int i=0; i<u[s].size(); i++)
        {
            if(dist1[u[s][i]]>(w+cost1[s][i]))
            {
                dist1[u[s][i]] = w+cost1[s][i];
                nd.v = u[s][i];
                nd.c = dist1[u[s][i]];
                pq.push(nd);
            }
        }
    }
}

void dijkstra2(int s)
{
    int w;
    node nd;
    nd.v = s;
    nd.c = 0;
    dist2[s] = 0;
    pq.push(nd);
    while(!pq.empty())
    {
        nd = pq.top();
        pq.pop();
        s = nd.v;
        w = nd.c;
        for(int i=0; i<v[s].size(); i++)
        {
            if(dist2[v[s][i]]>(w+cost2[s][i]))
            {
                dist2[v[s][i]] = w+cost2[s][i];
                nd.v = v[s][i];
                nd.c = dist2[v[s][i]];
                pq.push(nd);
            }
        }
    }
}

void clr()
{
    for(int i=0; i<MX; i++)
    {
        u[i].clear();
        v[i].clear();
        cost1[i].clear();
        cost2[i].clear();
        dist1[i] = dist2[i] = IMX;
    }
}

int main()
{
    int n,m,i,j,k,x,y,w,mx;
    char str[20],temp[10];
    set<int>st;
    while(1)
    {
        scanf("%d",&n);
        if(n==0)    break;
        clr();
        st.clear();
        m = INT_MIN;
        for(i=0; i<n; i++)
        {
            while(gets(str) && !str[0]);
            m = max(m,(str[4]-65));
            m = max(m,(str[6]-65));
            k = 0;
            for(j=8; str[j]; j++)   temp[k++] = str[j];
            temp[k] = '\0';
            w = atoi(temp);
            if(str[0]=='Y')
            {
                if(str[2]=='U')
                {
                    u[str[4]-65].push_back(str[6]-65);
                    cost1[str[4]-65].push_back(w);
                }
                else
                {
                    u[str[4]-65].push_back(str[6]-65);
                    u[str[6]-65].push_back(str[4]-65);
                    cost1[str[4]-65].push_back(w);
                    cost1[str[6]-65].push_back(w);
                }
            }
            else
            {
                if(str[2]=='U')
                {
                    v[str[4]-65].push_back(str[6]-65);
                    cost2[str[4]-65].push_back(w);
                }
                else
                {
                    v[str[4]-65].push_back(str[6]-65);
                    v[str[6]-65].push_back(str[4]-65);
                    cost2[str[4]-65].push_back(w);
                    cost2[str[6]-65].push_back(w);
                }
            }
        }
        while(gets(str) && !str[0]);
        x = str[0]-65;
        y = str[2]-65;
        dijkstra1(x);
        dijkstra2(y);
        mx = IMX;
        for(i=0; i<=m; i++)
        {
            if(dist1[i]!=IMX && dist2[i]!=IMX)
            {
                if(mx==(dist1[i]+dist2[i])) st.insert(i);
                else if(mx>(dist1[i]+dist2[i]))
                {
                    mx = dist1[i]+dist2[i];
                    st.clear();
                    st.insert(i);
                }
            }
        }
        if(st.empty())  printf("You will never meet.\n");
        else
        {
            printf("%d",mx);
            set<int>::iterator it;
            for(it=st.begin(); it!=st.end(); it++)
            {
                printf(" %c",(*it+65));
            }
            puts("");
        }
    }
    return 0;
}
