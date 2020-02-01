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

int n,m,vis[13][13],track[13][13];
string lar[13],sm[13];


int dfs(int bx,int by,int sx,int sy)
{
    if(bx>=0 && bx<n && by>=0 && by<n)
    {
        if(lar[bx][by] == '.') return 0;
        if(vis[bx][by]) return 0;

        vis[bx][by] = 1;
        track[sx][sy] = 1;//cout<<sx<<" "<<sy<<endl;

        int fl = 1;

        for(int i=0; i<8; i++)
        {
            int tr = sx + dx[i];
            int tc = sy + dy[i];
//if(sx == 2 && sy == 7) cout<<tr<<" /// "<<tc<<endl;
            if(tr>=0 && tr<m && tc>=0 && tc<m)
            {
                if(sm[tr][tc] == '*' && !track[tr][tc])
                {
                    int nr = bx + dx[i];
                    int nc = by + dy[i];

                    fl &= dfs(nr,nc,tr,tc);
                }
            }
        }
        return fl;
    }
    else return 0;
}

int check()
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(lar[i][j] == '*')
            {
                if(!vis[i][j]) return 0;
            }
        }
    }
    return 1;
}

int main()
{//WRITE("in.txt");
    while(scanf("%d %d", &n,&m) == 2)
    {
        if(!n && !m) break;

        for(int i=0; i<n; i++) cin>> lar[i];
        for(int i=0; i<m; i++) cin>> sm[i];

        mem(vis,0);
        mem(track,0);
        int sx,sy,fl = 0,res = 1;

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(sm[i][j] == '*')
                {
                    fl = 1;
                    sx = i;
                    sy = j;
                    break;
                }
            }
            if(fl) break;
        }

        int bx,by;
        fl  = 0;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(lar[i][j] == '*')
                {
                    bx = i;
                    by = j;
                    fl = 1;
                    res = dfs(bx,by,sx,sy);
                    break;
                }
            }
            if(fl) break;
        }

        fl = 0;
        mem(track,0);
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(lar[i][j] == '*' && !vis[i][j])
                {//cout<<i<<" .... "<<j<<endl;
                    res &= dfs(i,j,sx,sy);
                    fl = 1;
                    break;
                }
            }
            if(fl) break;
        }

        //res = check();

        for(int i=0; i<n; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                if(lar[i][j] == '*')
                {
                    if(!vis[i][j])
                    {
                        res = 0;
                        //cout<<i<<" "<<j<<endl;
                    }
                }
            }
        }

        res? pf("1\n") : pf("0\n");
    }

    return 0;
}