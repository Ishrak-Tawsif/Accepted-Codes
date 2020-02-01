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


int main()
{
  int n,lw=0,rt=0,lf=0,up=0,cnt=0;
  int arr[203][203];

    //sf(tc);

       sf(n);
       for(int i=1; i<=n; i++)
       {
           scanf("%d %d", &arr[i][0], &arr[i][1]);
       }

            for(int i=1; i<=n; i++)
            {
                lw=0,rt=0,lf=0,up=0;

                for(int j=1; j<=n; j++)
                {
                    if(arr[j][0]>arr[i][0] && arr[j][1] == arr[i][1]) rt++;
                    if(arr[j][0]<arr[i][0] && arr[j][1] == arr[i][1]) lf++;
                    if(arr[j][0] == arr[i][0] && arr[j][1]<arr[i][1]) lw++;
                    if(arr[j][0] == arr[i][0] && arr[j][1]>arr[i][1]) up++;
                }
                if(rt>=1 && lf>=1 && lw>=1 && up>=1) cnt++;
            }

        pf("%d\n",cnt);
}