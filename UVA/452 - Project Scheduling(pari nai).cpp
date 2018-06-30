#include<bits/stdc++.h>
using namespace std;

#define MX 30
vector<int>v[MX];
int cost[MX],visited[MX];

int dfs(int s)
{
    int temp = cost[s];
    if(visited[s]==0)
    {
        for(int i=0; i<v[s].size(); i++)
        {
            temp = 0;
            temp = max(temp,dfs(v[s][i]));
        }
        visited[s] = 1;
        cost[s] += temp;
    }
    return  cost[s];
}

void clr()
{
    for(int i=0; i<MX; i++) v[i].clear();
    memset(visited,0,sizeof(visited));
    memset(cost,0,sizeof(cost));
}

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    cin.ignore();
    string s2 = "";
    while(t--)
    {
        clr();
        cout << s2;
        s2 = "\n";
        string s,s1;
        char c;
        while(getline(cin,s) && s!="")
        {
            int x = s[0]-65;
            stringstream ss(s);
            ss >> c >> cost[x];
            if(ss >> s1)
            {
                for(int i=0; i<s1.size(); i++)
                {
                    v[x].push_back(s1[i]-65);
                }
            }
        }
        int ans = 0;
        for(int i=0; i<26; i++) dfs(i);
        for(int i=0; i<26; i++) ans = max(ans,cost[i]);
        printf("%d\n",ans);
    }
    return 0;
}
