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
    if((l%ans)==0)  printf("%d\n",ans);
    else    printf("%d\n",l);
    /*{
        for(i=0; i<ans; i++)    printf("%c",str[i]);
        puts("");
    }*/
}

int main()
{
    int t;
    bool f = false;
    scanf("%d",&t);
    while(t--)
    {
        if(f)   puts("");
        f = true;
        scanf("%s",str);
        compute_lps();
    }
    return  0;
}
