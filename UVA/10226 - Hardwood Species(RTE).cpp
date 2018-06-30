#include<bits/stdc++.h>
using namespace std;

double n;
string str;

struct node
{
    bool bookmark;
    int cnt;
    node *next[55];
    node()
    {
        bookmark = false;
        cnt = 0;
        for(int i=0; i<54; i++)
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
            int x;
            if(s[i]==' ')   x = s[i]-32;
            else if(s[i]>='A' && s[i]<='Z') x = s[i]-64;
            else    x = s[i]-70;
            if(temp->next[x]==NULL) temp->next[x] = new node();
            temp = temp->next[x];
            temp->cnt++;
        }
        temp->bookmark = true;
    }

    void display(node *temp)
    {
        for(int i=0; i<54; i++)
        {
            if(temp->next[i])
            {
                if(i==0)    str += (i+32);
                else if(i<27)   str += (i+64);
                else    str += (i+70);
                display(temp->next[i]);
                if(temp->next[i]->bookmark)
                {
                    double y = (double)temp->next[i]->cnt;
                    double x = (y*100.0)/n;
                    cout << str;
                    printf(" %0.4lf\n",x);
                    if(str.size()!=0)   str.erase(str.end()-1);
                }
                else if(str.size()!=0)    str.erase(str.end()-1);
            }
        }
        return;
    }
};

int main()
{
    int t;
    scanf("%d\n\n",&t);
    while(t--)
    {
        prefix_tree pt;
        n = 0.0;
        string s;
        while(getline(cin,s) && s!="")
        {
            pt.insert(s);
            n++;
        }
        str.clear();
        node *temp = pt.tree;
        pt.display(temp);
        if(t>0) puts("");
    }
    return 0;
}
