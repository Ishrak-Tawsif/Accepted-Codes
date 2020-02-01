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

int dir_r_4[] = {0, 0, 1, -1};
int dir_c_4[] = {1, -1, 0, 0};

vector <pair<int,int> > graph[20005];
int vis[20005],dis[20005];


int dijkstra(int sr,int des)
{
    vis[sr] = 1;
    dis[sr] = 0;
    set <pair<int,int> > s;
    s.insert(mp(dis[sr],sr));

        while(!s.empty())
        {
            pair <int,int> temp = *s.begin();
            s.erase(s.begin());

                int udis = temp.first;
                int u = temp.second;

                    if(u == des) return dis[u];

                    for(int i=0; i<graph[u].size(); i++)
                    {
                        int v = graph[u][i].first;
                        int uv_dis = graph[u][i].second;

                            if(/*!vis[v] && */dis[v]> dis[u] + uv_dis)
                            {
                                dis[v] = dis[u] + uv_dis;
                                vis[v] = 1;
                                s.insert(mp(dis[v],v));
                            }
                    }
        }
     return -1;
}

int main()
{//WRITE("in.txt");
    int tc,n,m,s,t,u,v,cst;

        sf(tc);

            loop(tt,1,tc+1)
            {
                scanf("%d %d %d %d", &n,&m,&s,&t);

                for(int i=0; i<20005; i++)
                {
                    vis[i] = 0;
                    dis[i] = intinf;
                    graph[i].clear();
                }

                    loop(i,0,m)
                    {
                        scanf("%d %d %d", &u,&v,&cst);
                        graph[u].pb(mp(v,cst));
                        graph[v].pb(mp(u,cst));
                    }
                int ans = dijkstra(s,t);
                if(ans == -1? pf("Case #%d: unreachable\n",tt) : pf("Case #%d: %d\n",tt,ans));
            }
     return 0;
}