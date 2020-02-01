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

int n,vis[101][101],dominator[101],cnt[101],vis2[101][101];
vector <int> graph[105];

void dfs(int sr,int cur,int avoid)
{
    if(avoid == cur) return;
    vis[sr][cur] = 1;

    for(int i=0; i<graph[cur].size(); i++)
    {
        int v = graph[cur][i];

        if(!vis[sr][v]) dfs(sr,v,avoid);
    }

    //vis[cur] = 0;
}

void dfs2(int sr,int cur)
{
    vis2[sr][cur] = 1;
//if(sr == 1) out(cur);
    for(int i=0; i<graph[cur].size(); i++)
    {
        int v = graph[cur][i];

        if(!vis2[sr][v]) dfs2(sr,v);
    }
}

void printit()
{
    int till = (2 * n) - 1;
    pf("+");
    for(int i=1; i<=till; i++) pf("-");
    pf("+\n");
}


int main()
{//WRITE("out.txt");
    int tc,temp;

    sf(tc);

    for(int tt = 1; tt<=tc; tt++)
    {
        sf(n);

        for(int i=0; i<n; i++) graph[i].clear();

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                sf(temp);
                if(temp) graph[i].pb(j);
            }
        }
        pf("Case %d:\n",tt);

        mem(vis,0);
        mem(dominator,0);
        mem(cnt,0);
        for(int i=0; i<n; i++)
        {
            //mem(vis,0);
            dfs(i,0,i);

            for(int j=0; j<n; j++)
            {
                if(!vis[i][j])
                {
                    if(cnt[j] == 0) dominator[j] = i;
                    cnt[j] ++;
                }
            }
        }

        mem(vis2,0);
        for(int i=0; i<n; i++)
        {
            //mem(vis,0);
            dfs2(i,i);

        }

        printit();
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(!vis[i][j] && vis2[0][i] && vis2[i][j]) pf("|Y");
                else pf("|N");
            }
            
            pf("|\n");
            printit();
        }
    }

    return 0;
}