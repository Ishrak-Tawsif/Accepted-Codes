#include<bits/stdc++.h>
using namespace std;

#define sf(nn) scanf ("%d", &nn)
#define pf printf
#define loop(var,till) for(int var=0; var<till; var++)
#define loop1(var,till) for(int var=1; var<=till; var++)
#define pb push_back
#define mx 10005
#define ll long long int
#define mp make_pair
#define mod 100000007

int dir_r_8[]={-1,-1,-1,0,0,1,1,1};
int dir_c_8[]={-1,0,1,-1,1,-1,0,1};
int dir_r_4[]={-1,1,0,0};
int dir_c_4[]={0,0,-1,1};


int arr[2][1003],dis[2][1003],n,dp[2][1003],res=0;

int call2(int cur,int pos)
{
    if(pos == 0) return 0;

        int temp1 = dp[cur][pos-1];
        int temp2 = dp[1-cur][pos]+dis[cur][pos-1];
            if(temp1>temp2)
            {
                res += temp2;
                call2(1-cur,pos-1);
            }
            else{
                res += temp1;
                call2(cur,pos-1);
            }cout<<res<<endl;
    return res;
}

int call(int build,int pos)
{
    if(pos==0) return 0;
    if(dp[build][pos] != -1) return dp[build][pos];

        int ans=INT_MAX;
            //cout<<build<<" " <<pos<<" "<<call(build,pos-1) << " " << arr[build][pos] << " " <<call(1-build,pos-1) << " " << arr[build][pos] << " " << dis[1-build][pos-1]<<endl;

            ans = min((call(build,pos-1)+arr[build][pos]),arr[build][pos]+dis[1-build][pos-1]+(call(1-build,pos-1)));
            //cout<<ans<<endl;
    return dp[build][pos]=ans;
}

int main()
{
    int tc;

        sf(tc);

            loop1(tt,tc)
            {
                sf(n);

                    loop1(i,n) sf(arr[0][i]);
                    loop1(i,n) sf(arr[1][i]);
                    loop1(i,n-1) sf(dis[0][i]);
                    loop1(i,n-1) sf(dis[1][i]);

                    memset(dp,-1,sizeof(dp));
                    int ans = min(call(1,n),call(0,n));//cout<<ans<<endl;
                    /*for(int i=1; i<=n; i++)
                    {
                        cout << dp[0][i] << " " << dp[1][i] << endl;
                    }*/
                    /*res=0;

                        if(dp[0][n]<dp[1][n])
                        {
                            res += dp[0][n];
                            cout<<call2(0,n)<<endl;
                        }
                        else{
                            res += dp[1][n];
                            cout<<call2(1,n)<<endl;
                        }*/

                    pf("Case %d: %d\n",tt,ans);
            }
    return 0;
}