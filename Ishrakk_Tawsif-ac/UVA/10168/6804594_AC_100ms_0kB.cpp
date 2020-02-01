#include<bits/stdc++.h>
using namespace std;
#define mx 10000005

bitset <mx> isprime;

void sieve(){
    ///0 for prime
    isprime[0]=isprime[1]=1;

        for(int i=4; i<mx; i+=2) isprime[i]=1;

            int len=sqrt(mx);
            for(int i=3; i<len; i++){
                for(int j=i*i; j<mx; j+=i) isprime[j]=1;
            }
            /*int in=-1;
            for(int i=0; i<100; i++){
                if(!isprime[i])++in;
            }
            cout << in << endl;*/
}

int main(){

    sieve();
        long int n,ans,rem,i,n1,n2;
        bool fl;

            while(scanf("%ld", &n) == 1){

                if(n<8) cout << "Impossible." << endl;
                else{

                    if(n%2 == 0){ans=2+2;n1=2;n2=2;}
                    else {ans=2+3;n1=2;n2=3;}

                     //while(fl==false){
                        rem=n-ans;
                        i=0;

                        if(!isprime[rem]){ rem--; i++;}

                            while(/*isprime[rem]==1 && isprime[i]==1*/rem>=2){
                                rem--;i++;
                                if(!isprime[i] && !isprime[rem]) break;
                            }

                            if(!isprime[rem] && !isprime[i]){
                                cout << n1 << " " << n2 << " " << rem << " " << i << endl;
                                //fl=true;
                            }

                    //if(fl == false) cout << "Impossible." << endl;
                }

            }
    return 0;
}
