#include <bits/stdc++.h>
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
#define mod                     1000000007
#define left(n)                 (n<<1)
#define right(n)                ((n<<1) + 1)
#define fast                    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define PI                      acos(-1)
#define ull                     unsigned long long
template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}
string tostring(ll res){string curstr="";while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}


/* ...........................................................................................................*/


vector <pair<int,int> > graph,extra;
vector <int> ans;
int par[1005];

int find_par(int p)
{
    if(par[p] == p) return p;
    else return par[p] = find_par(par[p]);
}

int main()
{
    int n,m,u,v;

    scanf("%d", &n);

    for(int i=1; i<=n; i++) par[i] = i;

    for(int i=0; i<n-1; i++)
    {
        scanf("%d %d", &u,&v);
        graph.pb({u,v});
    }

    for(int i=0; i<graph.size(); i++)
    {
        u = graph[i].first;
        v = graph[i].second;

        int paru = find_par(u);
        int parv = find_par(v);

            if(paru != parv)
            {
                par[paru] = parv;
            }
            else extra.pb({u,v});
    }

    for(int i=1; i<=n; i++)
    {
        if(par[i] == i)
        {
            ans.pb(i);
        }
    }

    if(ans.size() == 1)
    {
        pf("0\n");
        return 0;
    }

    pf("%d\n",ans.size()-1);

    int ind = 0;
    for(int i=0; i<ans.size(); i++)
    {
        if(i>0)
        {
            cout<<extra[ind++].first<<" "<<extra[ind].second<<" "<<ans[i-1]<<" "<<ans[i]<<endl;
        }
    }
    return 0;
}