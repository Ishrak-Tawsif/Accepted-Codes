#include<iostream>
#include<cstring>
#include<cmath>
#define Max 1000
using namespace std;

bool isprime[Max];
int prime[Max];


void sieve(){
    memset(isprime,true,sizeof(isprime));
    isprime[0]=isprime[1]=false;
        for(int i=4; i<=Max; i+=2)
            isprime[i]=false;

            for(int i=3; i<sqrt(Max); i+=2){
                for(int j=i*i; j<=Max;j+=i)
                    isprime[j]=false;
            }
            int in=-1;
                for(int i=0; i<Max; i++){
                    if(isprime[i])
                        prime[++in]=i;
                }
                //cout << in << endl;
}

int main(){

    sieve();
    int n,k,count;
        while(cin>>n >>k){
            count=0;
            for(int i=0; prime[i]<=n; i++){
                for(int j=0; prime[j]<=prime[i]/2; j++){
                    if((prime[j]+prime[j+1]+1)==prime[i])
                        count++;
                }

            }
            if(count >= k) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
}
