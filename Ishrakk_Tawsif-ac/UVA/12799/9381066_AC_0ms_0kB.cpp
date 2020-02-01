#include<bits/stdc++.h>
using namespace std;

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
#define intinf                  2e9
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define MOD                     1003
#define mx                      32000


bitset<mx>isprime;
vector <int> prime;

void sieve()
{
    isprime[0] = isprime[1] = 1;

        for(int i=3; i*i<mx; i++)
        {
            for(int j=i*i; j<mx; j+=i) isprime[j] = 1;
        }
        prime.pb(2);
        for(int i=3; i<mx; i++)
            if(!isprime[i] && i%2!=0) prime.pb(i);
}

vector <ll> fact;

void prime_fact(ll n)
{
    int len = prime.size();

        for(int i=0; prime[i]*prime[i]<=n && i<len; i++)
        {
            if(n%prime[i] == 0)
            {
                ll temp = (ll) prime[i];
                fact.pb(temp);
                while(n%prime[i] == 0)
                {
                    n /= (ll)prime[i];
                }
            }
        }
    if(n!=1) fact.pb(n);
}

ll mul_inverse(ll r1,ll r2)
{
    ll q,r,t1=0,t2=1,t;

        while(r1 != 1)
        {
            q = r1/r2;
            r = r1%r2;
            t = t1-q*t2;
            r1=r2;
            r2=r;
            t1=t2;
            t2=t;
        }
    return max(t1,t1+t2);
}

ll bigmod(ll base,ll pow,ll mod)
{//cout<<base<<" " <<pow<<" " <<mod<<endl;

    if(pow == 0) return 1;

    else if(pow%2 == 0)
    {
        int res = (bigmod(base,pow/2,mod))%mod;
        return ((res%mod) * (res%mod))%mod;
    }
    else
    {
        return ((base%mod) * bigmod(base,pow-1 ,mod)%mod)%mod;
    }
    //return res;
}

int main()
{
    int n,e,c,tc;

    sieve();

            while(scanf("%d %d %d", &n,&e,&c) == 3)
            {
                fact.clear();//out("1");
                prime_fact(n);//out("2");
                    ll phi = (fact[0]-1) * (fact[1]-1);
                    ll d = mul_inverse((ll)phi,(ll)e);
                    ll ans = bigmod((ll)c,(ll)d,(ll)n);
                pf("%d\n",ans);
            }
            
    return 0;
}