#include<bits/stdc++.h>
using namespace std;

#define MX 105
vector<int>v[MX];
int visited[MX];
stack<int>sorted_list;

void topological_sort(int s)
{
    visited[s] = 1;
    for(int i=0; i<v[s].size(); i++)
    {
        if(visited[v[s][i]]==0) topological_sort(v[s][i]);
    }
    sorted_list.push(s);
}

void clr()
{
    memset(visited,0,sizeof(visited));
    for(int i=0; i<MX; i++) v[i].clear();
}

int main()
{
    int n,e,x,y,i;
    while(1)
    {
        scanf("%d %d",&n,&e);
        if(n==0 && e==0)    break;
        clr();
        for(i=0; i<e; i++)
        {
            scanf("%d %d",&x,&y);
            v[x].push_back(y);
        }
        for(i=1; i<=n; i++)
        {
            if(visited[i]==0)   topological_sort(i);
        }
        i = 0;
        while(!sorted_list.empty())
        {
            if(i>0) printf(" ");
            printf("%d",sorted_list.top());
            sorted_list.pop();
            i++;
        }
        puts("");
    }
    return 0;
}
