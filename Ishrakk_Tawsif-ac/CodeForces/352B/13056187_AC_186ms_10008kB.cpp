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
#define mx                      100005
#define mod                     1000000007

template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}

string tostring(ll res){string curstr="";while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}


/* ...........................................................................................................*/


int ar[100005],last[100005],cnt[100005];
set <int> st[100005];
vector <int> vv;

struct ST
{
    int fs,sn;
    bool operator <(const ST & x) const
    {
        return fs<x.fs;
    }
};

vector<ST> res;

int main()
{
    int n;

    mem(last,-1);
    sf(n);

    for(int i=1; i<=n; i++)
    {
        sf(ar[i]);
        //if(last[ar[i]] != -1) vv.pb(ar[i]);
        if(last[ar[i]] != -1)
        {
            int temp = i - last[ar[i]];
            st[ar[i]].insert(temp);
        }
        last[ar[i]] = i;
        cnt[ar[i]] ++;
    }

    ST get;
    int vis[100005];
    mem(vis,0);
    for(int i=1; i<=n; i++)
    {
        int cur = ar[i];
        if(vis[cur]) continue;
        vis[cur] = 1;
        if(st[cur].size() == 1)
        {
            int now = *st[cur].begin();
            get.fs = cur;
            get.sn = now;
            res.pb(get);
        }
        else if(cnt[cur] == 1) get.fs = cur,get.sn = 0,res.pb(get);//cout<<cur<<" "<<cnt[cur]<<endl;
    }
    out(res.size());
    sort(res.begin(),res.end());
    for(int i=0; i<res.size(); i++) pf("%d %d\n", res[i].fs,res[i].sn);

    return 0;
}