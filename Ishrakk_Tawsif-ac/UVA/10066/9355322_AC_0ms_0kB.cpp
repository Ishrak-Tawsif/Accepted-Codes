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
#define mx                      5005
#define mod                     100000007
#define intinf                  2e9
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())


int n1,n2,arr1[103],arr2[103],dp[103][103];

int lcs(int i,int j)
{
    if(i>n1 || j>n2) return 0;
    if(dp[i][j] != -1) return dp[i][j];

        int ans=0;
        //for(int k=j; k<=n2; k++)
        //{
            if(arr1[i] == arr2[j]) ans = lcs(i+1,j+1)+1;
            else ans = max(lcs(i+1,j),lcs(i,j+1));
        //}
    return dp[i][j] = ans;
}

int main()
{
    int tc=0;

    while(scanf("%d %d", &n1,&n2) == 2)
    {
        if(n1 ==0 && n2 == 0) break;

        loop(i,1,n1+1) sf(arr1[i]);
        loop(i,1,n2+1) sf(arr2[i]);

        int max_= (-1*intinf);
        for(int i=1; i<=n1; i++)
        {
            mem(dp,-1);
            int temp = lcs(i,1 );
            max_ = max(max_,temp);
        }
        pf("Twin Towers #%d\n",++tc);
        pf("Number of Tiles : %d\n\n", max_);
    }
    return 0;
}