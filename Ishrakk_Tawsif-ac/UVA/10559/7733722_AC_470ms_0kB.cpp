#include<bits/stdc++.h>
using namespace std;


int arr[203],n,cnt=0,max_,dp[203][203][203];

int call(int s, int e, int c){
cnt++;
    //if(s==e) {/*cout<<c<<"/////"<<endl;*/return c*c;}
    if(s>e) return 0;
    if(dp[s][e][c]!=-1) return dp[s][e][c];

        int max_ = ((c+1)*(c+1))+ call(s+1,e,0); //cout << s << " " << e << " " << max_ << endl;
        for(int mid=s+1; mid<=e; mid++){ //cout << mid <<".."<<endl;  system("pause");
            if(arr[mid] == arr[s]) {max_=max(max_, (call(s+1,mid-1,0) + call(mid,e,c+1)));
                                    /*cout<<call(mid,e,c+1)<<" call" << endl;*/}
            //max_ = c*c+ call(s+1,e,1);
        }//cout<<"returning "<<max_<<endl;

        return dp[s][e][c]=max_;
}

int main(){

    int tc;
        scanf("%d", &tc);
            for(int i=1; i<=tc; i++){
                scanf("%d", &n);
                for(int k=0; k<203; k++) for(int l=0; l<203; l++) for(int m=0; m<203; m++) dp[k][l][m]=-1;

                    for(int j=0; j<n; j++) scanf("%d", &arr[j]);
                        printf("Case %d: %d\n",i,call(0,n-1,0));
            }
return 0;
}