#include<bits/stdc++.h>
using namespace std;

struct MATRIX
{
    int SIZE;
    long long ara[25][25];
};
MATRIX mat;
long long column_matrix[25];
long long MOD;

void init()
{
    int k=0;
    for(int i=1; i<(mat.SIZE-1); i++)
    {
        for(int j=0; j<mat.SIZE; j++)
        {
            if(j==k)    mat.ara[i][j] = 1;
            else    mat.ara[i][j] = 0;
        }
        k++;
    }
    if((mat.SIZE-1))
    {
        for(int i=0; i<mat.SIZE; i++)   mat.ara[mat.SIZE-1][i] = 0;
        mat.ara[mat.SIZE-1][mat.SIZE-1] = 1;
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
    bool f=false;
    int k,t;
    long long int n,m;
    MATRIX ans;
    scanf("%d",&t);
    while(t--)
    {
        if(f)   puts("");
        f = true;
        scanf("%d %lld %lld",&k,&m,&n);
        MOD = m;
        mat.SIZE = k+1;
        for(int i=0; i<=k; i++)
        {
            scanf("%lld",&mat.ara[0][i]);
            mat.ara[0][i] %= MOD;
            mat.ara[0][i] += MOD;
            mat.ara[0][i] %= MOD;
        }
        for(int i=0; i<k; i++)
        {
            scanf("%lld",&column_matrix[k-i-1]);
            column_matrix[k-i-1] %= MOD;
            column_matrix[k-i-1] += MOD;
            column_matrix[k-i-1] %= MOD;
        }
        column_matrix[k] = 1;
        if(!k)  printf("%lld\n",mat.ara[0][mat.SIZE-1]%MOD);
        else if(n<k)    printf("%lld\n",column_matrix[k-n-1]);
        else
        {
            init();
            ans = big_mod(n-k);
            printf("%lld\n",gun(ans.ara[0]));
        }
    }
    return  0;
}
