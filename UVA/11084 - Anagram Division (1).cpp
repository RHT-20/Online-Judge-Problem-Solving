#include<bits/stdc++.h>
using namespace std;

vector<int>v;
int a[12],k;
long long fact[12],dp[1<<12][10005];

int set_bit(int n,int pos){ return  n = n|(1<<pos);}
int reset_bit(int n,int pos){ return  n = n&(~(1<<pos));}
bool check_bit(int n,int pos){ return  (bool)(n&(1<<pos));}

void init()
{
    fact[0] = 1;
    for(long long i=1; i<12; i++)   fact[i] = fact[i-1]*i;
}

long long solve(int mask,int val)
{
    if(mask==((1<<v.size())-1))    return  (val==0);
    else if(dp[mask][val]!=-1)  return  dp[mask][val];
    int x;
    long long res=0;
    for(int i=0; i<v.size(); i++)
    {
        if(check_bit(mask,i)==false)
        {
            x = (val*10)+v[i];
            x %= k;
            res += solve(set_bit(mask,i),x);
        }
    }
    return  dp[mask][val] = res;
}

int main()
{
    int t,i,x;
    long long ans;
    string str;
    scanf("%d",&t);
    init();
    while(t--)
    {
        cin >> str >> k;
        v.clear();
        memset(a,0,sizeof(a));
        memset(dp,-1,sizeof(dp));
        for(i=0; i<str.size(); i++)
        {
            x = (int)str[i]-48;
            v.push_back(x);
            a[x]++;
        }
        sort(v.begin(),v.end());
        ans = solve(0,0);
        for(i=0; i<10; i++) ans /= fact[a[i]];
        printf("%lld\n",ans);
    }
    return  0;
}
