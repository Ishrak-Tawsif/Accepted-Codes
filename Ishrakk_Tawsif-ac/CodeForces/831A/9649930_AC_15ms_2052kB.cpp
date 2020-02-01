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


int main()
{
    int arr[101],n;

        sf(n);

            loop(i,0,n) scanf("%d", &arr[i]);

                int in=0,dc=n-1;

                    for(int i=0; i<n-1; i++)
                    {
                        if(arr[i]<arr[i+1]) in++;
                        else break;
                    }
//cout<<in<<endl;
                    for(int i=in; i<n-1; i++)
                    {
                        if(arr[i] == arr[i+1]) in++;
                        else break;
                    }
//cout<<in<<endl;
                    for(int i=in; i<n-1; i++)
                    {
                        if(arr[i]>arr[i+1]) in++;
                        else break;
                    }
//cout<<in<<endl;
                    if(in==n-1) pf("YES\n");
                    else pf("NO\n");
                    
    return 0;
}