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
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      5000005
#define mod                     100000007

template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}

string tostring(ll res){string curstr="";while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}

/* ...........................................................................................................*/


int n,dfsclock,vis[10005],disc[10005],low[10005],par[10005],vis2[10005];
ll totcost[10005],cost[10005];
vector <pair<int,ll> >graph[10005],tree[10005];
//vector <pair<int,pair<int,int> > > bridge;

struct ST
{
    int u,v;
    ll l,city;
};
vector <ST> bridge;

ll findbridge(int cur,int curpar,int dep)
{//out(cur);
    vis[cur] = 1;
    disc[cur] = low[cur] = dep;
    low[cur] = 2e18;
    ll totsz = 1;
    for(int i=0; i<graph[cur].size(); i++)
    {
        int v = graph[cur][i].first;

        if(v == curpar) continue;

        if(!vis[v])
        {
            par[v] = cur;
            ll now = findbridge(v,cur,dep+1); ///v theke jegulate jaowa jabe
            totsz += now;

            if(low[v] > dep)
            {
                ST get;
                get.u = cur;
                get.v = v;
                get.l = graph[cur][i].second;
                get.city = now;
                bridge.pb(get);
            }
            low[cur] = min(low[cur],low[v]);
        }
        else  low[cur] = min(low[cur],disc[v]);
    }
    return totsz;
}

int dfs(int cur,int par,ll val,ll ncost)
{//out(cur);
    vis2[cur] = 1;
    int fl = 1;
    for(int i=0; i<tree[cur].size(); i++)
    {
        int now = tree[cur][i].first;
        ll nowcst = tree[cur][i].second;//out(nowcst);

        if(!vis2[now])
        {
            if(!dfs(now,cur,val,nowcst)) return 0;
        }
    }
    if(totcost[cur] + ncost<=val) totcost[cur] += ncost;
    else totcost[par] += ncost;
    if(totcost[par]>val) fl=0;

    return fl;
}

bool check(ll val)
{//out(val);
    mem(vis2,0);
    
    for(int i=1; i<=n; i++) totcost[i] = cost[i];
    int pos = 1;
    for(int i=1; i<=n; i++)
    {
        if(!vis2[i])
        {
            pos &= dfs(i,0,val,0);
        }
    }
    return pos;
}

void clearll()
{
    for(int i=0; i<10005; i++)
    {
        graph[i].clear();
        vis[i] = 0;
        tree[i].clear();
    }
}

int main()
{//WRITE("in.txt");
    int tc,m,u,v;
    ll l;
    ll sum,mn=-2e18;

    sf(tc);

    for(int tt=1; tt<=tc; tt++)
    {
        scanf("%d %d", &n,&m);

        sum = 0;
        mn=-2e18;
        clearll();

        for(int i=1; i<=n; i++) scanf("%lld", &cost[i]),sum+=cost[i],mn=max(mn,cost[i]);

        for(int i=0; i<m; i++)
        {
            scanf("%d %d %lld", &u,&v,&l);//out(l);
            graph[u].pb(mp(v,l));
            graph[v].pb(mp(u,l));
        }


        ///making graph from list of bridges
        for(int i=1; i<=n; i++)
        {
            if(vis[i]) continue;
            bridge.clear();
            dfsclock = 0;
            int totnode = findbridge(i,-1,0);
            //cout<<bridge.size()<<endl;system("pause");
            for(int i=0; i<bridge.size(); i++)
            {
                u = bridge[i].u;
                v = bridge[i].v;
                l = bridge[i].l ;
                ll city = bridge[i].city * (totnode-bridge[i].city);

                tree[u].pb(mp(v,l*city));
                tree[v].pb(mp(u,l*city));
                sum += (l*city);
                //cout<<u<<" // "<<v<<" "<<l*city<<endl;
            }
        }

        ///binary search on answer
        ll st = mn,en = sum,res = -1,mid;//cout<<st<<" : " << en<<endl;
//out(check(80));system("pause");
        while(st<=en)
        {//out(mid);

            mid = (st+en)>> 1;//out(mid);
            if(check(mid)) res=mid,en = mid-1 ;
            else  st = mid+1; //cout<<mid<<" "<<st<<" .. "<<en<<endl;
        }
        casepf(tt);
        pf("%lld\n",res);
    }
    
    return 0;
}

/*
666

7 3
6 2 7 4 1 8 7
5 1 5
5 2 1
3 6 3

7 13
6 4 1 3 2 8 10
5 3 4
7 2 10
4 5 9
2 3 5
6 7 8
3 4 5
1 2 1
6 5 2
7 1 10
1 5 1
4 1 6
6 1 2
2 5 7

7 15
9 4 6 7 2 3 3
6 3 10
4 1 7
4 5 5
6 5 1
4 2 6
1 6 4
4 7 2
3 5 1
2 3 4
2 6 2
3 4 7
2 5 9
7 1 2
5 7 10
7 3 6
*/