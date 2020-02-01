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

int n,m,p,vis[13][13],diss[13][13];
string str[13];

int dxx[] = {-1,0,1,0};
int dyy[] = {0,1,0,-1};

int doit(int r,int c)
{
    if(str[r][c] == 'N') return 0;
    else if(str[r][c] == 'E') return 1;
    else if(str[r][c] == 'S') return 2;
    else return 3;
}

void bfs(int sr,int sc)
{
    vis[sr][sc] = 1;
    diss[sr][sc] = 0;
    queue <int> q;
    q.push(sr);
    q.push(sc);

    while(!q.empty())
    {
        int curr = q.front(); q.pop();
        int curc = q.front(); q.pop();

        int type = doit(curr,curc);

        int tr = curr + dxx[type];
        int tc = curc + dyy[type];

        if(tr>=0 && tr<n && tc>=0 && tc<m)
        {

            if(vis[tr][tc])
            {
                int curdis = (diss[curr][curc] - diss[tr][tc]);

                pf("%d step(s) before a loop of %d step(s)\n",diss[tr][tc],curdis+1);

                return;
            }

            vis[tr][tc] = 1;
            diss[tr][tc] = diss[curr][curc] + 1;
            q.push(tr);
            q.push(tc);
        }
        else
        {
            pf("%d step(s) to exit\n", diss[curr][curc] + 1);
            return;
        }
    }
}

int main()
{
    while(scanf("%d %d %d", &n,&m,&p) == 3)
    {

        if(!n && !m && !p) break;

        for(int i=0; i<n; i++) cin>> str[i];

        mem(vis,0);
        bfs(0,p-1);
    }
    return 0;
}