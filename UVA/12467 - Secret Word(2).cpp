#include<bits/stdc++.h>
using namespace std;

#define MX 1000005
#define MOD 1000000007LL
#define BASE 347LL
char s[MX];
long long a[MX],b[MX],hh[MX];

void pre()
{
    hh[1] = BASE;
    for(int i=2; i<MX; i++) hh[i] = (hh[i-1]*BASE)%MOD;
}

void hash_code_f()
{
    long long h=0;
    for(int i=0; s[i]; i++)
    {
        h = (((h*BASE)%MOD)+(long long)(s[i]-'a'+1))%MOD;
        a[i] = h;
    }
}

void hash_code_b()
{
    long long h=0;
    int i,j=0,l;
    l = strlen(s)-1;
    for(i=l; i>=0; i--)
    {
        h = (((h*BASE)%MOD)+(long long)(s[i]-'a'+1))%MOD;
        b[j] = h;
        j++;
    }
}

bool cmp(int l)
{
    int x = strlen(s);
    long long temp=0,rep=0;
    for(int i=l; i<x; i++)
    {
        rep = (b[i]-temp)%MOD;
        rep = (rep+MOD)%MOD;
        if(a[l]==rep)  return  true;
        temp = (b[i-l]*hh[l+1])%MOD;
    }
    return  false;
}

void match()
{
    int hi,lo,md,c=0;
    hi = strlen(s)-1;
    lo = 0;
    while(lo<=hi)
    {
        md = (lo+hi)/2;
        if(cmp(md))
        {
            lo = md+1;
            c = max(c,md);
        }
        else    hi = md-1;
    }
    for(int i=c; i>=0; i--)  printf("%c",s[i]);
    puts("");
}

int main()
{
    int t;
    scanf("%d",&t);
    pre();
    while(t--)
    {
        scanf("%s",s);
        hash_code_f();
        hash_code_b();
        match();
    }
    return  0;
}

/**
1
cccbbccccaaaaccbbaacab

output = cccbbccc
*/
