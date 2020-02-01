#include<bits/stdc++.h>
using namespace std;

int arr[101][101];

int main(){

    int r,c,testcase,T=0;
        scanf("%d", &testcase);

        while(++T<=testcase){
        memset(arr,0,sizeof(arr));
        scanf("%d %d", &r,&c);
          for(int i=1; i<=r; i++){
            for(int j=1; j<=c; j++) scanf("%d",&arr[i][j]);
          }
              for(int i=2; i<=r; i++){
                for(int j=1; j<=c; j++){
                    arr[i][j]+=max(arr[i-1][j-1],max(arr[i-1][j],arr[i-1][j+1]));
                }
              }
                  int max_=INT_MIN;
                  for(int i=1;i<=c; i++){
                    max_=max(max_,arr[r][i]);//cout<<max_<<endl;
                  }
                  printf("%d\n",max_);

                  /*for(int i=1; i<=r; i++){
                    for(int j=1; j<=c; j++) printf("%d ",arr[i][j]); cout<<endl;
                  }*/
        }
return 0;
}