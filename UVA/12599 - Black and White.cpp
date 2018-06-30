#include<bits/stdc++.h>
using namespace std;

#define MX 10005
char str[MX];
bool vis[MX];

int main()
{
    //freopen("in.txt","w",stdout);
    bool f1,f2;
    int t,i,l,c;
    scanf("%d",&t);
    while(t--)
    {
        memset(vis,false,sizeof(vis));
        scanf("%s",str);
        l = strlen(str)-1;
        if(str[l]=='B' || str[0]=='W') puts("IMPOSSIBLE");
        else
        {
            c = 0;
            f1 = f2 = false;
            for(i=0; str[i]; i++)
            {
                if(str[i]=='B' && !f1)
                {
                    c++;
                    vis[i] = true;
                }
                else if(str[i]=='B' && f1)  f2 = true;
                else if(str[i]=='W' && (i<l || (i==l && !f2)))
                {
                    c++;
                    f1 = true;
                    vis[i] = true;
                }
            }
            if(c==(l+1))    puts("1");
            else    puts("2");
            printf("%d",c);
            for(i=0; str[i]; i++)
            {
                if(vis[i])  printf(" %d",(i+1));
            }
            puts("");
            if((l+1-c))
            {
                printf("%d",(l+1-c));
                for(i=0; str[i]; i++)
                {
                    if(!vis[i]) printf(" %d",(i+1));
                }
                puts("");
            }
        }
    }
    return  0;
}

/**
BWWBBWBW
*/
