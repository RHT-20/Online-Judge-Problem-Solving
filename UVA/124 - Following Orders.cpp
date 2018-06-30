#include<bits/stdc++.h>
using namespace std;

#define MX 1000
int v[MX],a[MX][MX],used[MX],b[MX];

void bktk(int r,int l)
{
    if(r==l)
    {
        for(int i=0; i<l; i++)  printf("%c",b[i]+'a');
        puts("");
        return;
    }
    for(int i=0; i<26; i++)
    {
        if(v[i] && used[i]==0)
        {
            for(int j=0; j<26; j++) if(a[i][j] && used[j])    return;
            used[i] = 1;
            b[r] = i;
            bktk(r+1,l);
            used[i] = 0;

        }
    }
}

int main()
{
    int i,l,cs=0;
    char s[100];
    while(gets(s))
    {
        if(cs)  puts("");
        cs++;
        memset(v,0,sizeof(v));
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(used,0,sizeof(used));
        l = 0;
        for(i=0; s[i]; i++)
        {
            if(isalpha(s[i]))
            {
                v[s[i]-'a'] = 1;
                l++;
            }
        }
        gets(s);
        for(i=0; i<strlen(s); i++)
        {
            if(isalpha(s[i]))
            {
                a[s[i]-'a'][s[i+2]-'a'] = 1;
                i += 3;
            }
        }
        bktk(0,l);
    }
    return 0;
}
