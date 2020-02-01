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
#define mx                      5005
#define mod                     100000007
#define intinf                  2e9
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())


int dr8[]={-1,-1,0,1,1,1,0,-1};
int dc8[]={0,1,1,1,0,-1,-1,-1};


int main()
{
    vector <int>v1,v2,v11,v22;
    int n,u,v,m;
        sf(n);

            loop(i,0,n)
            {
                scanf("%d %d", &u,&v);
                v1.pb(v);
                v11.pb(u);
            }

            sf(m);
            loop(i,0,m)
            {
                scanf("%d %d", &u,&v);
                v2.pb(u);
                v22.pb(v);
            }

            sort(v1.begin(),v1.end());
            sort(v11.begin(),v11.end());
            sort(v2.begin(),v2.end());
            sort(v22.begin(),v22.end());

            int ans = max(0,v2[m-1]-v1[0]);
            ans = max(ans,v11[n-1]-v22[0]);
            cout<<ans<<endl;
    return 0;
}