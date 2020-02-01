#include<bits/stdc++.h>
using namespace std;

int dx[8]={0,0,1,-1,1,1,-1,-1};
int dy[8]={1,-1,0,0,1,-1,1,-1};

#define sf(nn)                  scanf ("%d", &nn)
#define sfll(nn)                scanf ("%lld", &nn)
#define pf                      printf
#define casepf(nn)              printf ("Case %d: ",nn)
#define out(nn)                 cout <<nn <<endl
#define loop(var,start,till)    for(int var=start; var<till; var++)
#define pb                      push_back
#define mem(a,b)                memset(a,b,sizeof(a))
#define mp                      make_pair
#define ll                      long long int
#define inf                     2e9
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      20000005
#define mod                     1000000007

string str;
int len,dp[100000+27][5],vis[100000+27][5];

int call(int i,int j)
{
    if(i>=len) if(j%3 == 0) return 1;else return inf;
    if(i>=len) return inf;
    if(dp[i][j] != -1) return dp[i][j];

    int ans = inf,ans2;

    ans = call(i+1,(j+(str[i]-'0'))%3) + 1;
    ans2 = call(i+1,j);

    vis[i][j] = (ans>ans2)? 1 : 0;

    return dp[i][j] = min(ans,ans2);

}

void printans()
{
    int taken = 0;
    for(int i=0; i<len; i++)
    {
        if(vis[i][0] && vis[i][1])
        {
            if(!taken && str[i] == '0') continue;
            else taken++,cout<<str[i];
        }
    }
    pf("\n");
}

int main()
{
    /*cin>> str;
    len = str.length();
    mem(dp,-1);
    int res = call(0,0);
    printans();
    pf("%d\n", res);*/

    ll n,modd;

    cin>> n;
    modd = n+1;

    ll ans = (n*(n-1))/(2*n);
    pf("%lld\n", ans%modd);

    return 0;
}