#include<bits/stdc++.h>
using namespace std;

#define sf(nn)                  scanf ("%d", &nn)
#define sfll(nn)                scanf ("%lld", &nn)
#define pf                      printf
#define casepf(nn)              printf ("Case %d\n",nn)
#define out(nn)                 cout <<nn <<endl
#define loop(var,start,till)    for(int var=start; var<till; var++)
#define pb                      push_back
#define mem(a,b)                memset(a,b,sizeof(a))
#define mp                      make_pair
#define ll                      long long int
#define inf                     1e9
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      10000+5
#define mod                     1000000007


int dx[8]={0,0,1,-1,1,1,-1,-1};
int dy[8]={1,-1,0,0,1,-1,1,-1};

ll taka[mx],totalcost[2][mx],vis[2][mx];
int n,m,p,s,t;
vector <pair<ll,int> > graph[2][mx];

ll dikjstra(int type,int ss)
{
    set <pair<ll,int> > st;
    st.insert(mp(0,ss));
    totalcost[type][ss] = 0;

        while(!st.empty())
        {
            pair <ll,int> temp = *st.begin();
            st.erase(st.begin());

            ll cst = temp.first;
            int u = temp.second;
//cout<<u<<" ..m "<< cst <<endl;
                for(int i=0; i<graph[type][u].size(); i++)
                {
                    int vv = graph[type][u][i].second;
                    int uvcost = graph[type][u][i].first;

                    if(totalcost[type][vv]>cst+uvcost)
                    {
                        vis[type][vv] = 1;
                        totalcost[type][vv] = cst + uvcost;
                        st.insert(mp(totalcost[type][vv],vv));
                    }
                }
        }
}

int main()
{//WRITE("in.txt");
    int tc,u,v,w;

    sf(tc);

    for(int tt=1; tt<=tc; tt++)
    {
        for(int i=0; i<mx; i++)
            graph[0][i].clear(),graph[1][i].clear(),totalcost[0][i]=totalcost[1][i]=inf,vis[0][i]=vis[1][i]=0;

        scanf("%d %d %d %d %d", &n,&m,&s,&t,&p);

        //mem(vis,0);
        for(int i=0; i<m; i++)
        {
            scanf("%d %d %d", &u,&v,&w);
            graph[0][u].pb(mp(w,v));
            graph[1][v].pb(mp(w,u));
        }

        dikjstra(0,s);
        dikjstra(1,t);

        ll ans = -1;
        for(int i=1; i<=n; i++)
        {
            for(int j=0; j<graph[0][i].size(); j++)
            {
                int v = graph[0][i][j].second;
                ll curcost = totalcost[0][i] + totalcost[1][v] + graph[0][i][j].first;
                //cout<<i<<" "<<graph[0][i][j].second << " " << graph[0][i][j].first<<" "<<curcost<<endl;
                if(curcost<=p) ans = max(ans,graph[0][i][j].first);
            }
        }

        pf("Case %d: %lld\n", tt,ans);
    }
    return 0;
}