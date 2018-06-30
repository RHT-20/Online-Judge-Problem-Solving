#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define LL long long
#define PC(x)   __builtin_popcount(x)
inline int setBit(int mask,int pos){    return  (mask | (1<<pos));}
inline int resetBit(int mask,int pos){  return  (mask & ~(1<<pos));}
inline bool checkBit(int mask,int pos){ return  (bool)(mask & (1<<pos));}

vector<int>digit;
LL dp[12][3][3][1030],dpp[1030][1030];
int vis[12][3][3][1030],c,trgt_mask;
LL val[1030];

LL solve1(int pos,int start,int small,int mask)
{
    //cout<<pos<<" "<<mask<<" "<<trgt_mask<<endl;
    if(pos>=(int)digit.size())  return  (trgt_mask==mask);
    else if(vis[pos][start][small][mask]==c)    return  dp[pos][start][small][mask];
    vis[pos][start][small][mask] = c;

    LL res=0;
    int l = small ? 9 : digit[pos];

    if(start)
    {
        for(int i=1; i<=l; i++)
        {
            if(checkBit(trgt_mask,i))   res += solve1(pos+1,0,(small|(i<l)),setBit(mask,i));
        }
        res += solve1(pos+1,1,1,0);
    }
    else
    {
        for(int i=0; i<=l; i++)
        {
            if(checkBit(trgt_mask,i))   res += solve1(pos+1,0,(small|(i<l)),setBit(mask,i));
        }
    }
    return  dp[pos][start][small][mask] = res;
}

void pre()
{
    for(int i=2; i<1024; i++)
    {
        c++;
        trgt_mask = i;
        val[i] = solve1(0,1,0,0);
        //cout<<val[i]<<endl;
    }
    return;
}

LL solve2(int pos,int last)
{
    if(pos>=1024)   return  (last!=0);
    else if(dpp[pos][last]!=-1)    return  dpp[pos][last];

    LL res = 0,tmp = 0;

    if(!last)   res = (val[pos]*solve2(pos+1,pos))%MOD;
    res = (res+solve2(pos+1,last))%MOD;
    if(last && !(last & pos))   tmp = (val[pos]*solve2(pos+1,(last|pos)))%MOD;
    res = (res+tmp)%MOD;

    return  dpp[pos][last] = res;
}

void call(LL x)
{
    digit.clear();
    while(x)
    {
        digit.push_back((x%10));
        x /= 10;
    }
    reverse(digit.begin(),digit.end());
    //for(int i=0; i<(int)digit.size(); i++)  cout<<digit[i]<<endl;
    return;
}

int main()
{
    int t,cs=0;
    LL x;
    scanf("%d",&t);
    while(t--)
    {
        cs++;
        scanf("%lld",&x);
        call(x);
        pre();
        memset(dpp,-1,sizeof(dpp));
        printf("Case %d: %lld\n",cs,solve2(2,0));
    }
    return  0;
}

