#include<bits/stdc++.h>
using namespace std;

#define mx 1000005

bitset <mx> isprime;
vector <int> prime;

void sieve()
{
    isprime[1]=isprime[2]=1;

        for(int i=3; i*i<mx; i+=2)
          if(!isprime[i])
            for(int j=i*i; j<mx; j+=i) isprime[j]=1;
        prime.push_back(2);
        for(int i=3; i<mx; i+=2) if(!isprime[i]) prime.push_back(i);//cout<<prime.size();
}

int get_div(long long int n)
{
    long long int ans=1,len=prime.size();
    for(long long int i=0; prime[i]*prime[i]<=n && i<len; i++)
    {
        if(n%prime[i] == 0)
        {
            long long int cnt=0;
            while(n%prime[i]==0){n/=(long long int)prime[i]; cnt++;}
            ans *= (cnt+1);
        }
    }
    if(n!=1) ans *= (long long int) 2;
    return ans;
}

int main()
{
    sieve();
        long long int n,m,ans;
        int tc;
            scanf("%d", &tc);

                for(int tt=1; tt<=tc; tt++)
                {
                    scanf("%lld %lld", &n, &m);
                    if(m*m>=n)ans=0;
                    else
                    {
                        ans=get_div(n); //cout<<ans<<endl;
                        ans/=2;

                        for(long long int i=1; i<m; i++) if(n%i==0) ans--;
                    }
                    printf("Case %d: %lld\n",tt,ans);
                }
    return 0;
}