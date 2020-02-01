 #include<bits/stdc++.h>
using namespace std;

#define sf(nn) scanf ("%d", &nn)
#define pf printf
#define loop(till) for(int i=0; i<till; i++)
#define pb push_back
#define mx 1000005
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
vector<int>prime;
int cnt[mx];

void sieve()
{

    isprime[0]=isprime[1]=1;
    prime.pb(2);

            for(int i=3; i*i<mx; i+=2)
            {
                if(!isprime[i]) for(int j=i*i; j<mx; j+=i) isprime[j]=1;
            }
            cnt[2]=1;
            for(int i=3; i<mx; i++){
                    if(!isprime[i] && i%2!=0) {prime.pb(i); cnt[i]=cnt[i-1]+1;}
                    else cnt[i]=cnt[i-1];
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

ll divisor[mx];

ll solve()
{
    divisor[1] = 0;
    for (int i=2; i<=1000000; i++) {
        divisor[i] = divisor[i-1];
            int n=i, j=0;
                while (isprime[n] == true || (n%2)==0 && n!=2) {
                    if (n%prime[j]==0) {
                        divisor[i]++;
                        n /= prime[j];
                    }
                    else j++;
                }
                if (isprime[n] == false && (n%2)!=0 || n==2) divisor[i]++;
    }
}


int main()
{
   int n;
   sieve();
   solve();
        while(cin>> n)
        {
            cout<<divisor[n]<<endl;
        }
}