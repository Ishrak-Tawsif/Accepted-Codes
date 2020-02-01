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
#define mod                     100000007


int dr8[]={-1,-1,0,1,1,1,0,-1};
int dc8[]={0,1,1,1,0,-1,-1,-1};


vector <int> graph[50005];
int vis[50005];


int dfs(int sr)
{
    vis[sr]=1;

        for(int i=0; i<graph[sr].size(); i++)
        {
            int v = graph[sr][i];

                if(!vis[v])
                {
                    vis[v] = 1;
                    dfs(v);
                }
        }
}

int main()
{
    int n,m,u,v,cnt,_case=0;

        while(scanf("%d %d",&n,&m) == 2)
        {
            if(n==0 && m==0) break;

                for(int i=0; i<50005; i++)
                {
                    vis[i]=0;
                    graph[i].clear();
                }

                loop(i,0,m)
                {
                    scanf("%d %d",&u,&v);
                    graph[u].pb(v);
                    graph[v].pb(u);
                }

                cnt=0;
                for(int i=1; i<=n; i++)
                {
                    if(!vis[i])
                    {
                        cnt++;
                        dfs(i);
                    }
                }
                pf("Case %d: %d\n",++_case,cnt);
        }

    return 0;
}