#include<bits/stdc++.h>
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
#define mx                      10005
#define mod                     1000000007

template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}

string tostring(ll res){string curstr="";while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}

/* ...........................................................................................................*/

string str[13];
vector <pair<int,int> > vv;
int val[11][11],vis[11][11],n,m,dis[103][11][11];

int dirx[] = {1,1,2,2,-1,-1,-2,-2};
int diry[] = {2,-2,1,-1,2,-2,1,-1};

void bfs(int rr,int cc,int ind)
{
    mem(vis,0);
    queue <pair<int,int> > q;
    q.push(mp(rr,cc));
    int k = (int) (str[rr][cc]-'0');

    val[rr][cc] ++;
    dis[ind][rr][cc] = 0;
    vis[rr][cc] = 1;

    while(!q.empty())
    {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();

            for(int i=0; i<8; i++)
            {
                    int tr = cr + (dirx[i]);
                    int tc = cc + (diry[i]);

                    if(tr>=0 && tr<n && tc>=0 && tc<m)
                    {
                        if(!vis[tr][tc])
                        {
                            vis[tr][tc] = 1;
                            val[tr][tc] ++;//cout<<ind<<" "<<tr<<" "<<tc<<endl;
                            dis[ind][tr][tc] = (dis[ind][cr][cc] + 1);
                            q.push(mp(tr,tc));
                        }
                        else if(dis[ind][tr][tc]>dis[ind][cr][cc] + 1)
                        {
                            dis[ind][tr][tc] = dis[ind][cr][cc] + 1;
                            q.push(mp(tr,tc));
                        }
                    }
            }
    }
}

void clearall()
{
    mem(dis,0);
    mem(vis,0);
    mem(val,0);
    vv.clear();
}

int main()
{//WRITE("in.txt");
    int tc;


    sf(tc);

    for(int tt=1; tt<=tc; tt++)
    {
        scanf("%d %d", &n,&m);

        clearall();

        for(int i=0; i<n; i++)
        {
            cin>> str[i];
            int len = str[i].length();
            for(int j=0; j<len; j++) if(str[i][j]>= '0' && str[i][j]<= '9') vv.pb(mp(i,j));
        }
        for(int i=0; i<vv.size(); i++)
        {
            int rr = vv[i].first;
            int cc = vv[i].second;
            bfs(rr,cc,i);
        }

        int tot = vv.size(),res=2e9;;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                    if(val[i][j] == tot)
                    {
                        int tempcost = 0;
                        for(int l=0; l<tot; l++)
                        {
                            int modval = (int) (str[vv[l].first][vv[l].second] - '0');
                            tempcost += (dis[l][i][j]/modval) + ((dis[l][i][j] % modval)>=1);
                        }
                        res = min(res,tempcost);
                    }
            }
        }
        casepf(tt); if(res == 2e9) pf("-1\n"); else pf("%d\n", res);
    }
    return 0;
}