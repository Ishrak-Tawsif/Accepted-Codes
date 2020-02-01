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
#define mx                      11
#define mod                     1000000007

template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}

string tostring(ll res){string curstr="";while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}

/* ...........................................................................................................*/

string sr,ds[1005];
unordered_map <string,int> id;
int vis[105][105];
ll cost[105][105],diss[105];

struct ST
{
    int v;
};
vector <ST> graph[105];

pair<int,int> check(string str)
{
    for(int i=0; i<105; i++) diss[i] = 2e9;
    int len = str.length(),tp;
    if(str[0] == '<' && str[len-1] == '>') tp = 1;

    else if(str[0] == '<' && str[len-1] == '-') tp = 2;

    else tp = 3;

    ll cst = 0;
    for(int i=0; i<len; i++)
    {
        if(str[i]>='0' && str[i]<='9')
        {
            int now = str[i] - '0';
            cst = (cst*10) + now;
        }
    }

    return mp(tp,cst);
}


void warshall(int n)
{
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                for(int k=1; k<=n; k++)
                {
                    if(j!=k)
                    {
                        cost[j][k] = min(cost[j][k],cost[j][i]+cost[i][k]);
                    }
                }
            }
        }
}

void clearall()
{
    for(int i=0; i<105; i++) graph[i].clear();
    for(int i=0; i<105; i++)
    {
        for(int j=0; j<105; j++)
        {
            if(i == j) cost[i][j] = 0;
            else cost[i][j] = 2e9+10;
        }
    }
    id.clear();
    mem(vis,0);
}

int main()
{
    int n,cc,r,tt = 0;

    while(scanf("%d %d %d", &n,&cc,&r) == 3)
    {
        if(!n && !cc && !r) break;

        clearall();

        int curid = 0;

        cin>> sr;
        id[sr] = ++curid;

        for(int i=0; i<cc; i++) {cin>> ds[i];if(!id[ds[i]])id[ds[i]] = ++curid;}

        string a,b,c;

        ST get;

        for(int i=0; i<r; i++)
        {
            cin>> a>> c>> b;

            if(!id[a]) id[a] = ++curid;
            if(!id[b]) id[b] = ++curid;

            pair<int,ll> temp =  check(c);
//cout<<temp.first << " "<< temp.second<<endl;
            int aid = id[a],bid = id[b];
            //cout<<aid<<" ... "<<bid<<" "<<b<<endl;
            if(temp.first == 1)
            {
                get.v = bid;
                //get.cst = temp.second;
                graph[aid].pb(get);
                get.v = aid;
                graph[bid].pb(get);
                cost[aid][bid] = min(cost[aid][bid],temp.second);
                cost[bid][aid] = min(cost[bid][aid],temp.second);
            }
            else if(temp.first == 2)
            {
                get.v = aid;
                //get.cst = temp.second;
                graph[bid].pb(get);
                cost[bid][aid] = min(cost[bid][aid],temp.second);
            }
            else
            {
                get.v = bid,graph[aid].pb(get);
                cost[aid][bid] = min(cost[aid][bid],temp.second);
            }
        }

        warshall(n);
        int source,destination;
        ll res=0;

        source = id[sr];

            for(int i=0; i<cc; i++)
            {
                destination = id[ds[i]];

                res += cost[source][destination];
                res += cost[destination][source];
            }

        pf("%d. %lld\n",++tt,res);//system("pause");

    }
    return 0;
}