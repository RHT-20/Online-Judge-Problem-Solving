#include<bits/stdc++.h>
using namespace std;

int main()
{
    double n,p,k;
    while(scanf("%lf %lf",&n,&p)==2)
    {
        k = log10(p);
        k /= n;
        k = exp(k*log(10)); /// anti log
        printf("%0.0lf\n",round(k));
    }
    return  0;
}

