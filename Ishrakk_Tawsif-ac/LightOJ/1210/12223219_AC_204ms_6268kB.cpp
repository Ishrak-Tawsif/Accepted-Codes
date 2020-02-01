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
#define mx                      20005
#define mod                     1000000007

template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}

string tostring(ll res){string curstr="";while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}

/* ...........................................................................................................*/



///hints ::: first identify all scc from given graph ..... then each scc should have one in degree and one out degree


vector <int> graph[mx],scc[mx];
int dfsclock,disc[mx],low[mx],vis[mx],instack[mx],curscc,sccar[mx],res,cnt,indeg[mx],outdeg[mx];
stack <int> st;

void tarzan(int sr)
{//out(sr);
    ++dfsclock;
    disc[sr] = dfsclock;
    low[sr] = dfsclock;
    st.push(sr);
    instack[sr] = 1;

    for(int i=0; i<graph[sr].size(); i++)
    {
        int v = graph[sr][i];

        if(disc[v] == -1)
        {
            tarzan(v);
            low[sr] = min(low[sr],low[v]);
        }
        else if(instack[v])
        {
            low[sr] = min(low[sr],disc[v]);
        }
    }

    if(low[sr] == disc[sr])
    {
        curscc++;
        while(st.top() != sr)
        {
            int cur = st.top();
            st.pop();
            scc[curscc].pb(cur);
            sccar[cur] = curscc;
            instack[cur] = 0;
        }
        if(st.top() == sr)
        {
            scc[curscc].pb(st.top());
            instack[st.top()] = 0;
            sccar[st.top()] = curscc;
            st.pop();
        }
    }
}

void dfs(int curnode)
{
    vis[curnode] = 1;

    for(int i=0; i<graph[curnode].size(); i++)
    {
        int vv = graph[curnode][i];
        if(sccar[curnode] != sccar[vv])
        {
            outdeg[sccar[curnode]] ++;
            indeg[sccar[vv]] ++;
        }
        if(!vis[vv]) dfs(vv);
    }
}


void clearall()
{
    curscc = 0;
    dfsclock = 0;
    while(!st.empty()) st.pop();
    cnt=0;
    for(int i=0; i<mx; i++)
    {
        graph[i].clear();
        scc[i].clear();
        vis[i] = 0;
        //vis2[i] = 0;
        low[i] = 0;
        outdeg[i] = 0;
        indeg[i] = 0;
        disc[i] = -1;
        instack[i] = 0;
        sccar[i] = 0;
    }
}

int main()
{//WRITE("in.txt");
    int n,e,u,v,tc;

    sf(tc);

    for(int tt=1; tt<=tc; tt++)
    {
        clearall();
        scanf("%d %d", &n,&e);

        for(int i=0; i<e; i++)
        {
            scanf("%d %d", &u,&v);
            graph[u].pb(v);
        }

        mem(disc,-1);
        for(int i=1; i<=n; i++) if(!low[i])tarzan(i);

        res = curscc;

        if(res == 1) {casepf(tt),out(0); continue;}

        for(int i=1; i<=n; i++) if(!vis[i]) dfs(i);

        int in = 0,rout = 0;

        for(int i=1; i<=curscc; i++)
        {
            if(!outdeg[i]) rout ++;
            if(!indeg[i]) in++;
        }//out(koyta);
        casepf(tt);
        out(max(in,rout));
    }
    return 0;
}