#include<bits/stdc++.h>
using namespace std;

#define sf(nn) scanf ("%d", &nn)
#define pf printf
#define loop(var,till) for(int var=0; var<till; var++)
#define loop1(var,till) for(int var=1; var<=till; var++)
#define pb push_back
#define mx 103
#define ll long long int
#define mp make_pair
#define mod 100000007

int dir_r_8[]={-1,-1,-1,0,0,1,1,1};
int dir_c_8[]={-1,0,1,-1,1,-1,0,1};
int dir_r_4[]={-1,1,0,0};
int dir_c_4[]={0,0,-1,1};

string str;
ll dp[103][103][103],arr[103][103],row,col,vis[103][103];

ll call(int r1,int c1,int r2, int c2)
{
    if(r1> row || r2>row || c1>col || c2>col || (r1 == r2 && c1 >= c2)) return 0;
    if(dp[r1][c1][c2] != -1) return dp[r1][c1][c2];

        ll ans = LONG_MIN;

            ans = call(r1+1,c1,r2+1,c2)+ arr[r1][c1] + arr[r2][c2];
            ans = max(ans,call(r1+1,c1,r2,c2+1)+ arr[r1][c1] + arr[r2][c2]);
            ans = max(ans,call(r1,c1+1,r2+1,c2)+ arr[r1][c1] + arr[r2][c2]);
            ans = max(ans,call(r1,c1+1,r2,c2+1)+ arr[r1][c1] + arr[r2][c2]);
    return dp[r1][c1][c2] = ans;
}

int main()
{
    int tc;

        sf(tc);
            loop1(tt,tc)
            {
                scanf("%lld %lld", &row,&col);

                loop1(i,row){ loop1(j,col) {scanf("%lld", &arr[i][j]);}}
                memset(dp,-1,sizeof(dp));
                memset(vis,0,sizeof(vis));
                pf("Case %d: %lld\n",tt,call(1,2,2,1)+arr[1][1]+arr[row][col]);
            }
    return 0;
}