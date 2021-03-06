#include <bits/stdc++.h>
#include <ext/rope>

using namespace __gnu_cxx;
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
#define left(n)                 (n<<1)
#define right(n)                ((n<<1) + 1)
#define fast                    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define PI                      acos(-1)
#define bitOff(N,in)            (N&(~(1LL<<(in))))
#define bitOn(N,in)             (N|(1LL<<(in)))
#define ull                     unsigned long long
#define eps                     .000000001

#define mx                      2000005
#define mod                     998244353

template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}
string tostring(ll res){string curstr="";if(!res) curstr += ((char)res + '0');while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}

/* ...........................................................................................................*/

vector <ll> prime;
bitset <mx> isprime;

void sieve()
{
    prime.pb((ll)2);

    for(int i=3; i*i<mx; i+=2)
    {
        if(!isprime[i])
        {
            for(int j=i*i; j<mx; j+=i) isprime[j] = 1;
        }
    }
    for(int i=3; i<mx; i+=2) if(!isprime[i]) prime.pb((ll)i);
}

void factor(ll n)
{
    for(int i=0; prime[i]*prime[i]<=n && i<prime.size() ; i++)
    {
        if(n%prime[i] == 0)
        {
            while(n%prime[i] == 0) cout<<" "<<prime[i],n/=prime[i];
        }
    }
    if(n != 1) cout<<" "<<n;
    cout<<endl;
}

ll ipow(ll b,ll p)
{
    ll res = 1;

    while(p --) res *= b;

    return res;
}

int main()
{


        int n,m;

        int tc;

        scanf("%d", &tc);

        for(int tt=1; tt<=tc; tt++)
        {

            scanf("%d %d", &n,&m);

            int two = 0, three = 0;

            if(n%2 == 0) two = 1,three = 0;
            else
            {
                if(n%3 == 0) two = 2,three = 2;
                else two = 2,three = 1;
            }

            int tw = 0, th = 0;

            if(m%2 == 0) tw = 1, th = 0;
            else
            {
                if(m%3 == 0) tw = 2, th = 2;
                else tw = 2, th = 1;
            }
            int fintw = min(two,tw);
            int finth = min(three,th);

            ll ans = 1;

            while(fintw--) ans *= 2;
            while(finth--) ans *= 3;

            printf("%lld\n", ans);
        }

    return 0;

}