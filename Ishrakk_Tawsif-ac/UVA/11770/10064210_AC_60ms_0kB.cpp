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

int n,m,vis[2][10005];
vector <int> graph[10005],topsort;

int dfstopsort(int sr)
{
    vis[0][sr] = 1;

        for(int i=0; i<graph[sr].size(); i++)
        {
            int v = graph[sr][i];

                if(!vis[0][v])
                {
                    dfstopsort(v);
                }
        }
    topsort.pb(sr);
}

int dfs(int sr)
{
    vis[1][sr] = 1;

        for(int i=0; i<graph[sr].size(); i++)
        {
            int v=graph[sr][i];

                if(!vis[1][v])
                {
                    dfs(v);
                }
        }
}

int main()
{
    int tc,u,v,ans,cnt;
        sf(tc);

            loop(tt,1,tc+1)
            {
                sf(n);
                sf(m);

                for(int i=0; i<10005; i++)
                {
                    graph[i].clear();
                    vis[0][i] = vis[1][i] = 0;
                }
                topsort.clear();

                    loop(i,0,m)
                    {
                        scanf("%d %d",&u,&v);
                        graph[u].pb(v);
                    }

                    for(int i=1;i<=n; i++) if(!vis[0][i])dfstopsort(i);

                    ans=0,cnt=0;
                    for(int i=topsort.size()-1; i>=0; i--)
                    {//cout<<vis[1][topsort[i]]<<endl;
                        if(!vis[1][topsort[i]])
                        {
                            ans++;//out(topsort[i]);
                            dfs(topsort[i]);
                        }
                    }
                    pf("Case %d: %d\n",tt,ans);
            }
    return 0;
}