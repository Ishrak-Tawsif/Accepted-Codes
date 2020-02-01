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

int ar[207],diss[207],vis[207];
vector <int> graph[207];

int cube(int a,int b)
{
    a = (a-b);
    return a*a*a;
}

int dikjstra()
{

    for(int i=0; i<207; i++) vis[i] = 0, diss[i] = 2e9;

    set <pair<int,int> > st;
    st.insert(mp(0,1));
    diss[1] = 0;


    while(!st.empty())
    {
        pair <int,int> temp = *st.begin();
        st.erase(st.begin());

        int cst = temp.first;
        int u = temp.second;//cout<<u<<" ... "<<cst<<endl;

        for(int i=0; i<graph[u].size(); i++)
        {
            int v = graph[u][i];

            if(!vis[v])
            {
                vis[v] = 1;
                diss[v] = cst + cube(ar[v],ar[u]);
                st.insert(mp(diss[v],v));
            }
            else if(diss[v]>(cst + cube(ar[v],ar[u])) && diss[v]>=-10000)
            {
                diss[v] = cst + cube(ar[v],ar[u]);
                st.insert(mp(diss[v],v));
            }
        }
    }
}

int main()
{//WRITE("in.txt");
    int tc,n,m,u,v,q,ds;
    sf(tc);
    for(int tt = 1; tt<=tc; tt++)
    {
        sf(n);

        for(int i=0; i<207; i++) graph[i].clear();
        for(int i=1; i<=n; i++) sf(ar[i]);

        sf(m);
        for(int i=0; i<m; i++)
        {
            scanf("%d %d", &u,&v);
            graph[u].pb(v);
        }

        dikjstra();

        casepf(tt);

        sf(q);

        while(q--)
        {
            sf(ds);//out("ok");
            if(diss[ds]>=3 && diss[ds] != 2e9) pf("%d\n", diss[ds]);
            else pf("?\n");
        }
    }

    return 0;
}