#include<iostream>
#include<cmath>
#include <cstring>
using namespace std;
bool isprime[10000000];
int divisor[10000000];
int prime[78500];

void sieve(){
        memset(isprime,false,sizeof(isprime));
        isprime[0]=isprime[1]=true;

        for(int i=4; i<=1000000; i += 2)
            isprime[i]=true;

            for(int i=3; i<=sqrt(1000000); i++){
                 if(isprime[i] == 0){
                    for(int j=i*i; j<1000000; j+=i)
                        isprime[j]=true;
                 }
            }

            int in=-1;
            for(int i=0; i<=1000000; i++){
                if(isprime[i] == false){
                    prime[++in] = i;
                }
            }
            //cout << in  << endl;
}

void setFactorialFactor() {

    divisor[1] = 0;
    for (int i=2; i<=1000000; i++) {
        divisor[i] = divisor[i-1];
            int n=i, j=0;
                while (isprime[n] == true) {
                    if (n%prime[j]==0) {
                        divisor[i]++;
                        n /= prime[j];
                    }
                    else j++;
                }
                if (isprime[n] == false) divisor[i]++;
    }
}

int main(){

    sieve();

        long long int number;
        setFactorialFactor();
            while(cin>> number){
                cout << divisor[number] << endl;
                }
    return 0;
}
