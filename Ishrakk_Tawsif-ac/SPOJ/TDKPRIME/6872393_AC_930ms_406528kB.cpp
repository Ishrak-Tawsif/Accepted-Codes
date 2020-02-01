#include<bits/stdc++.h>
using namespace std;

#define mx 100000005

bitset <mx> isprime;
int prime[mx];

void sieve(){
    ///0 for prime
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
            }
            //cout << in << endl;
}

int main(){
    sieve();
        int n,testcase;

            scanf("%d", &testcase);

                while(testcase --){
                    scanf("%d", &n);
                    printf("%d\n", prime[n-1]);
                }

return 0;
}
