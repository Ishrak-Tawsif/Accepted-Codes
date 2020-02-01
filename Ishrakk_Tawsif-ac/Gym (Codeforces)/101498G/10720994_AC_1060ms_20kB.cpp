#include<bits/stdc++.h>
using namespace std;

#define sf(nn)                  scanf ("%d", &nn)
#define sfll(nn)                scanf ("%lld", &nn)
#define pf                      printf
#define casepf(nn)              printf ("Case %d:\n",nn)
#define out(nn)                 cout <<nn <<endl
#define loop(var,start,till)    for(int var=start; var<till; var++)
#define pb                      push_back
#define mem(a,b)                memset(a,b,sizeof(a))
#define mp                      make_pair
#define ll                      long long int
#define intinf                  2e9
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      100005
#define mod                     1000000007


int dx[8] = {1,-1,0,0,-1,-1,1,1};
int dy[8] = {0,0,-1,1,-1,1,-1,1};

int dirr[] = {-1,-1,0,0,1,1};
int dirc[] = {0,1,-1,1,-1,0};

ll ar[2005];

ll lim = (2000*1e10);

ll __lcm(ll a,ll b)
{
    return (a/__gcd(a,b))*b;
}

int main()
{

    //READ("in.txt");

    int tc,n;

    sf(tc);

    loop(tt,0,tc)
    {
        sf(n);
        //mem(sum,0);
        loop(i,0,n) {sfll(ar[i]); /*sum[i] = (sum[i-1]+ar[i]);*/}

        ll ans = n;
        for(int i=0; i<n; i++)
        {
            ll cur=ar[i],fl=1,lcm=ar[i];
            for(int j=i+1;j<n; j++)
            {
                cur += ar[j];//cout<<lcm<<endl;
                lcm = (ll)((ll)(__lcm(lcm,ar[j])));

                if(lcm>lim) break;

                if(!(cur%lcm)) ans++;
                //else {fl=0;break;}
                //cnt++;cout<<i<<" " << cnt-1 << " " << cur << " " << ans << endl;
            }
        }

        pf("%lld\n", ans);
    }
    return 0;
}