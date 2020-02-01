#include<bits/stdc++.h>
using namespace std;

int n,m,mm[11],dp[1000000];

int main(){

    while(scanf("%d", &n) == 1){

        scanf("%d", &m);
        memset(dp,0,sizeof(dp));
            for(int i=0; i<m; i++) {scanf("%d", &mm[i]); dp[mm[i]]=1;}

                for(int taken=1; taken<=n; taken++){

                    for(int i=0; i<m; i++){
                        if(taken-mm[i] >=0){
                            if(!dp[taken-mm[i]]) dp[taken]=1;
                        }
                    }
                }

                if(dp[n]) cout<< "Stan wins"<<endl;
                else cout << "Ollie wins"<<endl;
    }
return 0;
}