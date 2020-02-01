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
#define inf                     2e9
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      20000005
#define mod                     1000000007

double sx,sy,x2,y2,dxx1,dyy1,dxx2,dyy2;

double calc(double tmm)
{
    double xx = sx + ((dxx1-sx)*tmm);
    double yy = sy + ((dyy1-sy)*tmm);
    double xx1 = x2 + ((dxx2-x2)*tmm);
    double yy1 = y2 + ((dyy2-y2)*tmm);

    return sqrt(((xx-xx1)*(xx-xx1)) + ((yy-yy1)*(yy-yy1)));
}

double trenerysearch()
{
    double st = 0.0,en = 1.0,sn,th,ans = inf*1.0;
    int cnt = 0;

    while(cnt<=200)
    {
        cnt++;
        sn = ((2.0*st) + en)/3.0;
        th = (st + (en*2.0))/3.0;

        double temp1 = calc(sn);
        double temp2 = calc(th);

        if(temp1>temp2) st = sn;
        else en = th;

        ans = min(ans,min(temp1,temp2));
    }
    return ans;
}

int main()
{
    int tc;

    sf(tc);

    for(int tt=1; tt<=tc; tt++)
    {
        cin>> sx>>sy>>dxx1>>dyy1>>x2>>y2>>dxx2>>dyy2;

        double res = trenerysearch();
        printf("Case %d: %.9f\n", tt,res);
    }
    return 0;
}