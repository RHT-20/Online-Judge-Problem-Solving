#include<bits/stdc++.h>
using namespace std;

struct node
{
    node *next[12];
    node()
    {
        for(int i=0; i<10; i++)
        {
            next[i] = NULL;
        }
    }
};

struct prefix_tree
{
    node *tree = new node();
    void insert(string s)
    {
        node *temp = tree;
        for(int i=0; i<s.size(); i++)
        {
            int x = s[i]-'0';
            if(temp->next[x]==NULL) temp->next[x] = new node();
            temp = temp->next[x];
        }
    }
    bool srch(node *temp,string s)
    {
        int x;
        for(int i=0; i<s.size(); i++)
        {
            x = s[i]-'0';
            temp = temp->next[x];
        }
        for(int i=0; i<10; i++)
        {
            if(temp->next[i])   return true;
        }
        return false;
    }
};

int main()
{
    int t;
    scanf("%d\n",&t);
    while(t--)
    {
        prefix_tree pt;
        int n,f=0;
        scanf("%d",&n);
        string s[n];
        for(int i=0; i<n; i++)
        {
            cin >> s[i];
            pt.insert(s[i]);
        }
        for(int i=0; i<n; i++)
        {
            node *temp = pt.tree;
            bool x = pt.srch(temp,s[i]);
            if(x)
            {
                f = 1;
                printf("NO\n");
                break;
            }
        }
        if(f==0)    printf("YES\n");
    }
    return 0;
}
