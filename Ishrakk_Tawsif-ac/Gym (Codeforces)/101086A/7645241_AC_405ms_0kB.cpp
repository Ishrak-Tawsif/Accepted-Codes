#include<bits/stdc++.h>
using namespace std;


int main(){

   int tc,n;
   char v;

    scanf("%d", &tc);
        while(tc--){
            scanf("%d", &n);
                long long int min_=LONG_LONG_MAX,temp=0,u;
                while(n--){
                    scanf("%lld %c",&u,&v);
                        if(v=='+'){
                            temp+= u+25;
                        }
                        else{
                            min_=min(min_, temp+u+25); ///minimum tk can have
                        }
                }printf("%lld\n", min_-temp);
        }
return 0;
}