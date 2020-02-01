#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;


long long int limit =1000003;
int arr[1000003];

void sieve(){
    memset(arr,0,sizeof(arr));
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

}

int main(){

    long long int n;
        sieve();
        while(cin>> n){
            long int sq  = ceil(n/2);
            for(int k=2; k<=sq; k++){
                if(arr[k] == 0)

                    if(arr[n-k] == 0){
                        cout << n << " = " << k << " + " << n-k << endl;
                        break;
                }
            }
        }

return 0;
}
