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

int n,m,r;
ll ar[503],res,dp[503][53];

ll call(int ind,int curm)
{
    if(ind > n)
    {
        if(curm == m) return 0;
        else {return -2e14;}
    }
    
    if(curm == m) return 0;
    
    if(dp[ind][curm] != -1) return dp[ind][curm];

    ll ans = -2e14,sum = 0,ans2 = 0;
    int cnt = 0,st;

    for(int i=ind; i<=n; i++)
    {
        cnt++;
        sum = sum + (ar[i]*(ll)cnt);
        if(curm + cnt <= m)
        {
            if(cnt <= r)
            {
                ans = max(ans,call(ind+cnt+1,curm+cnt)+sum);
                for(int j=1; ; j++)
                {
                    if(ind+cnt+j<=n) ans = max(ans,(call(ind+cnt+j,curm+cnt)+sum));
                    else break;
                }
            }
        }
    }

    return dp[ind][curm] = ans;
}

int main()
{
    scanf("%d %d %d", &n,&m,&r);
    
    for(int i=1; i<=n; i++) sfll(ar[i]);

    res = -2e14;

    int now = r + 1;
    now = n/now + n%(r+1);

    mem(dp,-1);
    for(int i=1; i<=n; i++) res = max(call(i,0),res);

    if(res>=0)out(res);

    else pf("-1\n");

    return 0;

}

/*
10 3 3
10 10 9 6 5 4 2 1 4 4

10 6 1
1 2 3 4 5 6 7 8 9 10

5 3 2
1 2 3 4 5

output: 16

*/