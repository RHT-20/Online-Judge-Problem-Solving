#include<bits/stdc++.h>
using namespace std;

struct MATRIX
{
    int SIZE;
    long long ara[20][20];
};
MATRIX mat;
long long column_matrix[20];
long long MOD;

void init()
{
    int k=0;
    for(int i=1; i<mat.SIZE; i++)
    {
        for(int j=0; j<mat.SIZE; j++)
        {
            if(j==k)    mat.ara[i][j] = 1;
            else    mat.ara[i][j] = 0;
        }
        k++;
    }
    return;
}

void print_matrix(MATRIX ma)
{
    for(int i=0; i<ma.SIZE; i++)
    {
        for(int j=0; j<ma.SIZE; j++)
        {
            printf("%lld ",ma.ara[i][j]);
        }
        puts("");
    }
    for(int i=0; i<ma.SIZE; i++)   printf("%lld ",column_matrix[i]);
    puts("");
    return;
}

MATRIX multiplication(MATRIX &ma,MATRIX &mb)
{
    MATRIX res;
    long long x;
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

long long gun(long long a[])
{
    long long x=0;
    for(int i=0; i<mat.SIZE; i++)
    {
        x = (x+(a[i]*column_matrix[i])%MOD)%MOD;
    }
    return  x;
}

MATRIX big_mod(long long n)
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
    int k;
    long long int n,m;
    MATRIX ans;

    while(scanf("%d %lld %lld",&k,&n,&m)==3 && k && n && m)
    {
        MOD = m;
        mat.SIZE = k;
        for(int i=0; i<k; i++)  scanf("%lld",&mat.ara[0][i]);
        for(int i=0; i<k; i++)  scanf("%lld",&column_matrix[k-i-1]);

        if(n<=k)    printf("%lld\n",1LL);
        else
        {
            init();
            ans = big_mod(n-k-1);
            printf("%lld\n",gun(ans.ara[0]));
        }
    }
    return  0;
}
