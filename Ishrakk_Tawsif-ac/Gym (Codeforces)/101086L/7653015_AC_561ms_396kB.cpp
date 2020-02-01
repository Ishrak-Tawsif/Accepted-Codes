#include<bits/stdc++.h>
using namespace std;

#define mx 100

bitset<mx>isprime;
int prime[100005];

void sieve(){

    isprime[0]=isprime[1]=1;

        for(int i=4; i<mx; i+=2) isprime[i]=1;

            for(int i=3; i*i<mx; i+=2){
                if(!isprime[i]){
                    for(int j=i*i; j<mx; j+=i) isprime[j]=1;
                }
            }
            //int in=-1;
            //for(int i=0; i<mx; i++) if(!isprime[i]) ++in; cout <<in <<endl;
}

void pre_gen(){

    prime[0]=0;
    for(int n=1; n<=100000; n++){
        int cnt=0,temp=n;
            while(temp!=0){
                if(temp%2==1) cnt++;
                temp/=2;
            }
        if(!isprime[cnt])prime[n]=prime[n-1]+1;
        else prime[n]=prime[n-1];
    }
}

int main(){

    sieve();
    pre_gen();
        //for(int i=0; i<=101; i++) cout<<prime[i]<<" "<<i<<endl;
        int l,u,tc;
            while(cin>>tc){
                while(tc--){
                    cin>>l>>u;
                    cout<<prime[u]-prime[l-1]<<endl;
                }
            }
return 0;
}