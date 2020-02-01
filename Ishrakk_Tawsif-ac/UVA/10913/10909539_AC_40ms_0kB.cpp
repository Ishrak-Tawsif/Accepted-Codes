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
#define inf                     1e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      20000005
#define mod                     1000000007


int dx[8]={0,0,1,-1,1,1,-1,-1};
int dy[8]={1,-1,0,0,1,-1,1,-1};

ll ar[77][77],dp[77][77][7][3];
int n,k,fl;

ll call(int i,int j,int kk,int prev)
{
    //cout<<i<<" " << j <<endl;
    if(i>=n || i<0) return -inf;
    if(j>=n || j<0) return -inf;
    if(kk>k) return -inf;

    if(i==(n-1) && j == (n-1))
    {
        if(ar[i][j]<0 && (kk+1)<=k) {fl=1;return ar[i][j];}
        else if(ar[i][j]>=0) {fl=1;return ar[i][j];}
        else return -inf;
    }

    if(dp[i][j][kk][prev] != -inf) return dp[i][j][kk][prev];


    ll ans1,ans2,ans3;

    ans1 = ans2 = ans3 = -inf;

    if(prev == 0) ///previous move was down move
    {
        if(ar[i][j]<0) ///negetive
        {//out(ar[i][j]);
            ans1 = call(i+1,j,kk+1,0) + ar[i][j];
            ans2 = call(i,j+1,kk+1,1) + ar[i][j];
            ans3 = call(i,j-1,kk+1,2) + ar[i][j];
        }
        else
        {
            ans1 = call(i+1,j,kk,0) + ar[i][j];
            ans2 = call(i,j+1,kk,1) + ar[i][j];
            ans3 = call(i,j-1,kk,2) + ar[i][j];
        }
    }
    else if(prev == 1) ///previous move was right move
    {
        if(ar[i][j]<0) ///negetive
        {
            ans1 = call(i+1,j,kk+1,0) + ar[i][j];
            ans2 = call(i,j+1,kk+1,1) + ar[i][j];
        }
        else
        {
            ans1 = call(i+1,j,kk,0) + ar[i][j];
            ans2 = call(i,j+1,kk,1) + ar[i][j];
        }
    }
    else if(prev == 2)
    {
        if(ar[i][j]<0) ///negetive
        {
            ans1 = call(i+1,j,kk+1,0) + ar[i][j];
            ans2 = call(i,j-1,kk+1,2) + ar[i][j];
        }
        else
        {
            ans1 = call(i+1,j,kk,0) + ar[i][j];
            ans2 = call(i,j-1,kk,2) + ar[i][j];
        }
    }
//cout<< ans1 << " " << ans2 << " " << ans3 <<endl;
    return dp[i][j][kk][prev] = max(ans1,max(ans2,ans3));
}

int main()
{
//WRITE("in.txt");
    int tt=0;
    while(scanf("%d %d", &n,&k))
    {//cout<<n<<" " << k << endl;
        if(!n && !k) break;

        for(int i=0; i<n; i++) for(int j=0; j<n; j++) scanf("%lld", &ar[i][j]);

        for(int i=0; i<77; i++) for(int j=0; j<77; j++) for(int kk=0; kk<7; kk++) for(int l=0; l<3; l++)
            dp[i][j][kk][l] = -inf;

        fl=0;

        ll res = call(0,0,0,0);

        casepf(++tt);
        (fl)? pf("%lld\n",res) : pf("impossible\n");
    }
    return 0;
}