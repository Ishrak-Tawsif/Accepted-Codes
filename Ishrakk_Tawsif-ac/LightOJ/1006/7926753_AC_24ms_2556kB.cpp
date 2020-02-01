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

int cap,n,val[2005],wei[2005],dp[10005],a,b,c,d,e,f;


int fn( int n ) {
    if( n == 0 ) return a;
    if( n == 1 ) return b;
    if( n == 2 ) return c;
    if( n == 3 ) return d;
    if( n == 4 ) return e;
    if( n == 5 ) return f;
    if(dp[n]!=-1) return dp[n];
    return( dp[n]=(fn(n-1)%mod) + (fn(n-2)%mod) + (fn(n-3)%mod) + (fn(n-4)%mod) + (fn(n-5)%mod) + (fn(n-6)%mod))%mod;
}


int main()
{
    int tc;

    while(sf(tc) == 1)
    {
        loop(tc){
            memset(dp,-1,sizeof(dp));
            scanf("%d %d %d %d %d %d %d",&a, &b, &c, &d, &e, &f, &n);
            pf("Case %d: %d\n",i+1,fn(n)%mod);
        }
    }
    return 0;
}