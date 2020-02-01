 #include<bits/stdc++.h>
using namespace std;

#define sf(nn)                  scanf ("%d", &nn)
#define sfll(nn)                scanf ("%lld", &nn)
#define pf                      printf
#define casepf(nn)              printf ("Case %d: ",nn)
#define out(nn)                 cout <<nn <<endl
#define loop(var,start,till)    for(int var=start; var<till; var++)
#define pb                      push_back
#define mem(a,b)                memset(a,b,sizeof(a))
#define mp                      make_pair
#define ll                      long long int
#define inf                     1e9
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      1000005
#define mod                     1000000007

///1/ab + 1/ef = 1/c

int main()
{
    double a,b,c;

    int tc;

    sf(tc);

    for(int tt=1; tt<=tc; tt++)
    {
        scanf("%lf %lf %lf", &a,&b,&c);

        double st=0,en=min(a,b),mid,ans=0.0;
        int it=0;

        while(st<=en)
        {
            it++;
            mid = (st+en)/2.0;
            double ab = sqrt((a*a)-(mid*mid));
            double ef = sqrt((b*b)-(mid*mid));
            double cc = (1.0/ab) + (1.0/ef);
            cc = 1.0/cc;

            if(cc<c) ans = mid,en=mid;
            else st = mid;

            if(it == 301) break;
        }
        casepf(tt);
        pf("%.11f\n", ans);
    }

    return 0;
}