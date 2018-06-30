#include<bits/stdc++.h>
using namespace std;

#define MX 105
map<string,int>mp1;
map<int,string>mp2;
vector<int>v[MX],top;
int indegree[MX],visited[MX],n;

void topological_sort()
{
    int k;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(indegree[j]==0 && visited[j]==0)
            {
                top.push_back(j);
                visited[j] = 1;
                k = j;
                break;
            }
        }
        for(int j=0; j<v[k].size(); j++)    indegree[v[k][j]]--;
    }
}

void clr()
{
    top.clear();
    mp1.clear();
    mp2.clear();
    memset(indegree,0,sizeof(indegree));
    memset(visited,0,sizeof(visited));
    for(int i=0; i<MX; i++) v[i].clear();
}

int main()
{
    int m,i,x,y,cs=0;
    string s1,s2;
    while(scanf("%d",&n)==1)
    {
        cs++;
        clr();
        for(i=0; i<n; i++)
        {
            cin >> s1;
            mp1[s1] = i;
            mp2[i] = s1;
        }
        scanf("%d",&m);
        for(i=0; i<m; i++)
        {
            cin >> s1 >> s2;
            v[mp1[s1]].push_back(mp1[s2]);
            indegree[mp1[s2]]++;
        }
        topological_sort();
        printf("Case #%d: Dilbert should drink beverages in this order:",cs);
        for(i=0; i<top.size(); i++) cout << " " << mp2[top[i]];
        puts(".");
        if(cs)  puts("");
    }
    return 0;
}

