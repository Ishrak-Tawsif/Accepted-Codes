#include<bits/stdc++.h>
using namespace std;

#define ll long long int


ll bigmod(ll num,ll pow, ll mod){

    if(pow == 0) return 1;
    else if(pow%2 == 0){
        ll ret = bigmod(num, pow/2, mod)%mod;
        return (ret * ret)%mod;
    }
    else{
        return (num%mod) * bigmod(num, pow-1, mod)%mod;
    }
}

int main(){

    ll x,y,mod,testcase;
            while(cin>> testcase && testcase){
                while(testcase --){
                    cin>> x>> y>>mod;
                    cout << bigmod(x,y,mod) << endl;
                }
            }
return 0;
}