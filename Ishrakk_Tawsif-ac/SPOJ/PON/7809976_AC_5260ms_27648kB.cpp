#include<bits/stdc++.h>
using namespace std;

#define mx 199999999
#define ll long long int

bitset <mx> isprime;
vector <ll> prime;

void sieve(){
    isprime[0]=isprime[1]=1;
    prime.push_back(2);

        for(ll i=3; i*i<mx; i+=2)
            if(!isprime[i]) for(ll j=i*i; j<mx; j+=i) isprime[j]=1;

        for(ll i=3; i<mx; i+=2)if(!isprime[i]) prime.push_back(i);
}

bool prime_check(unsigned long long int n)
{
    for(int i=0; prime[i]*prime[i]<=n && i<prime.size(); i++)
    {
        if(n%prime[i] == 0) return false;
    }
    return true;
}

int main(){

    sieve();
    unsigned long long int n;
    int tc;

        scanf("%d", &tc);
            while(tc--)
            {
                scanf("%llu", &n);
                if(prime_check(n)) printf("YES\n");
                else printf("NO\n");
            }
return 0;
}