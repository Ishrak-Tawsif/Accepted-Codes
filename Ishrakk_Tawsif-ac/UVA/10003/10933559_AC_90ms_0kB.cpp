#include<bits/stdc++.h>
using namespace std;

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
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      20000005
#define mod                     1000000007


int dx[8]={0,0,1,-1,1,1,-1,-1};
int dy[8]={1,-1,0,0,1,-1,1,-1};

int n;
int ar[103],dp[103][103];

int call(int st,int en)
{
    if(st == en) return 0;
    if(dp[st][en] != -1) return dp[st][en];

    int res = 1<<30,cur_res;

    for(int mid = st; mid<en; mid++)
    {
        int left_res = call(st,mid);
        int right_res = call(mid+1,en);

        cur_res = left_res + right_res + ar[en]-ar[st-1];

        res = min(res,cur_res);
    }
//cout<<res<<endl;
    return dp[st][en] = res;
}

int main()
{
    int total;
    while(~sf(total))
    {
        if(!total) break;

        sf(n);

        for(int i=1; i<=n; i++) sf(ar[i]);

        ar[0] = 0;
        ar[n+1] = total;

        mem(dp,-1);
        pf("The minimum cutting is %d.\n",call(1,n+1));
    }
}