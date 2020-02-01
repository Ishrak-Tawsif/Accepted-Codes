#include<bits/stdc++.h>
using namespace std;

#define sf(nn) scanf ("%d", &nn)
#define pf printf
#define loop(var,till) for(int var=0; var<till; var++)
#define loop1(var,till) for(int var=1; var<=till; var++)
#define pb push_back
#define mx 1003
#define ll long long int
#define mp make_pair
#define mod 1000000

int arr[203],n,k,d;
ll dp[203][13][203];

ll call(int i,int j,int sum)
{
    if(i>=n)
    {
        if(j==k)
        {
            //if(sum == 0) return 1;
            if(sum%d == 0) {/*cout<<sum<<endl;*/return 1;}
            else return 0;
        }
        else return 0;
    }
    if(j==k)
    {
        //if(sum==0) return 1;
        if(sum%d==0) {/*cout<<sum<<endl;*/return 1;}
        else return 0;
    }
    if(dp[i][j][sum] != -1) return dp[i][j][sum];

        ll ans=0;

        ans = call(i+1,j+1,((sum+arr[i])%d)+d);
        ans += call(i+1,j,sum);
//cout<<i<<" " <<j<<" "<<ans<<endl;
    return dp[i][j][sum] = ans;
}

int main()
{
    int tc=0,q;

        //sf(tc);

            //loop1(tt,tc)
            //{
                while(scanf("%d %d", &n,&q)==2){//sf(d);
                //sum=0;
                    if(n==0 && q==0) break;
                    loop(i,n) {sf(arr[i]);}

                    //sort(coin,coin+n);
                    pf("SET %d:\n",++tc);
                    int tt=0;
                    while(q--){
                        sf(d); sf(k);
                        memset(dp,-1,sizeof(dp));
                        pf("QUERY %d: %lld\n",++tt,call(0,0,0));
                    }
                }
            //}
     return 0;
}