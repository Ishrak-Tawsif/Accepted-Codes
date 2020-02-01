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
#define mx                      1000000+25
#define mod                     1000000007

template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}

string tostring(ll res){string curstr="";while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}

/* ...........................................................................................................*/


int cnt,k,vis[1005];
vector<int>graph[1005];

//int call(int node)
//{cout<<node<<" "<<graph[node].size()<<endl;
//    if(graph[node].size() == 0)
//    {out(node);
//        return 1;
//    }
//    if(dp[node] != -1) return dp[node];
//
//    int ans = 0;
//
//    for(int i=0; i<graph[node].size(); i++)
//    {
//        int v = graph[node][i];out(v);
//        ans += call(v);
//    }out(ans);
//    if(ans>=3) cnt += 3;
//
//    return dp[node] = (ans>=3);
//}


int dfs(int cur,int par)
{//out(cur);
    vis[cur] = 1;
    if(cur == 1 && graph[cur].size()<k) return 1;

    ///all node without root should have at least 3 child without int parent
    ///as tree is biderectional so parent of any node will also be in its child list
    else if(cur != 1 && graph[cur].size()-1<k) return 1;

    vector <int> childs;

    for(int i=0; i<graph[cur].size(); i++)
    {
        int v = graph[cur][i];

        if(v != par)
        {
            int now = dfs(v,cur);
            childs.pb(now);
        }
    }

    int cnt = 0,tot=1;
    sort all(childs);
    for(int i=childs.size()-1; i>=0; i--)
    {
        if(cnt == k) break;
        cnt++;
        tot += childs[i];//if(cur == 1) cout<<" 1111 " << tot<<endl;
    }
    //cout<<cur<<" /// "<<tot<<endl;
    return tot;
}

int main()
{//WRITE("out.txt");
    int n,tc,u,v;

    sf(tc);

    for(int tt=1; tt<=tc; tt++)
    {
        cnt = 0;
        for(int i=0; i<1005; i++) graph[i].clear(),vis[i] = 0;

        scanf("%d %d", &n,&k);

        for(int i=1; i<n; i++)
        {
            scanf("%d %d", &u,&v);
            graph[u].pb(v);
            graph[v].pb(u);
        }
        casepf(tt);
        out(dfs(1,-1));
    }

    return 0;
}