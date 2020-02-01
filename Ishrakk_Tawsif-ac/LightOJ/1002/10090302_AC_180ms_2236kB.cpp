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
#define intinf                  2e9
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      100005
#define mod                     1000000007

int n,m,dis[503],vis[503];
vector <pair<int,int> > graph[503];

void dikjstra(int sr)
{
    set <pair<int,int> > st;
    vis[sr] = 1;
    dis[sr] = 0;
    st.insert(mp(0,sr));

        while(!st.empty())
        {
            pair <int,int> temp = *st.begin();
            st.erase(st.begin());
            int udis = temp.first;
            int u = temp.second;
//cout<<u<<endl;
                for(int i=0; i<graph[u].size(); i++)
                {
                    int v = graph[u][i].first;
                    int uvdis = graph[u][i].second;
//cout<<u<<" " << v<< " " <<dis[v] << " " << udis << " " << uvdis << endl;
                        if(dis[v]>max(udis,uvdis))
                        {
                            dis[v] = max(udis,uvdis);
                            st.insert(mp(dis[v],v));
                        }
                }
        }
}

int main()
{
    int tc,u,v,c;

        sf(tc);

            loop(tt,1,tc+1)
            {
                scanf("%d %d", &n, &m);


                for(int i=0; i<503; i++)
                {
                        graph[i].clear();
                        dis[i]=intinf;
                }
                    loop(i,0,m)
                    {
                        scanf("%d %d %d", &u, &v, &c);
                        graph[u].pb(mp(v,c));
                        graph[v].pb(mp(u,c));
                    }
                int sr;
                sf(sr);
                dikjstra(sr);
                casepf(tt);
                for(int i=0; i<n; i++)
                {
                     (dis[i] == intinf)?pf("Impossible\n") : pf("%d\n", dis[i]);
                }
            }
    return 0;
}