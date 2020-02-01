#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
#define MAX 1299800
bool isprime[MAX];
int prime[MAX];

void sieve(){

    memset(isprime,true,sizeof(isprime));
    isprime[0]=isprime[1]=false;
        for(int i=4; i<= MAX; i += 2)
            isprime[i]=false;

                for(int i=3; i<=(sqrt(MAX)); i += 2){
                    for(int j=i*i; j<=MAX; j+=i)
                        isprime[j]=false;
                }
                    int in=-1;
                    for(int i=1; i<=MAX+2; i++){
                        if(isprime[i])
                            prime[++in]=i;
                    }
        //cout << in << endl;
}

int main(){

    sieve();
        int input;
            while(cin>> input && input){
                if(isprime[input]){
                    cout << "0" << endl;
                    //break;
                }
                else{
                    for(int i=0; ; i++){
                        if(prime[i]<input && prime[i+1]>input){
                            cout<<prime[i+1]-prime[i] << endl;
                            break;
                        }
                    }
                }
            }
return 0;
}
