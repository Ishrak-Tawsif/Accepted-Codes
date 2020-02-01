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

int ar[100005],cnt[1000005];
vector <int> prime;
bitset <mx> isprime;

void sieve()
{
    isprime[0] = isprime[1] = 1;
    prime.pb(2);
    for(int i=3; i*i<mx; i+=2)
    {
        if(!isprime[i])
        {
            for(int j=i*i; j<mx; j+=i) isprime[j] = 1;
        }
    }
    for(int i=3; i<mx; i+=2) {if(!isprime[i]) prime.pb(i);}
}


int main()
{
    sieve();
    //out(prime.size());
    int tc,n;

    sf(tc);

    while(tc --)
    {
        sf(n);
        mem(cnt,0);

        for(int i=1; i<=n; i++) sf(ar[i]);
        for(int i=1; i<=n; i++)
        {
            int nn = ar[i];
            for(int j=0; prime[j]*prime[j]<=nn; j++)
            {
                if(nn%prime[j] == 0)
                {//cout<<"vitore "<<prime[j]<<endl;
                    cnt[prime[j]] ++;
                    while(nn%prime[j] == 0) nn/=prime[j];
                }
            }//out(n);
            if(nn!=1) cnt[nn] ++;
        }

        int res = 0;
        for(int i=0; i<prime.size(); i++)
        {
            if(cnt[prime[i]])res += (cnt[prime[i]]/3 + (cnt[prime[i]]%3>0))
                /*,cout<<prime[i]<<" "<<cnt[prime[i]]<<endl*/;
        }

        pf("%d\n", res);
    }

    return 0;
}