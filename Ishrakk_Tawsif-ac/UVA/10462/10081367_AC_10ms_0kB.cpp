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
#define mod                     1000000007

int n,m,par[103],tot=0,cnt=0,konta,koto,ans=intinf;;
vector <int>path;

///hints

/*
    At first run an mst and check if it possible to connect all node together if not print no way else
    we will save (during first mst) all edges we need to connect all nodes together and then we will delete
    every edges and run an mst and the minimum value will be answer.If there is no value then print no second path.
*/

struct S
{
    int u,v,c;

        bool operator <(const S & x)const
        {
            return c<x.c;
        }
};
vector <S> best;

int find_par(int p)
{
    if(par[p] == p) return p;
    else return par[p] = find_par(par[p]);
}

int mst(int cur)
{
    tot=0,cnt=0,konta,koto,ans=intinf;

        for(int i=0; i<best.size(); i++)
        {
            if(i == cur) continue;

            int uu = best[i].u;
            int vv = best[i].v;
            int cc = best[i].c;

                int paru = find_par(uu);
                int pary = find_par(vv);

                    if(paru != pary)
                    {
                        par[paru] = pary;//cout<<uu<<" " << vv << endl;
                        cnt++;
                        tot += cc;
                        if(cur == -1)path.pb(i);
                        if(cnt==(n-1)) break;
                    }
        }
        if(cnt == (n-1)) return tot;
        else return -1;
}

int main()
{
    int tc;

        scanf("%d",&tc);
            loop(tt,1,tc+1)
            {
                scanf("%d %d",&n,&m);

                S get;

                    best.clear();
                    path.clear();

                    loop(i,0,m)
                    {
                        scanf("%d %d %d", &get.u, &get.v, &get.c);
                        //graph[get.u][get.v].pb(get.c);
                        //graph[get.v][get.u].pb(get.c);//cout<<graph[5][4].size()<<endl;
                        best.pb(get);
                    }
                    sort(best.begin(),best.end());
                    for(int i=0; i<=n; i++) par[i] = i;

                    int res = mst(-1),sec_path=intinf;

                    if(res == -1)pf("Case #%d : No way\n",tt);
                    else
                    {
                        for(int i=0; i<path.size(); i++)
                        {
                            for(int i=0; i<=n; i++) par[i] = i;
                            int temp_res = mst(path[i]);//cout<<temp_res<<endl;
                            if(temp_res != -1) sec_path = min(sec_path,temp_res);
                        }

                        if(sec_path==intinf)pf("Case #%d : No second way\n",tt);
                        else pf("Case #%d : %d\n",tt,sec_path);
                    }
            }
    return 0;
}