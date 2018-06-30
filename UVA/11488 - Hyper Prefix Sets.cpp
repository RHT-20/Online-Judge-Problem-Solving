#include<bits/stdc++.h>
using namespace std;

#define MX 10000005

struct node
{
    int nxt[3],cnt,end_mark;
};
node Trie[MX];
int current=0;

void insert_str(char str[])
{
    int x,pos=0;
    Trie[pos].cnt++;
    for(int i=0; str[i]; i++)
    {
        x = (int)(str[i]-'0');
        if(Trie[pos].nxt[x]==-1)
        {
            current++;
            Trie[pos].nxt[x] = current;
            memset(Trie[current].nxt,-1,sizeof(Trie[current].nxt));
            Trie[current].cnt = 0;
            Trie[current].end_mark = 0;
        }
        pos = Trie[pos].nxt[x];
        Trie[pos].cnt++;
    }
    Trie[pos].end_mark++;
}

long long solve(int pos,long long l)
{
    long long res=(l*Trie[pos].cnt);

    if(Trie[pos].nxt[0]!=-1)    res = max(res,solve(Trie[pos].nxt[0],l+1));
    if(Trie[pos].nxt[1]!=-1)    res = max(res,solve(Trie[pos].nxt[1],l+1));
    return  res;
}

void delete_trie()
{
    for(int i=0; i<=current; i++)
    {
        memset(Trie[i].nxt,-1,sizeof(Trie[i].nxt));
        Trie[i].cnt = Trie[i].end_mark = 0;
    }
    current = 0;
}

int main()
{
    int t,n;
    char str[205];
    long long ans;

    memset(Trie[current].nxt,-1,sizeof(Trie[current].nxt));
    Trie[current].cnt = Trie[current].end_mark = 0;

    scanf("%d",&t);
    while(t--)
    {
        ans = 0;
        scanf("%d",&n);
        while(n--)
        {
            scanf("%s",str);
            insert_str(str);
        }
        ans = solve(0,0);
        printf("%lld\n",ans);
        delete_trie();
    }
    return  0;
}
