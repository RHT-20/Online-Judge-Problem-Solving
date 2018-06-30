#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long t,cs=0,g1,g2,d1,d2,s1,s2,g,d,s,ans;
    scanf("%lld",&t);
    while(t--)
    {
        cs++;
        scanf("%lld %lld %lld %lld %lld %lld",&g1,&g2,&d1,&d2,&s1,&s2);
        g = abs(g1-g2);
        d = abs(d1-d2)+1;
        s = abs(s1-s2);
        g = g/2+(g1%2==0 || g2%2==0);
        s = s/2+(s1%2==0 || s2%2==0);
        ans = ((g*s)*d);
        printf("Case %lld: %lld\n",cs,ans);
    }
    return  0;
}

