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

ll ipow(ll base, ll pow)
{
    ll res=1;

        while(pow--) res *= base;//cout<<base<<" "<<res<<endl;
    return res;
}

int main()
{
    sieve();

        ll h,l,tc;

            sf(tc);

                loop1(tt,tc)
                {
                    scanf("%lld %lld", &l,&h);

                        ll cnt=0,p,in=0;


                            p=prime[in];

                            for(ll i=prime[in]; i*i<=h; )
                            {
                                int pw=2;
                                ll ans;

                                    while(1)
                                    {
                                        ans = ipow(i,pw++);
                                        if(ans>=l && ans<=h) cnt++;
                                        if(ans>h) break;//cout<<ans<<endl;
                                    }
                                i=prime[++in];
                            }//cout<<prime[in]<<endl;
                    pf("%lld\n",cnt);
                }
    return 0;
}