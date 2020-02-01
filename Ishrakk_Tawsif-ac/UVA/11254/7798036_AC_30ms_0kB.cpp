#include<bits/stdc++.h>
using namespace std;

int main(){

    long int sum,start,firstTerm;

        while(scanf("%lld", &sum) == 1){
            //double firstTerm;
            start=sqrt(2*sum);

                for(long int i=start; i>0; i--){
                    firstTerm =  (((2*sum)-(i*i))+i);

                    if(firstTerm%(2*i) == 0){
                        firstTerm /= (2*i);
                        printf("%d = %d + ... + %d\n",sum,firstTerm,firstTerm+i-1);
                        break;
                    }
                }
        }
return 0;
}