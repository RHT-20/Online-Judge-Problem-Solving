#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
vector<pii>point,res;

bool compare(pii a,pii b)
{
    return  (a.first<b.first);
}

int main()
{
    int t,m,x,y,i,left_min;
    pii pre,current;
    bool f=false,hobe;
    scanf("%d",&t);
    while(t--)
    {
        if(f)   puts("");
        f = true;
        point.clear();
        res.clear();
        scanf("%d",&m);
        while(1)
        {
            scanf("%d %d",&x,&y);
            if(!x && !y)    break;
            if(x>m || y<0)  continue;
            point.push_back(pii(x,y));
        }
        sort(point.begin(),point.end(),compare);
        pre = point[0];
        if(pre.first>0)
        {
            puts("0");
            continue;
        }
        else if(pre.first<=0 && pre.second>=m)
        {
            printf("1\n");
            printf("%d %d\n",pre.first,pre.second);
            continue;
        }
        left_min = 0;
        hobe = false;
        for(i=1; i<point.size(); i++)
        {
            current = point[i];
            if(current.first<=left_min && current.second>pre.second)  pre = current;
            else if(current.first>=pre.first && current.first<=pre.second && current.second>pre.second)
            {
                res.push_back(pre);
                left_min = pre.second;
                if(left_min>=m)
                {
                    hobe = true;
                    break;
                }
                pre = current;
            }
        }
        if(!hobe && pre.second>=m)
        {
            res.push_back(pre);
            hobe = true;
        }
        if(hobe)
        {
            printf("%d\n",res.size());
            for(i=0; i<res.size(); i++) printf("%d %d\n",res[i].first,res[i].second);
        }
        else    puts("0");
    }
    return  0;
}

/**
2
6
-4 3
-2 2
0 4
4 6
5 12
0 0

27
8 30
-15 7
8 9
-19 6
8 24
0 0
*/
