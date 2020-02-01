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
#define mod                     998244353
#define left(n)                 (n<<1)
#define right(n)                ((n<<1) + 1)
#define fast                    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define PI                      acos(-1)
#define bitOff(N,in)            (N&(~(1LL<<(in))))
#define bitOn(N,in)             (N|(1LL<<(in)))
#define ull                     unsigned long long
#define eps                     .000000001

template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}
string tostring(ll res){string curstr="";if(!res) curstr += ((char)res + '0');while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}

/* ...........................................................................................................*/

string str,str2;
int vis[129];
ll cost[129][129],fincst[129][129],diss[129];
vector <int> graph[129];

ll bfs(int sr,int des)
{
    for(int i=0; i<129; i++) diss[i] = 2e14;
    queue <ll> q;
    diss[sr] = 0;
    vis[sr] = 1;
    q.push(sr);
    q.push(0);

    while(!q.empty())
    {
        int u = (int)q.front(); q.pop();
        ll cst = q.front(); q.pop();

        //if(u == des) return cst;//cout<<" .... "<<u<<endl;

        for(int i=0; i<graph[u].size(); i++)
        {
            int v = graph[u][i];
            //if(sr == 79 && des == 68)cout<<u<<" /// "<<v<<" "<<cst<<" "<<cost[u][v]<<" "<<diss[v]<<endl;
            if(!vis[v] || diss[v]>(cst + cost[u][v]))
            {
                vis[v] = 1;
                q.push(v);
                diss[v] = cst + cost[u][v];
                q.push(cst + cost[u][v]);
            }
        }
    }
    if(diss[des] != 2e14) return diss[des];
    return -1;
}

int main()
{
    //int temp = 2600000000; out(temp);
    //string sss = "a"; int coss = sss[0]; cout<<coss<<" "; coss -= 32; out(coss);
    for(int i=0; i<129; i++) for(int j=0; j<129; j++) cost[i][j] = 2e14;

    cin>> str>> str2;

    int n;

    sf(n);

    char a,b;
    ll c;

    for(int i=0; i<n; i++)
    {
        cin>> a>> b>> c;

        int u = a; u -= 32;
        int v = b; v -= 32;
//cout<<a<<" "<<b<<" "<<u<<" "<<v<<endl;
        if(cost[u][v] == 2e14) graph[u].pb(v);

        cost[u][v] = min(cost[u][v],c);
    }

    for(int i=1; i<=94; i++)
    {
        for(int j=1; j<=94; j++)
        {
            mem(vis,0);
            ll curcst = bfs(i,j);
            if(curcst != -1)
            {
                fincst[i][j] = curcst;
            }
            else fincst[i][j] = 2e14;
        }
    }

    ll res = 0;
    for(int i=0; i<str.length(); i++)
    {
        int u = str[i]; u -= 32;
        int v = str2[i]; v -= 32;

        if(fincst[u][v] != 2e14) res += fincst[u][v];
        else {res = -1; break;}
    }
    pf("%lld\n", res);

    return 0;

}