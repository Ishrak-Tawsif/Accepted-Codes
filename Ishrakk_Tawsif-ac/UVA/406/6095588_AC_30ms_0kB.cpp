///not solved

#include<iostream>
#include<cmath>
using namespace std;


long long int limit =1500;
int arr[1500]={0},prime[1500];
int in=-1;

void sieve(){
    //memset(arr,0,sizeof(arr));
            arr[1]=0;
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

                for(int i=1; i<=1500; i++){
                    if(arr[i] == 0){
                        prime[++in]=i;
                    }
                }
                //cout << prime[0] << endl;

}


int main(){
    sieve();
    int maximum_number,c,list[1001],len,count;

         while(cin>> maximum_number>> c){
            len=-1;
            count=0;
            for(int i=0; prime[i]<=maximum_number; i++){
                list[++len]=prime[i];
                count++;
            }
            /*cout << count << endl;
                for(int i=0; i<count; i++)
                    cout << list[i] << endl;*/
                     cout << maximum_number << " " << c << ":";
                     if(count%2 == 0){
                        int half = count/2 - c;

                                if(count<half || half<0){
                                    for(int i=0; i<count; i++)
                                        cout << " " << list[i];
                                }
                                else{
                                    for(int j=half,i=1; i<=(c*2); j++,i++)
                                        cout << " " << list[j];
                                }
                          cout << "\n" << endl;
                    }

                    else{
                        int half=count/2 - c + 1;
                            if(count<half || half <0){
                                for(int i=0; i<count; i++)
                                    cout <<" " << list[i];
                            }
                            else{
                                for(int j=half,i=1; i<=((c*2)-1); j++,i++){
                                    cout << " " << list[j];

                                }
                            }
                        cout << "\n" << endl;
                    }

         }
}
