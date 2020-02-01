#include<bits/stdc++.h>
using namespace std;


#define mx 503



int gcd(int a, int b){

    if(a == 0) return b;
    else return gcd(b%a,a);
}

int pre_gen(int n){
    int sum=0;
    for(int i=1; i<n; i++){
        int s=0;
        for(int j=i+1; j<=n; j++) s += gcd(i,j);
        sum += s;//cout<<s<<endl;
    }
    return sum;
}

int main(){
    int n;
        while(cin>> n && n){
            cout << pre_gen(n) << endl;
        }
return 0;
}