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
#define mx                      1990005
#define mod                     1000000007
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

int n,m,draw,pathtype[2][100005],pathnode[2][100005];
bool vis[2][100005];
int vis2[100005];
vector <int> graph[100005];

void dfs(int cur,int type/*even (0) or odd (1) */)
{
    vis[type][cur] = 1;
//cout<<type<<" "<<cur<<endl;
    int curtype = 1 - type;
    for(int i=0; i<graph[cur].size(); i++)
    {
        int v = graph[cur][i];
        if(!vis[curtype][v])
        {
            pathtype[curtype][v] = type;
            pathnode[curtype][v] = cur;
            dfs(v,curtype);
        }
    }
}

int dfs2(int cur)
{
    vis2[cur] = 1;

    int cycle;
    for(int i=0; i<graph[cur].size(); i++)
    {
        int now = graph[cur][i];

        if(!vis2[now])
        {
            if(dfs2(now)) return 1;
        }
        else if(vis2[now] == 1) return 1;
    }
    vis2[cur] = 2;
    return 0;
}

int main()
{
    int q;
    scanf("%d %d", &n,&m);

    int temp;
    for(int i=1; i<=n; i++)
    {
        sf(q);

        while(q--)
        {
            sf(temp);
            graph[i].pb(temp);
        }
    }

    int s;

    sf(s);
    pathtype[1][s] = -1;
    pathnode[1][s] = -1;
    dfs(s,1);

    int win = 0;
    for(int i=1; i<=n; i++)
    {
        if(vis[0][i] && !graph[i].size())
        {
            win = 1;
            pf("Win\n");

            vector <int> vv;
            int cur = i,type = 0,fl = 0;
//cout<<pathtype[0][8]<<" "<<pathnode[0][8]<<endl;
//cout<<pathtype[1][7]<<" "<<pathnode[1][7]<<endl;system("pause");
            while(cur != -1 && type != -1)
            {
//                if(!fl) pf("%d", cur);
//                else pf(" %d", cur);

                vv.pb(cur);//out(vv.size());
 //cout<<cur<<" "<<type<<endl;system("pause");
                fl = 1;
                int tempcur = cur;
                cur = pathnode[type][tempcur];
                type = pathtype[type][tempcur];
            }

            for(int i=vv.size()-1; i>=0; i--)
            {
                if(i == vv.size()-1) pf("%d", vv[i]);
                else pf(" %d", vv[i]);
            }

            return 0;
        }
    }

    //if(win) pf("Win\n");
    //else
    //{
        mem(vis,0);
        draw = dfs2(s);
        if(draw) pf("Draw\n");
        else pf("Lose\n");
    //}
    
    return 0;
}