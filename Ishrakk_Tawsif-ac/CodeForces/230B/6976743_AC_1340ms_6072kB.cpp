#include<bits/stdc++.h>
using namespace std;

#define mx 1000005

bitset <mx> isprime;
int prime[mx], in=-1;

void sieve(){
    isprime[0]=isprime[1]=1;
        for(int i=4; i<mx; i+=2)isprime[i]=1;

            for(int i=3; i*i<mx; i+=2){
                if(!isprime[i]){
                    for(int j=i*i; j<mx; j+=i) isprime[j]=1;
                }
            }
            for(int i=0; i<mx; i++){
                if(!isprime[i]) prime[++in]=i;
            }//cout << prime[in] << endl;
}
/*
int count_div(long long int n){

    int tot=1,con=0;

        for(int i=0; i<=in && prime[i]*prime[i]<=n; i++){
            con=0;
            if(n%prime[i] == 0){
                    while(n%prime[i] == 0){ con ++; n /= prime[i];}
            }
            tot *= con + 1;//cout << con << " " << endl;
        }
        if(n!=1) tot *= 2;
    return tot;
}
*/
int main(){

    sieve();
    long long int num,t,temp2;
        cin>> t;

            while(t--){
                cin>> num;
                     int temp=(int)sqrt(num);//cout << (long long int) temp*temp << endl;
                     temp2 = (long long int) temp*temp; //cout << temp2 << endl;
                        if(temp2 == num){
                            if(!isprime[temp]) cout << "YES" << endl;
                            else cout << "NO" << endl;
                        }
                        else cout << "NO" << endl;
            }
return 0;
}
