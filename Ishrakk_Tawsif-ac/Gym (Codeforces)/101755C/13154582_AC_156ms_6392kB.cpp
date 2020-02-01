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

struct ST
{
    int s,e;

    bool operator <(const ST & x) const
    {
        if(s == x.s) return e<x.e;
        return s<x.s;
    }
};
vector <ST> vv;

int main()
{
    int n;
    ST get;

    scanf("%d", &n);

    for(int i=0; i<n; i++)
    {
        scanf("%d %d", &get.s,&get.e);
        vv.pb(get);
    }
    sort all(vv);
    //for(int i=0; i<vv.size(); i++) cout<<vv[i].s<<" "<<vv[i].e<<endl;
    int now = vv[0].e;
    stack <int> q;
    q.push(now);

    for(int i=1; i<vv.size(); i++)
    {
        //if(now>=vv[i].s && now<vv[i].e) continue;
        if(vv[i].s<=now)
        {
            if(vv[i].e<now)
            {
                now = vv[i].e;
                q.pop();
                q.push(now);
            }
            continue;
        }
        now = vv[i].e;
        q.push(now);

    }

    pf("%d\n", q.size());
    int fl = 0;
    while(!q.empty())
    {
        int temp = q.top(); q.pop();
        if(!fl)pf("%d", temp),fl = 1;
        else pf(" %d", temp);
    }
    pf("\n");
    return 0;
}