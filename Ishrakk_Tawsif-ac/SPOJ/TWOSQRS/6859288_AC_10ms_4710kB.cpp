#include<iostream>
#include<cstring>
#include<cmath>
#define Max 1001000
using namespace std;

bool isprime[Max];
long int prime[80000];
int in=-1;

void sieve(){
    memset(isprime,true,(sizeof(isprime)));
    isprime[0]=isprime[1]=false;
        for(int i=4; i<=Max; i+=2)
            isprime[i]=false;
            for(int i=3; i<sqrt(Max); i+=2){
                for(int j=i*i; j<=Max; j+=i)
                    isprime[j]=false;
            }
                for(int i=0; i<Max; i++){
                    if(isprime[i])
                        prime[++in]=i;
                }
               // cout << prime[in-1] << endl;
}

void getAnswer(unsigned long long int number){
    int prime_count;
    bool ispossible=true;
    for(int i=0; i<in && 1LL * prime[i]*prime[i]<=number; i++){
        prime_count=0;
        if(number%prime[i] == 0){
            while(number%prime[i] == 0){
                number /= prime[i];
                if (prime[i]%4==3) prime_count++;
            }
        }

        ///checking...
            if(prime_count != 0){
                if(prime_count%2 != 0){
                    ispossible=false;
                    break;
                }
            }
    }

            if(ispossible == true && number%4 != 3)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
}

int main(){
    sieve();
        int testcase;
        unsigned long long int number;
        cin >>testcase;
            while(testcase --){
                cin>> number;
                if(number == 0) cout << "Yes" << endl;
                else    getAnswer(abs(number));
            }
    return 0;
}
