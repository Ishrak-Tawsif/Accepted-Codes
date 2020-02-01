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
#define casepf(nn)              printf ("Case %d: ",nn)
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
#define all(a)                  (a.begin(),a.end())
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      200005
#define mod                     1000000007
#define pi                      acos(-1)
#define eps                     1e-7

template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}

string tostring(ll res){string curstr="";while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}

/* ...........................................................................................................*/

unordered_map <string,int> id;
int par[3*100005],frnd[3*100005];

double calc(double x1,double y1,double x2,double y2)
{
    return sqrt(((x1-x2) * (x1-x2)) + ((y1-y2)*(y1-y2)));
}

struct ST
{
    double dist;
    int i,j;

    bool operator <(const ST & x)const
    {
        return dist<x.dist;
    }
};
vector <ST> graph;
double arx[100005],ary[100005];

int findpar(int p)
{
    if(par[p] == p) return p;
    return par[p] = findpar(par[p]);
}

double mst(int n)
{
    sort all(graph);
    double cst;
    int cnt = 0;

    for(int i=0; i<graph.size(); i++)
    {
        int u = graph[i].i;
        int v = graph[i].j;

        int paru = findpar(u);
        int parv = findpar(v);

        if(paru != parv)
        {
            cnt ++;
            par[paru] = parv;
            cst += graph[i].dist;//cout<<u<<" "<<v<<" "<<graph[i].dist<<endl;
            if(cnt == (n-1)) break;
        }
    }
    return cst;
}

int main()
{
    int n,m,tc;

    //sf(tc);

    while(~scanf("%d", &n))
    {

        graph.clear();

        ST get;

        for(int i=0; i<n; i++)
        {
            cin>> arx[i]>> ary[i];
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i != j)
                {
                    get.dist = calc(arx[i],ary[i],arx[j],ary[j]);
                    get.i = i;
                    get.j = j;
                    graph.pb(get);
                }
            }
        }

        for(int i=0; i<=n; i++) par[i] = i;

        int q,u,v;

        sf(q);

        while(q--)
        {
            scanf("%d %d", &u,&v);
            u--;
            v--;

            int paru = findpar(u);
            int parv = findpar(v);

            par[paru] = parv;
        }

        pf("%.2f\n",mst(n));
    }
    return 0;
}