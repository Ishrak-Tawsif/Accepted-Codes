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
#define mx                      1000005
#define mod                     1000000009
#define left(n)                 (n<<1)
#define right(n)                ((n<<1) + 1)
#define fast                    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define PI                      acos(-1)
#define ull                     unsigned long long
#define eps                     .000000001

template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}
string tostring(ll res){string curstr="";if(!res) curstr += ((char)res + '0');while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}

/* ...........................................................................................................*/

int n,t,w,ar[33],val[33],dp[33][1003],vis[33][1003],mark[33][1003];

int call(int pos,int tot)
{
    if(pos>=n) return 0;
    if(dp[pos][tot] != -1) return dp[pos][tot];

    int ans1 = 0,ans2 = 0;

    if(tot + ar[pos] <= t) ans1 = call(pos+1,tot+ar[pos]) + val[pos];
    ans2 = call(pos+1,tot);

    if(ans1 || ans2) mark[pos][tot] = (ans1>ans2);

    return dp[pos][tot] = max(ans1,ans2);
}

int main()
{//WRITE("out.txt");
    int tc = 0;

    while(scanf("%d %d", &t,&w) == 2)
    {

        if(tc) pf("\n");
        tc++;

        mem(mark,0);
        sf(n);
        for(int i=0; i<n; i++) sf(ar[i]),ar[i] = (3* w * ar[i]),sf(val[i]);

        mem(dp,-1);
        int res = call(0,0);
        pf("%d\n", res);


        int now = 0,ans = 0;
        for(int i=0; i<n; i++)
        {//cout<<i<<" "<<now<<" "<<mark[i][now]<<endl;
            if(mark[i][now]) {ans++;now += ar[i];}
        }
        pf("%d\n",ans);
        now = 0;
        for(int i=0; i<n; i++)
        {
            if(mark[i][now]) {pf("%d %d\n", ar[i]/(3 * w),val[i]);now += ar[i];}
        }
    }

    return 0;
}