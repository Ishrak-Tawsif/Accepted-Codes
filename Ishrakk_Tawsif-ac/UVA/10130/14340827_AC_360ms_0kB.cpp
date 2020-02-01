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
#define mx                      1123
#define mod                     1000000009
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


int n,g,cost[1001],val[1001],dp[1001][33];

int call(int ind,int w)
{
    if(ind>=n) return 0;
    //if(w<=0) return 0;
    if(dp[ind][w] != -1) return dp[ind][w];

    int ans = 0;

    if(w-cost[ind]>=0)ans = max(call(ind+1,w-cost[ind]) + val[ind],call(ind+1,w));
    else ans = call(ind+1,w);

    return dp[ind][w] = ans;
}

int main()
{

    #ifndef ONLINE_JUDGE
    	clock_t TStart = clock();
        //READ("in.txt");
        //WRITE("out.txt");
    #endif

    int tc;

    sf(tc);

    while(tc --)
    {
        scanf("%d", &n);

        for(int i=0; i<n; i++) scanf("%d %d", &val[i],&cost[i]);

        sf(g);

        int res = 0,mw;
        while(g--)
        {
            sf(mw);

            mem(dp,-1);
            res += call(0,mw);
        }
        pf("%d\n", res);
    }

    #ifndef ONLINE_JUDGE
    	printf("\n>>Time taken: %.10fs\n", (double) (clock() - TStart) / CLOCKS_PER_SEC);
	#endif

    return 0;
    
}