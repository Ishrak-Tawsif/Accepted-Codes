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

queue <pair<int,int> > qq;
map <pair<int,int>,int> vis,level,dis;
string str[2000005];
int n,m,d;

int valid(int rr,int cc)
{
    if(rr>=0 && rr<n && cc>=0 && cc<m)
    {
        return 1;
    }
    return 0;
}

int bfs(int sr,int sc,int er,int ec)
{
    queue <pair<int,int > > q;
    q.push(mp(sr,sc));
    dis[mp(sr,sc)] = 0;
    if(str[sr][sc] == 'M' || str[sr][sc] == '#') return -1;

    while(!q.empty())
    {
        pair <int,int> ttmm,temp = q.front();
        q.pop();

        if(temp.first == er && temp.second == ec) return dis[temp];

        for(int i=0; i<4; i++)
        {
            int tr = temp.first + dx[i];
            int tc = temp.second + dy[i];
            ttmm = mp(tr,tc);

            if(valid(tr,tc))
            {
                if(!vis[ttmm] && str[tr][tc] != 'M' && str[tr][tc] != '#')
                {//cout<<ttmm.first<<" "<<ttmm.second<<endl;
                    q.push(ttmm);
                    dis[ttmm] = dis[temp] + 1;
                    vis[ttmm] = 1;
                }
            }
        }
    }
    return -1;
}

void setall()
{
//    queue <int> qq;
//    qq.pb(r);
//    qq.pb(c);

    while(!qq.empty())
    {
        int rr = qq.front().first;
        //qq.pop();
        int cc = qq.front().second;
        qq.pop();

        pair <int,int> temp ,ttmm;

        temp = mp(rr,cc);


        for(int i=0; i<4; i++)
        {
            int tr = rr + dx[i];
            int tc = cc + dy[i];//cout<<tr<<" "<<tc<<endl;
            if(valid(tr,tc))
            {
                if(str[tr][tc] != 'M' && str[tr][tc] != '#')
                {
                    str[tr][tc] = '#';
                    ttmm = mp(tr,tc);
                    level[ttmm] = level[temp] + 1;
                    if(level[ttmm] == d) continue;
                    qq.push(mp(tr,tc));
                }
            }
        }
    }
}

int main()
{
    int sr,sc,er,ec;

    scanf("%d %d %d", &n,&m,&d);

    for(int i=0; i<n; i++)
    {
        cin>> str[i];
        for(int j=0; j<m; j++)
        {
            if(str[i][j] == 'S') sr = i,sc = j;
            else if(str[i][j] == 'F') er = i,ec = j;
            else if(str[i][j] == 'M')
            {
                //setall(i,j);
                qq.push(mp(i,j));
                //qq.push(j);
            }
        }
    }

    if(d)setall();
    //for(int i=0; i<n; i++) {for(int j=0; j<m; j++) cout<<str[i][j]; cout<<endl;}
    cout<<bfs(sr,sc,er,ec)<<endl;

    return 0;
}