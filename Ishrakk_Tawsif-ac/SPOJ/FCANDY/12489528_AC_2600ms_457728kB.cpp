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
#define mx                      2000000 + 5
#define mod                     1000000007

template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}

string tostring(ll res){string curstr="";while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}

/* ...........................................................................................................*/



int n,sz,dp[500005][225];
vector <int> vv;

int call(int pos,int diff)
{
    if(pos == sz) return diff;
    if(dp[pos][diff] != -1) return dp[pos][diff];

    int ans1 = 2e9,ans2 = 2e9;

    if(diff+vv[pos]<=200) ans1 = call(pos+1,diff+vv[pos]);
    if(diff-vv[pos]>=-200) ans2 = call(pos+1,abs(diff-vv[pos]));

//cout<<ans1<<" "<<ans2<<endl;
    return dp[pos][diff] = min(ans1,ans2);
}

int main()
{//READ("in.txt");
    sf(n);
    for(int i=0; i<n; i++)
    {
        int u,v;
        scanf("%d %d", &u,&v);

        while(u--) vv.pb(v);
    }

    sz = vv.size();
    //sort all(vv);
    mem(dp,-1);
    out(call(0,0));

    return 0;
}