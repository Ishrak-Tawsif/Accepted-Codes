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

int n,p,m,g,t,lim;
int pl[17],timespend[20005];
unordered_map <int,int> idd;

struct st
{
    int v,tm;
};

vector <st> graph[20005];
int vis[17][20005],dis[17][20005],dp[17][1<<17],dp2[17][1<<17][2];

void dikjstra(int sr,int id)
{
    multiset <pair<int,int> > st;
    st.insert(mp(0,sr));
    vis[id][sr] = 1;
    dis[id][sr] = 0;


    while(!st.empty())
    {
        pair <int,int> temp = * st.begin();
        st.erase(st.begin());

        int cstu = temp.first;
        int u = temp.second;
        vis[id][u] = 0;
//if(sr == 5) cout<<u<<" |||| "<<cstu<<endl;
        for(auto x : graph[u])
        {//if(u == 3) cout<<" 3 : " << x.v<<endl;
            int v = x.v;
            int cst = x.tm;

            if(dis[id][v]>dis[id][u]+cst)
            {
                dis[id][v] = dis[id][u] + cst;
                if(!vis[id][v]) st.insert(mp(dis[id][v],v));
                vis[id][v] = 1;
                //cout<< sr <<" : " << v <<" " << dis[id][v] << endl;
            }
        }
    }
}

int tsp(int cityid,int mask)
{//out(mask);
    if(mask == lim)
    {
        int myid;
        if(!cityid) myid = p+1;
        else myid = cityid;
        return dis[myid][0];
    }
    if(dp[cityid][mask] != -1) return dp[cityid][mask];

    int ans = 1e9;
    for(int i=1; i<=p; i++)
    {
        if(!(mask & (1<<i)))
        {
            int myid;
            if(!cityid) myid = p+1;
            else myid = cityid;
            ans = min(ans,(tsp(i,mask | (1<<i)) + dis[myid][pl[i]] + timespend[pl[i]]));
        }
    }//out(ans);
    return dp[cityid][mask] = ans;
}

int tsp2(int cityid,int mask,int kinci)
{//out(mask);
    if(mask == lim)
    {
        int myid;
        if(!cityid) myid = p+1;
        else myid = cityid;
        if(!kinci)return min(dis[myid][0],t);
        else return dis[myid][0];
    }
    if(dp2[cityid][mask][kinci] != -1) return dp2[cityid][mask][kinci];

    int ans = 1e9;
    for(int i=1; i<=p; i++)
    {
        if(!(mask & (1<<i)))
        {
            int myid;
            if(!cityid) myid = p+1;
            else myid = cityid;
            ans = min(ans,(tsp2(i,mask | (1<<i),kinci) + dis[myid][pl[i]] + timespend[pl[i]]));
            if(!kinci)ans = min(ans,(tsp2(i,mask | (1<<i),1) + t + timespend[pl[i]]));
        }
    }//out(ans);
    return dp2[cityid][mask][kinci] = ans;
}


int main()
{
    scanf("%d %d %d %d %d", &n,&p,&m,&g,&t);

    int tm,tottm = 0;
    for(int i=1; i<=p; i++)
    {
        scanf("%d %d", &pl[i],&tm);
        timespend[pl[i]] = tm;
        tottm += tm;
    }

    st get;
    int u;

    for(int i=1; i<=m; i++)
    {
        scanf("%d %d %d", &u,&get.v,&get.tm);
        graph[u].pb(get);
        swap(u,get.v);
        graph[u].pb(get);
    }

    for(int i=0; i<=16; i++)
    {
        for(int j=0; j<20005; j++) dis[i][j] = 1e9;
    }

    for(int i=1; i<=p; i++)
    {
        idd[pl[i]] = i;
        dikjstra(pl[i],i);
    }

    dikjstra(0,p+1);

    lim = ((1<<(p+1)) - 1);//cout<<"lim: "<<lim<<endl;
    mem(dp,-1);
    int res1 = tsp(0,1) ;
    mem(dp2,-1);
    int res2 = tsp2(0,1,0) ;

   //out(res1);   //// out(res2);

    if(res1 <= g) printf  ("possible without taxi\n");
    else if(res2 <= g) printf("possible with taxi\n");
    else printf("impossible\n");

    return 0;
    
}