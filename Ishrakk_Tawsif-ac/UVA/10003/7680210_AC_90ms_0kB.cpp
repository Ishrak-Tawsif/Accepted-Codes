#include<bits/stdc++.h>
using namespace std;

int n,arr[101],dp[101][101],sum[101],tot;

int call(int s, int e){

    if(s==e) return 0;
    if(dp[s][e]!=-1) return dp[s][e];

        int res=1<<30,temp;
        for(int mid=s; mid<e; mid++){

            int lef_res=call(s,mid);
            //int l_col=(sum[mid]-sum[s-1])%100;
            //int left=(tot-s)+(tot-mid);

            int rig_res=call(mid+1,e);
            //int r_col=(sum[e]-sum[mid])%100;

            temp= lef_res+rig_res+arr[e]-arr[s-1];
            //cout<<mid<<" "<<s<<" "<<e<<endl;
            //cout<<temp<<" "<<lef_res<<" "<<rig_res<<" "<<l_col<<" "<<r_col<<endl;
            if(res>temp) res=temp;
        }
       return dp[s][e]=res;
}

int main(){


        while(scanf("%d", &tot) == 1 && tot){
            scanf("%d", &n);
            for(int i=1; i<=n; i++) {scanf("%d", &arr[i]); sum[i]=sum[i-1]+arr[i];}
            memset(dp,-1,sizeof(dp));
            arr[0]=0; arr[n+1]=tot;
            cout<<"The minimum cutting is "<<call(1,n+1)<<"."<<endl;
        }

return 0;
}