#include<bits/stdc++.h>
using namespace std;

#define mx 1025

bitset <mx> isprime;
int prime[201],in=-1;

void sieve(){
    ///0 for prime
    isprime[0]=isprime[1]=1;

        for(int i=4; i<mx; i+=2) isprime[i]=1;

            for(int i=3; i*i<mx; i+=2){
                if(!isprime[i]){
                    for(int j=i*i; j<mx; j+=i)isprime[j]=1;
                }
            }
            //int in=-1;
            for(int i=0; i<mx; i++){
                if(!isprime[i]) prime[++in]=i;
            }
            //cout << in << endl;
}

int prime_fact(int n){

    int cnt=0;
    for(int i=0; i<=in && prime[i]*prime[i]<=n; i++){
        if(n%prime[i] == 0){
            cnt++;
            while(n%prime[i] == 0)n/=prime[i];
        }
    }
    if(n != 1) cnt++;

    return cnt;
}

int main(){
    sieve();

        int n;
            while(scanf("%d", &n) ==1 && n){
                printf("%d : %d\n",n,prime_fact(n));
            }
return 0;
}
