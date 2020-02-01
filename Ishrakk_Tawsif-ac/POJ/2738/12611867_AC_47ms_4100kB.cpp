#include<stdio.h>
//using namespace std;

/*int dx[8]={0,0,1,-1,1,1,-1,-1};
int dy[8]={1,-1,0,0,1,-1,1,-1};

#pragma comment(linker,"/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define sf(nn)                  scanf ("%d", &nn)
#define sfll(nn)                scanf ("%lld", &nn)
#define pf                      printf
#define casepf(nn)              printf ("Case %d: ",nn)
#define out(nn)                 cout <<nn <<endl
#define loop(var,start,till)    for(int var=start; var<till; var++)
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
#define mx                      105
#define mod                     1000000007

template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}*/

//string tostring(ll res){string curstr="";while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
//ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}

/* ...........................................................................................................*/

int n,ar[1005],dp[1005][1005];

int call(int i,int j)
{
    if(i > j)
    {
        return 0;
    }

    if(dp[i][j] != -1) return dp[i][j];

    int ans = 0,ans2=0;

    /// i tomo nibo
    if(ar[i+1]>=ar[j]) ans = call(i+2,j) + ar[i];
    else if(ar[j]>ar[i+1]) ans = call(i+1,j-1) + ar[i];

    ///j tomo nibo
    if(ar[i]>=ar[j-1]) ans2 = call(i+1,j-1) + ar[j];
    else if(ar[j-1]>ar[i]) ans2 = call(i,j-2) + ar[j];

    int kk;
    if(ans>=ans2) kk = ans;
    else kk = ans2;

    return dp[i][j] = kk;
}

int main()
{
    int tt=0;

    while(scanf("%d",&n) && n)
    {
        int tot = 0;
        for(int i=0; i<n; i++) scanf("%d", &ar[i]),tot += ar[i];

        for(int i=0; i<1005; i++)
        {
            for(int j=0; j<1005; j++) dp[i][j] = -1;
        }
        int fplayer = call(0,n-1);
        int splayer = tot-fplayer;
        printf("In game %d, the greedy strategy might lose by as many as %d points.\n", ++tt,fplayer-splayer);
    }
    return 0;
}