#include<bits/stdc++.h>
using namespace std;

#define mx 32000

bitset <mx> isprime;
int prime[mx],in=-1;

void sieve(){

    isprime[0]=isprime[1]=1;

        for(int i=4; i<mx; i += 2) isprime[i]=1;
            for(int i=3; i*i<mx; i+=2){
                if(!isprime[i]){
                    for(int j=i*i; j<mx; j+=i) isprime[j]=1;
                }
            }
            for(int i=0; i<mx; i++){
                if(!isprime[i]) prime[++in]=i;
            }//cout << in << endl;
}


int div(long int n){

    int cnt=0,tot=1;

        for(int i=0; i<=in && prime[i]*prime[i]<=n; i++){
            cnt=0;
            while(n%prime[i] == 0){
                cnt++;n/=prime[i];
            }
            tot *= cnt+1;
        }
        if(n!=1) tot *= 2;
    return tot;
}

int main(){
    sieve();
    long int a,b,n,ans=0; cin >>a >>b >>n;
        for(int i=a; i<=b; i++){
            if(div(i) == n) ans++;
        }cout << ans << endl;
return 0;
}
