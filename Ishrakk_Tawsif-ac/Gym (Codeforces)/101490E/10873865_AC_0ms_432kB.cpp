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
#define intinf                  1e9
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      100005
#define mod                     1000000007


int dx[8] = {1,-1,0,0,-1,-1,1,1};
int dy[8] = {0,0,-1,1,-1,1,-1,1};

int dirr[] = {-1,-1,0,0,1,1};
int dirc[] = {0,1,-1,1,-1,0};

int n,m,x,vis[10005];
unordered_map <int,unordered_map<int,ll> > cost;
ll diss[10004],dsss[10005];

vector <int> graph[10005];

struct ST
{
    ll ed,total;
    bool operator <(const ST &x)const
    {
        return ed < x.ed;
    }
};

vector <ST> res[10005];

ll bfs(int sr,int ds)
{
    vis[sr] = 1;
    diss[sr] = 0;
    queue <int> q;
    q.push(sr);

        while(!q.empty())
        {
            int u = q.front(); q.pop();

            if(u == ds) return diss[u];
//cout<<u<<endl;
                for(int i=0; i<graph[u].size(); i++)
                {
                    int v = graph[u][i];

                        if(!vis[v])
                        {
                            vis[v] = 1;
                            diss[v] = diss[u] + cost[u][v];
                            q.push(v);
                        }
                }
        }
     return 0;
}

ll dikjstra(int sr,int desti)
{
    for(int i=0; i<=n; i++) diss[i] = dsss[i] = 1e18;
    ST get;

    set <pair<ll,int> > st;
    vis[sr] = 1;
    diss[sr] = 0;
    dsss[sr] = 0;
    st.insert(mp(0,sr));

        while(!st.empty())
        {
            pair <ll,int> temp = *st.begin();
            st.erase(st.begin());
            ll udis = temp.first;
            int u = temp.second;
//cout<<u<<endl;
                //if(u == desti) {cout<<u<<" "<<diss[u]<<endl;return diss[u];}

                for(int i=0; i<graph[u].size(); i++)
                {
                    int v = graph[u][i];
                    ll uvdis = cost[u][v];
//cout<<u<<" " << v<< " " <<dis[v] << " " << udis << " " << uvdis << endl;
                        if(diss[v]>max(udis,uvdis) || dsss[v]>dsss[u]+uvdis)
                        {
                            dsss[v] = uvdis + dsss[u];
                            diss[v] = max(udis,uvdis);
                            st.insert(mp(diss[v],v));
                            get.ed = diss[v],get.total = dsss[v];
                            res[v].pb(get);
                        }
                }
        }
}


int main()
{
    scanf("%d %d %d", &n,&m,&x);

    int u,v;
    ll c;

    for(int i=0; i<m; i++)
    {
        scanf("%d %d %lld", &u,&v,&c);//cout<<u<<" .. " << v << " " << c << endl;
        graph[u].pb(v);
        graph[v].pb(u);
        cost[u][v] = cost[v][u] = c;
    }

    ll sd = bfs(1,n);
    //cout<<sd<<endl;

    double sd2 = sd * 1.0;
    double x2 = x * 1.0;
    double dd2 = sd2 * (x2/100.0);

    ll validdis = (ll) dd2;
    validdis += sd;

    //cout << validdis << endl;

    dikjstra(1,n);
    sort(res[n].begin(),res[n].end());
    for(int i=0; i<res[n].size(); i++)
    {
        //cout<<res[n][i].total << " " << res[n][i].ed << endl;
        if(res[n][i].total>=sd && res[n][i].total<=validdis)
        {
            pf("%d\n", res[n][i].ed);
            break;
        }
    }
    return 0;
}

/*
9 8 15
1 9 16
1 4 4
4 5 4
5 6 4
6 8 4
4 7 5
7 8 5
8 9 4

9 8 30
1 9 16
1 4 4
4 5 4
5 6 4
6 8 4
4 7 5
7 8 5
8 9 4
*/