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
#define mx                      262144+7
#define mod                     10056
#define left(n)                 (n<<1)
#define right(n)                ((n<<1) + 1)
#define fast                    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define PI                      acos(-1)
#define ull                     unsigned long long
template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}
string tostring(ll res){string curstr="";while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}


/* ...........................................................................................................*/

///idea - catalan number
///pdf ::: http://www.geometer.org/mathcircles/catalan.pdf
/*
/// Counting Non-Crossing Handshakes

To count the number of hand-shakes discussed in Section 1.5 we can use an analysis similar to that
used in section 2.1.
If there are 2n people at the table pick any particular person, and that person will shake hands
with somebody. To admit a legal pattern, that person will have to leave an even number of people on
each side of the person with whom he shakes hands. Of the remaining n − 1 pairs of people, he can
leave zero on the right and n−1 pairs on the left, 1 on the right and n−2 on the left, and so on. The
pairs left on the right and left can independently choose any of the possible non-crossing handshake
patterns.

so again, the count Cn for n pairs of people is given by:
Cn = Cn−1C0 + Cn−2C1 + · · · + C1Cn−2 + C0Cn−1,
which, together with the fact that C0 = C1 = 1, is just the definition of the Catalan numbers.

*/

///Can be solved by dp or following to formula -

///first formula - ncr(2n,n) - ncr(2n,n-1)
///second formula - 2n! / ((n+1)! * n!)



int n,dp[23];

int catalan(int cur)
{
    if(cur == 0) return 1;
    if(cur == 2) return 1;

    if(dp[cur] != -1) return dp[cur];

    int ans = 0;
    for(int i=0; i<=cur-2; i += 2)
    {
        int left = i;
        int right = (cur - 2 - i);
        ans += (catalan(left) * catalan(right));
    }
    return dp[cur] = ans;
}

int main()
{
    int fl = 0;
    while(cin >>n)
    {
        if(fl) pf("\n");
        fl = 1;

        n *= 2;
        mem(dp,-1);
        int ans = catalan(n);

        out(ans);
    }
    return 0;
}