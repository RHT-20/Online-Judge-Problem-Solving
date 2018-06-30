#include<bits/stdc++.h>
using namespace std;

#define MX 105
map<string,int>mp1;
map<int,string>mp2;
vector<int>v[MX],top;
int indegree[MX];

struct data
{
    int vrtx;
    bool operator < (data a) const
    {
        return  (vrtx>a.vrtx);
    }
};
priority_queue<data>pq;

void topological_sort()
{
    int s,i;
    data d;
    while(!pq.empty())
    {
        d = pq.top();
        pq.pop();
        s = d.vrtx;
        top.push_back(s);
        for(i=0; i<v[s].size(); i++)
        {
            indegree[v[s][i]]--;
            if(indegree[v[s][i]]==0)
            {
                d.vrtx = v[s][i];
                pq.push(d);
            }
        }
    }
}

void clr()
{
    top.clear();
    mp1.clear();
    mp2.clear();
    memset(indegree,0,sizeof(indegree));
    for(int i=0; i<MX; i++) v[i].clear();
}

int main()
{
    int n,e,i,x,y,cs=0;
    string s1,s2;
    while(scanf("%d",&n)!=EOF)
    {
        cs++;
        clr();
        for(i=1; i<=n; i++)
        {
            cin >> s1;
            mp1[s1] = i;
            mp2[i] = s1;
        }
        scanf("%d",&e);
        for(i=0; i<e; i++)
        {
            cin >> s1 >> s2;
            v[mp1[s1]].push_back(mp1[s2]);
            indegree[mp1[s2]]++;
        }
        data d;
        for(i=1; i<=n; i++)
        {
            if(indegree[i]==0)
            {
                d.vrtx = i;
                pq.push(d);
            }
        }
        topological_sort();
        printf("Case #%d: Dilbert should drink beverages in this order:",cs);
        for(i=0; i<top.size(); i++) cout << " " << mp2[top[i]];
        puts(".");
        if(cs)  puts("");
    }
    return 0;
}

