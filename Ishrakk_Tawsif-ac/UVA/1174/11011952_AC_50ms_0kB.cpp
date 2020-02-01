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
#define mx                      20000005
#define mod                     1000000007


int dx[8]={0,0,1,-1,1,1,-1,-1};
int dy[8]={1,-1,0,0,1,-1,1,-1};

struct ST
{
    int u,v,cost;

        bool operator < (const ST & x) const
        {
            return cost<x.cost;
        }
};

int n,m,par[2005];
unordered_map <string,int> id;
vector <ST> graph;

int find_par(int p)
{
    if(par[p] == p) return p;
    else return find_par(par[p]);
}

int mst()
{
    int cnt = 0,totalcost=0;

    for(int i=0; i<m; i++)
    {
        int uu = graph[i].u;
        int vv = graph[i].v;
        int cst = graph[i].cost;

            int paru = find_par(uu);
            int parv = find_par(vv);

                if(paru != parv)
                {
                    par[paru] = parv;
                    totalcost += cst;
                    cnt ++;
                    if(cnt == (n-1)) break;
                }
    }
    if(cnt == (n-1)) return totalcost;
    return -1;
}

void reset()
{
    graph.clear();
    id.clear();
}

int main()
{//WRITE("in.txt");
    int tc,cs;
    string fs,sn;
    ST get;

    scanf("%d", &tc);

    for(int tt=1; tt<=tc; tt++)
    {
        scanf("%d %d", &n,&m);

        reset();

        int in = 0;
        loop(i,0,m)
        {
            cin>> fs>> sn>> cs;//cout<<fs<<" "<<sn<<endl;
            //scanf("%d", cs);
            if(id[fs] == 0) id[fs] = ++in;
            if(id[sn] == 0) id[sn] = ++in;

            get.u = id[fs];
            get.v = id[sn];
            get.cost = cs;

            graph.pb(get);
        }

        for(int i=1; i<=n; i++) par[i] = i;

        sort(graph.begin(),graph.end());

        int res = mst();

        (tt == tc)? pf("%d\n", res) : pf("%d\n\n", res);
    }

    return 0;
}