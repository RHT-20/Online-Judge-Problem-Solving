#include<bits/stdc++.h>
using namespace std;

struct point
{
    double x,y;
};
point p1,p2,p3,p4;

bool check_same_line()
{
    point pa,pb;
    pa.x = p2.x-p1.x;
    pa.y = p2.y-p1.y;
    pb.x = p3.x-p1.x;
    pb.y = p3.y-p1.y;
    double d = (pa.x*pb.y)-(pa.y*pb.x);
    //cout<<"d = "<<d<<endl;
    return  (d==0.0);
}

void solve()
{
    double defx1 = p2.x-p1.x;
    double defx2 = p4.x-p3.x;
    double defy1 = p1.y-p2.y;
    double defy2 = p3.y-p4.y;

    double defc1 = (p2.x*p1.y)-(p1.x*p2.y);
    double defc2 = (p4.x*p3.y)-(p3.x*p4.y);

    double det = (defy1*defx2)-(defy2*defx1);

    //double slope1 = (p1.y-p2.y)/(p1.x-p2.x);
    //double slope2 = (p3.y-p4.y)/(p3.x-p4.x);
    //cout<<slope1<<" "<<slope2<<endl;

    if(det!=0.0)
    {
        double x = (defc1*defx2)-(defc2*defx1);
        x /= det;
        double y = (defy1*defc2)-(defy2*defc1);
        y /= det;
        printf("POINT %0.2lf %0.2lf\n",x,y);
    }
    else if(check_same_line())  puts("LINE");
    //else if(slope1==slope2) puts("LINE");
    else    puts("NONE");

    return;
}

int main()
{
    int t;
    scanf("%d",&t);
    puts("INTERSECTING LINES OUTPUT");
    while(t--)
    {
        scanf("%lf %lf %lf %lf",&p1.x,&p1.y,&p2.x,&p2.y);
        scanf("%lf %lf %lf %lf",&p3.x,&p3.y,&p4.x,&p4.y);
        solve();
    }
    puts("END OF OUTPUT");
    return 0;
}

