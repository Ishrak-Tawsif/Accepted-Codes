#include <bits/stdc++.h>
using namespace std;

int dx[8]={0,0,1,-1,1,1,-1,-1};
int dy[8]={1,-1,0,0,1,-1,1,-1};

/*#pragma comment(linker,"/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
#define sf(nn)                  scanf ("%d", &nn)
#define sfll(nn)                scanf ("%lld", &nn)
#define pf                      printf
#define casepf(nn)              printf ("Case %d: ",nn)
#define out(nn)                 cout <<nn <<endl
#define loop(var,start,till)    for(int var=start; var<till; var++)
#define loop1(var,start,till)   for(int var=start; var<=till; var++)
#define pb                      push_back
#define mem(a,b)                memset(a,b,sizeof(a))
#define mp                      make_pair
#define ll                      long long int
#define inf                     2e9
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define all(a)                  (a.begin(),a.end())
#define Unique_(a)              sort(all(a));a.erase(unique(all(a)),a.end())
#define mx                      100005
#define mod                     7901
#define left(n)                 (n<<1)
#define right(n)                ((n<<1) + 1)
#define fast                    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define PI                      acos(-1)
#define ull                     unsigned long long
#define eps                     .000000001
template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}
string tostring(ll res){string curstr="";while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}


/* ...........................................................................................................*/

int main()
{
    ll x,n;

    int tc;

    sf(tc);

    ll ar[1005];
    while(tc --)
    {
        scanf("%lld %lld", &x,&n);
        ll temp = x/n;

        mem(ar,0);

        if(x<=n)
        {
            for(int i=1; i<=n && x>0; i++,x--) ar[i] += 1;
            for(int i=1; i<=n; i++) {if(i == 1) pf("%lld", ar[i]); else pf(" %lld",ar[i]);}
            pf("\n");
            continue;
        }

        if(n == 1)
        {
            pf("%lld\n", x);
            continue;
        }

        for(int i=1; i<=n && x>0; i++,x--) ar[i] ++;

        if(x)
        {
            ll round = x / (n-1);//out(round);
            for(int i=2; i<n; i++) ar[i] += round;
            if(round %2 == 1) ar[1] += (round / 2) + 1,ar[n] += (round/2);
            else ar[1] += (round / 2), ar[n] += (round / 2);

            ll extra = (x % (n-1));

            round ++;

            ///

            ll now = round;
            x = extra;
            //for(int i=1; i<=n && x>0; i++,x--) ar[i] ++;
            while(x>0)
            {
                if(now%2 == 1)
                {
                    for(int i=n-1; i>=1 && x>0; i--,x--) ar[i] ++;
                }
                else for(int i=2; i<=n && x>0; i++,x--) ar[i] ++;
                now ++;
            }

            ///
        }

        for(int i=1; i<=n; i++) {if(i == 1) pf("%lld", ar[i]); else pf(" %lld",ar[i]);}
        pf("\n");

    }
    return 0;
}