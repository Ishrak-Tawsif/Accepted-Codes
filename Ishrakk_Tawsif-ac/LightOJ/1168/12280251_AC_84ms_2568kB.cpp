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
#define mx                      10005
#define mod                     1000000007

template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}

string tostring(ll res){string curstr="";while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}

/* ...........................................................................................................*/

int n,m,node,vis[mx],instack[mx],low[mx],disc[mx],sccar[mx],dfsclock,sccnum,visscc[mx],outdeg[mx];
vector <int> nd,graph[mx],scc[mx];
stack <int> st;

void clearall()
{
    nd.clear();
    dfsclock = sccnum = 0;
    while(!st.empty()) st.pop();

    for(int i=0; i<mx; i++)
    {
        vis[i] = 0;
        graph[i].clear();
        scc[i].clear();
        instack[i] = 0;
        low[i] = 0;
        disc[i] = -1;
        sccar[i] = 0;
        outdeg[i] = 0;
        visscc[i] = 0;
    }
}

void tarzan(int cur)
{
    low[cur] = disc[cur] = ++dfsclock;
    st.push(cur);
    instack[cur] = 1;

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
    {
        sccnum ++;
        while(st.top() != cur)
        {
            int temp = st.top();
            st.pop();
            instack[temp] = 0;
            sccar[temp] = sccnum;
            scc[sccnum].pb(temp);
        }
        
        int temp = st.top();
        instack[temp] = 0;
        sccar[temp] = sccnum;
        scc[sccnum].pb(temp);
        st.pop();
    }
}

void dfs(int cur)
{
    vis[cur] = 1;
    visscc[sccar[cur]] = 1;

    for(int i=0; i<graph[cur].size(); i++)
    {
        int vv = graph[cur][i];
        if(sccar[cur] != sccar[vv])
        {
            //indeg[sccar[vv]] ++;
            outdeg[sccar[cur]] ++;
        }
        if(!vis[vv]) dfs(vv);
    }
}

int main()
{//WRITE("in.txt");
    int tc,u,v,fl;

    sf(tc);

    for(int tt=1; tt<=tc; tt++)
    {
        scanf("%d", &n);
        node = 0;
        int edg = 0;
        fl = 1;

        clearall();
        node = 1;
        nd.pb(0);
        vis[0] = 1;

        for(int i=0; i<n; i++)
        {
            int k;
            sf(k);
            while(k--)
            {
                scanf("%d %d", &u,&v);
                if(!vis[u]) node++,vis[u]=1,nd.pb(u);
                if(!vis[v]) node++,vis[v]=1,nd.pb(v);
                graph[u].pb(v);
                edg++;
            }
        }

        mem(vis,0);
        for(int i=0; i<nd.size(); i++)
        {
            int vv = nd[i];
            if(disc[vv] == -1)
            {//out(vv);
                tarzan(vv);
            }
        }

        dfs(0);

        int fl = 1;
        for(int i=1; i<=sccnum; i++) if(!visscc[i]) fl = 0;
        if(fl)
        {
            for(int i=1; i<=sccnum; i++)
            {
                if(outdeg[i]>1) fl = 0;
            }
        }
        casepf(tt);fl? pf("YES\n") : pf("NO\n");
    }

    return 0;
}