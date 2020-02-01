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
#define mx                      300005
#define mod                     1000000007
#define left(n)                 (n<<1)
#define right(n)                ((n<<1) + 1)
#define fast                    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define PI                      acos(-1)
#define ull                     unsigned long long

template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}
string tostring(ll res){string curstr="";while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}


/* ...........................................................................................................*/

ll /*ncr[mx][mx],*/fact[mx],invmod[mx];

//void genncr()
//{
//    ncr[0][0] = 1;
//    for(int i=1; i<mx; i++)
//    {
//        for(int j=0; j<=i; j++)
//        {
//            if(j == 0) ncr[i][j] = 1;
//            else if(j == 1) ncr[i][j] = i;
//            else ncr[i][j] = ( (ncr[i-1][j-1]%mod) + (ncr[i-1][j]%mod) ) % mod;
//        }
//    }
//}

ll bigmod(ll A,ll B)
{
    ll ret = 1;
    while(B)
    {
        if(B & 1) ret = (ret * A)%mod;
        A = (A * A)%mod;B = B >> 1;
        ret = ret%mod;
    }
    return ret%mod;
}

void gen_fact()
{
    fact[0] = 1;
    invmod[0] = 1;

    for(ll i=1; i<mx; i++)
    {
        fact[i] = (i * fact[i-1]%mod);
        fact[i] %= mod; //cout<<i<<" "<<i*fact[i-1]<<endl;system("pause");
        invmod[i] = bigmod(fact[i],mod - 2) % mod;
    }
}

ll ncr(ll m, ll k)
{
    if(k == 0) return 1;
    if(k == 1) return m;
    if(k > m) return 0;

    ll res;
    if(m<=1000000)
    {
        res = fact[m];//out(res);
        res = ((res % mod) * ((invmod[k])%mod * (invmod[m-k])%mod )) %mod ;
        return res%mod;
    }

    k = max(k,m-k);

    res = 1;
    for(ll i = k+1; i<=m; i++)
    {
        res = ((res % mod) * i)%mod;
    }

    res = ((res % mod) * invmod[m-k]%mod ) %mod;

    return res%mod;
}

ll ipow(ll base,ll pow)
{
    ll res = 1;

    while(pow --) res = ((res%mod) * (base%mod))%mod;

    return res;
}

int main()
{
    //genncr();
    gen_fact();
    ll n,c,now,temp;

    scanf("%lld %lld", &n,&c);

    temp = c - (n * 2);//out(temp);
//    now = ncr(temp,n) % mod; //out(now);
//    now = (now%mod * (fact[n]%mod))%mod;//out(now);
//    ll res = (((ll)bigmod(6,n))%mod)%mod;//out(res);
//    res = (res%mod * now%mod)%mod;//out(now);

    ll res = 1;

    for(ll i = temp; i>=(temp-n+1); i--) res = ((res%mod) * i) % mod;

    res = ((res%mod) * ipow((ll)6,n)%mod)%mod;

    pf("%lld", res%mod);

    return 0;
}