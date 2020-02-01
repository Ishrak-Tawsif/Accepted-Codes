#include<bits/stdc++.h>
using namespace std;

#define sf(nn)                  scanf ("%d", &nn)
#define sfll(nn)                scanf ("%lld", &nn)
#define pf                      printf
#define casepf(nn)              printf ("Case %d:\n",nn)
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

int original[23],ar[23],dp[23][23],n;

int call(int i,int j)
{//cout<<i<<" "<< j<<endl;
    if(i>=n || j>=n) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    int ans1 = 0,ans2=0;

    if(original[i] == ar[j])
        ans1 = call(i+1,j+1) + 1;
    else
        ans2 = max(call(i,j+1),call(i+1,j));

    return dp[i][j] = max(ans1,ans2);
}

int main()
{//WRITE("in.txt");

    int temp;
    while(~scanf("%d", &n))
    {
        for(int i=0; i<n; i++) sf(temp),original[temp-1] = i;


        while(~scanf("%d", &temp))
        {
            ar[temp-1] = 0;
            for(int i=1; i<n; i++) scanf("%d", &temp),ar[temp-1] = i;

            mem(dp,-1);
            pf("%d\n", call(0,0));
        }
    }
    return 0;
}