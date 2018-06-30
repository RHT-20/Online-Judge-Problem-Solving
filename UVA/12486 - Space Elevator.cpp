#include<bits/stdc++.h>
using namespace std;

#define INF 10000000000000000000
typedef unsigned long long int ULLI;
vector<int>digit;
ULLI dp[25][5][5];

ULLI solve(int pos,bool one,bool small)
{
    if(pos>=(int)digit.size())  return  1;
    else if(dp[pos][one][small]!=-1)    return  dp[pos][one][small];

    ULLI res = 0;
    int l = small ? 9 : digit[pos];

    for(int i=0; i<=l; i++)
    {
        if(i==4 || (one && i==3))   continue;
        res += solve(pos+1,(i==1),(small | (i<l)));
    }
    return  dp[pos][one][small] = res;
}

ULLI process(ULLI x)
{
    digit.clear();
    while(x)
    {
        digit.push_back((x%10));
        x /= 10;
    }
    reverse(digit.begin(),digit.end());
    memset(dp,-1,sizeof(dp));
    return  (solve(0,false,false)-1);
}

void BS(ULLI x)
{
    ULLI lo=1,hi=INF,mid,res,tmp;
    while(lo<=hi)
    {
        mid = (lo/2)+(hi/2);
        if((lo%2) && (hi%2))    mid++;
        tmp = process(mid);
        if(tmp>=x)
        {
            if(tmp==x)  res = mid;
            hi = mid-1;
        }
        else    lo = mid+1;
    }
    printf("%llu\n",res);
    return;
}

int main()
{
    ULLI n;
    while(scanf("%llu",&n)==1)
    {
        BS(n);
    }
    return  0;
}
