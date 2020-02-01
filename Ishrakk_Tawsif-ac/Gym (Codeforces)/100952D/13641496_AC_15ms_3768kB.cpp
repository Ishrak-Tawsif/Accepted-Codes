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

int n,m,k,d;
ll ar[205];
ll ncr[205][205];

void pregen()
{
    ncr[0][0] = 1;
    for(int i=1; i<205; i++)
    {
        for(int j=0; j<=i; j++)
        {
            if(!j) ncr[i][j] = 1;
            else if(j == 1) ncr[i][j] = i;
            else ncr[i][j] = (ncr[i-1][j]%mod + ncr[i-1][j-1]%mod)%mod;
        }
    }
}

vector <ll> vv;

int main()
{//READ("in.txt");
    int tc;
    ll temp;
    pregen();
    sf(tc);

    while(tc--)
    {
        //mem(dp,-1);
        scanf("%d %d %d %d", &n,&m,&k,&d);

        for(int i=1; i<=n; i++) sfll(ar[i]);//out(tc);

        sort (ar,ar+n+1);

        if(!m && !k) {pf("1\n");continue;}

        ll ans = 0;

        if(k)
        {
            for(int i=1; i<=n; i++)
            {
                ll now = ar[i];//out(ar[i]);
                if(now>=d) ans += (ncr[n-i][k-1]%mod * ncr[i-1][m-k]%mod)%mod,ans%=mod;
                ans%=mod;//out(n-i);
            }//out("ok");
        }
        else
        {
            //ans = 0;
            for(int i=1; i<=n; i++)
            {//out(ar[i]);
                ans += ncr[i-1][m-1]%mod;//out(i+1);
                ans%=mod;
            }
        }
        pf("%lld\n", ans%mod);
        //vv.clear();
    }
    return 0;
}