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
#define mod                     998244353
#define left(n)                 (n<<1)
#define right(n)                ((n<<1) + 1)
#define fast                    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define PI                      acos(-1)
#define bitOff(N,in)            (N&(~(1LL<<(in))))
#define bitOn(N,in)             (N|(1LL<<(in)))
#define ull                     unsigned long long
#define eps                     .000000001
#define mx                      1000005

template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}
string tostring(ll res){string curstr="";if(!res) curstr += ((char)res + '0');while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}

/* ...........................................................................................................*/

int blocksz = 450,ar[300005];

struct st
{
    int qry,l,r;

    bool operator <(const st & x)const
    {
        if(l/blocksz != x.l/blocksz) return l/blocksz<x.l/blocksz;
        else return r<x.r;
    }
};

vector <st> vv;
map <int,int> id;
int tempcnt[300005],cntercnt[300005],ans[300005];

int main()
{
    int n,q;

    scanf("%d %d", &n,&q);

    int val,curid = 0;
    for(int i=1; i<=n; i++)
    {
        sf(ar[i]);
        if(!id[ar[i]]) id[ar[i]] = ++curid;
    }

    st get;

    for(int i=1; i<=q; i++)
    {
        scanf("%d %d", &get.l,&get.r);
        get.qry = i;
        vv.pb(get);
    }

    sort all(vv);

    int curl = 1,curr = 0,res = 0;

    for(int i=0; i<vv.size(); i++)
    {
        int l = vv[i].l;
        int r = vv[i].r;

        while(curl>l)
        {
            curl--;
            val = ar[curl];
            int now = id[val];
            tempcnt[now] ++; /// koy din repeat hocche
            cntercnt[tempcnt[now]] ++; /// koyta tempcnt[now] bar repeat hocche
            if(tempcnt[now] == cntercnt[tempcnt[now]]) res++;
        }
        while(curr<r)
        {
            curr++;
            val = ar[curr];
            int now = id[val];
            tempcnt[now] ++;
            cntercnt[tempcnt[now]] ++;
            if(tempcnt[now] == cntercnt[tempcnt[now]]) res++;
            //curr ++;
        }
        while(curl<l)
        {//out("ok");
            val = ar[curl];
            int now = id[val];
            if(tempcnt[now] == cntercnt[tempcnt[now]]) res--;
            cntercnt[tempcnt[now]] --;
            tempcnt[now] --;
            curl ++;
        }
        while(curr>r)
        {
            val = ar[curr];
            int now = id[val];
            if(tempcnt[now] == cntercnt[tempcnt[now]]) res--;
            cntercnt[tempcnt[now]] --;
            tempcnt[now] --;
            curr--;
        }
        ans[vv[i].qry] = res;
    }

    for(int i=1; i<=q; i++) cout<<ans[i]<<endl;

    return 0;
}