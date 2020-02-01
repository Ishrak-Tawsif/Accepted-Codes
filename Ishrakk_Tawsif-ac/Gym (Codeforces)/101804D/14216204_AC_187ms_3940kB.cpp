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
#define mod                     1000000007
#define left(n)                 (n<<1)
#define right(n)                ((n<<1) + 1)
#define fast                    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define PI                      acos(-1)
#define ull                     unsigned long long

template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}
string tostring(ll res){string curstr="";while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}


/* ...........................................................................................................*/

double ar[mx],sum[4*mx];

struct seg
{
    void build(int node,int L,int R)
    {
        sum[node] = 0;

        if(L == R)
        {
            sum[node] = ar[L];
            return;
        }

        int mid = (L + R) / 2;
        int lf = left(node);
        int rt = right(node);

        build(lf, L , mid);
        build(rt, mid + 1, R);

        sum[node] = sum[lf] + sum[rt];
    }

    void update(int node,int L,int R,int pos,double u)
    {
        if(pos<L || R<pos) return;

        if(L == R)
        {
            sum[node] = u;
            return;
        }

        int mid = (L + R) / 2;
        int lf = left(node);
        int rt = right(node);

        if(pos<=mid) update(lf,L,mid,pos,u);
        else update(rt,mid+1,R,pos,u);

        sum[node] = sum[lf] + sum[rt];
    }

    double query(int node,int L,int R,int l,int r)
    {
        if(r<L || R<l) return 0.0;
        if(l<=L && R<=r) return sum[node];

        int mid = (L + R) / 2;
        int lf = left(node);
        int rt = right(node);

        double x = query(lf,L,mid,l,r);
        double y = query(rt,mid+1,R,l,r);

        return (x + y);
    }
};

int main()
{
    //fast;

    int n,q,l,r,tp;
    double val;

    scanf("%d", &n);

    for(int i=1; i<=n; i++) scanf("%lf", &ar[i]);

    seg get;
    get.build(1,1,n);

    sf(q);

    while(q--)
    {
        sf(tp);
        if(tp == 1)
        {
            scanf("%d", &l);
            scanf("%lf",&val);
            get.update(1,1,n,l,val);
        }
        else
        {
            scanf("%d %d", &l,&r);
            double res = get.query(1,1,n,l,r);
            res = res / ((r-l+1)*1.0);

            pf("%.6f\n",res);
        }
    }

    return 0;
}