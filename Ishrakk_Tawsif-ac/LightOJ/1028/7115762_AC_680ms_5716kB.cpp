#include<bits/stdc++.h>
using namespace std;

#define mx 1000000
#define ll long long int
int prime[mx],in;
bitset <mx> isprime;


void sieve(){

    isprime[0] = isprime[1] = 1;
        for(int i=4; i<mx; i+=2) isprime[i] = 1;
            for(int i=3; i*i<mx; i+=2){
                if(!isprime[i]){
                    for(int j=i*i; j<mx; j+=i) isprime[j] = 1;
                }
            }
            in = -1;
            for(int i=0; i<mx; i++){
                if(!isprime[i]) prime[++in] = i;
            }//cout << in << endl;
}

int prime_gen(ll n){

    int cnt=0; int div=1;
    for(int i=0; i<=in && prime[i]*prime[i]<=n; i++){
        if(n%prime[i] == 0){
            cnt=0;
            while(n%prime[i] == 0){
                n/=prime[i]; cnt++;
            }
            div *= cnt+1;
        }
    }
    if(n!=1) div *= 2;
  return div;
}

int main(){
    sieve();
    int testcase;
    ll nn;
        scanf("%d", &testcase);
        for(int i=1; i<=testcase; i++){
            scanf("%lld", &nn);
            printf("Case %d: %d\n", i,prime_gen(nn)-1);
        }
    return 0;
}