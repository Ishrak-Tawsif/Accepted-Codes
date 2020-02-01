#include<bits/stdc++.h>
using namespace std;

#define sf(nn) scanf ("%d", &nn)
#define pf printf
#define loop(var,till) for(int var=0; var<till; var++)
#define loop1(var,till) for(int var=1; var<=till; var++)
#define pb push_back
#define mx 1000005
#define ll long long int
#define mp make_pair
#define mod 100000007

int dir_r_8[]={-1,-1,-1,0,0,1,1,1};
int dir_c_8[]={-1,0,1,-1,1,-1,0,1};
int dir_r_4[]={-1,1,0,0};
int dir_c_4[]={0,0,-1,1};

//int row,col,r,c,cost[21][21],dis[21][21],vis[21][21],dp[21][1<<21],len;
//string grid[21];
//vector <pair<int,int> >vv,cc;



/*int time_needed()
{
    double end = clock();
    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    cout<<cpu_time_used<<endl;
}*/

/*struct order
{
    int s,e;

        bool operator < (const order &x) const
        {
            //if(s == x.s) return e<x.e;
            //else
                return e<x.e;
        }
};*/


bitset <mx> isprime;
vector <int> prime;

void sieve()
{
    isprime[0]=isprime[1]=1;
    prime.pb(2);

        for(int i=3; i*i<mx; i+=2)
        {
            if(!isprime[i])
            {
                for(int j=i*i; j<mx; j+=i) isprime[j]=1;
            }
        }
        for(int i=3; i<mx; i+=2) if(!isprime[i]) prime.pb(i);
}

int prime2[3][mx];

void prime_div(int type,ll n)
{
    for(int i=0; prime[i]*prime[i]<=n; i++)
    {
        if(n%prime[i]==0)
        {
            int cnt=0;
                while(n%prime[i]==0)
                {
                    cnt++;
                    n/= (ll) prime[i];
                }
            prime2[type][prime[i]]=cnt;
        }
    }
    if(n!=1) prime2[type][n]=1;
}

ll ipow(ll base,ll pow)
{
    ll ans=1;

        while(pow--) ans *= base;
    return ans;
}

int main()
{
    sieve();
        ll n,m,l,tc;
            scanf("%lld", &tc);

                for(int tt=1; tt<=tc; tt++)
                {
                    scanf("%lld %lld %lld", &n,&m,&l);

                    //ll lcm=(n*m)/__gcd(n,m);

                    if(l%n != 0 || l%m!=0) pf("Case %d: impossible\n",tt);
                    else{
                        memset(prime2,0,sizeof(prime2));

                            prime_div(0,n);
                            prime_div(1,m);
                            prime_div(2,l);
                            ll ans=1;

                                for(int i=0; i<prime.size(); i++)
                                {
                                    //if(prime2[0][prime[i]]!=0)cout<<prime[i]<<" 0 "<<prime2[0][prime[i]]<<endl;
                                    //if(prime2[1][prime[i]]!=0)cout<<prime[i]<<" 1 "<<prime2[1][prime[i]]<<endl;
                                    //if(prime2[2][prime[i]]!=0)cout<<prime[i]<<" 2 "<<prime2[2][prime[i]]<<endl;
                                    if(prime2[2][prime[i]]>prime2[0][prime[i]])
                                    {
                                        if(prime2[2][prime[i]]>prime2[1][prime[i]])
                                        {
                                            ans *= ipow(prime[i],prime2[2][prime[i]]);
                                        }
                                    }
                                }
                                pf("Case %d: %lld\n",tt,ans);
                    }
                }
    return 0;
}