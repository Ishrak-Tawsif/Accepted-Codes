#include<bits/stdc++.h>
using namespace std;

int dirx[8]={0,0,1,-1,1,1,-1,-1};
int diry[8]={1,-1,0,0,1,-1,1,-1};

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
#define mx                      10000007+5
#define mod                     1000000007

int node,edge,query,vis[105],diss[105];

struct ST
{
    int u,cost;

    bool operator <(const ST & x) const
    {
        return cost < x.cost;
    }
};

vector <ST> graph[105];
//ST get;


int dikjstra(int sr,int ds)
{
    //mem(vis,0);
    for(int i=0; i<105; i++) vis[i] = 0,diss[i] = inf;
    set < pair<int,int> > ss;
    ss.insert(mp(0,sr));
    vis[sr] = 1;
    diss[sr] = 0;

        while(!ss.empty())
        {
            pair<int,int> temp = * ss.begin();
            ss.erase(ss.begin());

                int u = temp.second,udis;
                /*if(vis[u]) udis = diss[u];
                else*/ udis = temp.first;

                    //if(u == ds) return diss[ds];
//cout<<u<<endl;
                    //sort(graph[u].begin(),graph[u].end());
                    for(int i=0; i<graph[u].size(); i++)
                    {
                        int v = graph[u][i].u;
                        int uvdis = graph[u][i].cost;
 //cout<<u<<" " << v <<" "<< udis << " " << uvdis << " " << diss[u] << " " << diss[7] << endl;
                            if(diss[v]>(max(uvdis,udis)))
                            {
                                diss[v] = max(uvdis,udis);//if(u == 6 && v == 7) out(diss[v]);
                                vis[v] = 1;
                                ss.insert(mp(diss[v],v));
                            }
                            /*if(vis[v])
                            {
                                if(diss[v]>(max(uvdis,udis))) diss[v] = max(uvdis,udis);
                                //ss.insert(mp(diss[v],v));
                            }*/
                    }
        }
    return diss[ds];
}

int main()
{//WRITE("in.txt");
    int tt=0;
    while(scanf("%d %d %d", &node,&edge,&query))
    {
        if(!node && !edge && !query) break;

        for(int i=0; i<105; i++)graph[i].clear();

        int u,v,c;
        ST get;

        for(int i=0; i<edge; i++)
        {
            scanf("%d %d %d", &u,&v,&c);
            get.u = v;
            //get.v = v;
            get.cost = c;
            graph[u].pb(get);
            get.u = u;
            graph[v].pb(get);
        }

        if(tt)pf("\n");
        casepf(++tt);

        while(query --)
        {
            int st,ds,res;

            scanf("%d %d", &st,&ds);

            res = dikjstra(st,ds);
            (res == inf)? pf("no path\n") : pf("%d\n", res);
        }
    }
    return 0;
}