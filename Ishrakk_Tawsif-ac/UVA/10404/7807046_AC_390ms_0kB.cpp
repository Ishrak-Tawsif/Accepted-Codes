#include<bits/stdc++.h>
using namespace std;


int dp[1000000];

int main(){

    int n,m,mm[11];

        while(scanf("%d", &n) == 1){
            scanf("%d", &m);
                memset(dp,0,sizeof(dp));
                    for(int i=0; i<m; i++)
                    {
                        scanf("%d", &mm[i]);
                        dp[mm[i]]=1;
                    }

                        for(int i=1; i<=n; i++)
                        {
                            for(int j=0; j<m; j++)
                            {
                                if(i-mm[j]>=0)
                                    {
                                        if(!dp[i-mm[j]]) dp[i]=1;
                                    }
                            }
                        }

                        if(dp[n]) printf("Stan wins\n");
                        else printf("Ollie wins\n");
        }
return 0;
}