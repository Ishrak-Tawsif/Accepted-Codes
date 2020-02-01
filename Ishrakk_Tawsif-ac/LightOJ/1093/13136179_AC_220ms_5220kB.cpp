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

int tree[4*mx],tree2[4*mx],ar[mx];

struct segmenttree1
{
    void build(int node,int bg,int en)
    {//cout<<bg<<" "<<en<<endl;
        if(bg == en) {tree[node] = ar[bg]; return;}

        int lf = (node<<1);
        int rt = lf | 1;
        int mid = (bg + en)>>1;

        build(lf,bg,mid);
        build(rt,mid+1,en);

        tree[node] = min(tree[lf],tree[rt]);
    }

    int query(int node,int bg,int en,int i,int j)
    {
        if(j<bg || i>en) return 2e9;
        if(i<=bg && j>=en) return tree[node];

        int lf = (node<<1);
        int rt = lf | 1;
        int mid = (bg + en)>>1;

        int left = query(lf,bg,mid,i,j);
        int right = query(rt,mid+1,en,i,j);

        return min(left,right);
    }
};

struct segmenttree2
{
    void build(int node,int bg,int en)
    {
        if(bg == en) {tree2[node] = ar[bg]; return;}

        int lf = (node<<1);
        int rt = lf | 1;
        int mid = (bg + en)>>1;

        build(lf,bg,mid);
        build(rt,mid+1,en);

        tree2[node] = max(tree2[lf],tree2[rt]);
    }

    int query(int node,int bg,int en,int i,int j)
    {
        if(j<bg || i>en) return -2e9;
        if(i<=bg && j>=en) return tree2[node];

        int lf = (node<<1);
        int rt = lf | 1;
        int mid = (bg + en)>>1;

        int left = query(lf,bg,mid,i,j);
        int right = query(rt,mid+1,en,i,j);

        return max(left,right);
    }
};

int main()
{//WRITE("loj1.txt");
    int tc,n,d;
    segmenttree1 get1;
    segmenttree2 get2;

    sf(tc);

    for(int tt=1; tt<=tc; tt++)
    {
        scanf("%d %d", &n,&d);
        for(int i=1; i<=n; i++) scanf("%d", &ar[i]);
        get1.build(1,1,n);//out("ok1");
        get2.build(1,1,n);//out("ok2");

        int res = -1;
        if(n == d)
        {
            int mini = get1.query(1,1,n,1,n);
            int maxi = get2.query(1,1,n,1,n);
            int now = maxi - mini;
            res = max(res,now);
        }
        else
        {
            for(int i=1; i+d-1<=n; i++)
            {//out(i);
                int mini = get1.query(1,1,n,i,i+d-1);
                int maxi = get2.query(1,1,n,i,i+d-1);
                int now = maxi - mini;//cout<<maxi<<" "<<mini<<endl;
                res = max(res,now);
            }
        }
        pf("Case %d: %d\n", tt,res);
    }
    return 0;
}