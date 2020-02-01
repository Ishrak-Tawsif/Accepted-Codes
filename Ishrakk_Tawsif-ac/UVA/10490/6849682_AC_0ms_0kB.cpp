#include<bits/stdc++.h>
using namespace std;

#define mx 100

bitset <mx> isprime;
int perfect[32];

void sieve(){
    ///0 for prime
        isprime[0]=isprime[1]=1;
        for(int i=4; i<mx; i+=2) isprime[i]=1;
            for(int i=3; i<mx; i+=2){
                if(!isprime[i]){
                    for(int j=i*i; j<mx; j+=i) isprime[j]=1;
                }
            }
            int in=-1;
            /*for(int i=0; i<mx; i++){
                if(!isprime[i]) ++in;
            }
            cout << in << endl;*/
}

int main(){
    sieve();

        int n;

            perfect[2] = perfect[3] = perfect[5] = perfect[7] = perfect[13] = perfect[17] = perfect[19] = perfect[31] = 1;
            while(scanf("%d", &n) == 1 && n){

                if(perfect[n]){
                        double temp = pow(2,n-1);
                        double _temp = ((temp*2)-1)*temp;
                        printf("Perfect: %.0lf!\n", _temp);
                }
                else if (!isprime[n]) printf("Given number is prime. But, NO perfect number is available.\n");
                else printf("Given number is NOT prime! NO perfect number is available.\n");

            }
  return 0;
}
