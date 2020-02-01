 #include<bits/stdc++.h>
using namespace std;

#define sf(nn) scanf ("%d", &nn)
#define pf printf
#define loop(till) for(int i=0; i<till; i++)
#define pb push_back
#define mx 1000005
#define ll long long int
#define mp make_pair
#define mod 10000007

/*
creating iterator to iterate a map ...
typedef std::map<string,int>::iterator it_type;
for(it_type iterator = fruits.begin(); iterator != fruits.end(); iterator++)
*/

/*int knapsack(int i,int w)
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

void sieve()
{

    isprime[0]=isprime[1]=1;
    prime.pb(2);

            for(int i=3; i*i<mx; i+=2)
            {
                if(!isprime[i]) for(int j=i*i; j<mx; j+=i) isprime[j]=1;
            }
            for(int i=3; i<mx; i+=2) if(!isprime[i] && (i%2)!=0) prime.pb(i);
}

bool issquare(ll n)
{
    int temp=sqrt(n);

        if((temp*temp) == n) return true;
    return false;
}

ll div_count(ll n)
{
    ll cnt,ans=1,len=prime.size();
        for(int i=0; prime[i]*prime[i]<=n && i<len; i++)
        {
            cnt=0;
            if(n%prime[i] == 0)
            {//cout<<prime[i]<<endl;
                while(n%prime[i] == 0) {n/=(ll)prime[i]; cnt++;}
                ans *= ((2*cnt)+1);
            }
        }
    if(n!=1) ans *= 3;
    return ans;
}

vector <ll> divv[100005];

void solve()
{
    for(ll i=1; i<=100002; i++)
    {
        ll divisor=div_count(i);
        ll temp=(i*i);
        divv[divisor].pb(temp);
    }
    //sort(divv.begin(),divv.end());
}

/*
int in_s,in_e;

int b_s(ll s_v)
{
    int mid,s=0,e=(divv.size()-1);

        while(s<=e)
        {
            mid=(s+e)/2;

                if(divv[mid]==s_v && divv[mid+1]>s_v) {in_e=mid; break;}
                else if(divv[mid]>s_v) e=mid-1;
                else s=mid+1;
        }


        mid,s=0,e=(divv.size()-1);

        while(s<=e)
        {
            mid=(s+e)/2;

                if(divv[mid]==s_v && divv[mid-1]<s_v) {in_s=mid;cout<<"ok"<<endl; break;}
                else if(divv[mid]>=s_v) e=mid-1;
                else s=mid+1;
                //cout<<divv[mid]<<" " << divv[mid-1]<<" " <<mid<<endl;
        }
        cout<<in_s << " " << in_e <<endl;
}
*/

int main()
{
    //ll ii=10000000000; cout<<ii;
    sieve();
    solve();
    int tc;
    ll high,low,k,n;
        //cout<<prime.size()<<endl;
        sf(tc);
            loop(tc)
            {
                int cnt=0;
                scanf("%lld %lld %lld", &k,&low,&high);

                int l=lower_bound(divv[k].begin(),divv[k].end(),low)-divv[k].begin();
                int h=upper_bound(divv[k].begin(),divv[k].end(),high)-divv[k].begin();
                //cout<<divv[k][l]<<" " <<divv[k][h]<<endl;
                //for(int i=l; i<=h; i++) cout<< divv[k][i]<<" ";
                //cout<<l<<" "<<h<<endl;
                
                pf("%d\n", h-l);
            }
    return 0;
}