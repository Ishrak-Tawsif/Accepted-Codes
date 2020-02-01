#include<bits/stdc++.h>
using namespace std;

bitset <1005> isprime;
int prime[171];

void sieve(){

    isprime[0] = isprime[1] = 1;

        for(int i=4; i<1005; i+=2) isprime[i] = 1;

            for(int i=3; i*i<1005; i+=2){
                if(!isprime[i]){
                    for(int j=i*i; j<1003; j+=i) isprime[j] = 1;
                }
            }
            int in=-1;
            for(int i=0; i<1003; i++){
                if(!isprime[i]) prime[++in]=i;
            }//cout << prime[167] << endl;
}

vector <int> v[1003];

void pre_gen(){

    for(int i=1; i<=1000; i++){
        int temp=0;

            for(int j=0; prime[j]<=i && j<=167; j++){
                for(int k=0; prime[k]<=i && k<=167; k++){
                        if(i - (prime[j]+prime[k])<1001 && i - (prime[j]+prime[k])>0){
                        if(!isprime[i - (prime[j]+prime[k])]){
                            v[i].push_back(prime[j]);
                            v[i].push_back(prime[k]); //if(i==999) //cout << k << " " << prime[k] << endl;
                            v[i].push_back(i - (prime[j]+prime[k]));
                            temp=1;break;
                            }
                        }
                }if(temp == 1) break;
            }
            if(temp == 0) v[i].push_back(0);
    }
}

int main(){

    sieve();
    pre_gen();

        int testcase,n;
        cin>> testcase;

            while(testcase--){
                cin>> n;
                    //cout << v[n].size() << endl;

                    for(int i=0; i<v[n].size(); i++){
                         if(i!=v[n].size()-1)   cout << v[n][i] << " ";
                         else cout << v[n][i] << endl;
                    }
            }
return 0;
}