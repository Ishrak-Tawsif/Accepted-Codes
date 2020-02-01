#include<bits/stdc++.h>
using namespace std;

int price[1005],wei[1005],n,people,cap,dp[1005][1005];

int call(int i,int w){
    if(i<0) return 0;
    if(dp[i][w]!=-1) return dp[i][w];

        if(w-wei[i]<0) return dp[i][w] = call(i-1,w);
        else return dp[i][w]=max(call(i-1,w),call(i-1,w-wei[i])+price[i]);
}

int main(){

    int testcase,T=0;
        scanf("%d", &testcase);

            while(++T<=testcase){
                scanf("%d", &n);
                    for(int i=0; i<n; i++) scanf("%d %d", &price[i],&wei[i]);
                scanf("%d", &people);
                int sum=0;
                memset(dp,-1,sizeof(dp));
                for(int i=0;i<people; i++){
                    scanf("%d", &cap);
                    sum += call(n-1,cap);
                }cout<<sum<<endl;
            }
return 0;
}