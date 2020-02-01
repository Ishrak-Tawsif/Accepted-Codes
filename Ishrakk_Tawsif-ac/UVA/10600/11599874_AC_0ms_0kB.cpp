#include<bits/stdc++.h>
using namespace std;

int dx[8]={0,0,1,-1,1,1,-1,-1};
int dy[8]={1,-1,0,0,1,-1,1,-1};

#define sf(nn)                  scanf ("%d", &nn)
#define sfll(nn)                scanf ("%lld", &nn)
#define pf                      printf
#define casepf(nn)              printf ("Case #%d: ",nn)
#define out(nn)                 cout <<nn <<endl
#define loop(var,start,till)    for(int var=start; var<till; var++)
#define pb                      push_back
#define mem(a,b)                memset(a,b,sizeof(a))
#define mp                      make_pair
#define ll                      long long int
#define inf                     2e9
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      20000005
#define mod                     1000000007

int n,m,par[105],cost[105][105];

struct ST
{
    int u,v,c;
    bool operator <(const ST & x)const
    {
        return c<x.c;
    }
};
vector <ST> tempvv,vv;

int find_par(int p)
{
    if(par[p] == p) return p;
    else return par[p] = find_par(par[p]);
}

int mst(int nn)
{
    int cnt = 0,tot = 0;
    ST get;

        for(int i=0; i<vv.size(); i++)
        {
            int uu = vv[i].u;
            int vvv = vv[i].v;
            int cc = vv[i].c;
            get.u = uu,get.v = vvv,get.c = cc;
            //if(i == nn) continue;

                int paru = find_par(uu);
                int parv = find_par(vvv);

                if(paru != parv)
                {
                    par[paru] = parv;
                    cnt++;
                    tot += cc;
                    tempvv.pb(get);
                    if(cnt == (n-1)) break;
                }
        }
    return tot;
}

int mstsecond(int curu,int curv)
{
    int cnt = 0,tot = 0;
    ST get;

        for(int i=0; i<vv.size(); i++)
        {
            int uu = vv[i].u;
            int vvv = vv[i].v;
            int cc = vv[i].c;
            if(uu == curu && vvv == curv) continue;

                int paru = find_par(uu);
                int parv = find_par(vvv);

                if(paru != parv)
                {
                    par[paru] = parv;
                    cnt++;
                    tot += cc;
                    if(cnt == (n-1)) break;
                }
        }
    if(cnt == (n-1))return tot;
    return inf;
}

int main()
{//WRITE("in.txt");
    int tc;
    ST get;

    sf(tc);

    for(int tt=1; tt<=tc; tt++)
    {
        scanf("%d %d", &n,&m);

        vv.clear();
        tempvv.clear();
        mem(cost,-1);

        for(int i=0; i<m; i++)
        {
            scanf("%d %d %d", &get.u, &get.v, &get.c);
            vv.pb(get);
        }

        sort(vv.begin(),vv.end());
        for(int i=1; i<=n; i++) par[i] = i;
        int cost1 = mst(-1);

        int cost2 = inf,fl=0;

        for(int i=0; i<tempvv.size(); i++)
        {
            for(int i=1; i<=n; i++) par[i] = i;
            int cur = mstsecond(tempvv[i].u,tempvv[i].v);
            cost2 = min(cost2,cur);
        }

        if(cost2 != inf)pf("%d %d\n", cost1,cost2);
        else pf("%d %d\n", cost1,cost1);//out("...\n");
    }

    return 0;
}

/*
66

9  14
1  2  4
1  8  8
2  8  11
3  2  8
8  9  7
8  7  1
7  9  6
9  3  2
3  4  7
3  6  4
7  6  2
4  6  14
4  5  9
5  6  10
*/