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
#define mx                      100005
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

set <int> st;
bool mark[200005];
vector <int> graph[100005],_list;
int vis[100005];
vector <pair<int,int> > qur[100005];

void dfs(int cur)
{//cout<<cur<<" /// "<<qur[cur].size()<<endl;
    vis[cur] = 1;
    if(!graph[cur].size())
    {//cout<<cur<<" --- : \n"; for(auto x : st) out(x);
        for(auto x : qur[cur])
        {
            int y = x.first;
            int ind = x.second;

            if(y == cur) {mark[ind] = 1; continue;}

            auto now = st.find(y);
            if(now == st.end()) continue;
            mark[ind] = 1;
        }
        return;
    }

    st.insert(cur);
    for(int i=0; i<graph[cur].size(); i++)
    {
        int now = graph[cur][i];
        if(!vis[now]) dfs(now);
    }

    //cout<<cur<<" --- : \n"; for(auto x : st) out(x);
    for(auto x : qur[cur])
    {
        int y = x.first;
        int ind = x.second;

        auto now = st.find(y);
        if(now == st.end()) continue;
        mark[ind] = 1;
    }//if(cur == 0) system("pause");
    st.erase(cur);
    return;
}

int main()
{
    int n,q,temp;

    scanf("%d %d", &n,&q);

    for(int i=0; i<=n-1; i++)
    {
        sf(temp);
        if(temp == -1) {_list.pb(i);continue;}
        graph[temp].pb(i);
    }

//    for(int i=0; i<n; i++)
//    {
//        sort all(par[i]);
//    }

    int x,y;

    for(int query = 1; query<=q; query++)
    {
        scanf("%d %d", &x, &y);
        qur[x].pb(mp(y,query));
    }

    for(int i=0; i<_list.size(); i++)
    {//out(_list[i]);
        dfs(_list[i]);
        while(!st.empty())st.erase(*st.begin());
    }

    for(int query = 1; query<=q; query++)
    {
        mark[query]? pf("Yes\n") : pf("No\n");
    }

    return 0;
}

/*
5 22
4 0 4 2 -1
1 4
0 4
2 4
3 4
4 4
1 1
0 0
0 1
4 4
2 2
3 3
4 0
4 1
2 3
4 2
4 3
1 2
0 2
2 1
2 0
3 1
3 0
yes
yes
yes
yes
yes
yes
yes

*/