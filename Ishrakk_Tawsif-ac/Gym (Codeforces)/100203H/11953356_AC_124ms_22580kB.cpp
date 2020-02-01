#include<bits/stdc++.h>
using namespace std;

int dx[8]={0,0,1,-1,1,1,-1,-1};
int dy[8]={1,-1,0,0,1,-1,1,-1};

/*#pragma comment(linker,"/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
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
#define inf                     2e9
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      5000005
#define mod                     1000000007

template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}

string tostring(ll res){string curstr="";while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}


/* ...........................................................................................................*/

int x[755],y[755],ds[755][755],par[755];

struct ST
{
    int u,v,cost;
    bool operator <(const ST & x)const
    {
        return cost<x.cost;
    }
};

vector <ST> vv;
vector <pair<int,int> > ans;

int calcdis(int x1,int y1,int x2,int y2)
{
    x1 -= x2;
    y1 -= y2;

    return ((x1*x1) + (y1*y1));
}

int find_par(int p)
{
    if(par[p] == p) return p;
    else return par[p] = find_par(par[p]);
}

void mst()
{
    for(int i=0; i<vv.size(); i++)
    {
        int uu = vv[i].u;
        int vvv = vv[i].v;
        int cst = vv[i].cost;

            int paru = find_par(uu);
            int parv = find_par(vvv);

            if(parv != paru)
            {
                par[paru] = parv;
                ans.pb(mp(uu,vvv));
            }
    }
}

int main()
{
    int n;

    sf(n);

    for(int i=1; i<=n; i++) scanf("%d %d", &x[i],&y[i]);

    ST get;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            ds[i][j] = calcdis(x[i],y[i],x[j],y[j]);
            get.u = i;
            get.v = j;
            get.cost = ds[i][j];
            vv.pb(get);
        }
    }

    int u,v,m;
    sf(m);
    for(int i=1; i<=n; i++) par[i] = i;
    for(int i=0; i<m; i++)
    {
        scanf("%d %d", &u,&v);
        int paru = find_par(u);
        int parv = find_par(v);
        par[paru] = parv;
    }

    sort(vv.begin(),vv.end());

    mst();//out(ans.size());//system("pause");
    for(int i=0; i<ans.size(); i++) pf("%d %d\n", ans[i].first,ans[i].second);
    return 0;
}