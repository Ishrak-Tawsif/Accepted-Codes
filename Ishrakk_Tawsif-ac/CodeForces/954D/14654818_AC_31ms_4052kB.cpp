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
#define mod                     7901
#define left(n)                 (n<<1)
#define right(n)                ((n<<1) + 1)
#define fast                    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define PI                      acos(-1)
#define ull                     unsigned long long
#define eps                     .000000001
template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}
string tostring(ll res){string curstr="";if(!res) curstr += '0';while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}


/* ...........................................................................................................*/

int diss[3][1005],n,m,s,t,u,v,edge[1005][1005],vis[3][1005];
vector <int> graph[1005];

void dfs(int cur,int type)
{//out(cur);
    vis[type][cur] = 1;
//cout<<cur<<" "<<dis[type][cur]<<endl;
    for(int i=0; i<graph[cur].size(); i++)
    {
        int now = graph[cur][i];
        if(!vis[type][now] || diss[type][now]>diss[type][cur] + 1) diss[type][now] = diss[type][cur] + 1,dfs(now,type);
    }
}

//void warshall()
//{
//    for(int i=1; i<=n; i++)
//    {
//        for(int j=1; j<=n; j++)
//        {
//            for(int k=1; k<=n; k++)
//            {
//                if(diss[i][j]>diss[i][k]+diss[k][j]) diss[i][j] = diss[i][k] + diss[k][j];
//            }
//        }
//    }
//}

int main()
{
    scanf("%d %d %d %d", &n,&m,&s,&t);

//    for(int i=1; i<=n; i++)
//    {
//        for(int j=1; j<=n; j++)
//        {
//            if(i == j) diss[i][j] = 0;
//            else diss[i][j] = 1e9;
//        }
//    }
//cout<<n<<" "<<m<<" "<<s<<" "<<t<<endl;
    for(int i=1; i<=m; i++)
    {
        scanf("%d %d", &u,&v);
        graph[u].pb(v);
        graph[v].pb(u);
        //diss[u][v] = diss[v][u] = 1;
        edge[u][v] = edge[v][u] = 1;
    }//out("ok");

    dfs(s,1);//system("pause");
    dfs(t,2);
//cout<<dis[1][t]<<" "<<dis[2][s]<<endl;

    //warshall();

    int cnt = 0;
    for(int i=1; i<=n; i++)
    {
        for(int j=i+1; j<=n; j++)
        {
            if(!edge[i][j])
            {//cout<<i<<" "<<j<<" "<<diss[s][i]+diss[t][j]+1<<" "<<diss[s][t]<<endl;
                if(diss[1][i]+diss[2][j]+1>=diss[1][t] && diss[1][j]+diss[2][i]+1>=diss[1][t]) cnt++;
            }
        }
    }

    pf("%d\n", cnt);

    return 0;

}