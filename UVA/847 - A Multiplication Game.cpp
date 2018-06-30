#include<bits/stdc++.h>
using namespace std;

long long n;

int can_win()
{
    int w = 1;
    while(n>1)
    {
        if(w)
        {
            if(n%9==0)  n /= 9;
            else    n = (n/9)+1;
            w = 0;
        }
        else
        {
            if(n%2==0)  n /= 2;
            else    n = (n/2)+1;
            w = 1;
        }
    }
    if(n==1 && w==0)    return  1;
    else    return  0;
}

int main()
{
    while(scanf("%lld",&n)==1)
    {
        if(can_win())  puts("Stan wins.");
        else    puts("Ollie wins.");
    }
    return 0;
}

