#include<bits/stdc++.h>
using namespace std;

int dp[(1<<16)+10],r,c;
int fx[] = {-1,-1,-1,0,1,1,1,0};
int fy[] = {-1,0,1,1,1,0,-1,-1};

int set_bit(int n,int pos){ return  n = n|(1<<pos);}
int reset_bit(int n,int pos){ return  n = n&(~(1<<pos));}
bool check_bit(int n,int pos){ return  (bool)(n&(1<<pos));}

int solve(int mask,int n)
{
    if(n==1)    return  (__builtin_popcount(mask)==1);
    else if(dp[mask]!=-1)    return  dp[mask];
    int pos,dest,mid,temp,res=0;
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            pos = (i*r)+j;
            if(check_bit(mask,pos))
            {
                for(int k=0; k<8; k++)
                {
                    int dx1 = i+fx[k];
                    int dy1 = j+fy[k];
                    int dx2 = i+(2*fx[k]);
                    int dy2 = j+(2*fy[k]);
                    if(dx1>=0 && dx1<r && dy1>=0 && dy1<c && dx2>=0 && dx2<r && dy2>=0 && dy2<c)
                    {
                        mid = (dx1*r)+dy1;
                        dest = (dx2*r)+dy2;
                        if(check_bit(mask,mid) && check_bit(mask,dest)==false)
                        {
                            temp = reset_bit(mask,pos);
                            temp = reset_bit(temp,mid);
                            temp = set_bit(temp,dest);
                            res += solve(temp,n-1);
                        }
                    }
                }
            }
        }
    }
    return  dp[mask] = res;
}

int main()
{
    int t,cs=0,n,x,y,i,mask,temp;
    scanf("%d",&t);
    while(t--)
    {
        cs++;
        mask = 0;
        scanf("%d %d %d",&r,&c,&n);
        for(i=0; i<n; i++)
        {
            scanf("%d %d",&x,&y);
            temp = (x-1)*r+(y-1);
            mask |= (1 << temp);
        }
        memset(dp,-1,sizeof(dp));
        printf("Case %d: %d\n",cs,solve(mask,n));
    }
    return  0;
}
