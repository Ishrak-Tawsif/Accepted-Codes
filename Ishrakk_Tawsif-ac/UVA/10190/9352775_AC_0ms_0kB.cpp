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
#define mx                      5005
#define mod                     100000007
#define intinf                  2e9
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())


bool boring;
vector<ll>vv;


int main()
{
    ll n,m;

        while(scanf("%lld %lld", &n,&m) == 2)
        {

            if ( n < 2 || m < 2 || m > n ) {
                printf ("Boring!\n");
                continue;
            }

            boring = false;
            vv.clear();

                while(n%m == 0)
                {
                    vv.pb(n);
                    n/=m;
                }

                    if(n==1) {

                        vv.pb(n);
                        for(int i=0; i<vv.size() && boring!=true; i++)
                        {
                            if(i == 0) pf("%d", vv[i]);
                            else pf(" %d", vv[i]);
                        }
                        pf("\n");
                    }
                    else pf("Boring!\n");
        }
    return 0;
}