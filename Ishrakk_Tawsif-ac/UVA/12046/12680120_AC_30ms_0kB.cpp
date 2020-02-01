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
#define mx                      557
#define mod                     1000007

template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}

string tostring(ll res){string curstr="";while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}

/* ...........................................................................................................*/

ll dp[41][2][2][2][2][2][61],n,ar[7];

ll call(int pos,int t,int th,int f,int fi,int s,int tot)
{
    if(pos == n)
    {//out(tot);
        int fl = 1;//cout<<t<<" "<<th<<" "<<f<<" "<<fi<<" "<<s<<" "<<tot<<endl;
        if(t) if(tot%2 != 0) fl = 0;
        if(th) if(tot%3 != 0) fl = 0;
        if(f) if(tot%4 !=0) fl = 0;
        if(fi) if(tot%5 != 0) fl = 0;
        if(s) if(tot%6 != 0) fl = 0;
        return fl;
    }
    if(dp[pos][t][th][f][fi][s][tot] != -1) return dp[pos][t][th][f][fi][s][tot]%mod;

    ll ans = 0,ans1 = 0,ans2=0;
    //int fl;

    for(int i=1; i<=6; i++)
    {
        ar[2] = t,ar[3] = th,ar[4] = f,ar[5] = fi,ar[6] = s;
        ll temp = (tot*10) + i;
        ar[i] = 1;
        ans1 = ((ans1%mod) + (call(pos+1,ar[2],ar[3],ar[4],ar[5],ar[6],temp%60))%mod)%mod;
        ans1%=mod;
        //ar[i] = 0;
        //ans2 += call(pos+1,ar[2],ar[3],ar[4],ar[5],ar[6],tot%60);

        //ans = (ans1+ans2);
    }

    return dp[pos][t][th][f][fi][s][tot] = (ans1%mod);
}

int main()
{//WRITE("in.txt");
    int tc;

    sf(tc);
    //mem(dp,-1);
    while(tc--)
    {
        scanf("%lld", &n);
        mem(dp,-1);
        out(call(0,0,0,0,0,0,0)%mod);
    }
    return 0;
}