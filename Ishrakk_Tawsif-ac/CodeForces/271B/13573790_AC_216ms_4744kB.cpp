///>>>>>>>>>>>>>>>>>>>>

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
#define casepf(nn)              printf ("Case #%d: ",nn)
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
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      100005
#define mod                     1000000007
#define flush                   fflush(stdout)

template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}

string tostring(ll res){string curstr="";while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}

/* ...........................................................................................................*/

bitset <mx> isprime;
set <int> prime;
int ar[503][503];

void sieve()
{
    prime.insert(2);
    for(int i=3; i*i<mx; i+=2)
    {
        if(!isprime[i])
        {
            for(int j=i*i; j<mx; j+=i) isprime[j] = 1;
        }
    }
    for(int i=3; i<mx; i+=2) if(!isprime[i]) prime.insert(i);
}

int main()
{
    sieve(); //out(prime.size());
    int n,m;
    sf(n);sf(m);
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++) sf(ar[i][j]);
    }

    ///col check
    int res = 2e9;
    for(int i=1; i<=n; i++)
    {
        int curcst = 0;
        for(int j=1; j<=m; j++)
        {
            auto cur = prime.lower_bound(ar[i][j]); //out(*cur);
            int val = *cur;
            curcst += (val-ar[i][j]);
        }
        res = min(res,curcst);
    }

    ///row check
    for(int i=1; i<=m; i++)
    {
        int curcst = 0;
        for(int j=1; j<=n; j++)
        {
            auto cur = prime.lower_bound(ar[j][i]);
            int val = *cur;
            //out(val);
            curcst += (val-ar[j][i]);
        }//out(curcst);
        res = min(res,curcst);
    }
    out(res);
    return 0;
}