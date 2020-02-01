#include<bits/stdc++.h>
using namespace std;

int dirx[8]={0,0,1,-1,1,1,-1,-1};
int diry[8]={1,-1,0,0,1,-1,1,-1};

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
#define mx                      10000007+5
#define mod                     1000000007

struct ST
{
    int u,v;
    ll cost;

    bool operator <(const ST & x)const
    {
        return cost < x.cost;
    }
};

vector <ST> best,worse;

int n,par[1000005],in;
vector <pair<ll,ll> > vv;
vector <ll> ttmm;

int find_par(int p)
{
    if(par[p] == p) return p;
    return par[p] = find_par(par[p]);
}

ll mst()
{
    int cnt = 0;
    ll total = 0;

        for(int i=0; i<best.size(); i++)
        {
            int curu = best[i].u;
            int curv = best[i].v;
            ll cost = best[i].cost;

                int paru = find_par(curu);
                int parv = find_par(curv);

                    if(paru != parv)
                    {
                        par[paru] = parv;
                        total = max(cost,total);
                        cnt++;
                        ttmm.pb(cost);
                        if(cnt == (in-1)) break;
                    }
        }
     if(cnt == (in-1)) return total;
     return 0;
}


int main()
{
    int tc;
    ST get;

    sf(tc);

    for(int tt=1; tt<=tc; tt++)
    {
        sf(n);

        ll u,v;

        worse.clear();
        best.clear();
        vv.clear();
        ttmm.clear();


        while(scanf("%lld", &u) == 1)
        {
            if(u == -1) break;
            scanf("%lld", &v);
            vv.push_back(make_pair(u,v));
        }

        in = vv.size();

        for(int i=0; i<vv.size(); i++)
        {
            double curu = vv[i].first*1.0, curv = vv[i].second*1.0;
            for(int j=i+1; j<vv.size(); j++)
            {
                double tempu = vv[j].first*1.0,tempv = vv[j].second*1.0;

                double dis = sqrt(((curu-tempu)*(curu-tempu)) + ((curv-tempv)*(curv-tempv)));
                get.u = i;
                get.v = j;
                get.cost = (ll) ceil(dis);
                best.pb(get);

            }
        }

        sort(best.begin(),best.end());

        for(int i=0; i<=in; i++) par[i] = i;

        mst();
        pf("%lld\n", ttmm[ttmm.size()-n]);
    }
    return 0;
}