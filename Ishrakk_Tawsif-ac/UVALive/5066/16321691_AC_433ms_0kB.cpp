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
#define casepf(nn)              printf ("Case %d:\n",nn)
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
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      100005
#define mod                     1000000007

template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}

string tostring(ll res){string curstr="";while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}


/* ...........................................................................................................*/

string str[11][101];
int f[101],r[101],c[101],point[101],diss[11][101][101],vis[11][101][101],dp[101][10001],wei[101];
int l,h,w,n,t; /// floor,height,weight,people,time

struct st
{
    int fl,rw,cl;
};

void bfs(int sr,int sc)
{
    st get;
    queue <st> q;
    get.fl = 0;
    get.rw = sr;
    get.cl = sc;
    q.push(get);
    diss[0][sr][sc] = 0;
    vis[0][sr][sc] = 1;

    while(!q.empty())
    {
        get = q.front(); q.pop();

        int curf = get.fl;
        int curr = get.rw;
        int curc = get.cl;//cout<<curf<<" "<<curr<<" "<<curc<<endl;

        for(int i=0; i<4; i++)
        {
            int tr = curr + dx[i];
            int tc = curc + dy[i];

            if(tr>=0 && tr<h && tc>=0 && tc<w)
            {
                if(!vis[curf][tr][tc])
                {
                    vis[curf][tr][tc] = 1;
                    if(str[curf][tr][tc] == 'X') continue;

                    if(str[curf][tr][tc] == 'U')
                    {
                        diss[curf+1][tr][tc] = diss[curf][curr][curc] + 2;
                        diss[curf][tr][tc] = diss[curf][curr][curc] + 1;
                        //cout<<diss[curf+1][tr][tc]<<endl;
                        get.fl = curf + 1;
                        get.rw = tr;
                        get.cl = tc;
                        q.push(get);

                        get.fl = curf;
                        q.push(get);
                    }
                    else if(str[curf][tr][tc] == 'D')
                    {
                        diss[curf-1][tr][tc] = diss[curf][curr][curc] + 2;
                        diss[curf][tr][tc] = diss[curf][curr][curc] + 1;

                        get.fl = curf - 1;
                        get.rw = tr;
                        get.cl = tc;
                        q.push(get);

                        get.fl = curf;
                        q.push(get);
                    }
                    else
                    {
                        diss[curf][tr][tc] = diss[curf][curr][curc] + 1;
                        get.fl = curf;
                        get.rw = tr;
                        get.cl = tc;
                        q.push(get);
                    }
                }
            }
        }
    }

}

vector <pair<int,int> > vv;

int call(int pos,int totwei)
{
    if(pos>=vv.size()) return 0;
    if(dp[pos][totwei] != -1) return dp[pos][totwei];

    int ans;
    if(totwei+vv[pos].first <= t)
    {
        ans = max(call(pos+1,totwei),call(pos+1,totwei + vv[pos].first) + vv[pos].second);
    }
    else ans = call(pos+1,totwei);

    return dp[pos][totwei] = ans;
}

int main()
{//WRITE("out.txt");
    int tc;
    scanf("%d", &tc);

    for(int tt=1; tt<=tc; tt++)
    {
        mem(vis,0);
        mem(diss,-1);
        vv.clear();

        scanf("%d %d %d %d %d", &l,&h,&w,&n,&t);

        for(int i=0; i<l; i++)
        {
            for(int j=0; j<h; j++)
            {
                cin>> str[i][j];
            }
        }

        int sr,sj;
        for(int i=0; i<h; i++)
        {
            for(int j=0; j<w; j++)
            {
                if(str[0][i][j] == 'S')
                {
                    sr = i;
                    sj = j;
                    break;
                }
            }
        }

        for(int i=1; i<=n; i++)
        {
            scanf("%d %d %d %d", &f[i],&r[i],&c[i],&point[i]);
        }
        bfs(sr,sj);

        for(int i=1; i<=n; i++)
        {
            int curdis = diss[f[i]-1][r[i]-1][c[i]-1];
            if(curdis == -1) continue;
            curdis = curdis + (2*curdis);
            //cout << curdis - (2*diss[f[i]-1][r[i]-1][c[i]-1]) << " " << curdis << " " << point[i] <<endl;
            vv.pb(mp(curdis,point[i]));
        }

        mem(dp,-1);
        int ans = call(0,0);
        printf("%d\n", ans);

    }

    return 0;
}