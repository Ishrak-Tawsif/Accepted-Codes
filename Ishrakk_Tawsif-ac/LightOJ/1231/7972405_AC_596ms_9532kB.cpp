 #include<bits/stdc++.h>
using namespace std;

#define sf(nn) scanf ("%d", &nn)
#define pf printf
#define loop(till) for(int i=0; i<till; i++)
#define pb push_back
#define mx 10000000005
#define ll long long int
#define mp make_pair
#define mod 100000007

/*
creating iterator to iterate a map ...
typedef std::map<string,int>::iterator it_type;
for(it_type iterator = fruits.begin(); iterator != fruits.end(); iterator++)
*/

ll val[1001],coin [1001],dp[1001][1001],n;

//knapsack
/*int ks(int i,int w)
{
    if(i<0) return 0;
    if(dp[i][w]!=-1) return dp[i][w];

        if(w-wei[i]>=0)dp[i][w] = max(ks(i-1,w),ks(i-1,w-wei[i])+val[i]);
        else dp[i][w]=ks(i-1,w);
        //cout << i << " " << w << " " << dp[i][w]<<endl;
    return dp[i][w];
}*/

//vector <int> graph[mx];
//vector <int> graph2[mx];

//bitset<mx>isprime;
//vector<int>prime;

/*void sieve()
{

    isprime[0]=isprime[1]=1;
    prime.pb(2);

            for(int i=3; i*i<mx; i+=2)
            {
                if(!isprime[i]) for(int j=i*i; j<mx; j+=i) isprime[j]=1;
            }
            for(int i=3; i<mx; i+=2) if(!isprime[i]) prime.pb(i);
}*/
//int arr[101][101],dp[101][101],n,m;

ll call(ll i,ll tk)
{
    if(i==n) {
        if(tk==0) return 1;
        return 0;
    }
    if(tk==0) return 1;
    if(tk<0) return 0;
    if(dp[i][tk]!=-1) return dp[i][tk];

        ll ans=0;
        for(int j=0; j<=val[i]; j++)
        {
            ans = (ans+call(i+1,tk-coin[i]*j))%mod;
        }//cout<<ans<<endl;
   return dp[i][tk]=(ans%mod);
}

/*struct d
{
    int h,w,nn;

        bool operator <(const d &x) const{
            if(w==x.w) return h<x.h;
            return w<x.w;
        }
};*/

//vector <d> vv;

//map<string,int>mmp;
//map<string,int>track;

int main()
{
   ll k;
   int tc;
   sf(tc);

   for(int tt=1; tt<=tc; tt++)
   {
       scanf("%lld %lld", &n,&k);
       loop(n) scanf("%lld", &coin[i]);
       loop(n) scanf("%lld", &val[i]);
       memset(dp,-1,sizeof(dp));
       pf("Case %d: %lld\n",tt,call(0,k));
   }
   return 0;
}