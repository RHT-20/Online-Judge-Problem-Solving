#include<bits/stdc++.h>
using namespace std;

#define MX 5005
#define pii pair<int,int>
map<string,int>mp1;
map<int,string>mp2;
map<pii,bool>mp3;
vector<int>v[MX],rev[MX];
stack<int>top;
set<int>st,stemp;
set<string>sst;
int visited[MX],indegree[MX],n,word;

void dfs1(int s)
{
    visited[s] = 1;
    for(int i=0; i<v[s].size(); i++)
    {
        if(visited[v[s][i]]==0) dfs1(v[s][i]);
    }
    top.push(s);
}

void dfs2(int s)
{
    visited[s] = 1;
    for(int i=0; i<rev[s].size(); i++)
    {
        if(visited[rev[s][i]]==0) dfs2(rev[s][i]);
    }
    stemp.insert(s);
}

void dfs3()
{
    int s;
    queue<int>q;
    for(int i=1; i<word; i++)
    {
        if(indegree[i]==0)  q.push(i);
    }
    while(!q.empty())
    {
        s = q.front();
        q.pop();
        for(int i=0; i<v[s].size(); i++)
        {
            indegree[v[s][i]]--;
            if(indegree[v[s][i]]==0)    q.push(v[s][i]);
        }
    }
    for(int i=1; i<word; i++)
    {
        if(indegree[i]) st.insert(i);
    }
}

void clr()
{
    word = 1;
    st.clear();
    stemp.clear();
    sst.clear();
    mp1.clear();
    mp2.clear();
    mp3.clear();
    for(int i=0; i<MX; i++)
    {
        v[i].clear();
        rev[i].clear();
    }
    memset(visited,0,sizeof(visited));
    memset(indegree,0,sizeof(indegree));
}

void input()
{
    int k,i,j,f,x;
    char str[1005],temp[50];
    for(i=0; i<n; i++)
    {
        while(gets(str) && !str[0]);
        f = 0;
        k = 0;
        for(j=0; str[j]; j++)
        {
            if(str[j]==' ')
            {
                temp[k] = '\0';
                if(mp1[(string)temp]==0)
                {
                    mp1[(string)temp] = word;
                    mp2[word] = (string)temp;
                    word++;
                }
                if(f==0)
                {
                    x = mp1[(string)temp];
                    f = 1;
                }
                else if(!mp3[make_pair(x,mp1[(string)temp])] && x!=mp1[(string)temp])
                {
                    v[x].push_back(mp1[(string)temp]);
                    rev[mp1[(string)temp]].push_back(x);
                    indegree[mp1[(string)temp]]++;
                    mp3[make_pair(x,mp1[(string)temp])] = true;
                }
                k = 0;
                continue;
            }
            temp[k++] = str[j];
        }
        temp[k] = '\0';
        if(mp1[(string)temp]==0)
        {
            mp1[(string)temp] = word;
            mp2[word] = (string)temp;
            word++;
        }
        if(f && !mp3[make_pair(x,mp1[(string)temp])] && x!=mp1[(string)temp])
        {
            v[x].push_back(mp1[(string)temp]);
            rev[mp1[(string)temp]].push_back(x);
            indegree[mp1[(string)temp]]++;
            mp3[make_pair(x,mp1[(string)temp])] = true;
        }
    }
}

int main()
{
    int i,f;
    while(1)
    {
        scanf("%d",&n);
        if(!n)  break;
        clr();
        input();
        for(i=1; i<word; i++)
        {
            if(visited[i]==0)   dfs1(i);
        }
        memset(visited,0,sizeof(visited));
        set<int>::iterator it;
        set<string>::iterator it2;
        while(!top.empty())
        {
            if(visited[top.top()]==0)
            {
                stemp.clear();
                dfs2(top.top());
                if(stemp.size()>1)
                {
                    for(it=stemp.begin(); it!=stemp.end(); it++)    st.insert((*it));
                }
            }
            top.pop();
        }
        f = 0;
        dfs3();
        printf("%d\n",st.size());
        for(it=st.begin(); it!=st.end(); it++)  sst.insert(mp2[(*it)]);
        for(it2=sst.begin(); it2!=sst.end(); it2++)
        {
            if(f)   printf(" ");
            cout << (*it2);
            f = 1;
        }
        if(sst.size())   puts("");
    }
    return  0;
}

