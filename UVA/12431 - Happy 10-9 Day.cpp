#include<bits/stdc++.h>
using namespace std;

struct MATRIX
{
    unsigned int SIZE;
    long long int ara[5][5];
};
MATRIX mat;
long long int column_matrix[5];
long long int MOD;

void init(long long int b,long long int d)
{
    mat.SIZE = 2;

    mat.ara[0][0] = b;
    mat.ara[1][0] = 0;
    mat.ara[0][1] = mat.ara[1][1] = 1;

    column_matrix[0] = d;
    column_matrix[1] = d;
    return;
}

void print_matrix(const MATRIX &ma)
{
    for(unsigned int i=0; i<ma.SIZE; i++)
    {
        for(unsigned int j=0; j<ma.SIZE; j++)
        {
            printf("%lld ",ma.ara[i][j]);
        }
        puts("");
    }
    for(unsigned int i=0; i<ma.SIZE; i++)   printf("%lld ",column_matrix[i]);
    puts("");
    return;
}

long long int multi(long long int x,long long int n)
{
    long long int res = 0;
    while(n)
    {
        if(n&1)
        {
            res = (res+x)%MOD;
            n--;
        }
        else
        {
            x = (x+x)%MOD;
            n >>= 1;
        }
    }
    return  res;
}

MATRIX multiplication(const MATRIX &ma,const MATRIX &mb)
{
    MATRIX res;
    long long int x;
    res.SIZE = ma.SIZE;

    for(unsigned int i=0; i<ma.SIZE; i++)
    {
        for(unsigned int j=0; j<ma.SIZE; j++)
        {
            x = 0;
            for(unsigned int k=0; k<ma.SIZE; k++)
            {
                x = (x+multi(ma.ara[i][k],mb.ara[k][j]))%MOD;
                //x = (x+(ma.ara[i][k]*mb.ara[k][j])%MOD)%MOD;
            }
            res.ara[i][j] = x;
        }
    }
    return  res;
}

long long int gun(long long int a[])
{
    long long int x=0;
    for(unsigned int i=0; i<mat.SIZE; i++)
    {
        x = (x+(a[i]*column_matrix[i])%MOD)%MOD;
    }
    return  x;
}

MATRIX big_mod(long long int n)
{
    MATRIX res,temp;
    res = temp = mat;

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
    int t,cs=0;
    long long int n,b,d;
    MATRIX ans;
    scanf("%d",&t);

    while(t--)
    {
        cs++;
        scanf("%lld %lld %lld %lld",&n,&b,&d,&MOD);

        printf("Case %d: ",cs);
        if(n==1)    printf("%lld\n",(d%MOD));
        else
        {
            init(b,d);
            //print_matrix(mat);
            ans = big_mod(n-2);
            //print_matrix(ans);
            printf("%lld\n",gun(ans.ara[0]));
        }
    }
    return  0;
}

