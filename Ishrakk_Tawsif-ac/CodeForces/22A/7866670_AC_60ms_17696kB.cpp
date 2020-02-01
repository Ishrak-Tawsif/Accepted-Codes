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
    vector<int>v;
        while(sf(n) == 1)
        {
            int f_min=200,s_min=150; v.clear();
            loop(n)
            {
                sf(arr[i]);
                v.pb(arr[i]);
            }
            sort(v.begin(),v.end());
            v.resize(distance(v.begin(), unique(v.begin(),v.end())));
                int len=v.size();
                if(len<2) pf("NO\n");
                else pf("%d\n",v[1]);
        }
   return 0;
}