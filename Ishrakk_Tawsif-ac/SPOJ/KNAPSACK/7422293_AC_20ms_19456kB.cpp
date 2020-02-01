#include<bits/stdc++.h>
using namespace std;

int val[2005],wei[2005],dp[2005][2005],capacity,temp1,temp2,n;


int call(int i, int w){
    if(i<=0) return 0;
        //if(dp[i][w]==13) cout<<i<<"....."<<endl;
        if(dp[i][w]!=-1) return dp[i][w]=dp[i][w];

        if(w-wei[i]<0) return dp[i][w]=call(i-1,w);
        else return dp[i][w]=max(call(i-1,w-wei[i])+val[i],call(i-1,w));
}

void printCostTable(){
    for(int i = 0; i <= n; ++i){
        printf("%d:  ", i);
        for(int w = 0; w <= capacity; ++w)
            printf("%2d ", dp[i][w]);
        printf("\n");
    }
}

int bottomupcall(int n,int capacity){

    for(int i=0; i<=n; i++){
        for(int j=0; j<=capacity; j++){
            if(i==0 || j==0) {dp[i][j]=0; continue;}
                if(j<wei[i])  dp[i][j]=dp[i-1][j];
                else  dp[i][j]=max(val[i]+dp[i-1][j-wei[i]],dp[i-1][j]);
        }
    }
}

int main(){


        scanf("%d %d", &capacity, &n);

        memset(dp,-1,sizeof(dp));

            for(int i=1; i<=n; i++) scanf("%d %d", &wei[i],&val[i]);

                //dp[0][0]=0;
                bottomupcall(n,capacity);
                printf("%d\n", dp[n][capacity]);
                //printf("%d\n", call(n,capacity));
                //printCostTable();
                //for(int i=0; i<n; i++){for(int j=0; j<=capacity; j++) cout<<dp[i][j]<<endl;}

return 0;
}