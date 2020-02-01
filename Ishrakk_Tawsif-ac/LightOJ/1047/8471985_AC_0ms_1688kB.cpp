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

int arr[5][23],dp[5][23],n;

int call(int cl,int hs)
{
    if(hs == n+1) return 0;
    if(dp[cl][hs]!=-1) return dp[cl][hs];

    int ans1=INT_MAX,ans2=INT_MAX;

        if(cl==1)
        {
            ans1=call(cl+1,hs+1) + arr[cl][hs];
            ans2=call(cl+2,hs+1) + arr[cl][hs];
        }
        else if(cl==2)
        {
            ans1=call(cl+1,hs+1) + arr[cl][hs];
            ans2=call(cl-1,hs+1) + arr[cl][hs];
        }
        else if(cl==3)
        {
            ans1=call(cl-1,hs+1) + arr[cl][hs];
            ans2=call(cl-2,hs+1) + arr[cl][hs];
        }
        int ans = min(ans1,ans2);
        //cout<< cl << " " << hs << " " << ans << endl;
    return dp[cl][hs]=ans;
}

int main()
{
    int tc;
        sf(tc);

            loop1(tt,tc)
            {
                sf(n);

                    loop1(i,n)
                    {
                        scanf("%d %d %d",&arr[1][i],&arr[2][i],&arr[3][i]);
                    }

                    memset(dp,-1,sizeof(dp));
                    int ans=INT_MAX;

                    for(int i=1; i<=3; i++)
                    {

                        ans=min(ans,call(i,1));
                        /*for(int i=1; i<=n; i++)
                        {
                            for(int j=1; j<=3; j++) cout<< dp[j][i] << " ";
                            cout<<endl;
                        }*/
                    }
                    pf("Case %d: %d\n",tt,ans);
            }
    return 0;
}