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
#define intinf                  2e9
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      100005
#define mod                     100000007


int dr8[]={-1,-1,0,1,1,1,0,-1};
int dc8[]={0,1,1,1,0,-1,-1,-1};


struct S
{
    int a,b;

        bool operator <(const S &x) const
        {
            return a<x.a;
        }
};

vector <S> vv;

int main()
{
    int n;
    S get;
        sf(n);
        for(int i=0; i<n; i++)
        {
            scanf("%d %d", &get.a,&get.b);
            vv.pb(get);
        }
        sort(vv.begin(),vv.end());
        //for(int i=0; i<vv.size(); i++) cout<<vv[i].a << " " << vv[i].b << endl;

        int ans=0,cur=vv[0].b;

        for(int i=0; i<n; i++)
        {
            if(vv[i].b<cur) ans++;
            else cur=vv[i].b;
        }
        pf("%d\n", ans);
    return 0;
}