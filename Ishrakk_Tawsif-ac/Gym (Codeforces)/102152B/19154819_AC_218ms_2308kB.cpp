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
#define left(n)                 (n<<1)
#define right(n)                ((n<<1) + 1)
#define fast                    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define PI                      acos(-1)
#define bitOff(N,in)            (N&(~(1LL<<(in))))
#define bitOn(N,in)             (N|(1LL<<(in)))
#define ull                     unsigned long long
#define eps                     .000000001

#define mx                      200005
#define mod                     998244353

template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}
string tostring(ll res){string curstr="";if(!res) curstr += ((char)res + '0');while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}

/* ...........................................................................................................*/

int n,m,q;

struct st
{
    int u,v;

    bool operator < (const st & x)const
    {
        if(u == x.u) return v<x.v;
        else return u<x.u;
    }
};

vector <st> inp;

struct st2
{
    int u,v,sz;

    bool operator < (const st2 & x)const
    {
        if(sz == x.sz)
        {
            if(v == x.v) return u>x.u;
            else return v>x.v;
        }
        else return sz>x.sz;
    }
};

vector <st2> vv,ans;
int ansu[100005],ansv[100005];

int main()
{
    int tc;

    scanf("%d", &tc);

    for(int tt=1; tt<=tc; tt++)
    {
        scanf("%d %d %d", &n,&m,&q);

        int u,v,last = 1;
        st get;

        inp.clear();
        vv.clear();
        mem(ansu,-1);
        mem(ansv,-1);

        for(int i=1; i<=n; i++)
        {
            scanf("%d %d", &get.u,&get.v);
            inp.pb(get);
        }
        if(inp.size())sort all(inp);

        st2 get2;
        for(int i=0; i<inp.size(); i++)
        {
            u = inp[i].u;
            v = inp[i].v;

            if(last<u)
            {
                int fs = last;
                int sn = u-1;
                int sz = (sn - fs) + 1;

                get2.u = fs;
                get2.v = sn;
                get2.sz = sz;

                vv.pb(get2);
            }
            last = v+1;
        }

        if(last <= m)
        {
            int fs = last;
            int sn = m;
            int sz = (sn - fs) + 1;

            get2.u = fs;
            get2.v = sn;
            get2.sz = sz;

            vv.pb(get2);
        }

        if(vv.size())sort all(vv);

        int ind = 0;
        for(int i=m; i>=1 && vv.size(); i--)
        {
            int curu = -1,curv = -1;

            if(i != m)
            {
                curu = ansu[i+1];
                curv = ansv[i+1];
            }

            if(vv[ind].sz>=i)
            {
                if(curv<vv[ind].v)
                {
                    curu = vv[ind].u;
                    curv = vv[ind].v;
                }
            }

            while(ind+1<vv.size() && vv[ind+1].sz>=i)
            {
                if(curv<vv[ind].v)
                {
                    curu = vv[ind].u;
                    curv = vv[ind].v;
                }//cout<<i<<".. "<<ind<<" "<<vv[ind].sz<<endl;
                ind++;
            }

            if(vv[ind].sz>=i)
            {
                if(curv<vv[ind].v)
                {
                    curu = vv[ind].u;
                    curv = vv[ind].v;
                }
            }

            ansu[i] = curu;
            ansv[i] = curv;
        }//out("here");

        while(q--)
        {
            scanf("%d", &u);

                if(ansu[u] == -1 && ansv[u] == -1) {printf("-1 -1\n"); continue;}

                int st = ansv[u] - u + 1;
                printf("%d %d\n", st,ansv[u]);
        }

    }

    return 0;
}


/*
5
1 5 5
1 5
1
2
3
4
5
*/