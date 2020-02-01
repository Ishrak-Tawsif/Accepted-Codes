#include<bits/stdc++.h>
using namespace std;

vector <int> v[201];
int dp[201][201],n;

int call(int i, int j){

    if(i>=0 && i<((2*n)-1) && j>=0 && j<v[i].size()){
        if(dp[i][j]!=-1) return dp[i][j];

            int temp=INT_MIN;
                temp=max(temp,call(i+1,j)+v[i][j]);
                    if(i<n-1) temp=max(temp,call(i+1,j+1)+v[i][j]);
                    else temp=max(temp,call(i+1,j-1)+v[i][j]);
                      //cout<<i << " " << j<<endl;
                      return  dp[i][j]=temp;
    }
    else {/*cout<<"returning zero"<<endl;*/return 0;}
}

int main(){

    int temp,testcase;

    scanf("%d", &testcase);

        for(int tt=1; tt<=testcase; tt++){
            memset(dp,-1,sizeof(dp));
            scanf("%d", &n);
                for(int i=0; i<n; i++){
                    v[i].clear();
                    for(int j=0; j<=i; j++) {scanf("%d", &temp); v[i].push_back(temp);}
                }
                for(int i=n,k=1; n>=k; i++,k++){
                    v[i].clear();
                    for(int j=0; j<n-k; j++) {scanf("%d", &temp); v[i].push_back(temp);}
                }

                printf("Case %d: %d\n", tt,call(0,0));
         }//out<<":)"<<endl;
return 0;
}