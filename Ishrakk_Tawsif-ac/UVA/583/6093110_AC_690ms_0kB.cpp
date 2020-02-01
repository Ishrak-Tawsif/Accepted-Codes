#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;


long long int limit =1000007;
int arr[1000007]={0},prime[1000007];
int in=-1;

void sieve(){
    //memset(arr,0,sizeof(arr));
            arr[0]=arr[1]=0;
            for(int i= 4; i<=limit; i += 2) ///i=4 cause ... 2 is a prime number,so we start from first multiple of 2.
                arr[i] = 1;

                int sq_of_limit = sqrt(limit);
                ///now we will eliminate the multiples of rest of the prime less than sqrt(limit) ...
                for(int i=3; i<=sq_of_limit; i +=2){

                    if(arr[i] == 0){   ///it will check either i is a prime or not . :)
                        for (int j=i*i; j<=limit; j += i){
                            arr[j] = 1;
                        }
                    }
                }

                for(int i=1; i<=1000007; i++){
                    if(arr[i] == 0){
                        prime[in++]=i;
                    }
                }
                //cout << in << endl;

}


int main(){

    sieve();
    long int num,temp,count;

        while(cin>> num && num){
            if(num == 1){
                cout <<  num << " = 1"<<endl;
                continue;
            }
            else if(num == -1){
                cout <<  num << " = -1 x 1"<<endl;
                continue;
            }
            //cout << num << " = ";
            if(num<0){
                cout << num << " = " << "-1 x ";
                num *= -1;
            }
            else{
                cout << num << " = ";
            }

            for(int i=0; prime[i] < num && i<in; i++){

                if(num%prime[i] == 0){

                        while(num%prime[i] == 0){
                            num /= prime[i];
                            cout << prime[i] ;
                                if(num!=1){
                                    cout << " x ";
                                }
                        }
                }

            }
            if(num>1){
                        cout << num;

                    }
            cout << endl;
            //printf("%ld : %d\n",temp,count);
        }
   return 0;
}
