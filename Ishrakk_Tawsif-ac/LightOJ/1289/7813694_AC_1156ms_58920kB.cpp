#include<bits/stdc++.h>
using namespace std;

#define mx 100000005

bitset <mx> isprime;
int prime[5761509],in=-1;
unsigned dp [5761509];

void sieve()
{
    isprime[0]=isprime[1]=1;
    prime[++in]=2;

        for(int i=3; i*i<mx; i+=2)
            if(!isprime[i]) for(int j=i*i; j<mx; j+=i) isprime[j]=1;
        for(int i=3; i<mx; i+=2)
            if(!isprime[i]) prime[++in]=i;
}

long long int get_power(long long int n)
{
    int sqr=sqrt(n);
    long long int res=1,cnt=0,temp;

        for(int i=0; prime[i]*prime[i]<=n; i++)
        {
            temp=n; temp/= prime[i];
            //if(temp>=prime[i])
            //{
                while(temp>=prime[i])
                {
                    temp/= (long long int)prime[i];
                    res *= (long long int) prime[i];
                }//cout<<prime[i]<<" "<<res<<endl;
            //res/=prime[i];
            //}
        }
   return res;
}

int main()
{
    sieve();
    long int n; int tc;

    dp[0]=2; ///first prime is 2
    for(int i=1; i<=in; i++)
        {
            dp[i]=(unsigned)prime[i]*dp[i-1];
        }

        scanf("%d", &tc);

            for(int tt=1; tt<=tc; tt++)
            {
                scanf("%lld", &n);
                int len=in+1;
                unsigned ans=(unsigned)get_power(n);//cout<<ans<<endl;

                int num_of_prime_in_range=
                upper_bound(prime,prime + len,n)-prime;
                ans *= dp[num_of_prime_in_range-1];
                printf("Case %d: %u\n",tt,ans);
            }
    return 0;
}