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
#define inf                     1e9
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      9999+3
#define mod                     1000000007

struct ST
{
    int u,v,cost;

    bool operator < (const ST &x)const
    {
        return cost < x.cost;
    }
};

int n,m,par[1000005];
vector <ST> graph;

int find_par(int p)
{
    if(par[p] == p) return p;
    return par[p] = find_par(par[p]);
}

int mst()
{
    int cnt = 0,ans = -inf;

        for(int i=0; i<graph.size(); i++)
        {
            int u = graph[i].u;
            int v = graph[i].v;
            int cost = graph[i].cost;

                int paru = find_par(u);
                int parv = find_par(v);//cout<<paru << " " << parv <<endl;

                    if(paru != parv)
                    {
                        par[paru] = parv;
                        cnt++;//cout<<cost<<endl;
                        ans = max(ans,cost);
                        if(cnt == (n-1)) break;
                    }
        }
    if(cnt == (n-1)) return ans;
    return -1;
}

void reset()
{
    graph.clear();
}

int main()
{//WRITE("in.txt");
    int u,v,c;
    ST get;
    while(scanf("%d %d", &n,&m) == 2)
    {
        if(!n && !m) break;

        reset();

        for(int i=0; i<m; i++)
        {
            scanf("%d %d %d", &u,&v,&c);
            get.u = u;
            get.v = v;
            get.cost = c;
            graph.pb(get);
        }

        sort(graph.begin(),graph.end());

        for(int i=0; i<=n; i++) par[i] = i;
        int res = mst();
        (res == -1)? pf("IMPOSSIBLE\n") : pf("%d\n", res);
    }

    return 0;
}