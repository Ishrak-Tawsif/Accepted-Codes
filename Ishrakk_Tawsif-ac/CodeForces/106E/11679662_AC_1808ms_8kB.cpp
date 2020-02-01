#include<bits/stdc++.h>
using namespace std;

int dx[8]={0,0,1,-1,1,1,-1,-1};
int dy[8]={1,-1,0,0,1,-1,1,-1};

#define sf(nn)                  scanf ("%d", &nn)
#define sfll(nn)                scanf ("%lld", &nn)
#define pf                      printf
#define casepf(nn)              printf ("Case #%d: ",nn)
#define out(nn)                 cout <<nn <<endl
#define loop(var,start,till)    for(int var=start; var<till; var++)
#define pb                      push_back
#define mem(a,b)                memset(a,b,sizeof(a))
#define mp                      make_pair
#define ll                      long long int
#define inf                     1e4
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      20000005
#define mod                     1000000007

double x,y,z,curx,cury,curz,resx,resy,resz,ansx,ansy,ansz;
int nn;
struct ST
{
    double xx,yy,zz;
};
ST ar[103];

double calcdist(double a,double b,double c,double d,double e,double f)
{
    a -= d;
    b -= e;
    c -= f;

    return sqrt((a*a) + (b*b) + (c*c));
}

double calc(double n,double m,double p)
{
    double temp1,temp2,ans=0;
    for(int i=0; i<nn; i++)
    {
        temp1 = calcdist(n,m,p,ar[i].xx,ar[i].yy,ar[i].zz);
        ans = max(ans,temp1);
    }
    return ans;
}

double ternerysearch3(double n,double m)
{
    double st = -inf,en = inf,sn,th,ans = 2e18;

    int cnt = 0;

    while(cnt<=60)
    {
        cnt++;

        sn = ((st*2) + en)/3;
        th = (st + (en*2))/3;

        double temp1 = calc(n,m,sn);
        double temp2 = calc(n,m,th);

        if(temp1>temp2)
        {
            st = sn;
            resz = sn;
        }
        else
        {
            en = th;
            resz = th;
        }
        ans = min(ans,min(temp1,temp2));
    }
    return ans;
}

double ternerysearch2(double n)
{
    resy = inf;
    double st = -inf,en = inf,sn,th,ans = 2e18;

    int cnt = 0;

    while(cnt<=60)
    {
        cnt++;

        sn = ((st*2) + en)/3;
        th = (st + (en*2))/3;

        double temp1 = ternerysearch3(n,sn);
        double temp2 = ternerysearch3(n,th);

        if(temp1>temp2)
        {
            st = sn;
            resy = sn;
        }
        else
        {
            en = th;
            resy = th;
        }
        ans = min(ans,min(temp1,temp2));
    }
    return ans;
}

void ternerysearch()
{
    double st = -inf,en = inf,sn,th,ans = 2e18;

    int cnt = 0;

    while(cnt<=60)
    {
        cnt++;
        sn = ((st*2) + en)/3;
        th = (st + (en*2))/3;

        double temp1 = ternerysearch2(sn);//out("ok");
        double temp2 = ternerysearch2(th);//out("ok2");

        if(temp1>temp2)
        {
            st = sn;
            ansx = sn;
            ansy = resy;
            ansz = resz;
        }
        else
        {
            en = th;
            ansx = th;
            ansy = resy;
            ansz = resz;
        }//pf("%.9f\n", ansx);
        //ans = min(ans,min(temp1,temp2));
    }
    //return ans;
}

int main()
{
    //int n;
    sf(nn);

    for(int i=0; i<nn; i++)
    {
        scanf("%lf %lf %lf", &ar[i].xx, &ar[i].yy, &ar[i].zz);
    }
    ternerysearch();
    pf("%.9f %.9f %.9f\n", ansx,ansy,ansz);

    return 0;
}