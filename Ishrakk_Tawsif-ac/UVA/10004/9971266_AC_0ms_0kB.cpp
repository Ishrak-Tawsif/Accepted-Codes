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


vector <int> graph[203];
int color[203],vis[203];

bool dfs(int sr)
{
    vis[sr]=1;

        for(int i=0; i<graph[sr].size(); i++)
        {
            int v = graph[sr][i];

                if(!vis[v])
                {
                    color[v] = 1-color[sr];
                    dfs(v);
                }
                else
                {
                    if(color[sr] == color[v]) {return 0;}
                }
        }
    return 1;
}

int main()
{
    int n,m,u,v;

        while(sf(n)==1 && n)
        {
            sf(m);

                for(int i=0; i<203; i++)
                {
                    color[i]=-1;
                    vis[i]=0;
                    graph[i].clear();
                }

                loop(i,0,m)
                {
                    scanf("%d %d", &u,&v);
                    graph[u].pb(v);
                    graph[v].pb(u);
                }

                color[0]=0;
                (dfs(0) == true)? pf("BICOLORABLE.\n") : pf("NOT BICOLORABLE.\n");
        }
    return 0;
}