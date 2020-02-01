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


int arr[103][103],sum[103][103],dp[103];

int main()
{

     int n;
        sf(n);

            loop1(i,n)
            {
                loop1(j,n)
                {
                    sf(arr[i][j]);
                    sum [i][j] = sum[i][j-1] + arr[i][j];
                }
            }

            /*loop1(i,n)
            {
                loop1(j,n)
                {
                    pf(" %d ",sum[i][j]);
                }pf("\n");
            }*/


            int ans=INT_MIN;

            for(int i=0; i<=n; i++)
            {
                for(int j=i+1; j<=n; j++)
                {
                    dp[0]=0;
                    for(int k=1; k<=n; k++)
                    {
                        dp[k] = max(sum[k][j]-sum[k][i],sum[k][j]-sum[k][i]+dp[k-1]);
                        ans = max(ans,dp[k]);
                    }
                }
            }

        pf("%d\n",ans);

     return 0;
}

/*
2
9 2
-4 1
*/