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
#define left(n)                 (n<<1)
#define right(n)                ((n<<1) + 1)
#define fast                    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define PI                      acos(-1)
#define bitOff(N,in)            (N&(~(1LL<<(in))))
#define bitOn(N,in)             (N|(1LL<<(in)))
#define ull                     unsigned long long
#define eps                     .000000001

#define mx                      2000005
#define mod                     998244353

template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}
string tostring(ll res){string curstr="";if(!res) curstr += ((char)res + '0');while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}

/* ...........................................................................................................*/

int vis[9][9];

int bfs(int sr,int sc,int dr,int dc)
{
    queue <int> q;
    q.push(0);
    q.push(sr);
    q.push(sc);
    mem(vis,0);

    while(!q.empty())
    {
        int diss = q.front(); q.pop();
        int curr = q.front(); q.pop();
        int curc = q.front(); q.pop();

        if(curr == dr && curc == dc) return diss;

        for(int i=0; i<4; i++)
        {
            int tr = curr + dx[i];
            int tc = curc + dy[i];

            if(tr>=1 && tr<=8 && tc>=1 && tc<=8)
            {
                if(!vis[tr][tc])
                {
                    vis[tr][tc] = 1;
                    q.push(diss+1);
                    q.push(tr);
                    q.push(tc);
                }
            }
        }
    }
}

int main()
{
    int tc,sr,sc,dr,dc;
    string str;

    scanf("%d", &tc);

    for(int tt=1; tt<=tc; tt++)
    {
        scanf("%d %d %d %d", &sr,&sc,&dr,&dc);
        int res = bfs(sr,sc,dr,dc);
        printf("%d\n", res);
    }

    return 0;
}