#include <bits/stdc++.h>
#include <ext/rope>

using namespace __gnu_cxx;
using namespace std;

int dx[8]={0,0,1,-1,1,1,-1,-1};
int dy[8]={1,-1,0,0,1,-1,1,-1};

/*#pragma comment(linker,"/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
#define sf(nn)                  scanf ("%d", &nn)
#define sfll(nn)                scanf ("%lld", &nn)
#define pf                      printf
#define casepf(nn)              printf ("Case %d: ",nn)
#define out(nn)                 cout <<nn <<endl
#define loop(var,start,till)    for(int var=start; var<till; var++)
#define loop1(var,start,till)   for(int var=start; var<=till; var++)
#define pb                      push_back
#define mem(a,b)                memset(a,b,sizeof(a))
#define mp                      make_pair
#define ll                      long long int
#define inf                     2e9
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define all(a)                  (a.begin(),a.end())
#define Unique_(a)              sort(all(a));a.erase(unique(all(a)),a.end())
#define mod                     998244353
#define left(n)                 (n<<1)
#define right(n)                ((n<<1) + 1)
#define fast                    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define PI                      acos(-1)
#define bitOff(N,in)            (N&(~(1LL<<(in))))
#define bitOn(N,in)             (N|(1LL<<(in)))
#define ull                     unsigned long long
#define eps                     .000000001
#define mx                      1000005

template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}
string tostring(ll res){string curstr="";if(!res) curstr += ((char)res + '0');while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}


/* ...........................................................................................................*/

int n,r,q,mstpar[mx],par[mx],level[mx];
pair <int,int> sparse[mx][17];
vector <pair <int,int> > tree[mx];
unordered_map <int,unordered_map<int,int> > edge;

struct lca
{
    void dfs(int cur,int curpar,int lev,int val)
    {
        par[cur] = curpar;
        level[cur] = lev;
        sparse[cur][0].second = val;

        for(int i=0; i<tree[cur].size(); i++)
        {
            int vv = tree[cur][i].first;

            if(vv == curpar) continue;

            dfs(vv,cur,lev + 1,tree[cur][i].second);
        }
    }

    void build()
    {
        dfs(1,-1,1,0);

        for(int j=1; (1<<j) <= n; j++)
        {
            for(int i=1; i<=n; i++)
            {
                sparse[i][j].first = -1;
                sparse[i][j].second = -1;
            }
        }
        for(int i=0; i<=n; i++) sparse[i][0].first = par[i];

        for(int j=1; (1<<j)<=n; j++)
        {
            for(int i=1; i<=n; i++)
            {
                sparse[i][j].first = sparse[sparse[i][j-1].first][j-1].first;
                sparse[i][j].second = max(sparse[i][j-1].second,sparse[sparse[i][j-1].first][j-1].second);
            }
        }
    }

    int query(int p,int q)
    {
        int log,ans=-1;
        if(level[p] < level[q]) swap(p,q);

        for(log=0; (1 << log) <= level[p]; log++);
        log--;

        for(int i=log; i>=0; i--)
        {
            if(level[p]-(1 << i)>=level[q])
            {
                ans = max(ans,sparse[p][i].second);
                p = sparse[p][i].first;
            }
        }
        if(p == q) return ans;

        for(int i=log; i>=0; i--)
        {
            if(sparse[p][i].first != -1 && sparse[p][i].first != sparse[q][i].first)
            {
                ans = max(ans,max(sparse[p][i].second,sparse[q][i].second));
                p = sparse[p][i].first;
                q = sparse[q][i].first;
            }
        }
        ans = max(ans,max(sparse[p][0].second,sparse[q][0].second));
        return ans;
    }
};


struct st
{
    int u,v,cst;

    bool operator <(const st & x) const
    {
        return cst < x.cst;
    }
};
vector <st> vv;

int findpar(int p)
{
    if(mstpar[p] == p) return p;
    else return mstpar[p] = findpar(mstpar[p]);
}

int mst()
{
    sort all(vv);
    for(int i=1; i<=n; i++) mstpar[i] = i;
    int cnt = 0,tot = 0;

    for(int i=0; i<vv.size(); i++)
    {
        int u = vv[i].u;
        int v = vv[i].v;
        int curcst = vv[i].cst;

        int paru = findpar(u);
        int parv = findpar(v);

        if(paru != parv)
        {
            mstpar[paru] = parv;
            tree[u].pb(mp(v,curcst));
            tree[v].pb(mp(u,curcst));
            tot += curcst;
            if(++cnt == n-1) return tot;
        }
    }
}

int main()
{
    scanf("%d %d", &n,&r);

    st get;
    for(int i=0; i<r; i++)
    {
        scanf("%d %d %d", &get.u,&get.v,&get.cst);
        edge[get.u][get.v] = get.cst;
        edge[get.v][get.u] = get.cst;
        vv.pb(get);
    }

    int mstcst = mst();//out(mstcst);
    lca LCA;

    LCA.build();

    sf(q);

    int u,v;
    for(int i=0; i<q; i++)
    {
        scanf("%d %d", &u,&v);
        int lcauv = LCA.query(u,v);
        if(lcauv == edge[u][v]) printf("%d\n", mstcst);
        else
        {
            int nowcst = mstcst - lcauv + edge[u][v];
            printf("%d\n", nowcst);
        }
    }

    return 0;
    
}