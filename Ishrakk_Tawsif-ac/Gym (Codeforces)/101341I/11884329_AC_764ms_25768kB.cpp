#include<bits/stdc++.h>
using namespace std;

int dx[8]={0,0,1,-1,1,1,-1,-1};
int dy[8]={1,-1,0,0,1,-1,1,-1};

#define sf(nn)                  scanf ("%d", &nn)
#define sfll(nn)                scanf ("%lld", &nn)
#define pf                      printf
#define casepf(nn)              printf ("Case %d:\n",nn)
#define out(nn)                 cout <<nn <<endl
#define loop(var,start,till)    for(int var=start; var<till; var++)
#define pb                      push_back
#define mem(a,b)                memset(a,b,sizeof(a))
#define mp                      make_pair
#define ll                      long long int
#define inf                     2e9
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      5000005
#define mod                     1000000007

ll a[1005][1005],b[1005][1005],c[1005][1005],randar[1005],temp1[1005],temp2[1005],temp3[1005];

int main()
{
    int n;

    sf(n);

    for(int i=0; i<n; i++) for(int j=0; j<n; j++) scanf("%lld", &a[i][j]);
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) scanf("%lld", &b[i][j]);
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) scanf("%lld", &c[i][j]);

    for(int i=0; i<n; i++) randar[i] = rand()%mod;
//randar[0][0] = 3; randar[1][0] = 4;
    /// b * randar

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            temp1[i] += ((b[i][j]%mod) * (randar[j]%mod))%mod;
            temp1[i] = temp1[i]%mod;
        }
    }


    /// a * (b*randar)

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            temp2[i] += ((a[i][j]%mod) * (temp1[j]%mod))%mod;
            temp2[i] = temp2[i]%mod;
        }
    }

    ///c*randar

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            temp3[i] += ((c[i][j]%mod) * (randar[j]%mod))%mod;
            temp3[i] = temp3[i]%mod;
        }
    }
//for(int i=0; i<n; i++) cout<<temp3[i][0]<<endl;

    int fl = 1;

    for(int i=0; i<n; i++) if(temp2[i] != temp3[i]) fl=0;

    fl? pf("YES\n") : pf("NO\n");

    return 0;
}