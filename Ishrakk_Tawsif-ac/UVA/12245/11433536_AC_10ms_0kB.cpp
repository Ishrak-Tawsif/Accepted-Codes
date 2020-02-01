#include<bits/stdc++.h>
using namespace std;

#define sf(nn)                  scanf ("%d", &nn)
#define sfll(nn)                scanf ("%lld", &nn)
#define pf                      printf
#define casepf(nn)              printf ("Case %d: ",nn)
#define out(nn)                 cout <<nn <<endl
#define loop(var,start,till)    for(int var=start; var<till; var++)
#define pb                      push_back
#define mem(a,b)                memset(a,b,sizeof(a))
#define mp                      make_pair
#define ll                      long long int
#define inf                     1e9
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      100000+5
#define mod                     100000000


int dx[8]={0,0,1,-1,1,1,-1,-1};
int dy[8]={1,-1,0,0,1,-1,1,-1};

int ans[105][105],n,m;
pair <int,int> ar[105];

struct ST
{
    int l,r;

    bool operator <(const ST & x)const
    {
        return r<x.r;
    }
};
vector <ST> vv;

int main()
{//WRITE("in.txt");

    ST get;
    while(scanf("%d %d", &m,&n))
    {
        if(!n && !m) break;

        vv.clear();

        for(int i=0; i<n; i++)
        {
            scanf("%d %d", &get.l, &get.r);
            vv.pb(get);
        }
        sort(vv.begin(),vv.end());

        mem(ans,0);
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                if(vv[i].l !=0) continue;
                if(vv[i].l>=vv[j].l) continue;
                if(vv[i].r>=vv[j].r) continue;
                if(vv[i].r<vv[j].l) continue;

                ans[i][j] ++;
            }
        }

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<i; j++)
            {
                if(!ans[j][i]) continue;
                for(int k=i+1; k<n; k++)
                {
                    if(vv[k].l<=vv[j].r) continue;
                    if(vv[k].l>vv[i].r) continue;
                    if(vv[i].r>=vv[k].r) continue;
                    ans[i][k] = (ans[i][k]+ans[j][i])%mod;
                }
            }
        }

        int res = 0;
        for(int i=0; i<n; i++)
        {
            if(vv[i].l == 0 && vv[i].r == m) res++;
        }

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(vv[j].r == m) res = ((res+(ans[i][j]%mod)))%mod;
            }
        }
        pf("%d\n", res);
    }
    return 0;
}