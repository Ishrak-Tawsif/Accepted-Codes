#include<bits/stdc++.h>
using namespace std;

int dp[1001][1001];

int main(){

    int tc;
    string str;

        scanf("%d", &tc);

            for(int tt=1; tt<=tc; tt++){
                cin>> str;
                int len=str.length();
                int arr[len+1],sum=0;

                    for(int i=0; i<len; i++) {arr[i]=str[i]-'0';sum+=arr[i];}

                        int fl=1,ans=0; /// ans 0 means s
                        memset(dp,0,sizeof(dp));
                            while(fl){

                                fl=0;
                                for(int i=0; i<len; i++){
                                    if(dp[i][arr[i]] == -1) continue;
                                    dp[i][arr[i]]=sum-arr[i];

                                        if(dp[i][arr[i]]%3 == 0){
                                            fl=1;
                                            ans++;
                                            dp[i][arr[i]]=-1;
                                            sum-=arr[i];
                                        }
                                }
                            }
                            printf("Case %d: ", tt);
                            if(ans%2 == 0) printf("T\n");
                            else printf("S\n");
            }

return 0;
}