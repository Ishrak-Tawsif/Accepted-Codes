#include<bits/stdc++.h>
using namespace std;

#define sf(nn) scanf ("%d", &nn)
#define pf printf
#define loop(till) for(int i=0; i<till; i++)
#define pb push_back
#define mx 47001
#define ll long long int
#define mp make_pair
#define mod 1000000009

/*
creating iterator to iterate a map ...
typedef std::map<string,int>::iterator it_type;
for(it_type iterator = fruits.begin(); iterator != fruits.end(); iterator++)
*/

//ll val[1001],coin [1001],dp[1001][1001],n;

///knapsack
/*int ks(int i,int w)
{
    if(i<0) return 0;
    if(dp[i][w]!=-1) return dp[i][w];

        if(w-wei[i]>=0)dp[i][w] = max(ks(i-1,w),ks(i-1,w-wei[i])+val[i]);
        else dp[i][w]=ks(i-1,w);
        //cout << i << " " << w << " " << dp[i][w]<<endl;
    return dp[i][w];
}*/

///struct
/*struct d
{
    int h,w,nn;

        bool operator <(const d &x) const{
            if(w==x.w) return h<x.h;
            return w<x.w;
        }
};*/

///sieve

bitset<mx>isprime;
ll prime[mx],in;
vector <ll> ans;

void sieve()
{

    isprime[0]=isprime[1]=1;
    prime[0]=2;
    //for(int i=4; i<mx; i+=2) isprime[i]=1;
            for(int i=3; i*i<mx; i+=2)
            {
                if(!isprime[i]) for(int j=i*i; j<mx; j+=i) isprime[j]=1;
            }
            //cnt[2]=1;
            in=0;
            for(int i=3; i<mx; i+=2){
                    if(!isprime[i] && (i%2)!=0) prime[++in]=(ll)i;
                    //else cnt[i]=cnt[i-1];
            }
}


//int arr[101][101],dp[101][101],n,m;


///power function
/*ll ipow(ll base,ll pow)
{
    ll res=base;

        while(pow--) res*=base;
    return res;
}*/


///dfs
/*
vector <int> graph[19];
ll cost[19][19];
int dis[19],vis[19];

int dfs(int s)
{
    if(!vis[s]){
        vis[s]=1;
        for(int i=0; i<graph[s].size(); i++){
            int v=graph[s][i];
                if(!vis[v] && dis[v]>dis[s]+cost[s][v]){
                    dis[v]=dis[s]+cost[s][v];
                    dfs(v);
                }
        }
    }
}
*/
/*
void bfs(int s)
{
    dis[s]=0;
    vis[s]=1;
    queue<int>q;
    q.push(s);

        while(!q.empty())
        {
            int u=q.front(); q.pop();

                for(int i=0; i<graph[u].size(); i++)
                {
                    int v=graph[u][i];

                        if(!vis[v] && dis[v]>dis[u]+cost[u][v])
                        {
                            vis[v]=1;
                            dis[v]=dis[s]+cost[u][v];
                            q.push(v);
                        }
                }
        }
}
*/

/*
int row,col,ii,rr;
int dp[101][101],grid[101][101];


int call(int i, int j)
{
    if(j==col || i==row) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int ans;
//cout<<i<<" .. "<<j<<endl;system("pause");
        ans=grid[i][j]+max(call(i+1,j),call(i,j+1));
    return dp[i][j]=ans;
}
*/

/*
ll arr[21],dp[1<<17][21],in=-1,len,lim,k,base;

///bitmask dp

ll bitmask(int num,int mask)
{
    if(mask==lim){if(num%k == 0) return 1; else return 0;}
    if(dp[mask][num]!=-1) return dp[mask][num];

        ll ans=0;
        for(int i=0; i<=in; i++){
            if(!(mask & 1<<i))
                ans+=(bitmask(((num*base)+arr[i])%k,(mask|(1<<i))));
        }
    return dp[mask][num]=ans;
}
*/

vector <ll> v;

void prime_gen(ll l, ll h)
{
    v.clear();//cout<<v.size()<<endl;
    for(ll i=l; i<=h; i++)
    {
        int fl=1;//cout<<i<<endl;
            if(i<mx){if((!isprime[i] && i%2!=0) || i==2) v.pb(i);}
            else{
                for(int j=0; prime[j]*prime[j]<=i && j<=in; j++)
                    {
                        if(i%prime[j]==0){fl=0; break;}
                    }
                    if(fl==1) v.pb(i);
            }
    }//cout<<v.size()<<endl;
}

ll a,b,min_=LONG_LONG_MAX,max_=LONG_LONG_MIN;

int solve()
{
            int len=v.size();
            min_=LONG_LONG_MAX,max_=LONG_LONG_MIN;
            for(ll i=1; i<len; i++)
            {   //cout<<v[i]<<endl;
                ll temp=v[i]-v[i-1];
                    if(temp<min_) {min_=temp; a=(ll)i-1;}
                    if(temp>max_) {max_=temp; b=(ll)i-1;}//cout<<i<<endl;
            }
}

/*
unsigned ll div(unsigned ll n)
{
    unsigned ll cnt=0;
    for(int i=0; (unsigned ll)prime[i]*prime[i]<=n && i<=in; i++)
    {
        if(n%prime[i]==0){
            cnt++;

                while(n%prime[i] == 0) n/=(unsigned ll)prime[i];
        }
    }
    if(n!=1) cnt++;

    return cnt;
}
*/
int main()
{

   sieve();
   //pre_gen();
    ll u,l;

        while(scanf("%lld %lld", &l, &u) == 2){
            prime_gen(l,u);//cout<<"pg"<<endl;
            solve();//cout<<"sl"<<endl;
                if(min_==LONG_LONG_MAX || max_==LONG_LONG_MIN)
                    pf("There are no adjacent primes.\n");
                else
                    pf("%lld,%lld are closest, %lld,%lld are most distant.\n",v[a],v[a+1],v[b],v[b+1]);
        }//.
   return 0;
}