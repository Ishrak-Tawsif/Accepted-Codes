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
#define intinf                  2e9
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      100005
#define mod                     1000000007


int dr8[]={-1,-1,0,1,1,1,0,-1};
int dc8[]={0,1,1,1,0,-1,-1,-1};

int arr[] = {2,3,4,5};
int n,k,ans=intinf,dp[53][253][253];

int call(int s,int i,int dui)
{
    if(s>n) return 0;
    if(s==n)
    {
       if(i==k) {/*cout<<dui<<endl;*/return dui;}
       else return intinf;
    }

    if(dp[s][i][dui] != -1) return dp[s][i][dui];

    int ans1=intinf,ans2=intinf,ans3=intinf,ans4=intinf;

    if(i+arr[0]<=k)ans1 = call(s+1,i+arr[0],dui+1);
    if(i+arr[1]<=k)ans2 = call(s+1,i+arr[1],dui);
    if(i+arr[2]<=k)ans3 = call(s+1,i+arr[2],dui);
    if(i+arr[3]<=k)ans4 = call(s+1,i+arr[3],dui);

    return dp[s][i][dui] = min(ans1,min(ans2,min(ans3,ans4)));
}

int main()
{
    scanf("%d %d", &n,&k);

    mem(dp,-1);
    int ans = call(0,0,0);
    /*(ans == intinf)? pf("0\n") :*/ pf("%d\n", ans); ///koyta sub, koto nilam, 2 koybar

    return 0;
}