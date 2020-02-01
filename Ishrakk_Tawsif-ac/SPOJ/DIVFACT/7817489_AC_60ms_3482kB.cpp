#include<bits/stdc++.h>
using namespace std;

#define mx 50005
#define ll long long int
#define mod 1000000007

bitset <mx> isprime;
vector <int>prime;

void sieve()
{
    isprime[0]=isprime[1]=1;
    prime.push_back(2);
        for(int i=3; i*i<mx; i+=2)
            if(!isprime[i])
                for(int j=i*i; j<mx; j+=i) isprime[j]=1;
        for(int i=3; i<mx;i+=2) if(!isprime[i]) prime.push_back(i);
}

ll ipow(int base, int pow)
{

    ll res=1;
        while(pow--) res *= (ll) base;
    return res;
}

int findMaxPowerOfPrime(int n,int p)
{
    ll cnt=0,in=1,powOfp = p; /// p case p^1 = p
            while(powOfp<=n)
            {
                cnt += (n%mod)/(powOfp%mod);
                powOfp=ipow(p,++in);
            }
    return cnt;
}

ll numOfDiv(int n)
{
    ll temp,cnt,res=1;
    int len=prime.size();

        for(int i=0; prime[i]<=n && i<len; i++)
        {
            cnt=(ll)findMaxPowerOfPrime(n,prime[i]);
            res =  (ll)((res%mod) * (cnt+1))%mod;//cout<<prime[i]<<endl;
        }
    return (res%mod);
}

int main()
{
    sieve();
    //cout<<findMaxPowerOfPrime(100,2);
        int n,tc;
            scanf("%d", &tc);
                while(tc--)
                {
                    scanf("%d", &n);
                    cout<<numOfDiv(n)<<endl;
                }
    return 0;
}