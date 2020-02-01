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
#define mod                     100000007


int dr8[]={-1,-1,0,1,1,1,0,-1};
int dc8[]={0,1,1,1,0,-1,-1,-1};


int n,m,par[200005];

struct ST
{
    int u,v,c;

        bool operator <(const ST &x)const
        {
            return c<x.c;
        }
};
vector <ST> vv;

int find_par(int p)
{
    if(par[p] == p) return p;
    return par[p] = find_par(par[p]);
}

int mst()
{
    int cnt=0,totcost=0;
    loop(i,0,vv.size())
    {
        int uu = vv[i].u;
        int vvv = vv[i].v;
        int cst = vv[i].c;

            int x = find_par(uu);
            int y = find_par(vvv);

                if(x != y)
                {
                    par[x] = y;
                    cnt++;
                    totcost += cst;//cout<<cnt<<" . . " << cst << " " << totcost << endl;
                    if(cnt == n-1) break;
                }
    }
    if(cnt==n-1) return totcost;
}

int main()
{
    ST get;
    int sum=-0;
    while(scanf("%d %d", &n,&m) == 2)
    {
        if(n==0 && m==0) break;

            vv.clear();
            sum=0;


            loop(i,0,m)
            {
                scanf("%d %d %d", &get.u,&get.v,&get.c);
                sum += get.c;
                vv.pb(get);
            }
            sort(vv.begin(),vv.end());
            //loop(i,0,vv.size())cout<<vv[i].u<<" " << vv[i].v<<" " <<vv[i].c<<endl;

            loop(i,0,n+1) par[i] = i;

            int res = mst();//cout<<res<<endl;

            pf("%d\n",sum-res);
    }
    return 0;
}