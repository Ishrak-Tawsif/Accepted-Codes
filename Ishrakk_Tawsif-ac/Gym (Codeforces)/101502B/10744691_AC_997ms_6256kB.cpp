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
#define intinf                  1e9
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      100005
#define mod                     1000000007


int dx[8] = {1,-1,0,0,-1,-1,1,1};
int dy[8] = {0,0,-1,1,-1,1,-1,1};

int dirr[] = {-1,-1,0,0,1,1};
int dirc[] = {0,1,-1,1,-1,0};

int ar[6][4]={{2,4,5,3},{1,3,4,6},{1,2,5,6},{1,2,5,6},{1,3,4,6},{2,3,4,5}};

//int totsum,cur,dp[7][10005][10005];

/*int call(int i,int sum,int ans)
{
    if(sum == totsum) {cout<<" " <<i+1<<" "<<ans<<endl;return ans;}
    if(sum>totsum) return intinf;

    if(dp[i][sum][ans] != -1) return dp[i][sum][ans];


    int ans1 = intinf,ans2=intinf;

    for(int j=0; j<4; j++)
    {
        if(sum+ar[i][j]<=totsum)ans1 = min(ans1,call(ar[i][j]-1,sum+ar[i][j],ans+1));
        //ans2 = min(ans1,ans2);
       // cout<<ans1<<endl;
    }

    return dp[i][sum] = ans1;
}*/

unordered_map <int,int> mc;
int rw[100005];

int main()
{
    int tc;

    sf(tc);

    //for(int i=0; i<6; i++){for(int j=0; j<4; j++)pf(" %d",ar[i][j]);pf("\n");}

    while(tc--)
    {
        mc.clear();

        int n,r,c;

        sf(n);

        loop(i,0,n)
        {
            scanf("%d %d", &rw[i],&c);
            //mr[rw[i]]++;
            mc[c]++;
        }

        ll ans=0;
        for(int i=0; i<n; i++)
        {
            ans += (ll)mc[rw[i]];
        }
        pf("%lld\n",ans);
    }
    return 0;
}