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
#define mx                      5005
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

int dp[5001][5001],ar[5001][5001],orgi[5001],n;

int call(int i,int j)
{
    if(i == j) return orgi[i];
    if(dp[i][j] != -1) return dp[i][j];

    int ans = -2e9;
    if(i+1<=n)ans = max(ans,call(i+1,j));
    if(j-1>=1)ans = max(ans,call(i,j-1));

    return dp[i][j] = max(ans,ar[j-i][i]);
}

int main()
{
//    READ("in.txt");
//    WRITE("out.txt");
    // n;

    sf(n);

    for(int i=1; i<=n; i++) sf(ar[0][i]),orgi[i] = ar[0][i];

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n-i; j++)
        {
            ar[i][j] = ar[i-1][j] ^ ar[i-1][j+1];
        }
    }

    mem(dp,-1);
    call(1,n);

    int l,r,q;

    sf(q);

    while(q--)
    {
        scanf("%d %d", &l,&r);
        if(dp[l][r] != -1)pf("%d\n", dp[l][r]);
        else pf("%d\n", call(l,r));
    }

    return 0;

}