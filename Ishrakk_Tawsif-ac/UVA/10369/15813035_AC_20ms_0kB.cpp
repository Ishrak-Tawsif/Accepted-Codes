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
#define mx                      100005
#define mod                     998244353
#define left(n)                 (n<<1)
#define right(n)                ((n<<1) + 1)
#define fast                    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define PI                      acos(-1)
#define bitOff(N,in)            (N&(~(1LL<<(in))))
#define bitOn(N,in)             (N|(1LL<<(in)))
#define ull                     unsigned long long
#define eps                     .000000001

template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}
string tostring(ll res){string curstr="";if(!res) curstr += ((char)res + '0');while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}

/* ...........................................................................................................*/

double x[503],y[503],r,railroads,roads;
int s,n,par[1005],mark[503];
vector <int> graph[503];

struct st
{
  int u,v;
  double cst;

    bool operator <(const st & x) const
    {
        return cst < x.cst;
    }

};
vector <st> vv,store;

double calc(double x,double y,double xx,double yy)
{
    x -= xx;
    y -= yy;

    return sqrt((x*x) + (y*y));
}

int find_par(int p)
{
    if(par[p] == p) return par[p];
    else return par[p] = find_par(par[p]);
}

double mst()
{
    store.clear();
    sort all(vv);
    for(int i=0; i<n; i++) par[i] = i;

    int cnt = 0,compo = 0;

    for(int i=0; i<vv.size(); i++)
    {
        int u = vv[i].u;
        int v = vv[i].v;
        double cst = vv[i].cst;

        int paru = find_par(u);
        int parv = find_par(v);

        if(paru != parv)
        {
            par[paru] = parv;
            //graph[u].pb(v);
            //graph[v].pb(u);
            store.pb(vv[i]);
//cout<<u<<" "<<v<<" "<<cst<<endl;
            cnt++;
        }
        if(cnt == (n-1)) break;
    }
    return compo + 1;
}

int main()
{//READ("in.txt"); WRITE("out.txt");
    int tc;

    sf(tc);

    for(int tt=1; tt<=tc; tt++)
    {
        sf(s);
        cin>> n;

        for(int i=0; i<n; i++)
        {
            cin>> x[i]>> y[i];
        }

        st get;
        vv.clear();
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                //cout<<i<<" "<<j<<" "<<calc(x[i],y[i],x[j],y[j])<<endl;
                double now = calc(x[i],y[i],x[j],y[j]);

                get.u = i;
                get.v = j;
                get.cst = now;
                vv.pb(get);
            }
        }

        mst();

        mem(mark,0);
        sort all(store);

        double res = store[n-s-1].cst;

        pf("%.2f\n", res);
    }

    return 0;
}