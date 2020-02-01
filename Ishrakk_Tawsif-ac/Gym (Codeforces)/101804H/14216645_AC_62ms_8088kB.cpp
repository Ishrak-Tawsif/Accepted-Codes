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

int n,m,u,v,q,c,diss[1005][1005],vis[1005][1005];
vector <pair<int,int> > graph[1005];

void dikjstra(int sr)
{

    for(int i=0; i<1005; i++)
    {
        for(int j=0; j<1005; j++) diss[i][j] = 2e9;
    }

    set <pair<int,int> > st; /// tot edge, node
    st.insert(mp(0,sr));
    diss[0][sr] = 0;
    vis[0][sr] = 1;

    while(!st.empty())
    {
        auto now = * st.begin();
        st.erase(st.begin());

        int f = now.first;
        int u = now.second;

        if(vis[f][u]) vis[f][u] = 0;

        if(f == (m-1)) continue;

        for(int i=0; i<graph[u].size(); i++)
        {
            int vv = graph[u][i].first;
            int cost = graph[u][i].second;

            if(diss[f+1][vv] > diss[f][u] + cost)
            {
                if(!vis[f+1][vv])
                {
                    st.insert(mp(f+1,vv));
                    vis[f+1][vv] = 1;
                }

                diss[f+1][vv] = diss[f][u] + cost;
            }
        }
    }
}

int main()
{
    scanf("%d %d", &n,&m);

    //sf(q);

    for(int i=0; i<m; i++)
    {
        scanf("%d %d %d", &u,&v,&c);
        graph[u].pb({v,c});
        //graph[v].pb({u,c});
    }

    dikjstra(1);

    sf(q);
//out(q);

    while(q--)
    {//out("here");
        int res = 2e9;
        scanf("%d %d", &u,&v);
        v++;
        for(int i = 0; i<=v; i++) res = min(res,diss[i][u]);

        if(res != 2e9)pf("=] %d\n", res);
        else pf("=[\n");

    }

    return 0;
}