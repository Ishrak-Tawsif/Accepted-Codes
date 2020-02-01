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
#define casepf(nn)              printf ("Case %d:\n",nn)
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
#define mx                      2000005
#define mod                     1000000007
#define flush                   fflush(stdout)

template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}

string tostring(ll res){string curstr="";while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}


/* ...........................................................................................................*/

ll ar[200005],cum[200005];

struct ST
{
    ll val;
    int ind;
};

ST rightt[2000005];


int main()
{
    int n,k;
    sf(n); sf(k);
    for(int i=1; i<=n; i++)
    {
        sfll(ar[i]);
        cum[i] = cum[i-1] + ar[i];
    }

    int in = 0;
    for(int i=1; i<=n; i++) rightt[i].val = -2e18;
    for(int i=1; i<=n; i++)
    {
        int st = i-1;
        int en = i + k - 1;
        if(en>n){break;}

        ll now = cum[en]-cum[st];

        if(now>rightt[en-1].val)
        {
            rightt[en].val = now;
            rightt[en].ind = i;
        }
        else rightt[en] = rightt[en-1];
        //rightt[en] = max(rightt[en-1],);cout<<i<<" "<<rightt[i]<<endl;
    }

    int ans1,ans2;
    ll res = -2e15;
    for(int i=n; ; i--)
    {
        int st = i - k;
        int en = i;
        if(st<0) break;

        if(st-k+1<=0) break;

        ll now = cum[en] - cum[st];
        ll rt = rightt[st].val;
        now += rt;//cout<<i<<" "<<now<<endl;
        if(res<=now)
        {
            res = now;
            ans1 = rightt[st].ind;
            ans2 = st+1;
        }
    }
    cout << ans1 << " " << ans2 << endl;
    
    return 0;
}