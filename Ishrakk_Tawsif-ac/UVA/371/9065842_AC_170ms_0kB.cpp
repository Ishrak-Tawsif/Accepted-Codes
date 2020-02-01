#include<bits/stdc++.h>
using namespace std;

#define sf(nn) scanf ("%d", &nn)
#define pf printf
#define loop(var,till) for(int var=0; var<till; var++)
#define loop1(var,till) for(int var=1; var<=till; var++)
#define pb push_back
#define mx 1003
#define ll long long int
#define mp make_pair
#define mod 1000000

int dir_r_8[]={-1,-1,-1,0,0,1,1,1};
int dir_c_8[]={-1,0,1,-1,1,-1,0,1};
int dir_r_4[]={-1,1,0,0};
int dir_c_4[]={0,0,-1,1};

unordered_map <ll,ll> dp;

ll call(ll n)
{
    //if(n == 1) return 0;
    if(dp[n] != 0) return dp[n];

        ll ans=0,temp;//cout<<n<<endl;if(n == 0) system("pause");
        if(n%2 == 0) temp = n/2; else temp = (3*n) + 1;
        if(temp == 1) return 1;
        ans = call(temp)+1;
    return dp[n]=ans;
}

int main()
{
    ll higher,lower;
        //memset(dp,-1,sizeof(dp));
        int n;
        while(scanf("%lld %lld", &higher,&lower) == 2)
        {
            if(higher == 0 && lower == 0) break;

            if(higher>lower) swap(higher,lower);

            ll max_ = LONG_MIN,ans=1;//cout<<higher<<" " <<lower<<endl;
            for(ll i=higher; i<=lower; i++) {ll temp=call(i); if(temp>max_) {max_=temp;ans=i;}}
            pf("Between %lld and %lld, %lld generates the longest sequence of %lld values.\n",higher,lower,ans,max_);
        }
    return 0;
}