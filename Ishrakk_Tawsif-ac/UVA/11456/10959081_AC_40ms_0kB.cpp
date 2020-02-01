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

int ar[2003],dp1[2003],dp2[2003],n;

int lis()
{
    for(int i=n-1; i>=0; i--)
    {
        dp1[i] = 1;
        for(int j=0; j<n; j++)
        {
            if(ar[i]<ar[j]) dp1[i] = max(dp1[j]+1,dp1[i]);
        }
    }

    for(int i=n-1; i>=0; i--)
    {
        dp2[i] = 1;
        for(int j=0; j<n; j++)
        {
            if(ar[i]>ar[j]) dp2[i] = max(dp2[j]+1,dp2[i]);
        }
    }

    int ans = 0;
    for(int i=0; i<n; i++) ans = max(ans,dp1[i]+dp2[i]-1);

    return ans;
}

int main()
{//WRITE("in.txt");

    int tc;

    scanf("%d", &tc);

    while(tc--)
    {//system("pause");
        scanf("%d", &n);
        for(int i=0; i<n; i++) sf(ar[i]);

        mem(dp1,0);
        mem(dp2,0);

        int ans = lis();

        pf("%d\n", ans);//system("pause");
    }
    return 0;
}