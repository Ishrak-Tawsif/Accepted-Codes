 #include<bits/stdc++.h>
using namespace std;

#define sf(nn) scanf ("%d", &nn)
#define pf printf
#define loop(till) for(int i=0; i<till; i++)
#define pb push_back
#define mx 9999999+10
#define ll long long int
#define mp make_pair
#define mod 1000005

/*
creating iterator to iterate a map ...
typedef std::map<string,int>::iterator it_type;
for(it_type iterator = fruits.begin(); iterator != fruits.end(); iterator++)
*/

//ll val[1001],coin [1001],dp[1001][1001],n;

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

bitset<mx>isprime;
vector<ll>prime;
int cnt;

void sieve()
{

    isprime[0]=isprime[1]=1;
    prime.pb(2);

            for(int i=3; i*i<mx; i+=2)
            {
                if(!isprime[i]) for(int j=i*i; j<mx; j+=i) isprime[j]=1;
            }
            //cnt[2]=1;
            for(int i=3; i<mx; i++){
                    if(!isprime[i] && i%2!=0) prime.pb(i);
                    //else cnt[i]=cnt[i-1];
            }
}
//int arr[101][101],dp[101][101],n,m;

/*struct d
{
    int h,w,nn;

        bool operator <(const d &x) const{
            if(w==x.w) return h<x.h;
            return w<x.w;
        }
};*/

/*ll ipow(ll base,ll pow)
{
    ll res=base;

        while(pow--) res*=base;
    return res;
}*/


ll solve(ll n)
{
   ll len=prime.size(),ans=LONG_LONG_MAX;
   for(int i=0; prime[i]*prime[i]<=n && i<len; i++)
   {
       if(n%prime[i] == 0){
            ans=(ll)prime[i];
            cnt++;
            while(n%prime[i] == 0) n/=prime[i];
       }
   }
   if(n!=1) {cnt++;ans=max(ans,n);}
   return ans;
}


int main()
{
   ll n;
   sieve();//cout<<prime.size()<<endl;
   //solve();
        while(cin>> n && n)
        {
            cnt=0; n=abs(n);
            ll temp=solve(n);
            if(cnt <=1) pf("-1\n");
            else pf("%lld\n", temp);
        }
}