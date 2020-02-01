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
#define mx                      300005
#define mod                     998244353
#define left(n)                 (n<<1)
#define right(n)                ((n<<1) + 1)
#define fast                    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define PI                      acos(-1)
#define bitOff(N,in)            (N&(~(1LL<<(in))))
#define bitOn(N,in)             (N|(1LL<<(in)))
#define ull                     unsigned long long
#define eps                     .000000001

template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}
string tostring(ll res){string curstr="";if(!res) curstr += ((char)res + '0');while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}

/* ...........................................................................................................*/

map <string,int> id;
string str,temp;
int ok,vis[203];
vector <int> graph[203],graph2[203];

void dfs1(int cur,int des)
{//cout<<cur<<" .. "<<des<<endl;
    if(cur == des)
    {
        ok = 1;
        return;
    }
    if(ok) return;

    vis[cur] = 1;
//cout<<cur<<" sz "<<graph[cur].size()<<endl;
    for(int i=0; i<graph[cur].size(); i++)
    {
        int v = graph[cur][i];//cout<<cur<<" here "<<v<<endl;
        if(!vis[v]) dfs1(v,des);
    }
}

int main()
{
    int n,m,curid=0;

    scanf("%d %d", &n,&m);

    getchar();
    for(int i=1; i<=n; i++)
    {
        getline(cin,str);
        stringstream ss(str);

        string fs,sn;
        while(ss>> temp)
        {
            if(temp == "are" || temp == "worse" || temp == "than") continue;
            if(id[temp] == 0) id[temp] = ++curid;
            if(fs == "") fs = temp;
            else sn = temp;
        }
        //cout<<id[fs]<<" "<<id[sn]<<endl;
        graph[id[fs]].pb(id[sn]);
    }

    //getchar();
    for(int i=1; i<=m; i++)
    {
        getline(cin,str);
        stringstream ss(str);

        int curid = 0;
        string fs,sn;
        while(ss>> temp)
        {
            if(temp == "are" || temp == "worse" || temp == "than") continue;
            //if(id[temp] == 0) id[temp] = ++curid;
            if(fs == "") fs = temp;
            else sn = temp;
        }


        ok = 0;

        int sr = id[fs];
        int ds = id[sn];//cout<<fs<<" : " << sn <<" " <<sr<<" "<<ds <<endl;

        if(!sr || !ds)
        {
            pf("Pants on Fire\n");
            continue;
        }

        mem(vis,0);
        dfs1(sr,ds); //out("ok");

        if(ok)
        {
            pf("Fact\n");
            continue;
        }

        mem(vis,0);
        dfs1(ds,sr);

        if(ok)
        {
            pf("Alternative Fact\n");
            continue;
        }

        pf("Pants on Fire\n");///
    }

    return 0;
}