#include<bits/stdc++.h>
using namespace std;

struct node
{
    node *next[3];
    node()
    {
        for(int i=0; i<2; i++)
        {
            next[i] = NULL;
        }
    }
};

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
    return;
}

bool srch(string s)
{
    int x;
    node *temp = tree;
    for(int i=0; i<s.size(); i++)
    {
        x = s[i]-'0';
        temp = temp->next[x];
    }
    for(int i=0; i<2; i++)
    {
        if(temp->next[i])   return true;
    }
    return false;
}

int main()
{
    int cs=0,f;
    vector<string>v;
    string s;
    while(cin >> s)
    {
        v.clear();
        while((s[0]-'0')!=9)
        {
            v.push_back(s);
            insert(s);
            cin >> s;
        }
        cs++;
        f = 0;
        for(int i=0; i<v.size(); i++)
        {
            bool b = srch(v[i]);
            if(b)
            {
                cout << "Set " << cs << " is not immediately decodable" << endl;
                f = 1;
                break;
            }
        }
        if(f==0)    cout << "Set " << cs << " is immediately decodable" << endl;
    }
    return 0;
}
