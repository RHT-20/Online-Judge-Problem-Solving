#include<bits/stdc++.h>
using namespace std;

#define MOD 10
#define LL long long int

struct MATRIX
{
    int SIZE;
    int ara[45][45];
};
MATRIX mat;

void set_identity_matrix(MATRIX &ma)
{
    ma.SIZE = mat.SIZE;
    for(int i=0; i<ma.SIZE; i++)
    {
        for(int j=0; j<ma.SIZE; j++)
        {
            if(i==j)    ma.ara[i][j] = 1;
            else    ma.ara[i][j] = 0;
        }
    }
    return;
}

void set_zero_matrix(MATRIX &ma)
{
    ma.SIZE = mat.SIZE;
    for(int i=0; i<ma.SIZE; i++)
    {
        for(int j=0; j<ma.SIZE; j++)    ma.ara[i][j] = 0;
    }
    return;
}

void print_matrix(const MATRIX &ma)
{
    for(int i=0; i<ma.SIZE; i++)
    {
        for(int j=0; j<ma.SIZE; j++)
        {
            if(j)   printf(" ");
            printf("%d",ma.ara[i][j]);
        }
        puts("");
    }
    return;
}

MATRIX multiplication(const MATRIX &ma,const MATRIX &mb)
{
    MATRIX res;
    int x;
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

MATRIX summation(const MATRIX &ma,const MATRIX &mb)
{
    MATRIX res;
    res.SIZE = ma.SIZE;

    for(int i=0; i<res.SIZE; i++)
    {
        for(int j=0; j<res.SIZE; j++)
        {
            res.ara[i][j] = (ma.ara[i][j]+mb.ara[i][j])%MOD;
        }
    }
    return  res;
}

MATRIX big_mod(LL n)
{
    MATRIX tmp1,tmp2,tmp3,tmp4,res;
    tmp1 = tmp2 = mat;
    set_identity_matrix(tmp3);
    set_zero_matrix(res);

    /*puts("xxxxxxxxxx");
    print_matrix(tmp1);
    puts("xxxxxxxxxxxx");
    print_matrix(tmp2);
    puts("xxxxxxxxxxxx");
    print_matrix(tmp3);
    puts("xxxxxxxxxxxx");
    print_matrix(res);*/

    while(n)
    {
        if(n&1)
        {
            tmp4 = multiplication(tmp1,tmp3);
            res = summation(res,tmp4);          /// res = res + a*c
            tmp3 = multiplication(tmp3,tmp2);   /// c = b*c
            n--;
        }
        else
        {
            tmp4 = multiplication(tmp1,tmp2);
            tmp1 = summation(tmp1,tmp4);        /// a = a + a*b
            tmp2 = multiplication(tmp2,tmp2);   /// b = b*b
            n >>= 1;
        }
    }
    return  res;
}

int main()
{
    //freopen("out.txt","w",stdout);
    int n,i,j;
    LL k;
    MATRIX ans;
    while(1)
    {
        scanf("%d %lld",&n,&k);
        if(!n)  break;
        mat.SIZE = n;

        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                scanf("%d",&mat.ara[i][j]);
                mat.ara[i][j] %= MOD;
            }
        }
        ans = big_mod(k);
        print_matrix(ans);
        puts("");
    }
    return  0;
}

/**
F() = A + A^2 + A^3 + ... + A^k
*/
