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


int dx[8] = {1,-1,0,0,-1,-1,1,1};
int dy[8] = {0,0,-1,1,-1,1,-1,1};


string a,b;
int dp[33][33];
unsigned ll dp2[33][33][73];

int cnt=0;
int lsub(int i,int j)
{
    if(i == (a.length()))
    {//cout<< j << " b " << " " << j << " " <<b.length()-(j)<<endl;
        return b.length()-(j);
    }
    if(j == (b.length()))
    {//cout<<j << " a "<<a.length()-(i+1)<<endl;
        return a.length()-(i);
    }
    if(dp[i][j] != -1) return dp[i][j];

    int ans1=intinf,ans2=intinf;

    if(a[i] == b[j])
        {
            int ans = 1 + lsub(i+1,j+1);
            return dp[i][j] = ans;
        }

    ans1 = 1+lsub(i,j+1);
    ans2 = 1+lsub(i+1,j);

    return dp[i][j] = min(ans1,ans2);
}

unsigned ll numberofsub(int i,int j,int sz)
{//cout<<i<<" " << j << endl;system("pause");
    if(i>a.length() || j>b.length()) return (unsigned ll)0;
    if(i == a.length() && j != b.length())
    {
        numberofsub(i,j+1,sz-1);
    }
    if(i != a.length() && j == b.length())
    {
        numberofsub(i+1,j,sz-1);
    }
    if(i == a.length() && j == b.length() && sz == 0) return (unsigned ll)1;
    if(i == a.length() && j == b.length() && sz != 0) return (unsigned ll)0;

    if(dp2[i][j][sz] != -1) return dp2[i][j][sz];

    if(a[i] == b[j])
    {
        unsigned ll ans = numberofsub(i+1,j+1,sz-1);
        return dp2[i][j][sz] = ans;
    }

    unsigned ll ans1=0,ans2=0;

    ans1 = numberofsub(i+1,j,sz-1);
    ans2 = numberofsub(i,j+1,sz-1);

    return dp2[i][j][sz] = ans1 + ans2;
}

int main()
{
    int tc;

    sf(tc);

        for(int tt=1; tt<=tc; tt++)
        {
            cin>> a>> b;
//cout<<a<<" " << b << endl;
            mem(dp,-1);
            mem(dp2,-1);

            int ans = lsub(0,0);//cout<<ans<<endl;

            pf("Case %d: %d %llu\n", tt,ans,numberofsub(0,0,ans));
        }

    return 0;
}