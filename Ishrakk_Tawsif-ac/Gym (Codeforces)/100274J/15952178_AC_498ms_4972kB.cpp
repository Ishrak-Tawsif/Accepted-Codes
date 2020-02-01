#include <bits/stdc++.h>
#include <ext/rope>

using namespace __gnu_cxx;
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
#define mod                     998244353
#define left(n)                 (n<<1)
#define right(n)                ((n<<1) + 1)
#define fast                    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define PI                      acos(-1)
#define bitOff(N,in)            (N&(~(1LL<<(in))))
#define bitOn(N,in)             (N|(1LL<<(in)))
#define ull                     unsigned long long
#define eps                     .000000001
#define mx                      100005

template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}
string tostring(ll res){string curstr="";if(!res) curstr += ((char)res + '0');while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}

/* ...........................................................................................................*/

int n,u,v,vis[mx],val[mx],dis[mx];
vector <int> graph[mx];

int diameter(int cur)
{
    vis[cur] = 1;
    int mx1,mx2;
    mx1 = mx2 = 0;

    for(int i=0; i<graph[cur].size(); i++)
    {
        int v = graph[cur][i];
        if(vis[v]) continue;
        int depth = diameter(v);
        if(depth > mx1) mx2 = mx1,mx1 = depth;
        else if(depth > mx2) mx2 = depth;
    }
//cout<<cur<<" ||| "<<mx1+mx2<<endl;

    val[cur] = (mx1+1 + mx2+1);

    return max(1+mx1,1+mx2);
}

pair <int,int> bfs(int sr)
{//out("ok");
    for(int i=0; i<=n; i++) dis[i] = 2e9;
    dis[sr] = 0;
    queue <int> q;
    q.push(sr);

    int last;

    while(!q.empty())
    {
        last = q.front();
        q.pop();

        for(int i=0; i<graph[last].size(); i++)
        {
            int v = graph[last][i];
            if(dis[v] > dis[last] + 1)
            {
                dis[v] = dis[last] + 1;
                q.push(v);
            }
        }
    }//out("ok2");
    return mp (last,dis[last]);
}

int main()
{
    int tc;

    sf(tc);

    for(int tt=1; tt<=tc; tt++)
    {
        sf(n);
        for(int i=0; i<mx; i++) graph[i].clear();

        for(int i=1; i<=n-1; i++)
        {
            scanf("%d %d", &u,&v);
            graph[u].pb(v);
            graph[v].pb(u);
        }

//        mem(vis,0);
//        int res = diameter(1);out(res);
//        pf("%d\n", res/2 + (res%2>0));


        int iter = 11,cur = 1,maxi = 2e9,fl=0,finalnode;

        while(iter --)
        {//out(iter);
            pair <int,int> now = bfs(cur);
            int node = now.first;
            int distance = now.second;

            if(distance < maxi && fl)
            {
                maxi = distance;
                finalnode = node;
            }
            cur = node;
            fl = 1;
        }
        if(maxi == 1) pf("1\n");
        else if(maxi%2 == 0) pf("%d\n", maxi/2);
        else pf("%d\n", (maxi/2)+1);
    }

    return 0;
}