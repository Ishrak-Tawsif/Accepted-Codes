#include<bits/stdc++.h>
using namespace std;

#define sf(nn) scanf ("%d", &nn)
#define pf printf
#define loop(till) for(int i=0; i<till; i++)
#define pb push_back
#define mx 10000025
#define ll long long int
#define mp make_pair
#define mod 1000005

/*
creating iterator to iterate a map ...
typedef std::map<string,int>::iterator it_type;
for(it_type iterator = fruits.begin(); iterator != fruits.end(); iterator++)
*/

int n,mask,arr[17][17],lim,dp[17][1<<17];

int call(int i,int mask)
{
    if(mask==lim) return 0;
    //if(i>=n) return 0;
    if(dp[i][mask]!=-1)return dp[i][mask];

        int ans=INT_MAX;
        for(int k=0; k<n; k++){
            if(!(mask & (1<<k))){//cout<<k<<endl;
                    int temp=0;
                    for(int j=0; j<n; j++)
                    {
                        if(j==k) temp+=arr[k][j];
                        else if((mask & (1<<j)))
                        {
                            temp+=arr[k][j];
                        }
                    }
                    //cout<<temp<<endl;
                    temp+=call(i+1,((mask)|(1<<k)));
                    //cout<<ans<<" "<<temp<<endl;
                    ans=min(ans,temp);
                }
        }
        return dp[i][mask]=ans;
}

int main()
{
    int tc;

        sf(tc);

            for(int tt=1;tt<=tc;tt++)
            {
                sf(n);
                    loop(n){
                        for(int j=0; j<n; j++) sf(arr[i][j]);
                    }
                lim = (1<<n)-1;
                memset(dp,-1,sizeof(dp));
                printf("Case %d: %d\n",tt,call(0,0));
            }
    return 0;
}