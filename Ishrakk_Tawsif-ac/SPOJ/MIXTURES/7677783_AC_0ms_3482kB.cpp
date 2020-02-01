#include<bits/stdc++.h>
using namespace std;

int n,arr[101],dp[101][101],sum[101];

int call(int s, int e){

    if(s==e) return 0;
    if(dp[s][e]!=-1) return dp[s][e];

        int res=1<<30,temp;
        for(int mid=s; mid<e; mid++){

            int lef_res=call(s,mid);
            int l_col=(sum[mid]-sum[s-1])%100;

            int rig_res=call(mid+1,e);
            int r_col=(sum[e]-sum[mid])%100;

            temp= lef_res+rig_res+(l_col*r_col);
            if(res>temp) res=temp;
        }
       return dp[s][e]=res;
}

int main(){


        while(scanf("%d", &n) == 1){
            for(int i=1; i<=n; i++) {scanf("%d", &arr[i]); sum[i]=sum[i-1]+arr[i];}
            memset(dp,-1,sizeof(dp));
            cout<<call(1,n)<<endl;;
        }
return 0;
}