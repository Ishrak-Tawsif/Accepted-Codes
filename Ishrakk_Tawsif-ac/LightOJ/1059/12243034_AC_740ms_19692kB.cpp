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
     
    struct ST
    {
        int u,v,cs,t;
        bool operator <(const ST & x)const
        {
            return cs<x.cs;
        }
    };
     
    vector <ST> graph;
    int n,m,air,totairport,par[mx];
    map <int,map<int,int> > cost,type;
     
    void setall()
    {
        for(int i=0; i<graph.size(); i++)
        {
            int u = graph[i].u;
            int v = graph[i].v;
            graph[i].cs = cost[u][v];
            graph[i].t = type[u][v];
        }
    }
     
    int findpar(int p)
    {
        if(par[p] == p) return p;
        else return par[p] = findpar(par[p]);
    }
     
    int mst()
    {
        for(int i=1; i<=n; i++) par[i] = i;
        sort(graph.begin(),graph.end());
     
        int tot = 0,cnt = 0;
        for(int i=0; i<graph.size(); i++)
        {
            int u = graph[i].u;
            int v = graph[i].v;
            int t = graph[i].t;
     
            int paru = findpar(u);
            int parv = findpar(v);
     
            if(paru != parv)
            {
                par[paru] = parv;
                tot += graph[i].cs;
                cnt ++;
                if(graph[i].cs == air) totairport ++;
                if(cnt == (n-1)) break;
            }
        }
        return tot;
    }
     
    void clearall()
    {
        graph.clear();
        cost.clear();
        type.clear();
    }
     
    int main()
    {//WRITE("in.txt");
        int tc;
     
        sf(tc);
     
        ST get;
        for(int tt=1; tt<=tc; tt++)
        {
            clearall();
            scanf("%d %d %d", &n,&m,&air);
            for(int i=0; i<m; i++)
            {
                scanf("%d %d %d", &get.u,&get.v,&get.cs);
                if(!cost[get.u][get.v])
                {
                    cost[get.u][get.v] = min(air,get.cs);
                    cost[get.v][get.u] = min(air,get.cs);
                    graph.pb(get);
                }
                else
                {
                    cost[get.u][get.v] = min(get.cs,cost[get.u][get.v]);
                    cost[get.v][get.u] = min(get.cs,cost[get.v][get.u]);
                }
            }
            setall();
     
            totairport = 0;
     
            int res = mst();
            for(int i=1; i<=n; i++)
            {
                if(par[i] == i) totairport ++,res+=air;
            }
     
            casepf(tt);
            pf("%d %d\n", res,totairport);
        }
        return 0;
    }
     
    /*
    3
    3 3 10
    1 2 20
    2 3 30
    3 1 40
    */