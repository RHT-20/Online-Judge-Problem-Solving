#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007LL
#define BASE 347LL
map<long long,string>mpe;
map<string,long long>mpf;
map<long long,bool>mpc;

long long hashing(char s[])
{
    int i;
    long long hashs=0,power=1,temp=0,x;
    for(i=0; s[i]; i++)
    {
        x = (long long)s[i];
        temp = (x*power);
        hashs = (hashs+temp);
        power = (power*BASE);
    }
    return  hashs;
}

int main()
{
    long long x=0;
    char str[25],temp1[15],temp2[25];
    while(gets(str))
    {
        if(strlen(str)==0)  break;
        sscanf(str,"%s %s",temp1,temp2);
        x = hashing(temp2);
        mpe[x] = (string)temp1;
        mpf[(string)temp2] = x;
        mpc[x] = true;
    }
    while(scanf("%s",str)!=EOF)
    {
        x = hashing(str);
        if(mpc[x] && mpf[(string)str]==x)   printf("%s\n",mpe[x].c_str());
        else    puts("eh");
    }
    return  0;
}
