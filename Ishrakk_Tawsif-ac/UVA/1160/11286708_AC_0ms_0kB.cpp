 #include<bits/stdc++.h>
using namespace std;

#define sf(nn)                  scanf ("%d", &nn)
#define sfll(nn)                scanf ("%lld", &nn)
#define pf                      printf
#define casepf(nn)              printf ("Case #%d\n",nn)
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
#define mx                      2000+5
#define mod                     1000000007

int par[100005];

int find_par(int p)
{
    if(par[p] == p) return p;
    return par[p] = find_par(par[p]);
}

int main()
{
    int u,v,cnt1=0,cnt2=0;

    for(int i=0; i<100005; i++) par[i] = i;
    while(sf(u) == 1)
    {
        if(u == -1)
        {
            pf("%d\n", (cnt1-cnt2));
            for(int i=0; i<100005; i++) par[i] = i;
            cnt1=0,cnt2=0;
            continue;
        }
        sf(v);

        int paru = find_par(u);
        int parv = find_par(v);

        cnt1++;

        if(paru != parv)
        {
            par[paru] = parv;
            cnt2++;
        }
    }
    return 0;
}