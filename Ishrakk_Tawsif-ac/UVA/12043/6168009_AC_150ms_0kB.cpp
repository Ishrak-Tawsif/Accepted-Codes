///getting wa

#include<iostream>
#include<cmath>
#include <cstring>
using namespace std;
bool isprime[100000];
int prime[664590];

void sieve(){
        memset(isprime,false,sizeof(isprime));
        isprime[0]=isprime[1]=true;

        for(int i=4; i<=100000; i += 2)
            isprime[i]=true;

            for(int i=3; i<=sqrt(100000); i++){
                 if(isprime[i] == 0){
                    for(int j=i*i; j<100000; j+=i)
                        isprime[j]=true;
                 }
            }

            int in=-1;
            for(int i=0; i<=100000; i++){
                if(isprime[i] == false){
                    prime[++in] = i;
                }
            }
            //cout << in  << endl;

}


long long int ipow(int base, int exp)
{
    long long int result = 1;
    while (exp)
    {
        if (exp & 1)
            result *= base;
        exp >>= 1;
        base *= base;
    }

    return result;
}

int main(){
    sieve();
    long long int a,b,k,testcase,temp,tempk,sum_of_divisor,num_of_divisor,divisor,total_num_of_divisor,total_sum_of_divisor;
    int j;
        cin>> testcase;
            for(int t=1; t<=testcase; t++){
                cin>> a>> b>> k;
                    //tempk=k;
                    //while(a>=tempk){
                        //tempk += k;
                    //}
                    total_num_of_divisor=0;
                    total_sum_of_divisor=0;
                        for(int i=a; i<=b; i++){
                               if(i%k==0){
                                temp=i;
                                num_of_divisor=1;
                                sum_of_divisor=1;
                                for(j=0; prime[j]*prime[j]<=temp; j++){
                                    divisor=0;
                                    if((temp%prime[j]) == 0){
                                        while(temp%prime[j] == 0){
                                            temp /= prime[j];
                                            divisor++;
                                        }
                                    num_of_divisor *= (divisor+1);
                                    if(divisor==1)
                                            sum_of_divisor *= (prime[j]+1);
                                    else
                                            sum_of_divisor *= (((ipow(prime[j], (divisor+1)))-1) / (prime[j]-1));
                                    }
                                }
                                        if(temp != 1 && isprime[temp] == false){
                                                num_of_divisor *= 2;
                                                sum_of_divisor *= (temp+1);
                                        }

                                        total_num_of_divisor += num_of_divisor;
                                        total_sum_of_divisor += sum_of_divisor;
                               }
                        }
                        cout << total_num_of_divisor << " " << total_sum_of_divisor << endl;
                        }


return 0;
}
