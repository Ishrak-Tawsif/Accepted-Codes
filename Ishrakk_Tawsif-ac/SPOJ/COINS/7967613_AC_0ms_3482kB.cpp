 #include<bits/stdc++.h>
using namespace std;

#define sf(nn) scanf ("%d", &nn)
#define pf printf
#define loop(till) for(int i=0; i<till; i++)
#define pb push_back
#define mx 10000000005
#define ll long long int
#define mp make_pair
#define mod 10000007

/*
creating iterator to iterate a map ...
typedef std::map<string,int>::iterator it_type;
for(it_type iterator = fruits.begin(); iterator != fruits.end(); iterator++)
*/

//int wei[1005],val[1005],
map <int,long long int> dp;

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

ll call(ll i)
{//cout<<i<<endl;
    if(i==0) return 0;
    //if(i==2) return 2;
    if(dp[i] != 0) return dp[i];

        ll ans;

            ans= max(i,call(i/2)+call(i/3)+call(i/4));
            //cout<<ans<<endl;
    return dp[i]=ans;
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
   int tc;
   ll n;

        //sf(tc);

            while(scanf("%lld", &n) == 1)
            {
                cout<<(ll)call(n)<<endl;
            }

   return 0;
}