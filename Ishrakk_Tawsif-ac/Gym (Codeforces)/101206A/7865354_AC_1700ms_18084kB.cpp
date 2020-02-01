#include<bits/stdc++.h>
using namespace std;

#define sf(nn) scanf ("%d", &nn)
#define pf printf
#define loop(till) for(int i=0; i<till; i++)
#define pb push_back
#define mx 1000005
#define ll long long int

vector <int> graph[mx];
vector <int> topsort;
int vis[mx],n,domino;

int arr[100005];

int main()
{
    int tc,n;
    ll sum;

        sf(tc);
            for(int tt=1; tt<=tc; tt++)
            {
                sf(n);
                sum=0;

                    loop(n)
                    {
                        sf(arr[i]);
                        sum += arr[i];
                    }
                    sort(arr, arr+n);
                    for(int i=n-3; i>=0; i-=3) {sum-=arr[i];}
                    pf("Case #%d: %d\n",tt,sum);
            }
}