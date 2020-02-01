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
#define mx                      1000005
#define mod                     1000000009
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

int n,m,val[103],vis[103];
vector <int> graph[103];

pair <int,int> bfs()
{
    vis[0] = 1;
    set <pair<int,int> > st;
    st.insert(mp(0,0));
    int res = -2e9,resnode;

    while(!st.empty())
    {
        pair<int,int> temp = *st.begin();
        st.erase(st.begin());

        int cur = temp.second;
        int cost = temp.first;

        int maxi = -2e9,v,vv=-1;

        if(graph[cur].size() == 0)
        {
            if(cost>res) res = cost,resnode = cur;
        }

        for(int i=0; i<graph[cur].size(); i++)
        {
            v = graph[cur][i];//out(v);
            if(val[v]>maxi)
            {
                maxi = val[v];
                vv = v;
            }
        }

        if(!vis[vv])
        {//cout<<cur<<" .. "<<vv<<endl;
            vis[vv] = 1;
            st.insert(mp(cost+val[vv],vv));
        }
    }
    return mp(res,resnode);
}

int main()
{
    int tc;

    sf(tc);

    for(int tt = 1; tt<=tc; tt++)
    {
        scanf("%d %d", &n,&m);

        for(int i=0; i<n; i++) sf(val[i]);

        for(int i=0; i<103; i++) graph[i].clear();

        int u,v;
        for(int i=0; i<m; i++)
        {
            scanf("%d %d", &u,&v);
            graph[u].pb(v);
        }

        mem(vis,0);
        pair <int,int> ans = bfs();

        pf("Case %d: %d %d\n", tt,ans.first,ans.second);
    }

    return 0;
}