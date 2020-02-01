#include<bits/stdc++.h>
using namespace std;

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
#define inf                     2e9
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      20000005
#define mod                     1000000007


int dx[8]={0,0,1,-1,1,1,-1,-1};
int dy[8]={1,-1,0,0,1,-1,1,-1};

int n;

struct ST
{
    double x,y;
};
ST ar[105];

double calcdist(double curx,double cury)
{
    double minidist = 0;
    for(int i=0; i<n; i++)
    {
        double xaxis = curx-ar[i].x;
        double yaxis = cury-ar[i].y;
        double totdist = (xaxis*xaxis) + (yaxis*yaxis);

        minidist += sqrt(totdist);
    }
    return minidist;
}

double t_search2(double xx)
{
    double st=0,en = 1e4,sn,th,ansy = inf;
    int cnt = 0;

    while(cnt<=205)
    {
        cnt ++;
        sn = ((st*2) + en)/3;
        th = (st + (en*2))/3;

        double temp = calcdist(xx,sn);
        double temp2 = calcdist(xx,th);

        if(temp>temp2) st = sn;
        else en = th;

        ansy = min(ansy,min(temp,temp2));
    }
    return ansy;
}

double t_search()
{
    double st = 0,en =1e4,sn,th,ansx = inf;
    int cnt = 0;

    while(cnt<=205)
    {
        cnt++;
        sn = ((st*2) + en)/3;
        th = (st + (en*2))/3;

        double temp = t_search2(sn);
        double temp2 = t_search2(th);

        if(temp>temp2) st = sn;
        else en = th;
        ansx = min(ansx,min(temp,temp2));
    }
    return ansx;
}

int main()
{
    int tc;

    sf(tc);

    for(int tt=1; tt<=tc; tt++)
    {
        sf(n);
        for(int i=0; i<n; i++)
        {
            scanf("%lf %lf", &ar[i].x, &ar[i].y);
        }
        double res = t_search();

        pf("%.0f\n", round(res));
        if(tt != tc) pf("\n");
    }

    return 0;
}