#include<bits/stdc++.h>
using namespace std;

#define MX 30
vector<int>v[MX];
string str;
stack<char>stk,stk1,stk2;
stack<int>stki;
int visited[MX],yes[MX],value[MX],cycle,ans,n;

void dfs(int s)
{
    int x=1;
    visited[s] = 2;
    for(int i=0; i<v[s].size(); i++)
    {
        if(visited[v[s][i]]==0)
        {
            dfs(v[s][i]);
            x = max(x,(value[v[s][i]]+1));
        }
        else if(visited[v[s][i]]==2)
        {
            cycle = 1;
            return;
        }
        else if(visited[v[s][i]]==1)    x = max(x,(value[v[s][i]]+1));
    }
    visited[s] = 1;
    value[s] = x;
}

void infix_to_postfix()
{
    /** stk1 operand(a,b,..z) stk2 operator(+,*,(,)) */
    for(int i=0; i<str.size(); i++)
    {
        if(str[i]=='+')
        {
            while(!stk2.empty() && !(stk2.top()=='('))
            {
                stk1.push(stk2.top());
                stk2.pop();
            }
            stk2.push(str[i]);
        }
        else if(str[i]==')')
        {
            while(!stk2.empty() && !(stk2.top()=='('))
            {
                stk1.push(stk2.top());
                stk2.pop();
            }
            stk2.pop();
        }
        else if(str[i]=='*' || str[i]=='(')    stk2.push(str[i]);
        else    stk1.push(str[i]);
    }
    while(!stk2.empty())
    {
        stk1.push(stk2.top());
        stk2.pop();
    }
    while(!stk1.empty())
    {
        stk.push(stk1.top());
        stk1.pop();
    }
}

void expression_evaluation()
{
    int x;
    while(!stk.empty())
    {
        if(stk.top()=='+')
        {
            x = stki.top();
            stki.pop();
            x += stki.top();
            stki.pop();
            stki.push(x);
            stk.pop();
        }
        else if(stk.top()=='*')
        {
            x = stki.top();
            stki.pop();
            x *= stki.top();
            stki.pop();
            stki.push(x);
            stk.pop();
        }
        else
        {
            stki.push(value[stk.top()-97]);
            stk.pop();
        }
    }
    ans = stki.top();
    stki.pop();
}

void clr()
{
    ans = cycle = 0;
    str.clear();
    for(int i=0; i<MX; i++) v[i].clear();
    memset(visited,0,sizeof(visited));
    memset(yes,0,sizeof(yes));
    memset(value,0,sizeof(value));
}

void input()
{
    char temp[5];
    cin >> str >> n;
    for(int i=0; i<str.size(); i++)
    {
        if(str[i]>='a' && str[i]<='z')  yes[str[i]-97] = 1;
    }
    for(int i=0; i<n; i++)
    {
        while(gets(temp) && !temp[0]);
        v[temp[0]-97].push_back(temp[2]-97);
    }
}

int main()
{
    int t,cs=0,i;
    cin >> t;
    while(t--)
    {
        cs++;
        clr();
        input();
        for(i=0; i<26; i++)
        {
            if(yes[i] && !visited[i])   dfs(i);
            if(cycle)   break;
        }
        if(cycle)
        {
            printf("Case %d: -1\n",cs);
            continue;
        }
        infix_to_postfix();
        expression_evaluation();
        printf("Case %d: %d\n",cs,ans);
    }
    return  0;
}

