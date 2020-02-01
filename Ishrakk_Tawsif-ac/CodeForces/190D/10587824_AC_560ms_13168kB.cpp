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
#define mod                     1000000007


int dx[8] = {1,-1,0,0,-1,-1,1,1};
int dy[8] = {0,0,-1,1,-1,1,-1,1};

int dirr[] = {-1,-1,0,0,1,1};
int dirc[] = {0,1,-1,1,-1,0};

unordered_map <int,int> mpp;

int ar[400005];

int main()
{
    int n,k,temp,mark=0;
    ll cnt = 0;

    scanf("%d %d", &n, &k);

    for(int i=0; i<n; i++)
    {
        sf(ar[i]);
        mpp[ar[i]]++;
        if(mpp[ar[i]]==k)
        {
            while(mpp[ar[i]]==k){
                cnt += (ll) (n-i); //cout<<n-i << " " << i <<endl;
                mpp[ar[mark]]--;
                mark++;
            }
        }
    }

    pf("%lld\n", cnt);
}