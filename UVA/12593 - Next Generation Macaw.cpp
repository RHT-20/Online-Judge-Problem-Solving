#include<bits/stdc++.h>
using namespace std;

#define MOD 10007
#define LL long long int
struct MATRIX
{
    int SIZE;
    LL ara[105][105];
};
MATRIX mat;
LL column_matrix[105];

void init(int k)
{
    mat.SIZE = k;

    for(int i=1; i<=mat.SIZE; i++)
    {
        for(int j=1; j<=mat.SIZE; j++)
        {
            if(i==1)
            {
                if(j==1)    mat.ara[i][j] = 0;
                else    mat.ara[i][j] = 1;
            }
            else
            {
                if(j==(i-1))    mat.ara[i][j] = 1;
                else    mat.ara[i][j] = 0;
            }
        }
    }

    for(int i=1; i<=mat.SIZE; i++)
    {
        if(i==1)    column_matrix[i] = 1;
        else    column_matrix[i] = 0;
    }
    return;
}

void getIdentityMatrix(MATRIX &idm)
{
    idm.SIZE = mat.SIZE;
    for(int i=1; i<=idm.SIZE; i++)
    {
        for(int j=1; j<=idm.SIZE; j++)
        {
            if(i==j)    idm.ara[i][j] = 1;
            else    idm.ara[i][j] = 0;
        }
    }
    return;
}

void print_matrix(const MATRIX &ma)
{
    for(int i=1; i<=ma.SIZE; i++)
    {
        for(int j=1; j<=ma.SIZE; j++)
        {
            printf("%lld ",ma.ara[i][j]);
        }
        puts("");
    }
    for(int i=1; i<=ma.SIZE; i++)   printf("%lld ",column_matrix[i]);
    puts("");
    return;
}

MATRIX multiplication(const MATRIX &ma,const MATRIX &mb)
{
    MATRIX res;
    LL x;
    res.SIZE = ma.SIZE;

    for(int i=1; i<=ma.SIZE; i++)
    {
        for(int j=1; j<=ma.SIZE; j++)
        {
            x = 0;
            for(int k=1; k<=ma.SIZE; k++)
            {
                x = (x+(ma.ara[i][k]*mb.ara[k][j])%MOD)%MOD;
            }
            res.ara[i][j] = x;
        }
    }
    return  res;
}

LL gun(const MATRIX &ma)
{
    LL x=0,y;
    for(int i=1; i<=ma.SIZE; i++)
    {
        for(int j=1; j<=ma.SIZE; j++)
        {
            y = (ma.ara[i][j]*column_matrix[j])%MOD;
            x = (x+y)%MOD;
        }
    }
    x = (x*2LL)%MOD;
    return  x;
}

MATRIX big_mod(LL n)
{
    MATRIX res,temp;
    getIdentityMatrix(res);
    //print_matrix(res);
    temp = mat;

    while(n)
    {
        if(n&1)
        {
            res = multiplication(res,temp);
            n--;
        }
        else
        {
            temp = multiplication(temp,temp);
            n >>= 1;
        }
    }
    return  res;
}

int main()
{
    int t,cs=0,k;
    LL n;
    MATRIX ans;
    scanf("%d",&t);
    while(t--)
    {
        cs++;
        scanf("%lld %d",&n,&k);
        printf("Case %d: ",cs);
        if(n==1)
        {
            puts("2");
            continue;
        }
        init(k);
        //print_matrix(mat);
        ans = big_mod(n-1);
        printf("%lld\n",gun(ans));
    }
    return  0;
}

