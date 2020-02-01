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

int ar[7],ispos,sum,dp[7][20005];

int call(int i,int cursum)
{

    if(cursum == (sum/2))return 1;
    if(i>5) return 0;
    if(cursum>(sum/2))return 0;


    if(dp[i][cursum] != -1) return dp[i][cursum];

    int ans = 0;
    for(int j=0; j<=ar[i]; j++)
        {
            if((cursum+((i+1)*j))<=(sum/2))ans = ans | call(i+1,cursum+((i+1)*j));
            else break;

            if(ans) break;
        }

    return dp[i][cursum] = ans;
}

int main()
{
    int fl,tt=0;

    while(1)
    {

       fl=0;
       sum=0;

       for(int i=0; i<6; i++) {scanf("%d", &ar[i]); sum += (ar[i]*(i+1)); if(ar[i]) fl=1;}

       if(!fl)  break;

       pf("Collection #%d:\n", ++tt);

       if(sum%2 != 0) {pf("Can't be divided.\n\n"); continue;}

       //if(sum%2 != 0) break;

       ispos = 0;
       mem(dp,-1);

       ispos = call(0,0);

       ispos? pf("Can be divided.\n") : pf("Can't be divided.\n");

       pf("\n");
    }
    return 0;
}