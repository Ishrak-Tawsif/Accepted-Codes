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
#define intinf                  2100000000
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())

int tr[1005],ans[1005],aa[1005],bb[1005],vis[1005];

int main()
{
    int n,m,arr[100005];

        sf(n);
        sf(m);

            loop(i,0,n)sf(arr[i]);

                int u,v,x;

                    loop(i,0,m)
                    {
                        scanf("%d %d %d", &u,&v,&x);
                        int cnt=0;
                        u--;
                        v--;
                        x--;

                            for(int j=u; j<=v; j++)if(arr[j]<arr[x]) cnt++;

                            int new_pos = u+cnt;
                            //cout<<cnt<<" " << new_pos<<endl;
                            if(arr[new_pos] == arr[x]) pf("Yes\n");
                            else pf("No\n");
                    }
    return 0;
}