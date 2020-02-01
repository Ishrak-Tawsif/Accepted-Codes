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

int n,m,k,dp[53][51];
vector <int> graph[53];

int call(int i,int kk)
{//cout<<i<<" "<<kk<<endl;
    if(kk >= k)
    {
        if(i == (n-1)){return kk;}
        if(kk>3*k) return inf;
    }
    if(dp[i][kk] != -1) {/*if(!dp[i][kk])cout<<i<<" " <<kk<<" ",system("pause");*/return dp[i][kk];}

    int ans = inf;
    for(int j=0; j<graph[i].size(); j++)
    {
        int v = graph[i][j];
        ans = min(ans,call(v,kk+1));
    }
//if(ans)cout<<ans<<" "<<i<<endl;
    return dp[i][kk] = ans;
}

int main()
{//WRITE("in.txt");
    //ll temp;
    int tc,u,v;

    //scanf("%d", &tc);

    //for(int tt=1; tt<=tc; tt++)
    //{
       while(scanf("%d %d %d", &n,&m,&k))
    {

       if(!n && !m && !k) break;

       for(int i=0; i<53; i++)graph[i].clear();

       loop(i,0,m)
       {
           scanf("%d %d", &u,&v);
           graph[u].pb(v);
       }

       mem(dp,-1);//cout<<dp[0][0]<<endl;
       int res = call(0,1);

       (res == inf)? pf("LOSER\n") : pf("%d\n",res);
    }
    return 0;
}