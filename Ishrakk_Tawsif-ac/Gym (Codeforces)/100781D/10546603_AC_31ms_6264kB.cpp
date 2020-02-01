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


struct st{
    ll val;
    ll start;
    bool operator <(const st& t)const{
        if(val==t.val)return start<t.start;
        return val<t.val;
    }
};


st ar[400005];

int main()
    {
        int n,aa,bb,end_,k;

            sf(n);
            sf(k);

            end_=-1;
            for(int i=0;i<n;i++){
                scanf("%d", &aa);
                bb=aa+1000-1;
                ar[++end_].val=aa;
                ar[end_].start=0;
                ar[++end_].val=bb;
                ar[end_].start=1;
            }

            int cnt=0,ans=0;
            sort(ar,ar+end_+1);
            for(int i=0;i<=end_;i++){
                if(!ar[i].start)cnt++;
                else cnt--;
                ans=max(cnt,ans);
            }

            ans = ans/k + (ans%k!=0);

            pf("%d\n",ans);

        return 0;
}