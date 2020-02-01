#include<bits/stdc++.h>
using namespace std;

#define sf(nn) scanf ("%d", &nn)
#define pf printf
#define loop(var,till) for(int var=0; var<till; var++)
#define loop1(var,till) for(int var=1; var<=till; var++)
#define pb push_back
#define mx 2503
#define ll long long int
#define mp make_pair
#define mod 100000007

//int row,col,r,c,cost[21][21],dis[21][21],vis[21][21],dp[21][1<<21],len;
string grid[21];
vector <pair<int,int> >vv,cc;

int dir_r[]={-1,-1,-1,0,0,1,1,1};
int dir_c[]={-1,0,1,-1,1,-1,0,1};

/*int time_needed()
{
    double end = clock();
    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    cout<<cpu_time_used<<endl;
}*/

int arr[205][205],dp[205][205],n;

int call(int r,int c)
{
    if(r == ((2*n))) return 0;
    if(dp[r][c]!=-1) return dp[r][c];

    int ans1=INT_MIN,ans2=INT_MIN,ans3=INT_MIN;

        ans1 = call(r+1,c) + arr[r][c];
        if(r<n) ans2 = call(r+1,c+1) + arr[r][c];
        else ans2 = call(r+1,c-1) + arr[r][c];

        int ans = max(ans1,ans2);
    //cout<<ans <<endl;
    return dp[r][c]=ans;
}

int main()
{
    int tc;
        sf(tc);

            loop1(tt,tc)
            {
                sf(n);

                    memset(arr,0,sizeof(arr));

                    for(int i=1; i<=n; i++)
                    {
                        for(int j=1; j<=i; j++) sf(arr[i][j]);
                    }

                    for(int i=n-1,k=n+1; i>=0; i--,k++)
                    {
                        for(int j=1; j<=i; j++) sf(arr[k][j]);
                    }

                    /*for(int i=1; i<=(2*n)-1; i++)
                    {
                        for(int j=1; j<=n; j++) cout<<arr[i][j]<<" ";
                        cout<<endl;
                    }*/

                    memset(dp,-1,sizeof(dp));
                    int ans=INT_MAX;

                    //for(int i=1; i<=3; i++)
                    //{

                        ans=(ans,call(1,1));
                        /*for(int i=1; i<=(2*n)-1; i++)
                        {
                            for(int j=1; j<=n; j++) cout<< dp[i][j] << " ";
                            cout<<endl;
                        }*/
                    //}
                    pf("Case %d: %d\n",tt,ans);
            }
    return 0;
}