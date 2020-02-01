#include<bits/stdc++.h>
using namespace std;

#define sf(nn) scanf ("%d", &nn)
#define pf printf
#define loop(till) for(int i=0; i<till; i++)
#define pb push_back
#define mx 10005
#define ll long long int
#define mp make_pair
#define mod 10000007

/*
creating iterator to iterate a map ...
typedef std::map<string,int>::iterator it_type;
for(it_type iterator = fruits.begin(); iterator != fruits.end(); iterator++)
*/

/*int knapsack(int i,int w)
{
    if(i<0) return 0;
    if(dp[i][w]!=-1) return dp[i][w];

        if(w-wei[i]>=0)dp[i][w] = max(ks(i-1,w),ks(i-1,w-wei[i])+val[i]);
        else dp[i][w]=ks(i-1,w);
        //cout << i << " " << w << " " << dp[i][w]<<endl;
    return dp[i][w];
}*/

vector <int> graph[mx];
vector <int> graph2[mx];

int cap,n,val[2005],wei[2005],dp[105][105],stone[105][105],r,c;

int dir_r[] = {1,1,1};
int dir_c[] = {-1,0,1};

int call(int rr,int cc)
{
    if(rr<=0) return 0;
    if(dp[rr][cc]!=-1) return dp[rr][cc];
        int ans=stone[rr][cc]+max(call(rr-1,cc-1),max(call(rr-1,cc),call(rr-1,cc+1)));
    return dp[rr][cc]=ans;
}

int main()
{
    int tc;

    while(sf(tc) == 1)
    {
        while(tc--){
        sf(r); sf(c);
        memset(stone,0,sizeof(stone));
            loop(r){
                for(int j=0; j<c; j++) sf(stone[i+1][j+1]);
            }
            int temp=INT_MIN;
            memset(dp,-1,sizeof(dp));
            //for(int i=0; i<c; i++)
            loop(c) {temp=max(temp,call(r,i+1));}

            /*for(int i=1; i<=r; i++){
                for(int j=1; j<=c; j++) cout << dp[i][j]<<" ";
                cout << endl;
            }*/
            pf("%d\n", temp);
        }
    }
    return 0;
}