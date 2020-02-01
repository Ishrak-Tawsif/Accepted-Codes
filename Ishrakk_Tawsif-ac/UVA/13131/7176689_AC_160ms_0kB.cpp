#include<bits/stdc++.h>
using namespace std;

int main(){
    //sieve();//cout << isprime[50230];
    //cout << prime_gen(20,2);
        int testcase,n,k,sum;
            scanf("%d", &testcase);
                while(testcase--){
                    scanf("%d %d", &n, &k);
                    sum=0;
                        for(int i=1; i*i<=n; i++){
                            if(i*i==n && i%k!=0) sum+=i;
                            else if(n%i == 0){
                                if(i%k != 0) sum+=i;
                                if((n/i)%k != 0) sum+=n/i;
                            }
                        }printf("%d\n", sum);
                }
return 0;
}

/*101 100000 100000*/