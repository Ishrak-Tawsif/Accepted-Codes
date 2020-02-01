#include<bits/stdc++.h>
using namespace std;

vector<int>v[23];
int n,dp[23][5];

int call(int i, int j){ //cout << i << " " << j << endl;
    if(i>=0 && i<n && j>=0 && j<3){
        if(dp[i][j]!=-1) return dp[i][j];

            int temp1=INT_MAX,temp2=INT_MAX,temp3=INT_MAX,a,b;
            //for(int k=0; k<3; k++){
                if(j==0){a=1,b=2;}
                else if(j==1){a=-1;b=1;}
                else if(j==2){a=-1;b=-2;}

                    temp1= call(i+1,j+a)+v[i][j+a];
                    temp2= call(i+1,j+b)+v[i][j+b];
                    //temp3= min(temp3, call(i+1,2)+v[i][j]);
            //}
                    //temp= min(temp, call(i+1,2)+v[i][j]);
            //cout << temp1 << " " <<temp2<<endl;
            return dp[i][j]=min(temp1,temp2);
    }
    else return 0;
}

int main(){

    int testcase,temp;

        scanf("%d", &testcase);

            for(int tt=1; tt<=testcase; tt++){

                //memset(dp,-1,sizeof(dp));
                scanf("%d", &n);

                    for(int i=0; i<n; i++){

                        v[i].clear();
                        for(int j=0; j<3; j++){
                            scanf("%d", &temp);
                            v[i].push_back(temp);
                        }
                    }//cout << ":)" << endl;

                    int ans=INT_MAX;

                        for(int i=0; i<3; i++){
                            memset(dp,-1,sizeof(dp));
                            int temp=v[0][i]+call(1,i);
                            ans=min(ans,temp);//cout<<ans<<endl;
                        }
                    printf("Case %d: %d\n", tt,ans);
                    //for(int i=0; i<n; i++) cout << dp[i] << endl;
            }
return 0;
}