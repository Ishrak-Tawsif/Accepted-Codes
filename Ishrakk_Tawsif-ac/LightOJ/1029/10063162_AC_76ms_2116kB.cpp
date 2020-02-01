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

int cost [101][101],par[101],n;
vector <int> vv;

struct S1
{
    int u,v,c;

        bool operator <(const S1 &x)const
        {
            return c<x.c;
        }
};
vector <S1> best;

/*struct S2
{
    int u,v,c;

        bool operator <(const S2 &x)const
        {
            return c>x.c;
        }
};
vector <S2> worse;)*/

int find_par(int p)
{
    if(par[p] == p) return p;
    else find_par(par[p]);
}

int mst_best()
{
    int cnt=0,tot=0;

        for(int i=0; i<best.size(); i++)
        {
            int uu = best[i].u;
            int vv = best[i].v;
            int cst = best[i].c;

                int paru = find_par(uu);
                int parv = find_par(vv);

                    if(paru != parv)
                    {
                        par[paru] = par[vv];
                        cnt++;
                        tot += cst;
                        if(cnt == (n)) break;
                    }
        }//cout<<tot<<endl;
        if(cnt == n)return tot;
}

int mst_worse()
{
    int cnt=0,tot=0;

        for(int i=best.size()-1; i>=0; i--)
        {
            int uu = best[i].u;
            int vv = best[i].v;
            int cc = best[i].c;

                int paru = find_par(uu);
                int parv = find_par(vv);

                    if(paru != parv)
                    {
                        par[paru] = parv;
                        cnt++;
                        tot+=cc;
                        if(cnt==n) break;
                    }
        }//cout<<tot<<endl;
        if(cnt == n) return tot;
}

int main()
{
    int tc,u,v,c;

        sf(tc);

        loop(tt,1,tc+1){

            sf(n);
            S1 get1;
            //S2 get2;
            best.clear();
            while(scanf("%d %d %d",&get1.u,&get1.v,&get1.c))
            {
                if(get1.u==0 && get1.v==0 && get1.c==0) break;

                /*get2.u = get1.u;
                get2.v = get1.v;
                get2.c = get1.c;*/

                /*if(c>cost[u][v])
                {
                    cost[u][v] = c;
                    cost[v][u] = c;
                }*/
                best.pb(get1);
                //worse.pb(get2);
            }
            sort(best.begin(),best.end());
            //sort(worse.begin(),worse.end());

            for(int i=0; i<=n; i++) par[i]=i;
            int bst = mst_best();
            for(int i=0; i<=n; i++) par[i]=i;
            int wst = mst_worse();

            int total = bst + wst;

            (total%2 == 0)? pf("Case %d: %d\n",tt,total/2) : pf("Case %d: %d/2\n",tt,total);
        }

    return 0;
}