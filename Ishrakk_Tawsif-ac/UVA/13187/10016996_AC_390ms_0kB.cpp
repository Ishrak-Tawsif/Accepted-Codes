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
#define ll                      unsigned long long int
#define intinf                  2e9
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      100005
#define mod                     100000007


int main()
{
    /*double n,ans=0.0;
    cin>> n;

        for(int i=1; ;i++)
        {
            double temp = (i*1.0);
            double ttmm = temp+1.0;
            ans += (1.0/(sqrt(temp)+sqrt(ttmm)));cout<<ans<<endl;
            if(ans >= n){cout<<i<<endl;break;}
        }*/

        int tc;
        sf(tc);

        while(tc--){
            ll n;
            cin>> n;
            ll ans = (n*n) + (2*n);

            cout<<ans<<endl;
        }
    return 0;
}