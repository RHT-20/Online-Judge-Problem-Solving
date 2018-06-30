#include<bits/stdc++.h>
using namespace std;

#define MX 105
vector<int>v[MX];
set<int>apoint;
int visited[MX],discovery[MX],low[MX],parent[MX],tym,n;

void articulation_point(int s)
{
    int child=0;
    tym++;
    visited[s] = 1;
    discovery[s] = low[s] = tym;
    for(int i=0; i<v[s].size(); i++)
    {
        if(parent[s]==v[s][i])  continue;
        else if(visited[v[s][i]])   low[s] = min(low[s],discovery[v[s][i]]);
        else
        {
            child++;
            parent[v[s][i]] = s;
            articulation_point(v[s][i]);
            low[s] = min(low[s],low[v[s][i]]);
            if(parent[s]==-1 && child>1)    apoint.insert(s);
            else if(parent[s]!=-1 && discovery[s]<=low[v[s][i]])    apoint.insert(s);
        }
    }
}

void input()
{
    int x,y,i,k;
    char str[505],temp[5];
    while(1)
    {
        cin >> x;
        if(!x)  break;
        while(gets(str) && !str[0]);
        k = 0;
        /** an extra space will be taken in the first position so to
        avoid this I start from 1 index. */
        for(i=1; str[i]; i++)
        {
            if(str[i]==' ')
            {
                temp[k] = '\0';
                y = atoi(temp);
                v[x].push_back(y);
                v[y].push_back(x);
                k = 0;
                continue;
            }
            temp[k++] = str[i];
        }
        temp[k] = '\0';
        y = atoi(temp);
        v[x].push_back(y);
        v[y].push_back(x);
    }
}

void clr()
{
    tym = 0;
    apoint.clear();
    for(int i=0; i<MX; i++) v[i].clear();
    memset(visited,0,sizeof(visited));
    memset(discovery,0,sizeof(discovery));
    memset(parent,-1,sizeof(parent));
    memset(low,0,sizeof(low));
}

int main()
{
    while(1)
    {
        cin >> n;
        if(!n)  break;
        clr();
        input();
        articulation_point(1);
        cout << apoint.size() << endl;
    }
    return  0;
}
