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

bool instack[mx];
int low[mx],disc[mx],dfsclock,cost[mx],vis[mx];
stack<int>st;
vector<int>graph[mx];
vector<pair<int,int> >ans;

int tarzan(int cur)
{
    low[cur] = disc[cur] = ++dfsclock;
    st.push(cur);
    instack[cur] = 1;
    vis[cur] = 1;

    for(int i=0; i<graph[cur].size(); i++)
    {
        int now = graph[cur][i];

        if(disc[now] == -1)
        {
            tarzan(now);
            low[cur] = min(low[cur],low[now]);
        }
        else if(instack[now]) low[cur] = min(low[cur],disc[now]);
    }

    if(low[cur] == disc[cur])
    {//out(cur);
        vector<int>vv;
        //sccnum ++;
        int mini = 2e9;
        while(st.top() != cur)
        {
            int temp = st.top();
            st.pop();
            instack[temp] = 0;
            //sccar[temp] = sccnum;
            //scc[sccnum].pb(temp);
            vv.pb(cost[temp]);
            mini = min(mini,cost[temp]);
        }

        int temp = st.top();
        instack[temp] = 0;
        vv.pb(cost[temp]);
        mini = min(mini,cost[temp]);
        //sccar[temp] = sccnum;
        //scc[sccnum].pb(temp);
        st.pop();

        int cnt = 0;
        for(int i=0; i<vv.size(); i++) if(vv[i] == mini) cnt++;
        ans.pb({mini,cnt});
    }
}

int main()
{
    int n,m,u,v;

    sf(n);

    for(int i=1; i<=n; i++) sf(cost[i]);

    sf(m);

    for(int i=1; i<=m; i++)
    {
        scanf("%d %d", &u,&v);
        graph[u].pb(v);
    }
    mem(disc,-1);
    for(int i=1; i<=n; i++)
    {
        if(!vis[i])
        {//out(i);
            tarzan(i);
        }
    }

    ll res = 0,cont = 1;
    for(int i=0; i<ans.size(); i++)
    {
        res += (ll)ans[i].first;
        cont = ((cont%mod) * ((ll)ans[i].second%mod))%mod;
    }
    pf("%lld %lld\n", res,cont%mod);
    return 0;
}