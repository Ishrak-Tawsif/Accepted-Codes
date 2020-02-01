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
#define mx                      105
#define mod                     1000000007

template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}

string tostring(ll res){string curstr="";while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}

/* ...........................................................................................................*/

//int ar[1000005]cnt[1000005];
ll ncr_[1005][1005],len,cur,dp[1003][1003][2];
vector <ll> vv;
string str;
int mark[1003];

int gen(string str,int n,int tot)
{
    //if(tot == 1) return 0;
    int cnt = 1,temp = tot,one = 0;

    while(tot != 1)
    {
        one = 0;
        temp = tot;
        one = __builtin_popcount(temp);
        tot = one;//out(tot);
        cnt++;
    }
    return cnt;
}

int call(int i,int one,int iszero)
{
    if(i == len)
    {
        if(mark[one]) return 1;
        return 0;
    }
    //if(one == cur) return 1;

    if(dp[i][one][iszero] != -1) return dp[i][one][iszero];

    int ans;
    if(iszero) ans = (((call(i+1,one+1,iszero))%mod) + (call(i+1,one,iszero)%mod))%mod;
    else
    {
        if(str[i] == '1')
        {
            ans = ((call(i+1,one+1,iszero))%mod + call(i+1,one,1)%mod)%mod;
        }
        else
        {
            ans = call(i+1,one,iszero)%mod;
        }
    }
    return dp[i][one][iszero] = ans;
}

int main()
{
    //genncr();
    cin>> str;

    int tot = 0,k;
    cin>> k;

    len = str.length();
    for(int i=0; i<str.length(); i++)
    {
        if(str[i] == '1') tot ++;
    }//out(tot);

    if(k == 0){pf("1\n"); return 0;}
    if(str.length() == 1)
    {
        if(k == 0) pf("1\n");
        else pf("0\n");
        return 0;
    }

    for(int i=1; i<=str.length() && k!=0; i++)
    {
        int now = gen(str,i,i); //out(now);
        if(now == k)
        {
            mark[i] = 1;
        }
    }

    ll res = 0;
    mem(dp,-1);

    res = ((res%mod) + (call(0,0,0)%mod))%mod;//out(res);
    res %= mod;
    if(k == 1) res -= 1,res += mod, res %= mod;

    out(res%mod);

    return 0;
}