#include<bits/stdc++.h>
using namespace std;

#define sf(nn) scanf ("%d", &nn)
#define pf printf
#define loop(till) for(int i=0; i<till; i++)
#define pb push_back
#define mx 200005
#define ll long long int
#define mp make_pair
/*
creating iterator to iterate a map ...
typedef std::map<string,int>::iterator it_type;
for(it_type iterator = fruits.begin(); iterator != fruits.end(); iterator++)
*/


vector <int> graph[mx];
vector <int> graph2[mx];

int cap,n,val[2005],wei[2005],dp[2005][2005];

int ks(int i,int w)
{
    if(i<0) return 0;
    if(dp[i][w]!=-1) return dp[i][w];

        if(w-wei[i]>=0)dp[i][w] = max(ks(i-1,w),ks(i-1,w-wei[i])+val[i]);
        else dp[i][w]=ks(i-1,w);
        //cout << i << " " << w << " " << dp[i][w]<<endl;
    return dp[i][w];
}

int main()
{
    while(sf(cap) == 1)
    {
        sf(n);
        loop(n) {
            sf(wei[i]);
            sf(val[i]);
        }
        memset(dp,-1,sizeof(dp));
        pf("%d\n",ks(n-1,cap));
    }
    return 0;
}