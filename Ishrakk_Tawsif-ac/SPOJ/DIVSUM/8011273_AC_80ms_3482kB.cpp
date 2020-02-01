#include<bits/stdc++.h>
using namespace std;

int p_div_sum(int n){

    int sum=0;

        for(int i=2; i*i<=n; i++){
            if(n%i == 0){
                if(i!=n) sum += i;
                if(n/i != n) sum += n/i;
            }
        }
        int nn=sqrt(n); if(nn*nn == n) sum -= nn;
    return sum;
}

int main(){
    //sieve();
    int n,testcase;
        scanf("%d", &testcase);
        while(testcase--){
            scanf("%d", &n);
            if(n == 1) printf("0\n");
            else printf("%d\n",p_div_sum(n)+1);
        }

    return 0;
}