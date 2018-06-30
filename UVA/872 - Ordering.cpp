#include<bits/stdc++.h>
using namespace std;

#define MX 105
map<char,int>mp;
vector<int>v[MX],alphabet;
int visited[MX],indegree[MX],yes[MX],n,cycle;

void dfs(int s)
{
    visited[s] = 2;
    for(int i=0; i<v[s].size(); i++)
    {
        if(visited[v[s][i]]==0) dfs(v[s][i]);
        else if(visited[v[s][i]]==2)
        {
            cycle = 1;
            return;
        }
    }
    visited[s] = 1;
}

void bfs_and_permutation()
{
    if(alphabet.size()==n)
    {
        for(int i=0; i<alphabet.size(); i++)
        {
            if(i>0) printf(" ");
            printf("%c",alphabet[i]+65);
        }
        puts("");
    }
    for(int i=0; i<26; i++)
    {
        if(yes[i] && !visited[i] && indegree[i]==0)
        {
            for(int j=0; j<v[i].size(); j++)    indegree[v[i][j]]--;
            visited[i] = 1;
            alphabet.push_back(i);
            bfs_and_permutation();
            for(int j=0; j<v[i].size(); j++)    indegree[v[i][j]]++;
            visited[i] = 0;
            alphabet.pop_back();
        }
    }
}

void clr()
{
    n = cycle = 0;
    mp.clear();
    alphabet.clear();
    for(int i=0; i<MX; i++) v[i].clear();
    memset(visited,0,sizeof(visited));
    memset(indegree,0,sizeof(indegree));
    memset(yes,0,sizeof(yes));
}

void input()
{
    int k=0,i;
    char str[505],temp[5];
    while(gets(str) && !str[0]);
    for(i=0; str[i]; i++)
    {
        if(str[i]==' ') continue;
        mp[str[i]] = str[i]-65;
        yes[(int)str[i]-65] = 1;
        n++;
    }
    while(gets(str) && !str[0]);
    for(i=0; str[i]; i++)
    {
        if(str[i]==' ')
        {
            v[mp[temp[0]]].push_back(mp[temp[2]]);
            indegree[mp[temp[2]]]++;
            k = 0;
            continue;
        }
        temp[k++] = str[i];
    }
    v[mp[temp[0]]].push_back(mp[temp[2]]);
    indegree[mp[temp[2]]]++;
}

int main()
{
    int t,i,c;
    cin >> t;
    while(t--)
    {
        clr();
        input();
        c = 1;
        for(i=0; i<26; i++)
        {
            if(yes[i] && !visited[i])   dfs(i);
            if(cycle)   break;
        }
        if(cycle)   puts("NO");
        else
        {
            memset(visited,0,sizeof(visited));
            bfs_and_permutation();
        }
        if(c && t)   puts("");
    }
    return  0;
}
