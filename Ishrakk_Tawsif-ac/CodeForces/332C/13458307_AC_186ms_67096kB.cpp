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
#define mx                      2000005
#define mod                     1000000007
#define flush                   fflush(stdout)

template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}

string tostring(ll res){string curstr="";while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}


/* ...........................................................................................................*/


struct ST
{
    int a,b,ind,nowind;
};

ST order[mx],temp[mx];

bool log1 (const ST &x, const ST &y)
{
    if(x.b == y.b) return (x.a>y.a);
    else return x.b<y.b;
}

bool cmp (const ST &x, const ST &y)
{
    if(x.a == y.a) return (x.nowind>y.nowind);
    else return x.a>y.a;
}

vector <int>vv;

int main()
{
    int n,p,k;

    scanf("%d %d %d", &n,&p,&k);

    for(int i=1; i<=n; i++)
    {
        scanf("%d %d", &order[i].a,&order[i].b);
        order[i].ind = i;
    }
    sort(order+1,order+n+1,log1);

    for(int i=1; i<=n; i++)
    {
        order[i].nowind = i;
        temp[i].a = order[i].a;
        temp[i].b = order[i].b;
        temp[i].ind = order[i].ind;
        temp[i].nowind = order[i].nowind;
    }

    int baki = p - k;

    sort(order+baki+1,order+n+1,cmp);

    int mini = 2e9;

    for(int i=1; i<=k; i++)
    {
        vv.pb(order[i+baki].ind);
        mini = min(mini,order[i+baki].nowind);
    }
    int now = mini - 1;
    for(int i=1; i<=baki; i++,--now)
    {
        vv.pb(temp[now].ind);//cout<<temp[now].ind<<" "<<now<<endl;
        //now--;
    }

    for(int i=0; i<vv.size(); i++)
    {
        if(i == 0) pf("%d", vv[i]);
        else pf(" %d",vv[i]);
    }
    pf("\n");
    return 0;
}