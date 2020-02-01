#include<bits/stdc++.h>
using namespace std;

int dx[8]={0,0,1,-1,1,1,-1,-1};
int dy[8]={1,-1,0,0,1,-1,1,-1};

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
#define inf                     2e9
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      20000005
#define mod                     1000000007

int main()
{
    string str;

    cin>> str;
    ll ans = 0,cntb = 0;

    int len = str.length() - 1;

    for(int i=len; i>=0; i--)
    {
        if(str[i] == 'b') cntb++;
        else
        {//cout<<ans<<" "<<cntb<<endl;
            ans = (ans+cntb)%mod;//out(ans);
            ans = ans%mod;
            cntb = (cntb * 2)%mod;
        }
    }
    pf("%lld\n", ans);

    return 0;
}