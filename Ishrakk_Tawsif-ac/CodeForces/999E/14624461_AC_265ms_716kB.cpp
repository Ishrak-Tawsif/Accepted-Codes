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
#define mx                      1990005
#define mod                     1000000007
#define left(n)                 (n<<1)
#define right(n)                ((n<<1) + 1)
#define fast                    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define PI                      acos(-1)
#define ull                     unsigned long long
#define eps                     .000000001

template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}
string tostring(ll res){string curstr="";if(!res) curstr += ((char)res + '0');while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}

/* ...........................................................................................................*/

vector <int> graph[5005];
set <int> st;
int vis[5005],vis2[5005],vis3[5005];
vector <pair <int,int> > vv;

void dfs(int cur)
{
    vis[cur] = 1;
    st.erase(cur);

    for(int i=0; i<graph[cur].size(); i++)
    {
        int v = graph[cur][i];
        if(!vis[v]) dfs(v);
    }
}

int dfs2(int cur)
{
    vis2[cur] = 1;

    int cnt = 0;
    for(int i=0; i<graph[cur].size(); i++)
    {
        int v = graph[cur][i];
        if(!vis2[v] && !vis[v]) cnt += dfs2(v) + 1;
    }
    return cnt;
}

void dfs3(int cur)
{
    vis3[cur] = 1;

    for(int i=0; i<graph[cur].size(); i++)
    {
        int v = graph[cur][i];
        if(!vis3[v] && !vis[v]) dfs3(v);
    }
}

int main()
{
    int n,m,s,u,v;

    scanf("%d %d %d", &n,&m,&s);

    for(int i=0; i<m; i++)
    {
        scanf("%d %d", &u,&v);
        graph[u].pb(v);
    }

    for(int i=1; i<=n; i++) st.insert(i);

    dfs(s);
//out(st.size());
    for(auto x : st)
    {
        int cur = dfs2 (x);
        mem(vis2,0);
        vv.pb(mp(cur,x));
    }

    sort all(vv);

    int cnt = 0;
    for(int i = vv.size()-1; i>=0; i--)
    {
        int now = vv[i].second;

        if(!vis3[now] && !vis[now])
        {//out(now);
            cnt ++;
            dfs3(now);
        }
    }
    pf("%d\n", cnt);

    return 0;
}