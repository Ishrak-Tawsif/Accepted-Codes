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
    int n,temp;

        sf(n);

        for(int i=0; i<n; i++) {sf(aa[i]); vis[aa[i]]++;}
        for(int i=0; i<n; i++) sf(bb[i]);
            /*{
                if(aa[i] == bb[i]) {vis[aa[i]]=1; ans[i] = arr[i];}
            }*/
                for(int i=1; i<=n; i++) if(!vis[i]) temp=i;
                for(int i=0; i<n; i++)
                {
                    if(vis[aa[i]] == 2)
                    {
                        int cur = aa[i];
                        aa[i] = temp;

                            ///checking
                            int cnt=0;
                                for(int i=0;i <n; i++)
                                {
                                    if(aa[i] != bb[i]) cnt++;
                                }
                            if(cnt == 1) break;
                            else aa[i] = cur;
                    }
                }
                cout<<aa[0];
                for(int i=1; i<n; i++) cout<<" "<<aa[i];

    return 0;
}