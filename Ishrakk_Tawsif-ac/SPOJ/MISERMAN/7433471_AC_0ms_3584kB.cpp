#include<bits/stdc++.h>
using namespace std;

int r,c,testcase,T=0;
int arr[101][101],dp[101][101];

int call(int i,int j){

    if(i<=0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=arr[i][j]+min(call(i-1,j-1),min(call(i-1,j),call(i-1,j+1)));
}

int main(){


        //scanf("%d", &testcase);

        //while(++T<=testcase){
        for(int i=0; i<=101; i++){for(int j=0; j<=101; j++)arr[i][j]=99999;}
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

                  int min_=99999;
                  for(int i=1; i<=c; i++){
                    min_=min(min_,call(r,i));
                  }
                  printf("%d\n",min_);

                  /*for(int i=1; i<=r; i++){
                    for(int j=1; j<=c; j++) printf("%3d ",dp[i][j]); cout<<endl;
                  }*/
        //}
return 0;
}