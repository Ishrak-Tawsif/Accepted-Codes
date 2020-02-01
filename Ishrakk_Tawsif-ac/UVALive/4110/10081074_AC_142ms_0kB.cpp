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


int n,m,par[10005];

struct S
{
    int u,v,c;

        bool operator <(const S &x) const
        {
            return c>x.c;
        }
};
vector <S> best;

int find_par(int p)
{
    if(par[p] == p) return p;
    else return par[p] = find_par(par[p]);
}

int mst()
{
    int tot=0,cnt=0;

        for(int i=0; i<best.size(); i++)
        {
            int uu = best[i].u;
            int vv = best[i].v;
            int cc = best[i].c;

                int paru = find_par(uu);
                int parv = find_par(vv);
//cout<<paru<<" " << parv << endl;
                    if(paru != parv)
                    {
                        par[paru] = parv;
                        tot += cc;
                        cnt++;
                        //if(cnt == (n-1)) break;
                    }
        }//cout<<tot<<endl;
    if(cnt == (n-1)) return tot;
}

int main()
{
    int tc,sum;
    S get;

        //while(sf(tc) == 1 && tc)
        //{

        sf(tc);
            loop(tt,1,tc+1)
            {
                scanf("%d %d",&n,&m);
                sum = 0;
                best.clear();

                    loop(i,0,m)
                    {
                        scanf("%d %d %d",&get.u,&get.v,&get.c);
                        best.pb(get);
                        sum += get.c;
                    }
                    sort(best.begin(),best.end());
                    for(int i=1; i<=n; i++) par[i] = i;
                    int res = mst();

                    pf("%d\n",sum-res);
            }
            int garbage;
            sf(garbage);
        //}
    return 0;
}