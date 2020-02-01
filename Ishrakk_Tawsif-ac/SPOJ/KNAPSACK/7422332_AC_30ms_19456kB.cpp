#include<bits/stdc++.h>
using namespace std;

int val[2005],wei[2005],n,capacity,dp[2005][2005];

int call(int i,int w){
     if(i<0) return 0;
        if(dp[i][w]!=-1) return dp[i][w];

            if(w-wei[i]<0) return dp[i][w]=call(i-1,w);
            else return dp[i][w]=max(call(i-1,w),call(i-1,w-wei[i])+val[i]);
}

int main(){

    scanf("%d %d", &capacity, &n);
        for(int i=0; i<n; i++) scanf("%d %d", &wei[i], &val[i]);
            memset(dp,-1,sizeof(dp));
            printf("%d\n", call(n-1,capacity));
return 0;
}