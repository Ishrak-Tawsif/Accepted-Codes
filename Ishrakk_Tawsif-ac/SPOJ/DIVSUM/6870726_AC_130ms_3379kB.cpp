#include<bits/stdc++.h>
using namespace std;

#define mx 1000

bitset <mx> isprime;
int prime[mx],in=-1;

/*void sieve(){
    ///0 for prime
    isprime[0]=isprime[1]=1;

        for(int i=4; i<mx; i+=2)isprime[i]=1;
            for(int i=3; i<mx; i+=2){
                if(!isprime[i]){
                    for(int j=i*i; j<mx; j+=i)isprime[j]=1;
                }
            }
            for(int i=0; i<mx; i++){
                if(!isprime[i]) prime[++in]=i;
            }//cout << in << endl;
}*/

int p_div_sum(int n){

    int sum=0;

        for(int i=2; i*i<=n; i++){
            if(n%i == 0){
                if(i!=n) sum += i;
                if(n/i != n) sum += n/i;
            }
        }
        int nn=sqrt(n); if(nn*nn == n) sum -= nn;
    return sum;
}

int main(){
    //sieve();
    int n,testcase;
        scanf("%d", &testcase);
        while(testcase--){
            scanf("%d", &n);
            if(n == 1) printf("0\n");
            else printf("%d\n",p_div_sum(n)+1);
        }

    return 0;
}
