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
#define loop1(var,start,till)    for(int var=start; var<=till; var++)
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

string str[503];
int par[507];

struct ST
{
    int i,j,cst;

    bool operator <(const ST & x)const
    {
        return cst < x.cst;
    }
};
vector <ST> vv;

int findpar(int p)
{
    if(par[p] == p) return p;
    else return par[p] = findpar(par[p]);
}

int calc(string a,string b)
{
    int len = a.length(),cst = 0;

    for(int i=0; i<len; i++)
    {
        int cura = a[i] - '0';
        int curb = b[i] - '0';

        if(cura>curb) swap(cura,curb);

        int curcst = curb - cura;//cout<<cura<<" "<<curb<<endl;
        curcst = min(curcst,10-curcst);

        cst += curcst;
    }

    return cst;
}

int mst(int n)
{//out("here");
    sort all(vv);
    for(int i=0; i<=n; i++) par[i] = i;

    int tot = 0,cnt = 0,flag = 0;

    for(int i=0; i<vv.size(); i++)
    {
        int u = vv[i].i;
        int v = vv[i].j;
        int cst = vv[i].cst;

        int paru = findpar(u);
        int parv = findpar(v);
;
        if(paru != parv)
        {
            if(u == 0 || v == 0)
            {
                if(flag) continue;
                else flag = 1;
            }
            par[paru] = parv;
            tot += cst;//cout<<u<<" "<<v<<" "<<cst<<endl;
            cnt++;
            if(cnt == n) break;
        }
    }
    return tot;
}

int main()
{//out(calc("0000","0909"));
    int tc,n;
    ST get;

    sf(tc);

    loop1(tt,1,tc)
    {
        sf(n);

        vv.clear();

        str[0] = "0000";
        loop1(i,1,n) cin>> str[i];

        for(int i=0; i<=n; i++)
        {
            for(int j=i+1; j<=n; j++)
            {
                get.i = i;
                get.j = j;
                get.cst = calc(str[i],str[j]);//cout<<i<<" "<<j<<" "<<get.cst <<endl;
                vv.pb(get);
            }
        }
//out("mmk");
        int res = mst(n);

        pf("%d\n",res);
    }

    return 0;
}