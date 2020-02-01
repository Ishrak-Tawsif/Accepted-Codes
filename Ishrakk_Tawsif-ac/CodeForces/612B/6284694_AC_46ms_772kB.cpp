#include<bits/stdc++.h>
using namespace std;
int main(){

    long long int n,temp,sum;

        while(scanf("%lld", &n) == 1){

            long int numbers[n+2];

                for(int i=1; i<=n; i++){
                    scanf("%lld", &temp);
                    numbers[temp]=i;
                }
                    sum=0;
                    for(int i=1; i<n; i++){
                        sum += abs(numbers[i+1]-numbers[i]);
                    }
                    printf("%lld\n", sum);
        }

return 0;
}
