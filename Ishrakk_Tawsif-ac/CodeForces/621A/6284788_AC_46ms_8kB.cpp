#include<bits/stdc++.h>
using namespace std;
int main(){

    long long int numbers,temp,sum,min;
    //vector<long long int>vc;
            while(scanf("%lld", &numbers) == 1){
                sum=0;
                min=LONG_LONG_MAX;
                    for(int i=0; i<numbers; i++){
                       scanf("%lld", &temp);
                       sum += temp;
                            if(min>temp && temp%2!=0) min=temp;
                    }
                          if(sum%2 == 0)
                            printf("%lld\n", sum);
                          else
                            printf("%lld\n", sum-min);
            }
   return 0;
}
