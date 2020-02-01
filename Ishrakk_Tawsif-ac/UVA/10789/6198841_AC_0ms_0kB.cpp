#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
using namespace std;

long long int limit =10000;
int arr[10000];

void sieve(){
    memset(arr,0,sizeof(arr));
    arr[0]=arr[1]=1;
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
int main()
{
    sieve();
    char input[2003];
    int testcase,len;
    cin>> testcase;

        for(int t=1; t<=testcase; t++){
            cin>> input;
            len=strlen(input);
            int count[128]={0};
                for(int i=0; i<len; i++)
                    count[input[i]]++;

                        printf("Case %d: ",t);
                        int j=0;
                        for(int i=0; i<128; i++){
                            if(arr[count[i]] == 0){
                                printf("%c", i);
                                j++;
                            }
                        }
                        if(j == 0)
                            cout << "empty";

                        cout << endl;
        }

    return 0;
}
