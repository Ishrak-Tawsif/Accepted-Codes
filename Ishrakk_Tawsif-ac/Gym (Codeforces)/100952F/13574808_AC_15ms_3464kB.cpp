///>>>>>>>>>>>>>>>>>>>>

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
#define casepf(nn)              printf ("Case #%d: ",nn)
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
#define flush                   fflush(stdout)

template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}

string tostring(ll res){string curstr="";while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}

/* ...........................................................................................................*/

string a,b,c;
int dis[305], vis[305];
map <string,int> mpp;
map<int,string> name;
vector <int>graph[305];
vector <pair<int,string> > ans;
int bfs()
{
    queue <int> qq;
    qq.push(1);
    int cnt = 0;
    dis[1] = 0;
    vis[1] = 1;
    for(int i=2; i<305;i++) dis[i] = 2e9;
    while(!qq.empty())
    {
        int cur = qq.front(); qq.pop();

        for(int i=0; i<graph[cur].size(); i++)
        {
            int now = graph[cur][i];
//cout<<cur<<" "<<now<<endl;
            if(!vis[now])
            {
                vis[now] = 1;
                dis[now] = dis[cur] + 1;
                qq.push(now);
                cnt++;//out(now);
            }
        }
    }
    return cnt;
}

int main()
{

    int tc,n;

    sf(tc);

    while(tc--)
    {
        sf(n);
        name.clear();
        mpp.clear();
        mem(vis,0);
        mpp["Ahmad"] = 1;
        name[1] = "Ahmad";
        int id = 1;
        for(int i=0; i<305; i++) graph[i].clear();

        for(int i=0; i<n; i++)
        {
            cin>> a>> b>> c;
            if(mpp[a] == 0) mpp[a] = ++id,name[id] = a;
            if(mpp[b] == 0) mpp[b] = ++id,name[id] = b;
            if(mpp[c] == 0) mpp[c] = ++id,name[id] = c;

            graph[mpp[a]].pb(mpp[b]);
            graph[mpp[a]].pb(mpp[c]);
            graph[mpp[b]].pb(mpp[a]);
            graph[mpp[b]].pb(mpp[c]);
            graph[mpp[c]].pb(mpp[a]);
            graph[mpp[c]].pb(mpp[b]);//cout<<mpp[a]<<" "<<mpp[b]<<" "<<mpp[c]<<endl;
        }
        //for(int i=1; i<=13; i++) cout<<i<<" "<<graph[i].size()<<endl;
        int res = bfs(); //cout<<" "<<res<<"...\n";
        pf("%d\n", id);

        for(int i=1; i<=id; i++)
        {
            ans.pb(mp(dis[i],name[i]));
        }
        sort all(ans);
        for(int i=0; i<ans.size(); i++)
        {
            if(ans[i].first == 2e9) cout<<ans[i].second<<" "<< "undefined\n";
            else cout<<ans[i].second<<" "<<ans[i].first<<endl;
        }ans.clear();
    }
    return 0;
}