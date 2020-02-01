#include<bits/stdc++.h>
using namespace std;

#define mx 48000
#define ll long long int

bool isprime[mx];
int prime[mx],in,prime_f[mx];

void sieve(){

    ///false for prime.

        isprime[0]=isprime[1]=true;
        for(int i=4; i<mx; i += 2) isprime[i]=true;

            int len = sqrt(mx);
            for(int i=3; i<len; i+=2){
                if(!isprime[i]){
                    for(int j=i*i; j<mx; j+=i) isprime[j]=true;
                }
            }
                in=-1;
                for(int i=0; i<mx; i++){
                    if(!isprime[i]){
                        prime[++in]=i;
                    }
                }
                //cout << prime[in] << endl;
}

ll get_powers(ll n, ll p)
{
    ll res = 0;
    for (ll power = p ; power <= n ; power *= p)
        res += n/power;
    return res;
}

ll rem;bool go=false;
bool prime_fact(ll n){
    go=false;
    memset(prime_f,0,sizeof(prime_f));

    for(int i=0; prime[i]*prime[i]<=n && i<=in; i++){
        if(n%prime[i] == 0){

            while(n%prime[i] == 0){
                n /= prime[i];
                prime_f[prime[i]]++;
            }
        }
    }
    if(n != 1){
            //cout << n << endl;
        if(n<=47981) prime_f[n]++;
        else {rem=n; go=true;}
    }
}

int main(){

     sieve();
     ll n,m;
     bool fl;

        while(scanf("%lld %lld", &n, &m) == 2){
            fl=true;

            if(n>=m) fl = true;
            else if(n == 0 && m == 1) fl=true;

            else{
            prime_fact(m);

                for(int i=0; i<in && prime[i] <= 47981; i++){

                    if(prime_f[prime[i]] != 0){
                        //cout << prime[i] << " " << prime_f[prime[i]] << " " << get_powers(n,prime[i]) << endl;
                        if(prime_f[prime[i]] > get_powers(n,prime[i])){fl=false; break;}
                    }
                }
                if(go==true){if(get_powers(n,rem)<1) fl=false;}
            }
                if(fl == true) printf("%lld divides %lld!\n",m,n);
                else printf("%lld does not divide %lld!\n",m,n);
        }
   return 0;
}
