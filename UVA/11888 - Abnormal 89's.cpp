#include<bits/stdc++.h>
using namespace std;

#define MX 4000005
int lps[MX];
char text[MX],ptrn[MX];

void pre()
{
    int i,j,l;
    l = strlen(text);
    for(i=0,j=(l-1); i<l; i++,j--)  ptrn[i] = text[j];
    ptrn[l] = '\0';
    for(i=0,j=l; i<l; i++,j++)  text[j] = text[i];
    text[j] = '\0';
}

void compute_lps()
{
    int indx=0,i,l;
    l = strlen(ptrn);
    memset(lps,0,sizeof(lps));

    for(i=1; i<l; )
    {
        if(ptrn[indx]==ptrn[i])
        {
            lps[i] = indx+1;
            indx++;
            i++;
        }
        else
        {
            if(indx!=0)    indx = lps[indx-1];
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

int KMP()
{
    int indx=0,i=0,l1,l2,x,f=-1;
    l1 = strlen(ptrn);
    l2 = strlen(text);

    while(i<l2 && indx<l1)
    {
        if(text[i]==ptrn[indx])
        {
            indx++;
            i++;
        }
        else
        {
            if(indx!=0) indx = lps[indx-1];
            else    i++;
        }
        if(indx==l1)
        {
            x = i-l1;
            if(x)   return  x;
            indx = lps[indx-1];
            f = 0;
        }
    }
    return  f;
}

int main()
{
    int t,x;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",text);
        pre();
        compute_lps();
        x = KMP();
        if(x==(int)strlen(ptrn))    puts("palindrome");
        else if(x==-1)  puts("simple");
        else    puts("alindrome");
    }
    return  0;
}

