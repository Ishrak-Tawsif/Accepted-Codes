#include<bits/stdc++.h>
using namespace std;

#define mx 10000005
long int prime[664580];
bitset <mx> isprime;

void sieve()
{

    isprime[0]=isprime[1]=1;

        for(int i=4; i<mx; i+=2) isprime[i]=1;

            for(int i=3; i*i<mx; i+=2){
                if(!isprime[i]){
                    for(int j=i*i; j<mx; j+=i) isprime[j]=1;
                }
            }
            int in=-1;
            for(int i=0; i<mx; i++){
                if(!isprime[i]) prime[++in]=i;
            }//cout<<in<<endl;
}

int main(){
    sieve();

        int n;

            while(cin>> n){
                for(int i=0; i<n-1; i++) cout << prime[i] << " " ;
                cout << prime[n-1] <<endl;
            }
}