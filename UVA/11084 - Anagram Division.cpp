#include<bits/stdc++.h>
using namespace std;

vector<int>v;
long long ans;

void solve(int d)
{
    ans = 0;
    long long x=0;
    for(int i=0; i<v.size(); i++)   x = (x*10)+v[i];
    if(x%d==0)  ans++;
    while(next_permutation(v.begin(),v.end()))
    {
        x = 0;
        for(int i=0; i<v.size(); i++)   x = (x*10)+v[i];
        if(x%d==0)  ans++;
    }
}

int main()
{
    int t,d,x,i;
    string str;
    scanf("%d",&t);
    while(t--)
    {
        v.clear();
        cin >> str >> d;
        for(i=0; i<str.size(); i++)
        {
            x = (int)str[i]-48;
            v.push_back(x);
        }
        sort(v.begin(),v.end());
        solve(d);
        printf("%lld\n",ans);
    }
    return  0;
}
