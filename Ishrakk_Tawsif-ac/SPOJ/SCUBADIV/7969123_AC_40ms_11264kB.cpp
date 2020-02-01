#include<bits/stdc++.h>
using namespace std;

#define loop(i,n) for(int ii=0; ii<n; ii++){}

int oxy[1005],nit[1005],wei[1005],dp[1005][25][81];

int call(int o, int ni, int in){

    if(dp[in][o][ni]!=-1) return dp[in][o][ni];
    if(o==0 && ni==0) return dp[in][o][ni]=0;
    else if(in==0) return dp[in][o][in]=99999;
    else{
        return dp[in][o][ni]=min(call(o,ni,in-1), call(max(o-oxy[in-1],0),max(ni-nit[in-1],0),in-1)+wei[in-1]);
    }
}

int main(){
    int ned_oxy,ned_nit,testcase,cyl;
        scanf("%d", &testcase);

            while(testcase--){

                for(int i=0; i<1005; i++){
                    for(int j=0; j<25; j++){
                        for(int k=0; k<81; k++) dp[i][j][k]=-1;
                    }
                }

                scanf("%d %d %d", &ned_oxy, &ned_nit, &cyl);
                    for(int c=0; c<cyl; c++){
                        scanf("%d %d %d", &oxy[c], &nit[c], &wei[c]);
                    }
                    printf("%d\n", call(ned_oxy,ned_nit,cyl));
            }
return 0;
}