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
#define mx                      557
#define mod                     1000000007

template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}

string tostring(ll res){string curstr="";while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}

/* ...........................................................................................................*/

int n,m;
ll diss[305][305],edge[305][305],cost[305][305];
vector<int>graph[305];

void dikjstra(int sr)
{
    diss[sr][sr] = 0;
    edge[sr][sr] = 0;

    priority_queue <pair<ll,int > > st;
    st.push(mp(0,sr));

    while(!st.empty())
    {
        pair<ll,int> temp = st.top();
        st.pop();

        ll curcst = temp.first;
        //int seg = temp.second.first;
        int u = temp.second;

        for(int i=0; i<graph[u].size(); i++)
        {
            int v = graph[u][i];
            //if(v<sr) continue;
            if(diss[sr][v]>diss[sr][u] + cost[u][v])
            {
                diss[sr][v] = diss[sr][u] + cost[u][v];
                edge[sr][v] = edge[sr][u] + 1;
                st.push(mp(-diss[sr][v],v));
            }
            else if(diss[sr][v] == diss[sr][u] + cost[u][v] && edge[sr][v]>edge[sr][u]+1)
            {
                diss[sr][v] = diss[sr][u] + cost[u][v];
                edge[sr][v] = edge[sr][u] + 1;
            }
        }
    }
}

int main()
{

    READ("trip.in");
    WRITE("trip.out");

    for(int i=0; i<305; i++)
    {
        for(int j=0; j<305; j++)
        {
            if(i == j) cost[i][j] = 0;
            else cost[i][j] = 2e18;
            diss[i][j] = 2e18;
            edge[i][j] = 2e18;
        }
    }

    scanf("%d %d", &n,&m);

    int u,v;
    ll cs;

    for(int i=0; i<m; i++)
    {
        scanf("%d %d %lld", &u,&v,&cs);

        if(cost[u][v] == 2e18)
        {
            cost[u][v] = cs;
            cost[v][u] = cs;
            graph[u].pb(v);
            graph[v].pb(u);
        }
        else
        {
            if(cost[u][v]>cs) cost[u][v] = cs,cost[v][u] = cs;
        }
    }

    for(int i=1; i<n; i++)
    {
        dikjstra(i);
    }

    double tot = 0.0;
    ll cnt = 0;
    for(int i=1; i<=n; i++)
    {
        for(int j=i+1; j<=n; j++)
        {
            //cout<<diss[i][j]<<" "<<edge[i][j]<<endl;
            tot += (edge[i][j] * 1.0);
            cnt ++;
        }
    }//out(tot);
    pf("%.17f\n", (tot/(cnt * 1.0)));

    return 0;
}