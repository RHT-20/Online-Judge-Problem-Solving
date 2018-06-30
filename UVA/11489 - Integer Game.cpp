#include<bits/stdc++.h>
using namespace std;

#define MX 1005
int a[MX],b[MX];

int main()
{
    int t,cs=0,i,j,sum,n,m,f,p;
    string s;
    scanf("%d",&t);
    while(t--)
    {
        cs++;
        cin >> s;
        sum = 0;
        n = m = s.size();
        p = 0;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        for(i=0; i<n; i++)
        {
            a[i] = s[i]-48;
            sum += a[i];
        }
        for(i=0; i<n; i++)
        {
            f = 0;
            for(j=0; j<n; j++)
            {
                if(b[j])    continue;
                if((sum-a[j])%3==0)
                {
                    f = 1;
                    break;
                }
            }
            if(f)
            {
                sum -= a[j];
                b[j] = 1;
                m--;
                p ^= 1;
            }
            if(m==0 || (f==0 && m>1))
            {
                p ^= 1;
                break;
            }
        }
        printf("Case %d: ",cs);
        if(p==0)    puts("S");
        else    puts("T");
    }
    return 0;
}

