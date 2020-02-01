#include<bits/stdc++.h>
using namespace std;

#define mx 100000000

bitset <mx>isprime;
int prime[mx],in=-1;

void sieve(){
    isprime[0]=isprime[1]=1;
        for(int i=4; i<mx; i+=2) isprime[i]=1;
            for(int i=3; i*i<mx; i+=2){
                if(!isprime[i]){
                    for(int j=i*i; j<mx; j+=i) isprime[j]=1;
                }
            }
            for(int i=0; i<mx; i++){
                if(!isprime[i]) prime[++in]=i;
            }
}


bool prime_check(long int n){
    //if(n == 1) return false;
    for(long int i=0; prime[i]*prime[i]<=n; i++){
        if(n%prime[i] == 0) return false;
    }
    return true;
}

int main(){
    sieve();

        long int low,high;
        int testcase;
            scanf("%d", &testcase);

                while(testcase --){
                    scanf("%ld %ld", &low, &high);
                    if(low == 1) low++;

                        for(long int i=low; i<=high; i++){
                            if(i>mx){
                                if(prime_check(i)) cout << i << endl;
                            }
                            else {
                                if(!isprime[i]) cout << i << endl; ;
                            }
                        }
                        //cout << endl;
                }
return 0;
}
