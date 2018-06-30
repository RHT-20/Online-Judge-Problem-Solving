#include<bits/stdc++.h>
using namespace std;

#define MX 100005

struct node
{
    int nxt[12],cnt,end_mark;
};
node Trie[MX];
int current=0;

bool insert_str(char str[])
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
    if(Trie[pos].cnt>1) return  false;
    else    return  true;
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
    int t,n,i,j;
    char str[MX][15],temp[15];
    bool flag;

    memset(Trie[current].nxt,-1,sizeof(Trie[current].nxt));
    Trie[current].cnt = Trie[current].end_mark = 0;

    scanf("%d",&t);
    while(t--)
    {
        flag = true;
        scanf("%d",&n);
        for(i=0; i<n; i++)
        {
            scanf("%s",str[i]);
            for(j=0; j<i; j++)
            {
                if(strlen(str[i])>strlen(str[j]))
                {
                    strcpy(temp,str[i]);
                    strcpy(str[i],str[j]);
                    strcpy(str[j],temp);
                    break;
                }
            }
        }

        for(i=0; i<n; i++)
        {
            if(!insert_str(str[i]))  flag = false;
        }
        if(flag)    puts("YES");
        else    puts("NO");
        delete_trie();
    }
    return  0;
}
