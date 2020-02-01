#include<iostream>
#include<cmath>
#include <cstring>
using namespace std;
bool isprime[10000000];
int prime[664590];

void sieve(){
        memset(isprime,false,sizeof(isprime));
        isprime[0]=isprime[1]=true;

        for(int i=4; i<=10000000; i += 2)
            isprime[i]=true;

            for(int i=3; i<=sqrt(10000000); i++){
                 if(isprime[i] == 0){
                    for(int j=i*i; j<10000000; j+=i)
                        isprime[j]=true;
                 }
            }

            int in=-1;
            for(int i=0; i<=10000000; i++){
                if(isprime[i] == false){
                    prime[++in] = i;
                }
            }

}

int main(){
    sieve();
        int testcase,count;
        int number;

            cin>> testcase;
                for(int t=1; t<=testcase;t++){
                    cin >> number;
                    count=0;
                        for(int i=0; prime[i]<=number/2; i++){
                            if(isprime[number-prime[i]] == false)
                                count++;
                        }
                        cout << "Case " << t << ": " << count << endl;
                }
    return 0;
}
