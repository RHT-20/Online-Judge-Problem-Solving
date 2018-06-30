#include<bits/stdc++.h>
using namespace std;

#define MX 1000005
int prime[MX];
bool mark[MX];

bool check(int x)
{
    int y=0,z=x;
    while(x)
    {
        y += (x%10);
        x /= 10;
    }
    return  (mark[y] && mark[z]);
}

void pre_process()
{
    memset(mark,true,sizeof(mark));
    mark[0] = mark[1] = false;
    for(int i=4; i<MX; i+=2)   mark[i] = false;
    for(int i=3; i<MX; i+=2)
    {
        if(mark[i]==true)
        {
            for(int j=(i+i); j<MX; j+=i)   mark[j] = false;
        }
    }
    prime[0] = prime[1] = 0;
    for(int i=2; i<MX; i++)
    {
        prime[i] = prime[i-1]+check(i);
    }
}

int main()
{
    int t,a,b,ans;
    scanf("%d",&t);
    pre_process();
    while(t--)
    {
        scanf("%d %d",&a,&b);
        if(a>b) swap(a,b);
        ans = prime[b]-prime[a-1];
        printf("%d\n",ans);
    }
    return  0;
}
