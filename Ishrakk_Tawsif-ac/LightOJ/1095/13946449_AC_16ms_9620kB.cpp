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
#define mx                      1000+7
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

ll ncr[mx][mx],fact[mx];

void gen_fact()
{
    fact[0] = 1;

    for(int i=1; i<mx; i++)
    {
        fact[i] = ((fact[i-1]%mod) * i)%mod;
    }
}

void genncr()
{
    ncr[0][0] = 1;
    for(int i=1; i<mx; i++)
    {
        for(int j=0; j<=i; j++)
        {
            if(j == 0) ncr[i][j] = 1;
            else if(j == 1) ncr[i][j] = i;
            else ncr[i][j] = (ncr[i-1][j-1]%mod) + (ncr[i-1][j]%mod)%mod;
        }
    }
}


int main()
{
    gen_fact();
    genncr();

    int tc,n,m,k;

    sf(tc);

    for(int tt=1; tt<=tc; tt++)
    {
        scanf("%d %d %d", &n,&m,&k);

        ll totperm = 0,temp;

        for(int i = 0; i<=m-k; i++)
        {
            if(i%2 == 0)
            {
                temp = (ncr[m-k][i] * fact[n-k-i])%mod;
                totperm += temp;
                totperm %= mod;
            }
            else
            {
                temp = (ncr[m-k][i] * fact[n-k-i])%mod;
                totperm += mod;
                totperm -= temp;
                totperm %= mod;
            }
        }

        ll res = ncr[m][k];
        
        res = (res%mod * totperm%mod)%mod;

        casepf(tt);
        
        pf("%lld\n", res%mod);
    }

    return 0;
}