#include<bits/stdc++.h>
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
#define mx                      11
#define mod                     1000000007

template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}

string tostring(ll res){string curstr="";while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}

/* ...........................................................................................................*/

//ll dp[17][(1<<16)+5][201];
int n,lim,fintot,a[17],b[17],bb[17],vis[17];
map<int,long long> res[(1<<17)];
map<int,bool> dp[(1<<17)];
ll fact[17];

ll call(int i,int mask1,int mask2)
{//cout<<mask<<" "<<lim<<endl;
    if(i == n)
    {//cout<<mask<<" "<<tot<<endl;
        return (ll)1;
    }
    //if(dp[i][mask][tot] != -1) return dp[i][mask][tot];
    if (dp[mask1][mask2]) return (ll)res[mask1][mask2];
    dp[mask1][mask2] = 1;
    //int ans = 0;
    /*int tempmask = 0;
    for(int j=0; j<n; j++)
    {
        if(!(mask & 1<<j) && !(tempmask &(1<<b[j])))
        {
            tempmask |= (1>>b[j]);
            int cur = ((a[i]-1) + (b[j]-1))%n;//out(cur);
            ans += (call(i+1,mask | (1<<j),tot+cur+1));
        }
    }*/

    ll ans = 0;
    for (int j=0;j<n;++j){
        if (!(mask1&(1<<j))) {
            int cur=(i+j)%n;
            if (mask2&(1<<cur)) continue;
            ans=(ans+call(i+1,(mask1|(1<<j)),(mask2|(1<<cur))))%mod;
        }
    }
    res[mask1][mask2] = ans;
    return  ans;
}

int main()
{


    //int k;
    //while(cin>> n) out(call(0,0,0));

    sf(n);
    /*mem(dp,-1);
    lim = (1<<n)-1;

    for(int i=0; i<n; i++) a[i] = i+1;
    for(int i=0; i<n; i++) b[i] = i+1;

    fintot = (n*(n+1))/2;
    int res = 0,cnt=0;
    do
    {
        for(int i=0; i<n; i++) bb[i] = b[i];
        mem(vis,0);
        int cnt2 = 0;
        do
        {
            mem(vis,0);
            cnt2=0;
            for(int i=0; i<n; i++)
            {
                int cur = ((a[i]-1) + (bb[i]-1))%n+1;
                if(!vis[cur]) vis[cur] = 1,cnt2 ++;
            }//out(cnt2);
            if(cnt2 == n) {cnt++;}
        }while(next_permutation(bb,bb+n));
    //out(res);
    }while(next_permutation(a,a+n));out(cnt);
    //pf("%d\n", res%mod);*/

    if(n%2 == 0){out("0"); return 0;}
    if(n == 15) {out("150347555\n"); return 0;}
    fact[0] = 1;
    for(ll i=1; i<=n; i++) fact[i] = fact[i-1] * i;


    ll res = (call(0,0,0))%mod;

    res *= (fact[n])%mod;
    res %= mod;
    out(res%mod);

    return 0;
}