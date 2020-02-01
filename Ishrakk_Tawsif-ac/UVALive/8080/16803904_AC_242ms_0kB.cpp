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
#define eps                     .000000001
template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}
string tostring(ll res){if(!res) return "0";string curstr="";while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}


/* ...........................................................................................................*/

vector <int> graph[1005];
vector <int> vv;
int vis[1005];

int dfs(int cur,int k)
{
    vis[cur] = 1;

    if(!graph[cur].size()) return 1;

    if(cur == 1 && graph[cur].size()<k) return 1;

    if(cur!=1 && graph[cur].size()<=k) return 1;

    int koyta;
    vector <int> vv;
    for(int i=0; i<graph[cur].size(); i++)
    {
        int v = graph[cur][i];

        if(vis[v]) continue;

        koyta = 0;

        koyta = dfs(v,k);
        vv.pb(koyta);
    }

    sort all(vv);

    int cnt = 0;
    koyta=0;

    for(int i=vv.size()-1; i>=0; i--)
    {
        koyta += vv[i];
        cnt++;
        if(cnt == k) break;
    }

    return koyta+1;
}

int main()
{
    //READ("in.txt"); WRITE("out.txt");
    int tc,n,k,u,v;

    scanf("%d", &tc);

    for(int tt=1; tt<=tc; tt++)
    {
        scanf("%d %d", &n,&k);

        for(int i=0; i<1005; i++) graph[i].clear();

        mem(vis,0);
        for(int i=1; i<=n-1; i++)
        {
            scanf("%d %d", &u,&v);
            graph[u].pb(v);
            graph[v].pb(u);
        }
        printf("Case %d: %d\n",tt,dfs(1,k));
    }

    return 0;
}