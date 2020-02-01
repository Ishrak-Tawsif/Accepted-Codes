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


int dr8[]={-1,-1,0,1,1,1,0,-1};
int dc8[]={0,1,1,1,0,-1,-1,-1};

pair<ll,int> pri[mx];
ll tot;
int n,s;
multiset<ll>sss;

ll calc(int k)
{
    ll ans=0,are=0;
    //set<ll>sss;
    for(int i=0; i<n; i++) {
            ans = (ll)((pri[i].first)+(ll)((ll)(i+1)*(ll)k));
            are += ans;
            sss.insert(ans);//cout<<sss.size()<<"/// "<<i<<" "<<ans<<endl;if(i!=sss.size())system("pause");
    }//cout<<are<<" "<<sss.size()<<" " << k<<endl;system("pause");
    ans=0;//cout<<ss.size()<<endl;
    for(int i=1; i<=k; i++)
    {
        if(sss.empty() && i!=k) {return intinf;}
        if(sss.empty()) break;
        ll ttmm = *sss.begin();
        ans += ttmm;
        sss.erase(sss.begin());
    }//cout<<ans<<endl;
    sss.clear();
    return ans;
}

int bs(int b,int e)
{
    int mid,ans=0;
    tot=0;

        while(b<=e)
        {
            mid = (b+e)/2;//cout<<mid<<" " <<calc(mid)<<endl;
            ll temp = calc(mid);
            if(temp<=s)
            {
                b=mid+1;
                ans = mid;
                tot = temp;
            }
            else e=mid-1;
        }

    return ans;
}

int main()
{

        scanf("%d %d",&n,&s);

            loop(i,0,n){scanf("%lld",&pri[i].first);pri[i].second=i+1;}
            //sort(pri,pri+n);
            int tt=bs(1,n);
            pf("%d %lld\n",tt,tot);

    return 0;
}