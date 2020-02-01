#include<bits/stdc++.h>
using namespace std;

int r,c,testcase,T=0;
int arr[101][101],dp[101][101];

int call(int i,int j){

    if(i<=0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=arr[i][j]+max(call(i-1,j-1),max(call(i-1,j),call(i-1,j+1)));
}

int main(){


        scanf("%d", &testcase);

        while(++T<=testcase){
        memset(arr,0,sizeof(arr));
        memset(dp,-1,sizeof(dp));
        scanf("%d %d", &r,&c);

          for(int i=1; i<=r; i++){
            for(int j=1; j<=c; j++) scanf("%d",&arr[i][j]);
          }
              /*for(int i=2; i<=r; i++){
                for(int j=1; j<=c; j++){
                    arr[i][j]+=max(arr[i-1][j-1],max(arr[i-1][j],arr[i-1][j+1]));
                }
              }
                  int max_=INT_MIN;
                  for(int i=1;i<=c; i++){
                    max_=max(max_,arr[r][i]);//cout<<max_<<endl;
                  }
                  printf("%d\n",max_);*/

                  int max_=INT_MIN;
                  for(int i=1; i<=c; i++){
                    max_=max(max_,call(r,i));
                  }
                  printf("%d\n",max_);

                  //for(int i=1; i<=r; i++){
                   // for(int j=1; j<=c; j++) printf("%3d ",dp[i][j]); cout<<endl;
                  //}
        }
return 0;
}