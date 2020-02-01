#include<bits/stdc++.h>
using namespace std;

long long int fact[23];

void pre_gen(){
    //fact[0]=1;fact[1]=1;//cout<<fact[2];
    //for(long long int i=2; i<21; i++) fact[i] =fact[i-1]*i;
    fact[0]=1;
    for(long long int i=1; i<=21; ++i) fact[i]=fact[i-1]*i;
}

int main(){
    
    freopen("popcorn.in","r",stdin);
    pre_gen(); //cout<<fact[21];
    int n,m,testcase;
        scanf("%d", &testcase);
            while(testcase--){
                scanf("%d %d", &n, &m);
                    long long int ans=(fact[n]/ (fact[m]*fact[n-m]));
                    printf("%lld\n", ans);
            }
return 0;
}