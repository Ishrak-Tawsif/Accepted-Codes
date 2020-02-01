#include<bits/stdc++.h>
using namespace std;


int main(){

    long int n,max_=0,temp;

        scanf("%lld", &n);

            for(int i=0; i<n; i++){
                    scanf("%ld", &temp);
                    max_ = max(max_,temp);
            }
            printf("%ld\n",max_);
return 0;
}