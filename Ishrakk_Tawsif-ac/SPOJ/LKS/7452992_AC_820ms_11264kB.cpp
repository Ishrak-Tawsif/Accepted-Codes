#include<bits/stdc++.h>
using namespace std;

#define ll long int

ll wei[501],val[501],n,cap,dp[2000001];
/// 0/1 knapsack using 1D array.
ll call(ll w){

    for(int i=0; i<n; i++){
        for(int j=w; j>=0; j--){
            if(j>wei[i]) dp[j]=max(dp[j],dp[j-wei[i]]+val[i]);
        }
    }
}

int main(){

    scanf("%ld %ld",&cap,&n);
        for(int i=0; i<n; i++) scanf("%ld %ld", &val[i],&wei[i]);

        //memset(dp,0,sizeof(dp));

        dp[0]=0;
        call(cap);
        printf("%ld\n", dp[cap]);
        //for(int i=0; i<cap; i++) cout << dp[i]<<endl;
return 0;
}