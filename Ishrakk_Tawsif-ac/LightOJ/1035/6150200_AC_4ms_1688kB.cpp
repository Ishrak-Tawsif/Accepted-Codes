#include<iostream>
#include<cmath>
using namespace std;

int isprime[125]={0};
int prime[125];

void sieve(){

    ///al prime will be 0 and non prime will be 1;
    isprime[0]=isprime[1]=1;
        ///eliminate all multiple of 2
            for(int i=4; i<=125; i += 2)
                isprime[i] = 1;

       ///eliminate all multiple of rest of the prime
            int limit = sqrt(125);
            for(int i=3; i<=limit; i += 2){
                if(isprime[i] == 0){
                    for(int j=i*i; j<=125; j += i)
                        isprime[j]=1;
                }
            }
            int in=-1;
            for(int i=0; i<=125; i++){
                if(isprime[i] == 0)
                    prime[++in]=i;
            }
}

int num_of_prime(int num, int prime){
    int count=0;
      if(num%prime == 0){
        while(num%prime == 0){
            num /= prime;
            count ++;
        }
      }
    return count;
}


int main(){

    int number,total,fl,testcase;
    sieve();
        cin>> testcase;
            for(int t=1; t<=testcase; t++){
                cin >> number;
                fl=0;
                cout << "Case " << t << ":" << " " << number << " = ";

                    for(int i=0; prime[i]<=(number); i++){
                        total=0;
                        for(int j=1; j<=(number); j++)
                            total += num_of_prime(j,prime[i]);
                        if(total != 0){
                            if(fl==0){
                                    cout << prime[i] << " (" << total << ")" ;
                                    fl=1;
                            }
                            else
                                    cout << " * " << prime[i] << " (" << total << ")" ;
                        }
                    }
                    cout << endl;
            }
return 0;
}
