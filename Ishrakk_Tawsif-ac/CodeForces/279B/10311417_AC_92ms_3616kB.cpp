#include<bits/stdc++.h>
using namespace std;

#define sf(nn)                  scanf ("%d", &nn)
#define sfll(nn)                scanf ("%lld", &nn)
#define pf                      printf
#define casepf(nn)              printf ("Case %d: ",nn)
#define out(nn)                 cout <<nn <<endl
#define loop(var,start,till)    for(int var=start; var<=till; var++)
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


int dr8[]={-1,-1,0,1,1,1,0,-1};
int dc8[]={0,1,1,1,0,-1,-1,-1};

ll ar[100005],csum[100005],m;
int n;

int calc(int mid)
{
    ll sum=0;
    int cnt=0;
    for(int i=mid; i<=n; i++)
    {
        sum += ar[i];//cout<<sum<<" "<<ar[i]<<" "<<i<<endl;
        if(sum>m) break;
        cnt++;
    }
   return cnt;
}

ll bs(int s,int e,int cur)
{
    int mid,ans=0;

        while(s<=e)
        {
            mid = (s+e)/2;

            ll temp = csum[mid]-csum[cur];
//cout<<mid<<" "<<temp<<endl;
            if(temp<=m)
            {
                ans=mid;
                s=mid+1;
            }
            else e=mid-1;
        }
    return ans;
}

int main()
{
        cin>>n>> m;

            loop(i,1,n){scanf("%lld", &ar[i]);csum[i] = csum[i-1] + ar[i];}
int ans=-1;
            for(int i=1; i<=n; i++)
            {
                int cur = bs(i,n,i-1)-i+1;//cout<<i<<" .. " <<cur<<endl;
                //cur -= i;
                ans = max(ans,cur);
            }
cout<<ans<<endl;
            //cout<<bs(1,n)-<<endl;
    return 0;
}