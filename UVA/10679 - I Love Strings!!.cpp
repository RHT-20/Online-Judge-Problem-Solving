#include<bits/stdc++.h>
using namespace std;

#define MX 1000005
int lps[MX];
char text[MX],ptrn[MX];

void compute_lps()
{
    int indx=0,i,l;
    l = strlen(ptrn);

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

void KMP()
{
    int indx=0,i=0,l1,l2,c=0;
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
            puts("y");
            return;
        }
    }
    puts("n");
    return;
}

int main()
{
    int t,q;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s %d",text,&q);
        while(q--)
        {
            scanf("%s",ptrn);
            compute_lps();
            KMP();
        }
    }
    return  0;
}
