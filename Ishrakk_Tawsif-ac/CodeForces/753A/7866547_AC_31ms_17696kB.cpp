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

int arr[105],sum[105];


int main()
{
    int n,i,arr[1001],in;

        while(sf(n) == 1)
        {
            in=-1;
            for(i=1; i<=n;i++){ n-=i; arr[++in]=i;}
            pf("%d\n", in+1);
            arr[in]+=n;

                pf("%d",arr[0]);
                for(int j=1; j<=in; j++) pf(" %d",arr[j]);

                pf("\n");
        }
   return 0;
}