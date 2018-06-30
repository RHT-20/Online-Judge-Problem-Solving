#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a[100005],l[100005],cs=0,k,x,i,j,mx;
    while(1)
    {
        k = 0;
        while(1)
        {
            scanf("%d",&x);
            if(x==-1)   break;
            else    a[k++] = x;
        }
        if(k==0 && x==-1)   break;
        if(cs)    puts("");
        cs++;
        mx = 0;
        for(i=0; i<k; i++)
        {
            l[i] = 1;
            for(j=i-1; j>=0; j--)
            {
                if(a[i]<a[j] && (l[j]+1)>l[i])    l[i] = l[j]+1;
            }
            mx = max(mx,l[i]);
        }
        printf("Test #%d:\n  maximum possible interceptions: %d\n",cs,mx);
    }
    return 0;
}
