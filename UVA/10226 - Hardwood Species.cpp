#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,c;
    map<string,int>mp;
    char a[35];
    scanf("%d\n\n",&t);
    while(t--)
    {
        mp.clear();
        c = 0;
        while(gets(a))
        {
            if(strlen(a)==0)    break;
            mp[string(a)]++;
            c++;
        }
        map<string,int>::iterator it;
        for(it=mp.begin(); it!=mp.end(); it++)
        {
            printf("%s %0.4lf\n",(*it).first.data(),((double)((*it).second)*100.0)/c);
        }
        if(t>0) puts("");
    }
    return 0;
}
