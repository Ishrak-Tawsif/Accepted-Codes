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


int main()
{
  int tc;
  ll n;

    sf(tc);

        loop(tt,0,tc)
        {
            scanf("%lld", &n);

                ll nn=n,st,ttt;
                while(1)
                {
                    ll temp = sqrt(nn);
                    if(temp*temp == nn) {st=nn;ttt=temp;break;}
                    else nn--;
                }
                pf("Case %d:",tt+1);

                for(ll i=ttt; i>=1; i--)
                {
                    ll x = (n-(i*i));
                    ll srt = sqrt(n-x);
                    //ll ans = x%srt;

                    if(x%srt== 0 && x>=1) pf(" %lld", x);
                }
                pf("\n");
        }
}