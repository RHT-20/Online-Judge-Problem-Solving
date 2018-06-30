#include<bits/stdc++.h>
using namespace std;

#define MX 1000005
char str[MX];
int lps[MX];

void compute_lps()
{
    int indx=0,i,l,ans;
    l = strlen(str);
    for(i=1; i<l; )
    {
        if(str[i]==str[indx])
        {
            lps[i] = indx+1;
            indx++;
            i++;
        }
        else
        {
            if(indx)    indx = lps[indx-1];
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
    ans = l-lps[l-1];
    printf("%d\n",(l/ans));
    /*if((l%ans)==0)
    {
        for(i=0; i<ans; i++)    printf("%c",str[i]);
        puts("");
    }*/
}

int main()
{
    while(scanf("%s",str)==1)
    {
        if(strcmp(str,".")==0)  break;
        compute_lps();
    }
    return  0;
}
