#include<bits/stdc++.h>
using namespace std;

#define MX 100005
map<string,vector<string> >mp;
map<string,string>path;
map<string,int>visited;

void bfs(string s)
{
    queue<string>q;
    q.push(s);
    path[s] = s;
    while(!q.empty())
    {
        s = q.front();
        q.pop();
        visited[s] = 1;
        for(int i=0; i<mp[s].size(); i++)
        {
            if(visited[mp[s][i]]==0)
            {
                q.push(mp[s][i]);
                visited[mp[s][i]] = 1;
                path[mp[s][i]] = s;
            }
        }
    }
}

void shortest_path(string b)
{
    if(path[b]==b)    return;
    shortest_path(path[b]);
    cout << path[b] << " " << b << endl;
}

int main()
{
    int n,i,c=0;
    string a,b;
    while(scanf("%d",&n)!=EOF)
    {
        if(c)   puts("");
        c = 1;
        for(i=0; i<n; i++)
        {
            cin >> a >> b;
            mp[a].push_back(b);
            mp[b].push_back(a);
        }
        cin >> a >> b;
        bfs(a);
        if(visited[b]==0)   printf("No route\n");
        else    shortest_path(b);
        mp.clear();
        visited.clear();
        path.clear();
    }
    return 0;
}
