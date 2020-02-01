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

int prop[4*mx],on[4*mx],off[4*mx];

void pushdown(int node)
{
    prop[node] = 0;
    prop[2*node] ^= 1;
    prop[(2*node)+1] ^= 1;
    swap(on[2*node],off[2*node]);
    swap(on[(2*node)+1],off[(2*node)+1]);
}

struct lazy
{
    void build(int node,int bg,int en)
    {
        prop[node] = 0;
        on[node] = 0;
        off[node] = (en-bg) + 1;

        if(bg == en) return;

        int mid = (bg + en)>> 1;
        build(2*node,bg,mid);
        build((2*node)+1,mid+1,en);
    }

    void update(int node,int i,int j,int bg,int en)
    {
        if(j<bg || i>en) return;
        if(i>=bg && j<=en)
        {
            swap(on[node],off[node]);
            prop[node] ^= 1;
            return;
        }

        if(prop[node]) pushdown(node);

        int mid = (i + j)>> 1;
        update(2*node,i,mid,bg,en);
        update((2*node)+1,mid+1,j,bg,en);

        on[node] = on[2*node] + on[(2*node)+1];
        off[node] = off[2*node] + off[(2*node)+1];
    }

    int query(int node,int i,int j,int bg,int en)
    {
        if(j<bg || i>en) return 0;
        if(i>=bg && j<=en)
        {
             return on[node];
        }
        if(prop[node]) pushdown(node);

        int mid = (i+j)>>1;

        int leftres = query(2*node,i,mid,bg,en);
        int rightres = query((2*node)+1,mid+1,j,bg,en);

        return leftres + rightres;
    }
};

int main()
{
    int n,q,tp,u,v;
    lazy get;

    scanf("%d %d", &n,&q);

    get.build(1,1,n);

    while(q--)
    {
        scanf("%d %d %d", &tp,&u,&v);
        if(!tp) get.update(1,1,n,u,v);
        else pf("%d\n", get.query(1,1,n,u,v));
    }
    return 0;
}