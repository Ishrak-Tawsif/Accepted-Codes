 #include<bits/stdc++.h>
using namespace std;

#define sf(nn)                  scanf ("%d", &nn)
#define sfll(nn)                scanf ("%lld", &nn)
#define pf                      printf
#define casepf(nn)              printf ("Case #%d\n",nn)
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
#define mx                      1000+5
#define mod                     1000000007

int n,m,par[mx],mark[25005];

struct ST
{
    int u,v,w;
    bool operator <(const ST & x)const
    {
        return w<x.w;
    }
};
vector <ST>graph;
vector <int> res;

int find_par(int p)
{
    if(par[p] == p) return p;
    return par[p] = find_par(par[p]);
}

void mst()
{
    int cnt = 0;

        for(int i=0; i<graph.size(); i++)
        {
            int uu = graph[i].u;
            int vv = graph[i].v;
            int ww = graph[i].w;

                int paru = find_par(uu);
                int parv = find_par(vv);

                if(paru != parv)
                {
                    mark[i] = 1;
                    par[paru] = parv;
                    cnt++;
                    if(cnt == (n-1)) break;
                }
        }
}

int main()
{
    ST get;
    while(scanf("%d %d", &n,&m) == 2 &&n && m)
    {
        graph.clear();

        for(int i=0; i<m; i++)
        {
            scanf("%d %d %d", &get.u,&get.v,&get.w);
            graph.pb(get);
        }

        mem(mark,0);
        for(int i=0; i<n; i++) par[i] = i;
        sort(graph.begin(),graph.end());
        res.clear();
        mst();

        for(int i=0; i<m; i++) if(!mark[i]) res.pb(graph[i].w);
        sort(res.begin(),res.end());

        if(!res.size()) pf("forest\n");
        else
        {
            pf("%d",res[0]);
            for(int i=1; i<res.size(); i++) pf(" %d", res[i]);
            pf("\n");
        }
    }

    return 0;
}