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

int n,vis[201][201];
int dxx[] = {-1,-1,0,0,1,1};
int dyy[] = {-1,0,-1,1,0,1};
string str[201];

int bfs(int sr,int sc,int type)
{
    char ch;
    int res = 2e9;
    if(type == 0) ch = 'b';
    else ch = 'w';
    vis[sr][sc] = 1;
    queue <int> q;
    q.push(sr);
    q.push(sc);
    q.push(0);
//out(ch);
    while(!q.empty())
    {
        int r = q.front(); q.pop();
        int c = q.front(); q.pop();
        int cst = q.front(); q.pop();
//if(ch == 'b') cout<<r<<" "<<c<<" "<<cst<<endl;
        if(ch == 'b' && r == (n-1)) res = min(res,cst);
        if(ch == 'w' && c == (n-1)) res = min(res,cst);

        for(int i=0; i<6; i++)
        {
            int tr = r + dxx[i];
            int tc = c + dyy[i];

            if(tr>=0 && tr<n && tc>=0 && tc<n)
            {
                if(str[tr][tc] != ch || vis[tr][tc]) continue;
                vis[tr][tc] = 1;
                q.push(tr);
                q.push(tc);
                q.push(cst+1);
            }
        }
    }
    return res;
}

int main()
{
    int tc = 0;

    while(sf(n) && n)
    {
        for(int i=0; i<n; i++) cin>> str[i];

        int bcost = 2e9,wcost = 2e9;

        ///black
        for(int i=0; i<n; i++)
        {
            mem(vis,0);
            if(str[0][i] == 'b') bcost = min(bfs(0,i,0),bcost);
        }

        ///while
        for(int i=0; i<n; i++)
        {
            mem(vis,0);
            if(str[i][0] == 'w') wcost = min(bfs(i,0,1),wcost);
        }//cout<<bcost<<" "<<wcost<<endl;
        (bcost>wcost)? pf("%d W\n", ++tc) : pf("%d B\n", ++tc);
    }
    return 0;
}