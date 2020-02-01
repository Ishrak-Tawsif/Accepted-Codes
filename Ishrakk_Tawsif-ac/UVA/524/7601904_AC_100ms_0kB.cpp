#include<bits/stdc++.h>
using namespace std;

int primes[101],n,arr[17],ans[17];

void sieve(){

    primes[0]=primes[1]=1;

        for(int i=4; i<101; i+=2) primes[i]=1;

            for(int i=3; i<101; i+=2){
                if(!primes[i]){
                        for(int j=i*i; j<101; j+=i) primes[j]=1;
                }
            }
}

void backtrack(int ind){
//cout<<ind<<endl;
    if(ind == n+1){
        int fl=1;
        //for(int i=1; i<n; i++){
        //    if(primes[ans[i]+ans[i+1]] == 0){fl=0; break;}
        //}
        if(primes[ans[n]+1]) fl=0;
            if(fl==1){
                printf("1");
                for(int i=2; i<=n; i++) printf(" %d",ans[i]);
                printf("\n");
            }
            else return;
    }

    for(int i=2; i<=n; i++){
        if(arr[i] == 0 && !primes[ans[ind-1]+i]){
            arr[i]=1;//cout<<primes[ans[ind-1]+i]<<endl;
            ans[ind]=i;
            backtrack(ind+1);
            arr[i]=0;
        }
    }
}

int main(){

  sieve();
    int tc=0;
        while(cin>> n){
            if(tc!=0) printf("\n");
            printf("Case %d:\n", ++tc);

            arr[1]=1;
            ans[1]=1;
            backtrack(2);

        }
return 0;
}