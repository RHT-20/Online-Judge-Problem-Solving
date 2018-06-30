#include<bits/stdc++.h>
using namespace std;

vector<int>light;
int dist[1<<15],n,m;
queue<int>q;

int set_bit(int n,int pos){ return  n = n|(1<<pos);}
int reset_bit(int n,int pos){ return  n = n&(~(1<<pos));}
bool check_bit(int n,int pos){ return  (bool)(n&(1<<pos));}

void process()
{
    int temp,i,x;
    while(!q.empty())
    {
        temp = q.front();
        q.pop();
        for(i=0; i<light.size(); i++)
        {
            x = temp^light[i];
            if(x==0)  continue;
            else if(dist[x]==-1 || dist[x]>(dist[temp]+1))
            {
                dist[x] = dist[temp]+1;
                q.push(x);
            }
        }
    }
}

int main()
{
    int t,cs=0,i,k,x,temp,qq;
    char str[50];
    scanf("%d",&t);
    while(t--)
    {
        cs++;
        light.clear();
        memset(dist,-1,sizeof(dist));
        dist[0] = 0;
        scanf("%d %d",&n,&m);
        for(i=0; i<m; i++)
        {
            scanf("%d",&k);
            temp = 0;
            while(k--)
            {
                scanf("%d",&x);
                temp = set_bit(temp,x);
            }
            if(dist[temp]==-1)
            {
                light.push_back(temp);
                dist[temp] = 1;
                q.push(temp);
            }
        }
        process();
        scanf("%d",&qq);
        printf("Case %d:\n",cs);
        while(qq--)
        {
            scanf("%s",&str);
            temp = 0;
            k = 0;
            for(i=(strlen(str)-1); i>=0; i--)
            {
                if(str[i]=='1') temp = set_bit(temp,k);
                k++;
            }
            printf("%d\n",dist[temp]);
        }
        puts("");
    }
    return  0;
}
