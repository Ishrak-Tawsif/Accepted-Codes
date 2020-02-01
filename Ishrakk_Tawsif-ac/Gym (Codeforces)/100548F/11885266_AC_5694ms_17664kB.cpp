#include<bits/stdc++.h>
using namespace std;

int dx[8]={0,0,1,-1,1,1,-1,-1};
int dy[8]={1,-1,0,0,1,-1,1,-1};

#define sf(nn)                  scanf ("%d", &nn)
#define sfll(nn)                scanf ("%lld", &nn)
#define pf                      printf
#define casepf(nn)              printf ("Case %d:\n",nn)
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
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      5000005
#define mod                     1000000007

ll n,m,k,invmodulo[1000005],fact[1000005];

ll binomialCoeff(ll nn, ll k)
{
    if(k>nn) return 0;
    if(k==0) return 0;
    ll res = 1;
    if(nn<=1000000)
    {//out("ok");
        res =  (((invmodulo[k]%mod * (invmodulo[nn-k]%mod))%mod)%mod)%mod;
        res = ((res) * (((fact[nn]))))%mod;//cout<<invmodulo[k]<<" "<<invmodulo[n-k]<<" "<<fact[nn]<<endl;
        return res;
    }
    res = 1;
    if(nn-k>k) k=nn-k;
    for(ll i=k+1; i<=nn; i++)
    {
        res = (res*i)%mod;
        res%mod;
    }
    res = ((res) * (invmodulo[nn-k]))%mod;
    return res%mod;
}

ll bigmod(ll b,ll p)
{
    if(!p)return 1;
        ll t=bigmod(b,p/2)%mod;
        ll tt=(t*t)%mod;
        if(p%2!=0)tt=(tt*b)%mod;
    return tt%mod;
}

/*ll calc(ll nn,ll cur)
{
    ll val[cur+5],sum=(2) * binomialCoeff(cur,2),sum2=0,preans=2;//cout<<sum<<" //// \n";
    val[2] = 2;
    for(ll i=3; i<cur; i++)
    {
        ll curval = pow(i-1,nn-1) * i;
        //ll mul = (nn == i)? 1 : ((nn-i)*(i-1));
        //curval *= mul;
        sum2 = 0;
        for(ll j=2; j<i; j++)
        {
            sum2 += (binomialCoeff(i,j) * val[j]);
        }
        ll curans = curval - sum2;
        val[i] = curans;
        sum += (curans*(binomialCoeff(cur,i)));
    }//cout<<sum<<" ... \n";
    ll res = (pow(cur-1,nn-1)) * cur;
    //ll mul = (nn == cur)? 1 : ((nn-cur)*(cur-1));
    cout<<" res " << res<<endl;
    return ((res)-sum);
}*/

void precalc()
{
    fact[0] = 1;
    invmodulo[0] = 1;
    for(ll i=1; i<=1000000; i++)
    {
        fact[i] = ((fact[i-1])%mod * i)%mod;
        invmodulo[i] = bigmod(fact[i],mod-2);
    }
}

int main()
{
    int tc;
    sf(tc);
    precalc();//cout<<fact[15]<<endl;
    for(int tt=1; tt<=tc; tt++)
    {
        scanf("%lld %lld %lld", &n,&m,&k);
        ll mck = binomialCoeff(m,k)%mod;
//cout<<mck<<endl;
        ll curres = ((k)*(bigmod(k-1,n-1))%mod);//cout<<curres<<endl;
        string lastsign = "+";

        for(ll curk=k-1; curk>=2; curk--)
        {
            ll now = ((curk%mod) * (bigmod(curk-1,n-1))%mod)%mod;
            now%=mod;
            now = ((now%mod) * binomialCoeff(k,curk)%mod)%mod;//cout<<k<<" "<<curk<<" "<<binomialCoeff(k,curk)<<endl;
            if(lastsign == "-")
            {
                curres = curres+now;
                curres %= mod;
                lastsign = "+";
            }
            else
            {
                curres = curres - now;
                curres = curres+mod;
                curres %= mod;
                lastsign = "-";
            }//cout<<curres<<" "<<now<<endl;
        }

        curres = ((curres) * (mck))%mod;
        printf("Case #%d: %lld\n", tt,(curres%mod));
    }

    //ll tn,tk;
    //while(cin>> tn>> tk)cout<<calc(tn,tk)<<endl;;
    return 0;
}