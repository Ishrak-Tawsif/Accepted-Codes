#include<bits/stdc++.h>
using namespace std;

#define mx 20000005


bitset <mx> isprime;
int prime[mx],in=-1;
vector < pair< int,int> >p;

void sieve(){

    isprime[0]=isprime[1]=1; /// 1 for non-prime
        for(int i=4; i<mx; i+=2) isprime[i]=1;

            int len = sqrt(mx);
            for(int i=3; i<=len; i++){
                for(int j=i*i; j<mx; j += i) isprime[j]=1;
            }

            in=-1;
            for(int i=0; i<mx; i++){
                if(!isprime[i]) prime[++in]=i;
            }
            //cout << prime[100000+1] << endl;
}

void pre_genarate(){

    int inn=-1;

        for(int i=1,j=0; i<in, j<=100001; i++){
            if(prime[i]-prime[i-1] == 2){
                p.push_back(make_pair(prime[i-1], prime[i]));
                j++;
            }
        }
}

int main(){
    sieve();
    pre_genarate();

        int n;

            while(cin>> n){
    
                cout << "(" << p[n-1].first << ", " << p[n-1].second << ")" << endl;
            }
    return 0;
}
