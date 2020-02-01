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
#define mx                      30005
#define mod                     1000000007

template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}

string tostring(ll res){string curstr="";while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}


/* ...........................................................................................................*/

int ar[mx],n,tree[4*mx];

struct segmenttree
{
    void build(int node,int bg,int en)
    {
        if(bg == en)
        {
            tree[node] = ar[bg];
            return;
        }

        int mid = (bg + en)>> 1;
        int lf = node<<1;
        int rt = lf | 1;

        build(lf,bg,mid);
        build(rt,mid+1,en);

        tree[node] = min(tree[lf],tree[rt]);
    }

    int query(int node,int bg,int en,int i,int j)
    {
        if(i>en || j<bg) return 2e9;
        if(i<=bg && j>=en)
        {
            return tree[node];
        }

        int mid = (bg + en)>> 1;
        int lf = (node<<1);
        int rt = lf | 1;

        int x = query(lf,bg,mid,i,j);
        int y = query(rt,mid+1,en,i,j);

        return min(x,y);
    }
};

int bs1(int val,int ind)
{
    segmenttree get;
    int st = ind,en = n,mid,res = -1;
    if(ar[ind]<val) return -1;
    while(st<=en)
    {
        mid = (st + en)>> 1;

        int now = get.query(1,1,n,ind-1,mid);
        if(now == val)
        {
            res = mid;
            st = mid + 1;
        }
        else en = mid - 1;
    }

    return res;
}

int bs2(int val,int ind)
{
    segmenttree get;
    int st = 1,en = ind,mid,now,res = -1;
    if(ar[ind]<val) return -1;
    while(st<=en)
    {
        mid = (st + en)>> 1;
        now = get.query(1,1,n,mid,ind+1);//cout<<"now "<<now<<endl;
        if(now == val)
        {
            res = mid;
            en = mid-1;
        }
        else st = mid + 1;
    }

    return res;
}

int main()
{//WRITE("in.txt");
    int tc,ans;
    segmenttree get;
    sf(tc);

    for(int tt=1; tt<=tc; tt++)
    {
        sf(n);
        for(int i=1; i<=n; i++) scanf("%d", &ar[i]);

        get.build(1,1,n);

        ans = 0;
        for(int i=1; i<=n; i++)
        {
            int ind1 = bs1(ar[i],i+1);
            int ind2 = bs2(ar[i],i-1);

            if(ind1 == -1) ind1 = i;
            if(ind2 == -1) ind2 = i;

            int segsz = ((ind1-ind2)+1);
            segsz *= ar[i];

            ans = max(ans,segsz);
        }
        casepf(tt);
        pf("%d\n", ans);
    }

    return 0;
}