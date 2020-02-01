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
#define mx                      205
#define mod                     1000000007

template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}

string tostring(ll res){string curstr="";while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}

/* ...........................................................................................................*/

map <string,int> id;
int n,dp[mx][2],flag[mx][2];
vector <int> graph[mx];

int call(int node,int taken/*,int sum*/)
{
    if(dp[node][taken]/*[sum]*/ != -1) return dp[node][taken]/*[sum]*/;

    int ans = 0;

    if(!taken)
    {
        int ans1=0,ans2=0;
        flag[node][0] = flag[node][1] = 1;
        for(int i=0; i<graph[node].size(); i++)
        {
            int vv = graph[node][i];
            ans1 = call(vv,1);
            ans2 = call(vv,0);
            ans += max(ans1,ans2);

            if(ans1 == ans2) flag[node][0] = flag[node][1] = 0;
            else if(ans1<ans2) if(flag[vv][0] == 0) flag[node][0] = 0;
            else {if(flag[vv][1] == 0) flag[node][0] = 0;}
        }
    }
    else
    {
        ans = 1;
        flag[node][1] = 1;
        for(int i=0; i<graph[node].size(); i++)
        {
            int vv = graph[node][i];
            ans += call(vv,0);
            if(flag[vv][0] == 0) flag[node][1] = 0;
        }//cout<<ans<<endl;
    }
    //cout << node << " " << taken << " " << ans <<endl;
    return dp[node][taken]/*[sum]*/ = ans;
}

int main()
{//WRITE("in.txt");
    int curid = 0;
    string u,v;
    while(sf(n) && n)
    {
    //sf(n);
        mem(flag,0);
        curid = 0;
        for(int i=0; i<mx; i++) graph[i].clear();
        id.clear();

        cin>> u;
        id[u] = ++curid;//cout<<id[u]<<endl;system("pause");

        for(int i=1; i<=n-1; i++)
        {
            cin>>u >>v;
            if(!id[u]) id[u] = ++curid;
            if(!id[v]) id[v] = ++curid;
            graph[id[v]].pb(id[u]);
        }
        //out(curid);
        //system("pause");
        //graph[0].pb(1);
        mem(dp,-1);
        int res = call(1,0); /// ke,nici,koyta
        int res2 = call(1,1);
        cout << max(res,res2) <<" ";

        if(res == res2) cout<<"No\n";
        else if(res>res2)
        {
            flag[1][0]? cout<<"Yes\n" : cout<<"No\n";
        }
        else flag[1][1]? cout<<"Yes\n" : cout<<"No\n";
        //cnt == 1? cout<<"Yes\n" : cout<<"No\n";
    }
    return 0;
}