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
#define mx                      100005
#define mod                     998244353
#define left(n)                 (n<<1)
#define right(n)                ((n<<1) + 1)
#define fast                    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define PI                      acos(-1)
#define bitOff(N,in)            (N&(~(1LL<<(in))))
#define bitOn(N,in)             (N|(1LL<<(in)))
#define ull                     unsigned long long
#define eps                     .000000001

template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}
string tostring(ll res){string curstr="";if(!res) curstr += ((char)res + '0');while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}

/* ...........................................................................................................*/

int x,n,dp[1003][15],ar[1003][15];

int call(int d,int h)
{
    if(d>n || h<0 || h>9) return 2e9;
    if(d == n)
    {
        if(h == 0) return 0;
        return 2e9;
    }

    if(dp[d][h] != -1) return dp[d][h];

    int ans = 2e9;

    ans = min(ans,call(d+1,h+1) + (60-ar[d][h]));
    ans = min(ans,call(d+1,h-1) + (20-ar[d][h]));
    ans = min(ans,call(d+1,h) + (30-ar[d][h]));
 //cout<<" ok "<<ans<<endl;
    return dp[d][h] = ans;
}

int main()
{//READ("in.txt");
    int tc;

    sf(tc);

    for(int tt=1; tt<=tc; tt++)
    {
        sf(x);
        n = x/100;

        for(int i=9; i>=0; i--)
        {
            for(int j=0; j<n; j++) sf(ar[j][i]);
        }

        mem(dp,-1);
        pf("%d\n", call(0,0));
        pf("\n");
    }

    return 0;
    
}