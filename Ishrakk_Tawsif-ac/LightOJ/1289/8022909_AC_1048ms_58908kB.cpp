#include<bits/stdc++.h>
using namespace std;

#define sf(nn) scanf ("%d", &nn)
#define pf printf
#define loop(var,till) for(int var=0; var<till; var++)
#define loop1(var,till) for(int var=1; var<=till; var++)
#define pb push_back
#define mx 100000005
#define ll long long int
#define mp make_pair
#define mod 1000000009

///sieve

bitset<mx>isprime;
int prime[5761459],in;
//vector <ll> ans;

void sieve()
{

    isprime[0]=isprime[1]=1;
    prime[0]=2;
    //for(int i=4; i<mx; i+=2) isprime[i]=1;
            for(int i=3; i*i<mx; i+=2)
            {
                if(!isprime[i]) for(int j=i*i; j<mx; j+=i) isprime[j]=1;
            }
            //cnt[2]=1;
            in=0;
            for(int i=3; i<mx; i+=2){
                    if(!isprime[i] && (i%2)!=0) prime[++in]=i;
                    //else cnt[i]=cnt[i-1];
            }
}

unsigned other_primes[5761459];

unsigned solve(ll n)
{

    unsigned temp,res=1,cnt;

        for(int i=0; prime[i]*prime[i]<=n && i<=in; i++)
        {
            temp=n;
            cnt=1;

                while(temp>=prime[i])
                {
                    temp/=prime[i];
                    cnt *= (unsigned)prime[i];
                }
            cnt/=(unsigned)prime[i];
            res *= cnt;
        }
    return res;
}

int main()
{
   sieve();
   ll n;
   int tc;
//cout<<in<<endl;
        other_primes[0]=2;
        for(int i=1; i<=in; i++)other_primes[i]=(unsigned)prime[i]*other_primes[i-1];

            scanf("%d", &tc);
                loop1(tt,tc)
                {
                    scanf("%lld", &n);
                    int up=upper_bound(prime,prime+(in+1),n)-prime;
                    unsigned ans=(unsigned)solve(n) * other_primes[up-1];
                    pf("Case %d: %u\n", tt,ans);
                }
   return 0;
}