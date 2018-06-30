#include<bits/stdc++.h>
using namespace std;

#define MOD     10007
#define LL      long long int
#define PC(x)   __builtin_popcount(x)
#define PII     pair<int,int>

struct MATRIX
{
    int SIZE;
    LL ara[75][75];
};
struct MATRIX_ARRY
{
    bool flag;
    MATRIX mat;
};
MATRIX_ARRY mat_arry[40];
vector<int>node;
vector<PII>edge;

int set_bit(int mask,int pos){  return  (mask | (1<<pos));}
bool check_bit(int mask,int pos){   return  (mask & (1<<pos));}

bool check1(int mask1,int mask2)
{
    if((mask1<<2)&mask2 || (mask1>>2)&mask2)    return  false;
    return  true;
}

bool check2(int mask1,int mask2,int mask3)
{
    if(!check1(mask1,mask2) || !check1(mask2,mask3))  return  false;
    else if((mask1<<1)&mask3 || (mask1>>1)&mask3)     return  false;
    return  true;
}

void init()
{
    int limit = (1<<6);
    /// 6 X 1
    while(limit--)
    {
        if(PC(limit)==2)    node.push_back(limit);
    }
    /// 6 X 2
    for(int i=0; i<node.size(); i++)
    {
        for(int j=0; j<node.size(); j++)
        {
            if(check1(node[i],node[j])) edge.push_back(PII(node[i],node[j]));
        }
    }
    mat_arry[0].mat.SIZE = edge.size();
    /// 6 X 3
    for(int i=0; i<edge.size(); i++)
    {
        for(int j=0; j<edge.size(); j++)
        {
            if(edge[i].second==edge[j].first)
            {
                if(check2(edge[i].first,edge[i].second,edge[j].second))
                {
                    mat_arry[0].mat.ara[i][j]++;
                }
            }
        }
    }
    return;
}

void print_matrix(const MATRIX &ma)
{
    for(int i=0; i<ma.SIZE; i++)
    {
        for(int j=0; j<ma.SIZE; j++)
        {
            printf("%lld ",ma.ara[i][j]);
        }
        puts("");
    }
    return;
}

MATRIX multiplication(const MATRIX &ma,const MATRIX &mb)
{
    MATRIX res;
    LL x;
    res.SIZE = ma.SIZE;

    for(int i=0; i<ma.SIZE; i++)
    {
        for(int j=0; j<ma.SIZE; j++)
        {
            x = 0;
            for(int k=0; k<ma.SIZE; k++)
            {
                x = (x+(ma.ara[i][k]*mb.ara[k][j])%MOD)%MOD;
            }
            res.ara[i][j] = x;
        }
    }
    return  res;
}

LL summation(const MATRIX &ma)
{
    LL x = 0;
    for(int i=0; i<ma.SIZE; i++)
    {
        for(int j=0; j<ma.SIZE; j++)
        {
            x = (x+ma.ara[i][j])%MOD;
        }
    }
    return  x;
}

MATRIX big_mod(LL n)
{
    int c = 1;
    MATRIX res,temp;
    res = temp = mat_arry[0].mat;
    //print_matrix(res);

    while(n)
    {
        if(n&1)
        {
            res = multiplication(res,temp);
            n--;
        }
        else
        {
            if(mat_arry[c].flag)    temp = mat_arry[c].mat;
            else
            {
                temp = multiplication(temp,temp);
                mat_arry[c].mat = temp;
                mat_arry[c].flag = true;
            }
            n >>= 1;
            c++;
        }
    }
    //print_matrix(res);
    return  res;
}

int main()
{
    int t;
    LL n;
    MATRIX ans;

    scanf("%d",&t);
    init();
    //print_matrix(mat_arry[0].mat);

    while(t--)
    {
        scanf("%lld",&n);
        if(n==1)    puts("15");
        else if(n==2)   puts("69");
        else
        {
            ans = big_mod(n-3);
            printf("%lld\n",summation(ans));
        }
    }
    return  0;
}

