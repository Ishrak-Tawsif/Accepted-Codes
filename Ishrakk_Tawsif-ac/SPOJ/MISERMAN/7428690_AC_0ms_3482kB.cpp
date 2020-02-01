#include<bits/stdc++.h>
using namespace std;

int arr[101][101];

int main(){

    int r,c,testcase,T=0;
        //scanf("%d", &testcase);

        //while(++T<=testcase){
        for(int i=0; i<=101; i++){for(int j=0; j<=101; j++)arr[i][j]=99999;}
        scanf("%d %d", &r,&c);
          for(int i=1; i<=r; i++){
            for(int j=1; j<=c; j++) scanf("%d",&arr[i][j]);
          }
              for(int i=2; i<=r; i++){
                for(int j=1; j<=c; j++){
                    arr[i][j]+=min(arr[i-1][j-1],min(arr[i-1][j],arr[i-1][j+1]));
                }
              }
                  int max_=99999;
                  for(int i=1;i<=c; i++){
                    max_=min(max_,arr[r][i]);//cout<<max_<<endl;
                  }
                  printf("%d\n",max_);

                  /*for(int i=1; i<=r; i++){
                    for(int j=1; j<=c; j++) printf("%2d ",arr[i][j]); cout<<endl;
                  }*/
        //}
return 0;
}