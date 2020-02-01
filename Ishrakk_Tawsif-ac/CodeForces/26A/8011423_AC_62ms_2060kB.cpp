#include<iostream>
#include<cmath>
using namespace std;

long long int limit =3000;
int arr[3000]={0},prime[3000];

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
                int in=-1;
                for(int i=1; i<=3000; i++){
                    if(arr[i] == 0){
                        prime[in++]=i;
                    }
                }
                /*for(int i=0; i<in; i++)
                    cout << prime[i] << " ";
                    cout << in ;*/

}
int main(){
    int num,div,almost_prime;
    sieve();
    while(cin>> num){
        almost_prime=0;
        for(int i=1; i<=num; i++){
            div=0;
            for(int j=0; prime[j]<=i/2 ;j++){
                if(i%prime[j] == 0){
                    div++;
                    //cout << prime[j] << endl;
                }
            }

                if(div == 2){
                    almost_prime++;
                }

        }
        cout << almost_prime << endl;
    }//.
   return 0; 
}