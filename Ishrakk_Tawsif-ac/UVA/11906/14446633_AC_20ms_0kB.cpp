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

int n,m,nn,mm,even,odd;
int mark[103][103],cnt[103][103],vis[103][103];
int dxx[] = {1,-1};

void doit(int r,int c,int curid)
{//out(curid);
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<2; j++)
        {
            int tr = r + (dxx[i] * nn);
            int tc = c + (dxx[j] * mm);

            if(tr>=0 && tr<n && tc>=0 && tc<m)
            {
                if(vis[tr][tc] != curid && mark[tr][tc] != 1) vis[tr][tc] = curid,cnt[tr][tc] ++;
            }

            tr = r + (dxx[i] * mm);
            tc = c + (dxx[j] * nn);

            if(tr>=0 && tr<n && tc>=0 && tc<m)
            {
                if(vis[tr][tc] != curid && mark[tr][tc] != 1) vis[tr][tc] = curid,cnt[tr][tc] ++;
            }
        }
    }
}

void dfs(int r,int c)
{

    if(vis[r][c] || mark[r][c]) return;
    vis[r][c] = 1;
//cout<<r<<" "<<c<<" "<<cnt[r][c]<<endl;
    if(cnt[r][c]%2 == 0) even ++;
    else odd++;

    for(int i=0; i<2; i++)
    {
        for(int j=0; j<2; j++)
        {
            int tr = r + (dxx[i] * nn);
            int tc = c +(dxx[j] * mm);

            if(tr>=0 && tr<n && tc>=0 && tc<m)
            {
                if(!mark[tr][tc] && !vis[tr][tc]) dfs(tr,tc);
            }

            tr = r + (dxx[i] * mm);
            tc = c + (dxx[j] * nn);

            if(tr>=0 && tr<n && tc>=0 && tc<m)
            {
                if(!mark[tr][tc] && !vis[tr][tc]) dfs(tr,tc);
            }

        }
    }
}

int main()
{//WRITE("out.txt");
    int tc,w,u,v;

    sf(tc);

    for(int tt = 1; tt<=tc; tt++)
    {
        scanf("%d %d %d %d", &n,&m,&nn,&mm);

        mem(mark,0);
        mem(cnt,0);

        sf(w);

        while(w--)
        {
            scanf("%d %d", &u,&v);
            mark[u][v] = 1;
        }

        int curid = 0;
        mem(vis,0);
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(!mark[i][j])doit(i,j,++curid);
            }
        }
        mem(vis,0);
        even = odd = 0;

        dfs(0,0);
        pf("Case %d: %d %d\n", tt,even,odd);
    }

    return 0;
}